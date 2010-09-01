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
* Description:  Test functions for alflayouthandlers.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"
#include "testalflayouthandlers.h"


// ============================ MEMBER FUNCTIONS =========================

// --------------------------------------------------------------------------
// CTestCAlfLayoutHandler::CTestCAlfLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfLayoutHandler::CTestCAlfLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfLayoutHandler::~CTestCAlfLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfLayoutHandler::~CTestCAlfLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfAnchorLayoutHandler::CTestCAlfAnchorLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfAnchorLayoutHandler::CTestCAlfAnchorLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfAnchorLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfAnchorLayoutHandler::~CTestCAlfAnchorLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfAnchorLayoutHandler::~CTestCAlfAnchorLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfAnchorLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfAnchorLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfLCTAnchorLayoutHandler::CTestCAlfLCTAnchorLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfLCTAnchorLayoutHandler::CTestCAlfLCTAnchorLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfLCTAnchorLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfLCTAnchorLayoutHandler::~CTestCAlfLCTAnchorLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfLCTAnchorLayoutHandler::~CTestCAlfLCTAnchorLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfLCTAnchorLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfLCTAnchorLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfGridLayoutHandler::CTestCAlfGridLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfGridLayoutHandler::CTestCAlfGridLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfGridLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfGridLayoutHandler::~CTestCAlfGridLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfGridLayoutHandler::~CTestCAlfGridLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfGridLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfGridLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }



// --------------------------------------------------------------------------
// CTestCAlfLCTGridLayoutHandler::CTestCAlfLCTGridLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfLCTGridLayoutHandler::CTestCAlfLCTGridLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfLCTGridLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfLCTGridLayoutHandler::~CTestCAlfLCTGridLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfLCTGridLayoutHandler::~CTestCAlfLCTGridLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfLCTGridLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfLCTGridLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfDeckLayoutHandler::CTestCAlfDeckLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfDeckLayoutHandler::CTestCAlfDeckLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfDeckLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfDeckLayoutHandler::~CTestCAlfDeckLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfDeckLayoutHandler::~CTestCAlfDeckLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfDeckLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfDeckLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfFlowLayoutHandler::CTestCAlfFlowLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfFlowLayoutHandler::CTestCAlfFlowLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfFlowLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfFlowLayoutHandler::~CTestCAlfFlowLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfFlowLayoutHandler::~CTestCAlfFlowLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfFlowLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfFlowLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfCurvePathLayoutHandler::CTestCAlfCurvePathLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfCurvePathLayoutHandler::CTestCAlfCurvePathLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfCurvePathLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfCurvePathLayoutHandler::~CTestCAlfCurvePathLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfCurvePathLayoutHandler::~CTestCAlfCurvePathLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfCurvePathLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfCurvePathLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfViewportLayoutHandler::CTestCAlfViewportLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfViewportLayoutHandler::CTestCAlfViewportLayoutHandler( MAlfInterfaceProvider& aResolver )
    : CAlfViewportLayoutHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfViewportLayoutHandler::~CTestCAlfViewportLayoutHandler
// --------------------------------------------------------------------------
//
CTestCAlfViewportLayoutHandler::~CTestCAlfViewportLayoutHandler()
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfViewportLayoutHandler::TestProtect
// --------------------------------------------------------------------------
//
TInt CTestCAlfViewportLayoutHandler::TestProtect( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// End of file


