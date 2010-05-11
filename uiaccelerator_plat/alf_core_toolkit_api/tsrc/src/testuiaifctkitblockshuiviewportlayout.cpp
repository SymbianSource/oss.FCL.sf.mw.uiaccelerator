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
* Description:  for testing the method of the CHuiVisual
*
*/

#include <uiacceltk\huiviewportlayout.h>

#include "testuiaifcoretoolkit.h"

const TInt KLength = 10;
const TInt KWidth = 5;


// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiViewPortLayoutAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiViewPortLayoutAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiViewPortLayoutAddNewL, "In TestHuiViewPortLayoutAddNewL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiViewPortLayoutAddNewL );
    // Print to log file
    iLog->Log( KTestHuiViewPortLayoutAddNewL );
    
    iHuiViewPortLayout = CHuiViewportLayout::AddNewL( *iHuiControl );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiViewPortLayoutSetVirtualSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiViewPortLayoutSetVirtualSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiViewPortLayoutSetVirtualSize, "In TestHuiViewPortLayoutSetVirtualSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiViewPortLayoutSetVirtualSize );
    // Print to log file
    iLog->Log( KTestHuiViewPortLayoutSetVirtualSize );
    
    THuiRealSize size( KLength, KWidth );
    
    iHuiViewPortLayout->SetVirtualSize( size );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiViewPortLayoutSetViewportSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiViewPortLayoutSetViewportSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiViewPortLayoutSetViewportSize, "In TestHuiViewPortLayoutSetViewportSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiViewPortLayoutSetViewportSize );
    // Print to log file
    iLog->Log( KTestHuiViewPortLayoutSetViewportSize );
    
    THuiRealSize size( KLength, KWidth );
    
    iHuiViewPortLayout->SetViewportSize( size );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiViewPortLayoutSetViewportPos
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiViewPortLayoutSetViewportPos( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiViewPortLayoutSetViewportPos, "In TestHuiViewPortLayoutSetViewportPos" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiViewPortLayoutSetViewportPos );
    // Print to log file
    iLog->Log( KTestHuiViewPortLayoutSetViewportPos );

    THuiRealPoint point( 0, 0 );
    
    iHuiViewPortLayout->SetViewportPos( point );

    return KErrNone;

    }
// End of file
