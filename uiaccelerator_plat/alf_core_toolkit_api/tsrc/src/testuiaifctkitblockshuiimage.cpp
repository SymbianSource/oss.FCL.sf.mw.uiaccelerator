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
#include <fbs.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huiimage.h>
#include <uiacceltk/huitexturehandle.h>

#include "testuiaifcoretoolkit.h"
#include "testuiaifblockstexturechild.h"
#include "testuiaifblocksmanagerchild.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIConstructorWithParaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIConstructorWithParaL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIConstructorWithParaL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    CHuiTexture* texture = CHuiTexture::NewL();
    CleanupStack::PushL( texture );
    THuiImage image( *texture );
    CleanupStack::PopAndDestroy( texture );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHISegmentCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHISegmentCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHISegmentCountL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TInt count = image.SegmentCount();
    STIF_ASSERT_EQUALS( count, 0 );

    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle();
    CHuiTexture* texture = CHuiTexture::NewL( handle );
    CleanupStack::PushL( texture );
    THuiImage image1( *texture );
    count = image1.SegmentCount();
    STIF_ASSERT_EQUALS( count, 0 );
    CleanupStack::PopAndDestroy( texture );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIGetVertexCoordsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIGetVertexCoordsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIGetVertexCoordsL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TInt16* coords = new( ELeave ) TInt16;
    image.GetVertexCoords( coords );

    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle();
    CHuiTexture* texture = CHuiTexture::NewL( handle );
    CleanupStack::PushL( texture );
    THuiImage image1( *texture );
    image1.GetVertexCoords( coords );
    CleanupStack::PopAndDestroy( texture );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIGetTexCoordsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIGetTexCoordsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIGetTexCoordsL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TReal32* coords = new( ELeave ) TReal32;
    image.GetTexCoords( coords );

    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle();
    CHuiTexture* texture = CHuiTexture::NewL( handle );
    CleanupStack::PushL( texture );
    THuiImage image1( *texture );
    image1.GetTexCoords( coords );
    CleanupStack::PopAndDestroy( texture );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHISetTexCoords
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHISetTexCoordsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHISetTexCoords" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TReal32* coords = new( ELeave ) TReal32;
    image.SetTexCoords();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHITopLeft
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHITopLeftL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHITopLeft" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TReal32* coords = new( ELeave ) TReal32;
    image.TopLeft();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIBottomRight
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIBottomRightL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIBottomRight" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TReal32* coords = new( ELeave ) TReal32;
    image.BottomRight();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIHasTexture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIHasTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIHasTexture" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    TReal32* coords = new( ELeave ) TReal32;
    TBool has = image.HasTexture();
    STIF_ASSERT_FALSE( has );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHISetTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHISetTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHISetTextureL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    CleanupStack::PushL( textureChild );
    image.SetTexture( *textureChild );
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHITextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHITextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHITextureL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    CleanupStack::PushL( textureChild );
    image.SetTexture( *textureChild );
    image.Texture();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHITextureIfL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHITextureIfL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHITextureIfL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    CleanupStack::PushL( textureChild );
    image.SetTexture( *textureChild );
    image.TextureIf();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIHasShadow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIHasShadow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIHasShadow" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    image.HasShadow();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIShadowTexture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIShadowTexture( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIShadowTexture" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    image.ShadowTexture();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHITranslate
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHITranslate( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHITranslate" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    image.Translate( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHIScale
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHIScale( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiImage, "In TestTHIScale" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiImage );
    // Print to log file
    iLog->Log( KHuiImage );

    THuiImage image;
    image.Scale( 1, 1 );

    return KErrNone;
    }
