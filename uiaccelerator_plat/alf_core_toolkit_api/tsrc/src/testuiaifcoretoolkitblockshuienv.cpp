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
#include <avkon.mbg>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huistatic.h>
#include <uiacceltk/huievent.h>
#include <uiacceltk/huieventhandler.h>
#include "testuiaifcoretoolkit.h"


//this class test for MHuiEventHandler class

class CHuiEventHandlerImp : public  CBase, MHuiEventHandler
    {
public:
    //default construct
    CHuiEventHandlerImp()
        {
        }
    //inherite from MHuiEventHandler
    TBool OfferEventL(const THuiEvent& /*aEvent*/)
        {
        return ETrue;
        }
    };
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvHuiEnvLC
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvHuiEnvLC( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvHuiEnvLC, "In TestTTHuiCEnvHuiEnvLC" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvHuiEnvLC );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvHuiEnvLC );
    
    //NewLC function has been call by the NewL function.
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvRenderer
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvRenderer( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvRenderer, "In TestTTHuiCEnvRenderer" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvRenderer );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvRenderer );
    
    iHuiEnv->Renderer();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvNewDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvNewDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvNewDisplayL, "In TestTTHuiCEnvNewDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvNewDisplayL );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvNewDisplayL );
    
    iHuiEnv->NewDisplayL( iDisplayRect, NULL, 0, NULL, CHuiDisplay::EDisplayNormal);
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvNewDisplayLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvNewDisplayLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvNewDisplayLL, "In TestTTHuiCEnvNewDisplayLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvNewDisplayLL );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvNewDisplayLL );
    
    TUid bufferUid = {KTestScreenBufferUidValue};
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal,bufferUid );
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvDisplayCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvDisplayCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvDisplayCount, "In TestTTHuiCEnvDisplayCount" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvDisplayCount );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvDisplayCount );
    
    iHuiEnv->DisplayCount();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvSetRefreshMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvSetRefreshMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvSetRefreshMode, "In TestTTHuiCEnvSetRefreshMode" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvSetRefreshMode );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvSetRefreshMode );
    
    iHuiEnv->SetRefreshMode( EHuiRefreshModeManual );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvRefreshMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvRefreshMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvRefreshMode, "In TestTTHuiCEnvRefreshMode" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvRefreshMode );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvRefreshMode );
    
    iHuiEnv->RefreshMode();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvSetMaxFrameRate
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvSetMaxFrameRate( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvSetMaxFrameRate, "In TestTTHuiCEnvSetMaxFrameRate" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvSetMaxFrameRate );
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvSetMaxFrameRate );
    
    TReal32 real = 20;
    iHuiEnv->SetMaxFrameRate( real );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvContinueRefresh
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvContinueRefresh( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvContinueRefresh, "In TestTTHuiCEnvContinueRefresh" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvContinueRefresh);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvContinueRefresh );
    
    iHuiEnv->ContinueRefresh();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvPauseRefresh
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvPauseRefresh( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvPauseRefresh, "In TestTTHuiCEnvPauseRefresh" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvPauseRefresh);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvPauseRefresh );
    
    iHuiEnv->PauseRefresh();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvNewControlGroupL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvNewControlGroupL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvNewControlGroupL, "In TestTTHuiCEnvNewControlGroupL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvNewControlGroupL);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvNewControlGroupL );
    
    TInt temp = 0;
    iHuiEnv->NewControlGroupL( temp );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvDeleteControlGroup
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvDeleteControlGroup( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvDeleteControlGroup, "In TestTTHuiCEnvDeleteControlGroup" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvDeleteControlGroup);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvDeleteControlGroup );
    
    TInt temp = 0;
    iHuiEnv->DeleteControlGroup( temp );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvLoadControlGroupL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvLoadControlGroupL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvLoadControlGroupL, "In TestTTHuiCEnvLoadControlGroupL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvLoadControlGroupL);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvLoadControlGroupL );
    
    TInt groupid = 0;
    iHuiEnv->LoadControlGroupL( groupid );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvControlGroup
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvControlGroup( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvControlGroup, "In TestTTHuiCEnvControlGroup" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvControlGroup);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvControlGroup );

    iHuiEnv->ControlGroup( KHuiCtrlGroupId );
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCEnvLoadBitmapsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCEnvLoadBitmapsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCEnvLoadBitmapsL, "In TestTTHuiCEnvLoadBitmapsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCEnvLoadBitmapsL);
    // Print to log file 
    iLog->Log( KTestTTHuiCEnvLoadBitmapsL );
    
    TInt bitmapid = 0;
    iHuiEnv->LoadBitmapsL( bitmapid );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCVisualFactory
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCVisualFactory( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCVisualFactory, "In TestTTHuiCVisualFactory" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCVisualFactory);
    // Print to log file 
    iLog->Log( KTestTTHuiCVisualFactory );
    
    iHuiEnv->VisualFactory();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCTextureManager
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCTextureManager( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCTextureManager, "In TestTTHuiCTextureManager" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCTextureManager);
    // Print to log file 
    iLog->Log( KTestTTHuiCTextureManager );
    
    iHuiEnv->TextureManager();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCFontManager
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCFontManager( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCFontManager, "In TestTTHuiCFontManager" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCFontManager);
    // Print to log file 
    iLog->Log( KTestTTHuiCFontManager );
    
    iHuiEnv->FontManager();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCTextStyleManager
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCTextStyleManager( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCTextStyleManager, "In TestTTHuiCTextStyleManager" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCTextStyleManager);
    // Print to log file 
    iLog->Log( KTestTTHuiCTextStyleManager );
    
    iHuiEnv->TextStyleManager();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCFindControl
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCFindControl( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCFindControl, "In TestTTHuiCFindControl" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCFindControl);
    // Print to log file 
    iLog->Log( KTestTTHuiCFindControl );
    
    TInt temp = 0;
    iHuiEnv->FindControl( temp );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCSendL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCSendL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCSendL, "In TestTTHuiCSendL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCSendL);
    // Print to log file 
    iLog->Log( KTestTTHuiCSendL );
    
    THuiCommand* aCommand = new ( ELeave )THuiActionCommand( 1 );
    CleanupStack::PushL( aCommand );
    iHuiEnv->Send( *aCommand );
    CleanupStack::PopAndDestroy( aCommand );
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCSendLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCSendLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCSendLL, "In TestTTHuiCSendLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCSendLL);
    // Print to log file 
    iLog->Log( KTestTTHuiCSendLL );
    
    THuiCommand* aCommand = new ( ELeave )THuiActionCommand( 1 );
    CleanupStack::PushL( aCommand );
    
    iHuiEnv->SendL( *aCommand );
    
    CleanupStack::PopAndDestroy( aCommand );
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCancelCommandsL, "In TestTTHuiCCancelCommandsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiCCancelCommandsL);
    // Print to log file 
    iLog->Log( KTestTTHuiCCancelCommandsL );
    
    THuiCommand* aCommand = new ( ELeave )THuiActionCommand( 1 );
    CleanupStack::PushL( aCommand );
    iHuiEnv->CancelCommands( &aCommand );
    CleanupStack::PopAndDestroy( aCommand );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsEventHandlerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCancelCommandsEventHandlerL, 
            "In TestTTHuiCCancelCommandsEventHandlerL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiCCancelCommandsEventHandlerL);
    // Print to log file 
    iLog->Log( KTestTTHuiCCancelCommandsEventHandlerL );
    
    CHuiEventHandlerImp* eventHandler = new ( ELeave ) CHuiEventHandlerImp();
    CleanupStack::PushL( eventHandler );
    iHuiEnv->CancelCommands( &eventHandler );
    CleanupStack::PopAndDestroy( eventHandler );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsTHuiOpL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsTHuiOpL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCancelCommandsTHuiOpL, 
            "In TestTTHuiCCancelCommandsTHuiOpL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiCCancelCommandsTHuiOpL);
    // Print to log file 
    iLog->Log( KTestTTHuiCCancelCommandsTHuiOpL );
    
    THuiCommand* aCommand = new ( ELeave )THuiActionCommand( EHuiOpNone );
    CleanupStack::PushL( aCommand );
    iHuiEnv->CancelCommands( &aCommand, EHuiOpNone);
    CleanupStack::PopAndDestroy( aCommand );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsTIntL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCCancelCommandsTIntL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCCancelCommandsTIntL, 
            "In TestTTHuiCCancelCommandsTIntL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiCCancelCommandsTIntL);
    // Print to log file 
    iLog->Log( KTestTTHuiCCancelCommandsTIntL );
    
    TInt temp = 1;
    THuiCommand* aCommand = new ( ELeave )THuiActionCommand( temp );
    CleanupStack::PushL( aCommand );
    iHuiEnv->CancelCommands( &aCommand, EHuiCommandTypeNone, temp );
    CleanupStack::PopAndDestroy( aCommand );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCTimeUntilCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCTimeUntilCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCTimeUntilCommandL, 
            "In TestTTHuiCTimeUntilCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiCTimeUntilCommandL);
    // Print to log file 
    iLog->Log( KTestTTHuiCTimeUntilCommandL );
    
    TInt temp = 1;
    THuiCommand* aCommand = new ( ELeave )THuiActionCommand( temp );
    CleanupStack::PushL( aCommand );
    iHuiEnv->TimeUntilCommand( aCommand, EHuiCommandTypeNone);
    CleanupStack::PopAndDestroy( aCommand );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiCSkin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiCSkin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiCSkin, 
            "In TestTTHuiCSkin" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTTHuiCSkin);
    // Print to log file 
    iLog->Log( KTestTTHuiCSkin );
    
    iHuiEnv->Skin();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTStartRefresh
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTStartRefresh( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTStartRefresh, "In TestTStartRefresh" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTStartRefresh);
    // Print to log file 
    iLog->Log( KTestTStartRefresh );
    
    TInt refTime = 10;
    iHuiEnv->StartRefresh( refTime );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHandleKeyEventLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHandleKeyEventLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHandleKeyEventLL, "In TestTHandleKeyEventLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTHandleKeyEventLL);
    // Print to log file 
    iLog->Log( KTestTHandleKeyEventLL );
    
    TKeyEvent keyEvent;
    
    iHuiEnv->HandleKeyEventL( keyEvent, EEventKey );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTSetIdleThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTSetIdleThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTSetIdleThreshold, "In TestTSetIdleThreshold" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTSetIdleThreshold);
    // Print to log file 
    iLog->Log( KTestTSetIdleThreshold );
    
    TInt refTime = 10;
    iHuiEnv->SetIdleThreshold( refTime );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTBroadcastEventLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTBroadcastEventLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTBroadcastEventLL, "In TestTBroadcastEventLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTBroadcastEventLL);
    // Print to log file 
    iLog->Log( KTestTBroadcastEventLL );
    
    TInt temp = 0;
    THuiEvent huiEvent( temp );
    iHuiEnv->BroadcastEventL( huiEvent );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTPrimaryDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTPrimaryDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTPrimaryDisplayL, "In TestTPrimaryDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTPrimaryDisplayL);
    // Print to log file 
    iLog->Log( KTestTPrimaryDisplayL );
    
    iHuiEnv->NewDisplayL( iDisplayRect );
    iHuiEnv->PrimaryDisplay();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCHuiEnvDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCHuiEnvDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCHuiEnvDisplayL, "In TestTCHuiEnvDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCHuiEnvDisplayL);
    // Print to log file 
    iLog->Log( KTestTCHuiEnvDisplayL );
    
    TInt index = 0;
    iHuiEnv->NewDisplayL( iDisplayRect );
    iHuiEnv->CHuiEnv::Display( index );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCNotifySkinChangedLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCNotifySkinChangedLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCNotifySkinChangedLL, "In TestTCNotifySkinChangedLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCNotifySkinChangedLL);
    // Print to log file 
    iLog->Log( KTestTCNotifySkinChangedLL );
    
    iHuiEnv->NotifySkinChangedL();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCRefreshCallBack
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCRefreshCallBack( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCRefreshCallBack, "In TestTCRefreshCallBack" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCRefreshCallBack);
    // Print to log file 
    iLog->Log( KTestTCRefreshCallBack );
    
    CHuiEnv::RefreshCallBack( iHuiEnv );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCRelease
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCRelease( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCRelease, "In TestTCRelease" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCRelease);
    // Print to log file 
    iLog->Log( KTestTCRelease );
    
    iHuiEnv->Release();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCRestoreLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCRestoreL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCRestoreL, "In TestTCRestoreLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCRestoreL);
    // Print to log file 
    iLog->Log( KTestTCRestoreL );
    
    iHuiEnv->RestoreL();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCSetMaxCpuTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCSetMaxCpuTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCSetMaxCpuTime, "In TestTCSetMaxCpuTime" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCSetMaxCpuTime);
    // Print to log file 
    iLog->Log( KTestTCSetMaxCpuTime );
    TUint time = 20;
    iHuiEnv->SetMaxCpuTime( time );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCStatic
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCStatic( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCStatic, "In TestTCStatic" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCStatic);
    // Print to log file 
    iLog->Log( KTestTCStatic );
   
    CHuiEnv::Static();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCThemeManager
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCThemeManager( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCThemeManager, "In TestTCThemeManager" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCThemeManager);
    // Print to log file 
    iLog->Log( KTestTCThemeManager );
   
    iHuiEnv->ThemeManager();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCSetFPSCounterThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCSetFPSCounterThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCSetFPSCounterThreshold, "In TestTCSetFPSCounterThreshold" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTCSetFPSCounterThreshold);
    // Print to log file 
    iLog->Log( KTestTCSetFPSCounterThreshold );
   
    TUint time = 10;
    iHuiEnv->SetFPSCounterThreshold( time );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTCChangeRefreshLoopPriority
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTCChangeRefreshLoopPriority( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTCChangeRefreshLoopPriority, "In TestTCSetFPSCounterThreshold" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTCChangeRefreshLoopPriority);
    // Print to log file 
    iLog->Log( KTestTCChangeRefreshLoopPriority );
   
    iHuiEnv->ChangeRefreshLoopPriority( CActive::EPriorityStandard );
    
    return KErrNone;
    
    }

//  [End of File]
