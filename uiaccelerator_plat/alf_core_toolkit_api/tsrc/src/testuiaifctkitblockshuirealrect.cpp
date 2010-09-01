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
#include <uiacceltk/huirealrect.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRConstructor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealRect rect;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRConstructorWithPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRConstructorWithPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRConstructorWithPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint point1;
    THuiRealPoint point2;
    THuiRealRect rect( point1, point2 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRConstructorWithPointAndSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRConstructorWithPointAndSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRConstructorWithPointAndSize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    THuiRealPoint point;
    THuiRealSize size;
    THuiRealRect rect( point, size );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRConstructorWithTRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRConstructorWithTRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRConstructorWithTRect" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect;
    THuiRealRect realRect( rect );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRWidth
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRWidth( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRWidth" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.Width();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRHeight
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRHeight( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRHeight" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.Height();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRTopRight
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRTopRight( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRTopRight" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.TopRight();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRBottomLeft
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRBottomLeft( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRBottomLeft" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.BottomLeft();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRSize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.Size();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRCenter
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRCenter( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRCenter" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.Center();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRGrow
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRGrow( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRGrow" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    TReal32 num1 = 0.1;
    TReal32 num2 = 0.1;
    realRect.Grow( num1, num2 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRShrink
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRShrink( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRShrink" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    TReal32 num1 = 0.1;
    TReal32 num2 = 0.1;
    realRect.Shrink( num1, num2 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRShrinkTPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRShrinkTPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRShrinkTPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    TPoint point( 0, 1 );
    realRect.Shrink( point );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRShrinkTHuiRealPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRShrinkTHuiRealPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRShrinkTHuiRealPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    THuiRealPoint point( 1, 0 );
    realRect.Shrink( point );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRShrinkTHuiRealRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRShrinkTHuiRealRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRShrinkTHuiRealRect" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect1( 1, 1, 1, 1 );
    TRect rect2( 0, 0, 1, 1 );
    THuiRealRect realRect1( rect1 );
    THuiRealRect realRect2( rect2 );
    realRect1.Shrink( realRect2 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRMove
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRMove( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRMove" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.Move( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRoperatorTRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRoperatorTRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRoperatorTRect" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect = rect;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRRound
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRRound( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRRound" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect( 1, 1, 1, 1 );
    THuiRealRect realRect( rect );
    realRect.Round();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHRRBoundingRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHRRBoundingRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiMappingFunctions, "In TestTHRRBoundingRect" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiMappingFunctions );
    // Print to log file
    iLog->Log( KHuiMappingFunctions );

    TRect rect1( 1, 1, 1, 1 );
    TRect rect2( 0, 0, 1, 1 );
    THuiRealRect realRect1( rect1 );
    THuiRealRect realRect2( rect2 );
    realRect1.BoundingRect( realRect2 );

    return KErrNone;
    }
