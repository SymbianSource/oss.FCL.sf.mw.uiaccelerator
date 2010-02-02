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
* Description:  Classes for executing GOOM actions (e.g. closing applications and running plugins).
*
*/


#include <apgtask.h>

#include "goomcloseapp.h"
#include "goomtraces.h"
#include "goomappclosetimer.h"
#include "goomappclosewatcher.h"
#include "goomactionref.h"

const TInt KGOomMaxAppExitTime = 1000000;
const TInt KGOomMaxAppAfterKillWaitTime = 1000000;

CGOomCloseApp* CGOomCloseApp::NewL(MGOomActionObserver& aStateChangeObserver, RWsSession& aWs)
    {
    FUNC_LOG;

    CGOomCloseApp* self = new (ELeave) CGOomCloseApp(aStateChangeObserver, aWs);
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    return self;
    }

// Close the application in order to free memory
// Call the CGOomAction::MemoryFreed when it is done
void CGOomCloseApp::FreeMemory(TInt)
    {
    FUNC_LOG;

    iAppCloserRunning = ETrue;
    
    // Set the TApaTask to the app
    iCurrentTask.SetWgId(iWgId);
    
    // Start a timer and the thread watcher 
    iAppCloseTimer->SetState(CGOomAppCloseTimer::EGOomAppClosing);
    iAppCloseTimer->After(KGOomMaxAppExitTime);
    iAppCloseWatcher->Start(iCurrentTask);
    // Tell the app to close
    TRACES1("CGOomCloseApp::FreeMemory: Closing app with window group id %d",iWgId);
    iCurrentTask.EndTask();
    }

CGOomCloseApp::~CGOomCloseApp()
    {
    FUNC_LOG;

    if (iAppCloseTimer)
        iAppCloseTimer->Cancel();
    
    if (iAppCloseWatcher)
        iAppCloseWatcher->Cancel();
    
    delete iAppCloseTimer;    
    delete iAppCloseWatcher;
    }

// Callback from CGOomAppCloseWatcher and CGOomAppCloseTimer
void CGOomCloseApp::CloseAppEvent()
    {
    FUNC_LOG;

    // The application has closed (or we have a timeout)
    iAppCloserRunning = EFalse;
    
    if (iAppCloseTimer)
        iAppCloseTimer->Cancel();
    if (iAppCloseWatcher)
        iAppCloseWatcher->Cancel(); 
    
    iAppCloseTimer->SetState(CGOomAppCloseTimer::EGOomAppKilled);
    iAppCloseTimer->After(KGOomMaxAppAfterKillWaitTime);
    //MemoryFreed(KErrNone);
    }

void CGOomCloseApp::Reconfigure(const TActionRef& aRef)
    {
    FUNC_LOG;

    iWgId = aRef.WgId();    
    }

void CGOomCloseApp::ConstructL()
    {
    FUNC_LOG;

    iAppCloseTimer = CGOomAppCloseTimer::NewL(*this);
    iAppCloseWatcher = new(ELeave) CGOomAppCloseWatcher(*this);
    }
        
CGOomCloseApp::CGOomCloseApp(MGOomActionObserver& aStateChangeObserver, RWsSession& aWs)
                                : CGOomAction(aStateChangeObserver), iCurrentTask(aWs)
    {
    FUNC_LOG;
    }

// ----------------------------------------------
// Callback from iAppCloseTimer
// App refused to exit gracefully on given time
// ----------------------------------------------
//
void CGOomCloseApp::KillTask()
    {
    FUNC_LOG;
    if (iAppCloseWatcher)
        {
        iAppCloseWatcher->Cancel(); 
        }
    
    iCurrentTask.KillTask();
    iAppCloserRunning = EFalse;
    
    iAppCloseTimer->SetState(CGOomAppCloseTimer::EGOomAppKilled);
    iAppCloseTimer->After(KGOomMaxAppAfterKillWaitTime);
    //MemoryFreed(KErrNone);
    }

void CGOomCloseApp::KillTaskWaitDone()
    {
    FUNC_LOG;
    MemoryFreed(KErrNone);
    }

