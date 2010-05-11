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



// [INCLUDE FILES]
#include <e32svr.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huicontrolgroup.h>
#include <uiacceltk/huivisual.h>
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huievent.h>
#include <eikenv.h>
#include <e32err.h>

#include "testuiaifcoretoolkit.h"
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlGroupAppendL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlGroupAppendL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlGroupAppendL, "In TestCHuiCntlGroupAppendL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlGroupAppendL );
    // Print to log file
    iLog->Log( KTestCHuiCntlGroupAppendL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlGroupAppendAndPopL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlGroupAppendAndPopL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlGroupAppendAndPopL, "In TestCHuiCntlGroupAppendAndPopL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlGroupAppendAndPopL );
    // Print to log file
    iLog->Log( KTestCHuiCntlGroupAppendAndPopL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendAndPopL( otherControl );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlGroupRemoveL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlGroupRemoveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlGroupRemoveL, "In TestCHuiCntlGroupRemoveL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlGroupRemoveL );
    // Print to log file
    iLog->Log( KTestCHuiCntlGroupRemoveL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendAndPopL( otherControl );
    iHuiControlGroup->Remove( otherControl );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlCountL, "In TestCHuiCntlCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlCountL );
    // Print to log file
    iLog->Log( KTestCHuiCntlCountL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    iHuiControlGroup->AppendL( otherControl );
    TInt count = iHuiControlGroup->Count();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlControlL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlControlL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlControlL, "In TestCHuiCntlControlL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlControlL );
    // Print to log file
    iLog->Log( KTestCHuiCntlControlL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TInt count = iHuiControlGroup->Count();
    CHuiControl& control = iHuiControlGroup->Control( 0 );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlFindControlL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlFindControlL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlFindControlL, "In TestCHuiCntlFindControlL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlFindControlL );
    // Print to log file
    iLog->Log( KTestCHuiCntlFindControlL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TInt count = iHuiControlGroup->Count();
    CHuiControl& control = iHuiControlGroup->Control( 0 );
    otherControl->SetId( 1 );
    CHuiControl* control2 = iHuiControlGroup->FindControl( 1 );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlEnableTsfomatonL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlEnableTsfomatonL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlEnableTsfomatonL, "In TestCHuiCntlEnableTsfomatonL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlEnableTsfomatonL );
    // Print to log file
    iLog->Log( KTestCHuiCntlEnableTsfomatonL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    iHuiControlGroup->EnableTransformationL();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlIsTransformedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlIsTransformedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlIsTransformedL, "In TestCHuiCntlIsTransformedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlIsTransformedL );
    // Print to log file
    iLog->Log( KTestCHuiCntlIsTransformedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TBool isTransformed = iHuiControlGroup->IsTransformed();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlTransformationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlTransformationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlTransformationL, "In TestCHuiCntlTransformationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlTransformationL );
    // Print to log file
    iLog->Log( KTestCHuiCntlTransformationL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TBool isTransformed = iHuiControlGroup->IsTransformed();
    iHuiControlGroup->EnableTransformationL( ETrue );
    CHuiTransformation& transformation = iHuiControlGroup->Transformation();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlAcceptInputL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlAcceptInputL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlAcceptInputL, "In TestCHuiCntlAcceptInputL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlAcceptInputL );
    // Print to log file
    iLog->Log( KTestCHuiCntlAcceptInputL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TBool isTransformed = iHuiControlGroup->IsTransformed();
    iHuiControlGroup->EnableTransformationL( ETrue );
    CHuiTransformation& transformation = iHuiControlGroup->Transformation();
    TBool isAcceptInput = iHuiControlGroup->AcceptInput();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlSetAcceptInputL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlSetAcceptInputL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlSetAcceptInputL, "In TestCHuiCntlSetAcceptInputL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlSetAcceptInputL );
    // Print to log file
    iLog->Log( KTestCHuiCntlSetAcceptInputL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TBool isTransformed = iHuiControlGroup->IsTransformed();
    iHuiControlGroup->EnableTransformationL( ETrue );
    CHuiTransformation& transformation = iHuiControlGroup->Transformation();
    TBool isAcceptInput = iHuiControlGroup->AcceptInput();
    iHuiControlGroup->SetAcceptInput( ETrue );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlTypeL, "In TestCHuiCntlChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlTypeL );
    // Print to log file
    iLog->Log( KTestCHuiCntlTypeL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TBool isTransformed = iHuiControlGroup->IsTransformed();
    iHuiControlGroup->EnableTransformationL( ETrue );
    CHuiTransformation& transformation = iHuiControlGroup->Transformation();
    TBool isAcceptInput = iHuiControlGroup->AcceptInput();
    iHuiControlGroup->SetAcceptInput( ETrue );
    iHuiControlGroup->Type();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlSessionIdL, "In TestCHuiCntlSessionIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlSessionIdL );
    // Print to log file
    iLog->Log( KTestCHuiCntlSessionIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    TBool isTransformed = iHuiControlGroup->IsTransformed();
    iHuiControlGroup->EnableTransformationL( ETrue );
    CHuiTransformation& transformation = iHuiControlGroup->Transformation();
    TBool isAcceptInput = iHuiControlGroup->AcceptInput();
    iHuiControlGroup->SetAcceptInput( ETrue );
    iHuiControlGroup->Type();
    TInt sessionId = iHuiControlGroup->SessionId();
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCntlSetSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCntlSetSessionIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCntlSetSessionIdL, "In TestCHuiCntlSetSessionIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCntlSetSessionIdL );
    // Print to log file
    iLog->Log( KTestCHuiCntlSetSessionIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* otherControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( otherControl );
    CleanupStack::PushL( otherControl );
    iHuiControl->SetId( 0 );
    STIF_ASSERT_NOT_NULL( iHuiControlGroup );
    iHuiControlGroup->AppendL( otherControl );
    iHuiControlGroup->IsTransformed();
    iHuiControlGroup->EnableTransformationL( ETrue );
    iHuiControlGroup->Transformation();
    iHuiControlGroup->AcceptInput();
    iHuiControlGroup->SetAcceptInput( ETrue );
    iHuiControlGroup->Type();
    TInt sessionId = iHuiControlGroup->SessionId();
    iHuiControlGroup->SetSessionId( sessionId );
    CleanupStack::Pop( 1 );

    return KErrNone;
    
    }

//  [End of File]
