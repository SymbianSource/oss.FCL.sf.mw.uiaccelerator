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
#include <uiacceltk/huitexturehandle.h>

#include "testuiaifcoretoolkit.h"

class TTestHuiTextureHandleExt : public THuiTextureHandle
    {
//friend class CTestUiAifCoreToolkit;

public:
//    TTestHuiTextureHandleExt() : THuiTextureHandle()
//    {
//    }
    TTestHuiTextureHandleExt(TUint aName,
                         const TSize& aSize,
                         const TSize& aTextureSize) :
                         THuiTextureHandle( aName, aSize, aTextureSize )
    {
    }

    };

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle;
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHConstructorWithParaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHConstructorWithParaL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHConstructorWithParaL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHIsNullL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHIsNullL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHIsNullL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    TBool isNull = handle->IsNull();
    STIF_ASSERT_FALSE( isNull );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHHasContentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHHasContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHHasContentL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    TBool has = handle->HasContent();
    STIF_ASSERT_TRUE( has );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHReleaseL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHReleaseL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHReleaseL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->Release();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSetL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle;
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->Set( 1, size, textSize );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSetNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSetNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSetNameL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle;
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SetName( 1 );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSetSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSetSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSetSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle;
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SetSize( size );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSetTextureSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSetTextureSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSetTextureSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle;
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SetTextureSize( textSize );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentedTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentedTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentedTextureL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SegmentedTexture();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentedTextureconstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentedTextureconstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentedTextureconstL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    const_cast< const THuiTextureHandle* > ( handle )->SegmentedTexture();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHShadowedTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHShadowedTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHShadowedTextureL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->ShadowedTexture();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHShadowedTextureconstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHShadowedTextureconstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHShadowedTextureconstL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    const_cast< const THuiTextureHandle* > ( handle )->ShadowedTexture();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHTextureChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHTextureChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHTextureChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->TextureChanged();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHTextureClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHTextureClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHTextureClearChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->TextureClearChanged();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHNameL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->Name();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->Size();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentCountL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SegmentCount();
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentNameL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SegmentName( 1 );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SegmentSize( 1 );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentTextureSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentTextureSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentTextureSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SegmentTextureSize( 1 );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHSegmentOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHSegmentOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiTextureHandle, "In TestTHTHSegmentOffsetL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
    // Print to log file
    iLog->Log( KCHuiTextureHandle );

    TSize size( 1, 1 );
    TSize textSize( 1, 1 );
    THuiTextureHandle* handle = new( ELeave ) THuiTextureHandle( 1, size, textSize );
    CleanupStack::PushL( handle );
    STIF_ASSERT_NOT_NULL( handle );
    handle->SegmentOffset( 1 );
    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTHTextureExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTHTextureExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
//    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
//    _LIT( KCHuiTextureHandle, "In TestTHTHTextureExtensionL" );
//    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiTextureHandle );
//    // Print to log file
//    iLog->Log( KCHuiTextureHandle );
//
//    TSize size( 1, 1 );
//    TSize textSize( 1, 1 );
//    TTestHuiTextureHandleExt* handle = new( ELeave ) TTestHuiTextureHandleExt( 1, size, textSize );
//    CleanupStack::PushL( handle );
//    STIF_ASSERT_NOT_NULL( handle );
//    TUid uid = TUid::Null();
//    TAny** any = NULL;
////    handle->TextureExtension( uid, any );
//    CleanupStack::PopAndDestroy( handle );

    return KErrNone;
    }
