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
#include <uiacceltk/huitexture.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextNewL, "In TestTHuiTextNewL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextNewL );
    // Print to log file 
    iLog->Log( KTestTHuiTextNewL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    delete texTure;
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextNewLC
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextNewLC( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextNewLC, "In TestTHuiTextNewLC" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextNewLC );
    // Print to log file 
    iLog->Log( KTestTHuiTextNewLC );
    
    CHuiTexture* textTure = CHuiTexture::NewLC();
    
    // Verify that all the member variables are correctly initialized.
    STIF_ASSERT_TRUE( textTure->ImageFileName().Size() == 0 );
    STIF_ASSERT_TRUE( !textTure->HasContent() );
    STIF_ASSERT_TRUE( !textTure->IsShadowEnabled() );
    STIF_ASSERT_TRUE( textTure->ShadowStyle() == EHuiTextureShadowStyleIcon );
    STIF_ASSERT_TRUE( !textTure->HasAlpha() );
    STIF_ASSERT_TRUE( textTure->Size().iWidth == 0 );
    STIF_ASSERT_TRUE( textTure->Size().iHeight == 0 );
    STIF_ASSERT_TRUE( textTure->Size().iWidth == 0 );
    STIF_ASSERT_TRUE( textTure->SegmentCount() == 0);
    STIF_ASSERT_TRUE( !textTure->TextureChanged() );
    STIF_ASSERT_TRUE( !textTure->IsSkinContent() );
    
    CleanupStack::PopAndDestroy( textTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextImageFileNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextImageFileNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextImageFileNameL, "In TestTHuiTextImageFileNameL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextImageFileNameL );
    // Print to log file 
    iLog->Log( KTestTHuiTextImageFileNameL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextHasContentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextHasContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextHasContentL, "In TestTHuiTextHasContentL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextHasContentL );
    // Print to log file 
    iLog->Log( KTestTHuiTextHasContentL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_TRUE( texTure->HasContent() == EFalse);
    
    CleanupStack::PopAndDestroy( texTure );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextHasAlphaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextHasAlphaL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextHasAlphaL, "In TestTHuiTextHasAlphaL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextHasAlphaL );
    // Print to log file 
    iLog->Log( KTestTHuiTextHasAlphaL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_TRUE( texTure->HasAlpha() == EFalse);
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextMaxTextureSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextMaxTextureSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextMaxTextureSizeL, "In TestTHuiTextMaxTextureSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextMaxTextureSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiTextMaxTextureSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->MaxTextureSize();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }


// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextClearLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextClearLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextMaxTextureSizeL, "In TestTHuiTextMaxTextureSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextMaxTextureSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiTextMaxTextureSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TSize size(128, 128);
    TRgb rgb = KRgbRed;    
    texTure->ClearL(size, rgb);

    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiClearWithAlphaLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiClearWithAlphaLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextMaxTextureSizeL, "In TestTHuiTextMaxTextureSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextMaxTextureSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiTextMaxTextureSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TSize size(128, 128);
    TRgb rgb = KRgbRed;
    TUint temp = 255;
    texTure->ClearWithAlphaL( size, rgb, temp);
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentedTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentedTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentedTextureL, "In TestTHuiSegmentedTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSegmentedTextureL );
    // Print to log file 
    iLog->Log( KTestTHuiSegmentedTextureL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->SegmentedTexture();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentedTextureConstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentedTextureConstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentedTextureConstL, "In TestTHuiSegmentedTextureConstL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSegmentedTextureConstL);
    // Print to log file 
    iLog->Log( KTestTHuiSegmentedTextureConstL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    ( ( const CHuiTexture* )texTure )->SegmentedTexture();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiShadowedTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiShadowedTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiShadowedTextureL, "In TestTHuiShadowedTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiShadowedTextureL );
    // Print to log file 
    iLog->Log( KTestTHuiShadowedTextureL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->ShadowedTexture();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiShadowedTextureConstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiShadowedTextureConstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiShadowedTextureConstL, "In TestTHuiShadowedTextureConstL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiShadowedTextureConstL );
    // Print to log file 
    iLog->Log( KTestTHuiShadowedTextureConstL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    ( ( const CHuiTexture* )texTure )->ShadowedTexture();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiEnableShadowL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiEnableShadowL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiEnableShadowL, "In TestTHuiEnableShadowL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiEnableShadowL );
    // Print to log file 
    iLog->Log( KTestTHuiEnableShadowL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->EnableShadow();
    texTure->SetSkinContent( ETrue );
    
    // Set shadow enabled
    texTure->EnableShadow();
    STIF_ASSERT_TRUE(texTure->IsShadowEnabled());
    STIF_ASSERT_TRUE(texTure->IsSkinContent());
    
    // Set skin content
    texTure->EnableShadow(EFalse);
    texTure->SetSkinContent(ETrue);
    STIF_ASSERT_TRUE( ! texTure->IsShadowEnabled() );
    STIF_ASSERT_TRUE( texTure->IsSkinContent() );
    
    // Set skin content and shadow enabled
    texTure->EnableShadow();
    STIF_ASSERT_TRUE(texTure->IsShadowEnabled() );
    STIF_ASSERT_TRUE(texTure->IsSkinContent() );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiIsShadowEnabledL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiIsShadowEnabledL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiIsShadowEnabledL, "In TestTHuiIsShadowEnabledL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiIsShadowEnabledL );
    // Print to log file 
    iLog->Log( KTestTHuiIsShadowEnabledL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_TRUE( texTure->IsShadowEnabled() == EFalse );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetShadowStyleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetShadowStyleL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetShadowStyleL, "In TestTHuiSetShadowStyleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetShadowStyleL );
    // Print to log file 
    iLog->Log( KTestTHuiSetShadowStyleL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->SetShadowStyle( EHuiTextureShadowStyleIcon );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiShadowStyleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiShadowStyleL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiShadowStyleL, "In TestTHuiShadowStyleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiShadowStyleL );
    // Print to log file 
    iLog->Log( KTestTHuiShadowStyleL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_EQUALS( texTure->ShadowStyle(), EHuiTextureShadowStyleIcon);
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSizeL, "In TestTHuiSetSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TSize size(10,29);
    texTure->SetSize( size );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSizeL, "In TestTHuiSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->Size();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentCountL, "In TestTHuiSegmentCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSegmentCountL );
    // Print to log file 
    iLog->Log( KTestTHuiSegmentCountL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_EQUALS(texTure->SegmentCount(), 0);
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentNameL, "In TestTHuiSegmentNameL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSegmentNameL );
    // Print to log file 
    iLog->Log( KTestTHuiSegmentNameL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0;
    texTure->SegmentName( temp );
    
    CleanupStack::PopAndDestroy(image);
    CleanupStack::PopAndDestroy( texTure );
    
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentSizeL, "In TestTHuiSegmentSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSegmentSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiSegmentSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0;
    texTure->SegmentSize( temp );
    
    CleanupStack::PopAndDestroy(image);
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentTextureSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentTextureSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentTextureSizeL, "In TestTHuiSegmentTextureSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTHuiSegmentTextureSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiSegmentTextureSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0;
    texTure->SegmentTextureSize( temp );
    
    CleanupStack::PopAndDestroy(image);
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSegmentOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSegmentOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSegmentOffsetL, "In TestTHuiSegmentOffsetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSegmentOffsetL );
    // Print to log file 
    iLog->Log( KTestTHuiSegmentOffsetL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0;
    texTure->SegmentOffset( temp );
    
    CleanupStack::PopAndDestroy(image);
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextureChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextureChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextureChangedL, "In TestTHuiTextureChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextureChangedL );
    // Print to log file 
    iLog->Log( KTestTHuiTextureChangedL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_TRUE( texTure->TextureChanged() == EFalse);
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextureClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextureClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextureClearChangedL, "In TestTHuiTextureClearChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextureClearChangedL );
    // Print to log file 
    iLog->Log( KTestTHuiTextureClearChangedL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->TextureClearChanged();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }


// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetTextureChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSegmentOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSegmentOffsetL, "In TestTHuiSetSegmentOffsetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetSegmentOffsetL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSegmentOffsetL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0;
    TPoint size( 10,20 );
    texTure->SetSegmentOffset( temp, size );
    
    CleanupStack::PopAndDestroy(image);
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSegmentCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSegmentCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSegmentCountL, "In TestTHuiSetSegmentCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiSetSegmentCountL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSegmentCountL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TInt temp = texTure->SegmentCount() ;
    texTure->SetSegmentCountL( temp );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSegmentNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSegmentNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSegmentCountL, "In TestTHuiSetSegmentCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiSetSegmentCountL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSegmentCountL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0;
    TUint name = 3;
    texTure->SetSegmentName( temp, name);
    
    CleanupStack::PopAndDestroy( image );
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSegmentSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSegmentSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSegmentSizeL, "In TestTHuiSetSegmentSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiSetSegmentSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSegmentSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0 ;
    TSize size( 10,20 );
    texTure->SetSegmentSize( temp, size );
    
    CleanupStack::PopAndDestroy( image );
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSegmentTextureSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSegmentTextureSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSegmentSizeL, "In TestTHuiSetSegmentSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiSetSegmentSizeL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSegmentSizeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TUint8* image = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgb888;
    TInt imageSize = (aFormat == EHuiTextureFormatRgb888 ? 3 : 4) * 100 * 200;
    image = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(image);
    for(TInt t=0; t<imageSize; t++)
        {
        image[t] = ((t % 3) + 1) * 2; // 2,4,6
        }
    // try to upload!
    texTure->UploadL(aFormat,
                     TSize(100, 200),
                     image,
                     EHuiTextureUploadFlagRetainResolution);
    
    TInt temp = 0 ;
    TSize size( 10,20 );
    texTure->SetSegmentTextureSize( temp, size );
    
    CleanupStack::PopAndDestroy( image );
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSkinContentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSkinContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSkinContentL, "In TestTHuiSetSkinContentL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetSkinContentL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSkinContentL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );

    texTure->SetSkinContent( ETrue );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiIsSkinContentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiIsSkinContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiIsSkinContentL, "In TestTHuiIsSkinContentL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiIsSkinContentL );
    // Print to log file 
    iLog->Log( KTestTHuiIsSkinContentL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    STIF_ASSERT_TRUE( !texTure->IsSkinContent());
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTypeL, "In TestTHuiTypeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTypeL );
    // Print to log file 
    iLog->Log( KTestTHuiTypeL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );

    texTure->Type();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSessionIdL, "In TestTHuiSessionIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSessionIdL );
    // Print to log file 
    iLog->Log( KTestTHuiSessionIdL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );

    texTure->SessionId();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetSessionIdL, "In TestTHuiSetSessionIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetSessionIdL );
    // Print to log file 
    iLog->Log( KTestTHuiSetSessionIdL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    TInt temp = 2 ;
    texTure->SetSessionId( temp );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetPriorityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetPriorityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetPriorityL, "In TestTHuiSetPriorityL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetPriorityL );
    // Print to log file 
    iLog->Log( KTestTHuiSetPriorityL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    TInt temp = 2 ;
    texTure->SetPriority( temp );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPriorityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPriorityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPriorityL, "In TestTHuiPriorityL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPriorityL );
    // Print to log file 
    iLog->Log( KTestTHuiPriorityL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->Priority();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiEnableAutoSizeCalculationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiEnableAutoSizeCalculationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiEnableAutoSizeCalculationL, 
            "In TestTHuiEnableAutoSizeCalculationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTHuiEnableAutoSizeCalculationL );
    // Print to log file 
    iLog->Log( KTestTHuiEnableAutoSizeCalculationL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    TBool target = EFalse;
    texTure->EnableAutoSizeCalculation(target);
    
    TBool target2 = ETrue;
    texTure->EnableAutoSizeCalculation(target2);
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiSetAutoSizeParamsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiSetAutoSizeParamsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetAutoSizeParamsL, "In TestTHuiSetAutoSizeParamsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetAutoSizeParamsL );
    // Print to log file 
    iLog->Log( KTestTHuiSetAutoSizeParamsL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    
    THuiTextureAutoSizeParams newparams = texTure->AutoSizeParams();
    newparams.SetSizeLowerThreshold(THuiTextureAutoSizeParams::EHigh);
    texTure->SetAutoSizeParams(newparams);
    
    THuiTextureAutoSizeParams resultparams = texTure->AutoSizeParams();
    TInt target = THuiTextureAutoSizeParams::EHigh;
    STIF_ASSERT_EQUALS( target, resultparams.SizeLowerThreshold() );
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiAutoSizeParamsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiAutoSizeParamsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiSetAutoSizeParamsL, "In TestTHuiAutoSizeParamsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiSetAutoSizeParamsL );
    // Print to log file 
    iLog->Log( KTestTHuiSetAutoSizeParamsL );
    
    CHuiTexture* texTure = CHuiTexture::NewL();
    CleanupStack::PushL( texTure );
    
    texTure->AutoSizeParams();
    
    CleanupStack::PopAndDestroy( texTure );
    
    return KErrNone;
    
    }

//  [End of File]
