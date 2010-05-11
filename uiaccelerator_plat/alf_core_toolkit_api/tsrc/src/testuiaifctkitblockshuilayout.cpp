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
#include <uiacceltk/huilayout.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huigc.h>
#include <uiacceltk/huiskin.h>
#include <uiacceltk/huistatic.h>

#include "testuiaifcoretoolkit.h"

_LIT( KName, "instance" );

class CHuiLayoutExt : public CHuiLayout
    {
friend class CTestUiAifCoreToolkit;
    
public:
    CHuiLayoutExt( MHuiVisualOwner& aOwner ) : CHuiLayout( aOwner )
    {
    }

    };

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutAddNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = new( ELeave ) CHuiLayout( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutDestructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutDestructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutDestructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = new( ELeave ) CHuiLayout( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutConstructL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = new( ELeave ) CHuiLayout( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->ConstructL();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutRemoveAndDestroyAllDL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutRemoveAndDestroyAllDL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutRemoveAndDestroyAllDL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->RemoveAndDestroyAllD();
    layout = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutFindTagL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutFindTagL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutFindTagL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    CHuiVisual* visual = layout->FindTag( _L8( "CannotFindVisual" ) );
    STIF_ASSERT_NULL( visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutAppendL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutAppendL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutAppendL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutInsertL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutInsertL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutInsertL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->InsertL( visual, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutRemoveL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutRemoveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutRemoveL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->Remove( visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutCountL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    TInt num = layout->Count();
    STIF_ASSERT_EQUALS( num, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutRemoveL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->Visual( 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutFindVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutFindVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutFindVisualL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TInt num = layout->FindVisual( visual );
    STIF_ASSERT_NOT_EQUALS( num, KErrNotFound );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetPosL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetPosL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetPosL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    THuiRealPoint pos( 0, 0 );
    layout->SetPos( pos );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    THuiRealSize size( 0, 0 );
    layout->SetSize( size );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutUpdateChildrenLayoutL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutUpdateChildrenLayoutL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutUpdateChildrenLayoutL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    layout->UpdateChildrenLayout();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutUpdateChildLayoutL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutUpdateChildLayoutL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutUpdateChildLayoutL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->UpdateChildLayout( 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetInnerPaddingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetInnerPaddingL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetInnerPaddingL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    const TPoint KInnerPadding1(8, 3);
    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->SetInnerPadding( KInnerPadding1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetInnerPaddingWithMetricL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetInnerPaddingWithMetricL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetInnerPaddingWithMetricL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    THuiXYMetric metric( 1, 1 );
    layout->SetInnerPadding( metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutInnerPaddingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutInnerPaddingL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutInnerPaddingL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    THuiXYMetric metric( 1, 1 );
    layout->SetInnerPadding( metric );
    THuiXYMetric getMetric = layout->InnerPadding();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutHorizontalInnerPaddingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutHorizontalInnerPaddingL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutHorizontalInnerPaddingL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    THuiXYMetric metric( 1, 1 );
    layout->SetInnerPadding( metric );
    TInt horizontal = layout->HorizontalInnerPadding();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutVerticalInnerPaddingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutVerticalInnerPaddingL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutVerticalInnerPaddingL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    TInt vertical = layout->VerticalInnerPadding();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutInnerPaddingInBaseUnitsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutInnerPaddingInBaseUnitsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutInnerPaddingInBaseUnitsL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->InnerPaddingInBaseUnits();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutEnableScrollingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutEnableScrollingL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutEnableScrollingL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->EnableScrollingL();
    layout->EnableScrollingL( EFalse );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutScrollingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutScrollingL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutScrollingL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->EnableScrollingL();
    TBool isEnable = layout->Scrolling();
    STIF_ASSERT_TRUE( isEnable );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutScrollOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutScrollOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutScrollOffsetL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->EnableScrollingL();
    THuiTimedPoint point = layout->ScrollOffset();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutScrollOffsetWithconstL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutScrollOffsetWithconstL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutScrollOffsetWithconstL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->EnableScrollingL();
    const THuiTimedPoint point = const_cast< const CHuiLayout* > ( layout )->ScrollOffset();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetScrollOffsetInBaseUnitsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetScrollOffsetInBaseUnitsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetScrollOffsetInBaseUnitsL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    TPoint pos;
    TSize size;
    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    CHuiVisual* child = CHuiVisual::AddNewL(*iHuiControl, layout);

    const TSize KChildSize( 50, 89 );
    const THuiRealPoint KChildPosition( 5.0, 12.0 );
    const TReal32 KPositiveHorizontalScroll = 13.6;
    const TReal32 KNegativeHorizontalScroll = -9.4;
    const TReal32 KPositiveVerticalScroll = 5.5;
    const TReal32 KNegativeVerticalScroll = -2.3;

    // Position child manually
    child->SetFlag( EHuiVisualFlagManualLayout );
    child->SetPos( KChildPosition );
    child->SetSize( KChildSize );   
    
    // Enable scrolling
    // Note: Since scrolling is applied directly to child visual display rectangles
    // we don't have to call UpdateLayoutChildren to apply changes. For the same
    // reason we have to retrieve the modified coordinates using LocalToDisplay() method
    // of individual child visuals.
    layout->EnableScrollingL( ETrue );
    
    // Positive horizontal scroll offset
    layout->SetScrollOffsetInBaseUnits( THuiRealPoint( KPositiveHorizontalScroll, 0 ) );
    pos = child->LocalToDisplay( child->Pos().Target() );
    size = child->Size().Target().AsSize();
    STIF_ASSERT_EQUALS( ( TInt )( KChildPosition.iX - KPositiveHorizontalScroll ), pos.iX );
    STIF_ASSERT_TRUE( KChildPosition.iY == pos.iY );
    STIF_ASSERT_TRUE( size.iWidth == KChildSize.iWidth );
    STIF_ASSERT_TRUE( size.iHeight == KChildSize.iHeight );

    // Negative horizontal scroll offset
    layout->SetScrollOffsetInBaseUnits( THuiRealPoint( KNegativeHorizontalScroll, 0 ) );
    pos = child->LocalToDisplay( child->Pos().Target() );
    size = child->Size().Target().AsSize();
    STIF_ASSERT_EQUALS( ( TInt )( KChildPosition.iX - KNegativeHorizontalScroll ), pos.iX );
    STIF_ASSERT_TRUE( KChildPosition.iY == pos.iY );
    STIF_ASSERT_TRUE( size.iWidth == KChildSize.iWidth );
    STIF_ASSERT_TRUE( size.iHeight == KChildSize.iHeight );
    
    // Positive vertical scroll offset
    layout->SetScrollOffsetInBaseUnits( THuiRealPoint( 0, KPositiveVerticalScroll ) );
    pos = child->LocalToDisplay( child->Pos().Target() );
    size = child->Size().Target().AsSize();
    STIF_ASSERT_TRUE( KChildPosition.iX == pos.iX );
    STIF_ASSERT_EQUALS( (TInt)(KChildPosition.iY - KPositiveVerticalScroll ), pos.iY );
    STIF_ASSERT_TRUE( size.iWidth == KChildSize.iWidth );
    STIF_ASSERT_TRUE( size.iHeight == KChildSize.iHeight );
    
    // Negative vertical scroll offset
    layout->SetScrollOffsetInBaseUnits( THuiRealPoint( 0, KNegativeVerticalScroll ) );
    pos = child->LocalToDisplay( child->Pos().Target() );
    size = child->Size().Target().AsSize();
    STIF_ASSERT_TRUE( KChildPosition.iX == pos.iX );
    STIF_ASSERT_EQUALS( (TInt )( KChildPosition.iY - KNegativeVerticalScroll ), pos.iY );
    STIF_ASSERT_TRUE( size.iWidth == KChildSize.iWidth );
    STIF_ASSERT_TRUE( size.iHeight == KChildSize.iHeight );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutVirtualSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutVirtualSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutVirtualSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->EnableScrollingL();
    layout->VirtualSize();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutEffectiveLayoutOrdinalL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutEffectiveLayoutOrdinalL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutEffectiveLayoutOrdinalL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->EffectiveLayoutOrdinal( *visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutReorderL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutReorderL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutReorderL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->Reorder( *visual, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutMoveVisualToFrontL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutMoveVisualToFrontL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutMoveVisualToFrontL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->MoveVisualToFront( *visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutMoveVisualToBackL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutMoveVisualToBackL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutMoveVisualToBackL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->MoveVisualToBack( *visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutNotifySkinChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutNotifySkinChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutNotifySkinChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->NotifySkinChangedL();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetTransitionTimeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetTransitionTimeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetTransitionTimeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->SetTransitionTime( 10 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutTransitionTimeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutTransitionTimeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutTransitionTimeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->SetTransitionTime( 10 );
    TInt time = layout->TransitionTime();
    STIF_ASSERT_EQUALS( time, 10 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutChildOrdinalL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutChildOrdinalL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutChildOrdinalL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TInt index = layout->ChildOrdinal( 0 );
    STIF_ASSERT_EQUALS( index, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutPrepareDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutPrepareDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutPrepareDrawL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->PrepareDrawL();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutDrawL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc* gc = &iHuiEnv->Skin().Context();
    layout->Draw( *gc );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutReportChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutReportChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutReportChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->ReportChanged();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutClearChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->ClearChanged();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->Changed();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutDumpTreeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutDumpTreeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutDumpTreeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->DumpTree();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetBaseUnitL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetBaseUnitL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetBaseUnitL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    THuiMetric metric( 1 );
    layout->SetBaseUnit( metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetBaseUnitXYL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetBaseUnitXYL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetBaseUnitXYL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    THuiXYMetric metric( 1, 1 );
    layout->SetBaseUnit( metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutBaseUnitL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutBaseUnitL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutBaseUnitL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    THuiXYMetric metric( 1, 1 );
    layout->SetBaseUnit( metric );
    layout->BaseUnit();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutInnerSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutInnerSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutInnerSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->InnerSize();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutInnerTopLeftL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutInnerTopLeftL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutInnerTopLeftL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->InnerTopLeft();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutChildSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutChildSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutChildSizeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TSize size( 1, 1 );
    layout->ChildSize( 0, size );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutChildPosL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutChildPosL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutChildPosL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TPoint point( 1, 1 );
    layout->ChildPos( 0, point );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutChildRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutChildRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutChildRectL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    layout->ChildRect( 0, realRect );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutBrushOpacityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutBrushOpacityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutBrushOpacityL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->BrushOpacity();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutBrushRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutBrushRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutBrushRectL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->BrushRect();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutBrushSkinL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutBrushSkinL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutBrushSkinL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->BrushSkin();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutGetInstanceNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutGetInstanceNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutGetInstanceNameL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TBuf<20> txt( KName );
    layout->GetInstanceName( txt );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutGetClassNameL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutGetClassNameL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutGetClassNameL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    TBuf<20> txt( KName );
    layout->GetClassName( txt );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutTypeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    CHuiLayout::TType type= layout->Type();
    STIF_ASSERT_EQUALS( type, CHuiLayout::ETypeVisual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSessionIdL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->SessionId();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutSetSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutSetSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutSetSessionIdL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );

    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiControl );
    layout->AppendL( visual );
    layout->SetSessionId( 1 );
    TInt id = layout->SessionId();
    STIF_ASSERT_EQUALS( id, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutDrawSelfL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutDrawSelfL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutDrawSelfL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayoutExt* layout = new( ELeave ) CHuiLayoutExt( *iHuiControl );
    layout->ConstructL();
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc* gc = &iHuiEnv->Skin().Context();
    TRect rect( 1, 1, 1, 1 );
    layout->DrawSelf( *gc, rect );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHLMetricReferenceForLayoutInPixelsWithLayoutL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHLMetricReferenceForLayoutInPixelsWithLayoutL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestHLMetricReferenceForLayoutInPixelsWithLayoutL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayoutExt* layout = new( ELeave ) CHuiLayoutExt( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->ConstructL();
    THuiXYMetric metric( 1, 1 );
    layout->MetricReferenceForLayoutInPixels( layout, metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHLMetricReferenceForLayoutInPixelsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHLMetricReferenceForLayoutInPixelsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestHLMetricReferenceForLayoutInPixelsL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayoutExt* layout = new( ELeave ) CHuiLayoutExt( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->ConstructL();
    THuiXYMetric metric( 1, 1 );
    layout->MetricReferenceForLayoutInPixels( metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutExpandRectWithContentL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutExpandRectWithContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutExpandRectWithContentL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayoutExt* layout = new( ELeave ) CHuiLayoutExt( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->ConstructL();
    TRect rect( 0, 0, 1, 1 );
    layout->ExpandRectWithContent( rect );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiLayoutVisualExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiLayoutVisualExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiLayout, "In TestCHuiLayoutVisualExtensionL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiLayout );
    // Print to log file
    iLog->Log( KTestCHuiLayout );

    CHuiLayoutExt* layout = new( ELeave ) CHuiLayoutExt( *iHuiControl );
    STIF_ASSERT_NOT_NULL( layout );
    layout->ConstructL();
    TUid uid = TUid::Null();
    TAny** any = NULL;
    layout->VisualExtension( uid, any );

    return KErrNone;
    }
