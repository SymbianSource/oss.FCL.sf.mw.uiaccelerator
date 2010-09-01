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

// implement the CAlfAppSrvSessionBase 
class CAlfAppSrvSessionBaseImp: public CAlfAppSrvSessionBase
    {
public:
    //test CAlfAppSrvSessionBase constructor with one paramet
    CAlfAppSrvSessionBaseImp(const CAlfAppServer* aServer)
        :CAlfAppSrvSessionBase( aServer )
        {
        }
    //test CAlfAppSrvSessionBase constructor with on paramet
    CAlfAppSrvSessionBaseImp():CAlfAppSrvSessionBase()
        {
        }
    
    //inherit from CAlfAppSrvSessionBase
    void DoHandleCommandL(const RMessage2& aMessage)
        {
        }
    
    // test baseconstructor in CAlfAppSrvSessionBase
    void TestBaseConstructL()
        {
        CAlfAppSrvSessionBase::BaseConstructL();
        }
    };

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerCAlfAppSrvSessionBaseServerL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerCAlfAppSrvSessionBaseServerL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerCAlfAppSrvSessionBaseServerL, 
                                   "In TestServerCAlfAppSrvSessionBaseServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                       KTestServerCAlfAppSrvSessionBaseServerL );
    // Print to log file
    iLog->Log( KTestServerCAlfAppSrvSessionBaseServerL );

    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );

    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerCAlfAppSrvSessionBaseL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerCAlfAppSrvSessionBaseL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerCAlfAppSrvSessionBaseL, 
                                         "In TestServerCAlfAppSrvSessionBaseL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                             KTestServerCAlfAppSrvSessionBaseL );
    // Print to log file
    iLog->Log( KTestServerCAlfAppSrvSessionBaseL );
    
    CAlfAppSrvSessionBase* sessionBase = 
                                      new ( ELeave ) CAlfAppSrvSessionBaseImp( );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerClientDrawingAreaL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerClientDrawingAreaL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerCAlfAppSrvSessionBaseL, 
                                         "In TestServerCAlfAppSrvSessionBaseL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                             KTestServerCAlfAppSrvSessionBaseL );
    // Print to log file
    iLog->Log( KTestServerCAlfAppSrvSessionBaseL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    

    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->ClientDrawingArea();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerFocusGainedLL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerFocusGainedLL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerFocusGainedLL, "In TestServerFocusGainedLL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerFocusGainedLL );
    // Print to log file
    iLog->Log( KTestServerFocusGainedLL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->FocusGainedL( ETrue );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerFocusLostL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerFocusLostL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerFocusGainedLL, "In TestServerFocusGainedLL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerFocusGainedLL );
    // Print to log file
    iLog->Log( KTestServerFocusGainedLL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->FocusLostL( ETrue );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerPreferredWindowGroupPositionL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerPreferredWindowGroupPositionL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerPreferredWindowGroupPositionL, 
                                  "In TestServerPreferredWindowGroupPositionL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                      KTestServerPreferredWindowGroupPositionL );
    // Print to log file
    iLog->Log( KTestServerPreferredWindowGroupPositionL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->PreferredWindowGroupPosition();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerPreferredRefreshModeL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerPreferredRefreshModeL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerPreferredRefreshModeL, 
                                          "In TestServerPreferredRefreshModeL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                              KTestServerPreferredRefreshModeL );
    // Print to log file
    iLog->Log( KTestServerPreferredRefreshModeL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->PreferredRefreshMode();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerAlfServerL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerAlfServerL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAlfServerL, "In TestServerAlfServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAlfServerL );
    // Print to log file
    iLog->Log( KTestServerAlfServerL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->AlfServer();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerAlfAppUiL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerAlfAppUiL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAlfServerL, "In TestServerAlfServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAlfServerL );
    // Print to log file
    iLog->Log( KTestServerAlfServerL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->AlfAppUi();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerLayoutManagerL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerLayoutManagerL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAlfServerL, "In TestServerAlfServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAlfServerL );
    // Print to log file
    iLog->Log( KTestServerAlfServerL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->LayoutManager();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerSharedHuiEnvL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerSharedHuiEnvL( 
   CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAlfServerL, "In TestServerAlfServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAlfServerL );
    // Print to log file
    iLog->Log( KTestServerAlfServerL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->SharedHuiEnv();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerHandleCurrentCommanndAsynchL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerHandleCurrentCommanndAsynchL( 
   CStifItemParser& /*aItem*/ )
    {
    
    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerHandleCurrentCommanndAsynchLL, 
                                   "In TestServerHandleCurrentCommanndAsynchL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, 
                                      KTestServerHandleCurrentCommanndAsynchLL );
    // Print to log file
    iLog->Log( KTestServerHandleCurrentCommanndAsynchLL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBase* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->HandleCurrentCommanndAsynch();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerBaseConstructL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerBaseConstructL( 
   CStifItemParser& /*aItem*/ )
    {
    
    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerBaseConstructL, "In TestServerBaseConstructL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerBaseConstructL );
    // Print to log file
    iLog->Log( KTestServerBaseConstructL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBaseImp* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->TestBaseConstructL();
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerGetInterfaceLL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerGetInterfaceLL( 
   CStifItemParser& /*aItem*/ )
    {
    
    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerGetInterfaceLL, "In TestServerGetInterfaceLL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerGetInterfaceLL );
    // Print to log file
    iLog->Log( KTestServerGetInterfaceLL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBaseImp* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    
    sessionBase->GetInterfaceL( EHuiObjectTypeVisual, 0 );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerGetHandleFromInterfaceL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerGetHandleFromInterfaceL( 
   CStifItemParser& /*aItem*/ )
    {
    
    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerGetHandleFromInterfaceL, "In TestServerGetHandleFromInterfaceL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerGetHandleFromInterfaceL );
    // Print to log file
    iLog->Log( KTestServerGetHandleFromInterfaceL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBaseImp* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );
    TBool temp =  ETrue;
    TAny* temp1 = &temp; 
    sessionBase->GetHandleFromInterface( EHuiObjectTypeVisual, &temp1 );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerCompleteCmdL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerCompleteCmdL( 
   CStifItemParser& /*aItem*/ )
    {
    
    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerCompleteCmdL, "In TestServerCompleteCmdL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerCompleteCmdL );
    // Print to log file
    iLog->Log( KTestServerCompleteCmdL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBaseImp* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );

    sessionBase->CompleteCmd( 0, 0 );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerAlfInterfaceProviderExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerAlfInterfaceProviderExtensionL( 
   CStifItemParser& /*aItem*/ )
    {
    
    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerAlfInterfaceProviderExtensionL, "In TestServerAlfInterfaceProviderExtensionL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerAlfInterfaceProviderExtensionL );
    // Print to log file
    iLog->Log( KTestServerAlfInterfaceProviderExtensionL );
    
    
    CAlfAppServer* appServer = CAlfAppServer::NewAppServerL();
    CleanupStack::PushL( appServer );
    
    CAlfAppSrvSessionBaseImp* sessionBase = 
                            new ( ELeave ) CAlfAppSrvSessionBaseImp( appServer );

    TUid tempUid = { 0 };
    TBool temp =  ETrue;
    TAny* temp1 = &temp; 
    sessionBase->AlfInterfaceProviderExtension( tempUid, &temp1 );
    
    CleanupStack::PopAndDestroy( appServer );
    
    return KErrNone;
    
    }

//  [End of File]
