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
#include <uiacceltk/huidropshadow.h>
#include <uiacceltk/huisegmentedtexture.h>

#include "testuiaifcoretoolkit.h"
#include "testuiaifblockstexturechild.h"
#include "testuiaifblocksmanagerchild.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuisegmentedTextureHandleL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuisegmentedTextureHandleL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuisegmentedTextureHandleL, "In TestHuisegmentedTextureHandleL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestHuisegmentedTextureHandleL );
    // Print to log file 
    iLog->Log( KTestHuisegmentedTextureHandleL );
    
    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    
    TInt segment = 0;
    TInt number = 1;
    textureChild->SetSegmentCountL( number );
    MHuiSegmentedTexture* segmentedTeexture  = textureChild->SegmentedTexture();
    segmentedTeexture->Handle( segment );
    
    CleanupStack::PushL( textureChild );
    CleanupStack::PopAndDestroy( textureChild );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuisegmentedTextureBindL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuisegmentedTextureBindL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuisegmentedTextureBindL, "In TestHuisegmentedTextureBindL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestHuisegmentedTextureBindL );
    // Print to log file 
    iLog->Log( KTestHuisegmentedTextureBindL );
    
    CTestUiAifBlocksManagerChild* managerChild =new ( ELeave ) CTestUiAifBlocksManagerChild;
    STIF_ASSERT_NOT_NULL( managerChild );
    CleanupStack::PushL( managerChild );
    CTestUiAifBlocksTextureChild* textureChild = CTestUiAifBlocksTextureChild::NewL( *managerChild );
    STIF_ASSERT_NOT_NULL( textureChild );
    
    TInt number = 1;
    textureChild->SetSegmentCountL( number );
    MHuiSegmentedTexture* segmentedTeexture  = textureChild->SegmentedTexture();
    segmentedTeexture->Bind();
    
    CleanupStack::PushL( textureChild );
    CleanupStack::PopAndDestroy( textureChild );
    
    return KErrNone;
    
    }

//  [End of File]
