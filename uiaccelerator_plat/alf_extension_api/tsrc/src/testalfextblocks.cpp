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
* Description:  function implement of testalfext
*
*/



// [INCLUDE FILES]
#include <e32svr.h>
#include <stifparser.h>
#include <stiftestinterface.h>

#include "testalfext.h"


// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CTestAlfExt::RunMethodL
// Run specified method. Contains also table of test mothods and their names.
// -----------------------------------------------------------------------------
//
TInt CTestAlfExt::RunMethodL( CStifItemParser& aItem ) 
    {

    static TStifFunctionInfo const KFunctions[] =
        {  
        // First string is the function name used in TestScripter script file.
        // Second is the actual implementation member function. 
        ENTRY( "TestBrushHandlerConstructL", CTestAlfExt::TestBrushHandlerConstructL ), 
        ENTRY( "TestBrushHandlerForMAlfExtensionL", CTestAlfExt::TestBrushHandlerForMAlfExtensionL ), 
        ENTRY( "TestBrushHandlerForOthersL", CTestAlfExt::TestBrushHandlerForOthersL ), 
        ENTRY( "TestBorderBrushHandlerConstructL", CTestAlfExt::TestBorderBrushHandlerConstructL ), 
        ENTRY( "TestBorderBrushHandlerProtectedL", CTestAlfExt::TestBorderBrushHandlerProtectedL ), 
        ENTRY( "TestImageBrushHandlerConstructL", CTestAlfExt::TestImageBrushHandlerConstructL ), 
        ENTRY( "TestImageBrushHandlerProtectedL", CTestAlfExt::TestImageBrushHandlerProtectedL ), 
        ENTRY( "TestShadowBorderBrushHandlerConstructL", CTestAlfExt::TestShadowBorderBrushHandlerConstructL ), 
        ENTRY( "TestShadowBorderBrushHandlerProtectedL", CTestAlfExt::TestShadowBorderBrushHandlerProtectedL ), 
        ENTRY( "TestDropShadowBrushHandlerConstructL", CTestAlfExt::TestDropShadowBrushHandlerConstructL ), 
        ENTRY( "TestDropShadowBrushHandlerProtectedL", CTestAlfExt::TestDropShadowBrushHandlerProtectedL ), 
        ENTRY( "TestGradientBrushHandlerConstructL", CTestAlfExt::TestGradientBrushHandlerConstructL ), 
        ENTRY( "TestGradientBrushHandlerProtectedL", CTestAlfExt::TestGradientBrushHandlerProtectedL ), 
        ENTRY( "TestFrameBrushHandlerConstructL", CTestAlfExt::TestFrameBrushHandlerConstructL ), 
        ENTRY( "TestFrameBrushHandlerProtectedL", CTestAlfExt::TestFrameBrushHandlerProtectedL ), 
        ENTRY( "TestLayoutHandlerConstructL", CTestAlfExt::TestLayoutHandlerConstructL ), 
        ENTRY( "TestLayoutHandlerProtectedL", CTestAlfExt::TestLayoutHandlerProtectedL ), 
        ENTRY( "TestAnchorLayoutHandlerConstructL", CTestAlfExt::TestAnchorLayoutHandlerConstructL ), 
        ENTRY( "TestAnchorLayoutHandlerProtectedL", CTestAlfExt::TestAnchorLayoutHandlerProtectedL ), 
        ENTRY( "TestLCTAnchorLayoutHandlerConstructL", CTestAlfExt::TestLCTAnchorLayoutHandlerConstructL ), 
        ENTRY( "TestLCTAnchorLayoutHandlerProtectedL", CTestAlfExt::TestLCTAnchorLayoutHandlerProtectedL ), 
        ENTRY( "TestGridLayoutHandlerConstructL", CTestAlfExt::TestGridLayoutHandlerConstructL ), 
        ENTRY( "TestGridLayoutHandlerProtectedL", CTestAlfExt::TestGridLayoutHandlerProtectedL ), 
        ENTRY( "TestLCTGridLayoutHandlerConstructL", CTestAlfExt::TestLCTGridLayoutHandlerConstructL ), 
        ENTRY( "TestLCTGridLayoutHandlerProtectedL", CTestAlfExt::TestLCTGridLayoutHandlerProtectedL ), 
        ENTRY( "TestDeckLayoutHandlerConstructL", CTestAlfExt::TestDeckLayoutHandlerConstructL ), 
        ENTRY( "TestDeckLayoutHandlerProtectedL", CTestAlfExt::TestDeckLayoutHandlerProtectedL ), 
        ENTRY( "TestFlowLayoutHandlerConstructL", CTestAlfExt::TestFlowLayoutHandlerConstructL ), 
        ENTRY( "TestFlowLayoutHandlerProtectedL", CTestAlfExt::TestFlowLayoutHandlerProtectedL ), 
        ENTRY( "TestCurvePathLayoutHandlerConstructL", CTestAlfExt::TestCurvePathLayoutHandlerConstructL ), 
        ENTRY( "TestCurvePathLayoutHandlerProtectedL", CTestAlfExt::TestCurvePathLayoutHandlerProtectedL ), 
        ENTRY( "TestViewportLayoutHandlerConstructL", CTestAlfExt::TestViewportLayoutHandlerConstructL ), 
        ENTRY( "TestViewportLayoutHandlerProtectedL", CTestAlfExt::TestViewportLayoutHandlerProtectedL ), 
        ENTRY( "TestTimedValueUtil", CTestAlfExt::TestTimedValueUtil ), 
        ENTRY( "TestTimedPointUtil", CTestAlfExt::TestTimedPointUtil ), 
        ENTRY( "TestFileTokenUtil", CTestAlfExt::TestFileTokenUtil ), 
        ENTRY( "TestVisualHandlerConstructL", CTestAlfExt::TestVisualHandlerConstructL ), 
        ENTRY( "TestVisualHandlerMutualL", CTestAlfExt::TestVisualHandlerMutualL ), 
        ENTRY( "TestTextVisualHandlerConstructL", CTestAlfExt::TestTextVisualHandlerConstructL ), 
        ENTRY( "TestTextVisualHandlerMutualL", CTestAlfExt::TestTextVisualHandlerMutualL ), 
        ENTRY( "TestLCTTextVisualHandlerConstructL", CTestAlfExt::TestLCTTextVisualHandlerConstructL ), 
        ENTRY( "TestLCTTextVisualHandlerMutualL", CTestAlfExt::TestLCTTextVisualHandlerMutualL ), 
        ENTRY( "TestImageVisualHandlerConstructL", CTestAlfExt::TestImageVisualHandlerConstructL ), 
        ENTRY( "TestImageVisualHandlerMutualL", CTestAlfExt::TestImageVisualHandlerMutualL ), 
        ENTRY( "TestLineVisualHandlerConstructL", CTestAlfExt::TestLineVisualHandlerConstructL ), 
        ENTRY( "TestLineVisualHandlerMutualL", CTestAlfExt::TestLineVisualHandlerMutualL ), 
        ENTRY( "TestMeshVisualHandlerConstructL", CTestAlfExt::TestMeshVisualHandlerConstructL ), 
        ENTRY( "TestMeshVisualHandlerMutualL", CTestAlfExt::TestMeshVisualHandlerMutualL ), 
        ENTRY( "TestRFTokenClientFuncL", CTestAlfExt::TestRFTokenClientFuncL ), 

        };

    const TInt count = sizeof( KFunctions ) / sizeof( TStifFunctionInfo );

    return RunInternalL( KFunctions, count, aItem );

    }

