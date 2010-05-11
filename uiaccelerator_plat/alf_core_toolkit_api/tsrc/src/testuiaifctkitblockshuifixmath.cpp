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
#include <uiacceltk/huifixmath.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFixHypot
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFixHypot( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFixHypot" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FixHypot( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFixSin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFixSin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFixSin" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FixSin( 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFixCos
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFixCos( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFixCos" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FixCos( 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFixMul
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFixMul( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFixMul" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FixMul( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFixDiv
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFixDiv( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFixDiv" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FixDiv( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFloatToFix
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFloatToFix( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFloatToFix" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FloatToFix( 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHFMFixToFloat
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHFMFixToFloat( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiFixMath, "In TestHFMFixToFloat" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiFixMath );
    // Print to log file
    iLog->Log( KHuiFixMath );

    HuiFixMath::FixToFloat( 1 );

    return KErrNone;
    }
