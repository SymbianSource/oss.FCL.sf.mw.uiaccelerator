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


#ifndef TESTUIAIFBLOCKSHUIIMAGECOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUIIMAGECOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>
// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiImageCommandChild
 * 
 */
class TTestUiAifBlocksHuiImageCommandChild : public THuiImageCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiImageCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiImageCommandChild* NewL( CHuiImageVisual& aImageVisual, const THuiImage& aImage, 
        THuiOp aOperation = EHuiOpSetPrimaryImage );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiImageCommandChild* NewLC( CHuiImageVisual& aImageVisual, const THuiImage& aImage, 
        THuiOp aOperation = EHuiOpSetPrimaryImage );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiImageCommandChild( CHuiImageVisual& aImageVisual, const THuiImage& aImage, 
        THuiOp aOperation = EHuiOpSetPrimaryImage );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension(const TUid& aExtensionUid, TAny** aExtensionParams);

    };

#endif // TESTUIAIFBLOCKSHUIIMAGECOMMANDCHILD_H
