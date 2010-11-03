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
#include <uiacceltk/huilinevisual.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huilayout.h>
#include <uiacceltk/huiownedpointer.h>
#include <uiacceltk/huicurvepath.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVAddNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVSetPathL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVSetPathL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVSetPathL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );

    CHuiCurvePath* path = CHuiCurvePath::NewL();
    CleanupStack::PushL( path );
    visual->SetPath( path, EHuiDoesNotHaveOwnership );
    CleanupStack::Pop( path );
    delete path;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVPathL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVPathL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVPathL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );

    CHuiCurvePath* path = CHuiCurvePath::NewL();
    CleanupStack::PushL( path );
    visual->SetPath( path, EHuiDoesNotHaveOwnership );
    visual->Path();
    CleanupStack::Pop( path );
    delete path;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVSetImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVSetImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );

    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );
    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    visual->SetImage( *image );
    CleanupStack::Pop( image );
    delete image;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVSetAlphaFunctionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVSetAlphaFunctionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVSetAlphaFunctionL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiCurvePath* path = CHuiCurvePath::NewL();
    CleanupStack::PushL( path );
    visual->SetAlphaFunction( path );
    CleanupStack::Pop( path );
    delete path;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVSetWidthFunctionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVSetWidthFunctionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVSetWidthFunctionL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiCurvePath* path = CHuiCurvePath::NewL();
    CleanupStack::PushL( path );
    visual->SetWidthFunction( path );
    CleanupStack::Pop( path );
    delete path;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHLVSetColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHLVSetColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHLVSetColorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiLineVisual* visual = CHuiLineVisual::AddNewL( *iHuiControl, layout );
    STIF_ASSERT_NOT_NULL( visual );
    visual->SetColor( KRgbRed );

    return KErrNone;
    }
