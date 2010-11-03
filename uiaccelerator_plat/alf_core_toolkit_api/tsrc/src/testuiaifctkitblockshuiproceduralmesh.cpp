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
#include <uiacceltk/huiproceduralmesh.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huilayout.h>
#include <uiacceltk/huimeshvisual.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMDeleteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMDeleteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMDeleteL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMResetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMResetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMDeleteL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    mesh->Reset();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMMakeCubeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMMakeCubeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMMakeCubeL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    mesh->MakeCubeL( 1, 1, 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMMakeSphereL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMMakeSphereL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMMakeSphereL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    mesh->MakeSphereL( 1, 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMMakeTorusL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMMakeTorusL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMMakeTorusL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    mesh->MakeTorusL( 1, 1, 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMStretchUniformlyL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMStretchUniformlyL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMStretchUniformlyL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    mesh->StretchUniformly( 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHPMScaleUniformlyL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHPMScaleUniformlyL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiProceduralMesh, "In TestHPMScaleUniformlyL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiProceduralMesh );
    // Print to log file
    iLog->Log( KCHuiProceduralMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    mesh->ScaleUniformly( 0.1, 0.1, 0.1 );

    return KErrNone;
    }
