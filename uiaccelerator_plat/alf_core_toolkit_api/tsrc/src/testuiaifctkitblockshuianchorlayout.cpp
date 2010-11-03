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
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>

#include "testuiaifcoretoolkit.h"
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayAddNewL, "In TestCHuiAnLayAddNewL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayAddNewL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayAddNewL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayDestructL, "In TestCHuiAnLayDestructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayDestructL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayDestructL );

    
    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayResetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayResetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayResetL, "In TestCHuiAnLayResetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayResetL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayResetL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    iAnchorLayout->Reset();
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLaySetAnchorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLaySetAnchorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLaySetAnchorL, "In TestCHuiAnLaySetAnchorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLaySetAnchorL );
    // Print to log file
    iLog->Log( KTestCHuiAnLaySetAnchorL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    const TInt KChildOne = 0;
    const THuiTimedPoint KBottomRightDefinitionTwo(0.8f, 0.7f);
    iAnchorLayout->SetAnchor(EHuiAnchorBottomRight, KChildOne,
                      EHuiAnchorOriginLeft, EHuiAnchorOriginTop,
                      EHuiAnchorMetricRelativeToSize,
                      EHuiAnchorMetricRelativeToSize,
                      KBottomRightDefinitionTwo);

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLaySetRelativeAnchorRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLaySetRelativeAnchorRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLaySetRelativeAnchorRectL, "In TestCHuiAnLaySetRelativeAnchorRectL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLaySetRelativeAnchorRectL );
    // Print to log file
    iLog->Log( KTestCHuiAnLaySetRelativeAnchorRectL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    const THuiRealPoint KTopLeftDefinitionOne(0.2f, 0.3f); 
    const THuiRealPoint KBottomRightDefinitionOne(-0.3f, -0.2f);    
    const TInt KChildOne = 0;
    iAnchorLayout->SetRelativeAnchorRect(KChildOne, EHuiAnchorOriginLeft,  EHuiAnchorOriginTop,    KTopLeftDefinitionOne,
                                             EHuiAnchorOriginRight, EHuiAnchorOriginBottom, KBottomRightDefinitionOne );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayRemoveAnchorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayRemoveAnchorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayRemoveAnchorL, "In TestCHuiAnLayRemoveAnchorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayRemoveAnchorL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayRemoveAnchorL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    iAnchorLayout->RemoveAnchor( EHuiAnchorTopLeft, 0 );
    iAnchorLayout->RemoveAnchor( EHuiAnchorBottomRight, 0 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayAttachOriginL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayAttachOriginL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayAttachOriginL, "In TestCHuiAnLayAttachOriginL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayAttachOriginL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayAttachOriginL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    THuiMetric offset;
    iAnchorLayout->Attach( 0, EHuiAnchorTypeWidth, offset, EHuiAnchorAttachmentOriginLeft );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayAttachOriginTopLeftL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayAttachOriginTopLeftL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayAttachOriginTopLeftL, "In TestCHuiAnLayAttachOriginTopLeftL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayAttachOriginTopLeftL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayAttachOriginTopLeftL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    THuiXYMetric offset;
    iAnchorLayout->Attach( 0, EHuiAnchorTypeWidth, offset );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayAttachOriginNoneL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayAttachOriginNoneL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayAttachOriginNoneL, "In TestCHuiAnLayAttachOriginNoneL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayAttachOriginNoneL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayAttachOriginNoneL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    THuiBoxMetric offset;
    iAnchorLayout->Attach( 0, offset );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayDetachL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayDetachL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayDetachL, "In TestCHuiAnLayDetachL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayDetachL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayDetachL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    iAnchorLayout->Detach( 0 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayDetachAnchorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayDetachAnchorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayDetachAnchorL, "In TestCHuiAnLayDetachAnchorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayDetachAnchorL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayDetachAnchorL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    iAnchorLayout->Detach( 0, EHuiAnchorTypeLeft );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLaySetSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLaySetSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLaySetSizeL, "In TestCHuiAnLaySetSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLaySetSizeL );
    // Print to log file
    iLog->Log( KTestCHuiAnLaySetSizeL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    THuiRealSize size;
    iAnchorLayout->SetSize( size, 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayChildSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayChildSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayChildSizeL, "In TestCHuiAnLayChildSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayChildSizeL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayChildSizeL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    TSize size;
    iAnchorLayout->ChildSize( 0, size );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayChildPosL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayChildPosL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayChildPosL, "In TestCHuiAnLayChildPosL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayChildPosL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayChildPosL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    TPoint aPos;
    iAnchorLayout->ChildPos( 0, aPos );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiAnLayChildRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiAnLayChildRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiAnLayChildRectL, "In TestCHuiAnLayChildRectL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiAnLayChildRectL );
    // Print to log file
    iLog->Log( KTestCHuiAnLayChildRectL );

    CHuiAnchorLayout* iAnchorLayout = CHuiAnchorLayout::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( iAnchorLayout );
    THuiRealRect aRect;
    iAnchorLayout->ChildRect( 0, aRect );
    
    return KErrNone;
    }

//  [End of File]
