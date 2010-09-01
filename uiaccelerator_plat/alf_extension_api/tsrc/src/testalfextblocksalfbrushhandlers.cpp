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
* Description:  Test alfbrushhandlers.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"
#include "testalfbrushhandlers.h"


// ============================ MEMBER FUNCTIONS =========================


// --------------------------------------------------------------------------
// CTestAlfExt::TestBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfbrushhandlercalfbrushhandler, "In TestCAlfBrushHandlerCAlfBrushHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfbrushhandlercalfbrushhandler);
    iLog->Log(Ktestcalfbrushhandlercalfbrushhandler);
    
    CTestCAlfBrushHandler* handler = new ( ELeave ) 
        CTestCAlfBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    
    CleanupStack::PopAndDestroy( handler );
    
    return KErrNone;
    }


// --------------------------------------------------------------------------
// CTestAlfExt::TestBrushHandlerForMAlfExtensionL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestBrushHandlerForMAlfExtensionL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfbrushhandlerrelease, "In TestCAlfBrushHandlerRelease");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfbrushhandlerrelease);
    iLog->Log(Ktestcalfbrushhandlerrelease);

    CTestCAlfBrushHandler* handler = new ( ELeave ) 
        CTestCAlfBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    handler->ConstructL();
    handler->TestBrushHandlerForMAlfExtensionL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestBrushHandlerForOthersL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestBrushHandlerForOthersL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfbrushhandlergetinterface, "In TestCAlfBrushHandlerGetInterface");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfbrushhandlergetinterface);
    iLog->Log(Ktestcalfbrushhandlergetinterface);

    CTestCAlfBrushHandler* handler = new ( ELeave ) 
        CTestCAlfBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    handler->ConstructL();
    handler->SetOwnership( EFalse );
    handler->TestBrushHandlerForOthers( aItem );
    CleanupStack::PopAndDestroy( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestBorderBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestBorderBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfborderbrushhandlernewl1, "In TestCAlfBorderBrushHandlerNewL1");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfborderbrushhandlernewl1);
    iLog->Log(Ktestcalfborderbrushhandlernewl1);

    TAlfXYMetric thickness;
    TAlfXYMetric edgeOffset;
    
    MAlfExtension* temp = CAlfBorderBrushHandler::NewL( *iInterface, 
            thickness, edgeOffset );
    CAlfBorderBrushHandler* handler = static_cast<CAlfBorderBrushHandler*>
        ( temp );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, thickness, edgeOffset );
    CleanupStack::Pop( brush );
    CleanupStack::PopAndDestroy( handler );
    
    handler = NULL;
    handler = static_cast<CAlfBorderBrushHandler*>
        (CAlfBorderBrushHandler::NewL( *iInterface, 1, 1, 1, 1 ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush2 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush2 );
    handler->ConstructL( brush2, 1, 1, 1, 1 );
    CleanupStack::Pop( brush2 );
    CleanupStack::PopAndDestroy( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestBorderBrushHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestBorderBrushHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfborderbrushhandlernewl2, "In TestCAlfBorderBrushHandlerNewL2");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfborderbrushhandlernewl2);
    iLog->Log(Ktestcalfborderbrushhandlernewl2);

    CTestCAlfBorderBrushHandler* handler = new ( ELeave ) 
        CTestCAlfBorderBrushHandler ( *iInterface);
    CleanupStack::PushL( handler );
    TAlfXYMetric thickness;
    TAlfXYMetric edgeOffset;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, thickness, edgeOffset );
    CleanupStack::Pop( brush );
    handler->TestProtectedL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestImageBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestImageBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlernewl, "In TestCAlfImageBrushHandlerNewL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlernewl);
    iLog->Log(Ktestcalfimagebrushhandlernewl);

    THuiImage image;
    MAlfExtension* temp = CAlfImageBrushHandler::NewL( *iInterface, image );
    CAlfImageBrushHandler* handler = static_cast<CAlfImageBrushHandler*>
        ( temp );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, image );
    CleanupStack::Pop( brush );
    CleanupStack::PopAndDestroy( handler );
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestImageBrushHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestImageBrushHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlercalfimagebrushhandler, "In TestCAlfImageBrushHandlerCAlfImageBrushHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlercalfimagebrushhandler);
    iLog->Log(Ktestcalfimagebrushhandlercalfimagebrushhandler);

    CTestCAlfImageBrushHandler* handler = new ( ELeave ) 
        CTestCAlfImageBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    THuiImage image;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, image );
    CleanupStack::Pop( brush );
    handler->TestProtectedL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestShadowBorderBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestShadowBorderBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlerconstructl, "In TestCAlfImageBrushHandlerConstructL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlerconstructl);
    iLog->Log(Ktestcalfimagebrushhandlerconstructl);

    CAlfShadowBorderBrushHandler* handler = 
        static_cast<CAlfShadowBorderBrushHandler*>
        (CAlfShadowBorderBrushHandler::NewL( *iInterface, 1 ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, 1 );
    CleanupStack::Pop( brush );
    CleanupStack::PopAndDestroy( handler );
    handler = NULL;
    TAlfMetric metric;
    handler = static_cast<CAlfShadowBorderBrushHandler*>
            (CAlfShadowBorderBrushHandler::NewL( *iInterface, metric ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush1 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush1 );
    handler->ConstructL( brush1, metric );
    CleanupStack::Pop( brush1 );
    CleanupStack::PopAndDestroy( handler );
    
    handler = NULL;
    handler = new ( ELeave )CAlfShadowBorderBrushHandler( *iInterface);
    CleanupStack::PushL( handler );
    CleanupStack::PopAndDestroy( handler );
    
    
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestShadowBorderBrushHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestShadowBorderBrushHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlerrelease, "In TestCAlfImageBrushHandlerRelease");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlerrelease);
    iLog->Log(Ktestcalfimagebrushhandlerrelease);

    CTestCAlfShadowBorderBrushHandler* handler = new ( ELeave ) 
        CTestCAlfShadowBorderBrushHandler ( *iInterface );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush1 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush1 );
    TAlfMetric metric;
    handler->ConstructL( brush1, metric );
    CleanupStack::Pop( brush1 );
    handler->TestProtectedL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestDropShadowBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestDropShadowBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlergetinterface, "In TestCAlfImageBrushHandlerGetInterface");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlergetinterface);
    iLog->Log(Ktestcalfimagebrushhandlergetinterface);

    CAlfDropShadowBrushHandler* handler = 
            static_cast<CAlfDropShadowBrushHandler*>
            (CAlfDropShadowBrushHandler::NewL( *iInterface, 1 ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, 1 );
    CleanupStack::Pop( brush );
    CleanupStack::PopAndDestroy( handler );
    handler = NULL;
    TAlfMetric metric;
    handler = static_cast<CAlfDropShadowBrushHandler*>
            (CAlfDropShadowBrushHandler::NewL( *iInterface, metric ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush1 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush1, metric );
    CleanupStack::Pop( brush1 );
    CleanupStack::PopAndDestroy( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestDropShadowBrushHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestDropShadowBrushHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlerhandlecmdl, "In TestCAlfImageBrushHandlerHandleCmdL");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlerhandlecmdl);
    iLog->Log(Ktestcalfimagebrushhandlerhandlecmdl);

    CTestCAlfDropShadowBrushHandler* handler = new ( ELeave ) 
            CTestCAlfDropShadowBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    TAlfMetric metric;
    CHuiBorderBrush* brush1 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush1 );
    handler->ConstructL( brush1, metric );
    CleanupStack::Pop( brush1 );
    handler->TestProtectedL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestGradientBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestGradientBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfimagebrushhandlerbrushhandlerextension, "In TestCAlfImageBrushHandlerBrushHandlerExtension");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfimagebrushhandlerbrushhandlerextension);
    iLog->Log(Ktestcalfimagebrushhandlerbrushhandlerextension);

    CAlfGradientBrushHandler* handler = static_cast<CAlfGradientBrushHandler*>
        ( CAlfGradientBrushHandler::NewL( *iInterface ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush );
    CleanupStack::Pop( brush );
    CleanupStack::PopAndDestroy( handler );
    handler = NULL;
    handler = new ( ELeave ) CAlfGradientBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    CleanupStack::PopAndDestroy( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestGradientBrushHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestGradientBrushHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfshadowborderbrushhandlernewl1, "In TestCAlfShadowBorderBrushHandlerNewL1");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfshadowborderbrushhandlernewl1);
    iLog->Log(Ktestcalfshadowborderbrushhandlernewl1);

    CTestCAlfGradientBrushHandler* handler = new ( ELeave ) 
            CTestCAlfGradientBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush );
    CleanupStack::Pop( brush );
    handler->TestProtectedL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestFrameBrushHandlerConstructL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestFrameBrushHandlerConstructL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfshadowborderbrushhandlernewl2, "In TestCAlfShadowBorderBrushHandlerNewL2");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfshadowborderbrushhandlernewl2);
    iLog->Log(Ktestcalfshadowborderbrushhandlernewl2);
    
    TAknsItemID id;
    TAlfXYMetric edgeOffset;
    CAlfFrameBrushHandler* handler = static_cast<CAlfFrameBrushHandler*>
        ( CAlfFrameBrushHandler::NewL( *iInterface, id, edgeOffset ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush );
    handler->ConstructL( brush, id, edgeOffset );
    CleanupStack::Pop( brush );
    CleanupStack::PopAndDestroy( handler );
    handler = NULL;
    handler = static_cast<CAlfFrameBrushHandler*>
            ( CAlfFrameBrushHandler::NewL( *iInterface, id, 1, 1 ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush1 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush1 );
    handler->ConstructL( brush1, id, 1, 1 );
    CleanupStack::Pop( brush1 );
    CleanupStack::PopAndDestroy( handler );
    handler = NULL;
    THuiImage image;
    handler = static_cast<CAlfFrameBrushHandler*>
            ( CAlfFrameBrushHandler::NewL( *iInterface, image, edgeOffset ) );
    CleanupStack::PushL( handler );
    CHuiBorderBrush* brush2 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush2 );
    handler->ConstructL( brush2, image, edgeOffset );
    CleanupStack::Pop( brush2 );
    CleanupStack::PopAndDestroy( handler );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestFrameBrushHandlerProtectedL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestFrameBrushHandlerProtectedL( CStifItemParser& aItem )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestcalfshadowborderbrushhandlercalfshadowborderbrushhandler, "In TestCAlfShadowBorderBrushHandlerCAlfShadowBorderBrushHandler");
    TestModuleIf().Printf(0, Kctestalfext, Ktestcalfshadowborderbrushhandlercalfshadowborderbrushhandler);
    iLog->Log(Ktestcalfshadowborderbrushhandlercalfshadowborderbrushhandler);

    CTestCAlfFrameBrushHandler* handler = new ( ELeave ) 
        CTestCAlfFrameBrushHandler( *iInterface );
    CleanupStack::PushL( handler );
    TAknsItemID id;
    CHuiBorderBrush* brush1 = CHuiBorderBrush::NewL( 1, 1, 1, 1 );
    CleanupStack::PushL( brush1 );
    handler->ConstructL( brush1, id, 1, 1 );
    CleanupStack::Pop( brush1 );
    handler->TestProtectedL( aItem );
    CleanupStack::Pop( handler );

    return KErrNone;
    }

// End of file


