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
* Description:  Test alflayouthandlers.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"
#include "testalflayouthandlers.h"

// CONSTANTS
const TInt KBufSize = 64;
// ============================ MEMBER FUNCTIONS =========================


// --------------------------------------------------------------------------
// CTestAlfExt::TestLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfLayoutHandler*handler = new ( ELeave ) CAlfLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    _LIT8( KTest, "test" );
    TBuf8<KBufSize> input( KTest );
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfLayoutHandler*>
        ( CAlfLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestAnchorLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestAnchorLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfAnchorLayoutHandler*handler = new ( ELeave ) 
        CAlfAnchorLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfAnchorLayoutHandler*>
        ( CAlfAnchorLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestAnchorLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestAnchorLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfAnchorLayoutHandler*handler = new ( ELeave ) 
            CTestCAlfAnchorLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestAlfExt::TestLCTAnchorLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLCTAnchorLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfLCTAnchorLayoutHandler*handler = new ( ELeave ) 
        CAlfLCTAnchorLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfLCTAnchorLayoutHandler*>
        ( CAlfLCTAnchorLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLCTAnchorLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLCTAnchorLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfLCTAnchorLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfLCTAnchorLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestAlfExt::TestGridLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestGridLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfGridLayoutHandler*handler = new ( ELeave ) 
        CAlfGridLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfGridLayoutHandler*>
        ( CAlfGridLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestGridLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestGridLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfGridLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfGridLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLCTGridLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLCTGridLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfLCTGridLayoutHandler*handler = new ( ELeave ) 
        CAlfLCTGridLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfLCTGridLayoutHandler*>
        ( CAlfLCTGridLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestLCTGridLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestLCTGridLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfLCTGridLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfLCTGridLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestDeckLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestDeckLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfDeckLayoutHandler*handler = new ( ELeave ) 
        CAlfDeckLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfDeckLayoutHandler*>
        ( CAlfDeckLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestDeckLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestDeckLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfDeckLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfDeckLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestFlowLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestFlowLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfFlowLayoutHandler*handler = new ( ELeave ) 
        CAlfFlowLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfFlowLayoutHandler*>
        ( CAlfFlowLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestFlowLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestFlowLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfFlowLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfFlowLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestCurvePathLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestCurvePathLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfCurvePathLayoutHandler*handler = new ( ELeave ) 
        CAlfCurvePathLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfCurvePathLayoutHandler*>
        ( CAlfCurvePathLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestCurvePathLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestCurvePathLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfCurvePathLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfCurvePathLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestViewportLayoutHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestViewportLayoutHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlernewl, "In TestCAlfLayoutHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlernewl);
    iLog->Log(Ktestcalflayouthandlernewl);

    CAlfViewportLayoutHandler*handler = new ( ELeave ) 
            CAlfViewportLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    THuiInterfaceSupport interface = EAlfVisualHandler;
    TInt cmd = EAlfLayoutBaseUnit;
    TBuf8<KBufSize> input;
    TBuf8<KBufSize> response;
    handler->GetInterface( interface );
    handler->HandleCmdL( cmd, input, response );
    handler->Release();
    CleanupStack::Pop(handler );
    handler = NULL;
    handler = static_cast<CAlfViewportLayoutHandler*>
        ( CAlfViewportLayoutHandler::NewL( *iInterface, iHuiControl, NULL ) );
    CleanupStack::PushL(handler );
    CleanupStack::PopAndDestroy(handler );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestViewportLayoutHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestViewportLayoutHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalflayouthandlercalflayouthandler, "In TestCAlfLayoutHandlerCAlfLayoutHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalflayouthandlercalflayouthandler);
    iLog->Log(Ktestcalflayouthandlercalflayouthandler);

    CTestCAlfViewportLayoutHandler*handler = new ( ELeave ) 
        CTestCAlfViewportLayoutHandler( *iInterface );
    CleanupStack::PushL(handler );
    handler->ConstructL( iHuiVisual, *iHuiControl, NULL );
    handler->TestProtect( aItem );
    CleanupStack::PopAndDestroy(handler );

    return KErrNone;
    }

// End of file


