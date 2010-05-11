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
* Description:  test function LoadBitmapsL, LoadControlGroupL in huienv.h
*
*/


#ifndef TESTUIAIFBLOCKSHUIACTIONCOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUIACTIONCOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

#include <uiacceltk/huicommand.h>

// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiActionCommandChild
 * 
 */
class TTestUiAifBlocksHuiActionCommandChild : public THuiActionCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiActionCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiActionCommandChild* NewL( TInt aId );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiActionCommandChild* NewLC( TInt aId );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiActionCommandChild( TInt aId );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension(const TUid& aExtensionUid, TAny** aExtensionParams);

    };

#endif // TESTUIAIFBLOCKSHUIACTIONCOMMANDCHILD_H
