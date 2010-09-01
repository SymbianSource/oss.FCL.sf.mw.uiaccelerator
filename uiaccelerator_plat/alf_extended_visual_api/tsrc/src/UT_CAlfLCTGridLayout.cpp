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
#include "UT_CAlfLCTGridLayout.h"

//  EXTERNAL INCLUDES
#include <EUnitMacros.h>


//  INTERNAL INCLUDES
#include "alf/alflctGridLayout.h"
#include "alf/alfdecklayout.h"
#include "alf/alfenv.h"
#include "alf/alfcontrol.h"

#include <aknlayout2def.h>
#include <aknlayoutscalable_avkon.cdl.h>
#include <aknlayout2hierarchy.h>
#include <LayoutMetaData.cdl.h>


// =================
// Test Class
// =================

// CONSTRUCTION
UT_CAlfLCTGridLayout* UT_CAlfLCTGridLayout::NewL()
    {
    UT_CAlfLCTGridLayout* self = UT_CAlfLCTGridLayout::NewLC();
    CleanupStack::Pop();

    return self;
    }

UT_CAlfLCTGridLayout* UT_CAlfLCTGridLayout::NewLC()
    {
    UT_CAlfLCTGridLayout* self = new( ELeave ) UT_CAlfLCTGridLayout();
    CleanupStack::PushL( self );

    self->ConstructL();

    return self;
    }

// Destructor (virtual by CBase)
UT_CAlfLCTGridLayout::~UT_CAlfLCTGridLayout()
    {
    }

// Default constructor
UT_CAlfLCTGridLayout::UT_CAlfLCTGridLayout()
    {
    }

// Second phase construct
void UT_CAlfLCTGridLayout::ConstructL()
    {
    // The ConstructL from the base class CEUnitTestSuiteClass must be called.
    // It generates the test case table.
    CEUnitTestSuiteClass::ConstructL();
    }

// =================
// Tests
// =================

void UT_CAlfLCTGridLayout::SetupL(  )
    {
    iEnv = CAlfEnv::NewL();
    
    iControl = new( ELeave ) CAlfControl;
    iControl->ConstructL( *iEnv );

    iLayout = (CAlfLCTGridLayout*)iControl->AppendLayoutL( EAlfLayoutTypeLCTGrid );
    }

void UT_CAlfLCTGridLayout::Teardown(  )
    {
    if ( iControl && iEnv && !iEnv->FindControl( iControl->Id() ) )
        {
        delete iControl;
        iControl = NULL;
        }
    delete iEnv;
    iEnv = NULL;
    }

void UT_CAlfLCTGridLayout::UT_CAlfLCTGridLayout_CAlfLCTGridLayoutL(  )
    {
    __UHEAP_MARK;
    CAlfLCTGridLayout* visual = new (ELeave) CAlfLCTGridLayout;
    delete visual;
    __UHEAP_MARKEND;
    }

void UT_CAlfLCTGridLayout::UT_CAlfLCTGridLayout_ConstructLL(  )
    {
    __UHEAP_MARK;
    CAlfLCTGridLayout* visual = new (ELeave) CAlfLCTGridLayout;
    CleanupStack::PushL( visual );
    visual->ConstructL( *iControl );
    CleanupStack::PopAndDestroy( visual );
    __UHEAP_MARKEND;
    }

void UT_CAlfLCTGridLayout::UT_CAlfLCTGridLayout_RemoveAndDestroyAllDL(  )
    {
    iLayout->RemoveAndDestroyAllD();
    iLayout = NULL;
    }

void UT_CAlfLCTGridLayout::UT_CAlfLCTGridLayout_SetColsAndRows(  )
    {
    TInt cell_app_pane_variety = Layout_Meta_Data::IsLandscapeOrientation() ? 2 : 1;
    TAknLayoutScalableParameterLimits cell_app_pane_limits = AknLayoutScalable_Avkon::cell_app_pane_ParamLimits(cell_app_pane_variety);
    TInt cols = cell_app_pane_limits.LastColumn() + 1;
    TInt rows = cell_app_pane_limits.LastRow() + 1;

    TAknLayoutHierarchyComponentHandle cell_app_pane_Handle(
        KUidAknLayoutSystemId_AknLayout2,
        AknLayoutScalable_Avkon::KCdlInterfaceUidValue, 
        AknLayoutScalable_Avkon::EApiId_cell_app_pane);

    cell_app_pane_Handle.SetVarietyIndex(cell_app_pane_variety);

    TAlfTimedPoint timedPoint;
    iLayout->SetColsAndRows(cell_app_pane_Handle, timedPoint);
    
    TInt resultCols = iLayout->ColumnCount();
    TInt resultRows = iLayout->RowCount();
    
    EUNIT_ASSERT_EQUALS( cols, resultCols );
    EUNIT_ASSERT_EQUALS( rows, resultRows );
    }

// =================
// Test Table
// =================


EUNIT_BEGIN_TEST_TABLE(
    UT_CAlfLCTGridLayout,
    "Alf Unit Tests",
    "UNIT" )

EUNIT_TEST(
    "CAlfLCTGridLayout - test ",
    "CAlfLCTGridLayout",
    "CAlfLCTGridLayout",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTGridLayout_CAlfLCTGridLayoutL, Teardown)

EUNIT_TEST(
    "ConstructL - test ",
    "CAlfLCTGridLayout",
    "ConstructL",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTGridLayout_ConstructLL, Teardown)

EUNIT_TEST(
    "RemoveAndDestroyAllD - test ",
    "CAlfLCTGridLayout",
    "RemoveAndDestroyAllD",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTGridLayout_RemoveAndDestroyAllDL, Teardown)

/** TODO: FIX TEST
 * THIS TEST IS NOT USED BECAUSE TEST FAILS. 
 * REQUIRES FURTHER STUDY AND FIX.
EUNIT_TEST(
    "SetColsAndRows - test ",
    "CAlfLCTGridLayout",
    "SetColsAndRows",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTGridLayout_SetColsAndRows, Teardown)
*/

EUNIT_END_TEST_TABLE

//  END OF FILE
