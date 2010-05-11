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


#include "testuiaifblockshuicontrolcommandchild.h"

TTestUiAifBlocksHuiControlCommandChild::TTestUiAifBlocksHuiControlCommandChild( 
    CHuiControl& aControl, THuiOp aOperation):THuiControlCommand( aControl, aOperation )
    {
    // No implementation required
    }

TTestUiAifBlocksHuiControlCommandChild::~TTestUiAifBlocksHuiControlCommandChild()
    {
    }

TTestUiAifBlocksHuiControlCommandChild* TTestUiAifBlocksHuiControlCommandChild::NewLC(
    CHuiControl& aControl, THuiOp aOperation )
    {
    TTestUiAifBlocksHuiControlCommandChild* self = new (ELeave)TTestUiAifBlocksHuiControlCommandChild(
        aControl, aOperation );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

TTestUiAifBlocksHuiControlCommandChild* TTestUiAifBlocksHuiControlCommandChild::NewL(
    CHuiControl& aControl, THuiOp aOperation )
    {
    TTestUiAifBlocksHuiControlCommandChild* self= TTestUiAifBlocksHuiControlCommandChild::NewLC(
        aControl, aOperation );
    CleanupStack::Pop(); // self;
    return self;
    }

void TTestUiAifBlocksHuiControlCommandChild::ConstructL()
    {

    }
void TTestUiAifBlocksHuiControlCommandChild::SetCommandExtension(
        const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    THuiControlCommand::CommandExtension( aExtensionUid, aExtensionParams );
    }
