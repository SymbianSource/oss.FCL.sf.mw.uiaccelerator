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
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huistatic.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticEnv
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticEnv( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticEnv" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::Env();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::Time();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticSetTimeFactor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticSetTimeFactor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticSetTimeFactor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::SetTimeFactor( 10.50 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticTimeFactor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticTimeFactor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticTimeFactor" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    TReal32 time = CHuiStatic::TimeFactor();
    CHuiStatic::SetTimeFactor( 10 );
    time = CHuiStatic::TimeFactor();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticPauseTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticPauseTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticPauseTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    iHuiEnv->RefreshCallBack(iHuiEnv);    

    // Sleep for 1430 milliseconds
    User::After(TTimeIntervalMicroSeconds32(1430000));
        
    // Pause timing
    CHuiStatic::PauseTime();      
    TReal32 pausedSeconds = CHuiStatic::ElapsedSeconds();

    // Sleep for another 1430 milliseconds
    User::After(TTimeIntervalMicroSeconds32(1430000));

    // Update time
    // @note This is rather awkward way to update the time. Perhaps we should make a unit test of CHuiStatic instead
    // and call CHuiStatic::UpdateTime() there.
    iHuiEnv->RefreshCallBack(iHuiEnv);

    // Retrieve the elapsed seconds
    TReal32 elapsedSeconds = CHuiStatic::ElapsedSeconds();

    STIF_ASSERT_TRUE( pausedSeconds == elapsedSeconds );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticContinueTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticContinueTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticContinueTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::ContinueTime();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticTimePaused
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticTimePaused( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticTimePaused" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::TimePaused();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticElapsedSeconds
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticElapsedSeconds( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticElapsedSeconds" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::ElapsedSeconds();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticSecondsSinceStart
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticSecondsSinceStart( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticSecondsSinceStart" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::SecondsSinceStart();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticMilliSecondsSinceStart
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticMilliSecondsSinceStart( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticMilliSecondsSinceStart" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::MilliSecondsSinceStart();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticFrameCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticFrameCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticFrameCount" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::FrameCount();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticAverageFrameRate
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticAverageFrameRate( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticAverageFrameRate" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::AverageFrameRate();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticFrameRate
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticFrameRate( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticFrameRate" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::FrameRate();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticPrintfTDesC8
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticPrintfTDesC8( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticPrintfTDesC8" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    TRefByValue<const TDesC8> value = _L8( "value" );
    CHuiStatic::Printf( value );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticPrintfTDesC16
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticPrintfTDesC16( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticPrintfTDesC16" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    TRefByValue<const TDesC16> value = _L16( "value" );
    CHuiStatic::Printf( value );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticEnableLogging
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticEnableLogging( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticEnableLogging" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::EnableLogging();
    CHuiStatic::EnableLogging( EFalse );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticLogging
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticLogging( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticLogging" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::EnableLogging();
    TBool logging = CHuiStatic::Logging();
    STIF_ASSERT_TRUE( logging );

    CHuiStatic::EnableLogging( EFalse );
    logging = CHuiStatic::Logging();
    STIF_ASSERT_FALSE( logging );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticTic
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticTic( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticTic" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::Tic( 0 );
    CHuiStatic::Tic( 1 );
    CHuiStatic::Tic( 2 );
    CHuiStatic::Tic( 3 );
    CHuiStatic::Tic( 4 );
    CHuiStatic::Tic( 5 );
    CHuiStatic::Tic( 6 );
    CHuiStatic::Tic( 7 );
    CHuiStatic::Tic( 8 );
    CHuiStatic::Tic( 9 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticToc
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticToc( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticToc" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::Toc( 0 );
    CHuiStatic::Toc( 1 );
    CHuiStatic::Toc( 2 );
    CHuiStatic::Toc( 3 );
    CHuiStatic::Toc( 4 );
    CHuiStatic::Toc( 5 );
    CHuiStatic::Toc( 6 );
    CHuiStatic::Toc( 7 );
    CHuiStatic::Toc( 8 );
    CHuiStatic::Toc( 9 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticFsSession
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticFsSession( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticFsSession" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::FsSession();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticSetLayoutTransitionTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticSetLayoutTransitionTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticSetLayoutTransitionTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::SetLayoutTransitionTime( 1000 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticLayoutTransitionTime
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticLayoutTransitionTime( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticLayoutTransitionTime" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::SetLayoutTransitionTime( 1000 );
    TInt time = CHuiStatic::LayoutTransitionTime();
    STIF_ASSERT_EQUALS( time, 1000 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestCHuiStaticSetProbe
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestCHuiStaticSetProbe( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KCHuiStatic, "In TestCHuiStaticSetProbe" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KCHuiStatic );
    // Print to log file
    iLog->Log( KCHuiStatic );

    CHuiStatic::SetProbe( NULL );

    return KErrNone;
    }
