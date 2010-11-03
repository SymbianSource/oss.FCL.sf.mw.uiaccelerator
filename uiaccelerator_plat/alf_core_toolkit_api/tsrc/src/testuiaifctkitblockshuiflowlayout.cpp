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
* Description:  for testing the method of the CHuiTextVisual
*
*/

#include <uiacceltk\huiflowlayout.h>

#include "testuiaifcoretoolkit.h"

const TInt KWidth = 10;
const TInt KHeight = 10;

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutAddNewL, "In TestHuiFlowLayoutAddNewL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutAddNewL );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutAddNewL );
    
    TRAPD( error, iHuiFlowLayout = iHuiFlowLayout->AddNewL( *iHuiControl, CHuiFlowLayout::EFlowHorizontal ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutDelete
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutDelete( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutDelete, "In TestHuiFlowLayoutDelete" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutDelete );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutDelete );
    
    delete iHuiFlowLayout;
    iHuiFlowLayout = NULL;

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutSetSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutSetSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutSetSize, "In TestHuiFlowLayoutSetSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutSetSize );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutSetSize );
    
    THuiRealSize size( KWidth, KHeight );
    
    iHuiFlowLayout->SetSize( size );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutSetFlowDirection
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutSetFlowDirection( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutSetFlowDirection, "In TestHuiFlowLayoutSetFlowDirection" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutSetFlowDirection );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutSetFlowDirection );
    
    iHuiFlowLayout->SetFlowDirection( CHuiFlowLayout::EFlowHorizontal );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutSetCentering
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutSetCentering( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutSetCentering, "In TestHuiFlowLayoutSetCentering" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutSetCentering );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutSetCentering );
    
    iHuiFlowLayout->SetCentering( ETrue );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutSetMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutSetMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutSetMode, "In TestHuiFlowLayoutSetMode" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutSetMode );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutSetMode );
    
    iHuiFlowLayout->SetMode( CHuiFlowLayout::EModeCenterPerpendicular );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiFlowLayoutMode
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiFlowLayoutMode( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiFlowLayoutMode, "In TestHuiFlowLayoutMode" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiFlowLayoutMode );
    // Print to log file
    iLog->Log( KTestHuiFlowLayoutMode );
    
    iHuiFlowLayout->Mode();

    return KErrNone;

    }

// End of file
