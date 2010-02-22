/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:   Server implementation fo share files in application private gage 
*                with controlled way
*
*/



#include <e32std.h>
#include <f32file.h>
#include <e32math.h>
#include "alfstreamerserver.h"
#include "alfstreamerconsts.h"
#include "alfstreamerbridge.h"
#include "alfwindowmanager.h"
#include "alfhierarchymodel.h"
#include <ecom.h>
#include <alf/AlfTransEffectPlugin.h>
#include <alf/AlfTransEffectPlugin.hrh>


// ==================================
// Launcher implementation.
// ==================================   

// ---------------------------------------------------------------------------
// DoAlfStreamerServerThreadStartFunctionL
// Construct the server object
// ---------------------------------------------------------------------------
//   
LOCAL_C void DoAlfStreamerServerThreadStartFunctionL(CAlfStreamerBridge* aBridge)
    {
    CAlfStreamerServer::NewLC(aBridge);
    
    RThread().Rendezvous(KErrNone);
    CActiveScheduler::Start();
    CleanupStack::PopAndDestroy(); // server
    }

// ---------------------------------------------------------------------------
// Entry point into the new thread
// ---------------------------------------------------------------------------
//   
GLDEF_C TInt AlfStreamerServerThreadStartFunction(TAny* aBridge)
    {
    __UHEAP_MARK;
    RThread thread;

    TInt err = User::RenameThread(KAlfStreamerServerThreadName);
    if (err == KErrNone)
        {
        thread.SetPriority(EPriorityAbsoluteHigh);
        thread.Close();

        // Set up scheduler and cleanup stack for this thread
        CActiveScheduler* scheduler = new CActiveScheduler;
        if (!scheduler)
            {
            return KErrNoMemory;
            }
        CActiveScheduler::Install(scheduler);
        CTrapCleanup* trapCleanup = CTrapCleanup::New();
        if (!trapCleanup)
            {
            return KErrNoMemory;
            }

        // Set initial trap harness, and construct server object
        TRAP(err,DoAlfStreamerServerThreadStartFunctionL((CAlfStreamerBridge*)aBridge));

        delete CActiveScheduler::Current();
        delete trapCleanup;
        }
    __UHEAP_MARKEND;
    return err;
    }

// ---------------------------------------------------------------------------
// LaunchServer
// ---------------------------------------------------------------------------
//   
TInt CAlfStreamerServer::LaunchServer(TThreadId& aThreadId, CAlfStreamerBridge* aBridge)
    {
    // First, check that ther server isn't already running.
    TFindServer findServer(ALFSTREAMER_SERVER_NAME);
    TFullName name;
    if (findServer.Next(name) == KErrNone)
        {
        return KErrAlreadyExists;
        }
    RThread serverThread;

    TInt err = serverThread.Create(
        KAlfStreamerServerThreadName,
        AlfStreamerServerThreadStartFunction,
        16384, // magic
        0, // uses caller thread's heap
        (TAny*)aBridge, 
        EOwnerThread);

    aThreadId = serverThread.Id();
    TRequestStatus status;
    serverThread.Rendezvous(status);
    serverThread.Resume();
    serverThread.Close();
    User::WaitForRequest(status);
    return err;
    }

// ---------------------------------------------------------------------------
// NewLC
// ---------------------------------------------------------------------------
//   
void CAlfStreamerServer::NewLC(CAlfStreamerBridge* aBridge)
    {
    CAlfStreamerServer* pS = new (ELeave) CAlfStreamerServer(aBridge);
    CleanupStack::PushL(pS);
    pS->ConstructL();
    }

TInt DoRendezvous(TAny* aCallBack)
    {
    RThread().Rendezvous(KErrNone);
    CAsyncCallBack* cb = (CAsyncCallBack*) aCallBack;
    delete cb;
    return KErrNone;
    }

// ---------------------------------------------------------------------------
// ConstructL
// ---------------------------------------------------------------------------
//   
void CAlfStreamerServer::ConstructL()
    {
    StartL(ALFSTREAMER_SERVER_NAME);
    
    iWindowHierarcy = CAlfHierarchyModel::NewL(*this);
    iWindowMgr = CAlfWindowManager::NewL(iWindowHierarcy);
    iBridge->SetStreamerServer( *this );
    iThemesListener = CThemeRepositoryListener::NewL();
    iThemesListener->IssueRequest();
    iRendezvous = new (ELeave) CAsyncCallBack(EPriorityHigh*3);
    iRendezvous->Set(TCallBack(DoRendezvous, iRendezvous));
    iRendezvous->CallBack();
    }

// ---------------------------------------------------------------------------
// NewSessionL
// ---------------------------------------------------------------------------
//   
CSession2* CAlfStreamerServer::NewSessionL(const TVersion& /*aVersion*/,const RMessage2& /*aMessage*/) const
    {
	CSession2* newSession = new(ELeave) CAlfStreamerServerSession();
    iSessions++;
    
    return newSession;   
    }

CAlfStreamerServerSession* CAlfStreamerServer::WservSession(TInt aScreenNumber)
    {
    CAlfStreamerServerSession* windowServerSession = NULL;
    for(TInt i = 0; i < iWindowServerSessions.Count(); i++ )
        { 
        if(aScreenNumber == iWindowServerSessions[i]->ScreenNumber() )
            {
            windowServerSession = iWindowServerSessions[i];
            break;
            }
        }
    return windowServerSession;
    }


// ---------------------------------------------------------------------------
// HandleClientExit
// ---------------------------------------------------------------------------
//   
void CAlfStreamerServer::HandleClientExit(const CSession2* /*aClient*/)
    {
    iSessions--;
    if (!iSessions)
        {
        // CActiveScheduler::Stop(); // TODO: lets not die, if client dies.
        }
    }

// ---------------------------------------------------------------------------
// destructor of CAlfStreamerServer
// ---------------------------------------------------------------------------
//   
CAlfStreamerServer::~CAlfStreamerServer()
    {
    delete iThemesListener;
    delete iWindowMgr;
    delete iWindowHierarcy;
    iCompositionSessions.Close();
    iCompositionHostSessions.Close();
    iCompositionTokens.Close();
    iWindowServerSessions.Close();
    }

void CAlfStreamerServer::AppendCompositionSessionL(CAlfStreamerServerSession* aSession, TBool aHost)
    {
    if(!aHost)
        {
        TInt index = iCompositionSessions.Find(aSession);    
        if (index == KErrNotFound)
            {
            iCompositionSessions.AppendL(aSession);
            }
        }
    else
        {
        TInt index = iCompositionHostSessions.Find(aSession);    
        if (index == KErrNotFound)
            {
            iCompositionHostSessions.AppendL(aSession);
            }
        }
    }
void CAlfStreamerServer::RemoveCompositionSession(CAlfStreamerServerSession* aSession)    
    {
    TInt index = iCompositionSessions.Find(aSession);    
    if (index != KErrNotFound)
        {
        FreeCompositionSessionExtents(aSession);
        TPckgC<TInt> id(reinterpret_cast<TInt>(aSession));
        for(TInt u = 0; u < iWindowServerSessions.Count(); u++ )
            { 
            if( aSession->ScreenNumber() == iWindowServerSessions[u]->ScreenNumber())
                {
                TRAP_IGNORE(QueueRequestForSessionL(iWindowServerSessions[u], id, KAlfCompOpSessionClosed));
                }
            }
            
        iCompositionSessions.Remove(index);
        
        }
    TInt hostindex = iCompositionHostSessions.Find(aSession);    
    if (hostindex != KErrNotFound)
        {
        HBufC8* message = HBufC8::NewLC(8);
        TInt session = reinterpret_cast<TInt>(aSession);
        TPtr8 clientBuf = message->Des();
        clientBuf.Insert(0, TPtrC8((TUint8*)&session ,sizeof(TInt)));
        TInt newtarget = 0;
        clientBuf.Insert(1 * sizeof(TInt), TPtrC8((TUint8*)&newtarget ,sizeof(TInt)));
        for(TInt i = 0; i < iWindowServerSessions.Count(); i++ )
            { 
            if( aSession->ScreenNumber() == iWindowServerSessions[i]->ScreenNumber())
                {
                TRAP_IGNORE(QueueRequestForSessionL(iWindowServerSessions[i], *message, KAlfCompOpBindSourceToToken)); // bind to 0 -> remove binding
                }
            }
        CleanupStack::PopAndDestroy();
        iCompositionHostSessions.Remove(hostindex);
        }

    // clean possible tokens for this composition source
    TInt targetSession = reinterpret_cast<TInt>(aSession);
    for( TInt i = 0; i < iCompositionTokens.Count() ; i++)
        {
        if ( targetSession == iCompositionTokens[i].iTarget )
            {
            iCompositionTokens.Remove(i);
            i--;
            }
        };
    }

void CAlfStreamerServer::HandleCompositionRequestL(CAlfStreamerServerSession* aSession, TInt aOp, const RMessage2& aMessage)
    {
    CAlfStreamerServerSession* wservsession = WservSession( aSession->ScreenNumber() );

    TInt length = aMessage.GetDesLength(0);
    User::LeaveIfError(length);
    HBufC8* message = HBufC8::NewLC(length+4);
    TPtr8 clientBuf = message->Des();
    aMessage.ReadL(0,clientBuf);

    if(aOp == KAlfCompOpSetExtent) 
        {
        TInt* ptr = (TInt*)clientBuf.Ptr();
        TInt screennumber = ptr[4];
        if(screennumber!=aSession->ScreenNumber())
            {
            aSession->ExtentSurfaceId().iInternal[0] = ptr[5];
            aSession->ExtentSurfaceId().iInternal[1] = ptr[6];
            aSession->ExtentSurfaceId().iInternal[2] = ptr[7];
            aSession->ExtentSurfaceId().iInternal[3] = ptr[8];
            wservsession = WservSession( screennumber );
            }
        }
    else if(aOp == KAlfCompOpSessionClosed)
        {
        FreeCompositionSessionExtents(aSession);
        }
    
    TInt session = reinterpret_cast<TInt>(aSession);
    clientBuf.Insert(0, TPtrC8((TUint8*)&session ,sizeof(TInt)));
    
    if( wservsession ) // don't send to any wservsession if composition source does not have a window anywhere and this is not SetExtent operation
        {
        QueueRequestForSessionL(wservsession, clientBuf, aOp);
        }
    
    CleanupStack::PopAndDestroy(); // unefficient..
 
    if (!wservsession)
        {
        aMessage.Complete(KErrNotReady);
        return;
        }
    
    if( aOp == KAlfCompOpCreateSource )
        {
        AppendCompositionSessionL(aSession);
        aMessage.Complete(reinterpret_cast<TInt>(aSession));
        }
    else if ( aOp != KAlfCompOpSetZOrder )
        {
        aMessage.Complete(KErrNone);
        }
    }

void CAlfStreamerServer::QueueRequestForSessionL(CAlfStreamerServerSession* aSession, const TPtrC8& aPtr, TInt aOp)
    {
    aSession->QueueL(aPtr, aOp);
    }

void CAlfStreamerServer::QueueRequestAllSessionsL(const TPtrC8& aPtr, TInt aOp, TBool aAlsoWServ)
    {
    if (aAlsoWServ)
        {
        for(TInt i = 0; i < iWindowServerSessions.Count(); i++ )
            { 
            iWindowServerSessions[i]->QueueL(aPtr, aOp);
            }    
        }
        
    for(TInt i = iCompositionSessions.Count()-1; i >= 0; i-- )
        { 
        iCompositionSessions[i]->QueueL(aPtr, aOp);
        }
    }

TInt CAlfStreamerServer::CreatePermissionToken(const RMessage2& aMessage, TInt aTarget, CAlfStreamerServerSession* aSession)
    {
    TInt length = aMessage.GetDesLength(0);
    User::LeaveIfError(length);
    HBufC8* message = HBufC8::NewLC(length);
    TPtr8 clientBuf = message->Des();
    aMessage.ReadL(0,clientBuf);

    TInt* ptr = (TInt*) clientBuf.Ptr();
    TInt newkey = Math::Random();
    
    TRAPD( err, iCompositionTokens.AppendL( CCompositionToken( newkey, ptr[0] /* customer specified key */,
                                                                ptr[1] /*flags*/, aTarget,
                                                                aSession->ScreenNumber() ) ) );
    if (err)
        {
        newkey = 0;
        }
    RDebug::Print(_L("CAlfStreamerServer::CreatePermissionToken - newkey %d target: %d, err: %d"), newkey, aTarget, err );
            
    CleanupStack::PopAndDestroy(message);
    return newkey; 
    }

void CAlfStreamerServer::ValidateToken( CAlfStreamerServerSession* aSession, const RMessage2& aMessage)
    {
    TInt length = aMessage.GetDesLength(0);
    User::LeaveIfError(length);
    HBufC8* message = HBufC8::NewLC(length + 12);
    TPtr8 clientBuf = message->Des();
    aMessage.ReadL(0,clientBuf);
        
    TInt* ptr = (TInt*) clientBuf.Ptr();
    TInt tokenkey  = ptr[1];
    TInt secret = ptr[2];
    // only AlfStreamer server knows the tokens. Thus it will pass the existing target and attribs to the client
    TInt i = 0;
    while(  i < iCompositionTokens.Count() )
        {
        if ( tokenkey == iCompositionTokens[i].iKey && secret == iCompositionTokens[i].iSecretKey )
            {
            break;
            }
        i++;
        };
    
    if ( i < iCompositionTokens.Count())
        {
        CAlfStreamerServerSession* wservsession = WservSession( iCompositionTokens[i].iScreenNumber );
        if( wservsession )
            {
            aSession->SetScreenNumber( wservsession->ScreenNumber() );
//            CCompositionToken token(iCompositionTokens[i].iKey, iCompositionTokens[i].iSecretKey, iCompositionTokens[i].iFlags, iCompositionTokens[i].iTarget, iCompositionTokens[i].iScreenNumber);
            TInt session = reinterpret_cast<TInt>(aSession);
            clientBuf.Insert(0, TPtrC8((TUint8*)&session ,sizeof(TInt)));
  
            if( iCompositionTokens[i].iCombinedTarget )
                {
                clientBuf.Insert(1 * sizeof(TInt), TPtrC8((TUint8*)&iCompositionTokens[i].iKey ,sizeof(TInt)));
                clientBuf.Insert(2 * sizeof(TInt), TPtrC8((TUint8*)&iCompositionTokens[i].iFlags ,sizeof(TInt)));
                }
            else
                {
                clientBuf.Insert(1 * sizeof(TInt), TPtrC8((TUint8*)&iCompositionTokens[i].iTarget ,sizeof(TInt)));
                clientBuf.Insert(2 * sizeof(TInt), TPtrC8((TUint8*)&iCompositionTokens[i].iFlags ,sizeof(TInt)));
                }
            
            AppendCompositionSessionL(aSession, ETrue);
            // pass the updated buffer to client    
            QueueRequestForSessionL(wservsession, clientBuf, KAlfCompOpBindSourceToToken);
            CleanupStack::PopAndDestroy(); // unefficient..
            aMessage.Complete(KErrNone);
            }
        else
            {
            CleanupStack::PopAndDestroy(); // unefficient..
            aMessage.Complete(KErrNotFound);
            }
        }
    else
        {
        CleanupStack::PopAndDestroy(); // unefficient..
        aMessage.Complete(KErrNotFound); // client will get User::Leave after this.
        }
    }

void CAlfStreamerServer::HandleCompositionEventL(CAlfStreamerServerSession* aSession, TInt aOp, const RMessage2& aMessage)
    {
    if ( aOp == KAlfCompositionWServReady )
        {
        TInt index = iWindowServerSessions.Find(aSession);    
        if (index == KErrNotFound)
            {
            iWindowServerSessions.AppendL(aSession);
            }
        aMessage.Complete(KErrNone);
        return;
        }
    
    if ( aOp == KAlfCompositionLowOnGraphicsMemory ||  aOp == KAlfCompositionGoodOnGraphicsMemory 
		|| aOp == KAlfCompositionTargetHidden ||aOp == KAlfCompositionTargetVisible)
        {
        aMessage.Complete(KErrNone);
        QueueRequestAllSessionsL(KNullDesC8(), aOp, ETrue);    
        return;
        }        
    
    TInt length = aMessage.GetDesLength(0);
    User::LeaveIfError(length);
    HBufC8* message = HBufC8::NewLC(length);
    TPtr8 clientBuf = message->Des();
    aMessage.ReadL(0,clientBuf);

    TInt* ptr = (TInt*) clientBuf.Ptr();
    CAlfStreamerServerSession* target =  reinterpret_cast<CAlfStreamerServerSession*>(*ptr);

    switch(aOp)
        {
        case KAlfCompositionFrameReady:
            {
            QueueRequestAllSessionsL(clientBuf.Right(4), aOp);    
            break;
            }
        case KAlfCompositionTargetCreated:
            {
            if (!target->MessagePtr().IsNull())
                {
                // create a combined target token
                if(ptr[1] > 0 )
                    {

                    TRAPD( err, iCompositionTokens.AppendL( 
                            CCompositionToken(
                            ptr[1], // new token
                            ptr[2], // secret key
                            0,
                            reinterpret_cast<TInt>(aSession),
                            aSession->ScreenNumber(),
                            ETrue // combined target
                           ) ) );
                    if (err)
                        {
                        ptr[1] = 0;
                        }
  
                    }
                
                target->MessagePtr().Complete(ptr[1]);    
                }
            break;
            }
        default:
            break;
        }
    CleanupStack::PopAndDestroy();
    aMessage.Complete(KErrNone);
    }    


void CAlfStreamerServer::FreeCompositionSessionExtents(CAlfStreamerServerSession* aSession)
    {
    if( !aSession->ExtentSurfaceId().IsNull())
        {
        for(TInt i = 0; i < iWindowServerSessions.Count(); i++)
            { 
            if( aSession->ScreenNumber() != iWindowServerSessions[i]->ScreenNumber() )
                {
                TInt session = reinterpret_cast<TInt>(aSession);
                TInt array[] = {session, 0,0,0,0, // TRect()
                                0, // screennumber does not matter
                                aSession->ExtentSurfaceId().iInternal[0],
                                aSession->ExtentSurfaceId().iInternal[1],
                                aSession->ExtentSurfaceId().iInternal[2],
                                aSession->ExtentSurfaceId().iInternal[3] };  
                TPtrC8 ptr((TUint8*)&array ,sizeof(array));
                QueueRequestForSessionL(iWindowServerSessions[i], ptr, KAlfCompOpSetExtent );
                }
            }
        aSession->ExtentSurfaceId().CreateNullId();
        }
    }

// ---------------------------------------------------------------------------
// constructor
// ---------------------------------------------------------------------------
//   
CAlfStreamerServerSession::CAlfStreamerServerSession() : iScreenNumber(KErrNotFound)
    {
    }

// ---------------------------------------------------------------------------
// destructor of CAlfStreamerServerSession
// ---------------------------------------------------------------------------
//   
CAlfStreamerServerSession::~CAlfStreamerServerSession()
    {
    TInt i = 0;
    RImplInfoPtrArray pluginArray;
    REComSession::ListImplementationsL( KAlfGfxPluginInterfaceUId, pluginArray );    
    for ( i = iLoadedPlugins.Count() - 1; i >= 0; i-- )
        {
        TInt j = 0;    
        for ( j= 0; j < pluginArray.Count(); j++ )
            {
            TUid loaded = TUid::Uid(iLoadedPlugins[i]);
            TUid listed = pluginArray[j]->ImplementationUid();
            TPtrC8 listedopaque = pluginArray[j]->OpaqueData();
            if ( loaded == listed && ( (listedopaque.CompareF( KAlfDoNotUnloadPlugin )) != 0 ) )
                {
                ((CAlfStreamerServer*)(Server()))->WindowMgr()->DestroyPlugin(TUid::Uid(iLoadedPlugins[i]));
                }
            }
        }
    // Clear the data in plugin array
    for (TInt i = pluginArray.Count() - 1; i >= 0; i-- )
        {
        // destroy 
        delete pluginArray[i];
        pluginArray.Remove( i );
        }
    pluginArray.Close();
    iLoadedPlugins.Close();    
            
    CAlfStreamerServer* server = dynamic_cast<CAlfStreamerServer*>((CAlfStreamerServer*)Server()); // nice const cast     
    server->RemoveCompositionSession((CAlfStreamerServerSession*)this); // deja vu   
    server->HandleClientExit(this);
    }


// ---------------------------------------------------------------------------
// ServiceL
// ---------------------------------------------------------------------------
//   
void CAlfStreamerServerSession::ServiceL(const RMessage2& aMessage)
    {
//    RDebug::Print(_L("CAlfStreamerServerSession::ServiceL %d"), aMessage.Function());
   CAlfStreamerServer* server = (CAlfStreamerServer*)( Server() );
   
   TInt op = aMessage.Function();
   
   // handle composition control ops in different function
   if (op >= KAlfCompOpCreateSource)
       {
       HandleCompositionOpL(op, aMessage, server);
       return;
       }
         
   switch(op)
        {
        case EAlfBridgerBlindSend:
        case EAlfBridgerSendChunk:
        case EAlfBridgerRequestDataBlock:
        case EAlfBridgerAsyncronousData:
        case EDsNotifyNativeWindowData:
        case EAlfSynchronize:
            {
            server->WindowTree()->HandleMessageL( aMessage );
            return;
            }
        
        case EAlfDecodSLoadPlugin:
            {
            TInt index = iLoadedPlugins.Find(aMessage.Int0());
            TRAPD( err, server->WindowMgr()->LoadPluginL(TUid::Uid(aMessage.Int0())) );
            // was successfully loaded, add uid to session's array
            if ( err == KErrNone || err == KErrAlreadyExists )
                {
                if ( index == KErrNotFound )
                    {
                    iLoadedPlugins.AppendL(aMessage.Int0());
                    }
                }
            else    
                {
                User::Leave( err );
                }
            break;
            }
        case EAlfDecodSUnloadPlugin:
            {
            TInt index = iLoadedPlugins.Find(aMessage.Int0());
            if  (index != KErrNotFound )
                {
                RImplInfoPtrArray pluginArray;
                REComSession::ListImplementationsL( KAlfGfxPluginInterfaceUId, pluginArray );    
                TInt i = 0;    
                for ( i = 0; i < pluginArray.Count(); i++ )
                    {
                    TUid loaded = TUid::Uid(aMessage.Int0());
                    TUid listed = pluginArray[i]->ImplementationUid();
                    TPtrC8 listedopaque = pluginArray[i]->OpaqueData();
                    if ( loaded == listed && (listedopaque.CompareF( KAlfDoNotUnloadPlugin )) != 0 ) 
                        {
                        iLoadedPlugins.Remove(index);
                        server->WindowMgr()->DestroyPlugin(TUid::Uid(aMessage.Int0()));
                        }
                    }
                // Clear the data in plugin array, it is not going to be used any more.    
                for ( i = pluginArray.Count() - 1; i >= 0; i-- )
                    {
                    // destroy 
                    delete pluginArray[i];
                    pluginArray.Remove( i );
                    }
                pluginArray.Close();
                }        
            break;
            }        

        case EAlfDecodSSendSynch:
        case EAlfDecodSSendAsynch:
            {
            server->WindowMgr()->HandlePluginMsgL(aMessage); // will complete synch message immediately       
            return; // so message won't be completed
            }        

        case EAlfDecodSCancelAsynch:
            {
            server->WindowMgr()->CancelPluginMsg(TUid::Uid(aMessage.Int0()), aMessage.Int1());       
            break;        
            }        
        
        case EAlfDecodSPrepareFrame:
            {
            server->WindowMgr()->PrepareNewFrame(aMessage.Int0());
            break;
            } 
        case EAlfSetScreenRotation:
            {
            TInt rotation = aMessage.Int0();
            aMessage.Complete(KErrNone);    
            server->Bridge()->AddData( EAlfBridgeSetScreenRotation,rotation);
            break;
            } 
        case EAlfGetNativeWindowHandles:
            {
            TPckgC<TAlfNativeWindowData> data(server->Bridge()->iAlfWindowData);
            aMessage.WriteL(0, data);
            break;    
            }

        default:
            {
            aMessage.Complete(KErrNotSupported);
            break;
            }        
        }
    if (!aMessage.IsNull())
        {
        aMessage.Complete(KErrNone);
        }
//    RDebug::Print(_L("CAlfStreamerServerSession::ServiceL exit"));
    }

void CAlfStreamerServerSession::HandleCompositionOpL(TInt aOp, const RMessage2& aMessage, CAlfStreamerServer* aServer)
    {
    switch (aOp)
        {
        case KAlfCompOpRequestEvent:
            {
            iIsListeningCompositionEvents = ETrue;    
            if (!CompletedFromQueue(aMessage))
                {
                iMessagePtr = aMessage;
                }
            break;   
            }
            
    case KAlfCompOpCancelEventRequest:
            {
            if (!iMessagePtr.IsNull())
                {
                iMessagePtr.Complete(KErrCancel);
                }
            aMessage.Complete(KErrNone);
            break;   
            }    

    case KAlfCompositionWServReady:
    case KAlfCompositionFrameReady:
    case KAlfCompositionLowOnGraphicsMemory:
    case KAlfCompositionGoodOnGraphicsMemory:    
    case KAlfCompositionTargetHidden:
    case KAlfCompositionTargetVisible:
    case KAlfCompositionTargetCreated:
        {
        aServer->HandleCompositionEventL(this, aOp, aMessage);
        break;
        }

    // temp, should go to window server to have more precise control on 
    // operations    
    case KAlfCompOpCreateToken:
        {
        TInt token = aServer->CreatePermissionToken( aMessage, reinterpret_cast<TInt>(this), this );
        aMessage.Complete(token);
        break;
        }
    case KAlfCompOpBindSourceToToken:
        {
        aServer->ValidateToken(this, aMessage);        // called method will complete aMessage 
        break;
        }
    case KAlfCompOpSetZOrder:
        iMessagePtr = aMessage; 
    case KAlfCompOpCreateSource:
    case KAlfCompOpEnableAlpha:
    case KAlfCompOpSetOpacity:
    case KAlfCompOpSetRotation: 
    case KAlfCompOpSetExtent:
    case KAlfCompOpEnableKb:
    case KAlfComOpSetBackgroundAnim:
    case KAlfCompOpSessionClosed:
        {
        aServer->HandleCompositionRequestL(this, aOp, aMessage);
        break;
        }
    case KAlfCompositionWServScreenNumber:
        {
        iScreenNumber  = aMessage.Int0();
        aMessage.Complete(KErrNone);
        break;
        }
    case KAlfCompositionSourceScreenNumber:
        {
        TInt length = aMessage.GetDesLength(0);
        User::LeaveIfError(length);
        HBufC8* message = HBufC8::NewLC(length);
        TPtr8 clientBuf = message->Des();
        aMessage.ReadL(0,clientBuf);

        TInt* ptr = (TInt*) clientBuf.Ptr();
        iScreenNumber  = ptr[0];
        
        CleanupStack::PopAndDestroy(message);
        aMessage.Complete(KErrNone);
        break;
        }
    default:        
        // add debug guards or remove
        RDebug::Print(_L("Oops, unknown composition command: %d "), aOp);
        User::Invariant();
        }
    }
    
TBool CAlfStreamerServerSession::CompletedFromQueue(const RMessage2& aMessage)
    {
    if (iQueue.Count())
        {
        TRAPD(err, aMessage.WriteL(0,*iQueue[0]/*->Des()*/));
        TInt cmd = iCmds[0];
        if (!err)
            {
            delete iQueue[0];
            iQueue.Remove(0);
            iCmds.Remove(0);
            }
        else
            {
            RDebug::Print(_L("CAlfStreamerServerSession::CompletedFromQueue err: %d"),err);
            }
        if( !iMessagePtr.IsNull())
            {
            iMessagePtr.Complete(err?err:cmd);
            }
        else
            {
            aMessage.Complete(err?err:cmd);
            }
        return ETrue;
        }
    return EFalse;
    }
    
void CAlfStreamerServerSession::QueueL(const TPtrC8& aPtr, TInt aCmd)
    {
    if (!iIsListeningCompositionEvents)    
        {
        return;
        }
            
    if (!iMessagePtr.IsNull())
        {
        TRAPD(err, iMessagePtr.WriteL(0,aPtr));
        iMessagePtr.Complete(err?err:aCmd);
        }    
    else
        {
        HBufC8* ptr = aPtr.AllocLC();
        TInt err = iCmds.Append(aCmd);
        if (!err)
            {
            iQueue.AppendL(ptr);
            }
        User::LeaveIfError(err);    
        CleanupStack::Pop();    
        }        
    }

void CAlfStreamerServerSession::SetScreenNumber(TInt aScreennumber)
    {
    iScreenNumber = aScreennumber;
    }

TInt CAlfStreamerServerSession::ScreenNumber() const
    {
    return iScreenNumber;
    }

TSurfaceId& CAlfStreamerServerSession::ExtentSurfaceId()
    {
    return iExtentSurfaceId;
    }
// end of file
