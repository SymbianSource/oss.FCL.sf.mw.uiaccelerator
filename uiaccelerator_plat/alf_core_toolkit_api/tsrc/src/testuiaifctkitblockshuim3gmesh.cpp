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
#include <uiacceltk/huim3gmesh.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huilayout.h>
#include <uiacceltk/huimeshvisual.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHM3GMLoadSceneL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHM3GMLoadSceneL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiM3GMesh, "In TestCHM3GMLoadSceneL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiM3GMesh );
    // Print to log file
    iLog->Log( KTestCHuiM3GMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiM3GMesh* mesh = visual->M3GMesh();
    TRAP_IGNORE( mesh->LoadSceneL( _L( "a" ) ) );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHM3GMSetAnimationPositionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHM3GMSetAnimationPositionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiM3GMesh, "In TestCHM3GMSetAnimationPositionL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiM3GMesh );
    // Print to log file
    iLog->Log( KTestCHuiM3GMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiM3GMesh* mesh = visual->M3GMesh();
    mesh->SetAnimationPosition( 0, 0, 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHM3GMStartAnimationControllerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHM3GMStartAnimationControllerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiM3GMesh, "In TestCHM3GMStartAnimationControllerL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiM3GMesh );
    // Print to log file
    iLog->Log( KTestCHuiM3GMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiM3GMesh* mesh = visual->M3GMesh();
    mesh->StartAnimationController( 0 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHM3GMStopAnimationControllerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHM3GMStopAnimationControllerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiM3GMesh, "In TestCHM3GMStopAnimationControllerL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiM3GMesh );
    // Print to log file
    iLog->Log( KTestCHuiM3GMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiM3GMesh* mesh = visual->M3GMesh();
    mesh->StartAnimationController( 0 );
    mesh->StopAnimationController( 0 );

    return KErrNone;
    }
