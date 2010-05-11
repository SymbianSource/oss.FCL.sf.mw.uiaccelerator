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
* Description:  Test functions for alfvisualhandlers.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"
#include "testalfvisualhandlers.h"


// ============================ MEMBER FUNCTIONS =========================

// --------------------------------------------------------------------------
// CTestCAlfVisualHandler::CTestCAlfVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfVisualHandler::CTestCAlfVisualHandler( MAlfInterfaceProvider& aResolver )
    : CAlfVisualHandler( aResolver )
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfVisualHandler::~CTestCAlfVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfVisualHandler::~CTestCAlfVisualHandler()
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfVisualHandler::TestProtected
// --------------------------------------------------------------------------
//
TInt CTestCAlfVisualHandler::TestProtected( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfTextVisualHandler::CTestCAlfTextVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfTextVisualHandler::CTestCAlfTextVisualHandler( MAlfInterfaceProvider& aResolver )
    : CAlfTextVisualHandler( aResolver )
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfTextVisualHandler::~CTestCAlfTextVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfTextVisualHandler::~CTestCAlfTextVisualHandler()
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfTextVisualHandler::TestProtected
// --------------------------------------------------------------------------
//
TInt CTestCAlfTextVisualHandler::TestProtected( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfLCTTextVisualHandler::CTestCAlfLCTTextVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfLCTTextVisualHandler::CTestCAlfLCTTextVisualHandler( MAlfInterfaceProvider& aResolver )
    : CAlfLCTTextVisualHandler( aResolver )
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfLCTTextVisualHandler::~CTestCAlfLCTTextVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfLCTTextVisualHandler::~CTestCAlfLCTTextVisualHandler()
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfLCTTextVisualHandler::TestProtected
// --------------------------------------------------------------------------
//
TInt CTestCAlfLCTTextVisualHandler::TestProtected( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestCAlfImageVisualHandler::CTestCAlfImageVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfImageVisualHandler::CTestCAlfImageVisualHandler( MAlfInterfaceProvider& aResolver )
    : CAlfImageVisualHandler( aResolver )
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfImageVisualHandler::~CTestCAlfImageVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfImageVisualHandler::~CTestCAlfImageVisualHandler()
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfImageVisualHandler::TestProtected
// --------------------------------------------------------------------------
//
TInt CTestCAlfImageVisualHandler::TestProtected( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfLineVisualHandler::CTestCAlfLineVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfLineVisualHandler::CTestCAlfLineVisualHandler( MAlfInterfaceProvider& aResolver )
    : CAlfLineVisualHandler( aResolver )
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfLineVisualHandler::~CTestCAlfLineVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfLineVisualHandler::~CTestCAlfLineVisualHandler()
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfLineVisualHandler::TestProtected
// --------------------------------------------------------------------------
//
TInt CTestCAlfLineVisualHandler::TestProtected( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestCAlfMeshVisualHandler::CTestCAlfMeshVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfMeshVisualHandler::CTestCAlfMeshVisualHandler( MAlfInterfaceProvider& aResolver )
    : CAlfMeshVisualHandler( aResolver )
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfMeshVisualHandler::~CTestCAlfMeshVisualHandler
// --------------------------------------------------------------------------
//
CTestCAlfMeshVisualHandler::~CTestCAlfMeshVisualHandler()
    {
    }
// --------------------------------------------------------------------------
// CTestCAlfMeshVisualHandler::TestProtected
// --------------------------------------------------------------------------
//
TInt CTestCAlfMeshVisualHandler::TestProtected( CStifItemParser& /*aItem*/ )
    {
    TUid id = { 0x00000001 };
    TAny** extent = NULL;
    VisualHandlerExtension( id, extent );
    return KErrNone;
    }




// End of file



