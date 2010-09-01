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
* Description:  for testing the method of the CHuiTextVisual
*
*/

#include <uiacceltk\huitextureautosizeparams.h>

#include "testuiaifcoretoolkit.h"


// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaConstructor( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaConstructor, "In TestHuiTexureAutoSizeParaConstructor" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaConstructor );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaConstructor );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaSizeLowerThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaSizeLowerThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaSizeLowerThreshold, "In TestHuiTexureAutoSizeParaSizeLowerThreshold" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaSizeLowerThreshold );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaSizeLowerThreshold );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.SizeLowerThreshold();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaSetSizeLowerThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaSetSizeLowerThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaSetSizeLowerThreshold, "In TestHuiTexureAutoSizeParaSetSizeLowerThreshold" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaSetSizeLowerThreshold );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaSetSizeLowerThreshold );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.SetSizeLowerThreshold( THuiTextureAutoSizeParams::EMedium );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaSizeUpperThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaSizeUpperThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaSizeUpperThreshold, "In TestHuiTexureAutoSizeParaSizeUpperThreshold" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaSizeUpperThreshold );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaSizeUpperThreshold );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.SizeUpperThreshold();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaSetSizeUpperThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaSetSizeUpperThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaSetSizeUpperThreshold, "In TestHuiTexureAutoSizeParaSetSizeUpperThreshold" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaSetSizeUpperThreshold );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaSetSizeUpperThreshold );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.SetSizeUpperThreshold( THuiTextureAutoSizeParams::EMedium );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaMinSizeChange
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaMinSizeChange( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaMinSizeChange, "In TestHuiTexureAutoSizeParaMinSizeChange" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaMinSizeChange );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaMinSizeChange );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.MinSizeChange();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaSetMinSizeChange
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaSetMinSizeChange( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaSetMinSizeChange, "In TestHuiTexureAutoSizeParaSetMinSizeChange" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaSetMinSizeChange );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaSetMinSizeChange );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.SetMinSizeChange( THuiTextureAutoSizeParams::EMedium );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaDownsizeSettleThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaDownsizeSettleThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaDownsizeSettleThreshold, "In TestHuiTexureAutoSizeParaDownsizeSettleThreshold" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaDownsizeSettleThreshold );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaDownsizeSettleThreshold );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.DownsizeSettleThreshold();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiTexureAutoSizeParaSetDownsizeSettleThreshold
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiTexureAutoSizeParaSetDownsizeSettleThreshold( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiTexureAutoSizeParaSetDownsizeSettleThreshold, "In TestHuiTexureAutoSizeParaSetDownsizeSettleThreshold" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiTexureAutoSizeParaSetDownsizeSettleThreshold );
    // Print to log file
    iLog->Log( KTestHuiTexureAutoSizeParaSetDownsizeSettleThreshold );
    
    THuiTextureAutoSizeParams huiTextureAutoSizeParams;
    huiTextureAutoSizeParams.SetDownsizeSettleThreshold( THuiTextureAutoSizeParams::EMedium );

    return KErrNone;

    }

// End of files
