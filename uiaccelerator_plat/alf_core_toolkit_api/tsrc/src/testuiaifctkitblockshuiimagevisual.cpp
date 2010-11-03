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
* Description:  for testing the method of the CHuiTextVisual
*
*/

#include <uiacceltk\huiimagevisual.h>

#include "testuiaifcoretoolkit.h"

const TInt KTop = 10;
const TInt KBottom = 20;
const TInt KShadowDistance = 10;

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualAddNewL, "In TestHuiImageVisualAddNewL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualAddNewL );
    // Print to log file
    iLog->Log( KTestHuiImageVisualAddNewL );
    
    TRAPD( error, iHuiImageVisual = iHuiImageVisual->AddNewL( *iHuiControl ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetScaleMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetScaleMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetScaleMode, "In TestHuiImageVisualSetScaleMode" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetScaleMode );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetScaleMode );
    
    iHuiImageVisual->SetScaleMode( CHuiImageVisual::EScaleNormal );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetImage
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetImage, "In TestHuiImageVisualSetImage" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetImage );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetImage );
    
    CHuiTexture* huiTexture = CHuiTexture::NewL();
    THuiImage huiImage( *huiTexture );
    
    iHuiImageVisual->SetImage( huiImage );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetSecondaryImage
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetSecondaryImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetSecondaryImage, "In TestHuiImageVisualSetSecondaryImage" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetSecondaryImage );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetSecondaryImage );
    
    CHuiTexture* huiTexture = CHuiTexture::NewL();
    THuiImage secHuiImage( *huiTexture );
    
    iHuiImageVisual->SetSecondaryImage( secHuiImage );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualImage
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualImage( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualImage, "In TestHuiImageVisualImage" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualImage );
    // Print to log file
    iLog->Log( KTestHuiImageVisualImage );
    
    iHuiImageVisual->Image();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSecondaryImage
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSecondaryImage( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSecondaryImage, "In TestHuiImageVisualSecondaryImage" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSecondaryImage );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSecondaryImage );
    
    iHuiImageVisual->SecondaryImage();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetColor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetColor, "In TestHuiImageVisualSetColor" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetColor );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetColor );
    
    TRgb color( 0, 0, 0 );
    
    iHuiImageVisual->SetColor( color );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetColorMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetColorMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetColorMode, "In TestHuiImageVisualSetColorMode" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetColorMode );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetColorMode );
    
    iHuiImageVisual->SetColorMode( CHuiImageVisual::EColorModulate );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetStretch
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetStretch( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetStretch, "In TestHuiImageVisualSetStretch" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetStretch );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetStretch );
    
    iHuiImageVisual->SetStretch( KTop, KBottom );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetStretchMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetStretchMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetStretchMode, "In TestHuiImageVisualSetStretchMode" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetStretchMode );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetStretchMode );
    
    iHuiImageVisual->SetStretchMode( CHuiGc::EStretchFull );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetDropShadow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetDropShadow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetDropShadow, "In TestHuiImageVisualSetDropShadow" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetDropShadow );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetDropShadow );
    
    iHuiImageVisual->SetDropShadow( KShadowDistance );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetDropShadowWithHuiMetric
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetDropShadowWithHuiMetric( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetDropShadowWithHuiMetric, "In TestHuiImageVisualSetDropShadowWithHuiMetric" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetDropShadowWithHuiMetric );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetDropShadowWithHuiMetric );
    
    THuiMetric huiMetric( KShadowDistance );
    
    iHuiImageVisual->SetDropShadow( huiMetric );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageVisualSetDropShadowWithHuiXYMetric
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageVisualSetDropShadowWithHuiXYMetric( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageVisualSetDropShadowWithHuiXYMetric, "In TestHuiImageVisualSetDropShadowWithHuiXYMetric" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageVisualSetDropShadowWithHuiXYMetric );
    // Print to log file
    iLog->Log( KTestHuiImageVisualSetDropShadowWithHuiXYMetric );
    
    THuiMetric huiMetric( KShadowDistance );
    THuiXYMetric huiXYMetric( huiMetric );
    
    iHuiImageVisual->SetDropShadow( huiXYMetric );

    return KErrNone;

    }
//End of file
