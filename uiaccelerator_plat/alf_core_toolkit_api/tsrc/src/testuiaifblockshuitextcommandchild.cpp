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


#include "testuiaifblockshuitextcommandchild.h"

TTestUiAifBlocksHuiTextCommandChild::TTestUiAifBlocksHuiTextCommandChild( CHuiTextVisual& aTextVisual, const TDesC& aText, 
    THuiOp aOperation ):THuiTextCommand( aTextVisual, aText, aOperation )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiTextCommandChild::~TTestUiAifBlocksHuiTextCommandChild()
    {
    }

TTestUiAifBlocksHuiTextCommandChild* TTestUiAifBlocksHuiTextCommandChild::NewLC( CHuiTextVisual& aTextVisual, const TDesC& aText, 
    THuiOp aOperation )
    {
    TTestUiAifBlocksHuiTextCommandChild* self = new (ELeave)TTestUiAifBlocksHuiTextCommandChild( aTextVisual, aText, aOperation );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiTextCommandChild* TTestUiAifBlocksHuiTextCommandChild::NewL( CHuiTextVisual& aTextVisual, const TDesC& aText, 
    THuiOp aOperation )
    {
    TTestUiAifBlocksHuiTextCommandChild* self=
        TTestUiAifBlocksHuiTextCommandChild::NewLC( aTextVisual, aText, aOperation );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiTextCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiTextCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiTextCommand::CommandExtension( aExtensionUid, aExtensionParams );
    }
