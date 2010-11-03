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
#include <uiacceltk/huiimagebrush.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBNewLCL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewLC( *image );
    CleanupStack::Pop();
    STIF_ASSERT_NOT_NULL( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBSetScaleModeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBSetScaleModeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBSetScaleModeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    brush->SetScaleMode( CHuiImageVisual::EScaleNormal );
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBSetImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBSetImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    brush->SetImage( *image );
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBSetBordersL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBSetBordersL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBSetBordersL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    STIF_ASSERT_TRUE( !brush->BorderDrawingEnabled() );
    brush->SetBorders( 1, 1, 1, 1 );
    STIF_ASSERT_TRUE( brush->BorderDrawingEnabled() );
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBBorderDrawingEnabledL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBBorderDrawingEnabledL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBBorderDrawingEnabledL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    STIF_ASSERT_FALSE( brush->BorderDrawingEnabled() );
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBCenterDrawingEnabledL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBCenterDrawingEnabledL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBCenterDrawingEnabledL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    brush->CenterDrawingEnabled();
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBExpandVisualRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBExpandVisualRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBExpandVisualRectL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    
    TRect rect(10, 10, 30, 20);
    brush->SetBorders(5, 5, 5, 5);
    brush->ExpandVisualRect(rect);
    
    STIF_ASSERT_TRUE(rect.iTl.iX == 5);
    STIF_ASSERT_TRUE(rect.iTl.iY == 5);
    
    STIF_ASSERT_TRUE(rect.iBr.iX == 35);
    STIF_ASSERT_TRUE(rect.iBr.iY == 25);

    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHIBDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHIBDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestCHIBDrawL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    CHuiImageBrush* brush = CHuiImageBrush::NewL( *image );
    CleanupStack::PushL( brush );
    STIF_ASSERT_NOT_NULL( brush );
    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc* gc = &iHuiEnv->Skin().Context();
    brush->Draw( *gc, *visual );
    CleanupStack::PopAndDestroy( brush );
    CleanupStack::PopAndDestroy( image );

    return KErrNone;
    }
