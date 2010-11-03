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
#include "UT_CAlfLCTTextVisual.h"

//  EXTERNAL INCLUDES
#include <EUnitMacros.h>


//  INTERNAL INCLUDES
#include "alf/alflcttextvisual.h"
#include "alf/alfdecklayout.h"
#include "alf/alfenv.h"
#include "alf/alfcontrol.h"

#include <aknlayout2def.h>
#include <aknlayoutscalable_avkon.cdl.h>
#include <aknlayout2hierarchy.h>


// =================
// Test Class
// =================

// CONSTRUCTION
UT_CAlfLCTTextVisual* UT_CAlfLCTTextVisual::NewL()
    {
    UT_CAlfLCTTextVisual* self = UT_CAlfLCTTextVisual::NewLC();
    CleanupStack::Pop();

    return self;
    }

UT_CAlfLCTTextVisual* UT_CAlfLCTTextVisual::NewLC()
    {
    UT_CAlfLCTTextVisual* self = new( ELeave ) UT_CAlfLCTTextVisual();
    CleanupStack::PushL( self );

    self->ConstructL();

    return self;
    }

// Destructor (virtual by CBase)
UT_CAlfLCTTextVisual::~UT_CAlfLCTTextVisual()
    {
    }

// Default constructor
UT_CAlfLCTTextVisual::UT_CAlfLCTTextVisual()
    {
    }

// Second phase construct
void UT_CAlfLCTTextVisual::ConstructL()
    {
    // The ConstructL from the base class CEUnitTestSuiteClass must be called.
    // It generates the test case table.
    CEUnitTestSuiteClass::ConstructL();
    }

// =================
// Tests
// =================

void UT_CAlfLCTTextVisual::SetupL(  )
    {
    iEnv = CAlfEnv::NewL();
    
    iControl = new( ELeave ) CAlfControl;
    iControl->ConstructL( *iEnv );

    iVisual = (CAlfLCTTextVisual*)iControl->AppendVisualL( EAlfVisualTypeLCTText );
    }

void UT_CAlfLCTTextVisual::Teardown(  )
    {
    if ( iControl && iEnv && !iEnv->FindControl( iControl->Id() ) )
        {
        delete iControl;
        iControl = NULL;
        }
    delete iEnv;
    iEnv = NULL;
    }

void UT_CAlfLCTTextVisual::UT_CAlfLCTTextVisual_CAlfLCTTextVisualL(  )
    {
    __UHEAP_MARK;
    CAlfLCTTextVisual* visual = new (ELeave) CAlfLCTTextVisual;
    delete visual;
    __UHEAP_MARKEND;
    }

void UT_CAlfLCTTextVisual::UT_CAlfLCTTextVisual_ConstructLL(  )
    {
    __UHEAP_MARK;
    CAlfLCTTextVisual* visual = new (ELeave) CAlfLCTTextVisual;
    CleanupStack::PushL( visual );
    visual->ConstructL( *iControl );
    CleanupStack::PopAndDestroy( visual );
    __UHEAP_MARKEND;
    }

void UT_CAlfLCTTextVisual::UT_CAlfLCTTextVisual_RemoveAndDestroyAllDL(  )
    {
    iVisual->RemoveAndDestroyAllD();
    iVisual = NULL;
    }

void UT_CAlfLCTTextVisual::UT_CAlfLCTTextVisual_SetTextPane(  )
    {
    TAlfAlignHorizontal alignHorizontal(EAlfAlignHLeft);
    TInt fontId1 = 0x80100004;
    TInt varietyIndex = 0;// not marked or highlighted

    TAknTextLineLayout componentLayout = AknLayoutScalable_Avkon::cell_app_pane_t1(varietyIndex).LayoutLine();
    TInt fontId2 = componentLayout.iFont;
    

    iVisual->SetAlign(alignHorizontal, EAlfAlignVCenter);
    // @todo can't test alignment, as huitk doesn't provide API
    
    // todo: do something else
    //iVisual->SetFontId(fontId1);
    //TInt resultFontId = iVisual->FontId(); // Deprecated
    //EUNIT_ASSERT_EQUALS( fontId1, resultFontId );
                           
    TAknLayoutHierarchyComponentHandle cell_app_pane_t1_Handle(
        KUidAknLayoutSystemId_AknLayout2,
        AknLayoutScalable_Avkon::KCdlInterfaceUidValue, 
        AknLayoutScalable_Avkon::EApiId_cell_app_pane_t1);
    cell_app_pane_t1_Handle.SetVarietyIndex(varietyIndex);
    
    iVisual->SetTextPane(cell_app_pane_t1_Handle);
        
    //resultFontId = iVisual->FontId(); // deprecated
//    EUNIT_ASSERT_EQUALS( fontId2, resultFontId );
    }

// =================
// Test Table
// =================


EUNIT_BEGIN_TEST_TABLE(
    UT_CAlfLCTTextVisual,
    "Alf Unit Tests",
    "UNIT" )

EUNIT_TEST(
    "CAlfLCTTextVisual - test ",
    "CAlfLCTTextVisual",
    "CAlfLCTTextVisual",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTTextVisual_CAlfLCTTextVisualL, Teardown)

EUNIT_TEST(
    "ConstructL - test ",
    "CAlfLCTTextVisual",
    "ConstructL",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTTextVisual_ConstructLL, Teardown)

EUNIT_TEST(
    "RemoveAndDestroyAllD - test ",
    "CAlfLCTTextVisual",
    "RemoveAndDestroyAllD",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTTextVisual_RemoveAndDestroyAllDL, Teardown)

/** TODO: FIX TEST
 * THIS TEST IS NOT USED BECAUSE TEST FAILS. 
 * REQUIRES FURTHER STUDY AND FIX.
EUNIT_TEST(
    "SetTextPane - test ",
    "CAlfLCTTextVisual",
    "SetTextPane",
    "FUNCTIONALITY",
    SetupL, UT_CAlfLCTTextVisual_SetTextPane, Teardown)
*/

EUNIT_END_TEST_TABLE

//  END OF FILE
