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
#include <uiacceltk/huidisplaybackgrounditem.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundItemL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundItemL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiDisplayBackgroundItemL, "In TestTTHuiDisplayBackgroundItemL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTTHuiDisplayBackgroundItemL );
    // Print to log file 
    iLog->Log( KTestTTHuiDisplayBackgroundItemL );
    
    THuiDisplayBackgroundItem* displayItem = 
                                     new ( ELeave ) THuiDisplayBackgroundItem();
    
    delete displayItem;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundItemRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundItemRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiDisplayBackgroundItemRectL, 
            "In TestTTHuiDisplayBackgroundItemRectL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiDisplayBackgroundItemRectL );
    // Print to log file 
    iLog->Log( KTestTTHuiDisplayBackgroundItemRectL );
    
    TRect rect( 0, 10, 0, 20);
    THuiDisplayBackgroundItem* displayItem = 
                               new ( ELeave ) THuiDisplayBackgroundItem( rect );
    
    delete displayItem;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundItemItemIDL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundItemItemIDL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiDisplayBackgroundItemItemIDL, 
            "In TestTTHuiDisplayBackgroundItemItemIDL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiDisplayBackgroundItemItemIDL );
    // Print to log file 
    iLog->Log( KTestTTHuiDisplayBackgroundItemItemIDL );
    
    TRect rect( 0, 10, 0, 20);
    TAknsItemID itemID = KAknsIIDQsnBgScreen;
    THuiDisplayBackgroundItem* displayItem = 
                        new ( ELeave ) THuiDisplayBackgroundItem( rect, itemID );
    
    delete displayItem;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiDisplayBackgroundColorL, 
            "In TestTTHuiDisplayBackgroundColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiDisplayBackgroundColorL );
    // Print to log file 
    iLog->Log( KTestTTHuiDisplayBackgroundColorL );
    
    TRect rect( 0, 10, 0, 20);
    TAknsItemID itemID = KAknsIIDQsnBgScreen;
    TInt color = 1;
    THuiDisplayBackgroundItem* displayItem = 
                 new ( ELeave ) THuiDisplayBackgroundItem( rect, itemID, color );
    
    delete displayItem;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundTRgbL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiDisplayBackgroundTRgbL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiDisplayBackgroundTRgbL, 
            "In TestTTHuiDisplayBackgroundTRgbL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTTHuiDisplayBackgroundTRgbL );
    // Print to log file 
    iLog->Log( KTestTTHuiDisplayBackgroundTRgbL );
    
    TRect rect( 0, 10, 0, 20);
    TRgb color;
    THuiDisplayBackgroundItem* displayItem = 
                 new ( ELeave ) THuiDisplayBackgroundItem( rect, color );
    
    delete displayItem;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiTestTSetRectLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiTestTSetRectLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiTestTSetRectLL, "In TestTTHuiTestTSetRectLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTTHuiTestTSetRectLL );
    // Print to log file 
    iLog->Log( KTestTTHuiTestTSetRectLL );
    
    THuiDisplayBackgroundItem* displayItem = 
                                      new ( ELeave ) THuiDisplayBackgroundItem();
    CleanupStack::PushL( displayItem );
    TRect rect;
    displayItem->SetRect( rect );
    
    CleanupStack::PopAndDestroy( displayItem );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiSetColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiSetColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiSetColorL, "In TestTTHuiSetColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTTHuiSetColorL );
    // Print to log file 
    iLog->Log( KTestTTHuiSetColorL );
    
    THuiDisplayBackgroundItem* displayItem = 
                                      new ( ELeave ) THuiDisplayBackgroundItem();
    CleanupStack::PushL( displayItem );
    TRgb color;
    displayItem->SetColor( color );
    
    CleanupStack::PopAndDestroy( displayItem );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiSetColorItemL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiSetColorItemL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiSetColorItemL, "In TestTTHuiSetColorItemL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTTHuiSetColorItemL );
    // Print to log file 
    iLog->Log( KTestTTHuiSetColorItemL );
    
    THuiDisplayBackgroundItem* displayItem = 
                                      new ( ELeave ) THuiDisplayBackgroundItem();
    CleanupStack::PushL( displayItem );
    
    TAknsItemID itemID = KAknsIIDQsnBgScreen;
    
    displayItem->SetColor( itemID, 1 );
    
    CleanupStack::PopAndDestroy( displayItem );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTTHuiSetSkinBackgroundL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTTHuiSetSkinBackgroundL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTTHuiSetSkinBackgroundL, "In TestTTHuiSetSkinBackgroundL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,KTestTTHuiSetSkinBackgroundL );
    // Print to log file 
    iLog->Log( KTestTTHuiSetSkinBackgroundL );
    
    THuiDisplayBackgroundItem* displayItem = 
                                      new ( ELeave ) THuiDisplayBackgroundItem();
    CleanupStack::PushL( displayItem );
    
    TAknsItemID itemID = KAknsIIDQsnBgScreen;
    
    displayItem->SetSkinBackground( itemID );
    
    CleanupStack::PopAndDestroy( displayItem );
    
    return KErrNone;
    
    }

//  [End of File]
