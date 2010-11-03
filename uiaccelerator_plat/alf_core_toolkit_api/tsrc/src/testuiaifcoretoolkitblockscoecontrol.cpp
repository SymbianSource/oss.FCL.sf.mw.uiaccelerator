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
* Description:  test api of alf_core_toolkit
*
*/


// [INCLUDE FILES]
#include <e32svr.h>
#include <gdi.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huistatic.h>
#include <uiacceltk/huidisplaycoecontrol.h>

#include "testuiaifcoretoolkit.h"

//this for testing the CHuiDisplayCoeControl class 
class CHuiDisplayCoeControlImp : public CHuiDisplayCoeControl
    {
public:
    /**
     * test for HanlePointerEventL
     */
    void TestHandlePointerEventL()
        {
        
        TPointerEvent event;
        HandlePointerEventL( event );
        }
    
    /**
     * test for DisplayCoeCntrlExtension
     */
    void TestDisplayCoeCntrlExtension()
        {
        TUid uid;
        TBool temp = ETrue;
        TAny *temp1 = &temp;
        TAny** any =  &temp1;
        DisplayCoeCntrlExtension( uid, any);
        }
    };

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiEnvL, "In TestTTHuiCCNewLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiEnvL );
    // Print to log file 
    iLog->Log( KTestTHuiEnvL );
    
    CHuiDisplayCoeControl *displayControl = 
        CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
    delete displayControl;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCNewLCL, "In TestTTHuiCCNewLCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCCNewLCL );
    // Print to log file 
    iLog->Log( KTestTTHuiCCNewLCL );
    
    CHuiDisplayCoeControl *displayControl = 
        CHuiDisplayCoeControl::NewLC( *iHuiEnv, iDisplayRect );
    CleanupStack::PopAndDestroy( displayControl );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCEnvL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCEnvL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCEnvL, "In TestTTHuiCCEnvL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCCEnvL );
    // Print to log file 
    iLog->Log( KTestTTHuiCCEnvL );
    
    CHuiDisplayCoeControl *displayControl = 
        CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( displayControl );
    displayControl->Env();
    
    CleanupStack::PopAndDestroy( displayControl );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCDisplayL, "In TestTTHuiCCDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCCDisplayL );
    // Print to log file 
    iLog->Log( KTestTTHuiCCDisplayL );
    
    CHuiDisplayCoeControl *displayControl = 
        CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( displayControl );
    displayControl->Display();
    
    CleanupStack::PopAndDestroy( displayControl );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCHandlePointerEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCHandlePointerEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCHandlePointerEventL, "In TestTTHuiCCHandlePointerEventL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTTHuiCCHandlePointerEventL );
    // Print to log file 
    iLog->Log( KTestTTHuiCCHandlePointerEventL );
    
    CHuiDisplayCoeControlImp *displayControl = 
        ( CHuiDisplayCoeControlImp* )CHuiDisplayCoeControlImp::NewL( 
            *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( displayControl );
    displayControl->TestHandlePointerEventL();
    
    CleanupStack::PopAndDestroy( displayControl );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCDisplayCoeCntrlExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCDisplayCoeCntrlExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCDisplayCoeCntrlExtensionL,
            "In TestTTHuiCCDisplayCoeCntrlExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTTHuiCCDisplayCoeCntrlExtensionL );
    // Print to log file 
    iLog->Log( KTestTTHuiCCDisplayCoeCntrlExtensionL );
    
    CHuiDisplayCoeControlImp *displayControl = 
       ( CHuiDisplayCoeControlImp* )CHuiDisplayCoeControlImp::NewL( 
            *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( displayControl );
    displayControl->TestDisplayCoeCntrlExtension();
    
    CleanupStack::PopAndDestroy( displayControl );
    
    return KErrNone;
    
    }

//  [End of File]
