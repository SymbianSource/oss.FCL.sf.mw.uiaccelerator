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
#include <uiacceltk/huienv.h>
#include <uiacceltk/huistatic.h>
#include <uiacceltk/huidropshadow.h>
#include <uiacceltk/huidropshadowbrush.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowBrushNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowBrushNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowBrushNewLL, "In TestShadowBrushNewLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowBrushNewLL );
    // Print to log file 
    iLog->Log( KTestShadowBrushNewLL );
    
    THuiMetric metric;
    
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewL( metric );
    
    delete shadowBrush;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowBrushNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowBrushNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowBrushNewLCL, "In TestShadowBrushNewLCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowBrushNewLCL );
    // Print to log file 
    iLog->Log( KTestShadowBrushNewLCL );
    
    THuiMetric metric;
    
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewLC( metric );
    CleanupStack::PopAndDestroy( shadowBrush );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowBrushNewLTIntL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowBrushNewLTIntL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowBrushNewLTIntL, "In TestShadowBrushNewLTIntL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowBrushNewLTIntL );
    // Print to log file 
    iLog->Log( KTestShadowBrushNewLTIntL );
    
    TInt temp = 7;
    
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewL( temp );
    delete shadowBrush;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowBrushNewLTIntLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowBrushNewLTIntLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowBrushNewLTIntLCL, "In TestShadowBrushNewLTIntLCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowBrushNewLTIntLCL );
    // Print to log file 
    iLog->Log( KTestShadowBrushNewLTIntLCL );
    
    TInt temp = 7;
    
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewLC( temp );
    CleanupStack::PopAndDestroy( shadowBrush );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowBrushSetDepthL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowBrushSetDepthL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowBrushSetDepthL, "In TestShadowBrushSetDepthL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowBrushSetDepthL );
    // Print to log file 
    iLog->Log( KTestShadowBrushSetDepthL );
    
    THuiMetric metric;
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewL( metric );
    CleanupStack::PushL( shadowBrush );
    shadowBrush->SetDepth( metric );
    CleanupStack::PopAndDestroy( shadowBrush );

    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowSetSoftnessL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowSetSoftnessL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowSetSoftnessL, "In TestShadowSetSoftnessL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowSetSoftnessL );
    // Print to log file 
    iLog->Log( KTestShadowSetSoftnessL );
    
    THuiMetric metric;
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewL( metric );
    CleanupStack::PushL( shadowBrush );
    shadowBrush->SetSoftness( metric );
    CleanupStack::PopAndDestroy( shadowBrush );

    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestShadowSetColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestShadowSetColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestShadowSetColorL, "In TestShadowSetColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestShadowSetColorL );
    // Print to log file 
    iLog->Log( KTestShadowSetColorL );
    
    THuiMetric metric;
    CHuiDropShadowBrush* shadowBrush = CHuiDropShadowBrush::NewL( metric );
    CleanupStack::PushL( shadowBrush );
    TRgb rgb;
    shadowBrush->SetColor( rgb );
    CleanupStack::PopAndDestroy( shadowBrush );

    return KErrNone;
    
    }
//  [End of File]
