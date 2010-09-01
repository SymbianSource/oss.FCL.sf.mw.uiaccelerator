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


#include "testuiaifblockshuigroupcommandchild.h"

TTestUiAifBlocksHuiGroupCommandChild::TTestUiAifBlocksHuiGroupCommandChild( CHuiControlGroup& aGroup, 
    THuiOp aOperation, CHuiDisplay* aDisplay ):THuiGroupCommand( aGroup, aOperation, aDisplay )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiGroupCommandChild::~TTestUiAifBlocksHuiGroupCommandChild()
    {
    }

TTestUiAifBlocksHuiGroupCommandChild* TTestUiAifBlocksHuiGroupCommandChild::NewLC(
    CHuiControlGroup& aGroup, THuiOp aOperation, CHuiDisplay* aDisplay )
    {
    TTestUiAifBlocksHuiGroupCommandChild* self = new (ELeave)TTestUiAifBlocksHuiGroupCommandChild(
    aGroup, aOperation, aDisplay );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiGroupCommandChild* TTestUiAifBlocksHuiGroupCommandChild::NewL(
    CHuiControlGroup& aGroup, THuiOp aOperation, CHuiDisplay* aDisplay )
    {
    TTestUiAifBlocksHuiGroupCommandChild* self= TTestUiAifBlocksHuiGroupCommandChild::NewLC(
        aGroup, aOperation, aDisplay);
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiGroupCommandChild::ConstructL()
    {

    }
void TTestUiAifBlocksHuiGroupCommandChild::SetCommandExtension(
        const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiGroupCommand::CommandExtension( aExtensionUid, aExtensionParams );
    }
