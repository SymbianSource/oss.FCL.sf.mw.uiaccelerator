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
#include <uiacceltk/huirealsize.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRSConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRSConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRSConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealSize size;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRSConstructorWithTReal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRSConstructorWithTReal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRSConstructorWithTReal" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealSize size( 1, 0.1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRSConstructorWithTSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRSConstructorWithTSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRSConstructorWithTSize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TSize size( 1, 1 );
    THuiRealSize realSize( size );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRSoperatorTSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRSoperatorTSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRSoperatorTSize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TSize size( 1, 1 );
    THuiRealSize realSize = size;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRSRound
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRSRound( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRSRound" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TSize size( 1, 1 );
    THuiRealSize realSize = size;
    realSize.Round();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRSoperatorPlus
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRSoperatorPlus( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRSoperatorPlus" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TSize size( 1, 1 );
    THuiRealSize realSize = size;
    realSize = realSize * 0.1;

    return KErrNone;
    }
