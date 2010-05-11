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
#include <uiacceltk/huimesh.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huilayout.h>
#include <uiacceltk/huimeshvisual.h>
#include <uiacceltk/huistatic.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshNewLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshNewLCL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewLC( EHuiMeshTypeProcedural );
    STIF_ASSERT_NOT_NULL( mesh );
    CleanupStack::Pop();
    delete mesh;
    mesh = NULL;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshDestructL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshMeshTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshMeshTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshMeshTypeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    THuiMeshType type = mesh->MeshType();
    STIF_ASSERT_TRUE( type == EHuiMeshTypeProcedural );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshResetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshResetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshResetL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->Reset();
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshStretchUniformlyL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshStretchUniformlyL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshStretchUniformlyL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->StretchUniformly( 0, 0, 0, 0, 0, 0 );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshScaleUniformlyL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshScaleUniformlyL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshScaleUniformlyL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->ScaleUniformly( 0, 0, 0 );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshTypeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->Type();
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshSessionIdL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->SessionId();
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshSetSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshSetSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshSetSessionIdL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->SetSessionId( 1 );
    TInt id = mesh->SessionId();
    STIF_ASSERT_EQUALS( id , 1 );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshAnimationControllerCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshAnimationControllerCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshAnimationControllerCountL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->AnimationControllerCount();
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshSetAnimationPositionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshSetAnimationPositionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshSetAnimationPositionL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->SetAnimationPosition( 0 ,0 ,0 );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshStartAnimationControllerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshStartAnimationControllerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshStartAnimationControllerL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->StartAnimationController( 0 );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshStopAnimationControllerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshStopAnimationControllerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshStopAnimationControllerL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiMesh* mesh = CHuiMesh::NewL( EHuiMeshTypeProcedural );
    CleanupStack::PushL( mesh );
    STIF_ASSERT_NOT_NULL( mesh );
    mesh->StartAnimationController( 0 );
    mesh->StopAnimationController( 0 );
    CleanupStack::PopAndDestroy( mesh );

    return KErrNone;
    }
