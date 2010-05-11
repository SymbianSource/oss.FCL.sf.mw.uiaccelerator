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


#include <uiacceltk/huiGradientBrush.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushNewLL, "TestHuiGradientBrushNewLL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushNewLL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushNewLL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewL();
    CleanupStack::PushL( huiGradientBrush );
    STIF_ASSERT_NOT_NULL( huiGradientBrush );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushNewLCL, "TestHuiGradientBrushNewLCL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushNewLCL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushNewLCL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    STIF_ASSERT_NOT_NULL( huiGradientBrush );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushSetDirectionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushSetDirectionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushSetDirectionL, "TestHuiGradientBrushSetDirectionL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushSetDirectionL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushSetDirectionL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    STIF_ASSERT_NOT_NULL( huiGradientBrush );
    huiGradientBrush->SetDirection( CHuiGradientBrush::EDirectionUp );
    huiGradientBrush->SetDirection( CHuiGradientBrush::EDirectionRight );
    huiGradientBrush->SetDirection( CHuiGradientBrush::EDirectionDown );
    huiGradientBrush->SetDirection( CHuiGradientBrush::EDirectionLeft );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushSetColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushSetColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushSetColorL, "TestHuiGradientBrushSetColorL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushSetColorL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushSetColorL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    STIF_ASSERT_NOT_NULL( huiGradientBrush );
    huiGradientBrush->SetColor( KRgbRed, .8 );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushSetImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushSetImageL, "TestHuiGradientBrushSetImageL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushSetImageL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushSetImageL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    STIF_ASSERT_NOT_NULL( huiGradientBrush );
    const CHuiTexture* backgroundTexture = NULL;
    TInt err = iHuiEnv->Skin().GetTexture(EHuiSkinBackgroundTexture, backgroundTexture);
    ASSERT(backgroundTexture!=NULL);
    __ASSERT_ALWAYS( err == KErrNone, User::Invariant() );

    // Apply background texture
    THuiImage background(*backgroundTexture);
    huiGradientBrush->SetImage( background );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushColorL, "TestHuiGradientBrushColorL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushColorL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushColorL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    STIF_ASSERT_NOT_NULL( huiGradientBrush );
    huiGradientBrush->SetColor( KRgbRed );
    TRgb rgb = huiGradientBrush->Color( 0 );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushOpacityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushOpacityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushOpacityL, "TestHuiGradientBrushOpacityL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushOpacityL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushOpacityL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    huiGradientBrush->SetColor( KRgbRed );
    TReal32 real = huiGradientBrush->Opacity( .8 );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushImageL, "TestHuiGradientBrushImageL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushImageL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushImageL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    THuiImage image = huiGradientBrush->Image();
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGradientBrushAppendColorLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGradientBrushAppendColorLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGradientBrushAppendColorLL, "TestHuiGradientBrushAppendColorLL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGradientBrushAppendColorLL );
    // Print to log file
    iLog->Log( KTestHuiGradientBrushAppendColorLL );

    CHuiGradientBrush* huiGradientBrush = CHuiGradientBrush::NewLC();
    huiGradientBrush->AppendColorL( .6f, KRgbRed, 1.f );
    CleanupStack::PopAndDestroy( huiGradientBrush );
    
    return KErrNone;

    }

//End of file.
