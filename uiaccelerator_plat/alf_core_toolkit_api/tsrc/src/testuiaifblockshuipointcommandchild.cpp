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
* Description:  For test alf core toolkit api modules
*
*/


#include "testuiaifblockshuipointcommandchild.h"

TTestUiAifBlocksHuiPointCommandChild::TTestUiAifBlocksHuiPointCommandChild( TAny* aOwner, THuiTimedPoint& aPoint, 
    THuiOp aOperation ):THuiPointCommand( aOwner, aPoint, aOperation)
    {
    // No implementation required
    }

TTestUiAifBlocksHuiPointCommandChild::~TTestUiAifBlocksHuiPointCommandChild()
    {
    }

TTestUiAifBlocksHuiPointCommandChild* TTestUiAifBlocksHuiPointCommandChild::NewLC( TAny* aOwner, THuiTimedPoint& aPoint, 
    THuiOp aOperation )
    {
    TTestUiAifBlocksHuiPointCommandChild* self = new (ELeave)TTestUiAifBlocksHuiPointCommandChild( aOwner, aPoint, aOperation );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiPointCommandChild* TTestUiAifBlocksHuiPointCommandChild::NewL( TAny* aOwner, THuiTimedPoint& aPoint, 
    THuiOp aOperation )
    {
    TTestUiAifBlocksHuiPointCommandChild* self=
        TTestUiAifBlocksHuiPointCommandChild::NewLC( aOwner, aPoint, aOperation );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiPointCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiPointCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiPointCommand::CommandExtension( aExtensionUid, aExtensionParams );
    
    }
