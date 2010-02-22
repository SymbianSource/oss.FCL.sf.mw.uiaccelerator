/*
* Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:   CAlfDrawer implementation.
*
*/




#include <alf/alfdrawer.h>
#include "alfcrppluginclient.h"

#include <coemain.h>
#include <w32std.h>

// Class to hold internal alf drawer data.
NONSHARABLE_CLASS( CAlfDrawer::TAlfDrawerData )
    {
public:
    TAlfDrawerData();
        
public:
    CAlfCrpPluginClient* iClient;
    };

// Creates CAlfCrpPluginClient instance, returns error code.
static TInt CreateAlfCrpClient(CAlfCrpPluginClient*& aClient);
// Creates CAlfCrpPluginClient instance.
static CAlfCrpPluginClient* CreateAlfCrpClientL();


// ---------------------------------------------------------------------------
// NewL
// ---------------------------------------------------------------------------
//
EXPORT_C CAlfDrawer* CAlfDrawer::NewL()
    {
    CAlfDrawer* self = new (ELeave) CAlfDrawer;
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop( self );    
    return self;
    }

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
EXPORT_C CAlfDrawer::~CAlfDrawer()
    {
    if ( iData )
        {
        delete iData->iClient;
        delete iData;
        }
    }

// ---------------------------------------------------------------------------
// Finish
// ---------------------------------------------------------------------------
//
EXPORT_C TInt CAlfDrawer::Finish()
    {
    // First perform RWsSession finish operation to ensure
    // that all drawing commands have been issued to renderstage.
    TInt err = CCoeEnv::Static()->WsSession().Finish();

    // Then create CRP instance (if needed).
    if ( err == KErrNone && !iData->iClient ) 
        {
        err = CreateAlfCrpClient( iData->iClient );
        }

    // Finally, wait until alf side has finished rendering.
    if ( err == KErrNone && iData->iClient )
        {
        iData->iClient->Synchronize();
        }
        
    return err;
    }

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
CAlfDrawer::CAlfDrawer()
    {
    }
    
// ---------------------------------------------------------------------------
// ConstructL
// ---------------------------------------------------------------------------
//
void CAlfDrawer::ConstructL()
    {
    iData = new (ELeave) TAlfDrawerData;
    CreateAlfCrpClient( iData->iClient );
    }

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
CAlfDrawer::TAlfDrawerData::TAlfDrawerData()
    : iClient( NULL )
    {
    }

// ---------------------------------------------------------------------------
// CreateAlfCrpClient
// ---------------------------------------------------------------------------
//
static TInt CreateAlfCrpClient(CAlfCrpPluginClient*& aClient)
    {
    TRAPD(err, aClient = CreateAlfCrpClientL());
    return err;
    }

// ---------------------------------------------------------------------------
// CreateAlfCrpClientL
// ---------------------------------------------------------------------------
//
static CAlfCrpPluginClient* CreateAlfCrpClientL()
    {
    CAlfCrpPluginClient* client = new (ELeave) CAlfCrpPluginClient;
    CleanupStack::PushL( client );
    client->ConstructL();
    CleanupStack::Pop( client );
    return client;
    }

