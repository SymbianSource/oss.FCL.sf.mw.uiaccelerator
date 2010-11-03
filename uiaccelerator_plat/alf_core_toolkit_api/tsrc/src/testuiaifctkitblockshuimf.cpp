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
#include <uiacceltk/HuiMappingFunctions.h>

#include "testuiaifcoretoolkit.h"

// --------------------------THuiConstantMappingFunction------------------------
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHCMFConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHCMFConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHCMFConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiConstantMappingFunction* function = new( ELeave ) THuiConstantMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHCMFMapValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHCMFMapValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHCMFMapValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiConstantMappingFunction* function = new( ELeave ) THuiConstantMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MapValue( 0 ,0 );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// ---------------------------THuiLinearMappingFunction-------------------------
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHLMFConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHLMFConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHLMFConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiLinearMappingFunction* function = new( ELeave ) THuiLinearMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHLMFMapValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHLMFMapValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHLMFMapValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiLinearMappingFunction* function = new( ELeave ) THuiLinearMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MapValue( 0 ,0 );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// ----------------------------THuiSineMappingFunction--------------------------
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHSMFConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHSMFConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHSMFConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiSineMappingFunction* function = new( ELeave ) THuiSineMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHSMFMapValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHSMFMapValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHSMFMapValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiSineMappingFunction* function = new( ELeave ) THuiSineMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MapValue( 0 ,0 );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// ---------------------------THuiCosineMappingFunction-------------------------
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHCosineMFConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHCosineMFConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHCosineMFConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiCosineMappingFunction* function = new( ELeave ) THuiCosineMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHCosineMFMapValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHCosineMFMapValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHCosineMFMapValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiCosineMappingFunction* function = new( ELeave ) THuiCosineMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MapValue( 0 ,0 );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// --------------------------THuiAverageMappingFunction-------------------------
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHAMFConstructorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHAMFConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHAMFConstructorL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiAverageMappingFunction* function = new( ELeave ) THuiAverageMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHAMFMapValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHAMFMapValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHAMFMapValueL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiAverageMappingFunction* function = new( ELeave ) THuiAverageMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MapValue( 0 ,0 );
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHAMFMappingFunctionChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHAMFMappingFunctionChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHAMFMappingFunctionChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiAverageMappingFunction* function = new( ELeave ) THuiAverageMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MappingFunctionChanged();
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHAMFMappingFunctionClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHAMFMappingFunctionClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHAMFMappingFunctionClearChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiAverageMappingFunction* function = new( ELeave ) THuiAverageMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MappingFunctionClearChanged();
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }
