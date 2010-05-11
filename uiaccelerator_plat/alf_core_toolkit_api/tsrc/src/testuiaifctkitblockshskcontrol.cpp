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
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huisoftkeycontrol.h>

#include "testuiaifcoretoolkit.h"

_LIT( KLabel, "label" );
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
    CleanupStack::PushL( keyControl );
    STIF_ASSERT_NOT_NULL( keyControl );
    CleanupStack::PopAndDestroy( keyControl );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCNewLCL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewLC( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( keyControl );
    CleanupStack::Pop();
    delete keyControl;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCDestructL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
    CleanupStack::PushL( keyControl );
    STIF_ASSERT_NOT_NULL( keyControl );
    CleanupStack::Pop( keyControl );
    delete keyControl;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCSetLabelL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCSetLabelL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCSetLabelL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
    CleanupStack::PushL( keyControl );
    STIF_ASSERT_NOT_NULL( keyControl );

    TPtrC ptr( KLabel );
    keyControl->SetLabelL( EHuiSoftKeyUpper, ptr );
    CleanupStack::Pop( keyControl );
    delete keyControl;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCSetBackgroundL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCSetBackgroundL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCSetBackgroundL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
    CleanupStack::PushL( keyControl );
    STIF_ASSERT_NOT_NULL( keyControl );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    keyControl->SetBackgroundL( *image, 100, 100 );
    CleanupStack::PopAndDestroy( image );
    CleanupStack::PopAndDestroy( keyControl );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCSetAnimationTimesL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCSetAnimationTimesL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCSetAnimationTimesL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
    CleanupStack::PushL( keyControl );
    STIF_ASSERT_NOT_NULL( keyControl );
    keyControl->SetAnimationTimes( 0, 100 );
    CleanupStack::PopAndDestroy( keyControl );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCEnterViewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCEnterViewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCEnterViewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

//    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
//    CleanupStack::PushL( keyControl );
//    STIF_ASSERT_NOT_NULL( keyControl );
//    TRect rect( 1, 1, 1, 1 );
//    iHuiEnv->CHuiEnv::Display( 0 );
//    keyControl->EnterView();
//    CleanupStack::PopAndDestroy( keyControl );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCExitViewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCExitViewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCExitViewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

//    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
//    CleanupStack::PushL( keyControl );
//    STIF_ASSERT_NOT_NULL( keyControl );
//    keyControl->EnterView();
//    keyControl->ExitView();
//    CleanupStack::PopAndDestroy( keyControl );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHSKCSetBackgroundTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHSKCSetBackgroundTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHSKCSetBackgroundTypeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiSoftKeyControl* keyControl = CHuiSoftKeyControl::NewL( *iHuiEnv );
    CleanupStack::PushL( keyControl );
    STIF_ASSERT_NOT_NULL( keyControl );
    keyControl->SetBackgroundType( EHuiBackgroundTypeLight );
    keyControl->SetBackgroundType( EHuiBackgroundTypeDark );
    CleanupStack::PopAndDestroy( keyControl );

    return KErrNone;
    }
