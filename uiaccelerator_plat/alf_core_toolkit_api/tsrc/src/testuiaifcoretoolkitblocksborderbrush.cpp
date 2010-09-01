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
#include <uiacceltk/huishadowborderbrush.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60BordBrushNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60BordBrushNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60BordBrushNewLL, "In TestH60BordBrushNewLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60BordBrushNewLL );
    // Print to log file 
    iLog->Log( KTestH60BordBrushNewLL );
    
    THuiMetric metric;
    CHuiShadowBorderBrush* brush = CHuiShadowBorderBrush::NewL( metric );
    delete brush;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60BordBrushNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60BordBrushNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60BordBrushNewLCL, "In TestH60BordBrushNewLCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60BordBrushNewLCL );
    // Print to log file 
    iLog->Log( KTestH60BordBrushNewLCL );
    
    THuiMetric metric;
    CHuiShadowBorderBrush* brush = CHuiShadowBorderBrush::NewLC( metric );
    CleanupStack::PopAndDestroy( brush );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60BordBrushNewLTIntL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60BordBrushNewLTIntL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60BordBrushNewLTIntL, "In TestH60BordBrushNewLTIntL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60BordBrushNewLTIntL );
    // Print to log file 
    iLog->Log( KTestH60BordBrushNewLTIntL );
    
    TInt temp = 10;
    CHuiShadowBorderBrush* brush = CHuiShadowBorderBrush::NewL( temp );
    delete brush;
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60BordBrushNewLCTIntL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60BordBrushNewLCTIntL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60BordBrushNewLTIntL, "In TestH60BordBrushNewLTIntL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60BordBrushNewLTIntL );
    // Print to log file 
    iLog->Log( KTestH60BordBrushNewLTIntL );
    
    TInt temp = 10;
    CHuiShadowBorderBrush* brush = CHuiShadowBorderBrush::NewLC( temp );
    CleanupStack::PopAndDestroy( brush );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestH60BordBrushSetWidthL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestH60BordBrushSetWidthL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestH60BordBrushNewLTIntL, "In TestH60BordBrushNewLTIntL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestH60BordBrushNewLTIntL );
    // Print to log file 
    iLog->Log( KTestH60BordBrushNewLTIntL );
    
    THuiMetric metric;
    CHuiShadowBorderBrush* brush = CHuiShadowBorderBrush::NewL( metric );
    CleanupStack::PushL( brush );
    brush->SetWidth( metric );
    CleanupStack::PopAndDestroy( brush );
    
    return KErrNone;
    
    }

//  [End of File]
