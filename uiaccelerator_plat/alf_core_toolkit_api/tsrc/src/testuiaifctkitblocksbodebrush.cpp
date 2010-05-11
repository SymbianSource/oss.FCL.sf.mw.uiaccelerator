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
#include <uiacceltk/huiborderbrush.h>

#include "testuiaifcoretoolkit.h"
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshNewL, "In TestCHuiBdeBrshNewL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshNewL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshNewL );

    THuiXYMetric aThickness;
    THuiXYMetric aEdgeOffset;
    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( aThickness, aEdgeOffset );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshNewCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshNewCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshNewCL, "In TestCHuiBdeBrshNewCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshNewCL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshNewCL );

    THuiXYMetric aThickness;
    THuiXYMetric aEdgeOffset;
    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewLC( aThickness, aEdgeOffset );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshOtherNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshOtherNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshOtherNewL, "In TestCHuiBdeBrshOtherNewL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshOtherNewL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshOtherNewL );

    THuiXYMetric aThickness;
    THuiXYMetric aEdgeOffset;
    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( 2, 2, 1 ,1 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshOtherNewCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshOtherNewCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshOtherNewCL, "In TestCHuiBdeBrshOtherNewCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshOtherNewCL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshOtherNewCL );

    THuiXYMetric aThickness;
    THuiXYMetric aEdgeOffset;
    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewLC( 0, 0 ,0, 0 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshSetImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshSetImageL, "In TestCHuiBdeBrshSetImageL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshSetImageL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshSetImageL );

    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( 2, 2, 1 ,1 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    CHuiTexture& texture = iHuiEnv->TextureManager().BlankTexture();
    THuiImage aImage( texture );
    borderBrush->SetImage( aImage );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshSetColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshSetColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshSetColorL, "In TestCHuiBdeBrshSetColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshSetColorL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshSetColorL );

    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( 2, 2, 1 ,1 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    borderBrush->SetColor( KRgbBlue );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshSetThicknessL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshSetThicknessL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshSetThicknessL, "In TestCHuiBdeBrshSetThicknessL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshSetThicknessL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshSetThicknessL );

    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( 2, 2, 1 ,1 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    THuiXYMetric aThickness;
    borderBrush->SetThickness( aThickness );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshSetEdgeOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshSetEdgeOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshSetEdgeOffsetL, "In TestCHuiBdeBrshSetEdgeOffsetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshSetEdgeOffsetL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshSetEdgeOffsetL );

    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( 2, 2, 1 ,1 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    THuiXYMetric aEdgeOffset;
    borderBrush->SetEdgeOffset( aEdgeOffset );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiBdeBrshSetImageOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiBdeBrshSetImageOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiBdeBrshSetImageOffsetL, "In TestCHuiBdeBrshSetImageOffsetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiBdeBrshSetImageOffsetL );
    // Print to log file
    iLog->Log( KTestCHuiBdeBrshSetImageOffsetL );

    CHuiBorderBrush* borderBrush = CHuiBorderBrush::NewL( 2, 2, 1 ,1 );
    STIF_ASSERT_NOT_NULL( borderBrush );
    CleanupStack::PushL( borderBrush );
    THuiXYMetric aImageOffset;
    borderBrush->SetImageOffset( aImageOffset );
    CleanupStack::PopAndDestroy( borderBrush );

    return KErrNone;
    }

//  [End of File]
