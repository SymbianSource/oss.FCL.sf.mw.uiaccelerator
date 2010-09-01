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
* Description:  for testing the method of the CHuiVisual
*
*/

#include <uiacceltk\huitexturemanager.h>
#include <uiacceltk\HuiImageLoaderUtil.h>

#include "testuiaifcoretoolkit.h"

const TInt KTextureId = 0x80000001;
const TInt KTextureNewId = 0x80000002;

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerEnv
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerEnvL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerEnv, "In TestHuiTxureManagerEnv" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerEnv );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerEnv );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiEnv* env = &( txureManager->Env() );
    
    STIF_ASSERT_NOT_NULL( env );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerTexture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerTexture, "In TestHuiTxureManagerTexture" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerTexture );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerTexture );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiTexture* texture = txureManager->Texture( KTextureId );
    CleanupStack::PushL( texture );
    STIF_ASSERT_NOT_NULL( texture )
    CleanupStack::PopAndDestroy( texture );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerTextureConst
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerTextureConstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerTextureConst, "In TestHuiTxureManagerTextureConst" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerTextureConst );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerTextureConst );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    const CHuiTexture* texture = const_cast<const CHuiTextureManager*>( txureManager )->Texture( KTextureId );
    
    STIF_ASSERT_NOT_NULL( texture );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerTextureLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerTextureL, "In TestHuiTxureManagerTextureL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerTextureL );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerTextureL );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiTexture* texture = txureManager->TextureL( KTextureId );
    
    STIF_ASSERT_NOT_NULL( texture );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerSetImagePathL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerSetImagePathL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerSetImagePathL, "In TestHuiTxureManagerSetImagePathL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerSetImagePathL );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerSetImagePathL );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    TRAPD( error, txureManager->SetImagePathL( _L("c:\\data\\images\\") ) );
    
    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerImagePath
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerImagePath( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerImagePath, "In TestHuiTxureManagerImagePath" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerImagePath );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerImagePath );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->ImagePath();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerBlankTextureConstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerBlankTextureConstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerBlankTextureConst, "In TestHuiTxureManagerBlankTextureConst" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerBlankTextureConst );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerBlankTextureConst );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    const CHuiTexture* texture = &( const_cast<const CHuiTextureManager*>( txureManager )->BlankTexture() );
    
    STIF_ASSERT_NOT_NULL( texture );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerBlankTexture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerBlankTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerBlankTexture, "In TestHuiTxureManagerBlankTexture" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerBlankTexture );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerBlankTexture );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiTexture* texture = &( txureManager->BlankTexture() );
    
    STIF_ASSERT_NOT_NULL( texture );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerLoadTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerLoadTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerLoadTextureL, "In TestHuiTxureManagerLoadTextureL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerLoadTextureL );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerLoadTextureL );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->LoadTextureL( _L("test.bmp") );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerLoadTextureLWithSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerLoadTextureLWithIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerLoadTextureLWithSize, "In TestHuiTxureManagerLoadTextureLWithSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerLoadTextureLWithSize );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerLoadTextureLWithSize );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->LoadTextureL( KTextureId );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerLoadTextureLWithSizeImage
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerLoadTextureLWithSizeImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerLoadTextureLWithSizeImage, "In TestHuiTxureManagerLoadTextureLWithSizeImage" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerLoadTextureLWithSizeImage );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerLoadTextureLWithSizeImage );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->LoadTextureL( _L("test.bmp"), TSize( 0, 0 ) );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerCreateTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerCreateTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerCreateTextureL, "In TestHuiTxureManagerCreateTextureL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerCreateTextureL );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerCreateTextureL );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiImageLoaderUtil* iImageLoaderUtil =  new (ELeave) CHuiImageLoaderUtil();
    
    THuiTextureUploadFlags flag = (THuiTextureUploadFlags)(
            EHuiTextureUploadFlagGenerateShadow  | 
            EHuiTextureUploadFlagRetainResolution );
    
    TUid tUid = { KTextureId };
    
    MHuiBitmapProvider* bmpProvider = iImageLoaderUtil->CreateImageLoaderL( tUid, EAknsAppIconTypeList );

    CHuiTexture* tex = & ( txureManager->CreateTextureL( KTextureId, bmpProvider, flag ) );
    
    STIF_ASSERT_NOT_NULL( tex );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerUpdateTextureFromBitmapL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerUpdateTextureFromBitmapL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerUpdateTextureFromBitmapL, "In TestHuiTxureManagerUpdateTextureFromBitmapL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerUpdateTextureFromBitmapL );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerUpdateTextureFromBitmapL );

    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->UpdateTextureFromBitmapL( KTextureId );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerUnloadTexture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerUnloadTexture( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerUnloadTexture, "In TestHuiTxureManagerUnloadTexture" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerUnloadTexture );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerUnloadTexture );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->UnloadTexture( _L("test.bmp") );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerUnloadTextureWithID
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerUnloadTextureWithID( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerUnloadTextureWithID, "In TestHuiTxureManagerUnloadTextureWithID" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerUnloadTextureWithID );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerUnloadTextureWithID );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->UnloadTexture( KTextureId );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerDefineFileNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerDefineFileNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerDefineFileNameL, "In TestHuiTxureManagerDefineFileNameL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerDefineFileNameL );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerDefineFileNameL );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->DefineFileNameL( KTextureId, _L("test.bmp") );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerLoadQueueCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerLoadQueueCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerLoadQueueCount, "In TestHuiTxureManagerLoadQueueCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerLoadQueueCount );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerLoadQueueCount );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->LoadQueueCount();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerState, "In TestHuiTxureManagerState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerState );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerState );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->State();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerProcessor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerProcessorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerProcessor, "In TestHuiTxureManagerProcessor" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerProcessor );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerProcessor );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiTextureProcessor* processor = &( txureManager->Processor() );
    
    STIF_ASSERT_NOT_NULL( processor );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerPrependImagePath
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerPrependImagePath( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerPrependImagePath, "In TestHuiTxureManagerPrependImagePath" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerPrependImagePath );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerPrependImagePath );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    TBuf<30> buf;
    
    txureManager->PrependImagePath( buf );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerSetTextureId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerSetTextureId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerSetTextureId, "In TestHuiTxureManagerSetTextureId" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerSetTextureId );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerSetTextureId );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiTexture* texture = txureManager->Texture( KTextureId );
    
    txureManager->SetTextureId( texture, KTextureNewId );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerIsLoaded
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerIsLoaded( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerIsLoaded, "In TestHuiTxureManagerIsLoaded" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerIsLoaded );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerIsLoaded );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    txureManager->IsLoaded( _L("test.bmp") );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerIsLoadedWithID
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerIsLoadedWithID( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerIsLoadedWithID, "In TestHuiTxureManagerIsLoadedWithID" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerIsLoadedWithID );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerIsLoadedWithID );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    TBool flag = txureManager->IsLoaded( KTextureId );
    
    STIF_ASSERT_TRUE( flag );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTxureManagerIsLoadedWithTexture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTxureManagerIsLoadedWithTexture( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTxureManagerIsLoadedWithTexture, "In TestHuiTxureManagerIsLoadedWithTexture" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTxureManagerIsLoadedWithTexture );
    // Print to log file
    iLog->Log( KTestHuiTxureManagerIsLoadedWithTexture );
    
    CHuiTextureManager* txureManager = &( iHuiEnv->TextureManager() );
    
    CHuiTexture* texture = txureManager->Texture( KTextureId );
    
    TBool flag = txureManager->IsLoaded( texture );
    
    STIF_ASSERT_TRUE( flag );
    
    return KErrNone;

    }

// End of file
