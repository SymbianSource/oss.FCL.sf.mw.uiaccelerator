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


#ifndef TESTUIAIFBLOCKSHUIVISUALCOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUIVISUALCOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>
// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiVisualCommandChild
 * 
 */
class TTestUiAifBlocksHuiVisualCommandChild : public THuiVisualCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiVisualCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiVisualCommandChild* NewL( CHuiVisual& aVisual, THuiOp aOperation, 
        TInt aSetFlags = 0, TInt aClearFlags = 0  );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiVisualCommandChild* NewLC( CHuiVisual& aVisual, THuiOp aOperation, 
        TInt aSetFlags = 0, TInt aClearFlags = 0  );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiVisualCommandChild( CHuiVisual& aVisual, THuiOp aOperation, 
        TInt aSetFlags = 0, TInt aClearFlags = 0  );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension(const TUid& aExtensionUid, TAny** aExtensionParams);

    };

#endif // TESTUIAIFBLOCKSHUIVISUALCOMMANDCHILD_H
