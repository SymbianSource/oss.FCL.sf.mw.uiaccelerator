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


#ifndef TESTUIAIFBLOCKSHUIVALUECOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUIVALUECOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>
// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiValueCommandChild
 * 
 */
class TTestUiAifBlocksHuiValueCommandChild : public THuiValueCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiValueCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiValueCommandChild* NewL( TAny* aOwner, THuiTimedValue& aValue, 
        THuiOp aOperation = EHuiOpSet,
        TReal32 aTarget = 0.0, TReal32 aTiming = 0.0 );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiValueCommandChild* NewLC( TAny* aOwner, THuiTimedValue& aValue, 
        THuiOp aOperation = EHuiOpSet,
        TReal32 aTarget = 0.0, TReal32 aTiming = 0.0 );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiValueCommandChild( TAny* aOwner, THuiTimedValue& aValue, 
        THuiOp aOperation = EHuiOpSet,
        TReal32 aTarget = 0.0, TReal32 aTiming = 0.0 );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();

    void SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams );
    };

#endif // TESTUIAIFBLOCKSHUIVALUECOMMANDCHILD_H
