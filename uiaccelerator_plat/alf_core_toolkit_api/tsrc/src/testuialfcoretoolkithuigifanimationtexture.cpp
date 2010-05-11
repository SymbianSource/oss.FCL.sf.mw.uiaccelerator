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


#include <uiacceltk/huigifanimationtexture.h>
#include <alf/alfconstants.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGifAnimationTextureNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGifAnimationTextureNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGifAnimationTextureNewLL, "TestHuiGifAnimationTextureNewLL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGifAnimationTextureNewLL );
    // Print to log file
    iLog->Log( KTestHuiGifAnimationTextureNewLL );

//    RMessage2 message;
    TAlfCreateTextureAnimatedParams params;
    TPckg<TAlfCreateTextureAnimatedParams> paramsPckg(params);
//    message.Read(1,paramsPckg);
    CHuiGifAnimationTexture* animtext = CHuiGifAnimationTexture::NewL(params.iFilename,iHuiEnv->TextureManager(),params.iId, (THuiTextureUploadFlags)(params.iFlags));
    CleanupStack::PushL( animtext );
    STIF_ASSERT_NOT_NULL( animtext );
    CleanupStack::PopAndDestroy( animtext );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGifAnimationTextureIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGifAnimationTextureIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGifAnimationTextureIdL, "TestHuiGifAnimationTextureIdL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGifAnimationTextureIdL );
    // Print to log file
    iLog->Log( KTestHuiGifAnimationTextureIdL );

//    RMessage2 message;
    TAlfCreateTextureAnimatedParams params;
    TPckg<TAlfCreateTextureAnimatedParams> paramsPckg(params);
//    message.Read(1,paramsPckg);
    CHuiGifAnimationTexture* animtext = CHuiGifAnimationTexture::NewL(params.iFilename,iHuiEnv->TextureManager(),params.iId, (THuiTextureUploadFlags)(params.iFlags));
    CleanupStack::PushL( animtext );
    STIF_ASSERT_NOT_NULL( animtext );
    TInt id = animtext->Id();
    CleanupStack::PopAndDestroy( animtext );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGifAnimationTextureStartL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGifAnimationTextureStartL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGifAnimationTextureStartL, "TestHuiGifAnimationTextureStartL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGifAnimationTextureStartL );
    // Print to log file
    iLog->Log( KTestHuiGifAnimationTextureStartL );

//    RMessage2 message;
    TAlfCreateTextureAnimatedParams params;
    TPckg<TAlfCreateTextureAnimatedParams> paramsPckg(params);
//    message.Read(1,paramsPckg);
    CHuiGifAnimationTexture* animtext = CHuiGifAnimationTexture::NewL(params.iFilename,iHuiEnv->TextureManager(),params.iId, (THuiTextureUploadFlags)(params.iFlags));
    CleanupStack::PushL( animtext );
    STIF_ASSERT_NOT_NULL( animtext );
    animtext->Start();
    CleanupStack::PopAndDestroy( animtext );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGifAnimationTextureStopL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGifAnimationTextureStopL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGifAnimationTextureStopL, "TestHuiGifAnimationTextureStopL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGifAnimationTextureStopL );
    // Print to log file
    iLog->Log( KTestHuiGifAnimationTextureStopL );

//    RMessage2 message;
    TAlfCreateTextureAnimatedParams params;
    TPckg<TAlfCreateTextureAnimatedParams> paramsPckg(params);
//    message.Read(1,paramsPckg);
    CHuiGifAnimationTexture* animtext = CHuiGifAnimationTexture::NewL(params.iFilename,iHuiEnv->TextureManager(),params.iId, (THuiTextureUploadFlags)(params.iFlags));
    CleanupStack::PushL( animtext );
    STIF_ASSERT_NOT_NULL( animtext );
    animtext->Stop();
    CleanupStack::PopAndDestroy( animtext );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGifAnimationTextureEnableAnimationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGifAnimationTextureEnableAnimationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGifAnimationTextureEnableAnimationL, "TestHuiGifAnimationTextureEnableAnimationL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGifAnimationTextureEnableAnimationL );
    // Print to log file
    iLog->Log( KTestHuiGifAnimationTextureEnableAnimationL );

//    RMessage2 message;
    TAlfCreateTextureAnimatedParams params;
    TPckg<TAlfCreateTextureAnimatedParams> paramsPckg(params);
//    message.Read(1,paramsPckg);
    CHuiGifAnimationTexture* animtext = CHuiGifAnimationTexture::NewL(params.iFilename,iHuiEnv->TextureManager(),params.iId, (THuiTextureUploadFlags)(params.iFlags));
    CleanupStack::PushL( animtext );
    STIF_ASSERT_NOT_NULL( animtext );
    animtext->EnableAnimation( EFalse );
    CleanupStack::PopAndDestroy( animtext );
    
    return KErrNone;

    }


//End of file.
