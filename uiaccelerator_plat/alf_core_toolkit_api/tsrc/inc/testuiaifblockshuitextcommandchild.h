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


#ifndef TESTUIAIFBLOCKSHUITEXTCOMMANDCHILD_H
#define TESTUIAIFBLOCKSHUITEXTCOMMANDCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huicommand.h>
// CLASS DECLARATION

/**
 *  TTestUiAifBlocksHuiTextCommandChild
 * 
 */
class TTestUiAifBlocksHuiTextCommandChild : public THuiTextCommand
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~TTestUiAifBlocksHuiTextCommandChild();

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiTextCommandChild* NewL( CHuiTextVisual& aTextVisual, const TDesC& aText, 
        THuiOp aOperation = EHuiOpSetText );

    /**
     * Two-phased constructor.
     */
    static TTestUiAifBlocksHuiTextCommandChild* NewLC( CHuiTextVisual& aTextVisual, const TDesC& aText, 
        THuiOp aOperation = EHuiOpSetText );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    TTestUiAifBlocksHuiTextCommandChild( CHuiTextVisual& aTextVisual, const TDesC& aText, 
        THuiOp aOperation = EHuiOpSetText );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams );

    };

#endif // TESTUIAIFBLOCKSHUITEXTCOMMANDCHILD_H
