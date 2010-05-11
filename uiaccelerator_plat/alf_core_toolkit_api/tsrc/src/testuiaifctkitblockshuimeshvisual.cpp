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

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualAddNewL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualCreateMeshL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualCreateMeshL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualCreateMeshL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    visual->CreateMeshL( EHuiMeshTypeProcedural );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualSetImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualSetImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualSetImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );

    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    visual->SetImage( *image );
    CleanupStack::Pop( image );
    delete image;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualSetSecondaryImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualSetSecondaryImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualSetSecondaryImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );

    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    visual->SetSecondaryImage( *image );
    CleanupStack::Pop( image );
    delete image;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualSetSpecularImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualSetSpecularImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualSetSpecularImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );

    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    THuiImage* image = new( ELeave ) THuiImage();
    CleanupStack::PushL( image );
    visual->SetSpecularImage( *image );
    CleanupStack::Pop( image );
    delete image;

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualMeshL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualMeshL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualMeshL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );
    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    visual->Mesh();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualProceduralMeshL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualProceduralMeshL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualProceduralMeshL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );

    CHuiMeshVisual* visual =
        CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeProcedural, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiProceduralMesh* mesh = visual->ProceduralMesh();
    STIF_ASSERT_NOT_NULL( mesh );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiMeshVisualM3GMeshL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiMeshVisualM3GMeshL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiMesh, "In TestCHuiMeshVisualM3GMeshL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KTestCHuiMesh );
    // Print to log file
    iLog->Log( KTestCHuiMesh );

    CHuiLayout* layout = CHuiLayout::AddNewL( *iHuiControl );

    CHuiMeshVisual* visual = CHuiMeshVisual::AddNewL( *iHuiControl, EHuiMeshTypeM3G, layout );
    STIF_ASSERT_NOT_NULL( visual );
    CHuiM3GMesh* mesh = visual->M3GMesh();
    STIF_ASSERT_NOT_NULL( mesh );

    return KErrNone;
    }
