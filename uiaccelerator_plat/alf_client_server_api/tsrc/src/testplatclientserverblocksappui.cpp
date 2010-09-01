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
#include <alf/alfappui.h>
#include <aknserverapp.h> 

#include "testplatclientserver.h"

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerCAlfAppUiL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerCAlfAppUiL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerCAlfAppUiL, "In TestServerCAlfAppUiL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerCAlfAppUiL );
    // Print to log file
    iLog->Log( KTestServerCAlfAppUiL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    delete appUI;
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerContainerL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerContainerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerContainerL, "In TestServerContainerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerContainerL );
    // Print to log file
    iLog->Log( KTestServerContainerL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
    appUI->ConstructL();
    appUI->Container();  
    
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerConstructL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerConstructL, "In TestServerConstructL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerConstructL );
    // Print to log file
    iLog->Log( KTestServerConstructL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
    
    appUI->ConstructL();  
    
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerAppendDisplayOnSharedWindowL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerAppendDisplayOnSharedWindowL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAppendDisplayOnSharedWindowL, "In TestServerAppendDisplayOnSharedWindowL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAppendDisplayOnSharedWindowL);
    // Print to log file
    iLog->Log( KTestServerAppendDisplayOnSharedWindowL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
    
    CHuiEnv* huiEnv = CHuiEnv::NewL( EHuiRendererBitgdi ); 
    CleanupStack::PushL( huiEnv );
    
    TInt temp = 10;
    TRect displayRect( TPoint( temp, temp ), TPoint( temp, temp) );
    CHuiDisplay* huiDisplay = &huiEnv->NewDisplayL(displayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);  
    appUI->AppendDisplayOnSharedWindowL( *huiDisplay );
    
    CleanupStack::PopAndDestroy( huiEnv );
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerHandleSystemEventL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerHandleSystemEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerHandleSystemEventL, "In TestServerHandleSystemEventL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerHandleSystemEventL);
    // Print to log file
    iLog->Log( KTestServerHandleSystemEventL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
 
    TWsEvent event;
    appUI->HandleSystemEventL( event );
    

    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerHandleWsEventL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerHandleWsEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerHandleWsEventL, "In TestServerHandleWsEventL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerHandleWsEventL);
    // Print to log file
    iLog->Log( KTestServerHandleWsEventL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
 
    TWsEvent event;
    CCoeControl control;
    appUI->HandleWsEventL( event, &control );
    
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerFrameworkCallsRendezvousL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerFrameworkCallsRendezvousL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerFrameworkCallsRendezvousL, "In TestServerFrameworkCallsRendezvousL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerFrameworkCallsRendezvousL);
    // Print to log file
    iLog->Log( KTestServerFrameworkCallsRendezvousL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
 
    appUI->FrameworkCallsRendezvous();
    
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerHandleResourceChangeL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerHandleResourceChangeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerHandleResourceChangeL, "In TestServerHandleResourceChangeL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerHandleResourceChangeL);
    // Print to log file
    iLog->Log( KTestServerHandleResourceChangeL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
 
    TInt temp = 0;
    appUI->HandleResourceChangeL( temp );
    
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerHandleCommandL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerHandleCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerHandleCommandL, "In TestServerHandleCommandL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerHandleCommandL);
    // Print to log file
    iLog->Log( KTestServerHandleCommandL );

    CAlfAppUi* appUI = new ( ELeave ) CAlfAppUi();
    CleanupStack::PushL( appUI );
 
    TInt temp = 0;
    appUI->HandleCommandL( temp );
    
    CleanupStack::PopAndDestroy( appUI );
    
    return KErrNone;

    }

//  [End of File]
