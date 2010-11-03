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


#include "testuiaifblockshuicontrolchild.h"

CTestUiAifBlocksHuiControlChild::CTestUiAifBlocksHuiControlChild( CHuiEnv& aEnv ):
    CHuiControl( aEnv )
    {
    // No implementation required
    }

CTestUiAifBlocksHuiControlChild::~CTestUiAifBlocksHuiControlChild()
    {
    }

CTestUiAifBlocksHuiControlChild* CTestUiAifBlocksHuiControlChild::NewLC( CHuiEnv& aEnv )
    {
    CTestUiAifBlocksHuiControlChild* self = new (ELeave)CTestUiAifBlocksHuiControlChild( aEnv );
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

CTestUiAifBlocksHuiControlChild* CTestUiAifBlocksHuiControlChild::NewL( CHuiEnv& aEnv )
    {
    CTestUiAifBlocksHuiControlChild* self=
            CTestUiAifBlocksHuiControlChild::NewLC( aEnv );
    CleanupStack::Pop(); // self;
    return self;
    }

void CTestUiAifBlocksHuiControlChild::ConstructL()
    {

    }

void CTestUiAifBlocksHuiControlChild::ChildNotifyControlVisibility( TBool aIsVisible, CHuiDisplay& aDisplay )
    {
    CHuiControl::NotifyControlVisibility( aIsVisible, aDisplay );
    }

void CTestUiAifBlocksHuiControlChild::ChildVisualAddedL( CHuiVisual* aVisual )
    {
    CHuiControl::VisualAddedL( aVisual );
    }

void CTestUiAifBlocksHuiControlChild::ChildVisualRemovedL( CHuiVisual* aVisual )
    {
    CHuiControl::VisualRemoved( aVisual );
    }

void CTestUiAifBlocksHuiControlChild::ChildConnectionAddedL( CHuiControl* aConnectedControl, TInt aRole )
    {
    CHuiControl::ConnectionAddedL( aConnectedControl, aRole );
    }

void CTestUiAifBlocksHuiControlChild::ChildConnectionRemovedL( CHuiControl* aConnectedControl, TInt aRole )
    {
    CHuiControl::ConnectionRemoved( aConnectedControl, aRole );
    }

void CTestUiAifBlocksHuiControlChild::ChildHostChangingL( CHuiControl* aNewHost )
    {
    CHuiControl::HostChangingL( aNewHost );
    }

void CTestUiAifBlocksHuiControlChild::ChildBaseConstructL()
    {
    CHuiControl::BaseConstructL();
    }

void CTestUiAifBlocksHuiControlChild::ChildControlExtensionL( const TUid& aExtensionUid, TAny** aExtensionParams )
    {
    CHuiControl::ControlExtension( aExtensionUid, aExtensionParams );
    }

void CTestUiAifBlocksHuiControlChild::ChildTypeL()
    {
    CHuiControl::Type();
    }

TInt CTestUiAifBlocksHuiControlChild::ChildSessionIdL()
    {
    return CHuiControl::SessionId();
    }

void CTestUiAifBlocksHuiControlChild::ChildSetSessionIdL( TInt aSessionId )
    {
    CHuiControl::SetSessionId( aSessionId );
    }
