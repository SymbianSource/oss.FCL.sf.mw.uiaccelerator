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
* Description:  Main classes for Graphics Out of Memory Monitor
*
*/


#define USE_ASYNCYH_NOTIFICATIONS


#include <hal.h>
#include <libc/string.h>
#include <UikonInternalPSKeys.h>

//TODO: to be removed for wk44 onwards, should use only <EGL/egl.h> which is already included in goommemorymonitor.h
#ifdef USE_ASYNCYH_NOTIFICATIONS
#include <EGL/egl.h>
#else // use local 
#include "eglext.h"
#endif

#include "goommemorymonitor.h"
#include "goommonitorplugin.h"
#include "goomconfig.h"
#include "goommemorymonitorserver.h"
#include "goomconfigparser.h"
#include "goomactionlist.h"
#include "goomlog.h"
#include "goomtraces.h"
#include "goomwserveventreceiver.h"
#include "goomconstants.hrh"
#include "goomrunpluginconfig.h"
#include "goomapplicationconfig.h"
#include "goomcloseappconfig.h"
#include <goommonitorsession.h>
#ifdef USE_ASYNCYH_NOTIFICATIONS 
#include "goomthresholdcrossedao.inl"
#endif

// ======================================================================
// class CMemoryMonitor
// ======================================================================

// ---------------------------------------------------------
//
// ---------------------------------------------------------
//
CMemoryMonitor* CMemoryMonitor::NewL()
    { // static
    FUNC_LOG;

    CMemoryMonitor* self = new(ELeave) CMemoryMonitor();
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    return self;
    }

CMemoryMonitor::CMemoryMonitor()
    {
    FUNC_LOG;

    SetGMemoryMonitorTls(this);
    }

// ---------------------------------------------------------
//
// ---------------------------------------------------------
//
CMemoryMonitor::~CMemoryMonitor()
    {
    FUNC_LOG;

    delete iServer;
    delete iWservEventReceiver;
    iFs.Close();
    iWs.Close();

    delete iGOomWindowGroupList;

    delete iGOomActionList;

    delete iConfig;
 
 #ifdef USE_ASYNCYH_NOTIFICATIONS    
    delete iMemAllocationsGrowing;
    delete iMemAllocationsGoingDown;
 #endif
    
    eglTerminate(eglGetDisplay(EGL_DEFAULT_DISPLAY));

#ifdef _DEBUG
    delete iLogger;
#endif
    }

// ---------------------------------------------------------
//
// ---------------------------------------------------------
//
void CMemoryMonitor::ConstructL()
    {
    FUNC_LOG;
	
	    //Initialize EGL extension for memory data

    EGLDisplay dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    EGLint major, minor;
    eglInitialize(dpy, &major, &minor);
	
    /*
     ** Search for extName in the extensions string.  Use of strstr()
     ** is not sufficient because extension names can be prefixes of
     ** other extension names.  Could use strtok() but the constant
     ** string returned by glGetString can be in read-only memory.
     */
    TBool extensionFound = EFalse;
    char *p = (char *) eglQueryString(dpy,EGL_EXTENSIONS);
    char *end;
    int extNameLen;

    extNameLen = strlen("EGL_NOK_resource_profiling");
    end = p + strlen(p);

    while (p < end) 
        {
        int n = strcspn(p, " ");
        if ((extNameLen == n) && (strncmp("EGL_NOK_resource_profiling", p, n) == 0)) 
            {
            extensionFound = ETrue;
            break;
            }
        p += (n + 1);
        }
  
    if (!extensionFound)
        {
        TRACES("EGL_NOK_resource_profiling not found from EGL_EXTENSIONS");
        }
    // okay, let's fetch the function ptr to our profiling functions
    eglQueryProfilingData = (NOK_resource_profiling)eglGetProcAddress("eglQueryProfilingDataNOK");
    if (!eglQueryProfilingData)
        {
        TRACES("eglQueryProfilingDataNOK not found via eglGetProcAddress()");
        User::Leave(KErrNotSupported);
        }
	
    User::LeaveIfError(iWs.Connect());
    iWs.ComputeMode(RWsSession::EPriorityControlDisabled); 
    
    iGOomWindowGroupList = CGOomWindowGroupList::NewL(iWs);

    iConfig = CGOomConfig::NewL();

    iServer = CMemoryMonitorServer::NewL(*this);
    
   // Load up threshold & OOM app lists from resource.
    User::LeaveIfError(iFs.Connect());

    CGOomConfigParser* oomConfigParser = new (ELeave) CGOomConfigParser(*iConfig, iFs);
    CleanupStack::PushL(oomConfigParser);
    oomConfigParser->ParseL();
    CleanupStack::PopAndDestroy(oomConfigParser);

    iGOomActionList = CGOomActionList::NewL(*this, *iServer, iWs, *iConfig);

#ifdef _DEBUG
    iLogger = CGOomLogger::NewL(iWs, iFs);
#endif

    // Get the thresholds based on the current foreground app and the config
    RefreshThresholds();
    
    iWservEventReceiver = new(ELeave) CWservEventReceiver(*this, iWs);
    iWservEventReceiver->ConstructL();
    }

const CGOomGlobalConfig& CMemoryMonitor::GlobalConfig()
    {
    CMemoryMonitor* globalMemoryMonitor = static_cast<CMemoryMonitor*>(Dll::Tls());
    return globalMemoryMonitor->iConfig->GlobalConfig();
    }


// ---------------------------------------------------------
//
// ---------------------------------------------------------
//
void CMemoryMonitor::FreeMemThresholdCrossedL(TInt /*aAction*/, TInt aThreshold)
    {
    FUNC_LOG;
    // keep only one notification active at a moment
#ifdef USE_ASYNCYH_NOTIFICATIONS 
    if (aThreshold == EGL_PROF_TOTAL_MEMORY_USAGE_GT_NOK)
        {
        TRACES("FreeMemThresholdCrossedL : EGL_PROF_TOTAL_MEMORY_USAGE_GT_NOK");
        iMemAllocationsGrowing->Stop();
        iMemAllocationsGoingDown->Continue();
        }
    else
        {
        TRACES("FreeMemThresholdCrossedL : EGL_PROF_TOTAL_MEMORY_USAGE_LT_NOK");
        iMemAllocationsGrowing->Continue();
        iMemAllocationsGoingDown->Stop();            
        }    
#endif

    StartFreeSomeRamL(iGoodThreshold);
    if (aThreshold == EGL_PROF_TOTAL_MEMORY_USAGE_LT_NOK)
        {
        TInt current = GetFreeMemory();
        if(current >= iGoodThreshold  && (!NeedToPostponeMemGood()))
            {
            TRACES("FreeMemThresholdCrossedL : calling MemoryGOOD");
            iGOomActionList->MemoryGood();
            }
        }
    }

void CMemoryMonitor::HandleFocusedWgChangeL(TInt aForegroundAppUid)
    {
    FUNC_LOG;
    
    TRACES1("CMemoryMonitor::HandleFocusedWgChangeL Foregroundapp id = %x", aForegroundAppUid);
    
    if(aForegroundAppUid == 0)
        {
        return;
        }
    iForegroundAppUid = aForegroundAppUid;    

    // Refresh the low and good memory thresholds as they may have changed due to the new foreground application
    RefreshThresholds(aForegroundAppUid);
    // Not very elegant, now we poll on each window group change
    // Should have better trigger e.g. from window server 
#ifndef USE_ASYNCYH_NOTIFICATIONS  
    TInt current = GetFreeMemory();
    if (current < iLowThreshold)
        {
        StartFreeSomeRamL(iGoodThreshold);
        }  
    else if(current >= iGoodThreshold)
        {
        iGOomActionList->MemoryGood();
        }
#endif
     }

void CMemoryMonitor::StartFreeSomeRamL(TInt aTargetFree, TInt aMaxPriority) // The maximum priority of action to run
    {
    FUNC_LOG;

    TRACES2("MemoryMonitor::StartFreeSomeRamL: aTargetFree = %d, iCurrentTarget = %d", aTargetFree, iCurrentTarget);

    // Update the target if new target is higher. If the target is lower than the current target and memory
    // is currently being freed then we do not want to reduce the amount of memory this operation frees.
    if (aTargetFree > iCurrentTarget)
        iCurrentTarget = aTargetFree;

    // check if there is enough free memory already.
    TInt freeMemory;
    TBool freeMemoryAboveCurrentTarget = FreeGraphicsMemoryAboveThresholdL(freeMemory);

    TRACES2("MemoryMonitor::StartFreeSomeRamL freeMemoryAboveTarget = %d, freeMemory = %d", freeMemoryAboveCurrentTarget, freeMemory);

    if (freeMemoryAboveCurrentTarget)
        {
        ResetTargets();
        /*if(freeMemory >= iGoodThreshold && !NeedToPostponeMemGood())
            {
                iGOomActionList->MemoryGood();
            }
        */
        iServer->CloseAppsFinished(freeMemory, ETrue);
        return;
        }

    // update wg list only when actually about to use it 
    //iGOomWindowGroupList->Refresh();

#ifdef _DEBUG
    iLogger->StartL();
#endif

    // Build the list of memory freeing actions
    iGOomActionList->BuildPluginActionListL(*iGOomWindowGroupList, *iConfig);

    //iGOomActionList->SetCurrentTarget(aTargetFree);
    iGOomActionList->SetCurrentTarget(iCurrentTarget);

    // Run the memory freeing actions
    iGOomActionList->FreeMemory(aMaxPriority);
    }

void CMemoryMonitor::RunCloseAppActions(TInt aMaxPriority)
    {
    FUNC_LOG;
    // Build the list of memory freeing actions (by killing apps)
    iGOomActionList->BuildKillAppActionListL(*iGOomWindowGroupList, *iConfig);
    iGOomActionList->FreeMemory(aMaxPriority);
    }

// ---------------------------------------------------------
// This function attempts to free enough RAM to leave the target amount of space free.
// This function could take a substantial time to return as it may have to close a number
// of applications, and each will be given a timeout of KAPPEXITTIMEOUT.
// ---------------------------------------------------------
//
void CMemoryMonitor::StartFreeSomeRamL(TInt aTargetFree)
    {
    FUNC_LOG;

    StartFreeSomeRamL(aTargetFree, KGOomPriorityInfinate - 1);
    }

void CMemoryMonitor::RequestFreeMemoryL(TInt aTargetFree, TBool aUseAbsolute)
    {
    FUNC_LOG;

    StartFreeSomeRamL(aUseAbsolute?aTargetFree:(aTargetFree + iLowThreshold), KGOomPriorityInfinate - 1);
    }

void CMemoryMonitor::FreeOptionalRamL(TInt aTargetFree, TInt aPluginId, TBool aUseAbsolute) // The ID of the plugin that will clear up the allocation, used to determine the priority of the allocation
    {
    FUNC_LOG;

    // Calculate the priority of the allocation (the priority of the plugin that will clear it up - 1)
    TInt priorityOfAllocation = iConfig->GetPluginConfig(aPluginId).CalculatePluginPriority(*iGOomWindowGroupList) - 1;
    StartFreeSomeRamL(aUseAbsolute?aTargetFree:(aTargetFree + iGoodThreshold), priorityOfAllocation);
    }

// Does the EGL extension return the amount of memory in bits?
// If yes, int is clearly not enough
// Note that this function reserves memory so it can fail if the "standard" memory
// gets full.
TBool CMemoryMonitor::FreeGraphicsMemoryAboveThresholdL(TInt& aCurrentFreeMemory)
    {
    FUNC_LOG;
    
    TInt current = GetFreeMemory();
    User::LeaveIfError(current);
    aCurrentFreeMemory = current;
    
    return (current >= iCurrentTarget);
    }

// ---------------------------------------------------------
//
// ---------------------------------------------------------
//

void CMemoryMonitor::AppNotExiting(TInt aWgId)
    {
    FUNC_LOG;

    iGOomActionList->AppNotExiting(aWgId);
    }


void CMemoryMonitor::RefreshThresholds(TInt aForegroundAppUid)
    {
    FUNC_LOG;    
    
    TInt origGood = iGoodThreshold;
    TInt origLow = iLowThreshold;
    
    // Calculate the desired good threshold, this could be the globally configured value...
    iGoodThreshold = CMemoryMonitor::GlobalConfig().iGoodRamThreshold;
    iLowThreshold = CMemoryMonitor::GlobalConfig().iLowRamThreshold;
    iCurrentTarget = iGoodThreshold;
        
    TRACES2("CMemoryMonitor::RefreshThresholds: Global Good Threshold = %d, Global Low Threshold = %d", iGoodThreshold, iLowThreshold);

    // The global value can be overridden by an app specific value
    // Find the application config entry for the foreground application
    if (aForegroundAppUid == KErrNotFound)
        {
        return;
        }     
                
    // If this application configuration overrides the good_ram_threshold then set it
    if (iConfig->GetApplicationConfig(aForegroundAppUid).iGoodRamThreshold != KGOomThresholdUnset)
        {
        iGoodThreshold = iConfig->GetApplicationConfig(aForegroundAppUid).iGoodRamThreshold;
        TRACES2("CMemoryMonitor::RefreshThresholds: For foreground app %x, Good Threshold = %d", aForegroundAppUid, iGoodThreshold);
        }
    
    // If this application configuration overrides the low_ram_threshold then set it
    if (iConfig->GetApplicationConfig(aForegroundAppUid).iLowRamThreshold != KGOomThresholdUnset)
        {
        iLowThreshold = iConfig->GetApplicationConfig(aForegroundAppUid).iLowRamThreshold;
        TRACES2("CMemoryMonitor::RefreshThresholds: For foreground app %x, Low Threshold = %d", aForegroundAppUid, iLowThreshold);
        }
    
    // If this application configuration overrides the good_ram_threshold then set it
    if (iConfig->GetApplicationConfig(aForegroundAppUid).iTargetFree != KGOomThresholdUnset)
        {
        iCurrentTarget = iConfig->GetApplicationConfig(aForegroundAppUid).iTargetFree;
        TRACES2("CMemoryMonitor::RefreshThresholds: For foreground app %x, Target Free on Startup = %d", aForegroundAppUid, iCurrentTarget);
        }
    
    iGOomActionList->SetCurrentTarget(iCurrentTarget);
    
#ifdef USE_ASYNCYH_NOTIFICATIONS 

    // if allocation should fail, threshold should not naturally be set
    if (!iMemAllocationsGrowing)
        {
        TRAP_IGNORE(iMemAllocationsGrowing = CreateThresholdCrossedThreadL(*this, EGL_PROF_TOTAL_MEMORY_USAGE_GT_NOK, iLowThreshold))
        origLow = iLowThreshold; // do not reset
        }
    if (!iMemAllocationsGoingDown)
        {
        TRAP_IGNORE(iMemAllocationsGoingDown = CreateThresholdCrossedThreadL(*this, EGL_PROF_TOTAL_MEMORY_USAGE_LT_NOK, iGoodThreshold))
        origGood = iGoodThreshold; // do not reset
        }
        
    TBool releaseClient = ETrue;

    // update thresholds only if they really change
    if (origGood != iGoodThreshold)
        {
        iMemAllocationsGoingDown->SetThreshold(iGoodThreshold);
        }
    
    if ( origLow != iLowThreshold)
        {
        // need to synchronously check whether client should wait
        // memory to be released
        if(GetFreeMemory() <= iLowThreshold )    
            {
            releaseClient = EFalse;
            }
        iMemAllocationsGrowing->SetThreshold(iLowThreshold);
        }

   TRACES3("CMemoryMonitor::RefreshThresholds: releaseClient: %d For foreground app 0x%x, Active client = 0x%x",releaseClient, aForegroundAppUid, ActiveClientId());
        
   if (releaseClient && ActiveClientId() == iForegroundAppUid)
        {
        iServer->CloseAppsFinished(0, ETrue);    
        }     
#endif
   
   TRACES2("CMemoryMonitor::RefreshThresholds: Current Good Threshold = %d, Current Low Threshold = %d", iGoodThreshold, iLowThreshold);
    }

void CMemoryMonitor::ResetTargets(TInt aTarget)
    {
    FUNC_LOG;

    //we reset the target when a memory free operation completes, to deal with the case
    //where the operation was initiated with a target larger than the current good threshold
    iCurrentTarget = aTarget;
    iGOomActionList->SetCurrentTarget(iCurrentTarget);
    }

void CMemoryMonitor::SetPriorityBusy(TInt aWgId)
    {
    FUNC_LOG;
    
    TRACES2("Received SetPriorityBusy for appid = %x, wgid = %d", iGOomWindowGroupList->AppIdfromWgId(aWgId, ETrue), aWgId);
    iGOomWindowGroupList->SetPriorityBusy(aWgId);
    AppClosePriorityChanged(aWgId, RGOomMonitorSession::EGOomPriorityBusy);
    }

void CMemoryMonitor::SetPriorityNormal(TInt aWgId)
    {
    FUNC_LOG;

    iGOomWindowGroupList->SetPriorityNormal(aWgId);
    AppClosePriorityChanged(aWgId, RGOomMonitorSession::EGOomPriorityNormal);
    }

void CMemoryMonitor::SetPriorityHigh(TInt aWgId)
    {
    FUNC_LOG;
    
    iGOomWindowGroupList->SetPriorityHigh(aWgId);
    AppClosePriorityChanged(aWgId, RGOomMonitorSession::EGOomPriorityHigh);
    }

TInt CMemoryMonitor::GetFreeMemory()
    {
	FUNC_LOG;
    if (!eglQueryProfilingData)
        {
    	TRACES("EGL_NOK_resource_profiling not available");
	    return 0;
        }
    EGLint data_count;
    EGLint* prof_data;
    TInt i(0);
    TInt totalMem(0);
    TInt totalUsed(0);
	EGLDisplay dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);

	/* Find out how much profiling data is available */
	eglQueryProfilingData(dpy, EGL_PROF_QUERY_GLOBAL_BIT_NOK | EGL_PROF_QUERY_MEMORY_USAGE_BIT_NOK,
							NULL, 0, &data_count);

	TRACES1("eglQueryProfilingData - data size: %d", data_count);


	/* Allocate room for the profiling data */
	prof_data = (EGLint*)User::Alloc(data_count * sizeof(EGLint));
	if (prof_data == NULL)
	    {
    	TRACES1("eglQueryProfilingData - could not alloc: %d", data_count * sizeof(EGLint));	
		return KErrNoMemory;
        }

	/* Retrieve the profiling data */
	eglQueryProfilingData(dpy,
							 EGL_PROF_QUERY_GLOBAL_BIT_NOK |
							 EGL_PROF_QUERY_MEMORY_USAGE_BIT_NOK,
							 prof_data,
							 data_count,
							 &data_count);

	/* Iterate over the returned data */
	while (i < data_count)
		{
		TRACES2("EGL_NOK_resource_profiling - index: %d data: %d", i, prof_data[i]);
		
		switch (prof_data[i++])
			{
			case EGL_PROF_USED_MEMORY_NOK:
				{
				totalUsed = prof_data[i++];
				TRACES1("EGL_NOK_resource_profiling - total Used: %d", totalUsed);

				break;
				}
			case EGL_PROF_TOTAL_MEMORY_NOK:
				{
				totalMem = prof_data[i++];
				TRACES1("EGL_NOK_resource_profiling - total Mem: %d", totalMem);
				break;
				}
		    case EGL_PROF_PROCESS_ID_NOK:
                {
                if (sizeof(EGLNativeProcessIdTypeNOK) == 8)
                    {
                    i+=2;
                    }
                else
                    {
                    i++;
                    }
                break;
                }
            case EGL_PROF_PROCESS_USED_PRIVATE_MEMORY_NOK:
            case EGL_PROF_PROCESS_USED_SHARED_MEMORY_NOK:
			default:
				{
                i++;
				break;
				}
			}
		}

	/* Free allocated memory */
	User::Free(prof_data);
	
	 
    if ((totalMem-totalUsed) < 0)
	    {
	    return 0;
	    }
    return totalMem - totalUsed;
    }

void CMemoryMonitor::DoPostponedMemoryGood()
    {
    FUNC_LOG;
    TInt current = GetFreeMemory();
    if(current >= iGoodThreshold  && (!NeedToPostponeMemGood()))
        {
        TRACES("DoPostponedMemoryGood calling MemoryGOOD");
        iGOomActionList->MemoryGood();
        }
    }    


void CMemoryMonitor::AppClosePriorityChanged(TInt aWgId, TInt aPriority)
    {
    FUNC_LOG;
    CGOomCloseAppConfig* appCloseConfig = NULL;
    
    TRACES1("CMemoryMonitor::AppClosePriorityChanged wgid %d", aWgId);
    
    switch(aPriority)
    {
    case RGOomMonitorSession::EGOomPriorityBusy:
        appCloseConfig = iConfig->GetApplicationConfig(KGOomBusyAppId).GetAppCloseConfig();
        TRACES("CMemoryMonitor::AppClosePriorityChanged BUSY");
        break;
    case RGOomMonitorSession::EGOomPriorityHigh:
        appCloseConfig = iConfig->GetApplicationConfig(KGOomHighPriorityAppId).GetAppCloseConfig();
        TRACES("CMemoryMonitor::AppClosePriorityChanged HIGH");
        break;
    default:
        appCloseConfig = iConfig->GetApplicationConfig(aWgId).GetAppCloseConfig();
        TRACES("CMemoryMonitor::AppClosePriorityChanged NORMAL");
    }
        
    if (appCloseConfig)
        {  
        TInt32 appId = iGOomWindowGroupList->AppIdfromWgId(aWgId, ETrue);
        TInt wgIndex=iGOomWindowGroupList->GetIndexFromAppId(appId);
        
        TRACES2("CMemoryMonitor::AppClosePriorityChanged wgindex %d, appid %x", wgIndex, appId);
        
        if(wgIndex>=0)
            {
            TRACES2("CMemoryMonitor::AppClosePriorityChanged Setting Priority for app %x, wgid %d", appId, aWgId);
            TUint priority = appCloseConfig->CalculateCloseAppPriority(*iGOomWindowGroupList, wgIndex);
            iGOomActionList->SetPriority(wgIndex, priority);
            }
        else
            {
            TRACES1("CMemoryMonitor::AppClosePriorityChanged Could not find wgid %d in windogouplist", aWgId);
            }
        }
    else
        {
        TRACES("CMemoryMonitor::AppClosePriorityChanged appCloseConfig not found");
        }
    }

CGOomWindowGroupList * CMemoryMonitor::GetWindowGroupList() const
{
    return iGOomWindowGroupList; 
}
