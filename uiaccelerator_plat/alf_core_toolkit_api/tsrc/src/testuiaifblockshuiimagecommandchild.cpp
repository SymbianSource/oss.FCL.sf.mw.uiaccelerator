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


#include "testuiaifblockshuiimagecommandchild.h"

TTestUiAifBlocksHuiImageCommandChild::TTestUiAifBlocksHuiImageCommandChild( CHuiImageVisual& aImageVisual, const THuiImage& aImage, 
    THuiOp aOperation ):THuiImageCommand( aImageVisual, aImage, aOperation )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiImageCommandChild::~TTestUiAifBlocksHuiImageCommandChild()
    {
    }

TTestUiAifBlocksHuiImageCommandChild* TTestUiAifBlocksHuiImageCommandChild::NewLC( CHuiImageVisual& aImageVisual, const THuiImage& aImage, 
    THuiOp aOperation )
    {
    TTestUiAifBlocksHuiImageCommandChild* self = new (ELeave)TTestUiAifBlocksHuiImageCommandChild( aImageVisual, aImage, aOperation);
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiImageCommandChild* TTestUiAifBlocksHuiImageCommandChild::NewL( CHuiImageVisual& aImageVisual, const THuiImage& aImage, 
    THuiOp aOperation )
    {
    TTestUiAifBlocksHuiImageCommandChild* self=
            TTestUiAifBlocksHuiImageCommandChild::NewLC( aImageVisual, aImage, aOperation );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiImageCommandChild::ConstructL()
    {

    }

void TTestUiAifBlocksHuiImageCommandChild::SetCommandExtension( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiImageCommand::CommandExtension( aExtensionUid, aExtensionParams );
    
    }
