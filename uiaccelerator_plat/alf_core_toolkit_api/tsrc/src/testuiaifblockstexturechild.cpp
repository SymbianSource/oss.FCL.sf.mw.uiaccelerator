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

#include <uiacceltk/huitexturemanager.h>

#include "testuiaifblockstexturechild.h"
#include "testuiaifblocksmanagerchild.h"

CTestUiAifBlocksTextureChild::CTestUiAifBlocksTextureChild( CHuiTextureManager& aManager ):
    CHuiAnimatedTexture( aManager )
    {
    // No implementation required
    }

void CTestUiAifBlocksTextureChild::AdvanceTime(TReal32 /*aElapsedTime*/)
    {
    
    }

CTestUiAifBlocksTextureChild::~CTestUiAifBlocksTextureChild()
    {
    
    }


CTestUiAifBlocksTextureChild* CTestUiAifBlocksTextureChild::NewL( CHuiTextureManager& aManager )
    {
    CTestUiAifBlocksTextureChild* self = new( ELeave )CTestUiAifBlocksTextureChild( aManager );
//    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop(); // self;
    return self;
    }

void CTestUiAifBlocksTextureChild::ConstructL()
    {
    CHuiAnimatedTexture::BaseConstructL();
    }

void CTestUiAifBlocksTextureChild::TextureExtension( const TUid& aExtensionUid, TAny** aExtensionParameters )
    {
    CHuiAnimatedTexture::TextureExtension( aExtensionUid,  aExtensionParameters );
    }

void CTestUiAifBlocksTextureChild::SetSegmentCountL( TInt aCount )
    {
    this->iTexture->SetSegmentCountL( aCount );
    }
