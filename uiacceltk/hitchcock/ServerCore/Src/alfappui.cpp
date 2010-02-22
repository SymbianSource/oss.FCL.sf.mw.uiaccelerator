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
* Description:   AppUi class
*
*/

   
#include <apgtask.h>
#include <AknDoc.h>
#include "alf/alfappui.h"
#include "alf/alfappserver.h"
#include <uiacceltk/HuiEnv.h>
#include <aknenv.h>
#include <AknsConstants.h>
#include <uiacceltk/HuiSkin.h>
#include <uiacceltk/HuiDisplay.h>
#include <uiacceltk/HuiControl.h>
#include <uiacceltk/HuiControlGroup.h>
#include <uiacceltk/HuiEvent.h>
#include <uiacceltk/HuiDeckLayout.h>
#include <uiacceltk/HuiImageVisual.h>
#include <uiacceltk/HuiTransformation.h>
#include <uiacceltk/HuiBorderBrush.h>
#include <uiacceltk/HuiUtil.h>
#include <uiacceltk/HuiTextVisual.h>
#include <uiacceltk/HuiGradientBrush.h>
#include <apgwgnam.h>

#ifdef ALF_USE_CANVAS
#include <uiacceltk/HuiCanvasVisual.h>
#endif

#include "alflogger.h"
#include "alf/alfappsrvsessionbase.h"
#include "alf/alfappserver.h"
#include "alfsrvresourcemanager.h"
#include "alfsrvsettingshandler.h"
#include <uiacceltk/HuiTextureManager.h>
#include "alfsrvtexturemanager.h"
#include "alfshareddisplaycoecontrol.h"
#include "alfuids.h"

#ifdef SYMBIAN_BUILD_GCE
#include "alfbridge.h"
#include "alfstreamerserver.h"
#include "alfdecoderserverclient.h"
#include "alfstreamerconsts.h"
#endif // #ifdef SYMBIAN_BUILD_GCE

// DISABLE this if you want to use the AHDemoApp layout switch. If this is enabled
// and switch is done through AHDemoApp, the layout will be rotated too much.
#ifdef __WINSCW__
// Use this, if you want the VGA layout to show correctly
#define ALF_USE_EMULATOR_LAYOUT_SWITCH_BUTTON
#endif


_LIT(KAlfEventThreadName,"alfevents");
NONSHARABLE_CLASS(CAlfEventCatcher): public CActive
    { // this class does not actually catch the events but moves the wg so that alf can get pointer events
    public:
    CAlfEventCatcher(RWsSession& aWsSession, 
                     RWindowGroup& aWindowGroup, RWindow* aWindow, CWsScreenDevice* aScreenDevice)
                     :CActive(CActive::EPriorityStandard), 
                     iWsSession(aWsSession),
                     iWindowGroup(aWindowGroup),
                     iWindow(aWindow),
                     iScreenDevice(aScreenDevice),
                     iThread(RThread().Id())
        {
        CActiveScheduler::Add(this);
        iSema.CreateLocal();
        DoActivate();
        }
    
    ~CAlfEventCatcher()
        {
        Cancel();
        iSema.Close();
        }
    
    void DoActivate()
        {
        SetActive();
        iStatus = KRequestPending;        
        }
    
    void AdjustWindowGroupPositionL(TInt aParentIdentifier, TInt aPosition)
        {
        iSema.Wait();
        // ok to update previous values even they were not applied by ao
        iParentIdentifier = aParentIdentifier;
        iPosition = aPosition;
        if (IsActive() && iStatus == KRequestPending)
            {
            RThread t;
            TInt err = t.Open(iThread);
            if (err)
                {
                __ALFLOGSTRING1( "CAlfEventCatcher::Trigger() ignore RThread::Open() error: %d", err );
                }
            TRequestStatus* status = &iStatus;
            __ALFLOGSTRING("CAlfEventCatcher::Trigger - completing  CAlfEventCatcher");
            t.RequestComplete(status, err);
            t.Close();
            }
        iSema.Signal();
        }
    
    void RunL()
        {
        iSema.Wait();
        if (iStatus.Int() == KErrNone)
            {
            TRAPD(err, DoAdjustPositionL());
            if (err)
                {
                __ALFLOGSTRING1("ALF: WG Parent not found, err %d", err);
                }
            }
        DoActivate();
        iSema.Signal();
        }

    void DoAdjustPositionL()
        {
         __ALFLOGSTRING1("ALF: DoAdjustPositionL() %d", iPosition);
                  
        if (iPosition == CAlfAppServer::EAbsoluteBackground) // just for convenience
            {
            __ALFLOGSTRING("CAlfEventCatcher::DoAdjustPositionL - CAlfAppServer::EAbsoluteBackground");
            iWindowGroup.SetOrdinalPosition(-1,ECoeWinPriorityNeverAtFront);
            iWsSession.Flush();
            return;
            }
        else if (iPosition == CAlfAppServer::EAlfWindowSize ) // just for developer convenience
            {
            __ALFLOGSTRING("CAlfEventCatcher::DoAdjustPositionL - CAlfAppServer::EAlfWindowSize");
             // update window size when layout changes    
            iScreenDevice->SetAppScreenMode(iScreenDevice->CurrentScreenMode());
            iWindow->SetSize(iScreenDevice->SizeInPixels());
            __ALFLOGSTRING2("ALF EventWin: Size(%d,%d)", iWindow->Size().iWidth, iWindow->Size().iHeight );
            return;
            }
     
            
        TInt parentPriority = 
            iWsSession.GetWindowGroupOrdinalPriority(iParentIdentifier);

        // perhaps we should maintain wg-list elsewhere
        CArrayFixFlat<TInt>* wgs = new (ELeave) CArrayFixFlat<TInt>(1); 
        CleanupStack::PushL(wgs);
        iWsSession.WindowGroupList(parentPriority,wgs);
        
        TInt pos = KErrNotFound;
        TInt movingWgOldPos = KErrNotFound;
        TInt wgCount = wgs->Count();
        for (TInt i = 0; i < wgCount; i++)
            {
            if (iParentIdentifier == wgs->At(i))
                {
                if ( iPosition == CAlfAppServer::EOnTopOfParent )
                    {
                    pos = i;
                    }
                else
                    {
                    pos = i+1;
                    }
                }
            if ( iWindowGroup.WindowGroupId() == wgs->At(i))
                {
                movingWgOldPos = i;
                }
               
            if ( pos != KErrNotFound && movingWgOldPos != KErrNotFound )
                {
                // Both found already.
                break;
                }
            }
        
        // If the moving window group has already been before the parent
        // we need to adjust the new position
        if ( movingWgOldPos < pos && movingWgOldPos != KErrNotFound )
            {
            pos--;
            }

        User::LeaveIfError(pos); // parent not found, leave
        CleanupStack::PopAndDestroy(wgs);        
        iWindowGroup.SetOrdinalPosition(pos, parentPriority);
        iWsSession.Flush();
        }
    
    void DoCancel()
        {
        // do not..
        }
    
    RWsSession& iWsSession;
    RWindowGroup& iWindowGroup;
    RWindow* iWindow;
    CWsScreenDevice* iScreenDevice;
    TThreadId iThread;
    RCriticalSection iSema;
    TInt iPosition;
    TInt iParentIdentifier;
    };

NONSHARABLE_CLASS(CAlfEventBridge): public CActive
    {
    public:
    CAlfEventBridge(CAlfAppUi& aAppUi, CHuiDisplay& aDisplay)
        :CActive(CActive::EPriorityUserInput), 
        iAppUi(aAppUi), 
        iDisplay(aDisplay),
        iThread(RThread().Id())
        {
        CActiveScheduler::Add(this);
        iSema.CreateLocal();
        TPixelsAndRotation rot;
        CWsScreenDevice* sd = CHuiStatic::ScreenDevice();
        sd->GetScreenModeSizeAndRotation(sd->CurrentScreenMode(),rot);
        iVirtualSize = rot.iPixelSize; // for pointer event re-mapping
        RequestEventNotification();
        }
        
    ~CAlfEventBridge()
        {
        Cancel();
        iSema.Close();
        iQueue1.Close();
        iQueue2.Close();
        }        
 
    void RequestEventNotification()
    /** Asks WSERV proxy to give notification when an event is waiting */
        {
        iSema.Wait();
        iQueueSelection++;
        iQueueSelection%=2;
        iStatus = KRequestPending;
        SetActive();
        iSema.Signal();            
        }
    
    void AdjustWindowGroupPositionL(TInt aParentIdentifier, TInt aPosition)
        {
        if (iEventCatcher)
            {
            iEventCatcher->AdjustWindowGroupPositionL(aParentIdentifier, aPosition);
            }
        }
    
    void Trigger(TInt aReason)
        {
        if (IsActive() && iStatus == KRequestPending)
            {
            RThread t;
            TInt err = t.Open(iThread);
            if (err)
                {
                __ALFLOGSTRING1( "CAlfEventBridge::Trigger() ignore RThread::Open() error: %d", err );
                }
            TRequestStatus* status = &iStatus;
            __ALFLOGSTRING("CAlfEventBridge::Trigger - completing  CAlfEventBridge")
            t.RequestComplete(status, err?err:aReason);
            t.Close();
            }

        }
    
    void AddEventL(TWsEvent& aEvent)
        {  
        iSema.Wait();    
        User::LeaveIfError((!iQueueSelection?iQueue1:iQueue2).Append(aEvent));
        Trigger(KErrNone);
        iSema.Signal();
        }
    
    // Todo: Should cache entries
    TBool GetEvent(TWsEvent& aEvent)
        {
        if ((iQueueSelection?iQueue1:iQueue2).Count())    
            {
            aEvent = (iQueueSelection?iQueue1:iQueue2)[0];
            (iQueueSelection?iQueue1:iQueue2).Remove(0);
            return ETrue;
            }
        return EFalse;    
        }
        
    void RunL()
        {
        switch (iStatus.Int())
            {
        case KErrNone:
            break;
        case KErrCancel:
        case KErrServerTerminated:
            return;
        default:
            // Let bridge object know the event window group so that it is able reorder window groups correctly
            if (iStatus.Int() > KErrNone)
                {    
                iAppUi.SetAlfWindowGroupId(iStatus.Int());
                }
            break;
            }
				
        RequestEventNotification();

        TWsEvent event;
        while (GetEvent(event))
            {
            TRAPD(err,DoHandleEventL(event))
                if (err)
                {
                __ALFLOGSTRING2("ALF: Error in handling WSEvent: event: %d err: %d", err, event.Type());    
                }
            }    
        }
        
    void DoHandleEventL(TWsEvent& aEvent)
        {
        iAppUi.HandleWsEventL(aEvent, 0);

        if (aEvent.Type() >= EEventPointer && aEvent.Type() <=  EEventDragDrop )
            {
            // twiddle pointer coordinates
            THuiEvent huiEvent(&iDisplay, *aEvent.Pointer());
            // Send events received here only to the associated display    
            iDisplay.Roster().HandleEventL(huiEvent);        
            iAppUi.EndPointerEventHandling(); // flush here
            }
        }
        
    void DoCancel()
        {
        }
    
    CAlfAppUi& iAppUi;
    CHuiDisplay& iDisplay; // if we ever need to support touch events from multiple displays, this needs to change
                           // of course we could have several event fetchers on that scnario..  
    RArray<TWsEvent> iQueue1;
    RArray<TWsEvent> iQueue2;
    TInt iQueueSelection;
    RCriticalSection iSema;
    TThreadId iThread;
    CAlfEventCatcher* iEventCatcher;
    TSize iVirtualSize;
    };

// ===========ALF WINDOW THREAD================


NONSHARABLE_CLASS(CAlfEventFetcher): public CActive
    {
    public:
    CAlfEventFetcher(RWsSession& aWsSession, 
                     CAlfEventBridge* aBridge )
        :CActive(CActive::EPriorityUserInput), 
        iWsSession(aWsSession),
        iWindowGroup(aWsSession),
        iBridge(aBridge)
        {
        CActiveScheduler::Add(this);
        }
 
    ~CAlfEventFetcher()
        {
        Cancel();
        delete iWindowGc;
        if (iWindow)
            {
            iWindow->Close();    
            delete iWindow;
            }
        iWindowGroup.Close();    
        delete iScreenDevice;
        }    
 
    static CAlfEventFetcher* NewLC(RWsSession& aWsSession, 
                     CAlfEventBridge* aBridge )
        {
        CAlfEventFetcher* ret = new (ELeave)CAlfEventFetcher(aWsSession,aBridge);
        CleanupStack::PushL(ret);
        ret->CreateWindowAndStartL();    
        return ret;
        }     

    void CreateWindowAndStartL()
        {
        iWsSession.ComputeMode(RWsSession::EPriorityControlDisabled);
        RThread thread; 
#if defined(__EPOC32__)
    thread.SetProcessPriority(EPriorityForeground);    
#else
    thread.SetPriority(EPriorityAbsoluteForegroundNormal);    
#endif
        iScreenDevice =new(ELeave) CWsScreenDevice(iWsSession);
        iScreenDevice->Construct(0); // For main display only

        User::LeaveIfError(iWindowGroup.Construct((TUint32)iScreenDevice, EFalse,iScreenDevice));                   
        iWindowGroup.EnableReceiptOfFocus(EFalse); 
        // disable pointer events based autoforwarding
        iWindowGroup.AutoForeground(EFalse);
        iWindowGroup.EnableScreenChangeEvents();

        CApaWindowGroupName* wgName = CApaWindowGroupName::NewLC(iWsSession);
        wgName->SetHidden(ETrue); // hides us from FSW and protects us from OOM FW etc.
        wgName->SetSystem(ETrue); // Allow only application with PowerManagement cap to shut us down    
        wgName->SetCaptionL(_L("ALF Event"));
        wgName->SetAppUid(KNullUid);
        wgName->SetWindowGroupName(iWindowGroup);
        CleanupStack::PopAndDestroy();

        iWindow = new (ELeave) RWindow(iWsSession);
        iWindow->Construct(iWindowGroup,0x000FAB11); // FYI: multiple display support neglegted atm
        iWindow->SetExtent(TPoint(0,0),iScreenDevice->SizeInPixels()); // FYI: multiple display support neglegted atm            
        iWindow->EnableAdvancedPointers();
        iWindow->PointerFilter(EPointerFilterDrag,0);
        iWindow->SetPointerGrab(ETrue);
        iWindow->Activate();
        iWindow->SetVisible(ETrue);            
        iWindow->SetTransparencyAlphaChannel();
        iWindow->SetBackgroundColor(~0);
        
        iBridge->iEventCatcher = new (ELeave) CAlfEventCatcher(iWsSession, iWindowGroup, iWindow, iScreenDevice);   
        iBridge->Trigger(iWindowGroup.Identifier()); // let appui know our wgid
        
        //RequestEventNotification();            
        SetActive();
        TRequestStatus* sptr = &iStatus;
        User::RequestComplete(sptr, KErrNone);
        }    
    
 
    void RequestEventNotification()
    /** Asks WSERV to give notification when an event is waiting */
        {
        SetActive();
        iWsSession.EventReady(&iStatus);
        }
    
    void RunL()
        {
        if (!iInitializationComplete)
            { // invalidate window server scene to get the latest drawing commands
              // now that alf is there  
            iWindowGc = new CWindowGc(iScreenDevice);
            if (iWindowGc)
                {
                if(iWindowGc->Construct() == KErrNone)
                    {
                    iWindowGc->Activate(*iWindow);
                    iWindowGc->SetBrushColor(0xffffffff);
                    iWindowGc->Clear();
                    iWindowGc->Deactivate();
                    }                
                }

            iWindowGroup.SetOrdinalPosition(-1,ECoeWinPriorityNeverAtFront);
            iWsSession.Flush();
            iInitializationComplete = ETrue;
            RequestEventNotification(); 
            return;
            }
    
        switch (iStatus.Int())
            {
        case KErrNone:
            break;
        case KErrCancel:
        case KErrServerTerminated:
        default:
            return;
            }

        TWsEvent event;
        iWsSession.GetEvent(event);
        
        if( event.Type() == EEventScreenDeviceChanged  )
            {
#ifdef ALF_USE_EMULATOR_LAYOUT_SWITCH_BUTTON
            // Update window size when layout changes. The ScreenDevice
            // has to be updated separately, otherwise it will always return the orig resolution.
            iScreenDevice->SetAppScreenMode(iScreenDevice->CurrentScreenMode());
            
            TSize size = iScreenDevice->SizeInPixels();
            TSize origSize = iWindow->Size();
            
            TPixelsAndRotation rotation;
            iScreenDevice->GetDefaultScreenSizeAndRotation(rotation);
            
            // Set the new size to the window, if it wasn't orientation change within same resolution.
            if (origSize != size && rotation.iRotation == CFbsBitGc::EGraphicsOrientationNormal)
                {
                iWindow->SetSize(size);
                iWindow->Size(); // To populate size cache
                }
#else            
            // update window size when layout changes    
            iScreenDevice->SetAppScreenMode(iScreenDevice->CurrentScreenMode());
            iWindow->SetSize(iScreenDevice->SizeInPixels());
#endif
            
			// This is a workaround for possibly missing command buffers at layout switch
            iWsSession.ClearAllRedrawStores(); 
            
            __ALFLOGSTRING2("ALF EventWin: Size(%d,%d)", iWindow->Size().iWidth, iWindow->Size().iHeight );
            //and fall through
            }
    
        RequestEventNotification();     //Request now so that WSERV has time to respond (on SMP systems) before the return to the Active Scheduler
        iBridge->AddEventL(event);    
        }    
    
    void DoCancel()
        {
        iWsSession.EventReadyCancel();
        }
    
    RWsSession& iWsSession;
    RWindowGroup iWindowGroup;
    CWsScreenDevice* iScreenDevice;
    RWindow* iWindow;
    CAlfEventBridge* iBridge;  
    TBool iInitializationComplete;
    CWindowGc* iWindowGc;
    };

LOCAL_C void DoAlfEventThreadStartFunctionL(CAlfEventBridge* aBridge)
    {
    RWsSession wsSession;
    wsSession.Connect();
    CleanupClosePushL(wsSession);
        
    CAlfEventFetcher* fetch = CAlfEventFetcher::NewLC(wsSession, aBridge);
                    
    CActiveScheduler::Start();
    CleanupStack::PopAndDestroy(2); // ws, fetcher
    }

// ---------------------------------------------------------------------------
// Entry point into the new thread
// ---------------------------------------------------------------------------
//   
GLDEF_C TInt AlfEventThreadStartFunction(TAny* aBridge)
    {
    __UHEAP_MARK;

    TInt err = User::RenameThread(KAlfEventThreadName);
    if (err == KErrNone)
        {
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

        TRAP(err,DoAlfEventThreadStartFunctionL((CAlfEventBridge*)aBridge));

        delete CActiveScheduler::Current();
        delete trapCleanup;
        }
    __UHEAP_MARKEND;
    return err;
    }
    
// ==============END EVENT THREAD=====================



NONSHARABLE_CLASS(CAlfAppUi::CAlfAppUiData)
    : public CBase
    {
public:
    // Environment. Owned.
    CHuiEnv* iHuiEnv;
    
    // Pointer to server. Not owned.
    CAlfAppServer* iServer;
    
    // Shared window-owning control. Owned.
    CAlfSharedDisplayCoeControl* iSharedWindow;
    CAlfAppSrvSessionBase* iActiveSession;
    
    CAlfSrvResourceManager* iResourceManager;
    CAlfSrvSettingsHandler* iSettingsHandler;

    ~CAlfAppUiData() // for convenience
        {
        if ( iServer )
            {
            // Infom texture manager that env is deleted.
            iServer->TextureManager().HandleEnvToBeDeleted();
            }
            
        delete iSettingsHandler;
        delete iResourceManager;
        if (iEventAo)
            {
            iEventAo->Cancel();
            }
        delete iEventAo; // before session is being terminated       
        delete iHuiEnv;
        delete iSharedWindow;
#ifdef SYMBIAN_BUILD_GCE
        delete iBridgeObj;
#endif // #ifdef SYMBIAN_BUILD_GCE
        }
    TBool iAllClientsClosed;

    // Boolean flag indicating if non-fading of shared window is enabled or disabled.
    TBool iSharedWindowNonFading;
#ifdef SYMBIAN_BUILD_GCE
    CAlfBridge* iBridgeObj;
    CAlfStreamerBridge* iBridge;
#endif // #ifdef SYMBIAN_BUILD_GCE
    RWindow* iPlainWindow;
    CHuiDisplay* iMainDisplay;
    CHuiDisplay* iTVDisplay;
    CAlfEventBridge* iEventAo;
    RAlfTfxClient iDsServer;
    TBool iDsActivated;
    };

// ======== MEMBER FUNCTIONS ========

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
EXPORT_C CAlfAppUi::CAlfAppUi()
    {
    if (CCoeEnv::Static())    
        {
        SetFullScreenApp(EFalse); // to avoid getting queued/suspended in case of S60 system events
        }
    }

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
EXPORT_C CAlfAppUi::~CAlfAppUi()
    {
    #ifdef USE_MODULE_TEST_HOOKS_FOR_ALF
    delete AMT_CONTROL();
    #endif
    
    delete iData;
    }
  
 
// ---------------------------------------------------------------------------
// Returns HuiEnv.
// ---------------------------------------------------------------------------
// 
CHuiEnv& CAlfAppUi::HuiEnv()
    {
    return *iData->iHuiEnv;
    }


void AllocTestCreateHuiEnvL(CHuiEnv** aEnv, TInt aRenderer)
    {
    // Create as big bitmap as CHuiTextureManager. This will create
    // a scanline buffer in the "static" RFbsSession.
    CFbsBitmap* bitmap = new (ELeave) CFbsBitmap();
    CleanupStack::PushL( bitmap );
    User::LeaveIfError( bitmap->Create(TSize(4, 4), EColor64K) );
    
    TUint allocFail(0);
    for (TInt err = KErrNoMemory; err != KErrNone; allocFail++)
        {
        __UHEAP_SETFAIL(RHeap::EDeterministic, allocFail); 
        __UHEAP_MARK;
        TRAP(err, *aEnv = CHuiEnv::NewL((THuiRenderer)aRenderer));
        if ( (err != KErrNoMemory) && (err != KErrNone) )
            {
            //User::Panic(_L("HUIEnv Alloc Test"), err);
            }
        if (err == KErrNone)
            {
            __UHEAP_RESET;
            }
        else
            {
            __UHEAP_MARKEND;
            }    
        }
    __UHEAP_SETFAIL(RHeap::ENone, 0);
    
    // delete the bitmap
    CleanupStack::PopAndDestroy( bitmap );
    }
  
// ---------------------------------------------------------------------------
// Allocates HuiEnv.
// ---------------------------------------------------------------------------
//
void CAlfAppUi::CreateHuiEnvL()
    {
    ASSERT(!iData->iHuiEnv); // Cannot create the environment twice.

    THuiRenderer renderer =  iData->iSettingsHandler->Renderer();
    
    // Note: CHuiEnv::NewL might change renderer internally
    
#ifdef _DEBUG
    if ( renderer == EHuiRendererBitgdi ) // OPEN GL Would fail because of driver probs
        {
// Remove memory failure test because it causes problems with ECOM plugins
//        AllocTestCreateHuiEnvL(&iData->iHuiEnv, renderer);
        iData->iHuiEnv = CHuiEnv::NewL( renderer );
        }
    else
        {
        iData->iHuiEnv = CHuiEnv::NewL( renderer );
        }
#else
    iData->iHuiEnv = CHuiEnv::NewL( renderer );
#endif
    iData->iHuiEnv->SetMaxCpuTime( iData->iSettingsHandler->MaxCpuUsage() );
    } 
    
// ---------------------------------------------------------------------------
// Called when all the clients have exited.
// ---------------------------------------------------------------------------
//
void CAlfAppUi::AllClientsClosed()
    {
// In NGA master scene graph role, 
// we must not close the server even there were no hitchcock app clients present
#ifndef SYMBIAN_BUILD_GCE
    iData->iAllClientsClosed = ETrue;
    CAknEnv::Static()->RunAppShutter();
#endif // #ifdef SYMBIAN_BUILD_GCE
    }

// ---------------------------------------------------------------------------
// From class CAknAppUi.
// 2nd phase constructor
// ---------------------------------------------------------------------------
//
EXPORT_C void CAlfAppUi::ConstructL()
    {
    __ALFLOGSTRING( "CAlfAppUi::ConstructL start" )
    
    #ifdef USE_MODULE_TEST_HOOKS_FOR_ALF
    __ALFLOGSTRING( "CAlfAppUi::ConstructL. Open and initialize ALF module test chunk. " )
    // Initiliaze global data in TLS. 
    User::LeaveIfError(Dll::SetTls(new(ELeave) CAlfModuleTestDataControl()));
    // Open global module testing chunk and mutex
    User::LeaveIfError(AMT_CONTROL()->OpenGlobalObjects());
    __ALFLOGSTRING( "CAlfAppUi::ConstructL. ALF module test chunk ready. " )
    #endif
     
  
    TInt flags = EStandardApp|ENoScreenFurniture|ENonStandardResourceFile|EAknEnableSkin;
    CCoeEnv* coe = CCoeEnv::Static();
    iData =  new (ELeave) CAlfAppUiData();

    iData->iSettingsHandler = CAlfSrvSettingsHandler::NewL( *this );
    CreateHuiEnvL();
    
    if (coe)
        {
        // initialize app basic services
        CAknAppUi::BaseConstructL(flags);

        // create direct pointer to server so no need to access coestatics whenever server needed
        iData->iServer = static_cast<CAlfAppServer*>(static_cast<CEikonEnv*>(coe)->AppServer());
        }
    else
        { 
        iData->iServer = CAlfAppServer::NewAppServerL();
        }

    iData->iServer->SetAppUi(this);     
    
    RWindowGroup& mainWg = *CHuiStatic::RootWin();
    // to non-focusing
    mainWg.EnableReceiptOfFocus(EFalse); 
    // disable pointer events based autoforwarding
    mainWg.AutoForeground(EFalse);
    mainWg.SetOrdinalPosition(-1,ECoeWinPriorityNeverAtFront);


    if (!coe) // multiple screen support missing, for main display only atm
        {
        TUid appUid = TUid::Uid(KAlfAppServerInterfaceUid3);
        // complete server construction
        TName serverName;
        _LIT(KServerNameFormat, "%08x_%08x_AppServer");
        serverName.Format( 
                KServerNameFormat, 
                appUid, 
                appUid.iUid );
        
        iData->iServer->ConstructL(serverName);
        
        // parametrize our window group
        CApaWindowGroupName* wgName = CApaWindowGroupName::NewLC(CHuiStatic::WsSession());
        wgName->SetHidden(ETrue); // hides us from FSW and protects us from OOM FW etc.
        wgName->SetSystem(ETrue); // Allow only application with PowerManagement cap to shut us down    
        wgName->SetCaptionL(_L("ALF"));
        wgName->SetAppUid(appUid);
        wgName->SetWindowGroupName(mainWg);
        CleanupStack::PopAndDestroy();
        }
    // misc settings for surroundings     
    if (coe)
        { // we ndon't need these in NGA
        mainWg.EnableFocusChangeEvents();
        }
        
    CHuiStatic::WsSession().ComputeMode(RWsSession::EPriorityControlDisabled);

    RThread thread; 
#if defined(__EPOC32__)
    thread.SetProcessPriority(EPriorityForeground);    
#else
    thread.SetPriority(EPriorityAbsoluteForegroundNormal);    
#endif

    // delegates..
    iData->iResourceManager = CAlfSrvResourceManager::NewL( *iData->iHuiEnv );

    if (coe)
        {
        iData->iSharedWindow = new (ELeave) CAlfSharedDisplayCoeControl();
        iData->iSharedWindow->ConstructL();
        iData->iSharedWindow->DrawableWindow()->EnableVisibilityChangeEvents();
        }
    else
        { 
        //mainWg.EnableScreenChangeEvents();
        
        CHuiStatic::WsSession().EnableWindowSizeCacheL();
        iData->iPlainWindow = new (ELeave) RWindow(CHuiStatic::WsSession());
        iData->iPlainWindow->Construct(*CHuiStatic::RootWin(),0x000FAB10); // FYI: multiple display support neglegted atm
        iData->iPlainWindow->SetExtentErr(TPoint(0,0),CHuiStatic::ScreenDevice()->SizeInPixels()); // FYI: multiple display support neglegted atm            
        iData->iPlainWindow->Size(); // to populate size cache
        iData->iPlainWindow->Activate();
        iData->iPlainWindow->SetVisible(ETrue);
        iData->iPlainWindow->SetTransparencyAlphaChannel();
        iData->iPlainWindow->SetBackgroundColor(~0);          
        }

#ifdef SYMBIAN_BUILD_GCE    

    iData->iBridgeObj = CAlfBridge::NewL( &iData->iBridge, iData->iHuiEnv );
	iData->iBridgeObj->iAppUi = this;
		
    if( !iData->iPlainWindow)
        {
        // Create default CAlfScreen already now to be able to show controlgroups early enough... 
  	    iData->iBridgeObj->AddNewScreenL(iData->iSharedWindow);
        }
    else 
        {
  	    iData->iBridgeObj->AddNewScreenFromWindowL(iData->iPlainWindow);
        iData->iEventAo = new (ELeave) CAlfEventBridge(*this, *iData->iBridgeObj->Display(0));
        
        RThread eventThread;

        User::LeaveIfError(eventThread.Create(
            KAlfEventThreadName,
            AlfEventThreadStartFunction,
            16384, // magic
            0, // uses same heap
            (TAny*)iData->iEventAo, 
            EOwnerThread));

        eventThread.Resume();
        eventThread.Close();
        }

    AppendDisplayOnSharedWindowL(*(iData->iBridgeObj->Display(0)));

    iData->iBridge = CAlfStreamerBridge::NewL(iData->iBridgeObj);
    iData->iBridge->iAlfWindowData.iAlfWindowGrpId = mainWg.Identifier();
    iData->iBridge->iAlfWindowData.iAlfWindowHandle =  iData->iPlainWindow->ClientHandle();
    iData->iBridge->iAlfWindowData.iScreenNumber = 0; // TBD multiple screen support
        
    TThreadId threadId;
  	CAlfStreamerServer::LaunchServer(threadId, iData->iBridge);
    
#endif // #ifdef SYMBIAN_BUILD_GCE    
    // Inform texture manager that env has been created.
    iData->iServer->TextureManager().HandleEnvCreateL( *iData->iHuiEnv );
    
    // Construct transition effect instance if it does not yet exist
	iData->iServer->CreateTransitionEffectsL();
	
	// Load Tfx server client API plugin, if exists
	iData->iServer->CreateTfxServerPlugin();
    
#ifdef SYMBIAN_GRAPHICS_WSERV_QT_EFFECTS
    iData->iBridgeObj->ForceSwRendering(ETrue);
#endif

    __ALFLOGSTRING( "CAlfAppUi::ConstructL end" )
    }
    
// ---------------------------------------------------------------------------
// From class CAknAppUi.
// Handles system event.
// ---------------------------------------------------------------------------
//
EXPORT_C void CAlfAppUi::HandleSystemEventL(const TWsEvent& aEvent)
    {
    switch (*(TApaSystemEvent*)(aEvent.EventData()))
		{
	case EApaSystemEventBroughtToForeground:
        { // we need to suppress this event as it causes undesired effects on applications underneath
        break;
        }
    default:
        CAknAppUi::HandleSystemEventL(aEvent);
        }

    return;
    }

void CAlfAppUi::StartPointerEventHandling()
    {
    if (iData->iActiveSession)
        {
        iData->iActiveSession->StartPointerHandling();
        }
    }

void CAlfAppUi::EndPointerEventHandling()
    {
    if (iData->iActiveSession)
        {
        iData->iActiveSession->FlushPointerHandling();
        }
    }

void CAlfAppUi::UpdateActiveSession(CAlfAppSrvSessionBase* aSession)
    {
    EndPointerEventHandling();
    iData->iActiveSession = aSession;
    
    iData->iResourceManager->SetActiveSession( iData->iActiveSession );

    if (CCoeEnv::Static())
        {   
        if( aSession )
            {
            CHuiStatic::RootWin()->EnableGroupListChangeEvents();
            }
        else
            {
            CHuiStatic::RootWin()->DisableGroupListChangeEvents();
            }
        }
    if(!aSession)
        {
        if (iData->iMainDisplay) // TBD: multiple display support once again...
            {
            iData->iMainDisplay->SetClearBackgroundL(CHuiDisplay::EClearNone);
            }
        }
    }
    
// ---------------------------------------------------------------------------
// From class CAknAppUi.
// Handles window server event.
// ---------------------------------------------------------------------------
//
EXPORT_C void CAlfAppUi::HandleWsEventL(const TWsEvent& aEvent, CCoeControl* aDestination)
    {
    TBool handlingPtrEvent(EFalse);
    
    if (aEvent.Type() >= EEventPointer && aEvent.Type() <= 	EEventDragDrop )
        {
        StartPointerEventHandling();
        handlingPtrEvent = ETrue; // just to play it safe
        }

    // A Fix for AlfServer not shutting down on power off (ANIA-7EWFV6)
    if ( aEvent.Type() == EEventPowerMgmt ) 
        {
        TApaSystemEvent systemEvent( *(TApaSystemEvent*)(aEvent.EventData()) );
        if ( systemEvent == EApaSystemEventShutdown || systemEvent == EApaSystemEventSecureShutdown )
            {
            // Don't let this event go further to base class' HandleWsEventL,
            // since it'll start the appShutter, which will be ignored first,
            // and when it would be really needed (after AllClientsClosed), it's already destroyed. 
            return;
            }
        }
    
    if (!iData->iEventAo) // CCoeEnv exists
        {
        CAknAppUi::HandleWsEventL(aEvent, aDestination);
        if (handlingPtrEvent)
            {
            EndPointerEventHandling();
            }
        }
    else
        {
        if( aEvent.Type() == EEventScreenDeviceChanged  )
            {
            HandleResourceChangeL( KEikDynamicLayoutVariantSwitch );
            }
        }
    
    switch ( aEvent.Type() )
        {
        case EEventFocusGroupChanged:
        case EEventWindowGroupListChanged:
            {
            if( iData->iActiveSession )
                {                
                if( iData->iServer->AlfClientHasFocus() )
                    {
                     iData->iActiveSession->SetBackgroundMaxFps( EFalse );
                    }
                else
                    {
                    iData->iActiveSession->SetBackgroundMaxFps( ETrue );
                    }
                }
            break;
            }
        case EEventWindowVisibilityChanged:
            {   
            iData->iResourceManager->SetServerWindowPartiallyVisible( 
                    !(aEvent.VisibilityChanged()->iFlags&TWsVisibilityChangedEvent::ENotVisible) );
            break;
            }
        default:
            break;
        }
    }
    
// ---------------------------------------------------------------------------
// Called when client is about to exit.
// ---------------------------------------------------------------------------
//
void CAlfAppUi::FreeResourcesForClient( TInt aClientId )
    {
    if (aClientId == TInt(iData->iActiveSession))
        {
        iData->iActiveSession = 0;
        iData->iResourceManager->SetActiveSession( NULL );
        }
    }
    
// ---------------------------------------------------------------------------
// Returns the shared window-owning control.
// ---------------------------------------------------------------------------
//
EXPORT_C CCoeControl* CAlfAppUi::Container()
    {
    return iData->iSharedWindow;
    }
  
// ---------------------------------------------------------------------------
// Adds display into the redraw stack.
// ---------------------------------------------------------------------------
//  
EXPORT_C void CAlfAppUi::AppendDisplayOnSharedWindowL( CHuiDisplay& aDisplay )
    {
    if (!iData->iMainDisplay) // TBD: multiple display support once again...
        {
        iData->iMainDisplay = &aDisplay;
        }
    // with one display, one session (then one who creates the display) 
    // needs to add the display onto the shared window list.
    if ( !iData->iSharedWindow || iData->iSharedWindow->iDisplays.Count() > 0 )
        {
        return; 
        }
    User::LeaveIfError( iData->iSharedWindow->iDisplays.Append( &aDisplay ) );
    }

// ---------------------------------------------------------------------------
// Adds TV display into the redraw stack.
// ---------------------------------------------------------------------------
//  
void CAlfAppUi::AppendTvDisplayOnSharedWindowL( CHuiDisplay& aDisplay )
    {
    if (!iData->iTVDisplay) // TBD: true multiple display support once again...
        {
        iData->iTVDisplay = &aDisplay;
        }

    if ( !iData->iSharedWindow || iData->iSharedWindow->iDisplays.Count() > 1 )
        {
        return; 
        }
    
    User::LeaveIfError( iData->iSharedWindow->iDisplays.Append( &aDisplay ) );
    }

// ---------------------------------------------------------------------------
// Removes TV display from the redraw stack.
// ---------------------------------------------------------------------------
//  
void CAlfAppUi::RemoveTvDisplayOnSharedWindow( CHuiDisplay& /*aDisplay*/ )
    {
    iData->iTVDisplay = 0;

    if ( !iData->iSharedWindow || iData->iSharedWindow->iDisplays.Count() > 1 )
        {
        iData->iSharedWindow->iDisplays.Remove(1); 
        }        
    }


// ---------------------------------------------------------------------------
// Finds TV display from the redraw stack.
// ---------------------------------------------------------------------------
//  
CHuiDisplay* CAlfAppUi::FindTvDisplayOnSharedWindow()
    {
    return iData->iTVDisplay;
    }

// ---------------------------------------------------------------------------
// From class CAknAppUi.
// This is last entry where we can execute code before coe scheduler started
// ---------------------------------------------------------------------------
//
EXPORT_C TBool CAlfAppUi::FrameworkCallsRendezvous() const
    {
    // just basecall for now    
    return CAknAppUi::FrameworkCallsRendezvous();      
    }

// ---------------------------------------------------------------------------
// From class CAknAppUi.
// Called when system resources have changed.
// ---------------------------------------------------------------------------
//
EXPORT_C void CAlfAppUi::HandleResourceChangeL( TInt aType )
    {
    // A piece of code to resizing the surface on emulator.
#ifdef ALF_USE_EMULATOR_LAYOUT_SWITCH_BUTTON
    // Re-create the CWsScreenDevice, as the one cached in the HuiStatic doesn't
    // seem to notice the layout & orientation changes..

    CWsScreenDevice* screenDevice = CHuiStatic::ScreenDevice(0);
    screenDevice->SetAppScreenMode(screenDevice->CurrentScreenMode());
    
    TPixelsAndRotation rotation;
    screenDevice->GetDefaultScreenSizeAndRotation(rotation);
    
    // Get the sizes and set the new size for the main window
    TSize size = screenDevice->SizeInPixels();
    TSize origSize = iData->iHuiEnv->Display(0).Size();
    
    // No need to touch if just rotating, so skip the plain orientation change
    if (origSize != size && rotation.iRotation == CFbsBitGc::EGraphicsOrientationNormal)
        {
        TInt err = iData->iPlainWindow->SetSizeErr(size);
        iData->iPlainWindow->Size(); // To populate size cache.
        
        iData->iHuiEnv->Display(0).SetSizeL(size);
        iData->iHuiEnv->Display(0).SetVisibleArea(TRect(size));
        }
#endif
    
    if ( aType == KEikDynamicLayoutVariantSwitch || aType == KAknsMessageSkinChange && iData->iHuiEnv)
        {
        iData->iHuiEnv->Skin().NotifyDisplaySizeChangedL();
        }
        
    // Send notification events to clients here if needed    
    if (iData->iServer)
        {
        // Only KAknsMessageSkinChange is delivered to clients for now        
        if (aType == KAknsMessageSkinChange)
            {
            // We don't deliver wallpapaper change or morphing change
            // because textures should not depend on those -> no texture reuploads needed.
            if (CHuiStatic::SkinInstance())
                {
                if (AknsUtils::SkinInstance()->SkinChangeReason() == ENormalSkinChange)
                    {
                    iData->iServer->TriggerSystemEvent(KAknsMessageSkinChange);                         
                    }
                }
            }        
        }       
        
    // don't base call
    }

// ---------------------------------------------------------------------------
// From class CAknAppUi.
// Called when a command is received.
// ---------------------------------------------------------------------------
//
EXPORT_C void CAlfAppUi::HandleCommandL(TInt aCommand)
    {
    if (aCommand == EEikCmdExit && iData->iAllClientsClosed)
        {
        Exit();
        }
    }

// ---------------------------------------------------------------------------
// Return settings handler
// ---------------------------------------------------------------------------
//
CAlfSrvSettingsHandler& CAlfAppUi::SettingsHandler()
    {
    return *iData->iSettingsHandler;
    }

// ---------------------------------------------------------------------------
// Updates non-fading setting to window.
// ---------------------------------------------------------------------------
//
void CAlfAppUi::SetContainerNonFading( TBool aNonFading )
    {
    const TBool nonFading = iData->iSharedWindowNonFading;
    if ( ( nonFading && !aNonFading ) ||
         ( !nonFading && aNonFading ) )
        {
        // Update window server setting.
        iData->iSharedWindowNonFading = aNonFading;
        iData->iSharedWindow->DrawableWindow()->SetNonFading( aNonFading );
        
        // If non-fading is turned off, update fading to correct value.
        // It's assumed that alfred applications are not shown in a pop up.
        // If it were possible, we would need to know if alfred pop up is
        // topmost.
        if ( !aNonFading )
            {
            iData->iSharedWindow->DrawableWindow()->SetFaded( 
                IsFaded(),
                RWindowTreeNode::EFadeIncludeChildren );
            }
        }
    }

// ---------------------------------------------------------------------------
// Called when setting changes.
// ---------------------------------------------------------------------------
//
void CAlfAppUi::MAlfSrvUintSettingChangedL( TAlfSrvSetting aSetting, TUint aNewValue )
    {
    switch( aSetting )
        {
        case EAlfSrvSettingDefaultFramerate:
            // No need to update. Session will fetch the 
            // updated default frame rate when it receives 
            // focus for the next time. 
            break;
        case EAlfSrvSettingMaxCpuUsage:
            iData->iHuiEnv->SetMaxCpuTime( aNewValue );
            break;
        case EAlfSrvSettingMaxResourceCacheSize:
            // RnD feature. Cache side will not change in the 
            // final release.
            break;
        case EAlfSrvSettingEffectsComplexityFactor:
            {
            // Currently this key has no effect, for future expansion.
            
            // check RnD flags update
            const TUint rndFlags = iData->iSettingsHandler->RndFlags();
            // check dirty region redrawing
            for ( TInt d = 0; d < iData->iHuiEnv->DisplayCount() ; d++ )
                {
                // check dirty region redrawing
                iData->iHuiEnv->Display( d ).ShowDirtyRegions( 
                    rndFlags&EAlfSrvRndFlagDrawDirtyRegions );
                    
                //check visual outline drawing    
                if ( rndFlags&EAlfSrvRndFlagDrawAllVisualOutline )
                    {
                    iData->iHuiEnv->Display( d ).SetDrawVisualOutline( CHuiDisplay::EDrawVisualOutlineAllVisuals );
                    }
                else if ( rndFlags&EAlfSrvRndFlagDrawSelectedVisualOutline )
                    {
                    iData->iHuiEnv->Display( d ).SetDrawVisualOutline( CHuiDisplay::EDrawVisualOutlineSelectedVisuals );
                    }
                else
                    {
                    iData->iHuiEnv->Display( d ).SetDrawVisualOutline( CHuiDisplay::EDrawVisualOutlineNone );
                    }
                }

            // Check for Rnd flags
            // Currently used to enable/disable texture memory calculation but can be used for any Rnd flag in future
            iData->iHuiEnv->EnableDebugFlag( rndFlags );

            }
            break;
        default:
            User::Leave( KErrNotSupported );
            break;
        }
    }


TTypeUid::Ptr CAlfAppUi::MopSupplyObject(TTypeUid aId)
    {
    return CAknAppUi::MopSupplyObject(aId);
    }

// ---------------------------------------------------------------------------
// 
// ---------------------------------------------------------------------------
//
TInt CAlfAppUi::FirstAlfControlGroupIndex( TInt aScreenNumber )
    {
#ifdef SYMBIAN_BUILD_GCE
    return iData->iBridgeObj->FirstAlfControlGroupIndex( aScreenNumber );
#endif // #ifdef SYMBIAN_BUILD_GCE
    }

// ---------------------------------------------------------------------------
// 
// ---------------------------------------------------------------------------
//
TInt CAlfAppUi::LastAlfControlGroupIndex( TInt aScreenNumber )
    {
#ifdef SYMBIAN_BUILD_GCE
    return iData->iBridgeObj->LastAlfControlGroupIndex( aScreenNumber );
#endif // #ifdef SYMBIAN_BUILD_GCE
    }


// ---------------------------------------------------------------------------
// 
// ---------------------------------------------------------------------------
//
void CAlfAppUi::ShowControlGroupL(CHuiRoster& aRoster, CHuiControlGroup& aGroup, TInt aWhere, TInt aScreenNumber )
    {
#ifdef SYMBIAN_BUILD_GCE
    iData->iBridgeObj->ShowControlGroupL(aRoster, aGroup, aWhere, aScreenNumber);    
    iData->iBridgeObj->HandleVisualVisibility( aScreenNumber );    
#endif // #ifdef SYMBIAN_BUILD_GCE

    }

// ---------------------------------------------------------------------------
// PostQTCommandBufferL
// ---------------------------------------------------------------------------
//
void CAlfAppUi::PostQTCommandBufferL( TAlfQtCommandBufferParams aParams )
    {    
    if ( iData )
        {
        if( iData->iBridgeObj )
            {
            iData->iBridgeObj->PostQTCommandBufferL( aParams ); 
            }
        } 
    }

    
// ---------------------------------------------------------------------------
//
// ---------------------------------------------------------------------------
//
void CAlfAppUi::SetClientWindowForDrawingL(TInt aWindowGroupId, TInt aClientWindowHandle, CHuiVisual* aVisual)
	{
	iData->iBridgeObj->SetClientWindowForDrawingL(aWindowGroupId, aClientWindowHandle, aVisual);
	}
    

void CAlfAppUi::AdjustWindowGroupPositionL(TInt aParentIdentifier, TInt aPosition)
    {
    iData->iEventAo->AdjustWindowGroupPositionL(aParentIdentifier, aPosition);
    }

void CAlfAppUi::SetAlfWindowGroupId(TInt aWgId)
    {
    iData->iBridgeObj->SetAlfWindowGroupId(aWgId);
    }
    

// ---------------------------------------------------------------------------
// NotifyLowMemory
// ---------------------------------------------------------------------------
//
void CAlfAppUi::NotifyLowMemory(TInt aAmountOfFreeMemRequested)
    {
    if (!iData->iDsActivated)            
        {
        if (iData->iDsServer.Open() == KErrNone)
            {
            iData->iDsActivated = ETrue;            
            }
        }
    
    if (iData->iDsActivated )
        {
        if (!aAmountOfFreeMemRequested)
            {
            iData->iDsServer.SendSynch(KAlfCompositionGoodOnGraphicsMemory, TIpcArgs());
            }
        else
            {          
            iData->iDsServer.SendSynch(KAlfCompositionLowOnGraphicsMemory, TIpcArgs());
            }
        }

/*
	// Toggle between normal & low memory levels
    if (!aAmountOfFreeMemRequested)
        {
        iData->iBridgeObj->SetMemoryLevel(EHuiMemoryLevelNormal);
        }
    else
        {
        iData->iBridgeObj->SetMemoryLevel(EHuiMemoryLevelLow);        
        }
*/

	// Enable "ultra-low" memory mode
    if (!aAmountOfFreeMemRequested)
        {
        iData->iBridgeObj->SetMemoryLevel(EHuiMemoryLevelNormal);
        }
    else
        {
        iData->iBridgeObj->SetMemoryLevel(EHuiMemoryLevelLowest);        
        }
    }    
    
// ---------------------------------------------------------------------------
// ForceSwRendering
// ---------------------------------------------------------------------------
//
TInt CAlfAppUi::ForceSwRendering( TBool aEnabled )
    {
    return iData->iBridgeObj->ForceSwRendering( aEnabled );
    }
    
// end of file
