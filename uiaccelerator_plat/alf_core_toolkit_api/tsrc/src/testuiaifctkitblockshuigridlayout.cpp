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

#include <uiacceltk\huigridlayout.h>
#include <alf\alfgridlayout.h>
#include <uiacceltk\huiskin.h>

#include "testuiaifcoretoolkit.h"

const TInt KRow = 20;
const TInt KColumn = 20;
const TInt KWidth = 10;
const TInt KLength = 20;
const TInt KChildIndex = 5;
const TInt KPointX = 10;
const TInt KPointY = 20;
const TInt KCount = 10;
const TInt KPosition = 0;
const TInt KBufLength = 50;
const TInt KSessionId = 0x2001CB80;

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutAddNewL, "In TestHuiGridLayoutAddNewL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutAddNewL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutAddNewL );
    
    TRAPD( error, iHuiGridLayout = iHuiGridLayout->AddNewL( *iHuiControl, KRow, KColumn ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutConstructor, "In TestHuiGridLayoutConstructor" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutConstructor );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutConstructor );
    
    TRAPD( error, iHuiGridLayout = new( ELeave ) CHuiGridLayout( *iHuiControl ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutConstructL, "In TestHuiGridLayoutConstructL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutConstructL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutConstructL );
    
    TRAPD( error, iHuiGridLayout->ConstructL() );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutDelete
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutDelete( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutDelete, "In TestHuiGridLayoutDelete" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutDelete );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutDelete );
    
    delete iHuiGridLayout;
    iHuiGridLayout = NULL;

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetSize, "In TestHuiGridLayoutSetSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetSize );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetSize );
    
    TSize size( KWidth, KLength );
    THuiRealSize huiRelSize( size );
    
    iHuiGridLayout->SetSize( huiRelSize );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutChildOrdinal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutChildOrdinalL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutChildOrdinal, "In TestHuiGridLayoutChildOrdinal" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutChildOrdinal );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutChildOrdinal );

    iHuiVisual = new( ELeave ) CHuiVisual( *iHuiControl );
    
    iHuiGridLayout->AppendL( iHuiVisual );
    
    iHuiGridLayout->ChildOrdinal( 0 );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutChildPos
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutChildPos( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutChildPos, "In TestHuiGridLayoutChildPos" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutChildPos );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutChildPos );
    
    TPoint childpos;
    
    iHuiGridLayout->ChildPos( KChildIndex, childpos );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutChildSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutChildSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutChildSize, "In TestHuiGridLayoutChildSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutChildSize );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutChildSize );
    
    TSize size;
    
    iHuiGridLayout->ChildSize( KChildIndex, size );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutChildRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutChildRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutChildRect, "In TestHuiGridLayoutChildRect" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutChildRect );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutChildRect );
    
    THuiRealRect rect;
    
    iHuiGridLayout->ChildRect( KChildIndex, rect );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutBaseUnit
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutBaseUnit( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutBaseUnit, "In TestHuiGridLayoutBaseUnit" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutBaseUnit );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutBaseUnit );
    
    iHuiGridLayout->BaseUnit();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutRemoveAndDestroyAllD
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutRemoveAndDestroyAllD( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutRemoveAndDestroyAllD, "In TestHuiGridLayoutRemoveAndDestroyAllD" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutRemoveAndDestroyAllD );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutRemoveAndDestroyAllD );
    
    iHuiGridLayout->RemoveAndDestroyAllD();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutFindTag
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutFindTagL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutFindTag, "In TestHuiGridLayoutFindTag" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutFindTag );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutFindTag );
    
    iHuiVisual = new( ELeave ) CHuiVisual( *iHuiControl );
    
    iHuiGridLayout->AppendL( iHuiVisual );
    
    iHuiVisual->SetTagL( _L8( "huidisplaystring" ) );
    
    CHuiVisual* visual = iHuiGridLayout->FindTag( _L8("huidisplaystring") );
    
    STIF_ASSERT_NOT_NULL( visual );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutCount, "In TestHuiGridLayoutCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutCount );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutCount );
    
    iHuiGridLayout->Count();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutVisual
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutVisual, "In TestHuiGridLayoutVisual" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutVisual );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutVisual );

    iHuiVisual = new( ELeave ) CHuiVisual( *iHuiControl );
    
    iHuiGridLayout->AppendL( iHuiVisual );
    
    CHuiVisual* visual = &( iHuiGridLayout->Visual( 0 ) );
    
    STIF_ASSERT_NOT_NULL( visual );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetPos
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetPos( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetPos, "In TestHuiGridLayoutSetPos" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetPos );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetPos );
    
    THuiRealPoint point( KPointX, KPointY );
    
    iHuiGridLayout->SetPos( point );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutUpdateChildrenLayout
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutUpdateChildrenLayout( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutUpdateChildrenLayout, "In TestHuiGridLayoutUpdateChildrenLayout" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutUpdateChildrenLayout );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutUpdateChildrenLayout );
    
    iHuiGridLayout->UpdateChildrenLayout();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutPrepareDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutPrepareDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutPrepareDrawL, "In TestHuiGridLayoutPrepareDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutPrepareDrawL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutPrepareDrawL );
    
    iHuiGridLayout->PrepareDrawL();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutDraw
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutDraw, "In TestHuiGridLayoutDraw" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutDraw );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutDraw );

    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();

    iHuiGridLayout->Draw( gc );
    
    CleanupStack::PopAndDestroy( ctrl );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutDrawSelf
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutDrawSelfL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutDrawSelf, "In TestHuiGridLayoutDrawSelf" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutDrawSelf );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutDrawSelf );
    
    const TRect KDisplayRect( 0,0,100,100 );

    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();

    iHuiGridLayout->DrawSelf( gc, KDisplayRect );
    
    CleanupStack::PopAndDestroy( ctrl );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutChanged, "In TestHuiGridLayoutChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutChanged );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutChanged );
    
    iHuiGridLayout->Changed();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutReportChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutReportChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutReportChanged, "In TestHuiGridLayoutReportChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutReportChanged );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutReportChanged );
    
    iHuiGridLayout->ReportChanged();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutClearChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutClearChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutClearChanged, "In TestHuiGridLayoutClearChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutClearChanged );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutClearChanged );
    
    iHuiGridLayout->ClearChanged();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutNotifySkinChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutNotifySkinChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutNotifySkinChangedL, "In TestHuiGridLayoutNotifySkinChangedL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutNotifySkinChangedL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutNotifySkinChangedL );
    
    iHuiGridLayout->NotifySkinChangedL();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutExpandRectWithContent
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutExpandRectWithContent( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutExpandRectWithContent, "In TestHuiGridLayoutExpandRectWithContent" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutExpandRectWithContent );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutExpandRectWithContent );
    
    TRect rect( TPoint( 0, 0 ), TPoint( KWidth, KLength ) );
    
    iHuiGridLayout->ExpandRectWithContent( rect );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutVisualExtension
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutVisualExtension( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutVisualExtension, "In TestHuiGridLayoutVisualExtension" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutVisualExtension );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutVisualExtension );
    
    TUid uid = TUid::Null();
    
    TAny** any = NULL;
    
    iHuiGridLayout->VisualExtension( uid, any );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetColumnsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetColumnsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetColumnsL, "In TestHuiGridLayoutSetColumnsL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetColumnsL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetColumnsL );
    
    iHuiGridLayout->SetColumnsL( KColumn );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetRowsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetRowsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetRowsL, "In TestHuiGridLayoutSetRowsL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetRowsL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetRowsL );
    
    iHuiGridLayout->SetRowsL( KRow );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetColumnsLWithArray
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetColumnsLWithArray( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetColumnsLWithArray, "In TestHuiGridLayoutSetColumnsLWithArray" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetColumnsLWithArray );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetColumnsLWithArray );
    
    RArray<TInt> weight;
    weight.Append( KWidth );
    weight.Append( KLength );
    
    TRAPD( error, iHuiGridLayout->SetColumnsL( weight ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetRowsLWithArray
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetRowsLWithArray( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetRowsLWithArray, "In TestHuiGridLayoutSetRowsLWithArray" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetRowsLWithArray );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetRowsLWithArray );
    
    RArray<TInt> weight;
    weight.Append( KWidth );
    weight.Append( KLength );
    
    TRAPD( error, iHuiGridLayout->SetRowsL( weight ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutFillWeightsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutFillWeightsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutFillWeightsL, "In TestHuiGridLayoutFillWeightsL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutFillWeightsL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutFillWeightsL );
    
    THuiMetric x( KLength );
    
    iHuiGridLayout->FillWeightsL( EHuiGridColumn, KCount, x );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutAppendWeightL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutAppendWeightL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutAppendWeightL, "In TestHuiGridLayoutAppendWeightL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutAppendWeightL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutAppendWeightL );
    
    THuiMetric x( KLength );
    
    iHuiGridLayout->AppendWeightL( EHuiGridColumn, x );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutInsertWeightL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutInsertWeightL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutInsertWeightL, "In TestHuiGridLayoutInsertWeightL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutInsertWeightL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutInsertWeightL );
    
    THuiMetric x( KLength );
    
    iHuiGridLayout->InsertWeightL( EHuiGridColumn, x, KPosition );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutReplaceWeightL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutReplaceWeightL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutReplaceWeightL, "In TestHuiGridLayoutReplaceWeightL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutReplaceWeightL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutReplaceWeightL );
    
    THuiMetric x( KWidth );
    
    iHuiGridLayout->ReplaceWeightL( EHuiGridColumn, x, KPosition );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutRemoveWeightL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutRemoveWeightL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutRemoveWeightL, "In TestHuiGridLayoutRemoveWeightL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutRemoveWeightL );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutRemoveWeightL );
    
    iHuiGridLayout->RemoveWeightL( EHuiGridColumn, KPosition );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutWeight
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutWeight( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutWeight, "In TestHuiGridLayoutWeight" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutWeight );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutWeight );
    
    iHuiGridLayout->Weight( EHuiGridColumn, KPosition );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutDimensionCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutDimensionCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutDimensionCount, "In TestHuiGridLayoutDimensionCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutDimensionCount );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutDimensionCount );
    
    iHuiGridLayout->DimensionCount( EHuiGridColumn );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetExpanding
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetExpanding( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetExpanding, "In TestHuiGridLayoutSetExpanding" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetExpanding );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetExpanding );
    
    iHuiGridLayout->SetExpanding( CHuiLayout::EExpandHorizontally );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutRowCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutRowCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutRowCount, "In TestHuiGridLayoutRowCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutRowCount );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutRowCount );
    
    iHuiGridLayout->RowCount();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutColumnCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutColumnCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutColumnCount, "In TestHuiGridLayoutColumnCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutColumnCount );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutColumnCount );
    
    iHuiGridLayout->ColumnCount();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutOrdinalToBlock
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutOrdinalToBlock( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutOrdinalToBlock, "In TestHuiGridLayoutOrdinalToBlock" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutOrdinalToBlock );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutOrdinalToBlock );
    
    iHuiGridLayout->OrdinalToBlock( KChildIndex );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetLayoutModeFlags
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetLayoutModeFlags( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetLayoutModeFlags, "In TestHuiGridLayoutSetLayoutModeFlags" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetLayoutModeFlags );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetLayoutModeFlags );
    
    iHuiGridLayout->SetLayoutModeFlags( EHuiGridColumn, EAlfGridIncreaseInnerPadding );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutClearLayoutModeFlags
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutClearLayoutModeFlags( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutClearLayoutModeFlags, "In TestHuiGridLayoutClearLayoutModeFlags" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutClearLayoutModeFlags );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutClearLayoutModeFlags );
    
    iHuiGridLayout->ClearLayoutModeFlags( EHuiGridColumn, EAlfGridIncreaseInnerPadding );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutLayoutModeFlags
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutLayoutModeFlags( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutLayoutModeFlags, "In TestHuiGridLayoutLayoutModeFlags" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutLayoutModeFlags );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutLayoutModeFlags );
    
    iHuiGridLayout->LayoutModeFlags( EHuiGridColumn );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutGetClassName
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutGetClassName( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutGetClassName, "In TestHuiGridLayoutGetClassName" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutGetClassName );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutGetClassName );
    
    TBuf<KBufLength> className;
    
    iHuiGridLayout->GetClassName( className );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutDumpTree
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutDumpTree( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutDumpTree, "In TestHuiGridLayoutDumpTree" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutDumpTree );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutDumpTree );
    
    iHuiGridLayout->DumpTree();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutGetInstanceName
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutGetInstanceNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutGetInstanceName, "In TestHuiGridLayoutGetInstanceName" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutGetInstanceName );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutGetInstanceName );

    iHuiVisual = new( ELeave ) CHuiVisual( *iHuiControl );
    
    iHuiGridLayout->AppendL( iHuiVisual );
    
    _LIT( KInstanceName, "instancename" );
    
    TBuf<KBufLength> instanceName( KInstanceName );
    
    iHuiGridLayout->GetInstanceName( instanceName );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutType
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutType( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutType, "In TestHuiGridLayoutType" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutType );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutType );
    
    iHuiGridLayout->Type();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSessionId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSessionId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSessionId, "In TestHuiGridLayoutSessionId" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSessionId );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSessionId );
    
    iHuiGridLayout->SessionId();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiGridLayoutSetSessionId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiGridLayoutSetSessionId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiGridLayoutSetSessionId, "In TestHuiGridLayoutSetSessionId" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiGridLayoutSetSessionId );
    // Print to log file
    iLog->Log( KTestHuiGridLayoutSetSessionId );
    
    iHuiGridLayout->SetSessionId( KSessionId );

    return KErrNone;

    }

// End of file
