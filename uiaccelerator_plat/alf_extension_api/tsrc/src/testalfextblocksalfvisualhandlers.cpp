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
* Description:  Test alfvisualhandlers.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"
#include "testalfvisualhandlers.h"

// CONSTANTS
const TInt KBufSize = 64;
// ============================ MEMBER FUNCTIONS =========================


// --------------------------------------------------------------------------
// CTestAlfExt::TestVisualHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestVisualHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlernewl, "In TestCAlfVisualHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlernewl);
    iLog->Log(Ktestcalfvisualhandlernewl);

    CAlfVisualHandler*handler = new ( ELeave ) CAlfVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfVisualEnableDropShadow;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfVisualHandler*>
        ( CAlfVisualHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestVisualHandlerMutualL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestVisualHandlerMutualL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlercalfvisualhandler, "In TestCAlfVisualHandlerCAlfVisualHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlercalfvisualhandler);
    iLog->Log(Ktestcalfvisualhandlercalfvisualhandler);

    CTestCAlfVisualHandler*handler = new ( ELeave ) 
        CTestCAlfVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtected( aItem );
    CleanupStack::Pop(handler );

    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestAlfExt::TestTextVisualHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestTextVisualHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlernewl, "In TestCAlfVisualHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlernewl);
    iLog->Log(Ktestcalfvisualhandlernewl);

    CAlfTextVisualHandler*handler = new ( ELeave ) 
        CAlfTextVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfTextVisualSetText;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfTextVisualHandler*>
        ( CAlfTextVisualHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestTextVisualHandlerMutualL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestTextVisualHandlerMutualL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlercalfvisualhandler, "In TestCAlfVisualHandlerCAlfVisualHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlercalfvisualhandler);
    iLog->Log(Ktestcalfvisualhandlercalfvisualhandler);

    CTestCAlfTextVisualHandler*handler = new ( ELeave ) 
        CTestCAlfTextVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtected( aItem );
    CleanupStack::Pop(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLCTTextVisualHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLCTTextVisualHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlernewl, "In TestCAlfVisualHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlernewl);
    iLog->Log(Ktestcalfvisualhandlernewl);

    CAlfLCTTextVisualHandler*handler = new ( ELeave ) 
        CAlfLCTTextVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfTextVisualSetText;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfLCTTextVisualHandler*>
        ( CAlfLCTTextVisualHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLCTTextVisualHandlerMutualL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLCTTextVisualHandlerMutualL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlercalfvisualhandler, "In TestCAlfVisualHandlerCAlfVisualHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlercalfvisualhandler);
    iLog->Log(Ktestcalfvisualhandlercalfvisualhandler);

    CTestCAlfLCTTextVisualHandler*handler = new ( ELeave ) 
        CTestCAlfLCTTextVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtected( aItem );
    CleanupStack::Pop(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestImageVisualHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestImageVisualHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlernewl, "In TestCAlfVisualHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlernewl);
    iLog->Log(Ktestcalfvisualhandlernewl);

    CAlfImageVisualHandler*handler = new ( ELeave ) 
        CAlfImageVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfImageVisualSetOffset;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfImageVisualHandler*>
        ( CAlfImageVisualHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestImageVisualHandlerMutualL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestImageVisualHandlerMutualL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlercalfvisualhandler, "In TestCAlfVisualHandlerCAlfVisualHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlercalfvisualhandler);
    iLog->Log(Ktestcalfvisualhandlercalfvisualhandler);

    CTestCAlfImageVisualHandler*handler = new ( ELeave ) 
        CTestCAlfImageVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtected( aItem );
    CleanupStack::Pop(handler );

    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestAlfExt::TestLineVisualHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLineVisualHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlernewl, "In TestCAlfVisualHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlernewl);
    iLog->Log(Ktestcalfvisualhandlernewl);

    CAlfLineVisualHandler*handler = new ( ELeave ) 
        CAlfLineVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfVisualSetSize;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfLineVisualHandler*>
        ( CAlfLineVisualHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLineVisualHandlerMutualL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLineVisualHandlerMutualL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlercalfvisualhandler, "In TestCAlfVisualHandlerCAlfVisualHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlercalfvisualhandler);
    iLog->Log(Ktestcalfvisualhandlercalfvisualhandler);

    CTestCAlfLineVisualHandler*handler = new ( ELeave ) 
        CTestCAlfLineVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtected( aItem );
    CleanupStack::Pop(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestMeshVisualHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestMeshVisualHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlernewl, "In TestCAlfVisualHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlernewl);
    iLog->Log(Ktestcalfvisualhandlernewl);

    CAlfMeshVisualHandler*handler = new ( ELeave ) 
        CAlfMeshVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, EHuiMeshTypeM3G, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfVisualSetSize;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfMeshVisualHandler*>
        ( CAlfMeshVisualHandler::NewL( *iInterface, iHuiControl, 
                EHuiMeshTypeM3G, NULL ) );
    CleanupStack::PushL(handler );
    handler->Release();
    CleanupStack::Pop(handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestMeshVisualHandlerMutualL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestMeshVisualHandlerMutualL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfvisualhandlercalfvisualhandler, "In TestCAlfVisualHandlerCAlfVisualHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfvisualhandlercalfvisualhandler);
    iLog->Log(Ktestcalfvisualhandlercalfvisualhandler);

    CTestCAlfMeshVisualHandler*handler = new ( ELeave ) 
        CTestCAlfMeshVisualHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, EHuiMeshTypeM3G, NULL );
    handler->TestProtected( aItem );
    CleanupStack::Pop(handler );

    return KErrNone;
    }
// End of file


