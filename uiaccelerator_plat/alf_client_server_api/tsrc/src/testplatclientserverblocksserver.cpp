/*
* Copyright (c) 2002 - 2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  test functions for alf client server api
*
*/



// [INCLUDE FILES]
#include <e32svr.h>
#include <coemain.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <alf/alfappserver.h>
#include <alf/alfappsrvsessionbase.h>
#include <aknserverapp.h> 

#include "testplatclientserver.h"

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerNewAppServerL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerNewAppServerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerNewAppServerL, "In TestServerNewAppServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerNewAppServerL );
    // Print to log file
    iLog->Log( KTestServerNewAppServerL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    delete appServer;
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerHandleClientExitL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerHandleClientExitL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerHandleClientExitL, "In TestServerHandleClientExitL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerHandleClientExitL );
    // Print to log file
    iLog->Log( KTestServerHandleClientExitL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    appServer->HandleClientExit( 0 );
    
    CleanupStack::PopAndDestroy( appServer );
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerAdjustWindowGroupPositionL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerAdjustWindowGroupPositionL( 
    CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAdjustWindowGroupPositionL, 
                                     "In TestServerAdjustWindowGroupPositionL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver,
                                         KTestServerAdjustWindowGroupPositionL );
    // Print to log file
    iLog->Log( KTestServerAdjustWindowGroupPositionL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CCoeEnv* coe = CCoeEnv::Static();
    RWindowGroup& mainWg = coe->RootWin();
    appServer->AdjustWindowGroupPositionL( mainWg, 1, CAlfAppServer::EBehindOfParent );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerWsSessionL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerWsSessionL( 
    CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerWsSessionL, "In TestServerWsSessionL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerWsSessionL );
    // Print to log file
    iLog->Log( KTestServerWsSessionL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    appServer->WsSession();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerMetricsInterfaceL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerMetricsInterfaceL( 
    CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerMetricsInterfaceL, 
                                         "In TestServerMetricsInterfaceL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                                  KTestServerMetricsInterfaceL );
    // Print to log file
    iLog->Log( KTestServerMetricsInterfaceL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    appServer->MetricsInterface();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerMetricsInterfaceConstL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerMetricsInterfaceConstL( 
    CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerMetricsInterfaceConstL, 
                                         "In TestServerMetricsInterfaceConstL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                             KTestServerMetricsInterfaceConstL );
    // Print to log file
    iLog->Log( KTestServerMetricsInterfaceConstL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    ( ( const CAlfAppServer* ) appServer )->MetricsInterface();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerSetMetricsInterfaceL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerSetMetricsInterfaceL( 
    CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerSetMetricsInterfaceL, "In TestServerSetMetricsInterfaceL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerSetMetricsInterfaceL );
    // Print to log file
    iLog->Log( KTestServerSetMetricsInterfaceL );
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    appServer->SetMetricsInterface( NULL );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerAppUiL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerAppUiL( 
    CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAppUiL, "In TestServerAppUiL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAppUiL );
    // Print to log file
    iLog->Log( KTestServerAppUiL );
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    appServer->AppUi();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    }

//  [End of File]
