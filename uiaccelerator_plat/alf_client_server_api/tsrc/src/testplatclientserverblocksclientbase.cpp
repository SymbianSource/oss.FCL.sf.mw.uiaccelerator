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
#include <alf/alfclientbase.h>
#include <aknserverapp.h> 

#include "testplatclientserver.h"

//const veriable
const TInt KAlfAppServerInterfaceUid3 = 0x10282845;
const TInt KStringSize = 50;

//The RAlfClientBaseImp class is used to test the RAlfClientBase protect member
class RAlfClientBaseImp : public RAlfClientBase
	{
public:
	RAlfClientBaseImp(TInt aServiceUid):RAlfClientBase( aServiceUid )
	{
	}
	void TestConstructServerName(
	        TName& aServerName, 
	        TUid aAppServerUid, 
	        TUint aServerDifferentiator )
		{
		RAlfClientBase::ConstructServerName( aServerName, aAppServerUid, aServerDifferentiator );
		}
	TUint TestStartServerL( TUid aAppUid )
		{
		return StartServerL( aAppUid );
		}
	void TestLaunchAppL( 
	        TUid aAppUid, 
	        TUint aServerDifferentiator, 
	        TThreadId& aThreadId )
		{
		LaunchAppL( aAppUid, aServerDifferentiator, aThreadId);
		}
	};
// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerRAlfClientBaseL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerRAlfClientBaseL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerNewAppServerL, "In TestServerNewAppServerL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerNewAppServerL );
    // Print to log file
    iLog->Log( KTestServerNewAppServerL );

    RAlfClientBase clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerOpenL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerOpenL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerOpenL, "In TestServerOpenL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerOpenL );
    // Print to log file
    iLog->Log( KTestServerOpenL );

    RAlfClientBase clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );   
    clientBase.OpenL();
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }


// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerServiceUidL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerServiceUidL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerOpenL, "In TestServerOpenL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerOpenL );
    // Print to log file
    iLog->Log( KTestServerOpenL );

    RAlfClientBase clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
    
    clientBase.OpenL();
    clientBase.ServiceUid();
    
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerGrantAccessToPrivateFileL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerGrantAccessToPrivateFileL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerOpenL, "In TestServerOpenL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerOpenL );
    // Print to log file
    iLog->Log( KTestServerOpenL );

    RAlfClientBase clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
     
    TInt objectIdentfier = 0;
    TInt commandId = 0;
    
    TBuf<KStringSize> temp;
    clientBase.GrantAccessToPrivateFile( temp, objectIdentfier, commandId );
    
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerGrantAccessToPrivateRFileL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerGrantAccessToPrivateRFileL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerGrantAccessToPrivateRFileL, "In TestServerGrantAccessToPrivateRFileL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerGrantAccessToPrivateRFileL );
    // Print to log file
    iLog->Log( KTestServerGrantAccessToPrivateRFileL );

    RAlfClientBase clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
     
    TInt objectIdentfier = 0;
    TInt commandId = 0;
    RFile file;
    clientBase.GrantAccessToPrivateFile( file, objectIdentfier, commandId);
    
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerConstructServerNameL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerConstructServerNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerConstructServerNameL, "In TestServerConstructServerNameL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerConstructServerNameL );
    // Print to log file
    iLog->Log( KTestServerConstructServerNameL );

    RAlfClientBaseImp clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
     
    TName serverName( _L("Name")); 
    TUid appServerUid = { 0 };
    TUint serverDifferentiator = 0;
    clientBase.TestConstructServerName( serverName, appServerUid, serverDifferentiator );
    
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerStartServerLL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerStartServerLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerStartServerLL, "In TestServerStartServerLL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerStartServerLL );
    // Print to log file
    iLog->Log( KTestServerStartServerLL );

    RAlfClientBaseImp clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
     

    TUid appServerUid = { 0 };
    clientBase.TestStartServerL( appServerUid );
    
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// CTestPlatClientServer::TestServerLaunchAppL
// -----------------------------------------------------------------------------
//
TInt CTestPlatClientServer::TestServerLaunchAppL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatclientserver, "testplatclientserver" );
    _LIT( KTestServerLaunchAppL, "In TestServerLaunchAppL" );
    TestModuleIf().Printf( 0, Ktestplatclientserver, KTestServerLaunchAppL );
    // Print to log file
    iLog->Log( KTestServerLaunchAppL );

    RAlfClientBaseImp clientBase( KAlfAppServerInterfaceUid3 );
    CleanupClosePushL( clientBase );
     

    TUid appUid = { 0 };
    TUint aServerDifferentiator = 0;
    TThreadId aThreadId; 
    clientBase.TestLaunchAppL( appUid, aServerDifferentiator, aThreadId );
    
    CleanupStack::PopAndDestroy( &clientBase );
    
    return KErrNone;

    }

//  [End of File]
