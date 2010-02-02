/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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


#ifndef GOOMMEMORYMONITOR_H
#define GOOMMEMORYMONITOR_H

#include <e32property.h>
#include <f32file.h>
#include <w32std.h>
#include <EGL/egl.h>
#include "goomglobalconfig.h"
#include "goomwindowgrouplist.h"

// ---------------------------------------------------------
// CMemoryMonitor
// ---------------------------------------------------------
//
class CGOomMonitorPlugin;
class CMemoryMonitorServer;
class CWservEventReceiver;
class CGOomActionList;
class CGOomLogger;
class CGOomConfig;
class CGoomThresholdCrossed;

typedef EGLBoolean (*NOK_resource_profiling)(EGLDisplay, EGLint, EGLint*, EGLint, EGLint*);

NONSHARABLE_CLASS(CMemoryMonitor) : public CBase
    {
public:
    static CMemoryMonitor* NewL();
    ~CMemoryMonitor();

public: // event handlers
    void FreeMemThresholdCrossedL(TInt aAction = 0, TInt aThreshold = 0);
    void AppNotExiting(TInt aWgId);
    void StartFreeSomeRamL(TInt aTargetFree);
    void FreeOptionalRamL(TInt aTargetFree, TInt aPluginId, TBool aUseAbsolute = EFalse); // The ID of the plugin that will clear up the allocation, used to determine the priority of the allocation
    void RequestFreeMemoryL(TInt aTargetFree, TBool aUseAbsolute = EFalse);
    void HandleFocusedWgChangeL(TInt aForegroundAppUid = KErrNotFound);
    static const CGOomGlobalConfig& GlobalConfig();
    void SetPriorityBusy(TInt aWgId);
    void SetPriorityNormal(TInt aWgId);
    void SetPriorityHigh(TInt aWgId);
    void ResetTargets(TInt aTarget = 0);
    TInt GetFreeMemory();
    void RunCloseAppActions(TInt aMaxPriority);
    CGOomWindowGroupList * GetWindowGroupList() const;
        
    
    void SetActiveClient(TInt aClientId)
        {
        iActiveClientId = aClientId;
        }  
    
    TInt ActiveClientId()
        {
        return iActiveClientId;
        }

    TInt ForegroundAppUid()
        {
        return iForegroundAppUid;
        } 
    void SessionInCriticalAllocation(TBool aPostponeMemGood)
        {
        if (aPostponeMemGood)
            {
            iPostponeMemGood++;
            }
        else
            {
            iPostponeMemGood--;
            if(iPostponeMemGood<0)
                {
                iPostponeMemGood = 0;
                }
            }
                        
        if (iPostponeMemGood == 0)
            {
            DoPostponedMemoryGood();
            }
        
        } 
    
    void DoPostponedMemoryGood();
    
    TBool NeedToPostponeMemGood()
        {
        return (iPostponeMemGood != 0);
        } 
    
private:
    CMemoryMonitor();
    void ConstructL();
    TBool FreeGraphicsMemoryAboveThresholdL(TInt& aCurrentFreeMemory);
    void CloseNextApp();
    void RefreshThresholds(TInt aForegroundAppUid = KErrNotFound);
    void StartFreeSomeRamL(TInt aTargetFree, TInt aMaxPriority);
    void AppClosePriorityChanged(TInt aWgId, TInt aPriority);
    
public:
    // All members are owned
    // generally useful sessions
    RFs iFs;
    RWsSession iWs;

private: //data

    // parameters for GOOM watcher.
    TInt iLowThreshold;
    TInt iGoodThreshold;
    TInt iCurrentTarget;
        
    // event receivers
    CWservEventReceiver* iWservEventReceiver;

    /**
     * The Memory Monitor Server
     * Own.       
     */
    CMemoryMonitorServer* iServer;
    
#ifdef _DEBUG    
    /**
     * GOom logging tool - samples free memory for profiling
     * Own.       
     */
    CGOomLogger* iLogger;
#endif
    
    /**
     * A list of window group Ids, with child window groups removed such that there is one Id per application
     * Own.       
     */    
    CGOomWindowGroupList* iGOomWindowGroupList;
    
    /**
     * The object responsible for identifying the best actions to run, and running them 
     * Own.       
     */
    CGOomActionList* iGOomActionList;
    
    /**
     * The entire GOom Monitor configuration
     * Own.       
     */
    CGOomConfig* iConfig;
    
    // resource profiling extension function ptr
    NOK_resource_profiling eglQueryProfilingData;
    
    TInt iActiveClientId;
    
    // could use pointer array
    CGoomThresholdCrossed* iMemAllocationsGrowing;
    CGoomThresholdCrossed* iMemAllocationsGoingDown;
    
    TInt iForegroundAppUid;
    TInt iPostponeMemGood;
    };

#endif /*GOOMMEMORYMONITOR_H*/
