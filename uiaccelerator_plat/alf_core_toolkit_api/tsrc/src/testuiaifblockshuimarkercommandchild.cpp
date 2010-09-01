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


#include "testuiaifblockshuimarkercommandchild.h"

TTestUiAifBlocksHuiMarkerCommandChild::TTestUiAifBlocksHuiMarkerCommandChild( TInt Id )
    :THuiMarkerCommand( Id )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiMarkerCommandChild::~TTestUiAifBlocksHuiMarkerCommandChild()
    {
    }

TTestUiAifBlocksHuiMarkerCommandChild* TTestUiAifBlocksHuiMarkerCommandChild::NewLC( TInt Id )
    {
    TTestUiAifBlocksHuiMarkerCommandChild* self = new (ELeave)TTestUiAifBlocksHuiMarkerCommandChild( Id );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiMarkerCommandChild* TTestUiAifBlocksHuiMarkerCommandChild::NewL( TInt Id )
    {
    TTestUiAifBlocksHuiMarkerCommandChild* self=
            TTestUiAifBlocksHuiMarkerCommandChild::NewLC( Id );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiMarkerCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiMarkerCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiMarkerCommand::CommandExtension( aExtensionUid, aExtensionParams );
    
    }
