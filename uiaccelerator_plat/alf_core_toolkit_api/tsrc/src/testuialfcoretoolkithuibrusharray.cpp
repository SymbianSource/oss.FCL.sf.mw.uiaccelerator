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
* Description:  For test alf core toolkit api modules
*
*/


#include <uiacceltk/huiBrushArray.h>
#include <uiacceltk/HuiBorderBrush.h>
#include <uiacceltk/huidisplaycoecontrol.h>


#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayNewLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayNewLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayNewLL, "TestHuiBrushArrayNewLL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayNewLL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayNewLL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewL();
    CleanupStack::PushL( huiBrushArray );
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayNewLCL, "TestHuiBrushArrayNewLCL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayNewLCL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayNewLCL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayResetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayResetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayResetL, "TestHuiBrushArrayResetL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayResetL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayResetL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    huiBrushArray->Reset();
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayAppendL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayAppendL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayAppendL, "TestHuiBrushArrayAppendL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayAppendL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayAppendL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CHuiBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    THuiOwnership value = EHuiDoesNotHaveOwnership;
    huiBrushArray->AppendL( brush, value );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayInsertL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayInsertL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayInsertL, "TestHuiBrushArrayInsertL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayInsertL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayInsertL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CHuiBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    THuiOwnership value = EHuiDoesNotHaveOwnership;
    huiBrushArray->InsertL( 0, brush, value );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayRemoveL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayRemoveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayRemoveL, "TestHuiBrushArrayRemoveL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayRemoveL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayRemoveL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CHuiBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    THuiOwnership value = EHuiDoesNotHaveOwnership;
    huiBrushArray->AppendL( brush, value );
    huiBrushArray->Remove( 0 );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayCountL, "TestHuiBrushArrayCountL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayCountL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayCountL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    huiBrushArray->Count();
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayOperatorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayOperatorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayOperatorL, "TestHuiBrushArrayOperatorL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayOperatorL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayOperatorL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CHuiBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    THuiOwnership value = EHuiDoesNotHaveOwnership;
    huiBrushArray->AppendL( brush, value );
    CHuiBrush& huiBrush = huiBrushArray->operator []( 0 );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayAtL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayAtL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayAtL, "TestHuiBrushArrayAtL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayAtL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayAtL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    CHuiBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    THuiOwnership value = EHuiDoesNotHaveOwnership;
    huiBrushArray->AppendL( brush, value );
    CHuiBrush& huiBrush = huiBrushArray->At( 0 );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayLayerBrushCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayLayerBrushCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayLayerBrushCountL, "TestHuiBrushArrayLayerBrushCountL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayLayerBrushCountL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayLayerBrushCountL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    THuiBrushLayer layer = EHuiBrushLayerBackground;
    huiBrushArray->LayerBrushCount( layer );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }
// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiBrushArrayDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiBrushArrayDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiBrushArrayDrawL, "TestHuiBrushArrayDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiBrushArrayDrawL );
    // Print to log file
    iLog->Log( KTestHuiBrushArrayDrawL );

    CHuiBrushArray* huiBrushArray = CHuiBrushArray::NewLC();
    STIF_ASSERT_NOT_NULL( huiBrushArray );
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    CleanupStack::PushL( ctrl );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    CHuiGc& huiGc = iHuiEnv->Skin().Context();
    huiBrushArray->Draw( EHuiBrushLayerBackground, huiGc, *iHuiVisual );
    huiBrushArray->Draw( EHuiBrushLayerForeground, huiGc, *iHuiVisual );
    CleanupStack::PopAndDestroy( ctrl );
    CleanupStack::PopAndDestroy( huiBrushArray );
    
    return KErrNone;

    }

//End of file.
