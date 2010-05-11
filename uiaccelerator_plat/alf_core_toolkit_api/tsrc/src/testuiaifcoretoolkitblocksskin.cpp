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
#include <uiacceltk/huiskin.h>
#include <uiacceltk/huidisplaycoecontrol.h>

#include "testuiaifcoretoolkit.h"

// this class test the abstract CHuiSkin class
class CHuiSkinImp : public CHuiSkin
    {
public:
    TRgb StyleTextColor(THuiPreconfiguredTextStyle /*aStyle*/,
       THuiBackgroundType /*aBackgroundType*/) const
       {
       TRgb rgb;
       return rgb;
       }
    };
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinOrientationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinOrientationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinOrientationL, "In TestHSkinOrientationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinOrientationL );
    // Print to log file
    iLog->Log( KTestHSkinOrientationL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    skin->Orientation();
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinLocationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinLocationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinLocationL, "In TestHSkinLocationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinLocationL );
    // Print to log file
    iLog->Log( KTestHSkinLocationL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    skin->Location( EHuiSkinElementSoftKeys );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinNotifyDisplaySizeChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinNotifyDisplaySizeChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinNotifyDisplaySizeChangedL, 
            "In TestHSkinNotifyDisplaySizeChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestHSkinNotifyDisplaySizeChangedL );
    // Print to log file
    iLog->Log( KTestHSkinNotifyDisplaySizeChangedL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    skin->NotifyDisplaySizeChangedL();
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinSetContextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinSetContextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinSetContextL, "In TestHSkinSetContextL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinSetContextL );
    // Print to log file
    iLog->Log( KTestHSkinSetContextL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
   
     CHuiDisplayCoeControl* ctrl= 
                         CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
     CleanupStack::PushL( ctrl );
     CHuiEnv::RefreshCallBack( iHuiEnv );
     CHuiGc* gc = &iHuiEnv->Skin().Context();
     skin->SetContext( *gc );
     CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinContextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinContextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinContextL, "In TestHSkinContextL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinContextL );
    // Print to log file
    iLog->Log( KTestHSkinContextL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    CHuiDisplayCoeControl* ctrl= 
                        CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc* gc = &iHuiEnv->Skin().Context();
    skin->SetContext( *gc );
    skin->Context();
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinStyleTextColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinStyleTextColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinStyleTextColorL, "In TestHSkinStyleTextColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinStyleTextColorL );
    // Print to log file
    iLog->Log( KTestHSkinStyleTextColorL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkinImp* skin = (CHuiSkinImp* )&huiVisual->BrushSkin();
    
    skin->StyleTextColor( EHuiTextStyleNormal, EHuiBackgroundTypeLight );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinTextureL, "In TestHSkinTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinTextureL );
    // Print to log file
    iLog->Log( KTestHSkinTextureL );
        
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    skin->TextureL( EHuiSkinBackgroundTexture );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinReleaseTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinReleaseTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinReleaseTextureL, "In TestHSkinReleaseTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinReleaseTextureL );
    // Print to log file
    iLog->Log( KTestHSkinReleaseTextureL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    skin->ReleaseTexture( EHuiSkinBackgroundTexture );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinGetTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinGetTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinGetTextureL, "In TestHSkinGetTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHSkinGetTextureL );
    // Print to log file
    iLog->Log( KTestHSkinGetTextureL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    TInt temp = 0;
    const CHuiTexture* outTexture = NULL;
    
    skin->GetTexture( temp, outTexture );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinTextureContentUploadedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinTextureContentUploadedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinTextureContentUploadedL, 
            "In TestHSkinTextureContentUploadedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestHSkinTextureContentUploadedL );
    // Print to log file
    iLog->Log( KTestHSkinTextureContentUploadedL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    CHuiTexture* outTexture = CHuiTexture::NewL();
    CleanupStack::PushL( outTexture );
    skin->TextureContentUploaded( *outTexture );
    CleanupStack::PopAndDestroy( outTexture );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinTextureContentReleasedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinTextureContentReleasedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinTextureContentReleasedL, 
            "In TestHSkinTextureContentReleasedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestHSkinTextureContentReleasedL );
    // Print to log file
    iLog->Log( KTestHSkinTextureContentReleasedL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    CHuiTexture* outTexture = CHuiTexture::NewL();
    CleanupStack::PushL( outTexture );
    skin->TextureContentReleased( *outTexture );
    CleanupStack::PopAndDestroy( outTexture );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHSkinRestoreTextureContentLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHSkinRestoreTextureContentLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHSkinRestoreTextureContentLL, 
            "In TestHSkinRestoreTextureContentLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestHSkinRestoreTextureContentLL );
    // Print to log file
    iLog->Log( KTestHSkinRestoreTextureContentLL );
    
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    CHuiSkin* skin = &huiVisual->BrushSkin();
    
    CHuiTexture* outTexture = CHuiTexture::NewL();
    CleanupStack::PushL( outTexture );
    skin->RestoreTextureContentL( *outTexture );
    CleanupStack::PopAndDestroy( outTexture );
    
    return KErrNone;
    }

//  [End of File]
