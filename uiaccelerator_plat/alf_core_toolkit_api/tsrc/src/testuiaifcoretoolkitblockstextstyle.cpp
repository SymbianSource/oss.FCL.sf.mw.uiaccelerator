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
#include <uiacceltk/huitextstyle.h>
#include <uiacceltk/huistatic.h>

#include "testuiaifcoretoolkit.h"

//the const variable
const TInt KTextStyle = 2;

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTHuiTextStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTHuiTextStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTHuiTextStyle, "In TestTHuiTextTHuiTextStyle" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTHuiTextStyle );
    // Print to log file
    iLog->Log( KTestTHuiTextTHuiTextStyle );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    THuiTextStyle oneTextStyle ( *textStyle ) ;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTFont
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTFont( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTFont, "In TestTHuiTextTFont" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTFont );
    // Print to log file
    iLog->Log( KTestTHuiTextTFont );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->Font();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTFontConst
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTFontConst( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTFontConst, "In TestTHuiTextTFontConst" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTFontConst );
    // Print to log file
    iLog->Log( KTestTHuiTextTFontConst );

    const THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->Font();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetFont
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetFont( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetFont, "In TestTHuiTextTSetFont" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetFont );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetFont );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    THuiFont huiFont;
    textStyle->SetFont( huiFont );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTParentId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTParentId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTParentId, "In TestTHuiTextTParentId" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTParentId );
    // Print to log file
    iLog->Log( KTestTHuiTextTParentId );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->ParentId();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetParentId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetParentId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetParentId, "In TestTHuiTextTSetParentId" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetParentId );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetParentId );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetParentId( textStyle->ParentId() );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTId( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTId, "In TestTHuiTextTId" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTId );
    // Print to log file
    iLog->Log( KTestTHuiTextTId );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->Id();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTTextColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTTextColor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTTextColor, "In TestTHuiTextTTextColor" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTTextColor );
    // Print to log file
    iLog->Log( KTestTHuiTextTTextColor );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->TextColor();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetTextColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetTextColor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetTextColor, "In TestTHuiTextTSetTextColor" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetTextColor );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetTextColor );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetTextColor( textStyle->TextColor() );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTBackgroundColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTBackgroundColor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTBackgroundColor, "In TestTHuiTextTBackgroundColor" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTBackgroundColor );
    // Print to log file
    iLog->Log( KTestTHuiTextTBackgroundColor );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->BackgroundColor();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetBackgroundColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetBackgroundColor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetBackgroundColor, 
                                         "In TestTHuiTextTSetBackgroundColor" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
                                             KTestTHuiTextTSetBackgroundColor );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetBackgroundColor );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetBackgroundColor( textStyle->BackgroundColor() );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTBackgroundColor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTTextSizeInTwips( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTTextSizeInTwips, "In TestTHuiTextTTextSizeInTwips" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTTextSizeInTwips );
    // Print to log file
    iLog->Log( KTestTHuiTextTTextSizeInTwips );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->TextSizeInTwips();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetTextSizeInTwips
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetTextSizeInTwips( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetTextSizeInTwips, "In TestTHuiTextTSetTextSizeInTwips" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetTextSizeInTwips );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetTextSizeInTwips );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetTextSizeInTwips( KTextStyle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTextSizeInPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTextSizeInPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTextSizeInPixels, "In TestTHuiTextTextSizeInPixels" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTextSizeInPixels );
    // Print to log file
    iLog->Log( KTestTHuiTextTextSizeInPixels );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->TextSizeInPixels();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetTextSizeInPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetTextSizeInPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetTextSizeInPixels, "In TestTHuiTextTSetTextSizeInPixels" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetTextSizeInPixels );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetTextSizeInPixels );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetTextSizeInPixels( KTextStyle );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextStrokeWeight
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextStrokeWeight( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextStrokeWeight, "In TestTHuiTextStrokeWeight" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextStrokeWeight );
    // Print to log file
    iLog->Log( KTestTHuiTextStrokeWeight );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->StrokeWeight();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetStrokeWeight
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetStrokeWeight( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetStrokeWeight, "In TestTHuiTextTSetStrokeWeight" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiTextTSetStrokeWeight );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetStrokeWeight );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetStrokeWeight( ETrue );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTPosture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTPosture( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTPosture, "In TestTHuiTextTPosture" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTPosture );
    // Print to log file
    iLog->Log( KTestTHuiTextTPosture);

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->Posture();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetPosture
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetPosture( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetPosture, "In TestTHuiTextTSetPosture" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetPosture );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetPosture );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetPosture( ETrue );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTUnderline
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTUnderline( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTUnderline, "In TestTHuiTextTUnderline" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTUnderline );
    // Print to log file
    iLog->Log( KTestTHuiTextTUnderline );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->Underline();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetUnderline
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetUnderline( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetUnderline, "In TestTHuiTextTSetUnderline" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetUnderline );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetUnderline );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetUnderline( ETrue );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTStrikeThrough
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTStrikeThrough( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTStrikeThrough, "In TestTHuiTextTStrikeThrough" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTStrikeThrough );
    // Print to log file
    iLog->Log( KTestTHuiTextTStrikeThrough );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->StrikeThrough();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTSetStrikeThrough
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTSetStrikeThrough( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTSetStrikeThrough, "In TestTHuiTextTSetStrikeThrough" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTSetStrikeThrough );
    // Print to log file
    iLog->Log( KTestTHuiTextTSetStrikeThrough );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetStrikeThrough( ETrue );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTFontStyleId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTFontStyleId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTFontStyleId, "In TestTHuiTextTFontStyleId" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTFontStyleId );
    // Print to log file
    iLog->Log( KTestTHuiTextTFontStyleId );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    textStyle->FontStyleId();
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextGetTypeface
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextGetTypeface( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextGetTypeface, "In TestTHuiTextGetTypeface" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextGetTypeface );
    // Print to log file
    iLog->Log( KTestTHuiTextGetTypeface );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    TTypeface typeFace;
    textStyle->GetTypeface( typeFace );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextSetTextPaneHeightInPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextSetTextPaneHeightInPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextSetTextPaneHeightInPixels, 
            "In TestTHuiTextSetTextPaneHeightInPixels" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, 
            KTestTHuiTextSetTextPaneHeightInPixels );
    // Print to log file
    iLog->Log( KTestTHuiTextSetTextPaneHeightInPixels );

    THuiTextStyle* textStyle = 
                    CHuiStatic::Env().TextStyleManager().TextStyle( KTextStyle );
    
    textStyle->SetTextPaneHeightInPixels( KTextStyle );
    
    return KErrNone;
    
    }

//  [End of File]
