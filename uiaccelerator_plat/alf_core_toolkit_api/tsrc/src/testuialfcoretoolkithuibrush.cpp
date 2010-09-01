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


#include <uiacceltk/huiBrush.h>
#include <uiacceltk/HuiBorderBrush.h>
#include <uiacceltk/huiframebrush.h>
#include <uiacceltk/HuiDisplayCoeControl.h>

#include "testuiaifcoretoolkit.h"

// FOR DECLARATION
/**
 * This class is used to test huiBrush protected member.
 */
class CTestHuiBrush : public CHuiBrush
    {
public:
    /**
     * Test constructor
     */
    CTestHuiBrush() : CHuiBrush()
        {
        //do nothing.
        }
    ~CTestHuiBrush()
        {
        
        }
    /**
     * Test BrushExtension
     */
    void TestBrushExtension( const TUid& aExtensionUid, TAny** aExtensionParameters )
        {
        CHuiBrush::BrushExtension( aExtensionUid, aExtensionParameters );
        }
    };
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushExpandVisualRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushExpandVisualRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushExpandVisualRectL, "TestHuiBrushExpandVisualRectL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushExpandVisualRectL );
    // Print to log file
    iLog->Log( KTestHuiBrushExpandVisualRectL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    TRect rect(10, 10, 30, 20);
    huiBrush->ExpandVisualRect( rect );
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushSetChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushSetChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushSetChangedL, "TestHuiBrushSetChangedL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushSetChangedL );
    // Print to log file
    iLog->Log( KTestHuiBrushSetChangedL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    huiBrush->SetChanged();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushChangedL, "TestHuiBrushChangedL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushChangedL );
    // Print to log file
    iLog->Log( KTestHuiBrushChangedL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    TBool isChange = huiBrush->Changed();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushClearChangedL, "TestHuiBrushClearChangedL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushClearChangedL );
    // Print to log file
    iLog->Log( KTestHuiBrushClearChangedL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    huiBrush->ClearChanged();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushSetClipToVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushSetClipToVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushSetClipToVisualL, "TestHuiBrushSetClipToVisualL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushSetClipToVisualL );
    // Print to log file
    iLog->Log( KTestHuiBrushSetClipToVisualL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    huiBrush->SetClipToVisual( EFalse );
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushClipToVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushClipToVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushClipToVisualL, "TestHuiBrushClipToVisualL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushClipToVisualL );
    // Print to log file
    iLog->Log( KTestHuiBrushClipToVisualL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    TBool isClipToVisual = huiBrush->ClipToVisual();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushSetLayerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushSetLayerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushSetLayerL, "TestHuiBrushSetLayerL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushSetLayerL );
    // Print to log file
    iLog->Log( KTestHuiBrushSetLayerL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    THuiBrushLayer layer = EHuiBrushLayerBackground;
    huiBrush->SetLayer( layer );
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushLayerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushLayerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushLayerL, "TestHuiBrushLayerL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushLayerL );
    // Print to log file
    iLog->Log( KTestHuiBrushLayerL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    THuiBrushLayer layer = huiBrush->Layer();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushBeginDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushBeginDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushBeginDrawL, "TestHuiBrushBeginDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushBeginDrawL );
    // Print to log file
    iLog->Log( KTestHuiBrushBeginDrawL );

    TAknsItemID id;
    id.Set( TUid::Uid( 0 ), 0 );
    CHuiBrush* huiBrush = CHuiFrameBrush::NewL( id, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    huiBrush->BeginDraw( huiGc, *iHuiVisual );
    CleanupStack::PopAndDestroy( ctrl );
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushDrawL, "TestHuiBrushDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushDrawL );
    // Print to log file
    iLog->Log( KTestHuiBrushDrawL );

    CTestHuiBrush* testHuiBrush = new( ELeave ) CTestHuiBrush;
    CleanupStack::PushL( testHuiBrush );
    STIF_ASSERT_NOT_NULL( testHuiBrush );
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    testHuiBrush->Draw( huiGc, *iHuiVisual );
    CleanupStack::PopAndDestroy( ctrl );
    CleanupStack::PopAndDestroy( testHuiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushEndDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushEndDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushEndDrawL, "TestHuiBrushEndDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushEndDrawL );
    // Print to log file
    iLog->Log( KTestHuiBrushEndDrawL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    huiBrush->EndDraw( huiGc, *iHuiVisual );
    CleanupStack::PopAndDestroy( ctrl );
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushTypeL, "TestHuiBrushTypeL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushTypeL );
    // Print to log file
    iLog->Log( KTestHuiBrushTypeL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    huiBrush->Type();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushSessionIdL, "TestHuiBrushSessionIdL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushSessionIdL );
    // Print to log file
    iLog->Log( KTestHuiBrushSessionIdL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    TInt id = huiBrush->SessionId();
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushSetSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushSetSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushSetSessionIdL, "TestHuiBrushSetSessionIdL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushSetSessionIdL );
    // Print to log file
    iLog->Log( KTestHuiBrushSetSessionIdL );

    CHuiBrush* huiBrush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( huiBrush );
    STIF_ASSERT_NOT_NULL( huiBrush );
    huiBrush->SetSessionId( 0 );
    CleanupStack::PopAndDestroy( huiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushCHuiBrushL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushCHuiBrushL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushCHuiBrushL, "TestHuiBrushCHuiBrushL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushCHuiBrushL );
    // Print to log file
    iLog->Log( KTestHuiBrushCHuiBrushL );

    CTestHuiBrush* testHuiBrush = new( ELeave ) CTestHuiBrush;
    CleanupStack::PushL( testHuiBrush );
    STIF_ASSERT_NOT_NULL( testHuiBrush );
    CleanupStack::PopAndDestroy( testHuiBrush );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushBrushExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushBrushExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushBrushExtensionL, "TestHuiBrushBrushExtensionL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushBrushExtensionL );
    // Print to log file
    iLog->Log( KTestHuiBrushBrushExtensionL );

    CTestHuiBrush* testHuiBrush = new( ELeave ) CTestHuiBrush;
    CleanupStack::PushL( testHuiBrush );
    STIF_ASSERT_NOT_NULL( testHuiBrush );
    testHuiBrush->TestBrushExtension( TUid::Uid( 0 ), NULL );
    CleanupStack::PopAndDestroy( testHuiBrush );
    
    return KErrNone;

    }

//End of file.
