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
* Description:  for testing the method of the CHuiTextVisual
*
*/


#include <uiacceltk\huitextvisual.h>

#include "testuiaifcoretoolkit.h"

const TInt KMaxLineCount = 10; 
const TInt KMajor = 10;
const TInt KMinor = 0;
const TInt KStart = 0;
const TInt KEnd = 5;

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualAddNewL, "In TestHuiTextVisualAddNewL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualAddNewL );
    // Print to log file
    iLog->Log( KTestHuiTextVisualAddNewL );
    
    TRAPD( error, iHuiTextVisual = iHuiTextVisual->AddNewL( *iHuiControl ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetTextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetTextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetTextL, "In TestHuiTextVisualSetTextL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetTextL );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetTextL );
    
    TRAPD( error, iHuiTextVisual->SetTextL( _L("testtextvisual") ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualText
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualText( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualText, "In TestHuiTextVisualText" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualText );
    // Print to log file
    iLog->Log( KTestHuiTextVisualText );
    
    iHuiTextVisual->Text();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetAlign
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetAlign( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetAlign, "In TestHuiTextVisualSetAlign" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetAlign );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetAlign );
    
    iHuiTextVisual->SetAlign( EHuiAlignHCenter, EHuiAlignVCenter );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetLineSpacing
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetLineSpacing( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetLineSpacing, "In TestHuiTextVisualSetLineSpacing" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetLineSpacing );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetLineSpacing );
    
    iHuiTextVisual->SetLineSpacing( 0 );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetStyle, "In TestHuiTextVisualSetStyle" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetStyle );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetStyle );
    
    iHuiTextVisual->SetStyle( EHuiTextStyleNormal );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetTextStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetTextStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetTextStyle, "In TestHuiTextVisualSetTextStyle" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetTextStyle );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetTextStyle );
    
    iHuiTextVisual->SetTextStyle( 0 );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualStyle, "In TestHuiTextVisualStyle" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualStyle );
    // Print to log file
    iLog->Log( KTestHuiTextVisualStyle );
    
    iHuiTextVisual->Style();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualTextStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualTextStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualTextStyle, "In TestHuiTextVisualTextStyle" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualTextStyle );
    // Print to log file
    iLog->Log( KTestHuiTextVisualTextStyle );
    
    iHuiTextVisual->TextStyle();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetMaxLineCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetMaxLineCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetMaxLineCount, "In TestHuiTextVisualSetMaxLineCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetMaxLineCount );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetMaxLineCount );
    
    iHuiTextVisual->SetMaxLineCount( KMaxLineCount );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualMaxLineCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualMaxLineCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualMaxLineCount, "In TestHuiTextVisualMaxLineCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualMaxLineCount );
    // Print to log file
    iLog->Log( KTestHuiTextVisualMaxLineCount );
    
    TInt lineCount = iHuiTextVisual->MaxLineCount();
    
    STIF_ASSERT_EQUALS( lineCount, KMaxLineCount );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualWrapping
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualWrapping( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualWrapping, "In TestHuiTextVisualWrapping" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualWrapping );
    // Print to log file
    iLog->Log( KTestHuiTextVisualWrapping );
    
    iHuiTextVisual->Wrapping();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetWrapping
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetWrapping( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetWrapping, "In TestHuiTextVisualSetWrapping" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetWrapping );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetWrapping );
    
    iHuiTextVisual->SetWrapping( CHuiTextVisual::ELineWrapManual );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualBackgroundType
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualBackgroundType( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualBackgroundType, "In TestHuiTextVisualBackgroundType" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualBackgroundType );
    // Print to log file
    iLog->Log( KTestHuiTextVisualBackgroundType );
    
    iHuiTextVisual->BackgroundType();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualOffset
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualOffset( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualOffset, "In TestHuiTextVisualOffset" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualOffset );
    // Print to log file
    iLog->Log( KTestHuiTextVisualOffset );
    
    iHuiTextVisual->Offset();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualOffsetConst
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualOffsetConst( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualOffsetConst, "In TestHuiTextVisualOffsetConst" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualOffsetConst );
    // Print to log file
    iLog->Log( KTestHuiTextVisualOffsetConst );
    
    const_cast<const CHuiTextVisual*>( iHuiTextVisual )->Offset();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualTextExtents
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualTextExtentsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualTextExtents, "In TestHuiTextVisualTextExtents" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualTextExtents );
    // Print to log file
    iLog->Log( KTestHuiTextVisualTextExtents );
    
    iHuiTextVisual->SetTextL(_L("Testing..."));
    TSize extents = iHuiTextVisual->TextExtents();

    STIF_ASSERT_TRUE( extents.iWidth > 0 );
    STIF_ASSERT_TRUE( extents.iHeight > 0 );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualPrepareDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualPrepareDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualPrepareDrawL, "In TestHuiTextVisualPrepareDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualPrepareDrawL );
    // Print to log file
    iLog->Log( KTestHuiTextVisualPrepareDrawL );
    
    TBool flag = iHuiTextVisual->PrepareDrawL();
    
    STIF_ASSERT_TRUE( flag );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetColor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetColor, "In TestHuiTextVisualSetColor" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetColor );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetColor );
    
    TRgb color( 0, 0, 0 );
    
    iHuiTextVisual->SetColor( color );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetColorWithIndex
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetColorWithIndex( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetColorWithIndex, "In TestHuiTextVisualSetColorWithIndex" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetColorWithIndex );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetColorWithIndex );
    
    TAknsItemID id;
    id.Set( KMajor, KMinor );
    
    iHuiTextVisual->SetColor( id, 0 );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSubstringExtents
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSubstringExtents( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSubstringExtents, "In TestHuiTextVisualSubstringExtents" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSubstringExtents );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSubstringExtents );
    
    iHuiTextVisual->SubstringExtents( KStart, KEnd );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualEnableShadow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualEnableShadow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualEnableShadow, "In TestHuiTextVisualEnableShadow" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualEnableShadow );
    // Print to log file
    iLog->Log( KTestHuiTextVisualEnableShadow );
    
    iHuiTextVisual->EnableShadow( ETrue );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTextVisualSetHighlightRange
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTextVisualSetHighlightRange( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTextVisualSetHighlightRange, "In TestHuiTextVisualSetHighlightRange" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTextVisualSetHighlightRange );
    // Print to log file
    iLog->Log( KTestHuiTextVisualSetHighlightRange );
    
    TRgb lightColor( 0, 0, 0 );
    TRgb textColor( 0, 0, 0 );
    
    iHuiTextVisual->SetHighlightRange( KStart, KEnd, lightColor, textColor );

    return KErrNone;

    }
// End of files
