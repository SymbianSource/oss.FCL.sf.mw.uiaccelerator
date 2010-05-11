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



#ifndef C_TESTPLATCLIENTSERVER_H
#define C_TESTPLATCLIENTSERVER_H

//  INCLUDES
#include <stiflogger.h>
#include <testscripterinternal.h>
#include <stiftestmodule.h>
#include <testclassassert.h>

// MACROS
#define TEST_CLASS_VERSION_MAJOR 0
#define TEST_CLASS_VERSION_MINOR 0
#define TEST_CLASS_VERSION_BUILD 0

class CAlfAppServer;

// Logging path
_LIT( KtestplatclientserverLogPath, "\\logs\\testframework\\testplatclientserver\\" ); 
// Log file
_LIT( KtestplatclientserverLogFile, "testplatclientserver.txt" ); 
_LIT( KtestplatclientserverLogFileWithTitle, "testplatclientserver_[%S].txt" );

/**
*  CTestPlatClientServer test class for STIF Test Framework TestScripter.
*  @since S60 5.0
*/
NONSHARABLE_CLASS( CTestPlatClientServer ) : public CScriptBase
    {
public:  // Constructors and destructor

    /**
    * Two-phased constructor.
    */
    static CTestPlatClientServer* NewL( CTestModuleIf& aTestModuleIf );

    /**
    * Destructor.
    */
    virtual ~CTestPlatClientServer();

public: // Functions from base classes

    /**
    * From CScriptBase Runs a script line.
    * @since S60 5.0
    * @param aItem Script line containing method name and parameters
    * @return Symbian OS error code
    */
    virtual TInt RunMethodL( CStifItemParser& aItem );
    

private:

    /**
    * C++ default constructor.
    */
    CTestPlatClientServer( CTestModuleIf& aTestModuleIf );

    /**
    * By default Symbian 2nd phase constructor is private.
    */
    void ConstructL();
    
    /**
     * Method used to log version of test class
     */
    void SendTestClassVersion();
    
        /**
     * Turn off ScreenSaver
     * @since S60 5.0
     * @return Symbian OS error code.
     */
    void TurnOffScreenSaver();

    /**
     * Restore ScreenSaver
     * @since S60 5.0
     * @return Symbian OS error code.
     */
    void RestoreScreenSaver();

private: // [TestMethods]
    
    //alfappserver.h
    /**
    * TestServerNewAppServerL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerNewAppServerL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerNewAppServerL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerHandleClientExitL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerAdjustWindowGroupPositionL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerAdjustWindowGroupPositionL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerWsSessionL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerWsSessionL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerMetricsInterfaceL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerMetricsInterfaceL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerMetricsInterfaceConstL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerMetricsInterfaceConstL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerSetMetricsInterfaceL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerSetMetricsInterfaceL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerAppUiL test method in alfappserver.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerAppUiL( CStifItemParser& /*aItem*/ );
    
    //alfappsrvsessionbase.h
    /**
    * TestServerCAlfAppSrvSessionBaseServerL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerCAlfAppSrvSessionBaseServerL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerCAlfAppSrvSessionBaseL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerCAlfAppSrvSessionBaseL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerClientDrawingAreaL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerClientDrawingAreaL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerFocusGainedLL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerFocusGainedLL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerFocusLostL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerFocusLostL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerPreferredWindowGroupPositionL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerPreferredWindowGroupPositionL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerAlfServerL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerAlfServerL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerPreferredRefreshModeL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerPreferredRefreshModeL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerAlfAppUiL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerAlfAppUiL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerLayoutManagerL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerLayoutManagerL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerSharedHuiEnvL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerSharedHuiEnvL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerHandleCurrentCommanndAsynchL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerHandleCurrentCommanndAsynchL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerBaseConstructL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerBaseConstructL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerGetInterfaceLL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerGetInterfaceLL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerGetHandleFromInterfaceL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerGetHandleFromInterfaceL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerCompleteCmdL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerCompleteCmdL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerAlfInterfaceProviderExtensionL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerAlfInterfaceProviderExtensionL( CStifItemParser& /*aItem*/ );
    
    //alfappui.h
    /**
    * TestServerCAlfAppUiL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerCAlfAppUiL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerContainerL test method in alfappsrvsessionbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerContainerL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerConstructL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerConstructL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerAppendDisplayOnSharedWindowL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerAppendDisplayOnSharedWindowL( CStifItemParser& /*aItem*/ ); 
    
    /**
    * TestServerHandleSystemEventL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerHandleSystemEventL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerHandleWsEventL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerHandleWsEventL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerFrameworkCallsRendezvousL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerFrameworkCallsRendezvousL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerHandleResourceChangeL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerHandleResourceChangeL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerHandleCommandL test method in alfappui.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerHandleCommandL( CStifItemParser& /*aItem*/ ); 
    
    //alfclientbase.h
    /**
    * TestServerRAlfClientBaseL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerRAlfClientBaseL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerOpenL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerOpenL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerServiceUidL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerServiceUidL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerGrantAccessToPrivateFileL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerGrantAccessToPrivateFileL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerGrantAccessToPrivateRFileL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerGrantAccessToPrivateRFileL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerConstructServerNameL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerConstructServerNameL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerStartServerLL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerStartServerLL( CStifItemParser& /*aItem*/ );
    
    /**
    * TestServerLaunchAppL test method in alfclientbase.h.
    * @since S60 5.0
    * @param aItem no used.
    * @return Symbian OS error code.
    */
    virtual TInt TestServerLaunchAppL( CStifItemParser& /*aItem*/ );  
    
private:    // Data

    /**
     * ScreenSaver Property
     */
    TInt iOldScreenSaverProperty;

    };

#endif      // C_TESTPLATCLIENTSERVER_H

// End of File
