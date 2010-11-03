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



// [INCLUDE FILES]
#include <e32svr.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huianimatedtexture.h>
#include <fbs.h>
#include <BITDEV.H> // CFbsDevice
#include <BITSTD.H> // CFbsBitGc

#include "testuiaifcoretoolkit.h"
#include "testuiaifblockstexturechild.h"
#include "testuiaifblocksmanagerchild.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextDestructL, "In TestCHuiATextDestructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextDestructL );
    // Print to log file
    iLog->Log( KTestCHuiATextDestructL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    CleanupStack::PopAndDestroy( textureChild );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextTextureL, "In TestCHuiATextTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextTextureL );
    // Print to log file
    iLog->Log( KTestCHuiATextTextureL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    CHuiTexture& texture = textureChild->Texture();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentedTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentTextureL, "In TestCHuiATextSegmentTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentTextureL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentTextureL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->SegmentedTexture();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentTextureConstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentTextureConstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentTextureConstL, "In TestCHuiATextSegmentTextureConstL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentTextureConstL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentTextureConstL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    const CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    textureChild->SegmentedTexture();
    delete textureChild;

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextShadowedTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextShadowedTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextShadowedTextureL, "In TestCHuiATextShadowedTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextShadowedTextureL );
    // Print to log file
    iLog->Log( KTestCHuiATextShadowedTextureL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->ShadowedTexture();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextShadowedTextureConstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextShadowedTextureConstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentTextureConstL, "In TestCHuiATextSegmentTextureConstL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentTextureConstL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentTextureConstL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    CleanupStack::PushL( textureChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    textureChild->ShadowedTexture();
    CleanupStack::PopAndDestroy( textureChild );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextHasContentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextHasContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextHasContentL, "In TestCHuiATextHasContentL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextHasContentL );
    // Print to log file
    iLog->Log( KTestCHuiATextHasContentL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
//    textureChild->HasContent();
    STIF_ASSERT_EQUALS( textureChild->HasContent(), 0 );
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSizeL, "In TestCHuiATextSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSizeL );
    // Print to log file
    iLog->Log( KTestCHuiATextSizeL );
//my code
    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    TSize logicalSize = textureChild->Size();
    STIF_ASSERT_EQUALS( logicalSize.iWidth, 0 );
    STIF_ASSERT_EQUALS( logicalSize.iHeight, 0 );
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentCountL, "In TestCHuiATextSegmentCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentCountL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentCountL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    STIF_ASSERT_EQUALS( textureChild->SegmentCount(), 0 );
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentNameL( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentNameL, "In TestCHuiATextSegmentNameL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentNameL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentNameL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->SegmentedTexture();
    textureChild->SetSegmentCountL();
    STIF_ASSERT_EQUALS( textureChild->SegmentName( 0 ), (unsigned int)1 );
    textureChild->TextureClearChanged();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextTextureChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextTextureChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextTextureChangedL, "In TestCHuiATextTextureChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextTextureChangedL );
    // Print to log file
    iLog->Log( KTestCHuiATextTextureChangedL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    STIF_ASSERT_EQUALS( textureChild->TextureChanged(), 0 );
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextTextureClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextTextureClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextTextureClearChangedL, "In TestCHuiATextTextureClearChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextTextureClearChangedL );
    // Print to log file
    iLog->Log( KTestCHuiATextTextureClearChangedL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->TextureClearChanged();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextTextureConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextTextureConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextTextureConstructorL, "In TestCHuiATextTextureConstructorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextTextureConstructorL );
    // Print to log file
    iLog->Log( KTestCHuiATextTextureConstructorL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->TextureClearChanged();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextBaseConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextBaseConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextBaseConstructL, "In TestCHuiATextBaseConstructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextBaseConstructL );
    // Print to log file
    iLog->Log( KTestCHuiATextBaseConstructL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->TextureClearChanged();
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParameters = NULL;
    textureChild->TextureExtension( aExtensionUid, aExtensionParameters );
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextTextureExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextTextureExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextTextureExtensionL, "In TestCHuiATextTextureExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextTextureExtensionL );
    // Print to log file
    iLog->Log( KTestCHuiATextTextureExtensionL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->SegmentedTexture();
    textureChild->SetSegmentCountL();
    textureChild->SegmentName( 1 );
    textureChild->TextureClearChanged();
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParameters = NULL;
    textureChild->TextureExtension( aExtensionUid, aExtensionParameters );
    CleanupStack::PopAndDestroy( textureChild );
  
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentSizeL, "In TestCHuiATextSegmentSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentSizeL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentSizeL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->SegmentedTexture();
    textureChild->SetSegmentCountL();
    textureChild->SegmentName( 1 );
    STIF_ASSERT_EQUALS( textureChild->SegmentSize(0), textureChild->Size() );
    textureChild->TextureClearChanged();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentTextureSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentTextureSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentTextureSizeL, "In TestCHuiATextSegmentTextureSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentTextureSizeL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentTextureSizeL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->SegmentedTexture();
    textureChild->SetSegmentCountL();
    textureChild->SegmentName( 1 );
    textureChild->SegmentSize( 0 );
    textureChild->SegmentTextureSize( 0 );
    TInt width = textureChild->SegmentTextureSize(0).iWidth;
    TInt height = textureChild->SegmentTextureSize(0).iHeight;
    STIF_ASSERT_EQUALS( textureChild->SegmentTextureSize(0).iWidth, 0 );
    STIF_ASSERT_EQUALS( textureChild->SegmentTextureSize(0).iHeight, 0 );
    textureChild->TextureClearChanged();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiATextSegmentOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiATextSegmentOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiATextSegmentOffsetL, "In TestCHuiATextSegmentOffsetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiATextSegmentOffsetL );
    // Print to log file
    iLog->Log( KTestCHuiATextSegmentOffsetL );

    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    CleanupStack::PushL( textureChild );
    textureChild->SegmentedTexture();
    textureChild->SetSegmentCountL();
    textureChild->SegmentName( 1 );
    textureChild->SegmentSize( 0 );
    STIF_ASSERT_EQUALS( textureChild->SegmentTextureSize(0).iWidth, 0 );
    STIF_ASSERT_EQUALS( textureChild->SegmentTextureSize(0).iHeight, 0 );
    STIF_ASSERT_EQUALS( textureChild->SegmentOffset(0).iX, 0 );
    STIF_ASSERT_EQUALS( textureChild->SegmentOffset(0).iY, 0 );
    textureChild->TextureClearChanged();
    CleanupStack::PopAndDestroy( textureChild );

    return KErrNone;
    
    }

//  [End of File]
