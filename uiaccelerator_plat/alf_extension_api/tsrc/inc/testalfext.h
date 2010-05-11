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
* Description:  this project test api in alf_extension_api
*
*/



#ifndef C_TESTALFEXT_H
#define C_TESTALFEXT_H

//  INCLUDES
#include <stiflogger.h>
#include <testscripterinternal.h>
#include <stiftestmodule.h>
#include <testclassassert.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huicontrolgroup.h>
#include <uiacceltk/huidisplay.h>
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huicommand.h>
#include <uiacceltk/huimesh.h>
#include <uiacceltk/huidisplaycoecontrol.h>
#include <alf/alfbrushhandlers.h>
#include <alf/alflayouthandlers.h>
#include <alf/alfserverutils.h>
#include <alf/alfvisualhandlers.h>
#include <alf/ftokenclient.h>
#include <alf/alfmetric.h>
#include <alf/alfconstants.h>
#include <uiacceltk/huiborderbrush.h>

// MACROS
#define TEST_CLASS_VERSION_MAJOR 0
#define TEST_CLASS_VERSION_MINOR 0
#define TEST_CLASS_VERSION_BUILD 0

// Logging path
_LIT( KtestalfextLogPath, "\\logs\\testframework\\testalfext\\" ); 
// Log file
_LIT( KtestalfextLogFile, "testalfext.txt" ); 
_LIT( KtestalfextLogFileWithTitle, "testalfext_[%S].txt" );


/*This class provides interface object for the test functions*/
class CTestAlfInterfacePorvider : public CBase, public MAlfInterfaceProvider
    {
public:
    /*
     * Constructor
     * */
    CTestAlfInterfacePorvider(){}
    /*
     * Deconstructor
     * */
    ~CTestAlfInterfacePorvider(){}
    /**
    * Request to pointer of given type matching to given handle. 
    * Leaves if object not found i.e. always returns pointer on completion
    */
    TAny* GetInterfaceL(const THuiInterfaceSupport& /*aType*/, TInt /*aHandle*/)
        { return NULL; }

    /**
    * Request identifier for pointer of given type 
    * On error returns KErrNotFound
    */
    TInt GetHandleFromInterface(const THuiInterfaceSupport& /*aType*/,
            TAny* /*aInterface*/){ return 0; }

    /**
    * Returns common layoutmanager or null
    */
    CAlfLayoutManager* LayoutManager() const{ return NULL; }

    /**
    * Returns common hitchcock environment or null
    */
    CHuiEnv* SharedHuiEnv() const{ return NULL; }
    
    /**
    * Request to make current command (during MAlfExtension::HandleCmd) asynchronous
    * returns command id that is needed for completing the command later on
    *
    * exntension should take references to buffers (in/out) in case it wants to modify client message
    * before completing it
    */
    TInt HandleCurrentCommanndAsynch(){ return 0;}

    /**
    * Complete asynch command, if MAlfExtension implementing object utilizes asynch commands
    * it should also take care that those messages are completed at latest when the extension is being 
    * destoryed. FW will panic the client in case of orphean messages
    */    
    void CompleteCmd(TInt /*aCommadIdentifier*/, TInt aResult = KErrNone){}

    /** ! Future proofing */
    void AlfInterfaceProviderExtension(const TUid& /*aExtensionUid*/, TAny** /*aExtensionParams*/){}
    };

/**
*  CTestAlfExt test class for STIF Test Framework TestScripter.
*  @since S60 5.0
*/

NONSHARABLE_CLASS( CTestAlfExt ) : public CScriptBase
    {
public:  // Constructors and destructor

    /**
    * Two-phased constructor.
    */
    static CTestAlfExt* NewL( CTestModuleIf& aTestModuleIf );

    /**
    * Destructor.
    */
    virtual ~CTestAlfExt();

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
    CTestAlfExt( CTestModuleIf& aTestModuleIf );
    /**
    * By default Symbian 2nd phase constructor is private.
    */
    void ConstructL();

    /**
    * Example test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    
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
    // alfbrushhandlers.h
    /**
     * TestBrushHandlerConstructL test constructor and ConstructL\
     *  of CAlfBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestBrushHandlerForMAlfExtensionL test Release GetInterface
     * HandleCmdL of CAlfBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBrushHandlerForMAlfExtensionL( CStifItemParser& aItem );

    /**
     * TestBrushHandlerForOthersL test other functions of CAlfBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBrushHandlerForOthersL( CStifItemParser& aItem );

    // alfbrushhandlers.h
    /**
     * TestBorderBrushHandlerConstructL test NewL and ConstructL
     * of CAlfBorderBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBorderBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestBorderBrushHandlerProtectedL test protected functions
     * of CAlfBorderBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestBorderBrushHandlerProtectedL( CStifItemParser& aItem );

    // alfbrushhandlers.h
    /**
     * TestImageBrushHandlerConstructL test NewL and ConstructL
     * of CAlfImageBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestImageBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestImageBrushHandlerProtectedL test protected functions
     * of CAlfImageBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestImageBrushHandlerProtectedL( CStifItemParser& aItem );

    // alfbrushhandlers.h
    /**
     * TestShadowBorderBrushHandlerConstructL test NewL and ConstructL
     * of CAlfShadowBorderBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestShadowBorderBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestShadowBorderBrushHandlerProtectedL test protected functions
     * of CAlfShadowBorderBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestShadowBorderBrushHandlerProtectedL( CStifItemParser& aItem );
    
    // alfbrushhandlers.h
    /**
     * TestDropShadowBrushHandlerConstructL test NewL and ConstructL
     * of CAlfDropShadowBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestDropShadowBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestDropShadowBrushHandlerProtectedL test protected functions
     * of CAlfDropShadowBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestDropShadowBrushHandlerProtectedL( CStifItemParser& aItem );

    // alfbrushhandlers.h
    /**
     * TestGradientBrushHandlerConstructL test NewL and ConstructL
     * of CAlfGradientBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestGradientBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestGradientBrushHandlerProtectedL test protected functions
     * of CAlfGradientBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestGradientBrushHandlerProtectedL( CStifItemParser& aItem );
    
    // alfbrushhandlers.h
    
    /**
     * TestFrameBrushHandlerConstructL test NewL and ConstructL
     * of CAlfFrameBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestFrameBrushHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestFrameBrushHandlerProtectedL test protected functions
     * of CAlfFrameBrushHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestFrameBrushHandlerProtectedL( CStifItemParser& aItem );

    // alflayouthandlers.h
    /**
     * TestLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestLayoutHandlerProtectedL test protected functions
     * of CAlfLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestAnchorLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfAnchorLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestAnchorLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestAnchorLayoutHandlerProtectedL test protected functions
     * of CAlfAnchorLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestAnchorLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestLCTAnchorLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfLCTAnchorLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLCTAnchorLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestLCTAnchorLayoutHandlerProtectedL test protected functions
     * of CAlfLCTAnchorLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLCTAnchorLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestGridLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfGridLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestGridLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestGridLayoutHandlerProtectedL test protected functions
     * of CAlfGridLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestGridLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestLCTGridLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfLCTGridLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLCTGridLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestLCTGridLayoutHandlerProtectedL test protected functions
     * of CAlfLCTGridLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLCTGridLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestDeckLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfDeckLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestDeckLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestDeckLayoutHandlerProtectedL test protected functions
     * of CAlfDeckLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestDeckLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestFlowLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfFlowLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestFlowLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestFlowLayoutHandlerProtectedL test protected functions
     * of CAlfFlowLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestFlowLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestCurvePathLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfCurvePathLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestCurvePathLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestCurvePathLayoutHandlerProtectedL test protected functions
     * of CAlfCurvePathLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestCurvePathLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    /**
     * TestViewportLayoutHandlerConstructL test NewL, Constructor and ConstructL 
     * of CAlfViewportLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestViewportLayoutHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestViewportLayoutHandlerProtectedL test protected functions
     * of CAlfViewportLayoutHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestViewportLayoutHandlerProtectedL( CStifItemParser& aItem );
    
    // alfserverutils.h
    
    /**
     * TestTimedValueUtil test functions of AlfTimedValueUtility
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestTimedValueUtil( CStifItemParser& aItem );

    /**
     * TestTimedPointUtil test functions of AlfTimedPointUtility
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestTimedPointUtil( CStifItemParser& aItem );

    /**
     * TestFileTokenUtil test functions of AlfFileTokenUtility
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestFileTokenUtil( CStifItemParser& aItem );
    
    // alfvisualhandlers.h
    
    /**
     * TestVisualHandlerConstructL test NewL of CAlfVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestVisualHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestVisualHandlerMutualL test functions of CAlfVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestVisualHandlerMutualL( CStifItemParser& aItem );
    
    /**
     * TestTextVisualHandlerConstructL test NewL of CAlfTextVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestTextVisualHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestTextVisualHandlerMutualL test functions of CAlfTextVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestTextVisualHandlerMutualL( CStifItemParser& aItem );
    /**
     * TestLCTTextVisualHandlerConstructL test NewL of CAlfLCTTextVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLCTTextVisualHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestLCTTextVisualHandlerMutualL test functions of CAlfLCTTextVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLCTTextVisualHandlerMutualL( CStifItemParser& aItem );
    
    /**
     * TestImageVisualHandlerConstructL test NewL of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestImageVisualHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestImageVisualHandlerMutualL test functions of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestImageVisualHandlerMutualL( CStifItemParser& aItem );
    
    /**
     * TestLineVisualHandlerConstructL test NewL of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLineVisualHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestLineVisualHandlerMutualL test functions of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestLineVisualHandlerMutualL( CStifItemParser& aItem );
    
    /**
     * TestMeshVisualHandlerConstructL test NewL of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestMeshVisualHandlerConstructL( CStifItemParser& aItem );

    /**
     * TestMeshVisualHandlerMutualL test functions of CAlfImageVisualHandler
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestMeshVisualHandlerMutualL( CStifItemParser& aItem );
    
    // ftokenclient.h

    /**
     * TestRFTokenClientFuncL test functions of RFTokenClient
     * @since S60 5.0
     * @param aItem never used
     * @return Symbian OS error code.
     */
    virtual TInt TestRFTokenClientFuncL( CStifItemParser& aItem );

private:    // Data
    /**
     * ScreenSaver Property
     */
    TInt iOldScreenSaverProperty;
    /*
     * Interface pointer for test
     * */
    CTestAlfInterfacePorvider *iInterface;
    
    /*
     * The environment
    */
    CHuiEnv* iHuiEnv;
    /*
     * The iHuiControl of visual
    */
    CHuiControl* iHuiControl;
    /*
    * The iHuiControl group
    */
    CHuiControlGroup* iHuiControlGroup;
    /*
    * The CHuiVisual
    */
    CHuiVisual* iHuiVisual;
    
    };

#endif      // C_TESTALFEXT_H

// End of File

