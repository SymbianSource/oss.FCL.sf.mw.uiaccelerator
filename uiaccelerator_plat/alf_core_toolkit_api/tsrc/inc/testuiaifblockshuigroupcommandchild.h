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


#ifndef TESTUIAIFBLOCKSHUIGROUPCOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUIGROUPCOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>

// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiGroupCommandChild
 * 
 */
class TTestUiAifBlocksHuiGroupCommandChild : public THuiGroupCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiGroupCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiGroupCommandChild* NewL( CHuiControlGroup& aGroup, THuiOp aOperation, 
        CHuiDisplay* aDisplay = NULL );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiGroupCommandChild* NewLC( CHuiControlGroup& aGroup, THuiOp aOperation, 
        CHuiDisplay* aDisplay = NULL );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiGroupCommandChild( CHuiControlGroup& aGroup, THuiOp aOperation, 
        CHuiDisplay* aDisplay = NULL );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension(const TUid& aExtensionUid, TAny** aExtensionParams);

    };

#endif // TESTUIAIFBLOCKSHUIGROUPCOMMANDCHILD_H
