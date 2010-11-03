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
#include <uiacceltk/huirealpoint.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint point;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPConstructorWithTReal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPConstructorWithTReal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPConstructorWithTReal" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint point( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPConstructorWithTPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPConstructorWithTPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPConstructorWithTPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TPoint point( 1, 1 );
    THuiRealPoint realPoint( point );
    TPoint a = realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPAsSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPAsSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPAsSize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint.AsSize();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPTPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPTPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPTPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    TPoint point = realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPRound
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPRound( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPRound" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    TPoint point = realPoint.Round();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPoperator1
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPoperator1( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPoperator1" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint = realPoint + realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPoperator2
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPoperator2( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPoperator2" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint += realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPoperator3
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPoperator3( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPoperator3" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint -= realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPoperator4
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPoperator4( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPoperator4" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint = -realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPoperator5
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPoperator5( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPoperator5" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint = realPoint - realPoint;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPoperator6
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPoperator6( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPoperator6" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint = realPoint * 1;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRPAbs
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRPAbs( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRPAbs" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint realPoint;
    realPoint.Abs();

    return KErrNone;
    }
