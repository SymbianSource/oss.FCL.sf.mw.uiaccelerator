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


#include "testuiaifblockshuicustomeventcommandchild.h"

TTestUiAifBlocksHuiCustomEventCommandChild::TTestUiAifBlocksHuiCustomEventCommandChild( TInt aEventParam, 
    MHuiEventHandler* aRecipient ):THuiCustomEventCommand( aEventParam, aRecipient )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiCustomEventCommandChild::~TTestUiAifBlocksHuiCustomEventCommandChild()
    {
    }

TTestUiAifBlocksHuiCustomEventCommandChild* TTestUiAifBlocksHuiCustomEventCommandChild::NewLC( TInt aEventParam, 
    MHuiEventHandler* aRecipient )
    {
    TTestUiAifBlocksHuiCustomEventCommandChild* self = new (ELeave)TTestUiAifBlocksHuiCustomEventCommandChild( aEventParam, 
    aRecipient );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiCustomEventCommandChild* TTestUiAifBlocksHuiCustomEventCommandChild::NewL( TInt aEventParam, 
    MHuiEventHandler* aRecipient )
    {
    TTestUiAifBlocksHuiCustomEventCommandChild* self=
        TTestUiAifBlocksHuiCustomEventCommandChild::NewLC( aEventParam, aRecipient );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiCustomEventCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiCustomEventCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiCustomEventCommand::CommandExtension( aExtensionUid, aExtensionParams );
    
    }
