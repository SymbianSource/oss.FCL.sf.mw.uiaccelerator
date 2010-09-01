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



// INCLUDE FILES
#include <stiftestinterface.h>
#include <settingserverclient.h>
#include <screensaverinternalpskeys.h>
#include <e32property.h>

#include "testuiaifcoretoolkit.h"

// CONSTANTS
_LIT( KModuleName, "testuiaifcoretoolkit.dll" );


// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::CTestUiAifCoreToolkit
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CTestUiAifCoreToolkit::CTestUiAifCoreToolkit( CTestModuleIf& aTestModuleIf ):
    CScriptBase( aTestModuleIf )
    {
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::~CTestUiAifCoreToolkit
// Destructor.
// -----------------------------------------------------------------------------
//
CTestUiAifCoreToolkit::~CTestUiAifCoreToolkit()
    {
    // Delete logger
    delete iLog; 
    
    delete iHuiEnv;
    iHuiEnv = NULL;

    }
// -----------------------------------------------------------------------------

// Construct the needed member

// -----------------------------------------------------------------------------

void CTestUiAifCoreToolkit::ContructNeededMemberL()

    {
    //construct the environment
    iHuiEnv = CHuiEnv::NewL( EHuiRendererBitgdi );
    TRect rect = CEikonEnv::Static()->AppUiFactory()->ClientRect();    
    iHuiControlGroup = &( iHuiEnv->NewControlGroupL( KHuiCtrlGroupId ) );
    iDisplayRect = TRect(TPoint(KTestDisplayPosX, KTestDisplayPosY),
        TSize(KTestDisplayWidth, KTestDisplayHeight));
    
    //Construct the iHuiControl 
    iHuiControl = new( ELeave ) CHuiControl( *iHuiEnv );
    iHuiControl->ConstructL();
    iHuiCtrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );
    iHuiDisplay = &iHuiCtrl->Display();
    iHuiControlGroup->AppendL( iHuiControl );
    iHuiControl->BindDisplay( *iHuiDisplay );
    }


// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CTestUiAifCoreToolkit::ConstructL()
    {
    //Read logger settings to check whether test case name is to be
    //appended to log file name.
    RSettingServer settingServer;
    CleanupClosePushL( settingServer );
    TInt ret = settingServer.Connect();
    if ( ret != KErrNone )
        {
        User::Leave(ret);
        }
    // Struct to StifLogger settigs.
    TLoggerSettings loggerSettings; 
    // Parse StifLogger defaults from STIF initialization file.
    ret = settingServer.GetLoggerSettings( loggerSettings );
    if ( ret != KErrNone )
        {
        User::Leave( ret );
        } 
    // Close Setting server session
    settingServer.Close();
    CleanupStack::PopAndDestroy( &settingServer );

    TFileName logFileName;
    
    if ( loggerSettings.iAddTestCaseTitle )
        {
        TName title;
        TestModuleIf().GetTestCaseTitleL( title );
        logFileName.Format( KtestuiaifcoretoolkitLogFileWithTitle, &title );
        }
    else
        {
        logFileName.Copy( KtestuiaifcoretoolkitLogFile );
        }

    iLog = CStifLogger::NewL( KtestuiaifcoretoolkitLogPath, 
                          logFileName,
                          CStifLogger::ETxt,
                          CStifLogger::EFile,
                          EFalse );
    
    SendTestClassVersion();
    
    TurnOffScreenSaver();
    
    ContructNeededMemberL();
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CTestUiAifCoreToolkit* CTestUiAifCoreToolkit::NewL( CTestModuleIf& aTestModuleIf )
    {
    CTestUiAifCoreToolkit* self = new( ELeave ) CTestUiAifCoreToolkit( aTestModuleIf );

    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop( self );

    return self;

    }

//-----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::SendTestClassVersion
// Method used to send version of test class
//-----------------------------------------------------------------------------
//
void CTestUiAifCoreToolkit::SendTestClassVersion()
    {
    TVersion moduleVersion;
    moduleVersion.iMajor = TEST_CLASS_VERSION_MAJOR;
    moduleVersion.iMinor = TEST_CLASS_VERSION_MINOR;
    moduleVersion.iBuild = TEST_CLASS_VERSION_BUILD;

    TFileName moduleName;
    moduleName = KModuleName;

    TBool newVersionOfMethod = ETrue;
    TestModuleIf().SendTestModuleVersion( moduleVersion, moduleName, 
        newVersionOfMethod );
    }

// ========================== OTHER EXPORTED FUNCTIONS =========================

// -----------------------------------------------------------------------------
// LibEntryL is a polymorphic Dll entry point.
// Returns: CScriptBase: New CScriptBase derived object
// -----------------------------------------------------------------------------
//
EXPORT_C CScriptBase* LibEntryL( 
    CTestModuleIf& aTestModuleIf ) // Backpointer to STIF Test Framework
    {
    return ( CScriptBase* ) CTestUiAifCoreToolkit::NewL( aTestModuleIf );
    }

// -----------------------------------------------------------------------------
// Turn off ScreenSaver
// -----------------------------------------------------------------------------
//
void CTestUiAifCoreToolkit::TurnOffScreenSaver()
    {
    TInt err1 = RProperty::Get( KPSUidScreenSaver, KScreenSaverAllowScreenSaver, 
        iOldScreenSaverProperty );
    TInt err2 = RProperty::Set( KPSUidScreenSaver, KScreenSaverAllowScreenSaver, 
        KScreenSaverAllowScreenSaver );    
    RDebug::Printf( "screensaver property=%d err1=%d err2=%d\n", 
        iOldScreenSaverProperty, err1, err2 );
    }

// -----------------------------------------------------------------------------
// Restore ScreenSaver
// -----------------------------------------------------------------------------
//
void CTestUiAifCoreToolkit::RestoreScreenSaver()
    {
    RProperty::Set( KPSUidScreenSaver, KScreenSaverAllowScreenSaver, 
        iOldScreenSaverProperty );
    User::ResetInactivityTime();
    }

//  End of File
