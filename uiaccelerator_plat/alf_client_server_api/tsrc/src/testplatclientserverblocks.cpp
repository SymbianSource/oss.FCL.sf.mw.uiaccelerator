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
#include <stifparser.h>
#include <stiftestinterface.h>

#include "testplatclientserver.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CTestPlatClientServer::RunMethodL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::RunMethodL( CStifItemParser& aItem ) 
    {

    static TStifFunctionInfo const KFunctions[] =
        {  
        // First string is the function name used in TestScripter script file.
        // Second is the actual implementation member function. 
        ENTRY( "TestServerNewAppServerL",
                                CTestPlatClientServer::TestServerNewAppServerL ),
        ENTRY( "TestServerHandleClientExitL",
                            CTestPlatClientServer::TestServerHandleClientExitL ),
        ENTRY( "TestServerAdjustWindowGroupPositionL",
                   CTestPlatClientServer::TestServerAdjustWindowGroupPositionL ),
        ENTRY( "TestServerWsSessionL",
                                   CTestPlatClientServer::TestServerWsSessionL ),
        ENTRY( "TestServerMetricsInterfaceL",
                            CTestPlatClientServer::TestServerMetricsInterfaceL ),
        ENTRY( "TestServerMetricsInterfaceConstL",
                       CTestPlatClientServer::TestServerMetricsInterfaceConstL ),
        ENTRY( "TestServerSetMetricsInterfaceL",
                       CTestPlatClientServer::TestServerSetMetricsInterfaceL ),
        ENTRY( "TestServerAppUiL", CTestPlatClientServer::TestServerAppUiL ),
                       
        //alfappsrvsessionbase.h
        ENTRY( "TestServerCAlfAppSrvSessionBaseServerL", 
                 CTestPlatClientServer::TestServerCAlfAppSrvSessionBaseServerL ),
        ENTRY( "TestServerCAlfAppSrvSessionBaseL", 
                       CTestPlatClientServer::TestServerCAlfAppSrvSessionBaseL ),
        ENTRY( "TestServerClientDrawingAreaL", 
                           CTestPlatClientServer::TestServerClientDrawingAreaL ),
        ENTRY( "TestServerAppendDisplayOnSharedWindowL", 
                           CTestPlatClientServer::TestServerAppendDisplayOnSharedWindowL ),        
        ENTRY( "TestServerHandleSystemEventL", 
                           CTestPlatClientServer::TestServerHandleSystemEventL ),  
        ENTRY( "TestServerHandleWsEventL", 
                           CTestPlatClientServer::TestServerHandleWsEventL ),                             
        ENTRY( "TestServerFrameworkCallsRendezvousL", 
                           CTestPlatClientServer::TestServerFrameworkCallsRendezvousL ),  
        ENTRY( "TestServerHandleResourceChangeL", 
                           CTestPlatClientServer::TestServerHandleResourceChangeL ),                             
        ENTRY( "TestServerHandleCommandL", 
                           CTestPlatClientServer::TestServerHandleCommandL ),
        
        //alfappsrvsessionbase.h
        ENTRY( "TestServerCAlfAppUiL", 
                                   CTestPlatClientServer::TestServerCAlfAppUiL ),
        ENTRY( "TestServerContainerL", 
                                   CTestPlatClientServer::TestServerContainerL ),
        ENTRY( "TestServerConstructL", 
                                   CTestPlatClientServer::TestServerConstructL ),
        ENTRY( "TestServerFocusGainedLL", 
                                CTestPlatClientServer::TestServerFocusGainedLL ),
        ENTRY( "TestServerFocusLostL", 
                                   CTestPlatClientServer::TestServerFocusLostL ),
        ENTRY( "TestServerPreferredWindowGroupPositionL", 
                CTestPlatClientServer::TestServerPreferredWindowGroupPositionL ),
        ENTRY( "TestServerPreferredRefreshModeL", 
                        CTestPlatClientServer::TestServerPreferredRefreshModeL ),
        ENTRY( "TestServerAlfServerL", 
                                   CTestPlatClientServer::TestServerAlfServerL ),
        ENTRY( "TestServerAlfAppUiL", 
                                    CTestPlatClientServer::TestServerAlfAppUiL ),
        ENTRY( "TestServerLayoutManagerL", 
                               CTestPlatClientServer::TestServerLayoutManagerL ),
        ENTRY( "TestServerSharedHuiEnvL", 
                                CTestPlatClientServer::TestServerSharedHuiEnvL ),
        ENTRY( "TestServerHandleCurrentCommanndAsynchL", 
                 CTestPlatClientServer::TestServerHandleCurrentCommanndAsynchL ),
        ENTRY( "TestServerBaseConstructL", 
                               CTestPlatClientServer::TestServerBaseConstructL ),
        ENTRY( "TestServerGetInterfaceLL", 
                               CTestPlatClientServer::TestServerGetInterfaceLL ),        
        ENTRY( "TestServerGetHandleFromInterfaceL", 
                               CTestPlatClientServer::TestServerGetHandleFromInterfaceL ),
        ENTRY( "TestServerCompleteCmdL", 
                               CTestPlatClientServer::TestServerCompleteCmdL ), 
        ENTRY( "TestServerAlfInterfaceProviderExtensionL", 
                               CTestPlatClientServer::TestServerAlfInterfaceProviderExtensionL ),   
                               
        //alfclientbase.h
        ENTRY( "TestServerRAlfClientBaseL", 
                              CTestPlatClientServer::TestServerRAlfClientBaseL ),
        ENTRY( "TestServerOpenL", CTestPlatClientServer::TestServerOpenL ),
        ENTRY( "TestServerServiceUidL", 
                                  CTestPlatClientServer::TestServerServiceUidL ),
        ENTRY( "TestServerGrantAccessToPrivateFileL", 
                    CTestPlatClientServer::TestServerGrantAccessToPrivateFileL ),
        ENTRY( "TestServerGrantAccessToPrivateRFileL", 
                    CTestPlatClientServer::TestServerGrantAccessToPrivateRFileL ),
        ENTRY( "TestServerConstructServerNameL", 
                    CTestPlatClientServer::TestServerConstructServerNameL ),
        ENTRY( "TestServerStartServerLL", 
                    CTestPlatClientServer::TestServerStartServerLL ),                    
        ENTRY( "TestServerLaunchAppL", 
                    CTestPlatClientServer::TestServerLaunchAppL ),   
                    
       // [test cases entries]

        };

    const TInt count = sizeof( KFunctions ) / sizeof( TStifFunctionInfo );

    return RunInternalL( KFunctions, count, aItem );

    }


//  [End of File]
