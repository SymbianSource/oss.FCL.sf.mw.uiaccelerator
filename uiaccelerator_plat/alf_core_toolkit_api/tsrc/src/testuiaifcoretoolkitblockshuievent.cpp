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
#include <uiacceltk/huievent.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHETHuiEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHETHuiEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHETHuiEventL, "In TestTHETHuiEventL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHETHuiEventL );
    // Print to log file 
    iLog->Log( KTestTHETHuiEventL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    delete event;
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHETPointerEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHETPointerEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHETPointerEventL, "In TestTHETPointerEventL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHETPointerEventL );
    // Print to log file 
    iLog->Log( KTestTHETPointerEventL );
    
    TPointerEvent pointEvent;
    THuiEvent* event = new(ELeave) THuiEvent( NULL, pointEvent );
    delete event;
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHETypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHETypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHETypeL, "In TestTHETypeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHETypeL );
    // Print to log file 
    iLog->Log( KTestTHETypeL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->Type();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEIsCustomEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEIsCustomEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEIsCustomEventL, "In TestTHEIsCustomEventL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEIsCustomEventL );
    // Print to log file 
    iLog->Log( KTestTHEIsCustomEventL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->IsCustomEvent();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEIsKeyEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEIsKeyEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEIsKeyEventL, "In TestTHEIsKeyEventL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEIsKeyEventL );
    // Print to log file 
    iLog->Log( KTestTHEIsKeyEventL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->IsKeyEvent();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEIsPointerEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEIsPointerEventL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEIsPointerEventL, "In TestTHEIsPointerEventL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEIsPointerEventL );
    // Print to log file 
    iLog->Log( KTestTHEIsPointerEventL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->IsPointerEvent();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEDisplayL, "In TestTHEDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEDisplayL );
    // Print to log file 
    iLog->Log( KTestTHEDisplayL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    TPointerEvent pointerEvent;
    THuiEvent* event = new(ELeave) THuiEvent( huiDisplay, pointerEvent );
    CleanupStack::PushL( event );
    
    event->Display();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEPointerDownL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEPointerDownL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEPointerDownL, "In TestTHEPointerDownL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEPointerDownL );
    // Print to log file 
    iLog->Log( KTestTHEPointerDownL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->PointerDown();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEPointerUpL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEPointerUpL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEPointerUpL, "In TestTHEPointerUpL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEPointerUpL );
    // Print to log file 
    iLog->Log( KTestTHEPointerUpL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->PointerUp();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEPointerLongTapL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEPointerLongTapL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEPointerUpL, "In TestTHEPointerUpL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEPointerUpL );
    // Print to log file 
    iLog->Log( KTestTHEPointerUpL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->PointerLongTap();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHESetVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHESetVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHESetVisualL, "In TestTHESetVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHESetVisualL );
    // Print to log file 
    iLog->Log( KTestTHESetVisualL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->SetVisual( NULL );
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHEVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHEVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHEVisualL, "In TestTHEVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHEVisualL );
    // Print to log file 
    iLog->Log( KTestTHEVisualL );
    
    TInt temp = 0;
    THuiEvent* event = new(ELeave) THuiEvent( temp );
    CleanupStack::PushL( event );
    
    event->Visual();
    
    CleanupStack::PopAndDestroy( event );
    return KErrNone;
    }

//  [End of File]
