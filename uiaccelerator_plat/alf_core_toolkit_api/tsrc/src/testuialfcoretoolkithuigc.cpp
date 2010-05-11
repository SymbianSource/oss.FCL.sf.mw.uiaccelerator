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


#include <uiacceltk/huigc.h>
#include <uiacceltk/huidisplaycoecontrol.h>
#include <uiacceltk/huiskin.h>
#include <uiacceltk/HuiTexture.h>
#include <uiacceltk/huiTransformation.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcTHuiPathPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcTHuiPathPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcTHuiPathPoint, "TestHuiGcTHuiPathPoint" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcTHuiPathPoint );
    // Print to log file
    iLog->Log( KTestHuiGcTHuiPathPoint );

    TPoint point( 0, 0 );
    THuiPathPoint tHuiPahtPoint( point, 0 );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcDrawImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcDrawImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcDrawImageL, "TestHuiGcDrawImageL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcDrawImageL );
    // Print to log file
    iLog->Log( KTestHuiGcDrawImageL );

    THuiRealPoint pos;
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    // Acquire background texture
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err== KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);

    TPoint screenOrigin(0, 0);
    // The origin is used to offset the background in the display's
    // rendering surface, so that the background's origin is in the
    // top left screen corner.
    screenOrigin.iX = -screenOrigin.iX;
    screenOrigin.iY = -screenOrigin.iY;
    
    huiGc.DrawImage( background, screenOrigin, background.Texture().Size() );
    huiGc.DrawImage( background, rect );
    huiGc.DrawImage( background, background.Texture().Size(), rect );
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcDrawImagesL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcDrawImagesL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcDrawImagesL, "TestHuiGcDrawImagesL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcDrawImagesL );
    // Print to log file
    iLog->Log( KTestHuiGcDrawImagesL );

    THuiRealPoint pos;
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    // Acquire background texture
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err== KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);

    TPoint screenOrigin(0, 0);
    
    huiGc.DrawImages( background, background, pos, background.Texture().Size() );
    huiGc.DrawImages( background, background, background.Texture().Size(), rect);
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcFontL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcFontL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcFontL, "TestHuiGcFontL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcFontL );
    // Print to log file
    iLog->Log( KTestHuiGcFontL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
//    THuiFont* font= huiGc.Font();
    
//    CleanupStack::PushL( font );
//    CleanupStack::PopAndDestroy( font );
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcNearClipDistanceL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcNearClipDistanceL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcNearClipDistanceL, "TestHuiGcNearClipDistanceL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcNearClipDistanceL );
    // Print to log file
    iLog->Log( KTestHuiGcNearClipDistanceL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
//    TReal32 real;
//    real = huiGc.NearClipDistance();
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcFarClipDistanceL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcFarClipDistanceL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcFarClipDistanceL, "TestHuiGcFarClipDistanceL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcFarClipDistanceL );
    // Print to log file
    iLog->Log( KTestHuiGcFarClipDistanceL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
//    TReal32 real = huiGc.FarClipDistance();
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcFovFactorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcFovFactorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcFovFactorL, "TestHuiGcFovFactorL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcFovFactorL );
    // Print to log file
    iLog->Log( KTestHuiGcFovFactorL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
//    TReal32 real = huiGc.FovFactor();
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcOffset2DL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcOffset2DL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcOffset2DL, "TestHuiGcOffset2DL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcOffset2DL );
    // Print to log file
    iLog->Log( KTestHuiGcOffset2DL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
//    TReal32 real = huiGc.Offset2D();
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcSetWindowTransformationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcSetWindowTransformationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcSetWindowTransformationL, "TestHuiGcSetWindowTransformationL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcSetWindowTransformationL );
    // Print to log file
    iLog->Log( KTestHuiGcSetWindowTransformationL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    CHuiTransformation* windowTransformation = CHuiTransformation::NewL();
    CleanupStack::PushL( windowTransformation );
//    huiGc.SetWindowTransformation( windowTransformation );
    CleanupStack::PopAndDestroy( windowTransformation );
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGcLocaleTextAlignmentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGcLocaleTextAlignmentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGcLocaleTextAlignmentL, "TestHuiGcLocaleTextAlignmentL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGcLocaleTextAlignmentL );
    // Print to log file
    iLog->Log( KTestHuiGcLocaleTextAlignmentL );

    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
//    THuiAlignHorizontal alignHorizontal = huiGc.LocaleTextAlignment();
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }

//End of file.
