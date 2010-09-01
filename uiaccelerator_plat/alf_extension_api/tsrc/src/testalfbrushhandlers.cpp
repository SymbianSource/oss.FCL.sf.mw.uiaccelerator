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
* Description:  Test functions for alfbrushhandlers.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"
#include "testalfbrushhandlers.h"


// CONSTANTS
const TInt KBufSize = 64;
_LIT8( KTest, "test" );
// ============================ MEMBER FUNCTIONS =========================
// --------------------------------------------------------------------------
// CTestCAlfBrushHandler::CTestCAlfBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfBrushHandler::CTestCAlfBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfBrushHandler::ConstructL
// --------------------------------------------------------------------------
//
void CTestCAlfBrushHandler::ConstructL()
    {
    CHuiBorderBrush* brush = CHuiBorderBrush::NewLC( 1, 1, 1, 1 );
    CAlfBrushHandler::ConstructL( brush );
    CleanupStack::Pop( brush );
    }
// --------------------------------------------------------------------------
// CTestCAlfBrushHandler::~CTestCAlfBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfBrushHandler::~CTestCAlfBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfBrushHandler::TestBrushHandlerForMAlfExtensionL
// --------------------------------------------------------------------------
//
TInt CTestCAlfBrushHandler::TestBrushHandlerForMAlfExtensionL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfBrushGetOpacity;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    Release();
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestCAlfBrushHandler::TestBrushHandlerForOthers
// --------------------------------------------------------------------------
//
TInt CTestCAlfBrushHandler::TestBrushHandlerForOthers( CStifItemParser& /*aItem*/ )
    {
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfBorderBrushHandler::CTestCAlfBorderBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfBorderBrushHandler::CTestCAlfBorderBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfBorderBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfBorderBrushHandler::~CTestCAlfBorderBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfBorderBrushHandler::~CTestCAlfBorderBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfBorderBrushHandler::TestProtectedL
// --------------------------------------------------------------------------
//
TInt CTestCAlfBorderBrushHandler::TestProtectedL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfBorderBrushSetColor;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    Release();
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestCAlfImageBrushHandler::CTestCAlfImageBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfImageBrushHandler::CTestCAlfImageBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfImageBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfImageBrushHandler::~CTestCAlfImageBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfImageBrushHandler::~CTestCAlfImageBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfImageBrushHandler::TestProtectedL
// --------------------------------------------------------------------------
//
TInt CTestCAlfImageBrushHandler::TestProtectedL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfImageBrushSetOffset;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    Release();
    return KErrNone;
    }



// --------------------------------------------------------------------------
// CTestCAlfShadowBorderBrushHandler::CTestCAlfShadowBorderBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfShadowBorderBrushHandler::CTestCAlfShadowBorderBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfShadowBorderBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfShadowBorderBrushHandler::~CTestCAlfShadowBorderBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfShadowBorderBrushHandler::~CTestCAlfShadowBorderBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfShadowBorderBrushHandler::TestProtectedL
// --------------------------------------------------------------------------
//
TInt CTestCAlfShadowBorderBrushHandler::TestProtectedL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfShadowBorderBrushSetWidth;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    Release();
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestCAlfDropShadowBrushHandler::CTestCAlfDropShadowBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfDropShadowBrushHandler::CTestCAlfDropShadowBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfDropShadowBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfDropShadowBrushHandler::~CTestCAlfDropShadowBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfDropShadowBrushHandler::~CTestCAlfDropShadowBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfDropShadowBrushHandler::TestProtectedL
// --------------------------------------------------------------------------
//
TInt CTestCAlfDropShadowBrushHandler::TestProtectedL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfDropShadowBrushGetSoftness;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    Release();
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfGradientBrushHandler::CTestCAlfGradientBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfGradientBrushHandler::CTestCAlfGradientBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfGradientBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfGradientBrushHandler::~CTestCAlfGradientBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfGradientBrushHandler::~CTestCAlfGradientBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfGradientBrushHandler::TestProtectedL
// --------------------------------------------------------------------------
//
TInt CTestCAlfGradientBrushHandler::TestProtectedL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfBrushGetOpacity;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    Release();
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestCAlfFrameBrushHandler::CTestCAlfFrameBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfFrameBrushHandler::CTestCAlfFrameBrushHandler( MAlfInterfaceProvider& aResolver )
    :CAlfFrameBrushHandler( aResolver )
    {
    }

// --------------------------------------------------------------------------
// CTestCAlfFrameBrushHandler::~CTestCAlfFrameBrushHandler
// --------------------------------------------------------------------------
//
CTestCAlfFrameBrushHandler::~CTestCAlfFrameBrushHandler()
    {}

// --------------------------------------------------------------------------
// CTestCAlfFrameBrushHandler::TestProtectedL
// --------------------------------------------------------------------------
//
TInt CTestCAlfFrameBrushHandler::TestProtectedL(
        CStifItemParser& /*aItem*/ )
    {
    THuiInterfaceSupport interface = EAlfBrushHandler;
    GetInterface( interface );
    TInt cmd = EAlfFrameBrushSetEdgeOffsetMetric;
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    HandleCmdL( cmd, input, response );
    TUid uid = { 0x00000001 };
    TAny** extent = NULL;
    BrushHandlerExtension( uid, extent );
    Release();
    return KErrNone;
    }

// End of file

