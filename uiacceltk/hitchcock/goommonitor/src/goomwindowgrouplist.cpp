/*
* Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  A wrapper for the window group list, adding additional functionality required by GOOM Monitor
*
*/


#include <w32std.h>
#include <e32std.h>
#include <apgtask.h>
#include <apgwgnam.h>

//#include "eglext.h"
#include <EGL/egl.h>

#include "goomwindowgrouplist.h"
#include "goomtraces.h"
#include "goomconstants.hrh"

_LIT(KDummyWgName, "20");
const TInt KPreallocatedSpaceForAppList = 50;

const TUint KGOomTicksPerSecond = 1000;

typedef EGLBoolean (*NOK_resource_profiling)(EGLDisplay, EGLint, EGLint*, EGLint, EGLint*);

CGOomWindowGroupList::TGOomWindowGroupProperties::TGOomWindowGroupProperties() :  iIdleTickTime(0), iDynamicPriority(EGOomPriorityNormal)
    {
    FUNC_LOG;
    }

// Update the list of window groups
void CGOomWindowGroupList::Refresh()
    {
    FUNC_LOG;
    
#ifdef _DEBUG
    TRAPD(err, RefreshL());
    if (err)
        {
        TRACES1("CGOomWindowGroupList::Refresh(): RefreshL leave %d", err);
        }
#else
    TRAP_IGNORE(RefreshL());
    // Ignore any error
    // Errors are very unlikely, the only possibility is OOM errors (which should be very unlikely due to pre-created, re-reserved lists)
    // The outcome of any error is that the most foreground operations will be missing from the list
    // meaning that they will not be considered candidates for closing
#endif    
    }

// Update the list of window groups
// Should be called whenever the 
void CGOomWindowGroupList::RefreshL()
    {
    FUNC_LOG;
  
    NOK_resource_profiling eglQueryProfilingData = (NOK_resource_profiling)eglGetProcAddress("eglQueryProfilingDataNOK");
    
    if (!eglQueryProfilingData)
            {
            TRACES("RefreshL EGL_NOK_resource_profiling not available");
            return;
            }
    
    EGLint data_count;
    EGLint* prof_data;
    TInt i(0);
    RArray<TUint64> processIds;
    //RArray<TUint> privMemUsed;
        
    EGLDisplay dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    /* Find out how much profiling data is available */
    eglQueryProfilingData(dpy, EGL_PROF_QUERY_GLOBAL_BIT_NOK|
                                EGL_PROF_QUERY_MEMORY_USAGE_BIT_NOK,
                                NULL, 0, &data_count);
    
    /* Allocate room for the profiling data */
    prof_data = (EGLint*)User::Alloc(data_count * sizeof(EGLint));
    if (prof_data == NULL)
        return;

    /* Retrieve the profiling data */
    eglQueryProfilingData(dpy,   EGL_PROF_QUERY_GLOBAL_BIT_NOK|
                                 EGL_PROF_QUERY_MEMORY_USAGE_BIT_NOK,
                                 prof_data,
                                 data_count,
                                 &data_count);
    
    /* Iterate over the returned data */
    while (i < data_count)
        {
        TRACES2("RefreshL EGL_NOK_resource_profiling - index: %d data: %x", i, prof_data[i]);
            
        switch (prof_data[i++])
            {   
            case EGL_PROF_PROCESS_ID_NOK:
                {
                TUint64 process_id;
                if (sizeof(EGLNativeProcessIdTypeNOK) == 8)
                    {
                    process_id = TUint64(prof_data[i]);
                    process_id += (TUint64(prof_data[i + 1]) << 32);
                    i+=2;
                    }
                else
                    {
                    process_id = prof_data[i];
                    i++;
                    }
                processIds.Append(process_id);
                break;
                }
            case EGL_PROF_PROCESS_USED_PRIVATE_MEMORY_NOK:
                {
                //TUint mem = prof_data[i];
                //privMemUsed.Append(mem);
                i++;
                break;
                }
            case EGL_PROF_PROCESS_USED_SHARED_MEMORY_NOK:
            case EGL_PROF_USED_MEMORY_NOK:
            case EGL_PROF_TOTAL_MEMORY_NOK:
            default:
                {
                TRACES2("RefreshL index %d, data: %d\n", i, prof_data[i]);
                i++;
                break;
                }
            }
        }
        
    /* Free allocated memory */
    User::Free(prof_data);
    
    TRACES1("RefreshL : %d Processes use gfx memory", processIds.Count());
    
    ///////////////////////////////////////////////////////////////////
    // Optimization, no need to construct list if ALF is the only one
    ///////////////////////////////////////////////////////////////////
    
    if (processIds.Count() == 1)
        {
        RProcess process;
        TInt err =  process.Open(processIds[0]);
        if(!err)
            {
            TInt secureId = process.SecureId();
            process.Close();
            if(secureId == 0x10003B20) // magic, wserv 
                {
                processIds.Close();
                TRACES("Only WServ using GFX mem, no need for app actions");
                return;
                }
            }
        }
        
    // Refresh window group list
    // get all window groups, with info about parents
    TInt numGroups = iWs.NumWindowGroups(0);
    iWgIds.ReserveL(numGroups);
    User::LeaveIfError(iWs.WindowGroupList(0, &iWgIds));
    
    // Remove all child window groups, promote parents to foremost child position
    CollapseWindowGroupTree();
    
    // Note the current foreground window ID (if there is one)
    TBool oldForegroundWindowExists = EFalse;

    TInt oldForegroundWindowId;
    if (iWgIds.Count() > 0)
        {
        oldForegroundWindowId = iWgIds[0].iId;
        oldForegroundWindowExists = ETrue;
        }    
    
    // Cleanup the idletime hash map to remove idle times for any windows that have closed
    RemovePropertiesForClosedWindowsL();
    
    // Update the idle tick on the old foreground application (which might now be in the background)
    // This will be set to the current system tick count and will be used later to determine the idle time
    if (oldForegroundWindowExists)
        {
        TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(oldForegroundWindowId);
        if (wgProperties)
            {
            wgProperties->iIdleTickTime = User::NTickCount();
            }
        
        // If there is no idle tick entry for this window ID then it will be created in the next step...
        }
    
    TInt index = iWgIds.Count();
    
    while (index--)
        {
        //Remove if process is not in list of processes using gfx mem
        TUint secureId = AppId(index,ETrue);
        TBool found = 0;
        TInt i = 0;
        for(i = 0; i < processIds.Count(); i++)
            {
            RProcess process;
            TInt er =  process.Open(processIds[i]);
            if(er != KErrNone)
                {
                TRACES2("RefreshL Error opening process handle %d, err %d", index, er);
                continue;
                }
            /*static _LIT_SECURITY_POLICY_S0(mySidPolicy, secureId);
            if(mySidPolicy().CheckPolicy(process))*/
            TInt psecid = process.SecureId();
            if(secureId == psecid)
                {
                found = 1;
                process.Close();
                TRACES2("RefreshL Process id %x, wgindex %d, using gfx memory. Added to list", psecid, index);
                break;
                }
            process.Close();
            }
      
        if(!found)
            {
            iWgIds.Remove(index);
            continue;
            }
      
        // See if there is a tick count entry for each window in the list
        TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(iWgIds[index].iId);
        
        if (!wgProperties)
            {
            TGOomWindowGroupProperties wgProperties;
            wgProperties.iIdleTickTime = User::NTickCount();
            // If there is no idle tick entry for this window then add one
            iWgToPropertiesMapping.InsertL(iWgIds[index].iId, wgProperties);
            }
        }
       
    processIds.Close();
    //privMemUsed.Close();       
    
    }



void CGOomWindowGroupList::RemovePropertiesForClosedWindowsL()
    {
    FUNC_LOG;
    
    // First, clear the existing set of window IDs (it would be quicker to delete it BUT we have reserved memory for it and don't want to be allocating in low memory conditions)
    RHashSet<TInt>::TIter windowIdSetIter(iExistingWindowIds);
    while (windowIdSetIter.Next())
        {
        windowIdSetIter.RemoveCurrent();
        }
    
    // Create the set of existing window IDs (this saves expensive/repeated searching later on)
    TInt index = iWgIds.Count();
    while (index--)
        {
        iExistingWindowIds.InsertL(iWgIds[index].iId);
        }
    
    // Iterate the idle-time hash map - remove any items where the window no longer exists
    RHashMap<TInt, TGOomWindowGroupProperties>::TIter wgToIdleIterator(iWgToPropertiesMapping);
    while (wgToIdleIterator.NextKey())
        {
        // If the current key (window ID) does not exist in the set then remove the idle-time as it is no longer relevant
        if (!iExistingWindowIds.Find(*(wgToIdleIterator.CurrentKey())))
                wgToIdleIterator.RemoveCurrent();
        }
    }


TUint CGOomWindowGroupList::AppId(TInt aIndex, TBool aResolveFromThread) const
    {
    FUNC_LOG;

    if (aIndex < 0 || aIndex >= iWgIds.Count())
        {
        return 0; // somewhat equals to KNullUid
        }
		
    //TRACES2("CGOomWindowGroupList::AppId(%d), count: %d ",aIndex,iWgIds.Count());

    TInt wgId = iWgIds[aIndex].iId;
    
    return AppIdfromWgId(wgId, aResolveFromThread);
    }

TUint CGOomWindowGroupList::AppIdfromWgId(TInt aWgId, TBool aResolveFromThread) const
    {
    // get the app's details
    TPtr wgPtr(iWgNameBuf->Des());
    
    TUid uid;
    
    TInt wgId = aWgId;
    
    TInt err = iWs.GetWindowGroupNameFromIdentifier(wgId, wgPtr);
    
    if (KErrNone != err)
        // If there is an error then set the UID to 0;
        {
        uid.iUid = 0;
        }
    else 
        {
        iWgName->SetWindowGroupName(iWgNameBuf); // iWgName takes ownership of iWgNameBuf
        uid = iWgName->AppUid(); // This UID comes from the app, not the mmp!
        if (aResolveFromThread && uid.iUid == 0)
            {
            TApaTask task(iWs);
            task.SetWgId(wgId);
            TThreadId threadId = task.ThreadId();
            
            TUint resolvedUid = 0;
            RThread appThread;
            TInt err = appThread.Open( threadId );
            if ( err == KErrNone )
                {
                resolvedUid = appThread.SecureId().iId;
                }
            appThread.Close();
            //TRACES2("CGOomWindowGroupList::AppId: NULL wg UID, taking from thread; resolvedUid = %x aIndex = %d", resolvedUid, aIndex);            
            return resolvedUid;               
            }
        }
    
    return uid.iUid;
    }
    

TTimeIntervalSeconds CGOomWindowGroupList::IdleTime(TInt aIndex) const
    {
    FUNC_LOG;

    TUint32 currentTickCount = User::NTickCount();
        
    const TGOomWindowGroupProperties* wgProperties = 0;
    if (aIndex >= 0 && aIndex < iWgIds.Count())
        {
        wgProperties = iWgToPropertiesMapping.Find(iWgIds[aIndex].iId);
        }
    
    TTimeIntervalSeconds idleTime = 0;
    
    if (wgProperties)
        {
        // This should also handle the case where the current tick count has wrapped to a lower value than the idle tick time
        // It will only work if it has wrapped once, but
        TUint32 differenceBetweenTickCounts = currentTickCount - wgProperties->iIdleTickTime;
        idleTime = differenceBetweenTickCounts / KGOomTicksPerSecond;
        }
    
    return idleTime;
    }
  


void CGOomWindowGroupList::CollapseWindowGroupTree()
    {
    FUNC_LOG;

    // start from the front, wg count can reduce as loop runs
    for (TInt ii=0; ii<iWgIds.Count();)
        {
        RWsSession::TWindowGroupChainInfo& info = iWgIds[ii];
        if (info.iParentId > 0)        // wg has a parent
            {
            // Look for the parent position
            TInt parentPos = ii;        // use child pos as not-found signal
            TInt count = iWgIds.Count();
            for (TInt jj=0; jj<count; jj++)
                {
                if (iWgIds[jj].iId == info.iParentId)
                    {
                    parentPos = jj;
                    break;
                    }
                }

            if (parentPos > ii)  // parent should be moved forward
                {
                iWgIds[ii] = iWgIds[parentPos];
                iWgIds.Remove(parentPos);
                }
            else if (parentPos < ii)  // parent is already ahead of child, remove child
                iWgIds.Remove(ii);
            else                    // parent not found, skip
                ii++;
            }
        else    // wg does not have a parent, skip
            ii++;
        }    
    }



CGOomWindowGroupList::CGOomWindowGroupList(RWsSession& aWs) : iWs(aWs)
    {
    FUNC_LOG;
    }



void CGOomWindowGroupList::ConstructL()
    {
    FUNC_LOG;

    // Reserve enough space to build an app list later.
    iWgIds.ReserveL(KPreallocatedSpaceForAppList);
    iUncollapsedWgIds.ReserveL(KPreallocatedSpaceForAppList);
    
    // Reserve enough space for the WG to idle tick mapping
    iWgToPropertiesMapping.ReserveL(KPreallocatedSpaceForAppList);
    
    // Reserve enough space for CApaWindowGroupName.
    iWgName = CApaWindowGroupName::NewL(iWs);
    iWgNameBuf = HBufC::NewL(CApaWindowGroupName::EMaxLength);
    (*iWgNameBuf) = KDummyWgName;
    iWgName->SetWindowGroupName(iWgNameBuf);    // iWgName takes ownership of iWgNameBuf
    }



CGOomWindowGroupList* CGOomWindowGroupList::NewL(RWsSession& aWs)
    {
    FUNC_LOG;

    CGOomWindowGroupList* self = new (ELeave) CGOomWindowGroupList(aWs);
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    return self;
    }



CGOomWindowGroupList::~CGOomWindowGroupList()
    {
    FUNC_LOG;

    iWgIds.Close();
    iUncollapsedWgIds.Close();
    iWgToPropertiesMapping.Close();
    iExistingWindowIds.Close();
    delete iWgName;
    }


void CGOomWindowGroupList::SetPriorityBusy(TInt aWgId)
    {
    FUNC_LOG;

    //Refresh();
    
    TInt parentId;
    TRAPD(err, parentId = FindParentIdL(aWgId));
    if (err)
        {
        parentId = aWgId;
        }
    
    TRACES2("CGOomWindowGroupList::SetPriorityBusy aWgId = %d, parentId = %d", aWgId, parentId);
    
    TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(parentId);
    if (wgProperties)
        {
        wgProperties->iDynamicPriority = EGOomPriorityBusy;
        }
    
    // If we can't find the window group then ignore it
    }


TInt CGOomWindowGroupList::FindParentIdL(TInt aWgId)
    {
    TInt numGroups = iWs.NumWindowGroups(0);
    iUncollapsedWgIds.ReserveL(numGroups);
    User::LeaveIfError(iWs.WindowGroupList(0, &iUncollapsedWgIds));

    TInt parentPos = KErrNotFound;
   
    //loop through the window group list
    for (TInt i=0; i<numGroups; i++)
        {
        //find the index for the required aWgId
        if (iUncollapsedWgIds[i].iId == aWgId)
            {
            parentPos = i;
            break;
            }
        }

    if (parentPos >=0 )
        {
        while (iUncollapsedWgIds[parentPos].iParentId > 0)
            {
            // find the index for the parent
            for (TInt j=0; j<numGroups; j++)
                {
                if (iUncollapsedWgIds[j].iId == iUncollapsedWgIds[parentPos].iParentId)
                    {
                    parentPos = j;
                    break; // break out of inner loop
                    }
                }
            }
        return iUncollapsedWgIds[parentPos].iId;
        }
    else 
        {
        return KErrNotFound;
        }
    }


TBool CGOomWindowGroupList::IsBusy(TInt aWgIndex)
    {
    if (aWgIndex < 0 || aWgIndex >= iWgIds.Count())
        {
        return EFalse;
        }
            
    TBool isBusy = EFalse;
    TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(iWgIds[aWgIndex].iId);
    if (wgProperties)
        {
        isBusy = (wgProperties->iDynamicPriority == EGOomPriorityBusy);
        }
    
    return isBusy;
    }

// Returns ETrue if an application has registered itself as high priority at runtime
TBool CGOomWindowGroupList::IsDynamicHighPriority(TInt aWgIndex)
    {
    FUNC_LOG;
    if (aWgIndex < 0 || aWgIndex >= iWgIds.Count())
        {
        return EFalse;
        }

    TBool isHighPriority = EFalse;
    TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(iWgIds[aWgIndex].iId);
    if (wgProperties)
        {
        isHighPriority = (wgProperties->iDynamicPriority == EGOomPriorityHigh);
        }
    
    return isHighPriority;
    }

CApaWindowGroupName* CGOomWindowGroupList::WgName() const
    {
    return iWgName;
    }

void CGOomWindowGroupList::SetPriorityNormal(TInt aWgId)
    {
    FUNC_LOG;

    //Refresh();
    
    TInt parentId;
    TRAPD(err, parentId = FindParentIdL(aWgId));
    if (err)
        {
        parentId = aWgId;
        }
    
    TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(parentId);
    if (wgProperties)
        {
        wgProperties->iDynamicPriority = EGOomPriorityNormal;
        }
    
    // If we can't find the window group then ignore it
    }


void CGOomWindowGroupList::SetPriorityHigh(TInt aWgId)
    {
    FUNC_LOG;

    //Refresh();

    TInt parentId;
    TRAPD(err, parentId = FindParentIdL(aWgId));
    if (err)
        {
        parentId = aWgId;
        }
    
    TGOomWindowGroupProperties* wgProperties = iWgToPropertiesMapping.Find(parentId);
    if (wgProperties)
        {
        wgProperties->iDynamicPriority = EGOomPriorityHigh;
        }
    
    // If we can't find the window group then ignore it
    }

// Find the specificed application in the window group list and return the index
TInt CGOomWindowGroupList::GetIndexFromAppId(TUint aAppId) const
    {
    FUNC_LOG;

    TInt indexInGroupList = Count();
    TBool appFoundInWindowGroupList = EFalse;
    
    while (indexInGroupList--)
        {
        if (AppId(indexInGroupList, ETrue) == aAppId)
            {
            appFoundInWindowGroupList = ETrue;
            break;
            }
        }
    
    if (!appFoundInWindowGroupList)
        indexInGroupList = KAppNotInWindowGroupList;

    return indexInGroupList;
    }
