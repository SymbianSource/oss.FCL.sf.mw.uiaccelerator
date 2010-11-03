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
#include <uiacceltk/huimetric.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huilayout.h>

#include "testuiaifcoretoolkit.h"

// ==================================THuiMetric=================================
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHMConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHMConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHMConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHMConstructorWithPixel
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHMConstructorWithPixel( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHMConstructorWithPixel" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric( 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHMAbs
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHMAbs( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHMAbs" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;
    metric.Abs();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHMoperator
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHMoperator( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHMoperator" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;
    metric = metric * 1;

    return KErrNone;
    }

// =================================THuiXYMetric================================
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHXYMConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHXYMConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHXYMConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiXYMetric metric;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHXYMConstructorWithMetric
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHXYMConstructorWithMetric( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHXYMConstructorWithMetric" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;
    THuiXYMetric xyMetric( metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHXYMConstructorWithTwo
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHXYMConstructorWithTwo( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHXYMConstructorWithTwo" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric1;
    THuiMetric metric2;
    THuiXYMetric xyMetric( metric1, metric2 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHXYMoperator
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHXYMoperator( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHXYMoperator" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiXYMetric metric;
    THuiRealPoint point( 1, 1 );
    metric = metric * point;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHXYMAbs
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHXYMAbs( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHXYMAbs" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiXYMetric metric;
    metric.Abs();

    return KErrNone;
    }

// ================================THuiBoxMetric================================
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHBMConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHBMConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHBMConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiBoxMetric metric;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHBMConstructorWithMetric
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHBMConstructorWithMetric( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHBMConstructorWithMetric" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;
    THuiBoxMetric boxMetric( metric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHBMConstructorWithXYMetric
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHBMConstructorWithXYMetric( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHBMConstructorWithXYMetric" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;
    THuiXYMetric xyMetric( metric );
    THuiBoxMetric boxMetric( xyMetric );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHBMConstructorWithTwo
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHBMConstructorWithTwo( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHBMConstructorWithTwo" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric;
    THuiXYMetric xyMetric1( metric );
    THuiXYMetric xyMetric2( metric );
    THuiBoxMetric boxMetric( xyMetric1, xyMetric2 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHBMConstructorWithFour
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHBMConstructorWithFour( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMetric, "In TestTHBMConstructorWithFour" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMetric );
    // Print to log file
    iLog->Log( KTestCHuiMetric );

    THuiMetric metric1;
    THuiMetric metric2;
    THuiMetric metric3;
    THuiMetric metric4;
    THuiBoxMetric boxMetric( metric1, metric2, metric3, metric4 );

    return KErrNone;
    }
