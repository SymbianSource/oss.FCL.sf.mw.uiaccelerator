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
* Description:  test functions for alftexturegroup.h
*
*/



// [INCLUDE FILES]
#include <alf/alftexturegroup.h>
#include <alf/alfbitmapprovider.h>

#include "testplatalfvisual.h"


// CONSTANTS
const TInt KProvidedBitmapWidth = 64;
const TInt KProvidedBitmapHeight = 64;

const TInt KTextureNum = 3;


// FORWARD DECLARATION
// CTestBmpProvider for testing methods of CAlfTextureGroup
class CTestBmpProvider : public CBase, public MAlfBitmapProvider
    {
public:
    /**
     * Provide a bitmap and mask from the given UID.
     * This method should create a bitmap and its mask, usually by loading it from disk.
     */
    void ProvideBitmapL(TInt /*aId*/, CFbsBitmap*& aBitmap, CFbsBitmap*& aBitmapMask)
        {
        aBitmap = new ( ELeave ) CFbsBitmap;
        aBitmapMask = new ( ELeave ) CFbsBitmap;
        TSize providedBitmapSize( KProvidedBitmapWidth, KProvidedBitmapHeight );
        aBitmap->Create( providedBitmapSize, EColor64K );
        aBitmapMask->Create( providedBitmapSize, EGray256 );
        }
    };

// CTestTextureGroupObserver for testing methods of CAlfTextureGroup
class CTestTextureGroupObserver : public CBase, public MAlfTextureGroupLoadingCompletedObserver
    {
public:
    /**
     * Constructor
     */
    CTestTextureGroupObserver() : iObservedTexturegroup( NULL ) {}
    
    /**
     * From MAlfTextureGroupLoadingCompletedObserver
     */
    void TextureGroupLoadingCompleted( CAlfTextureGroup& aTextureGroup, TInt /*aErrorCode*/ )
        {
        iObservedTexturegroup = &aTextureGroup;
        }
    
public:
    /**
     * OWN: Group of textures that has been loaded
     */
    CAlfTextureGroup* iObservedTexturegroup;
    };



// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CTestPlatAlfVisual::TestTxtGroupNewL
// -----------------------------------------------------------------------------
//
TInt CTestPlatAlfVisual::TestTxtGroupNewL( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( KTestPlatAlfVisual, "TestPlatAlfVisual" );
    _LIT( KTestTxtGroupNewL, "TestTxtGroupNewL" );
    TestModuleIf().Printf( 0, KTestPlatAlfVisual, KTestTxtGroupNewL );
    // Print to log file
    iLog->Log( KTestTxtGroupNewL );
    
    CAlfTextureGroup* txtGroup = CAlfTextureGroup::NewL( *iAlfEnv );
    CleanupStack::PushL( txtGroup );
    STIF_ASSERT_NOT_NULL( txtGroup );
    CleanupStack::PopAndDestroy( txtGroup );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestPlatAlfVisual::TestTxtGroupNewLCL
// -----------------------------------------------------------------------------
//
TInt CTestPlatAlfVisual::TestTxtGroupNewLCL( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( KTestPlatAlfVisual, "TestPlatAlfVisual" );
    _LIT( KTestTxtGroupNewLCL, "TestTxtGroupNewLCL" );
    TestModuleIf().Printf( 0, KTestPlatAlfVisual, KTestTxtGroupNewLCL );
    // Print to log file
    iLog->Log( KTestTxtGroupNewLCL );
    
    CAlfTextureGroup* txtGroup = CAlfTextureGroup::NewLC( *iAlfEnv );
    STIF_ASSERT_NOT_NULL( txtGroup );
    CleanupStack::PopAndDestroy( txtGroup );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestPlatAlfVisual::TestTxtGroupTextureMethodsL
// -----------------------------------------------------------------------------
//
TInt CTestPlatAlfVisual::TestTxtGroupTextureMethodsL( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( KTestPlatAlfVisual, "TestPlatAlfVisual" );
    _LIT( KTestTxtGroupTextureMethodsL, "TestTxtGroupTextureMethodsL" );
    TestModuleIf().Printf( 0, KTestPlatAlfVisual, KTestTxtGroupTextureMethodsL );
    // Print to log file
    iLog->Log( KTestTxtGroupTextureMethodsL );
    
    CAlfTextureGroup* txtGroup = CAlfTextureGroup::NewL( *iAlfEnv );
    CleanupStack::PushL( txtGroup );
    STIF_ASSERT_NOT_NULL( txtGroup );
    
    STIF_ASSERT_EQUALS( 0, txtGroup->Count() );

    CTestBmpProvider* bmpProvider = new ( ELeave ) CTestBmpProvider;
    CleanupStack::PushL( bmpProvider );
    STIF_ASSERT_NOT_NULL( bmpProvider );
    CAlfTextureManager& textureMgr = iAlfEnv->TextureManager();
    CAlfTexture& firstTexture = textureMgr.CreateTextureL(
            KAlfAutoGeneratedTextureId, bmpProvider, EAlfTextureFlagDefault );
    CAlfTexture& secondTexture = textureMgr.CreateTextureL(
            KAlfAutoGeneratedTextureId, bmpProvider, EAlfTextureFlagDefault );
    CAlfTexture& thirdTexture = textureMgr.CreateTextureL(
            KAlfAutoGeneratedTextureId, bmpProvider, EAlfTextureFlagDefault );

    // Add one texture
    txtGroup->AddTextureL( firstTexture );
    STIF_ASSERT_EQUALS( 1, txtGroup->Count() );
    STIF_ASSERT_EQUALS( &firstTexture, &txtGroup->Texture( 0 ) );
    
    // Try adding first texture again (it should not increase count)
    txtGroup->AddTextureL( firstTexture );
    STIF_ASSERT_EQUALS( 1, txtGroup->Count() );
    
    txtGroup->AddTextureL( secondTexture );
    STIF_ASSERT_EQUALS( 2, txtGroup->Count() );
    STIF_ASSERT_EQUALS( &firstTexture, &txtGroup->Texture( 0 ) );
    STIF_ASSERT_EQUALS( &secondTexture, &txtGroup->Texture( 1 ) );
    
    txtGroup->AddTextureL( thirdTexture );
    STIF_ASSERT_EQUALS( KTextureNum, txtGroup->Count() );
    STIF_ASSERT_EQUALS( &firstTexture, &txtGroup->Texture( 0 ) );
    STIF_ASSERT_EQUALS( &secondTexture, &txtGroup->Texture( 1 ) );
    STIF_ASSERT_EQUALS( &thirdTexture, &txtGroup->Texture( 2 ) );
    
    // Try adding first texture again (it should not increase count)
    txtGroup->AddTextureL( firstTexture );
    STIF_ASSERT_EQUALS( KTextureNum, txtGroup->Count() );
    
    txtGroup->RemoveTexture( secondTexture );
    STIF_ASSERT_EQUALS( &firstTexture, &txtGroup->Texture( 0 ) );
    STIF_ASSERT_EQUALS( &thirdTexture, &txtGroup->Texture( 1 ) );
    STIF_ASSERT_EQUALS( 2, txtGroup->Count() );
    
    // add removed back
    txtGroup->AddTextureL( secondTexture );
    STIF_ASSERT_EQUALS( KTextureNum, txtGroup->Count() );
    
    // Remove succesful first texture
    txtGroup->RemoveTexture( firstTexture );
    STIF_ASSERT_EQUALS( 2, txtGroup->Count() );
    
    // Try to remove texture which does not exist (unsuccesful)
    txtGroup->RemoveTexture( firstTexture );
    STIF_ASSERT_EQUALS( 2, txtGroup->Count() );
    
    // Remove succesful last texture of array
    txtGroup->RemoveTexture( thirdTexture );
    STIF_ASSERT_EQUALS( 1, txtGroup->Count() );
    
    // Remove succesful last texture 
    txtGroup->RemoveTexture( secondTexture );
    STIF_ASSERT_EQUALS( 0, txtGroup->Count() );
    
    // Remove from empty group (unsuccesful)
    txtGroup->RemoveTexture( secondTexture );
    STIF_ASSERT_EQUALS( 0, txtGroup->Count() );
    
    CleanupStack::PopAndDestroy( bmpProvider );
    CleanupStack::PopAndDestroy( txtGroup );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestPlatAlfVisual::TestTxtGroupIsLoadingCompletedL
// -----------------------------------------------------------------------------
//
TInt CTestPlatAlfVisual::TestTxtGroupIsLoadingCompletedL( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( KTestPlatAlfVisual, "TestPlatAlfVisual" );
    _LIT( KTestTxtGroupIsLoadingCompletedL, "TestTxtGroupIsLoadingCompletedL" );
    TestModuleIf().Printf( 0, KTestPlatAlfVisual, KTestTxtGroupIsLoadingCompletedL );
    // Print to log file
    iLog->Log( KTestTxtGroupIsLoadingCompletedL );
    
    CAlfTextureGroup* txtGroup = CAlfTextureGroup::NewL( *iAlfEnv );
    CleanupStack::PushL( txtGroup );
    STIF_ASSERT_NOT_NULL( txtGroup );
    
    STIF_ASSERT_FALSE( txtGroup->IsLoadingCompleted() );

    CAlfTextureManager& textureMgr = iAlfEnv->TextureManager();
    CTestBmpProvider* bmpProvider = new ( ELeave ) CTestBmpProvider;
    CleanupStack::PushL( bmpProvider );
    STIF_ASSERT_NOT_NULL( bmpProvider );
    CAlfTexture& firstTexture = textureMgr.CreateTextureL(
                    KAlfAutoGeneratedTextureId, bmpProvider, EAlfTextureFlagDefault );

    // Add one texture that has content
    txtGroup->AddTextureL( firstTexture );
    txtGroup->IsLoadingCompleted();
    
    // Unload texture content
    textureMgr.UnloadTexture( firstTexture.Id() );
    txtGroup->IsLoadingCompleted();
    
    // restore texture content
    textureMgr.UpdateTextureFromBitmapL( firstTexture.Id() );
    txtGroup->IsLoadingCompleted();
    
    CleanupStack::PopAndDestroy( bmpProvider );
    CleanupStack::PopAndDestroy( txtGroup );
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestPlatAlfVisual::TestTxtGroupObserverMethodsL
// -----------------------------------------------------------------------------
//
TInt CTestPlatAlfVisual::TestTxtGroupObserverMethodsL( CStifItemParser& /*aItem*/ )
    {
    // Print to UI
    _LIT( KTestPlatAlfVisual, "TestPlatAlfVisual" );
    _LIT( KTestTxtGroupObserverMethodsL, "TestTxtGroupObserverMethodsL" );
    TestModuleIf().Printf( 0, KTestPlatAlfVisual, KTestTxtGroupObserverMethodsL );
    // Print to log file
    iLog->Log( KTestTxtGroupObserverMethodsL );
    
    CAlfTextureGroup* txtGroup = CAlfTextureGroup::NewL( *iAlfEnv );
    CleanupStack::PushL( txtGroup );
    STIF_ASSERT_NOT_NULL( txtGroup );
    CTestTextureGroupObserver* testObserver = new ( ELeave ) CTestTextureGroupObserver;
    CleanupStack::PushL( testObserver );
    STIF_ASSERT_NOT_NULL( testObserver );
    
    txtGroup->AddLoadObserverL( *testObserver );
    txtGroup->RemoveLoadObserver( *testObserver );
    
    txtGroup->RemoveLoadObserver( *testObserver );
    txtGroup->AddLoadObserverL( *testObserver );
    txtGroup->RemoveLoadObserver( *testObserver );

    CAlfTextureManager& textureMgr = iAlfEnv->TextureManager();
    CTestBmpProvider* bmpProvider = new ( ELeave ) CTestBmpProvider;
    CleanupStack::PushL( bmpProvider );
    STIF_ASSERT_NOT_NULL( bmpProvider );
    CAlfTexture& firstTexture = textureMgr.CreateTextureL(
                    KAlfAutoGeneratedTextureId, bmpProvider, EAlfTextureFlagDefault );
    
    // Add one texture that has content
    txtGroup->AddTextureL( firstTexture );
    
    // Unload texture content
    textureMgr.UnloadTexture( firstTexture.Id() );
    testObserver->iObservedTexturegroup = NULL;
    
    // restore texture content
    textureMgr.UpdateTextureFromBitmapL( firstTexture.Id() );
    
    txtGroup->AddLoadObserverL( *testObserver );

    // Add one texture that has content
    txtGroup->AddTextureL( firstTexture );
    
    // Unload texture content
    textureMgr.UnloadTexture( firstTexture.Id() );
    testObserver->iObservedTexturegroup = NULL;
    
    // restore texture content
    textureMgr.UpdateTextureFromBitmapL( firstTexture.Id() );
    
    // Unload texture content
    textureMgr.UnloadTexture( firstTexture.Id() );
    testObserver->iObservedTexturegroup = NULL;
    
    // Disable observing
    txtGroup->EnableLoadObservers( EFalse );
    
    // restore texture content
    textureMgr.UpdateTextureFromBitmapL( firstTexture.Id() );

    // Unload texture content
    textureMgr.UnloadTexture( firstTexture.Id() );
    testObserver->iObservedTexturegroup = NULL;
    
    // Enable observing
    txtGroup->EnableLoadObservers( ETrue );

    // restore texture content
    textureMgr.UpdateTextureFromBitmapL( firstTexture.Id() );

    txtGroup->RemoveLoadObserver( *testObserver );
    
    CleanupStack::PopAndDestroy( bmpProvider );
    CleanupStack::PopAndDestroy( testObserver );
    CleanupStack::PopAndDestroy( txtGroup );
    
    return KErrNone;
    }


//  [End of File]
