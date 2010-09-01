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
#include <uiacceltk/huis60skin.h>
#include <uiacceltk/huidisplaycoecontrol.h>

#include "testuiaifcoretoolkit.h"

//this class is to be used to test CHuiS60Skin class

class CHuiS60SkinImp : public CHuiS60Skin
    {
public:
    //constructor
    CHuiS60SkinImp(CHuiEnv& aEnv):CHuiS60Skin( aEnv )
    {
    }
    //this function is used to test SkinExtension function 
    void TestSkinExtension()
        {
        TUid aExtensionUid;
        TAny* uid = &aExtensionUid;
        TAny** aExtensionParameters = &uid;
        SkinExtension(  aExtensionUid, aExtensionParameters );
        }
    };
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinCHuiS60SkinL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinCHuiS60SkinL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinCHuiS60SkinL, "In TestH60SkinCHuiS60SkinL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60SkinCHuiS60SkinL );
    // Print to log file 
    iLog->Log( KTestH60SkinCHuiS60SkinL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    delete skin;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinConstructLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinConstructLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinCHuiS60SkinL, "In TestH60SkinCHuiS60SkinL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60SkinCHuiS60SkinL );
    // Print to log file 
    iLog->Log( KTestH60SkinCHuiS60SkinL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinLocationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinLocationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinLocationL, "In TestH60SkinLocationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60SkinLocationL );
    // Print to log file 
    iLog->Log( KTestH60SkinLocationL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    skin->Location( EHuiSkinElementSoftKeys );
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinTextureLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinTextureLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinTextureLL, "In TestH60SkinTextureLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60SkinTextureLL );
    // Print to log file 
    iLog->Log( KTestH60SkinTextureLL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    TInt temp = EHuiSkinBackgroundTexture;
    skin->TextureL( temp );
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinReleaseTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinReleaseTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinReleaseTextureL, "In TestH60SkinReleaseTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60SkinReleaseTextureL );
    // Print to log file 
    iLog->Log( KTestH60SkinReleaseTextureL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    skin->ReleaseTexture( EHuiSkinBackgroundTexture );
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinNotifyDisplaySizeChangedLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinNotifyDisplaySizeChangedLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinNotifyDisplaySizeChangedLL, 
            "In TestH60SkinNotifyDisplaySizeChangedLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinNotifyDisplaySizeChangedLL );
    // Print to log file 
    iLog->Log( KTestH60SkinNotifyDisplaySizeChangedLL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    skin->NotifyDisplaySizeChangedL();
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinStyleTextColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinStyleTextColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinStyleTextColorL, 
            "In TestH60SkinStyleTextColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinStyleTextColorL );
    // Print to log file 
    iLog->Log( KTestH60SkinStyleTextColorL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    skin->StyleTextColor( EHuiTextStyleNormal,EHuiBackgroundTypeLight);
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinRestoreTextureContentLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinRestoreTextureContentLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinRestoreTextureContentLL, 
            "In TestH60SkinRestoreTextureContentLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinRestoreTextureContentLL );
    // Print to log file 
    iLog->Log( KTestH60SkinRestoreTextureContentLL );
    
    CHuiTexture* outTexture = CHuiTexture::NewL();
    CleanupStack::PushL( outTexture );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    skin->RestoreTextureContentL( *outTexture );
    CleanupStack::PopAndDestroy( skin );
    
    CleanupStack::PopAndDestroy( outTexture );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinOrientationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinOrientationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinOrientationL, 
            "In TestH60SkinOrientationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinOrientationL );
    // Print to log file 
    iLog->Log( KTestH60SkinOrientationL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    skin->Orientation();
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinSetContextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinSetContextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinSetContextL, 
            "In TestH60SkinSetContextL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinSetContextL );
    // Print to log file 
    iLog->Log( KTestH60SkinSetContextL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    
    CHuiDisplayCoeControl* ctrl= 
                         CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc* gc = &iHuiEnv->Skin().Context();
    skin->SetContext( *gc );
    CleanupStack::PopAndDestroy( ctrl );
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinContextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinContextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinContextL, 
            "In TestH60SkinContextL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinContextL );
    // Print to log file 
    iLog->Log( KTestH60SkinContextL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    
    CHuiDisplayCoeControl* ctrl= 
                        CHuiDisplayCoeControl::NewL( *iHuiEnv, iDisplayRect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc* gc = &iHuiEnv->Skin().Context();
    skin->SetContext( *gc );
    skin->Context();
    CleanupStack::PopAndDestroy( ctrl );
    CleanupStack::PopAndDestroy( skin );

    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinGetTextureL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinGetTextureL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinGetTextureL, 
            "In TestH60SkinGetTextureL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinGetTextureL );
    // Print to log file 
    iLog->Log( KTestH60SkinGetTextureL );
    
    CHuiS60Skin* skin = new (ELeave) CHuiS60Skin( *iHuiEnv );
    CleanupStack::PushL( skin );
    skin->ConstructL();
    TInt temp = 0;
    const CHuiTexture* outTexture = NULL;
    skin->GetTexture( temp, outTexture );
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60SkinSkinExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60SkinSkinExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60SkinSkinExtensionL, 
            "In TestH60SkinSkinExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestH60SkinSkinExtensionL );
    // Print to log file 
    iLog->Log( KTestH60SkinSkinExtensionL );
    
    CHuiS60SkinImp* skin = new (ELeave) CHuiS60SkinImp( *iHuiEnv );
    CleanupStack::PushL( skin );
    
    skin->TestSkinExtension();
    CleanupStack::PopAndDestroy( skin );
    
    return KErrNone;
    
    }

//  [End of File]
