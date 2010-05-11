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
#include "uiacceltk/huivisual.h"
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huievent.h>
#include <uiacceltk/huicommand.h>
#include <uiacceltk/huiimagevisual.h>
#include <uiacceltk/huitextvisual.h>
#include <uiacceltk/huitimedvalue.h>
#include <uiacceltk/huitransformation.h>
#include <eikenv.h>
#include <e32err.h>

#include "testuiaifcoretoolkit.h"
#include "testuiaifblockshuiactioncommandchild.h"
#include "testuiaifblockshuigroupcommandchild.h"
#include "testuiaifblockshuicontrolcommandchild.h"
#include "testuiaifblockshuivisualcommandchild.h"
#include "testuiaifblockshuiimagecommandchild.h"
#include "testuiaifblockshuitextcommandchild.h"
#include "testuiaifblockshuivaluecommandchild.h"
#include "testuiaifblockshuipointcommandchild.h"
#include "testuiaifblockshuitranscommandchild.h"
#include "testuiaifblockshuimarkercommandchild.h"
#include "testuiaifblockshuicustomeventcommandchild.h"
//

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandDestructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandDestructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandDestructL, "In TestCHuiCommandDestructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandDestructL );
    // Print to log file
    iLog->Log( KTestCHuiCommandDestructL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandObjectCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandObjectCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandObjectCommandL, "In TestCHuiCommandObjectCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandObjectCommandL );
    // Print to log file
    iLog->Log( KTestCHuiCommandObjectCommandL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->ObjectCommand();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandSetSenderL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandSetSenderL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandSetSenderL, "In TestCHuiCommandSetSenderL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandSetSenderL );
    // Print to log file
    iLog->Log( KTestCHuiCommandSetSenderL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandTypeL, "In TestCHuiCommandTypeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandTypeL );
    // Print to log file
    iLog->Log( KTestCHuiCommandTypeL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiSenderTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiSenderTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiSenderTypeL, "In TestCHuiSenderTypeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiSenderTypeL );
    // Print to log file
    iLog->Log( KTestCHuiSenderTypeL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    actionCommand->SenderType();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiSenderL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiSenderL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiSenderL, "In TestCHuiSenderL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiSenderL );
    // Print to log file
    iLog->Log( KTestCHuiSenderL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    actionCommand->SenderType();
    actionCommand->Sender();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiSenderVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiSenderVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiSenderVisualL, "In TestCHuiSenderVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiSenderVisualL );
    // Print to log file
    iLog->Log( KTestCHuiSenderVisualL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    actionCommand->SenderType();
    actionCommand->Sender();
    actionCommand->SenderVisual();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiSenderControlL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiSenderControlL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiSenderControlL, "In TestCHuiSenderControlL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiSenderControlL );
    // Print to log file
    iLog->Log( KTestCHuiSenderControlL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    actionCommand->SenderType();
    actionCommand->Sender();
    actionCommand->SenderVisual();
    actionCommand->SenderControl();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiSenderControlGroupL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiSenderControlGroupL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiSenderControlGroupL, "In TestCHuiSenderControlGroupL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiSenderControlGroupL );
    // Print to log file
    iLog->Log( KTestCHuiSenderControlGroupL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    actionCommand->SenderType();
    actionCommand->Sender();
    actionCommand->SenderVisual();
    actionCommand->SenderControl();
    actionCommand->SenderControlGroup();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandConstructL, "In TestCHuiCommandConstructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandConstructL );
    // Print to log file
    iLog->Log( KTestCHuiCommandConstructL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->SetSender( EHuiCommandObjectTypeNone, iHuiControl );
    actionCommand->Type();
    actionCommand->SenderType();
    actionCommand->Sender();
    actionCommand->SenderVisual();
    actionCommand->SenderControl();
    actionCommand->SenderControlGroup();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandExtensionL, "In TestCHuiCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandExtensionL );
    // Print to log file
    iLog->Log( KTestCHuiCommandExtensionL );

    TTestUiAifBlocksHuiActionCommandChild* actionCommandChild =
        new ( ELeave ) TTestUiAifBlocksHuiActionCommandChild( 1 );
    STIF_ASSERT_NOT_NULL( actionCommandChild );
    CleanupStack::PushL( actionCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    actionCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( actionCommandChild )
        {
        delete actionCommandChild;
        actionCommandChild = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandTActionCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandTActionCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandTActionCommandL, "In TestCHuiCommandTActionCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandTActionCommandL );
    // Print to log file
    iLog->Log( KTestCHuiCommandTActionCommandL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandExecuteL, "In TestCHuiCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandExecuteL );
    // Print to log file
    iLog->Log( KTestCHuiCommandExecuteL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandSizeL, "In TestCHuiCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandSizeL );
    // Print to log file
    iLog->Log( KTestCHuiCommandSizeL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->ExecuteL( *iHuiEnv );
    actionCommand->Size();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiCommandIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiCommandIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiCommandIdL, "In TestCHuiCommandIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiCommandIdL );
    // Print to log file
    iLog->Log( KTestCHuiCommandIdL );

    THuiActionCommand* actionCommand = new ( ELeave )THuiActionCommand( 1 );
    STIF_ASSERT_NOT_NULL( actionCommand );
    CleanupStack::PushL( actionCommand );
    actionCommand->ExecuteL( *iHuiEnv );
    actionCommand->Size();
    actionCommand->Id();
    CleanupStack::Pop( 1 );
    if( actionCommand )
        {
        delete actionCommand;
        actionCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiActionCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiActionCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiActionCommandExtensionL, "In TestCHuiActionCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiActionCommandExtensionL );
    // Print to log file
    iLog->Log( KTestCHuiActionCommandExtensionL );

    TTestUiAifBlocksHuiActionCommandChild* actionCommandChild =
        new ( ELeave ) TTestUiAifBlocksHuiActionCommandChild( 1 );
    STIF_ASSERT_NOT_NULL( actionCommandChild );
    CleanupStack::PushL( actionCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    actionCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( actionCommandChild )
        {
        delete actionCommandChild;
        actionCommandChild = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandL, "In TestCHuiObjectCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ObjectCommand();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandExecuteL, "In TestCHuiObjectCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandExecuteL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandExecuteL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ObjectCommand();
    groupCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandSizeL, "In TestCHuiObjectCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandSizeL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandSizeL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ObjectCommand();
    groupCommand->ExecuteL( *iHuiEnv );
    groupCommand->Size();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandObjectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandObjectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandObjectL, "In TestCHuiObjectCommandObjectL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandObjectL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandObjectL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ObjectCommand();
    groupCommand->ExecuteL( *iHuiEnv );
    groupCommand->Size();
    groupCommand->Object();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandOperationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandOperationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandOperationL, "In TestCHuiObjectCommandOperationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandOperationL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandOperationL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ObjectCommand();
    groupCommand->ExecuteL( *iHuiEnv );
    groupCommand->Size();
    groupCommand->Object();
    groupCommand->Operation();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandConstructL, "In TestCHuiObjectCommandConstructL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandConstructL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandConstructL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiObjectCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiObjectCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestCHuiObjectCommandExtensionL, "In TestCHuiObjectCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestCHuiObjectCommandExtensionL );
    // Print to log file
    iLog->Log( KTestCHuiObjectCommandExtensionL );

    THuiOp aOperation = EHuiOpHide;
    TTestUiAifBlocksHuiGroupCommandChild* groupCommandChild = new ( ELeave )
        TTestUiAifBlocksHuiGroupCommandChild( *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommandChild );
    CleanupStack::PushL( groupCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    groupCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiGroupCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiGroupCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiGroupCommandL, "In TestTHuiGroupCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiGroupCommandL );
    // Print to log file
    iLog->Log( KTestTHuiGroupCommandL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiGroupCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiGroupCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiGroupCommandExecuteL, "In TestTHuiGroupCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiGroupCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiGroupCommandExecuteL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiGroupCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiGroupCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiGroupCommandSizeL, "In TestTHuiGroupCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiGroupCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiGroupCommandSizeL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ExecuteL( *iHuiEnv );
    groupCommand->Size();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiGroupCommandControlGroupL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiGroupCommandControlGroupL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiGroupCommandControlGroupL, "In TestTHuiGroupCommandControlGroupL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiGroupCommandControlGroupL );
    // Print to log file
    iLog->Log( KTestTHuiGroupCommandControlGroupL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ExecuteL( *iHuiEnv );
    groupCommand->Size();
    groupCommand->ControlGroup();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiGroupCommandDisplayL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiGroupCommandDisplayL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiGroupCommandDisplayL, "In TestTHuiGroupCommandDisplayL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiGroupCommandDisplayL );
    // Print to log file
    iLog->Log( KTestTHuiGroupCommandDisplayL );

    THuiOp aOperation = EHuiOpHide;
    THuiGroupCommand* groupCommand = new ( ELeave ) THuiGroupCommand( 
        *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommand );
    CleanupStack::PushL( groupCommand );
    groupCommand->ExecuteL( *iHuiEnv );
    groupCommand->Size();
    groupCommand->ControlGroup();
    groupCommand->Display();
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiGroupCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiGroupCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiGroupCommandExtensionL, "In TestTHuiGroupCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiGroupCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiGroupCommandExtensionL );

    THuiOp aOperation = EHuiOpHide;
    TTestUiAifBlocksHuiGroupCommandChild* groupCommandChild = new ( ELeave )
        TTestUiAifBlocksHuiGroupCommandChild( *iHuiControlGroup, aOperation, iHuiDisplay );
    STIF_ASSERT_NOT_NULL( groupCommandChild );
    CleanupStack::PushL( groupCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    groupCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiControlCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiControlCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiiHuiControlCommandL, "In TestTHuiiHuiControlCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiiHuiControlCommandL );
    // Print to log file
    iLog->Log( KTestTHuiiHuiControlCommandL );

    THuiOp aOperation = EHuiOpHide;
    THuiControlCommand* iHuiControlCommand = new ( ELeave ) THuiControlCommand( 
        *iHuiControl, aOperation );
    STIF_ASSERT_NOT_NULL( iHuiControlCommand );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiControlCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiControlCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiiHuiControlCommandExecuteL, "In TestTHuiiHuiControlCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiiHuiControlCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiiHuiControlCommandExecuteL );

    THuiOp aOperation = EHuiOpHide;
    THuiControlCommand* iHuiControlCommand = new ( ELeave ) THuiControlCommand( 
        *iHuiControl, aOperation );
    STIF_ASSERT_NOT_NULL( iHuiControlCommand );
    iHuiControlCommand->ExecuteL( *iHuiEnv );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiControlCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiControlCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiControlCommandSizeL, "In TestTHuiControlCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiControlCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiControlCommandSizeL );

    THuiOp aOperation = EHuiOpHide;
    THuiControlCommand* iHuiControlCommand = new ( ELeave ) THuiControlCommand( 
        *iHuiControl, aOperation );
    STIF_ASSERT_NOT_NULL( iHuiControlCommand );
    iHuiControlCommand->ExecuteL( *iHuiEnv );
    iHuiControlCommand->Size();
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiiHuiControlCommandControlL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiControlCommandControlL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiControlCommandControlL, "In TestTHuiControlCommandControlL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiControlCommandControlL );
    // Print to log file
    iLog->Log( KTestTHuiControlCommandControlL );

    THuiOp aOperation = EHuiOpHide;
    THuiControlCommand* iHuiControlCommand = new ( ELeave ) THuiControlCommand( 
        *iHuiControl, aOperation );
    STIF_ASSERT_NOT_NULL( iHuiControlCommand );
    iHuiControlCommand->ExecuteL( *iHuiEnv );
    iHuiControlCommand->Size();
    iHuiControlCommand->Control();
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiControlCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiControlCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiControlCommandExtensionL, "In TestTHuiControlCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiControlCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiControlCommandExtensionL );

    THuiOp aOperation = EHuiOpHide;
    TTestUiAifBlocksHuiControlCommandChild* iHuiControlCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiControlCommandChild( *iHuiControl, aOperation );
    STIF_ASSERT_NOT_NULL( iHuiControlCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    iHuiControlCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandL, "In TestTHuiVisualCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    THuiVisualCommand* visualCommand = new ( ELeave ) THuiVisualCommand( 
        *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommand );
    CleanupStack::PushL( visualCommand );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandExecuteL, "In TestTHuiVisualCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandExecuteL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    THuiVisualCommand* visualCommand = new ( ELeave ) THuiVisualCommand( 
        *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommand );
    CleanupStack::PushL( visualCommand );
    visualCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandSizeL, "In TestTHuiVisualCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandSizeL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    THuiVisualCommand* visualCommand = new ( ELeave ) THuiVisualCommand( 
        *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommand );
    CleanupStack::PushL( visualCommand );
    visualCommand->ExecuteL( *iHuiEnv );
    visualCommand->Size();
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandVisualL, "In TestTHuiVisualCommandVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandVisualL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandVisualL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    THuiVisualCommand* visualCommand = new ( ELeave ) THuiVisualCommand( 
        *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommand );
    CleanupStack::PushL( visualCommand );
    visualCommand->ExecuteL( *iHuiEnv );
    visualCommand->Size();
    visualCommand->Visual();
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandFlagsToSetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandFlagsToSetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandFlagsToSetL, "In TestTHuiVisualCommandFlagsToSetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandFlagsToSetL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandFlagsToSetL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    THuiVisualCommand* visualCommand = new ( ELeave ) THuiVisualCommand( 
        *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommand );
    CleanupStack::PushL( visualCommand );
    visualCommand->ExecuteL( *iHuiEnv );
    visualCommand->Size();
    visualCommand->Visual();
    visualCommand->FlagsToSet();
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandFlagsToClearL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandFlagsToClearL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandFlagsToClearL, "In TestTHuiVisualCommandFlagsToClearL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandFlagsToClearL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandFlagsToClearL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    THuiVisualCommand* visualCommand = new ( ELeave ) THuiVisualCommand( 
        *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommand );
    CleanupStack::PushL( visualCommand );
    visualCommand->ExecuteL( *iHuiEnv );
    visualCommand->Size();
    visualCommand->Visual();
    visualCommand->FlagsToSet();
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiVisualCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiVisualCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiVisualCommandExtensionL, "In TestTHuiVisualCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiVisualCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiVisualCommandExtensionL );

    CHuiVisual* visual = new ( ELeave )CHuiVisual( *iHuiControl );
    STIF_ASSERT_NOT_NULL( visual );
    CleanupStack::PushL( visual );
    THuiOp aOperation = EHuiOpRemoveAndDestroyAll;
    TTestUiAifBlocksHuiVisualCommandChild* visualCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiVisualCommandChild( *visual, aOperation );
    STIF_ASSERT_NOT_NULL( visualCommandChild );
    CleanupStack::PushL( visualCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    visualCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiImageCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiImageCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiImageCommandL, "In TestTHuiImageCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiImageCommandL );
    // Print to log file
    iLog->Log( KTestTHuiImageCommandL );

    CHuiImageVisual* aImageVisual = CHuiImageVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aImageVisual );
    CleanupStack::PushL( aImageVisual );
    const THuiImage* aImage = new ( ELeave )THuiImage;
    THuiImageCommand* imageCommand = 
        new ( ELeave ) THuiImageCommand( *aImageVisual, *aImage );
    STIF_ASSERT_NOT_NULL( imageCommand );
    CleanupStack::PushL( imageCommand );
    CleanupStack::Pop( 2 );
    if( aImage )
        {
        delete aImage;
        aImage = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiImageCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiImageCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiImageCommandExecuteL, "In TestTHuiImageCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiImageCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiImageCommandExecuteL );

    CHuiImageVisual* aImageVisual = CHuiImageVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aImageVisual );
    CleanupStack::PushL( aImageVisual );
    const THuiImage* aImage = new ( ELeave )THuiImage;
    THuiImageCommand* imageCommand = 
        new ( ELeave ) THuiImageCommand( *aImageVisual, *aImage );
    STIF_ASSERT_NOT_NULL( imageCommand );
    CleanupStack::PushL( imageCommand );
    imageCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 2 );
    if( aImage )
        {
        delete aImage;
        aImage = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiImageCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiImageCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiImageCommandSizeL, "In TestTHuiImageCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiImageCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiImageCommandSizeL );

    CHuiImageVisual* aImageVisual = CHuiImageVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aImageVisual );
    CleanupStack::PushL( aImageVisual );
    const THuiImage* aImage = new ( ELeave )THuiImage;
    THuiImageCommand* imageCommand = 
        new ( ELeave ) THuiImageCommand( *aImageVisual, *aImage );
    STIF_ASSERT_NOT_NULL( imageCommand );
    CleanupStack::PushL( imageCommand );
    imageCommand->ExecuteL( *iHuiEnv );
    imageCommand->Size();
    CleanupStack::Pop( 2 );
    if( aImage )
        {
        delete aImage;
        aImage = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiImageCommandVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiImageCommandVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiImageCommandVisualL, "In TestTHuiImageCommandVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiImageCommandVisualL );
    // Print to log file
    iLog->Log( KTestTHuiImageCommandVisualL );

    CHuiImageVisual* aImageVisual = CHuiImageVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aImageVisual );
    CleanupStack::PushL( aImageVisual );
    const THuiImage* aImage = new ( ELeave )THuiImage;
    THuiImageCommand* imageCommand = 
        new ( ELeave ) THuiImageCommand( *aImageVisual, *aImage );
    STIF_ASSERT_NOT_NULL( imageCommand );
    CleanupStack::PushL( imageCommand );
    imageCommand->ExecuteL( *iHuiEnv );
    imageCommand->Size();
    imageCommand->ImageVisual();
    CleanupStack::Pop( 2 );
    if( aImage )
        {
        delete aImage;
        aImage = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiImageCommandImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiImageCommandImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiImageCommandImageL, "In TestTHuiImageCommandImageL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiImageCommandImageL );
    // Print to log file
    iLog->Log( KTestTHuiImageCommandImageL );

    CHuiImageVisual* aImageVisual = CHuiImageVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aImageVisual );
    CleanupStack::PushL( aImageVisual );
    const THuiImage* aImage = new ( ELeave )THuiImage;
    THuiImageCommand* imageCommand = 
        new ( ELeave ) THuiImageCommand( *aImageVisual, *aImage );
    STIF_ASSERT_NOT_NULL( imageCommand );
    CleanupStack::PushL( imageCommand );
    imageCommand->ExecuteL( *iHuiEnv );
    imageCommand->Size();
    imageCommand->ImageVisual();
    imageCommand->Image();
    CleanupStack::Pop(2 );
    if( aImage )
        {
        delete aImage;
        aImage = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiImageCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiImageCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiImageCommandExtensionL, "In TestTHuiImageCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiImageCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiImageCommandExtensionL );

    CHuiImageVisual* aImageVisual = CHuiImageVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aImageVisual );
    CleanupStack::PushL( aImageVisual );
    const THuiImage* aImage = new ( ELeave )THuiImage;
    TTestUiAifBlocksHuiImageCommandChild* imageCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiImageCommandChild( *aImageVisual, *aImage );
    STIF_ASSERT_NOT_NULL( imageCommandChild );
    CleanupStack::PushL( imageCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    imageCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop(2 );
    if( aImage )
        {
        delete aImage;
        aImage = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCommandL, "In TestTHuiTextCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCommandL );
    // Print to log file
    iLog->Log( KTestTHuiTextCommandL );

    CHuiTextVisual* aTextVisual = CHuiTextVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aTextVisual );
    CleanupStack::PushL( aTextVisual );
    _LIT( KHello, "Hello" );
    const TDesC& aText = KHello;
    THuiTextCommand* textCommand = 
        new ( ELeave ) THuiTextCommand( *aTextVisual, aText );
    STIF_ASSERT_NOT_NULL( textCommand );
    CleanupStack::PushL( textCommand );
    CleanupStack::Pop(2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCommandExecuteL, "In TestTHuiTextCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiTextCommandExecuteL );

    CHuiTextVisual* aTextVisual = CHuiTextVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aTextVisual );
    CleanupStack::PushL( aTextVisual );
    _LIT( KHello, "Hello" );
    const TDesC& aText = KHello;
    THuiTextCommand* textCommand = 
        new ( ELeave ) THuiTextCommand( *aTextVisual, aText );
    STIF_ASSERT_NOT_NULL( textCommand );
    CleanupStack::PushL( textCommand );
    textCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop(2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCommandSizeL, "In TestTHuiTextCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiTextCommandSizeL );

    CHuiTextVisual* aTextVisual = CHuiTextVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aTextVisual );
    CleanupStack::PushL( aTextVisual );
    _LIT( KHello, "Hello" );
    const TDesC& aText = KHello;
    THuiTextCommand* textCommand = 
        new ( ELeave ) THuiTextCommand( *aTextVisual, aText );
    STIF_ASSERT_NOT_NULL( textCommand );
    CleanupStack::PushL( textCommand );
    textCommand->ExecuteL( *iHuiEnv );
    textCommand->Size();
    CleanupStack::Pop(2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCommandTextVisualL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCommandTextVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCommandTextVisualL, "In TestTHuiTextCommandTextVisualL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCommandTextVisualL );
    // Print to log file
    iLog->Log( KTestTHuiTextCommandTextVisualL );

    CHuiTextVisual* aTextVisual = CHuiTextVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aTextVisual );
    CleanupStack::PushL( aTextVisual );
    _LIT( KHello, "Hello" );
    const TDesC& aText = KHello;
    THuiTextCommand* textCommand = 
        new ( ELeave ) THuiTextCommand( *aTextVisual, aText );
    STIF_ASSERT_NOT_NULL( textCommand );
    CleanupStack::PushL( textCommand );
    textCommand->ExecuteL( *iHuiEnv );
    textCommand->Size();
    textCommand->TextVisual();
    CleanupStack::Pop(2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCommandTextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCommandTextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCommandTextL, "In TestTHuiTextCommandTextL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCommandTextL );
    // Print to log file
    iLog->Log( KTestTHuiTextCommandTextL );

    CHuiTextVisual* aTextVisual = CHuiTextVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aTextVisual );
    CleanupStack::PushL( aTextVisual );
    _LIT( KHello, "Hello" );
    const TDesC& aText = KHello;
    THuiTextCommand* textCommand = 
        new ( ELeave ) THuiTextCommand( *aTextVisual, aText );
    STIF_ASSERT_NOT_NULL( textCommand );
    CleanupStack::PushL( textCommand );
    textCommand->ExecuteL( *iHuiEnv );
    textCommand->Size();
    textCommand->TextVisual();
    textCommand->Text();
    CleanupStack::Pop(2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCommandExtensionL, "In TestTHuiTextCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiTextCommandExtensionL );

    CHuiTextVisual* aTextVisual = CHuiTextVisual::AddNewL( *iHuiControl );
    STIF_ASSERT_NOT_NULL( aTextVisual );
    CleanupStack::PushL( aTextVisual );
    _LIT( KHello, "Hello" );
    const TDesC& aText = KHello;
    TTestUiAifBlocksHuiTextCommandChild* textCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiTextCommandChild( *aTextVisual, aText );
    STIF_ASSERT_NOT_NULL( textCommandChild );
    CleanupStack::PushL( textCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    textCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop(2 );
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandL, "In TestTHuiValueCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    TReal32 aTarget = 1;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue, aTarget );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandMutiRefL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandMutiRefL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandMutiRefL, "In TestTHuiValueCommandMutiRefL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandMutiRefL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandMutiRefL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandExecuteL, "In TestTHuiValueCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandExecuteL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    valueCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandSizeL, "In TestTHuiValueCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandSizeL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    valueCommand->ExecuteL( *iHuiEnv );
    valueCommand->Size();
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandTimedValueL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandTimedValueL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandTimedValueL, "In TestTHuiValueCommandTimedValueL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandTimedValueL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandTimedValueL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    valueCommand->ExecuteL( *iHuiEnv );
    valueCommand->Size();
    valueCommand->TimedValue();
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandTargetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandTargetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandTargetL, "In TestTHuiValueCommandTargetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandTargetL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandTargetL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    valueCommand->ExecuteL( *iHuiEnv );
    valueCommand->Size();
    valueCommand->TimedValue();
    valueCommand->Target();
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandTransitionTimeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandTransitionTimeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandTransitionTimeL, "In TestTHuiValueCommandTransitionTimeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandTransitionTimeL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandTransitionTimeL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    valueCommand->ExecuteL( *iHuiEnv );
    valueCommand->Size();
    valueCommand->TimedValue();
    valueCommand->Target();
    valueCommand->TransitionTime();
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandSpeedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandSpeedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandSpeedL, "In TestTHuiValueCommandSpeedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandSpeedL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandSpeedL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    THuiValueCommand* valueCommand = 
        new ( ELeave ) THuiValueCommand( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommand );
    CleanupStack::PushL( valueCommand );
    valueCommand->ExecuteL( *iHuiEnv );
    valueCommand->Size();
    valueCommand->TimedValue();
    valueCommand->Target();
    valueCommand->TransitionTime();
    valueCommand->Speed();
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiValueCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiValueCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiValueCommandExtensionL, "In TestTHuiValueCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiValueCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiValueCommandExtensionL );
    
    THuiTimedValue* aValue = new ( ELeave ) THuiTimedValue;
    TTestUiAifBlocksHuiValueCommandChild* valueCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiValueCommandChild( iHuiControl, *aValue );
    STIF_ASSERT_NOT_NULL( valueCommandChild );
    CleanupStack::PushL( valueCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    valueCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( aValue )
        {
        delete aValue;
        aValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandL, "In TestTHuiPointCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandMutiRefL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandMutiRefL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandMutiRefL, "In TestTHuiPointCommandMutiRefL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandMutiRefL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandMutiRefL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandMutiRefOtherL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandMutiRefOtherL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandMutiRefOtherL, "In TestTHuiPointCommandMutiRefOtherL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandMutiRefOtherL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandMutiRefOtherL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandExecuteL, "In TestTHuiPointCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandExecuteL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    pointCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandSizeL, "In TestTHuiPointCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandSizeL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    pointCommand->Size();
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandTimedPointL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandTimedPointL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandTimedPointL, "In TestTHuiPointCommandTimedPointL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandTimedPointL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandTimedPointL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    pointCommand->TimedPoint();
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandTargetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandTargetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandTargetL, "In TestTHuiPointCommandTargetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandTargetL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandTargetL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    pointCommand->Target();
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandTransitionTimeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandTransitionTimeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandTransitionTimeL, "In TestTHuiPointCommandTransitionTimeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandTransitionTimeL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandTransitionTimeL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    pointCommand->TransitionTime();
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandSpeedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandSpeedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandSpeedL, "In TestTHuiPointCommandSpeedL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandSpeedL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandSpeedL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    THuiPointCommand* pointCommand = 
        new ( ELeave ) THuiPointCommand( iHuiControl, *aPoint, EHuiOpSetWithSpeed,  aTarget );
    STIF_ASSERT_NOT_NULL( pointCommand );
    CleanupStack::PushL( pointCommand );
    pointCommand->Speed();
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiPointCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiPointCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiPointCommandExtensionL, "In TestTHuiPointCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiPointCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiPointCommandExtensionL );
    
    THuiTimedPoint* aPoint = new ( ELeave ) THuiTimedPoint;
    THuiRealPoint aTarget;
    TTestUiAifBlocksHuiPointCommandChild* pointCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiPointCommandChild( iHuiControl, *aPoint, EHuiOpSetWithSpeed );
    STIF_ASSERT_NOT_NULL( pointCommandChild );
    CleanupStack::PushL( pointCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    pointCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( aPoint )
        {
        delete aPoint;
        aPoint = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandL, "In TestTHuiTransformationCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandExecuteL, "In TestTHuiTransformationCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandExecuteL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    transCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandSizeL, "In TestTHuiTransformationCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandSizeL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    transCommand->ExecuteL( *iHuiEnv );
    transCommand->Size();
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandTransmasnL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandTransmasnL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandTransmasnL, "In TestTHuiTransformationCommandTransmasnL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandTransmasnL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandTransmasnL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    transCommand->ExecuteL( *iHuiEnv );
    transCommand->Transformation();
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandStepL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandStepL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandStepL, "In TestTHuiTransformationCommandStepL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandStepL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandStepL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    transCommand->ExecuteL( *iHuiEnv );
    transCommand->Step();
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetXL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetXL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandSetXL, "In TestTHuiTransformationCommandSetXL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandSetXL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandSetXL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    transCommand->ExecuteL( *iHuiEnv );
    const THuiTimedValue* timeValue = new ( ELeave ) THuiTimedValue;
    transCommand->SetX( *timeValue );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    if( timeValue )
        {
        delete timeValue;
        timeValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetYL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetYL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandSetYL, "In TestTHuiTransformationCommandSetYL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandSetYL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandSetYL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    const THuiTimedValue* timeValue = new ( ELeave ) THuiTimedValue;
    transCommand->SetY( *timeValue );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    if( timeValue )
        {
        delete timeValue;
        timeValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetZL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetZL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandSetZL, "In TestTHuiTransformationCommandSetZL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandSetZL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandSetZL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    const THuiTimedValue* timeValue = new ( ELeave ) THuiTimedValue;
    transCommand->SetZ( *timeValue );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    if( timeValue )
        {
        delete timeValue;
        timeValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetAngleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandSetAngleL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandSetAngleL, "In TestTHuiTransformationCommandSetAngleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandSetAngleL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandSetAngleL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    THuiTransformationCommand* transCommand = 
        new ( ELeave ) THuiTransformationCommand( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommand );
    CleanupStack::PushL( transCommand );
    const THuiTimedValue* timeValue = new ( ELeave ) THuiTimedValue;
    transCommand->SetAngle( *timeValue );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    if( timeValue )
        {
        delete timeValue;
        timeValue = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTransformationCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTransformationCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTransformationCommandExtensionL, "In KTestTHuiTransformationCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTransformationCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiTransformationCommandExtensionL );
    
    CHuiTransformation* aTransformation = CHuiTransformation::NewL();
    TTestUiAifBlocksHuiTransCommandChild* transCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiTransCommandChild( iHuiControl, *aTransformation );
    STIF_ASSERT_NOT_NULL( transCommandChild );
    CleanupStack::PushL( transCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    transCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( aTransformation )
        {
        delete aTransformation;
        aTransformation = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiMarkerCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiMarkerCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiMarkerCommandL, "In TestTHuiMarkerCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiMarkerCommandL );
    // Print to log file
    iLog->Log( KTestTHuiMarkerCommandL );
    
    THuiMarkerCommand* markerCommand = new ( ELeave ) THuiMarkerCommand( 0 );
    STIF_ASSERT_NOT_NULL( markerCommand );
    CleanupStack::PushL( markerCommand );
    CleanupStack::Pop( 1 );
    if( markerCommand )
        {
        delete markerCommand;
        markerCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiMarkerCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiMarkerCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiMarkerCommandExecuteL, "In TestTHuiMarkerCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiMarkerCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiMarkerCommandExecuteL );
    
    THuiMarkerCommand* markerCommand = new ( ELeave ) THuiMarkerCommand( 0 );
    STIF_ASSERT_NOT_NULL( markerCommand );
    CleanupStack::PushL( markerCommand );
    markerCommand->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    if( markerCommand )
        {
        delete markerCommand;
        markerCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiMarkerCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiMarkerCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiMarkerCommandSizeL, "In TestTHuiMarkerCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiMarkerCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiMarkerCommandSizeL );
    
    THuiMarkerCommand* markerCommand = new ( ELeave ) THuiMarkerCommand( 0 );
    STIF_ASSERT_NOT_NULL( markerCommand );
    CleanupStack::PushL( markerCommand );
    markerCommand->Size();
    CleanupStack::Pop( 1 );
    if( markerCommand )
        {
        delete markerCommand;
        markerCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiMarkerCommandIdL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiMarkerCommandIdL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiMarkerCommandIdL, "In TestTHuiMarkerCommandIdL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiMarkerCommandIdL );
    // Print to log file
    iLog->Log( KTestTHuiMarkerCommandIdL );
    
    THuiMarkerCommand* markerCommand = new ( ELeave ) THuiMarkerCommand( 0 );
    STIF_ASSERT_NOT_NULL( markerCommand );
    CleanupStack::PushL( markerCommand );
    markerCommand->Id();
    CleanupStack::Pop( 1 );
    if( markerCommand )
        {
        delete markerCommand;
        markerCommand = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiMarkerCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiMarkerCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiMarkerCommandExtensionL, "In TestTHuiMarkerCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiMarkerCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiMarkerCommandExtensionL );
    
    TTestUiAifBlocksHuiMarkerCommandChild* markerCommandChild = 
        new ( ELeave ) TTestUiAifBlocksHuiMarkerCommandChild( 0 );
    STIF_ASSERT_NOT_NULL( markerCommandChild );
    CleanupStack::PushL( markerCommandChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    markerCommandChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( markerCommandChild )
        {
        delete markerCommandChild;
        markerCommandChild = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiCustomEventCommandL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiCustomEventCommandL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiCustomEventCommandL, "In TestTHuiCustomEventCommandL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiCustomEventCommandL );
    // Print to log file
    iLog->Log( KTestTHuiCustomEventCommandL );
    
    THuiCustomEventCommand* customEvent = 
        new ( ELeave ) THuiCustomEventCommand( 0 );
    STIF_ASSERT_NOT_NULL( customEvent );
    CleanupStack::PushL( customEvent );
    CleanupStack::Pop( 1 );
    if( customEvent )
        {
        delete customEvent;
        customEvent = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiCustomEventCommandExecuteL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiCustomEventCommandExecuteL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiCustomEventCommandExecuteL, "In TestTHuiCustomEventCommandExecuteL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiCustomEventCommandExecuteL );
    // Print to log file
    iLog->Log( KTestTHuiCustomEventCommandExecuteL );
    
    THuiCustomEventCommand* customEvent = 
        new ( ELeave ) THuiCustomEventCommand( 0 );
    STIF_ASSERT_NOT_NULL( customEvent );
    CleanupStack::PushL( customEvent );
    customEvent->ExecuteL( *iHuiEnv );
    CleanupStack::Pop( 1 );
    if( customEvent )
        {
        delete customEvent;
        customEvent = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiCustomEventCommandSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiCustomEventCommandSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiCustomEventCommandSizeL, "In TestTHuiCustomEventCommandSizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiCustomEventCommandSizeL );
    // Print to log file
    iLog->Log( KTestTHuiCustomEventCommandSizeL );
    
    THuiCustomEventCommand* customEvent = 
        new ( ELeave ) THuiCustomEventCommand( 0 );
    STIF_ASSERT_NOT_NULL( customEvent );
    CleanupStack::PushL( customEvent );
    customEvent->Size();
    CleanupStack::Pop( 1 );
    if( customEvent )
        {
        delete customEvent;
        customEvent = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiCustomEventCommandRecipientL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiCustomEventCommandRecipientL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiCustomEventCommandRecipientL, "In TestTHuiCustomEventCommandRecipientL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiCustomEventCommandRecipientL );
    // Print to log file
    iLog->Log( KTestTHuiCustomEventCommandRecipientL );
    
    THuiCustomEventCommand* customEvent = 
        new ( ELeave ) THuiCustomEventCommand( 0 );
    STIF_ASSERT_NOT_NULL( customEvent );
    CleanupStack::PushL( customEvent );
    customEvent->Recipient();
    CleanupStack::Pop( 1 );
    if( customEvent )
        {
        delete customEvent;
        customEvent = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiCustomEventCommandParamL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiCustomEventCommandParamL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiCustomEventCommandParamL, "In TestTHuiCustomEventCommandParamL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiCustomEventCommandParamL );
    // Print to log file
    iLog->Log( KTestTHuiCustomEventCommandParamL );
    
    THuiCustomEventCommand* customEvent = 
        new ( ELeave ) THuiCustomEventCommand( 0 );
    STIF_ASSERT_NOT_NULL( customEvent );
    CleanupStack::PushL( customEvent );
    customEvent->Param();
    CleanupStack::Pop( 1 );
    if( customEvent )
        {
        delete customEvent;
        customEvent = NULL;
        }
    
    return KErrNone;
    
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiCustomEventCommandExtensionL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiCustomEventCommandExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiCustomEventCommandExtensionL, "In TestTHuiCustomEventCommandExtensionL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiCustomEventCommandExtensionL );
    // Print to log file
    iLog->Log( KTestTHuiCustomEventCommandExtensionL );
    
    TTestUiAifBlocksHuiCustomEventCommandChild* customEventChild = 
        new ( ELeave ) TTestUiAifBlocksHuiCustomEventCommandChild( 0 );
    STIF_ASSERT_NOT_NULL( customEventChild );
    CleanupStack::PushL( customEventChild );
    const TUid aExtensionUid = TUid::Null();
    TAny** aExtensionParams = NULL;
    customEventChild->SetCommandExtension( aExtensionUid, aExtensionParams );
    CleanupStack::Pop( 1 );
    if( customEventChild )
        {
        delete customEventChild;
        customEventChild = NULL;
        }
    
    return KErrNone;
    
    }

// [End of File]
