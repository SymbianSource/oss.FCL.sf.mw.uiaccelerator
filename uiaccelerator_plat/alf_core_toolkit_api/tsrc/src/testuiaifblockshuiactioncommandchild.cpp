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


#include "testuiaifblockshuiactioncommandchild.h"

TTestUiAifBlocksHuiActionCommandChild::TTestUiAifBlocksHuiActionCommandChild( TInt aId )
:THuiActionCommand( aId )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiActionCommandChild::~TTestUiAifBlocksHuiActionCommandChild()
    {
    }

TTestUiAifBlocksHuiActionCommandChild* TTestUiAifBlocksHuiActionCommandChild::NewLC( TInt aId )
    {
    TTestUiAifBlocksHuiActionCommandChild* self = 
        new (ELeave)TTestUiAifBlocksHuiActionCommandChild( aId );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }
TTestUiAifBlocksHuiActionCommandChild* TTestUiAifBlocksHuiActionCommandChild::NewL( TInt aId )
    {
    TTestUiAifBlocksHuiActionCommandChild* self=
        TTestUiAifBlocksHuiActionCommandChild::NewLC( aId );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiActionCommandChild::ConstructL()
    {

    }
void TTestUiAifBlocksHuiActionCommandChild::SetCommandExtension(const TUid& aExtensionUid, TAny** aExtensionParams)
    {
    THuiActionCommand::CommandExtension( aExtensionUid, aExtensionParams);
    }
