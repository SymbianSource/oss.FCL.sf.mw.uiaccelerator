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

#include <uiacceltk\huiimageloaderutil.h>

#include "testuiaifcoretoolkit.h"

const TInt KWidth = 10;
const TInt KHeight = 10;
const TInt KMajor = 5;
const TInt KMinor = 0;

enum TTestEnum
    {
    EBitmapId,
    EBitmapMaskId
    };

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilConstructor
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilConstructorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilConstructor, "In TestHuiImageLoaderUtilConstructor" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilConstructor );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilConstructor );
    
    iHuiImageLoaderUtil = new( ELeave ) CHuiImageLoaderUtil();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilDelete
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilDelete( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilDelete, "In TestHuiImageLoaderUtilDelete" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilDelete );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilDelete );
    
    delete iHuiImageLoaderUtil;
    iHuiImageLoaderUtil = NULL;

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilCreateImageLoaderL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilCreateImageLoaderL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilCreateImageLoaderL, "In TestHuiImageLoaderUtilCreateImageLoaderL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilCreateImageLoaderL );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilCreateImageLoaderL );
    
    TAknsItemID id;
    id.Set( KMajor, KMinor );
    
    iHuiImageLoaderUtil->CreateImageLoaderL( id, _L("test.bmp"), EBitmapId, EBitmapMaskId );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilCreateImageLoaderLWithAppUid
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilCreateImageLoaderLWithAppUidL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilCreateImageLoaderLWithAppUid, "In TestHuiImageLoaderUtilCreateImageLoaderLWithAppUid" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilCreateImageLoaderLWithAppUid );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilCreateImageLoaderLWithAppUid );
    
    TUid uid =  { KTestScreenBufferUidValue };
    
    iHuiImageLoaderUtil->CreateImageLoaderL( uid, EAknsAppIconTypeList );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilSetSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilSetSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilSetSize, "In TestHuiImageLoaderUtilSetSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilSetSize );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilSetSize );
    
    TSize size( KWidth, KHeight );
    
    iHuiImageLoaderUtil->SetSize( size );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilSetSkinInstance
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilSetSkinInstance( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilSetSkinInstance, "In TestHuiImageLoaderUtilSetSkinInstance" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilSetSkinInstance );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilSetSkinInstance );
    
    MAknsSkinInstance* skinInstance = NULL;
    
    iHuiImageLoaderUtil->SetSkinInstance( skinInstance );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiImageLoaderUtilImageLoaderExtension
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiImageLoaderUtilImageLoaderExtension( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiImageLoaderUtilImageLoaderExtension, "In TestHuiImageLoaderUtilImageLoaderExtension" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiImageLoaderUtilImageLoaderExtension );
    // Print to log file
    iLog->Log( KTestHuiImageLoaderUtilImageLoaderExtension );
    
    TUid uid;
    uid.Null();
    
    iHuiImageLoaderUtil->ImageLoaderExtension( uid, NULL );

    return KErrNone;

    }

// End of files
