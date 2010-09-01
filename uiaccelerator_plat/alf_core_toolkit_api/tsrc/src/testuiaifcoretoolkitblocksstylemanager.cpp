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
#include <gdi.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huistatic.h>
#include <uiacceltk/huitextstylemanager.h>

#include "testuiaifcoretoolkit.h"

//the const variable
const TInt KTextStyle = 2;

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCHuiEnvL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCHuiEnvL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCHuiEnvL, "In TestTHuiTextCHuiEnvL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextCHuiEnvL );
    // Print to log file
    iLog->Log( KTestTHuiTextCHuiEnvL );
    
    CHuiTextStyleManager* styleManager = &iHuiEnv->TextStyleManager();
    styleManager->CreatePlatformTextStyleL( KTextStyle );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextTextStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextTextStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextTextStyle, "In TestTHuiTextTextStyle" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextTextStyle );
    // Print to log file
    iLog->Log( KTestTHuiTextTextStyle );
    
    CHuiTextStyleManager* styleManager = &iHuiEnv->TextStyleManager();
    styleManager->TextStyle( KTextStyle );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextCopyTextStyleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextCopyTextStyleL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextCopyTextStyleL, "In TestTHuiTextCopyTextStyleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTHuiTextCopyTextStyleL );
    // Print to log file
    iLog->Log( KTestTHuiTextCopyTextStyleL );
    
    CHuiTextStyleManager* styleManager = &iHuiEnv->TextStyleManager();
    styleManager->CopyTextStyleL( KTextStyle );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiTextDeleteTextStyle
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiTextDeleteTextStyle( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiTextDeleteTextStyle, "In TestTHuiTextDeleteTextStyle" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiTextDeleteTextStyle );
    // Print to log file
    iLog->Log( KTestTHuiTextDeleteTextStyle );
    
    CHuiTextStyleManager* styleManager = &iHuiEnv->TextStyleManager();
    styleManager->DeleteTextStyle( KTextStyle );
    
    return KErrNone;
    }

//  [End of File]
