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
* Description:  For test alf core toolkit api modules
*
*/



// [INCLUDE FILES]
#include <e32svr.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huicontrolgroup.h>
#include <uiacceltk/huivisual.h>
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huievent.h>
#include <uiacceltk/huicurvepath.h>
#include <uiacceltk/huicurvepathlayout.h>
#include <eikenv.h>
#include <e32err.h>

#include "testuiaifcoretoolkit.h"
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathLayAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathLayAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathLayAddNewL, "In TestCHuiCurvePathLayAddNewL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathLayAddNewL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathLayAddNewL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    CHuiCurvePath* curvePath = CHuiCurvePath::NewL();
    STIF_ASSERT_NOT_NULL( curvePath );
    CleanupStack::PushL( curvePath );
    curvePath->SetOrigin( 0 );
    TReal32 length = curvePath->Length();
    TReal32 aPos = 2; 
    THuiRealPoint aPoint( 3, 3 );
    curvePath->Evaluate( aPos, aPoint ); 
    CleanupStack::PopAndDestroy( curvePath );
    CHuiCurvePathLayout* pathLayout = CHuiCurvePathLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( pathLayout );
    CleanupStack::PushL( pathLayout );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathLayCurvePathL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathLayCurvePathL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathLayCurvePathL, "In TestCHuiCurvePathLayCurvePathL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathLayCurvePathL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathLayCurvePathL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    CHuiCurvePath* curvePath = CHuiCurvePath::NewL();
    STIF_ASSERT_NOT_NULL( curvePath );
    CleanupStack::PushL( curvePath );
    curvePath->SetOrigin( 0 );
    TReal32 length = curvePath->Length();
    TReal32 aPos = 2; 
    THuiRealPoint aPoint( 3, 3 );
    curvePath->Evaluate( aPos, aPoint ); 
    CleanupStack::PopAndDestroy( curvePath );
    CHuiCurvePathLayout* pathLayout = CHuiCurvePathLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( pathLayout );
    CHuiCurvePath& curvePahth = pathLayout->CurvePath();
    CleanupStack::PushL( pathLayout );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }

// [End of File]
