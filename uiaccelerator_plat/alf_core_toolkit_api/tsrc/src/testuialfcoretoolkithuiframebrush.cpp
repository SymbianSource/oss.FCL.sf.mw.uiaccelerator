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
* Description:  For test alf core toolkit api modules
*
*/


#include <uiacceltk/huiFrameBrush.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFrameBrushNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFrameBrushNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFrameBrushNewLL, "TestHuiFrameBrushNewLL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFrameBrushNewLL );
    // Print to log file
    iLog->Log( KTestHuiFrameBrushNewLL );

    TAknsItemID id;
    id.Set( TUid::Uid( 0 ), 0 );
    CHuiFrameBrush* huiFrameBrush = CHuiFrameBrush::NewL( id, 0, 0 );
    CleanupStack::PushL( huiFrameBrush );
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    THuiMetric metric( 0 );
    THuiXYMetric offset( metric );
    huiFrameBrush = CHuiFrameBrush::NewL( id, offset );
    CleanupStack::PushL( huiFrameBrush );
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
//    THuiImage image;
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err == KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);
    huiFrameBrush = CHuiFrameBrush::NewL( background, offset );
    CleanupStack::PushL( huiFrameBrush );
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFrameBrushNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFrameBrushNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFrameBrushNewLCL, "TestHuiFrameBrushNewLCL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFrameBrushNewLCL );
    // Print to log file
    iLog->Log( KTestHuiFrameBrushNewLCL );

    TAknsItemID id;
    id.Set( TUid::Uid( 0 ), 0 );
    CHuiFrameBrush* huiFrameBrush = CHuiFrameBrush::NewLC( id,-2,-1);
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    THuiMetric metric( 0 );
    THuiXYMetric offset( metric );
    huiFrameBrush = CHuiFrameBrush::NewLC( id, offset );
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err == KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);
    huiFrameBrush = CHuiFrameBrush::NewLC( background, offset );
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFrameBrushSetFrameRectsLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFrameBrushSetFrameRectsLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFrameBrushSetFrameRectsLL, "TestHuiFrameBrushSetFrameRectsLL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFrameBrushSetFrameRectsLL );
    // Print to log file
    iLog->Log( KTestHuiFrameBrushSetFrameRectsLL );

    TAknsItemID id;
    id.Set( TUid::Uid( 0 ), 0 );
    CHuiFrameBrush* huiFrameBrush = CHuiFrameBrush::NewLC( id,-2,-1);
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    TRect outerrect(0,0,100,100);
    TRect innerrect(10,10,90,90);
//    CHuiTexture& texture = iHuiEnv->TextureManager().BlankTexture();
//    THuiImage image( texture );
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err == KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);
    huiFrameBrush->SetImage( background );
    huiFrameBrush->SetFrameRectsL( innerrect, outerrect );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFrameBrushSetEdgeOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFrameBrushSetEdgeOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFrameBrushSetEdgeOffsetL, "TestHuiFrameBrushSetEdgeOffsetL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFrameBrushSetEdgeOffsetL );
    // Print to log file
    iLog->Log( KTestHuiFrameBrushSetEdgeOffsetL );

    TAknsItemID id;
    id.Set( TUid::Uid( 0 ), 0 );
    CHuiFrameBrush* huiFrameBrush = CHuiFrameBrush::NewLC( id,-2,-1);
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    THuiMetric metric( 0 );
    THuiXYMetric offset( metric );
    huiFrameBrush->SetEdgeOffset( offset );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFrameBrushSetImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFrameBrushSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFrameBrushSetImageL, "TestHuiFrameBrushSetImageL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFrameBrushSetImageL );
    // Print to log file
    iLog->Log( KTestHuiFrameBrushSetImageL );

    TAknsItemID id;
    id.Set( TUid::Uid( 0 ), 0 );
    CHuiFrameBrush* huiFrameBrush = CHuiFrameBrush::NewLC( id,-2,-1);
    STIF_ASSERT_NOT_NULL( huiFrameBrush );
    THuiMetric metric( 0 );
    THuiXYMetric offset( metric );
//    THuiImage image;
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err == KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);
    huiFrameBrush->SetImage( background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartCornerTl, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartCenter, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartCornerTr, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartCornerBl, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartCornerBr, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartSideB, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartSideL, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartSideR, background );
    huiFrameBrush->SetImage( CHuiFrameBrush::EFramePartSideT, background );
    CleanupStack::PopAndDestroy( huiFrameBrush );
    
    return KErrNone;

    }

//End of file.
