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


#include "testuiaifblockshuitranscommandchild.h"

TTestUiAifBlocksHuiTransCommandChild::TTestUiAifBlocksHuiTransCommandChild( TAny* aOwner, CHuiTransformation& aTransformation,
    THuiOp aOperation, TInt aStep ):THuiTransformationCommand( aOwner, aTransformation, aOperation, aStep )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiTransCommandChild::~TTestUiAifBlocksHuiTransCommandChild()
    {
    }

TTestUiAifBlocksHuiTransCommandChild* TTestUiAifBlocksHuiTransCommandChild::NewLC( TAny* aOwner, CHuiTransformation& aTransformation,
    THuiOp aOperation, TInt aStep )
    {
    TTestUiAifBlocksHuiTransCommandChild* self = new (ELeave)TTestUiAifBlocksHuiTransCommandChild( aOwner, aTransformation,
        aOperation, aStep );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiTransCommandChild* TTestUiAifBlocksHuiTransCommandChild::NewL( TAny* aOwner, CHuiTransformation& aTransformation,
    THuiOp aOperation, TInt aStep )
    {
    TTestUiAifBlocksHuiTransCommandChild* self=
        TTestUiAifBlocksHuiTransCommandChild::NewLC( aOwner, aTransformation,
            aOperation, aStep );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiTransCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiTransCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiTransformationCommand::CommandExtension( aExtensionUid, aExtensionParams );
    }
