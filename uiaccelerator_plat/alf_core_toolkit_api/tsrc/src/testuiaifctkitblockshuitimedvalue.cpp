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
#include <fbs.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huitimedvalue.h>
#include <uiacceltk/huimappingfunctions.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestMHMFMappingFunctionChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestMHMFMappingFunctionChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestMHMFMappingFunctionChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiConstantMappingFunction* function = new( ELeave ) THuiConstantMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MappingFunctionChanged();
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestMHMFMappingFunctionClearChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestMHMFMappingFunctionClearChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestMHMFMappingFunctionClearChangedL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiConstantMappingFunction* function = new( ELeave ) THuiConstantMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    function->MappingFunctionClearChanged();
    CleanupStack::Pop( function );
    delete function;
    function = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVConstructorWithValue
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVConstructorWithValue( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVConstructorWithValue" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value( 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVStyle" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    THuiInterpolationStyle style = value.Style();
    STIF_ASSERT_EQUALS( style, EHuiTimedValueStyleAdaptive );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSetStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSetStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSetStyle" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.SetStyle( EHuiTimedValueStyleNone );
    THuiInterpolationStyle style = value.Style();
    STIF_ASSERT_EQUALS( style, EHuiTimedValueStyleNone );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSetFunction
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSetFunction( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSetFunction" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.SetFunction( NULL );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSetMappingMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSetMappingMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSetMappingMode" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.SetMappingMode( 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVNow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVNow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVNow" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Now();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVUnmappedNow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVUnmappedNow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVUnmappedNow" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.UnmappedNow();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVTarget
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVTarget( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVTarget" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Target();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSetValue
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSetValue( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSetValue" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Set( 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSetValueTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSetValueTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSetValueTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Set( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSetWithSpeed
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSetWithSpeed( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSetWithSpeed" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.SetWithSpeed( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVRemainingTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVRemainingTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVRemainingTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.RemainingTime();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVFinish
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVFinish( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVFinish" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Finish();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVChanged" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Changed();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVInterpolating
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVInterpolating( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVInterpolating" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Interpolating();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVClearChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVClearChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVClearChanged" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.ClearChanged();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVEnableClock
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVEnableClock( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVEnableClock" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.EnableClock();
    value.EnableClock( EFalse );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVSuspend
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVSuspend( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVSuspend" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    value.Suspend();
    value.Suspend( EFalse );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTVoperatorEqualTo
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTVoperatorEqualTo( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiTimedValue, "In TestTHTVoperatorEqualTo" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiTimedValue );
    // Print to log file
    iLog->Log( KHuiTimedValue );

    THuiTimedValue value;
    THuiTimedValue otheValue;
    value = otheValue;

    return KErrNone;
    }
