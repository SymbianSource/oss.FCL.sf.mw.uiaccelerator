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


#include "goommonitorclientserver.h"
#include "goommemorymonitorsession.h"
#include "goommemorymonitor.h"
#include "goommemorymonitorserver.h"
#include "goomtraces.h"

CMemoryMonitorSession::CMemoryMonitorSession()
    {
    FUNC_LOG;
    }

void CMemoryMonitorSession::CreateL()
    {
    FUNC_LOG;
    }

CMemoryMonitorSession::~CMemoryMonitorSession()
    {
    FUNC_LOG;
    if (iUseAbsoluteTargets)
        { // se3ssion terminated while on critical allocation, release lock
        Server().Monitor().SessionInCriticalAllocation(0);
        }
    CloseAppsFinished(0, EFalse);
    }

CMemoryMonitorServer& CMemoryMonitorSession::Server()
    {
    FUNC_LOG;

    return *static_cast<CMemoryMonitorServer*>(const_cast<CServer2*>(CSession2::Server()));
    }

CMemoryMonitor& CMemoryMonitorSession::Monitor()
    {
    FUNC_LOG;

    return Server().Monitor();
    }

void CMemoryMonitorSession::ServiceL(const RMessage2& aMessage)
    {
    FUNC_LOG;
    
    iFunction = aMessage.Function();
    RThread t;
    aMessage.Client(t);
    Server().Monitor().SetActiveClient(t.SecureId());
    t.Close();
    
    switch (aMessage.Function())
        {
        case EGOomMonitorRequestFreeMemory:
            if (!iRequestFreeRam.IsNull())
                {
                aMessage.Complete(KErrInUse);
                return;
                }
            // message will be completed when CloseAppsFinished() is called.
            if (aMessage.Int1() == 0)
                {
                iRequestFreeRam = aMessage;

                TRAPD(err, Monitor().RequestFreeMemoryL(aMessage.Int0(), iUseAbsoluteTargets));
                if (err)
                    {
                    // completes the message if that was left to pending
                    CloseAppsFinished(0, EFalse);
                    }
                }
            else
                {
                TInt appUid = aMessage.Int1();
                // if no new memory was needed, the message is completed synchronously
                iRequestFreeRam = aMessage;
                TRAP_IGNORE(Monitor().HandleFocusedWgChangeL(appUid));
                }
            break;

        case EGOomMonitorCancelRequestFreeMemory:
            if (!iRequestFreeRam.IsNull())
                {
                iRequestFreeRam.Complete(KErrCancel);
                }
            aMessage.Complete(KErrNone);
            break;

        case EGOomMonitorThisAppIsNotExiting:
            Monitor().AppNotExiting(aMessage.Int0());
            aMessage.Complete(KErrNone);
            break;

        case EGOomMonitorRequestOptionalRam:
            if (!iRequestFreeRam.IsNull())
                {
                aMessage.Complete(KErrInUse);
                }
            // message will be completed when CloseAppsFinished() is called.
            iRequestFreeRam = aMessage;
            iMinimumMemoryRequested = aMessage.Int1();
            Monitor().FreeOptionalRamL(aMessage.Int0(), aMessage.Int2(), iUseAbsoluteTargets);
            break;
            
        case EGOomMonitorSetPriorityBusy:
            Monitor().SetPriorityBusy(aMessage.Int0());
            aMessage.Complete(KErrNone);
            break;
            
        case EGOomMonitorSetPriorityNormal:
               Monitor().SetPriorityNormal(aMessage.Int0());
            aMessage.Complete(KErrNone);
            break;

        case EGOomMonitorSetPriorityHigh:
               Monitor().SetPriorityHigh(aMessage.Int0());
            aMessage.Complete(KErrNone);
            break;

        case EGoomMonitorAppAboutToStart:
            {
            TInt appUid = aMessage.Int0();
            aMessage.Complete(KErrNone);  
            TRAP_IGNORE(Monitor().HandleFocusedWgChangeL(appUid))
            break;
            }
        case EGoomMonitorAppUsesAbsoluteMemTargets:
            {
            iUseAbsoluteTargets = aMessage.Int0();
            TRACES2("EGoomMonitorAppUsesAbsoluteMemTargets this: 0x%x, use abs targets %d", this, iUseAbsoluteTargets);
            Server().Monitor().SessionInCriticalAllocation(iUseAbsoluteTargets);
            aMessage.Complete(KErrNone);     
            break;
            }    
            
        default:
            PanicClient(aMessage, EPanicIllegalFunction);
            break;
        }
    }

void CMemoryMonitorSession::CloseAppsFinished(TInt aBytesFree, TBool aMemoryGood)
    {
    FUNC_LOG;

    if (!iRequestFreeRam.IsNull())
        {
        if (iFunction == EGOomMonitorRequestOptionalRam)
            {
            TInt memoryAvailable = aBytesFree - CMemoryMonitor::GlobalConfig().iGoodRamThreshold;
            
            // If memory available is greater than the requested RAM then complete with the amount of free memory, otherwise complete with KErrNoMemory
            if (memoryAvailable >= iMinimumMemoryRequested)
                {
                iRequestFreeRam.Complete(memoryAvailable);
                }
            else
                {
                iRequestFreeRam.Complete(KErrNoMemory);
                }
            }
        else 
            iRequestFreeRam.Complete(aMemoryGood ? KErrNone : KErrNoMemory);
        }
    Server().Monitor().SetActiveClient(0);
    }
