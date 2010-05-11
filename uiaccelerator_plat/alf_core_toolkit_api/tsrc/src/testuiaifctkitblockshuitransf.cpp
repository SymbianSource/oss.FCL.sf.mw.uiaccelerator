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
#include <uiacceltk/huitransformation.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranNewLCL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewLC();
    STIF_ASSERT_NOT_NULL( transfor );
    CleanupStack::Pop();
    delete transfor;
    transfor = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranCountL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    TInt count = transfor->Count();
    STIF_ASSERT_EQUALS( count, 0 );
    transfor->Translate( 1, 1 );
    count = transfor->Count();
    STIF_ASSERT_EQUALS( count, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranNonIdentityCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranNonIdentityCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranNonIdentityCountL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    TInt count = transfor->NonIdentityCount();
    STIF_ASSERT_EQUALS( count, 0 );
    transfor->Translate( 1, 1 );
    count = transfor->NonIdentityCount();
    STIF_ASSERT_EQUALS( count, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranStepL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranStepL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranStepL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Translate( 1, 1 );
    transfor->Step( 0 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranoperatorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranoperatorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranoperatorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Translate( 1, 1 );
    CHuiTransformation::TTransform trans = ( *transfor )[ 0 ];
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranLoadIdentityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranLoadIdentityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranLoadIdentityL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Translate( 1, 1 );
    transfor->LoadIdentity();
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranTranslateL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranTranslateL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranTranslateL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Translate( 1, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranTranslateWithValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranTranslateWithValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranTranslateWithValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    THuiTimedValue value1;
    THuiTimedValue value2;
    transfor->Translate( value1, value2 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranScaleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranScaleL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranScaleL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Scale( 1, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranScaleWithValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranScaleWithValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranScaleWithValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    THuiTimedValue value1;
    THuiTimedValue value2;
    transfor->Scale( value1, value2 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranScaleWithThreeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranScaleWithThreeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranScaleWithThreeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Scale( 1, 1, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranScaleWithThreeValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranScaleWithThreeValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranScaleWithThreeValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    THuiTimedValue value1;
    THuiTimedValue value2;
    THuiTimedValue value3;
    transfor->Scale( value1, value2, value3 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranRotateL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranRotateL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranRotateL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Rotate( 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranRotateValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranRotateValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranRotateValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    THuiTimedValue angle;
    transfor->Rotate( angle );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranRotateFourL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranRotateFourL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranRotateFourL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    transfor->Rotate( 1, 1, 1, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHTranRotateValueThreeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHTranRotateValueThreeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTransformation, "In TestCHTranRotateValueThreeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTransformation );
    // Print to log file
    iLog->Log( KCHuiTransformation );

    CHuiTransformation* transfor = CHuiTransformation::NewL();
    CleanupStack::PushL( transfor );
    STIF_ASSERT_NOT_NULL( transfor );
    THuiTimedValue angle;
    transfor->Rotate( angle, 1, 1, 1 );
    CleanupStack::PopAndDestroy( transfor );

    return KErrNone;
    }
