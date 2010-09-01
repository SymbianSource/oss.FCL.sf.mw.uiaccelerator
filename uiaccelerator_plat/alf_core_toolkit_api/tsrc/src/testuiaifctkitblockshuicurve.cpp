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
// CTestUiAifCoreToolkit::TestCHuiCurvePathNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathNewL, "In TestCHuiCurvePathNewL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathNewL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathNewL );

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
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathNewCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathNewCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathNewCL, "In TestCHuiCurvePathNewCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathNewCL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathNewCL );

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
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathDestructL, "In TestCHuiCurvePathDestructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathDestructL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathDestructL );

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
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathResetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathResetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathResetL, "In TestCHuiCurvePathResetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathResetL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathResetL );

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
    curvePath->Reset();
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathEnableLoopL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathEnableLoopL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathEnableLoopL, "In TestCHuiCurvePathEnableLoopL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathEnableLoopL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathEnableLoopL );

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
    curvePath->Reset();
    curvePath->EnableLoop();
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathLoopL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathLoopL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathLoopL, "In TestCHuiCurvePathLoopL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathLoopL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathLoopL );

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
    curvePath->Reset();
    curvePath->EnableLoop();
    curvePath->Loop();
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathSetOriginL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathSetOriginL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathSetOriginL, "In TestCHuiCurvePathSetOriginL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathSetOriginL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathSetOriginL );

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
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathAppendLineL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathAppendLineL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathAppendLineL, "In TestCHuiCurvePathAppendLineL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathAppendLineL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathAppendLineL );

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
    TPoint start( 0, 0 );
    TPoint end( 1, 1 );
    curvePath->AppendLineL( start, end );
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathAppendRealLineL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathAppendRealLineL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathAppendRealLineL, "In TestCHuiCurvePathAppendRealLineL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathAppendRealLineL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathAppendRealLineL );

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
    const THuiRealPoint realStart( 0, 0 );
    const THuiRealPoint realEnd( 1, 1 );
    curvePath->AppendLineL( realStart, realEnd );
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathAppendArcL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathAppendArcL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathAppendArcL, "In TestCHuiCurvePathAppendArcL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathAppendArcL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathAppendArcL );

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
    const TPoint aOrigin( 0, 0 );
    const TSize aSize( 3, 7 );
    TReal32 aStartAngle = 2;
    TReal32 aEndAngle = 4;
    curvePath->AppendArcL( aOrigin, aSize, aStartAngle, aEndAngle );
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathAppendHuiArcL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathAppendHuiArcL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathAppendHuiArcL, "In TestCHuiCurvePathAppendHuiArcL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathAppendHuiArcL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathAppendHuiArcL );

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
    const THuiRealPoint aOrigin( 0, 0 );
    const THuiRealSize aSize( 6, 9 );
    TReal32 aStartAngle = 2;
    TReal32 aEndAngle =8;
    curvePath->AppendArcL( aOrigin, aSize, aStartAngle, aEndAngle );
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathLengthL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathLengthL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathLengthL, "In TestCHuiCurvePathLengthL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathLengthL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathLengthL );

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
    TInt length = curvePath->Length();
    CleanupStack::PopAndDestroy( curvePath );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCurvePathEvaluateL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCurvePathEvaluateL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCurvePathEvaluateL, "In TestCHuiCurvePathLengthL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCurvePathEvaluateL );
    // Print to log file
    iLog->Log( KTestCHuiCurvePathEvaluateL );

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
    TInt length = curvePath->Length();
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

//  [End of File]
