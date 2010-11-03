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
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huitimedpoint.h>
#include <uiacceltk/HuiMappingFunctions.h>

#include "testuiaifcoretoolkit.h"

const TReal32 number = 0.5;
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPConstructorWithTReal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPConstructorWithTReal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPConstructorWithTReal" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPSetStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPSetStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPSetStyle" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.SetStyle( EHuiTimedValueStyleNone );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPSetFunctionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPSetFunctionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPSetFunctionL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiConstantMappingFunction* function = new( ELeave ) THuiConstantMappingFunction();
    CleanupStack::PushL( function );
    STIF_ASSERT_NOT_NULL( function );
    THuiTimedPoint point( number, number );
    point.SetFunction( function );
    CleanupStack::PopAndDestroy( function );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPSet
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPSet( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPSet" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiRealPoint realPoint;
    THuiTimedPoint point( number, number );
    point.Set( realPoint );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPSetTReal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPSetTReal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPSetTReal" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.Set( number );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPSetWithSpeed
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPSetWithSpeed( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPSetWithSpeed" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiRealPoint realPoint;
    THuiTimedPoint point( number, number );
    point.SetWithSpeed( realPoint, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPSetWithSpeedTReal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPSetWithSpeedTReal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPSetWithSpeedTReal" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.SetWithSpeed( number, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPNow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPNow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPNow" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.Now();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPRealNow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPRealNow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPRealNow" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.RealNow();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPTarget
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPTarget( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPTarget" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.Target();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPRealTarget
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPRealTarget( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPRealTarget" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.RealTarget();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHTPFinish
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHTPFinish( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiIMageBrush, "In TestTHTPFinish" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiIMageBrush );
    // Print to log file
    iLog->Log( KCHuiIMageBrush );

    THuiTimedPoint point( number, number );
    point.Finish();

    return KErrNone;
    }
