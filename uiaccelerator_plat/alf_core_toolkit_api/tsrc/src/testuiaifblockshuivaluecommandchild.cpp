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


#include "testuiaifblockshuivaluecommandchild.h"

TTestUiAifBlocksHuiValueCommandChild::TTestUiAifBlocksHuiValueCommandChild( TAny* aOwner, THuiTimedValue& aValue, 
    THuiOp aOperation, TReal32 aTarget, TReal32 aTiming ):THuiValueCommand( aOwner, aValue, aOperation, aTarget, aTiming )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiValueCommandChild::~TTestUiAifBlocksHuiValueCommandChild()
    {
    }

TTestUiAifBlocksHuiValueCommandChild* TTestUiAifBlocksHuiValueCommandChild::NewLC( TAny* aOwner, THuiTimedValue& aValue, 
    THuiOp aOperation, TReal32 aTarget, TReal32 aTiming )
    {
    TTestUiAifBlocksHuiValueCommandChild* self = new (ELeave)TTestUiAifBlocksHuiValueCommandChild( aOwner, aValue, 
        aOperation, aTarget, aTiming );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiValueCommandChild* TTestUiAifBlocksHuiValueCommandChild::NewL( TAny* aOwner, THuiTimedValue& aValue, 
    THuiOp aOperation, TReal32 aTarget, TReal32 aTiming )
    {
    TTestUiAifBlocksHuiValueCommandChild* self=
        TTestUiAifBlocksHuiValueCommandChild::NewLC( aOwner, aValue, aOperation, aTarget, aTiming );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiValueCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiValueCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiValueCommand::CommandExtension( aExtensionUid, aExtensionParams );
    }
