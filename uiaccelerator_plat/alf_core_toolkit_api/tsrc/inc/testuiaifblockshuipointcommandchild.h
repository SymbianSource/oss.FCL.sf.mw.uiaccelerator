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


#ifndef TESTUIAIFBLOCKSHUIPOINTCOMMAND_H
#define TESTUIAIFBLOCKSHUIPOINTCOMMAND_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>
#include <uiacceltk/huitimedvalue.h>
// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiPointCommandChild
 * 
 */
class TTestUiAifBlocksHuiPointCommandChild : public THuiPointCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiPointCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiPointCommandChild* NewL( TAny* aOwner, THuiTimedPoint& aPoint, 
        THuiOp aOperation );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiPointCommandChild* NewLC( TAny* aOwner, THuiTimedPoint& aPoint, 
        THuiOp aOperation );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiPointCommandChild( TAny* aOwner, THuiTimedPoint& aPoint, 
        THuiOp aOperation );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams );

    };

#endif // TESTUIAIFBLOCKSHUIPOINTCOMMAND_H
