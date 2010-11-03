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


#ifndef TESTUIAIFBLOCKSHUICONTROLCHILD_H
#define TESTUIAIFBLOCKSHUICONTROLCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>

// CLASS DECLARATION

/**
 *  CTestUiAifBlocksHuiControlChild
 * 
 */
class CTestUiAifBlocksHuiControlChild : public CHuiControl
    {
public:
    // Constructors and destructor

    /**
     * Destructor.
     */
    ~CTestUiAifBlocksHuiControlChild();

    /**
     * Two-phased constructor.
     */
    static CTestUiAifBlocksHuiControlChild* NewL( CHuiEnv& aEnv );

    /**
     * Two-phased constructor.
     */
    static CTestUiAifBlocksHuiControlChild* NewLC( CHuiEnv& aEnv );

public:

    /**
     * Constructor for performing 1st stage construction
     */
    CTestUiAifBlocksHuiControlChild( CHuiEnv& aEnv );

    /**
     * EPOC default constructor for performing 2nd stage construction
     */
    void ConstructL();
    
    void ChildNotifyControlVisibility( TBool aIsVisible, CHuiDisplay& aDisplay );
    
    void ChildVisualAddedL( CHuiVisual* aVisual );
    
    void ChildVisualRemovedL( CHuiVisual* aVisual );
    
    void ChildConnectionAddedL( CHuiControl* aConnectedControl, TInt aRole );
    
    void ChildConnectionRemovedL( CHuiControl* aConnectedControl, TInt aRole );
    
    void ChildHostChangingL( CHuiControl* aNewHost );
    
    void ChildBaseConstructL();
    
    void ChildControlExtensionL( const TUid& aExtensionUid, TAny** aExtensionParams );

    void ChildTypeL();

    TInt ChildSessionIdL();

    void ChildSetSessionIdL( TInt aSessionId );

    };

#endif // TESTUIAIFBLOCKSHUICONTROLCHILD_H
