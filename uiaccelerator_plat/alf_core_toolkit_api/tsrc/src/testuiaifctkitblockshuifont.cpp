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
#include <uiacceltk/huifont.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    THuiFont* font = new( ELeave ) THuiFont();
    CleanupStack::PushL( font );
    STIF_ASSERT_NOT_NULL( font );
    CleanupStack::PopAndDestroy( font );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFConstructorWithParaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFConstructorWithParaL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFConstructorWithParaL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    TFontSpec spec;
    THuiFont* font = new( ELeave ) THuiFont( 0, spec );
    CleanupStack::PushL( font );
    STIF_ASSERT_NOT_NULL( font );
    CleanupStack::PopAndDestroy( font );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFConstructorWithFontL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFConstructorWithFontL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFConstructorWithFontL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    THuiFont* font = new( ELeave ) THuiFont();
    CleanupStack::PushL( font );
    STIF_ASSERT_NOT_NULL( font );

    THuiFont* testFont = new( ELeave ) THuiFont( *font );
    CleanupStack::PushL( testFont );
    STIF_ASSERT_NOT_NULL( testFont );
    CleanupStack::PopAndDestroy( testFont );

    CleanupStack::PopAndDestroy( font );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFoperatorEqualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFoperatorEqual( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFoperatorEqualL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    THuiFont font;
    THuiFont testFont = font;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFIdL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    TFontSpec spec;
    THuiFont* font = new( ELeave ) THuiFont( 0, spec );
    CleanupStack::PushL( font );
    STIF_ASSERT_NOT_NULL( font );
    TInt id = font->Id();
    STIF_ASSERT_EQUALS( id, 0 );
    CleanupStack::PopAndDestroy( font );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFCategoryL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFCategoryL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFCategoryL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    TFontSpec spec;
    THuiFont* font = new( ELeave ) THuiFont( 0, spec );
    CleanupStack::PushL( font );
    STIF_ASSERT_NOT_NULL( font );
    font->Category();
    CleanupStack::PopAndDestroy( font );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHFFontSpecL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHFFontSpecL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTHuiFont, "In TestTHFFontSpecL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTHuiFont );
    // Print to log file
    iLog->Log( KTHuiFont );

    TFontSpec spec;
    THuiFont* font = new( ELeave ) THuiFont( 0, spec );
    CleanupStack::PushL( font );
    STIF_ASSERT_NOT_NULL( font );
    font->FontSpec();
    CleanupStack::PopAndDestroy( font );

    return KErrNone;
    }
