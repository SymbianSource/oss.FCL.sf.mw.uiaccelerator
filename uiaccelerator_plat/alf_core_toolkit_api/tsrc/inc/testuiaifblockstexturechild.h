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


#ifndef TESTUIAIFBLOCKSTEXTURECHILD_H
#define TESTUIAIFBLOCKSTEXTURECHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huianimatedtexture.h>
// CLASS DECLARATION

/**
 *  CTestUiAifBlocksTextureChild
 * 
 */
class CTestUiAifBlocksTextureChild : public CHuiAnimatedTexture
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~CTestUiAifBlocksTextureChild();

    /**
     * Two-phased constructor.
     */
    static CTestUiAifBlocksTextureChild* NewL( CHuiTextureManager& aManager );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    CTestUiAifBlocksTextureChild( CHuiTextureManager& aManager );
    
    void AdvanceTime(TReal32 aElapsedTime);
public:
    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void TextureExtension( const TUid& aExtensionUid, TAny** aExtensionParameters );

    void SetSegmentCountL( TInt aCount = 4 );
    };

#endif // TESTUIAIFBLOCKSTEXTURECHILD_H
