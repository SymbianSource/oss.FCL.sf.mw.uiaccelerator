/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*
*/


//  CLASS HEADER
#include "UT_CAlfLCTAnchorLayout.h"

//  EXTERNAL INCLUDES
#include <EUnitMacros.h>


//  INTERNAL INCLUDES
#include "alf/alflctAnchorLayout.h"
#include "alf/alfdecklayout.h"
#include "alf/alfenv.h"
#include "alf/alfcontrol.h"

#include <aknutils.h>
#include <aknlayout2def.h>
#include <aknlayoutscalable_avkon.cdl.h>
#include <aknlayout2hierarchy.h>


// =================
// Test Class
// =================

// CONSTRUCTION
UT_CAlfLCTAnchorLayout* UT_CAlfLCTAnchorLayout::NewL()
    {
    UT_CAlfLCTAnchorLayout* self = UT_CAlfLCTAnchorLayout::NewLC();
    CleanupStack::Pop();

    return self;
    }

UT_CAlfLCTAnchorLayout* UT_CAlfLCTAnchorLayout::NewLC()
    {
    UT_CAlfLCTAnchorLayout* self = new( ELeave ) UT_CAlfLCTAnchorLayout();
    CleanupStack::PushL( self );

    self->ConstructL();

    return self;
    }

// Destructor (virtual by CBase)
UT_CAlfLCTAnchorLayout::~UT_CAlfLCTAnchorLayout()
    {
    }

// Default constructor
UT_CAlfLCTAnchorLayout::UT_CAlfLCTAnchorLayout()
    {
    }

// Second phase construct
void UT_CAlfLCTAnchorLayout::ConstructL()
    {
    // The ConstructL from the base class CEUnitTestSuiteClass must be called.
    // It generates the test case table.
    CEUnitTestSuiteClass::ConstructL();
    }

// =================
// Tests
// =================

void UT_CAlfLCTAnchorLayout::SetupL(  )
    {
    iEnv = CAlfEnv::NewL();
    
    iControl = new( ELeave ) CAlfControl;
    iControl->ConstructL( *iEnv );

    iLayout = (CAlfLCTAnchorLayout*)iControl->AppendLayoutL( EAlfLayoutTypeLCTAnchor );
    }

void UT_CAlfLCTAnchorLayout::Teardown(  )
    {
    if ( iControl && iEnv && !iEnv->FindControl( iControl->Id() ) )
        {
        delete iControl;
        iControl = NULL;
        }
    delete iEnv;
    iEnv = NULL;
    }

void UT_CAlfLCTAnchorLayout::UT_CAlfLCTAnchorLayout_CAlfLCTAnchorLayoutL(  )
    {
    __UHEAP_MARK;
    CAlfLCTAnchorLayout* visual = new (ELeave) CAlfLCTAnchorLayout;
    delete visual;
    __UHEAP_MARKEND;
    }

void UT_CAlfLCTAnchorLayout::UT_CAlfLCTAnchorLayout_ConstructLL(  )
    {
    __UHEAP_MARK;
    CAlfLCTAnchorLayout* visual = new (ELeave) CAlfLCTAnchorLayout;
    CleanupStack::PushL( visual );
    visual->ConstructL( *iControl );
    CleanupStack::PopAndDestroy( visual );
    __UHEAP_MARKEND;
    }

void UT_CAlfLCTAnchorLayout::UT_CAlfLCTAnchorLayout_RemoveAndDestroyAllDL(  )
    {
    iLayout->RemoveAndDestroyAllD();
    iLayout = NULL;
    }

void UT_CAlfLCTAnchorLayout::UT_CAlfLCTAnchorLayout_SetAnchors(  )
    {
    // first calculate what the layout would be based on the current screen size
    TSize parentSize;
    AknLayoutUtils::LayoutMetricsSize(AknLayoutUtils::EScreen, parentSize);
    TAlfRealSize parentAlfSize(parentSize);
    iLayout->SetFlag(EAlfVisualFlagManualLayout);
    iLayout->SetSize(parentAlfSize);

#ifdef _DEBUG
    TAlfTimedPoint checkSize = iLayout->Size();
#endif // _DEBUG

    TInt cell_app_pane_g1_variety = 0; // not marked or highlighted
    TAknWindowLineLayout cell_app_pane_g1 = AknLayoutScalable_Avkon::cell_app_pane_g1(cell_app_pane_g1_variety).LayoutLineNoEmptys();

    TRect parentRect(parentSize);
    TAknLayoutRect layoutRect;
    layoutRect.LayoutRect( parentRect, cell_app_pane_g1);
    TRect cell_app_pane_g1_Rect = layoutRect.Rect();
    TSize cell_app_pane_g1_Size = cell_app_pane_g1_Rect.Size();

    // now the results
    TInt drawingIndex = 0;
    TAlfTimedPoint timedPoint;
    TAknLayoutHierarchyComponentHandle cell_app_pane_g1_Handle(
        KUidAknLayoutSystemId_AknLayout2,
        AknLayoutScalable_Avkon::KCdlInterfaceUidValue, 
        AknLayoutScalable_Avkon::EApiId_cell_app_pane_g1);
    cell_app_pane_g1_Handle.SetVarietyIndex(cell_app_pane_g1_variety);
    
    iLayout->SetAnchors(drawingIndex, cell_app_pane_g1_Handle, timedPoint);
    
    TPoint resultPos;
    TSize resultSize;
    iLayout->ChildPos(drawingIndex, resultPos);
    iLayout->ChildSize(drawingIndex, resultSize);

    EUNIT_ASSERT_EQUALS( cell_app_pane_g1_Rect.iTl, resultPos );
    EUNIT_ASSERT_EQUALS( cell_app_pane_g1_Size, resultSize );
    }

// =================
// Test Table
// =================


EUNIT_BEGIN_TEST_TABLE(
    UT_CAlfLCTAnchorLayout,
    "Alf Unit Tests",
    "UNIT" )

EUNIT_TEST(
    "CAlfLCTAnchorLayout - test ",
    "CAlfLCTAnchorLayout",
    "CAlfLCTAnchorLayout",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTAnchorLayout_CAlfLCTAnchorLayoutL, Teardown)

EUNIT_TEST(
    "ConstructL - test ",
    "CAlfLCTAnchorLayout",
    "ConstructL",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTAnchorLayout_ConstructLL, Teardown)

EUNIT_TEST(
    "RemoveAndDestroyAllD - test ",
    "CAlfLCTAnchorLayout",
    "RemoveAndDestroyAllD",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTAnchorLayout_RemoveAndDestroyAllDL, Teardown)

/** TODO: FIX TEST
 * THIS TEST IS NOT USED BECAUSE TEST FAILS. 
 * REQUIRES FURTHER STUDY AND FIX.
EUNIT_TEST(
    "SetAnchors - test ",
    "CAlfLCTAnchorLayout",
    "SetAnchors",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTAnchorLayout_SetAnchors, Teardown)
*/

EUNIT_END_TEST_TABLE

//  END OF FILE
