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
#include <uiacceltk/HuiDisplayCoeControl.h>
#include <uiacceltk/HuiDeckLayout.h>


#include "testuiaifcoretoolkit.h"
#include "testuiaifblockshuicontrolchild.h"
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlL, "In TestCHuiControlL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlL );
    // Print to log file
    iLog->Log( KTestCHuiControlL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlDestructL, "In TestCHuiControlDestructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlDestructL );
    // Print to log file
    iLog->Log( KTestCHuiControlDestructL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlSetIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlSetIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlSetIdL, "In TestCHuiControlSetIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlSetIdL );
    // Print to log file
    iLog->Log( KTestCHuiControlSetIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlIdL, "In TestCHuiControlIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlIdL );
    // Print to log file
    iLog->Log( KTestCHuiControlIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    STIF_ASSERT_EQUALS( iHuiControl->Id(), 67 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlEnvL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlEnvL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlEnvL, "In TestCHuiControlEnvL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlEnvL );
    // Print to log file
    iLog->Log( KTestCHuiControlEnvL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    iHuiControl->Env();

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlControlGroupL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlControlGroupL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlControlGroupL, "In TestCHuiControlControlGroupL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlControlGroupL );
    // Print to log file
    iLog->Log( KTestCHuiControlControlGroupL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    iHuiControl->ControlGroup();
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlTextureManagerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlTextureManagerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlTextureManagerL, "In TestCHuiControlTextureManagerL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlTextureManagerL );
    // Print to log file
    iLog->Log( KTestCHuiControlTextureManagerL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    iHuiControl->TextureManager();
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlDisplayL, "In TestCHuiControlDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlDisplayL );
    // Print to log file
    iLog->Log( KTestCHuiControlDisplayL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    iHuiControl->Display();
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlBindDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlBindDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlBindDisplayL, "In TestCHuiControlBindDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlBindDisplayL );
    // Print to log file
    iLog->Log( KTestCHuiControlBindDisplayL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAppendL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAppendL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAppendL, "In TestCHuiControlAppendL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAppendL );
    // Print to log file
    iLog->Log( KTestCHuiControlAppendL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->SetId( 67 );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAppendLayoutL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAppendLayoutL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAppendLayoutL, "In TestCHuiControlAppendLayoutL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAppendLayoutL );
    // Print to log file
    iLog->Log( KTestCHuiControlAppendLayoutL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    CHuiLayout* layout = NULL;
    iHuiControl->AppendL( visual, layout );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlRemoveL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlRemoveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlRemoveL, "In TestCHuiControlRemoveL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlRemoveL );
    // Print to log file
    iLog->Log( KTestCHuiControlRemoveL );


    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    iHuiControl->Remove( visual );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAppendVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAppendVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAppendVisualL, "In TestCHuiControlAppendVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAppendVisualL );
    // Print to log file
    iLog->Log( KTestCHuiControlAppendVisualL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    THuiVisualType type = EHuiVisualTypeVisual;
    iHuiControl->AppendVisualL( type );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAppendTypeLayoutL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAppendTypeLayoutL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAppendTypeLayoutL, "In TestCHuiControlAppendTypeLayoutL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAppendTypeLayoutL );
    // Print to log file
    iLog->Log( KTestCHuiControlAppendTypeLayoutL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    iHuiControl->AppendLayoutL( EHuiLayoutTypeLayout );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlVisualL, "In TestCHuiControlVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlVisualL );
    // Print to log file
    iLog->Log( KTestCHuiControlVisualL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    iHuiControl->Visual( 0 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlVisualCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlVisualCountL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlVisualCountL, "In TestCHuiControlVisualCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlVisualCountL );
    // Print to log file
    iLog->Log( KTestCHuiControlVisualCountL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    TInt visualCount = iHuiControl->VisualCount();
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlFindTagL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlFindTagL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlFindTagL, "In TestCHuiControlFindTagL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlFindTagL );
    // Print to log file
    iLog->Log( KTestCHuiControlFindTagL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    TInt visualCount = iHuiControl->VisualCount();
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    iHuiControl->FindTag( *ptr );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlHostL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlHostL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlHostL, "In TestCHuiControlHostL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlHostL );
    // Print to log file
    iLog->Log( KTestCHuiControlHostL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    iHuiControl->Host();
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAddConnectionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAddConnectionL( CStifItemParser& /*aItem */)
    {
    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAddConnectionL, "In TestCHuiControlAddConnectionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAddConnectionL );
    // Print to log file
    iLog->Log( KTestCHuiControlAddConnectionL );
    
    // Prepare
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    CleanupStack::PushL( connectControl );
    STIF_ASSERT_NOT_NULL( connectControl );
    iHuiControl->ControlGroup()->AppendL( connectControl ); // add into same group
    STIF_ASSERT_EQUALS( iHuiControl->ConnectionCount() , 0 );
    iHuiControl->AddConnectionL( connectControl );
    STIF_ASSERT_EQUALS( iHuiControl->ConnectionCount() , 1 );
    CleanupStack::Pop( connectControl );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlRemoveConnectionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlRemoveConnectionL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlRemoveConnectionL, "In TestCHuiControlRemoveConnectionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlRemoveConnectionL );
    // Print to log file
    iLog->Log( KTestCHuiControlRemoveConnectionL );

    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    CleanupStack::PushL( connectControl );
    STIF_ASSERT_NOT_NULL( connectControl );
    iHuiControl->ControlGroup()->AppendL( connectControl ); // add into same group
    STIF_ASSERT_EQUALS( iHuiControl->ConnectionCount() , 0 );
    iHuiControl->AddConnectionL( connectControl );
    STIF_ASSERT_EQUALS( iHuiControl->ConnectionCount() , 1 );
    iHuiControl->RemoveConnection( connectControl );
    STIF_ASSERT_EQUALS( iHuiControl->ConnectionCount() , 0 );
    CleanupStack::Pop( connectControl );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlFindConnectionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlFindConnectionL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlFindConnectionL, "In TestCHuiControlFindConnectionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlFindConnectionL );
    // Print to log file
    iLog->Log( KTestCHuiControlFindConnectionL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionCountL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionCountL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionCountL, "In TestCHuiControlConnectionCountL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionCountL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionCountL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    iHuiControl->ConnectionCount();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionL, "In TestCHuiControlConnectionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->Connection( index );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionByOrdinalL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionByOrdinalL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionByOrdinalL, "In TestCHuiControlConnectionByOrdinalL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionByOrdinalL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionByOrdinalL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->ConnectionByOrdinal( index );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionRoleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionRoleL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionRoleL, "In TestCHuiControlConnectionRoleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionRoleL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionRoleL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->ConnectionRole( index );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionOrdinalL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionOrdinalL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionOrdinalL, "In TestCHuiControlConnectionOrdinalL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionOrdinalL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionOrdinalL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->ConnectionOrdinal( index );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlRoleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlRoleL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlRoleL, "In TestCHuiControlRoleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlRoleL );
    // Print to log file
    iLog->Log( KTestCHuiControlRoleL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->Role();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlSetRoleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlSetRoleL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlSetRoleL, "In TestCHuiControlSetRoleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlSetRoleL );
    // Print to log file
    iLog->Log( KTestCHuiControlSetRoleL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->SetRole( index );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlHostIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlHostIdL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlHostIdL, "In TestCHuiControlHostIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlHostIdL );
    // Print to log file
    iLog->Log( KTestCHuiControlHostIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->FindConnection( connectControl );
    iHuiControl->HostId();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlSetHostIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlSetHostIdL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlSetHostIdL, "In TestCHuiControlSetHostIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlSetHostIdL );
    // Print to log file
    iLog->Log( KTestCHuiControlSetHostIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl );
    TInt index = iHuiControl->HostId();
    iHuiControl->SetHostId( index );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlSetHostL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlSetHostL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlSetHostL, "In TestCHuiControlSetHostL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlSetHostL );
    // Print to log file
    iLog->Log( KTestCHuiControlSetHostL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlContainerLayoutL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlContainerLayoutL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlContainerLayoutL, "In TestCHuiControlContainerLayoutL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlContainerLayoutL );
    // Print to log file
    iLog->Log( KTestCHuiControlContainerLayoutL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlHostToDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlHostToDisplayL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlHostToDisplayL, "In TestCHuiControlHostToDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlHostToDisplayL );
    // Print to log file
    iLog->Log( KTestCHuiControlHostToDisplayL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->HostToDisplay( iPoint );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlDisplayToHostL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlDisplayToHostL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlDisplayToHostL, "In TestCHuiControlDisplayToHostL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlDisplayToHostL );
    // Print to log file
    iLog->Log( KTestCHuiControlDisplayToHostL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlBoundsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlBoundsL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlBoundsL, "In TestCHuiControlBoundsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlBoundsL );
    // Print to log file
    iLog->Log( KTestCHuiControlBoundsL );


    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->Bounds();
    CleanupStack::Pop( 1 );

    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlHitTestL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlHitTestL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlHitTestL, "In TestCHuiControlHitTestL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlHitTestL );
    // Print to log file
    iLog->Log( KTestCHuiControlHitTestL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->HitTest( iPoint );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAcquireFocusL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAcquireFocusL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAcquireFocusL, "In TestCHuiControlAcquireFocusL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAcquireFocusL );
    // Print to log file
    iLog->Log( KTestCHuiControlAcquireFocusL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlFocusL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlFocusL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlFocusL, "In TestCHuiControlFocusL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlFocusL );
    // Print to log file
    iLog->Log( KTestCHuiControlFocusL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlIsFocusingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlIsFocusingL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlIsFocusingL, "In TestCHuiControlIsFocusingL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlIsFocusingL );
    // Print to log file
    iLog->Log( KTestCHuiControlIsFocusingL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlFocusChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlFocusChangedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlFocusChangedL, "In TestCHuiControlFocusChangedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlFocusChangedL );
    // Print to log file
    iLog->Log( KTestCHuiControlFocusChangedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    iHuiControl->FocusChanged( *iHuiDisplay, EFalse );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlAcceptInputL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlAcceptInputL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAcceptInputL, "In TestCHuiControlAcceptInputL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAcceptInputL );
    // Print to log file
    iLog->Log( KTestCHuiControlAcceptInputL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    iHuiControl->AcceptInput();
    CleanupStack::Pop( 1 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlOfferEventL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlOfferEventL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlAcceptInputL, "In TestCHuiControlAcceptInputL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlAcceptInputL );
    // Print to log file
    iLog->Log( KTestCHuiControlAcceptInputL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    iHuiControl->AcceptInput();
    const THuiEvent aEvent = 0 ;
    iHuiControl->OfferEventL( aEvent );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlDisplayAreaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlDisplayAreaL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlDisplayAreaL, "In TestCHuiControlDisplayAreaL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlDisplayAreaL );
    // Print to log file
    iLog->Log( KTestCHuiControlDisplayAreaL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    iHuiControl->AcceptInput();
    iHuiControl->DisplayArea();
    CleanupStack::Pop( 1 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlDisplayCenterL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlDisplayCenterL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlDisplayCenterL, "In TestCHuiControlDisplayCenterL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlDisplayCenterL );
    // Print to log file
    iLog->Log( KTestCHuiControlDisplayCenterL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    iHuiControl->AcceptInput();
    iHuiControl->DisplayCenter();
    CleanupStack::Pop( 1 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlCancelAllCommandsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlCancelAllCommandsL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlCancelAllCommandsL, "In TestCHuiControlCancelAllCommandsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlCancelAllCommandsL );
    // Print to log file
    iLog->Log( KTestCHuiControlCancelAllCommandsL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    const TPoint iPoint;
    iHuiControl->DisplayToHost( iPoint );
    iHuiControl->AcquireFocus();
    iHuiControl->Focus();
    iHuiControl->IsFocusing();
    iHuiControl->AcceptInput();
    iHuiControl->CancelAllCommands();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlVisualLayoutUpdatedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlVisualLayoutUpdatedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlVisualLayoutUpdatedL, "In TestCHuiControlVisualLayoutUpdatedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlVisualLayoutUpdatedL );
    // Print to log file
    iLog->Log( KTestCHuiControlVisualLayoutUpdatedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    iHuiControl->VisualLayoutUpdated( *visual );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlVisualDestroyedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlVisualDestroyedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlVisualDestroyedL, "In TestCHuiControlVisualDestroyedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlVisualDestroyedL );
    // Print to log file
    iLog->Log( KTestCHuiControlVisualDestroyedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    iHuiControl->VisualLayoutUpdated( *visual );
    iHuiControl->VisualDestroyed( *visual );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlEventHandlerL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlEventHandlerL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlEventHandlerL, "In TestCHuiControlEventHandlerL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlEventHandlerL );
    // Print to log file
    iLog->Log( KTestCHuiControlEventHandlerL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    STIF_ASSERT_NOT_NULL( iHuiControl );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    iHuiControl->AddConnectionL( connectControl);
    iHuiControl->ContainerLayout( connectControl );
    iHuiControl->SetId( 67 );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *iHuiControl );
    iHuiControl->AppendL( visual );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    iHuiControl->FindTag( *ptr );
    iHuiControl->VisualLayoutUpdated( *visual );
    iHuiControl->EventHandler();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlNotifyVisibilityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlNotifyVisibilityL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlNotifyVisibilityL, "In TestCHuiControlNotifyVisibilityL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlNotifyVisibilityL );
    // Print to log file
    iLog->Log( KTestCHuiControlNotifyVisibilityL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    controlChild->AddConnectionL( connectControl);
    controlChild->ContainerLayout( connectControl );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    controlChild->AppendL( visual );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildNotifyControlVisibility( EFalse, *display );
    CleanupStack::Pop( 2 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlVisualAddedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlVisualAddedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlVisualAddedL, "In TestCHuiControlVisualAddedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlVisualAddedL );
    // Print to log file
    iLog->Log( KTestCHuiControlVisualAddedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    controlChild->AddConnectionL( connectControl);
    controlChild->ContainerLayout( connectControl );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlVisualRemovedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlVisualRemovedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlVisualRemovedL, "In TestCHuiControlVisualRemovedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlVisualRemovedL );
    // Print to log file
    iLog->Log( KTestCHuiControlVisualRemovedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CHuiControl* connectControl = new( ELeave ) CHuiControl( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControl );
    CleanupStack::PushL( connectControl );
    controlChild->AddConnectionL( connectControl);
    controlChild->ContainerLayout( connectControl );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    CleanupStack::Pop( 2 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionAddedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionAddedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionAddedL, "In TestCHuiControlConnectionAddedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionAddedL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionAddedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlConnectionRemovedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlConnectionRemovedL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlConnectionRemovedL, "In TestCHuiControlConnectionRemovedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlConnectionRemovedL );
    // Print to log file
    iLog->Log( KTestCHuiControlConnectionRemovedL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    CleanupStack::Pop( 2 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlHostChangingL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlHostChangingL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlHostChangingL, "In TestCHuiControlHostChangingL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlHostChangingL );
    // Print to log file
    iLog->Log( KTestCHuiControlHostChangingL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    controlChild->ChildHostChangingL( connectControlChild );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlBaseConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlBaseConstructL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlBaseConstructL, "In TestCHuiControlBaseConstructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlBaseConstructL );
    // Print to log file
    iLog->Log( KTestCHuiControlBaseConstructL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    controlChild->ChildHostChangingL( connectControlChild );
    controlChild->ChildBaseConstructL();
    CleanupStack::Pop( 2 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlControlExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlControlExtensionL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlControlExtensionL, "In TestCHuiControlControlExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlControlExtensionL );
    // Print to log file
    iLog->Log( KTestCHuiControlControlExtensionL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    controlChild->ChildHostChangingL( connectControlChild );
    controlChild->ChildBaseConstructL();
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParameters = NULL;
    controlChild->ChildControlExtensionL( aExtensionUid, aExtensionParameters );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlTypeL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlTypeL, "In TestCHuiControlTypeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlTypeL );
    // Print to log file
    iLog->Log( KTestCHuiControlTypeL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    controlChild->ChildHostChangingL( connectControlChild );
    controlChild->ChildBaseConstructL();
    controlChild->ChildTypeL();
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParameters = NULL;
    controlChild->ChildControlExtensionL( aExtensionUid, aExtensionParameters );
    CleanupStack::Pop( 2 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlSessionIdL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlSessionIdL, "In TestCHuiControlSessionIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlSessionIdL );
    // Print to log file
    iLog->Log( KTestCHuiControlSessionIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    controlChild->ChildHostChangingL( connectControlChild );
    controlChild->ChildBaseConstructL();
    controlChild->ChildTypeL();
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParameters = NULL;
    controlChild->ChildControlExtensionL( aExtensionUid, aExtensionParameters );
    controlChild->ChildSessionIdL();
    CleanupStack::Pop( 2 );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiControlSetSessionIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiControlSetSessionIdL( CStifItemParser& /*aItem */)
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiControlSetSessionIdL, "In TestCHuiControlSetSessionIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiControlSetSessionIdL );
    // Print to log file
    iLog->Log( KTestCHuiControlSetSessionIdL );

    STIF_ASSERT_NOT_NULL( iHuiEnv );
    CTestUiAifBlocksHuiControlChild * controlChild = 
        new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( controlChild );
    CleanupStack::PushL( controlChild );
    CTestUiAifBlocksHuiControlChild* connectControlChild = 
    new( ELeave ) CTestUiAifBlocksHuiControlChild( *iHuiEnv );
    STIF_ASSERT_NOT_NULL( connectControlChild );
    CleanupStack::PushL( connectControlChild );
    controlChild->SetId( 67 );
    CHuiDisplay* display = controlChild->Display();
    controlChild->BindDisplay( *display );
    CHuiVisual* visual = new (ELeave) CHuiVisual( *controlChild );
    _LIT( KHello, " Hello " );
    const TDesC8* ptr = ( TDesC8* )&KHello;
    visual->SetTagL( *ptr );
    controlChild->FindTag( *ptr );
    controlChild->VisualLayoutUpdated( *visual );
    controlChild->ChildVisualAddedL( visual );
    controlChild->ChildVisualRemovedL( visual );
    controlChild->ChildConnectionAddedL( connectControlChild, 0 );
    controlChild->ChildConnectionRemovedL( connectControlChild, 0 );
    controlChild->ChildHostChangingL( connectControlChild );
    controlChild->ChildBaseConstructL();
    controlChild->ChildTypeL();
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParameters = NULL;
    controlChild->ChildControlExtensionL( aExtensionUid, aExtensionParameters );
    TInt sessionId = controlChild->ChildSessionIdL();
    controlChild->ChildSetSessionIdL( sessionId );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
   
    }

//  [End of File]
