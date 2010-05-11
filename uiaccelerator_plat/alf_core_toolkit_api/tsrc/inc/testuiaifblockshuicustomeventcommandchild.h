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


#ifndef TESTUIAIFBLOCKSHUICUSTOMEVENTCOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUICUSTOMEVENTCOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>
// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiCustomEventCommandChild
 * 
 */
class TTestUiAifBlocksHuiCustomEventCommandChild : public THuiCustomEventCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiCustomEventCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiCustomEventCommandChild* NewL( TInt aEventParam, MHuiEventHandler* aRecipient = NULL );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiCustomEventCommandChild* NewLC( TInt aEventParam, MHuiEventHandler* aRecipient = NULL );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiCustomEventCommandChild( TInt aEventParam, MHuiEventHandler* aRecipient = NULL );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension(const TUid& aExtensionUid, TAny** aExtensionParams);

    };

#endif // TESTUIAIFBLOCKSHUICUSTOMEVENTCOMMANDCHILD_H
