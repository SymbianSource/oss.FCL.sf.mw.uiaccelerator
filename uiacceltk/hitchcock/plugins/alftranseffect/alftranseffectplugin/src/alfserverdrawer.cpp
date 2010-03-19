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
* Description:   window server plugin, used by transition server to control
*                framebuffers.
*
*/



#include <bitstd.h>
#include <s32mem.h> //RMemReadStream
#include <e32cmn.h>
#include <apgwgnam.h>
#include <bautils.h> 

#include <akntranseffect.h> 
#include <akntransitionutils.h>

#include "alfwindowmanager.h"
#include "alfserverdrawer.h"
#include "wsserverdrawercontroller.h"
#include "alfgfxeffects.h"
#include "alfwindow.h"
#include "alfstreamerbridge.h"
#include "alfpolicyhandler.h"
#include <alflogger.h>
#include <uiacceltk/HuiUtil.h>

#ifdef __WINS__
const TInt KAlfShortEffectTimeout = 4000000;
const TInt KAlfLongEffectTimeout  = 5000000;
#else
const TInt KAlfShortEffectTimeout = 2000000;
const TInt KAlfLongEffectTimeout  = 3000000;
#endif
//const TInt KAlfLongEffectTimeout  = 500000;


// Timer to send finish full screen effect
// ---------------------------------------------------------
// CAlfFinishTimer
// ---------------------------------------------------------
//
NONSHARABLE_CLASS( CAlfFinishTimer ):public CTimer
    {
    public:  // Constructors and destructor
        static CAlfFinishTimer* NewL();
        virtual ~CAlfFinishTimer();

    public: // New functions
            
        void Start( TTimeIntervalMicroSeconds32 aPeriod, TCallBack aTimeoutCallback );
        
    protected:  // Functions from base classes
        
        void DoCancel();

    private:

        CAlfFinishTimer();
        void ConstructL();
        void RunL();
      
    private:    // Data
                
    TCallBack iCallback;
 
    };


// ---------------------------------------------------------
// CAlfFinishTimer
// ---------------------------------------------------------
//
CAlfFinishTimer::CAlfFinishTimer()
    :CTimer ( EPriorityStandard )
    {   
    }

void CAlfFinishTimer::ConstructL()
    {
    CTimer::ConstructL();
    CActiveScheduler::Add( this );
    }

CAlfFinishTimer* CAlfFinishTimer::NewL()
    {
    CAlfFinishTimer* self = new ( ELeave ) CAlfFinishTimer;
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop( self );
    return self;
    }

CAlfFinishTimer::~CAlfFinishTimer()
    {
    Cancel();        
    }

void CAlfFinishTimer::Start( TTimeIntervalMicroSeconds32 aPeriod, TCallBack aTimeoutCallback )
    {
    iCallback = aTimeoutCallback; 
    After( aPeriod );
    }

void CAlfFinishTimer::RunL()
    {
    //
    // timer completes and control is returned to caller
    //
    if ( iStatus.Int() != KErrCancel )
        {
        iCallback.CallBack();
        }
    }

void CAlfFinishTimer::DoCancel()
    {
    CTimer::DoCancel();
    }


NONSHARABLE_CLASS( CPSObserver ): public CActive
    {
    public:
        static CPSObserver* NewL( const TUid& aUid, TInt aKey );
        void StartObserving( TCallBack aCallback, TInt aHandle );
        ~CPSObserver();
    private:
        CPSObserver();
        void ConstructL( const TUid& aUid, TInt aKey );
        void DoCancel();
        void RunL();
    private:
        RProperty iProperty;
        TInt iKey;
        TCallBack iCallback;
        TInt iHandle;
    };
    
CPSObserver::CPSObserver():
    CActive( CActive::EPriorityHigh )
    {
    }
    
CPSObserver::~CPSObserver()
    {
    Cancel();
    iProperty.Close();
    }
    
CPSObserver* CPSObserver::NewL( const TUid& aUid, TInt aKey )
    {
    CPSObserver* self = new ( ELeave ) CPSObserver();
    CleanupStack::PushL( self );
    self->ConstructL( aUid, aKey );
    CleanupStack::Pop( self );
    return self;
    }

void CPSObserver::ConstructL( const TUid& aUid, TInt aKey ) 
    {
    iKey = aKey;
    User::LeaveIfError( iProperty.Attach( aUid, aKey ) );
    CActiveScheduler::Add( this );
    }

void CPSObserver::StartObserving( TCallBack aCallback, TInt aHandle )
    {
    Cancel();
    iHandle = aHandle;
    iCallback = aCallback;
    iProperty.Subscribe( iStatus );
    SetActive();
    }
    
void CPSObserver::RunL()
    {
    // prepare for stray signals
    iProperty.Subscribe( iStatus );
    SetActive();
    TInt value = -1;
    TInt err = iProperty.Get( value );
    if ( iStatus.Int() != KErrCancel && value == iHandle )
        {
        iCallback.CallBack();
        // Cancel wait for property change until a new effect is started
        Cancel();            
        }
    // If the handle does not match, the ending effect was some earlier one
    // We keep waiting for signal about ending of the correct effect.    
    }
    
void CPSObserver::DoCancel()
    {
    iProperty.Cancel();
    }


// ======== MEMBER FUNCTIONS ========

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
CAlfServerDrawer* CAlfServerDrawer::NewL( CAlfWindowManager* aWindowManager,
    CPolicyHandler& aPolicyHandler )
    {
    CAlfServerDrawer* self = new(ELeave) CAlfServerDrawer( aWindowManager, aPolicyHandler );
	CleanupStack::PushL(self);
	self->ConstructL();
	CleanupStack::Pop(self);
	return self;
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
void CAlfServerDrawer::ConstructL()
    {
    iController = CWsServerDrawerController::NewL(this);

    iIdle = CIdle::NewL(CActive::EPriorityIdle);

    iFullScreenTimeout = CAlfFinishTimer::NewL();
    iFinishFullScreen = CAlfFinishTimer::NewL();
    
    iTransitionEndObserver = CPSObserver::NewL( KPSAlfDomain, KAlfTransitionStatus );
    iProperty.Attach( KPSAlfDomain, KAlfTransitionStatus );
    iProperty.Set( KPSAlfDomain, KAlfTransitionStatus, 0 );
    iFs.Connect();
    
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
CAlfServerDrawer::CAlfServerDrawer( CAlfWindowManager* aWindowManager,
    CPolicyHandler& aPolicyHandler  ):
    iWindowManager( aWindowManager ),
    iPolicyHandler( aPolicyHandler )
    {
    iScrModeChangedState = EScreenModeChangedIdle;
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
CAlfServerDrawer::~CAlfServerDrawer()
    {
    delete iTransitionEndObserver;
    iProperty.Close();
    iFs.Close();
    delete iController;
    delete iIdle;
    delete iFinishFullScreen;
    delete iFullScreenTimeout;
        
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
TInt CAlfServerDrawer::BeginControlTransition( TUint aAction, TUid aControlUid,
    TInt aWindowGroup, TInt aWindowHandle)
    {
  	iControlRect = TRect(); // clear the rectangle

    if ( iInScreenModeChange )
        {
        return KErrAbort;
        }
    else
        {
        iControlAction = aAction;
        iControlUid = aControlUid;
        iControlWindowGroup = aWindowGroup;
        iControlHandle = aWindowHandle;
        return iController->BeginControlTransition();
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
void CAlfServerDrawer::EndControlTransition(TInt aHandle)
    {
    iController->EndControlTransition(aHandle);
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
void CAlfServerDrawer::PrepareFullscreen()
    {
    __ALFFXLOGSTRING(" -> PrepareFullscreen");
    __ALFFXLOGSTRING(" -> PrepareFullscreen end");
    }

void CAlfServerDrawer::UnregisterAllAlfFullScreenEffect()
    {
    TAlfBridgerData bridgerData;  
    bridgerData.Set( EAlfUnregisterAllFx, 0, 0, NULL );              
    iWindowManager->PostIt(bridgerData);
    }
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//  
void CAlfServerDrawer::UnregisterAlfFullScreenEffect( TInt aAction )
    {
    TAlfBridgerData bridgerData;  
    bridgerData.Set( EAlfUnregisterEffectFx, aAction, 0, NULL );              
    iWindowManager->PostIt(bridgerData);
    }

// ---------------------------------------------------------------------------
// BeginSyncronizedGroup
// ---------------------------------------------------------------------------
//  
void CAlfServerDrawer::BeginSyncronizedGroup(TInt aGroupId)
    {
    TAlfBridgerData bridgerData;  
    bridgerData.Set( EAlfEffectFxBeginSyncronizedGroup, aGroupId, 0, NULL );              
    iWindowManager->PostIt(bridgerData);
    }

// ---------------------------------------------------------------------------
// EndSyncronizedGroup
// ---------------------------------------------------------------------------
//  
void CAlfServerDrawer::EndSyncronizedGroup(TInt aGroupId, TBool aForced)
    {
    TAlfBridgerData bridgerData;  
    bridgerData.Set( EAlfEffectFxEndSyncronizedGroup, aGroupId, aForced, NULL );              
    iWindowManager->PostIt(bridgerData);
    }
	
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//  
void CAlfServerDrawer::RegisterAlfFullScreenEffect( TInt aAction, const TDesC& aResourceDir,
        const TDesC& aFileName)
    {
    TAlfBridgerData bridgerData;              
               
    TInt bufferSize = sizeof(TPtrC) + ( aResourceDir.Length()*2) + sizeof(TPtrC) + aFileName.Length() * 2;
    TInt index = 0;

    void* bridgeBuffer = NULL;
    // This function cannot actually leave
    TRAP_IGNORE( bridgeBuffer = (void*)iWindowManager->Bridge()->AppendEffectsDataL( bufferSize, index ) ); 
    if ( bridgeBuffer )
       {
       RMemWriteStream stream( bridgeBuffer, bufferSize );
       // The writes should not leave if we have calculated our buffer length correctly.
       TRAP_IGNORE(
           {
           stream << aResourceDir;
           stream << aFileName;                 
           stream.CommitL();    
           });      
       bridgerData.Set( EAlfRegisterEffectFx, aAction, bufferSize, (TAny*) index );              
       iWindowManager->PostIt(bridgerData);
       stream.Close();
       }
    }
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
void CAlfServerDrawer::BeginFullscreen(	TInt aAction, const TRect& aEffectRect,
                                        TInt aType, const TUid aUid1, const TUid aUid2, TInt aData )
    {  
    if ( iController->AppInfoCache().Action(aUid1) == aAction && 
         iController->AppInfoCache().Action(aUid1) !=  AknTransEffect::EApplicationExit )
        {
        __ALFFXLOGSTRING2(" -> CAlfServerDrawer::BeginFullscreen - skipping action: %d, because previous action is stronger: %d", aAction, iAction);
        // the action must be skipped, because stronger action has been request already.
        return;
        }
    
    __ALFFXLOGSTRING2(" -> CAlfServerDrawer::BeginFullscreen - Action: %d, aType: %d", aAction, aType);
    TInt action = iController->AppInfoCache().SetAction(aUid1, aAction);
    
    // Skip all embedded and background application effects, for now.
    // This addition is to prevent messaging app popping up in startup.
    // AVKON uses wrong parameter type and so NoEffects is not applied.
    if ( action == AknTransEffect::EEmbeddedApplicationExit ||
         action == AknTransEffect::EEmbeddedApplicationStart || 
         action == AknTransEffect::EAppStartupBackground )
        {
        __ALFFXLOGSTRING1(" -> CAlfServerDrawer::BeginFullscreen - Embedded/background (%d) application, skip effect", aAction);
        return;
        }
  
    if ( aAction != AknTransEffect::ENone && aAction != AknTransEffect::EAppStartupBackground )
        {
        // no action or background activity won't stop current effect
        // Matrix Menu sends start rect and avkon sends start for the same application!
        // We assume that we want to keep the rect from Matrix Menu if the app id matches 
//        if ( !iDoNotClearEffectRect )
        if ( iToUid == aUid1 &&
            ( iAction == AknTransEffect::EApplicationStartRect || iAction == AknTransEffect::EApplicationStartSwitchRect ) &&
            ( aAction == AknTransEffect::EApplicationStart || aAction == AknTransEffect::EApplicationStartSwitch ) ) 
            {
            // if we have first got a start rect and the basic start for the same application,
            // we save the rectangle information and keep asking an effect with a rectangle
            aAction = iAction; 
            }
        else
            {
            // This is a new event, we change the rectangle
            iEffectRect = aEffectRect;
            }
        }
        
   	iFlags = AknTransEffect::TParameter::EFlagNone;
	iToUid = KNullUid;
	iFromUid = KNullUid;
	iFocusWg = KErrNotFound;
	
	iType = aType;
	
	if ( aType == AknTransEffect::EParameterType )
		{
        __ALFFXLOGSTRING("CAlfServerDrawer::BeginFullscreen - AknTransEffect::EParameterType");    
        iToUid = aUid1;
        iFromUid = aUid2;
        iFlags = aData;  
		}
	if ( aType == AknTransEffect::EParameterAvkonInternal )
	    {
        // here comes in the avkon info, which will tell us the window group id required for the effect EndFullScreen event
        __ALFFXLOGSTRING("CAlfServerDrawer::BeginFullscreen - AknTransEffect::EParameterAvkonInternal");    
        iToUid = aUid1;
        iParentUid = aUid2;
        iFocusWg = aData;	    
        // We save the action in case we haven't got an EndFullScreen call yet
        iOldAction = iAction;
	    }
	    
    iAction = aAction;
    // TODO: TEMPORARY HACK
    // REMOVE AFTER APPSHELL HAS BEEN FIXED
    // commented out to test if the system works now
    /*
    if ( ( iAction == AknTransEffect::EApplicationStartRect || iAction == AknTransEffect::EApplicationStartSwitchRect ) &&
        iToUid.iUid == 0x101F4CD2 )
        {
        iDoNotClearEffectRect = ETrue;
        }
    */   
    // As appshell uses strange values for folder open and close, we change them now.
    /*
    if ( iAction == 1001 && iToUid.iUid == KAknApplicationShellViewId )
       {
       iAction = AknTransEffect::EApplicationStart;
       }
    if ( iAction == 1002 && iToUid.iUid == KAknApplicationShellViewId  )
       {
       // This might not be the right one, but we try if this is OK
       iAction = AknTransEffect::EApplicationExit;
       }
    */       
	    
    __ALFFXLOGSTRING2("CAlfServerDrawer::BeginFullscreen - From UID: 0x%X, To UID: 0x%X, Application UID: 0x%X", iFromUid.iUid, iToUid.iUid );    
    __ALFFXLOGSTRING3("CAlfServerDrawer::BeginFullscreen - Parent UID: 0x%X, Focus window group UID: 0x%X, Flags: 0x%X", iParentUid.iUid, iFocusWg, iFlags);    
    if( aAction == AknTransEffect::ELayoutSwitch )
        {
        iScrModeChangedState = EScreenModeBeginHasBeenCalled;
        }
    else 
        {
        iScrModeChangedState = EScreenModeChangedIdle;
        }

    iController->BeginFullscreen( aType, aUid1, aUid2, aData );
    __ALFFXLOGSTRING("CAlfServerDrawer::BeginFullscreen end");
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
void CAlfServerDrawer::EndFullscreen()
    {
    __ALFFXLOGSTRING(" -> CAlfServerDrawer::EndFullscreen");
    CancelEndChecker();
    iController->EndFullscreen(EFalse);
    iController->AppInfoCache().ClearActions();
    __ALFFXLOGSTRING("CAlfServerDrawer::EndFullscreen end");
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
void CAlfServerDrawer::CancelFullscreen()
    {
    __ALFFXLOGSTRING(" -> CAlfServerDrawer::CancelFullscreen");
    __ALFFXLOGSTRING("CAlfServerDrawer::CancelFullscreen end");
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
void CAlfServerDrawer::AbortFullscreen()
    {
    __ALFFXLOGSTRING(" -> CAlfServerDrawer::AbortFullscreen");
    iController->AbortTransition(EAbortFullscreen);
    iController->AppInfoCache().ClearActions();
    __ALFFXLOGSTRING("CAlfServerDrawer::AbortFullscreen end");
    }


TInt CAlfServerDrawer::FailedFullscreen(TAny* aArg) 
	{
	CAlfServerDrawer* self = static_cast<CAlfServerDrawer*>(aArg);
	self->iController->EndExpired(); // The same as if End Checker Expires.
	return EFalse;
	}

TBool CAlfServerDrawer::EffectFinishedFullScreen() const
    {
    return iFullScreenFinished;
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
void CAlfServerDrawer::SendBeginFullscreen()
    {
    TRAP_IGNORE(DoSendBeginFullscreenL());
    }
    
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//  
void CAlfServerDrawer::DoSendBeginFullscreenL()
    {
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendBeginFullscreen");
    __ALFFXLOGSTRING(" <- Original window server ids");
    __ALFFXLOGSTRING2("From UID: 0x%X, To UID: 0x%X", iFromUid.iUid, iToUid.iUid);    
    __ALFFXLOGSTRING2("Parent UID: 0x%X, Focus window group UID: 0x%X", iParentUid.iUid, iFocusWg);    
    TInt err = KErrNone;
    
    // This should be only the first half of the effect, the second part should start
    // when we get EndFullScreen
    // Originally this was where the screen capture was made and the drawing redirected.
    // Here we can start doing some effect for the application that is currently on the
    // screen. The new application effect should start at "EndFullScreen"
    // That normally means that the application has drawn something to its window.
    
    iFromWg = 0;
    iToWg = 0;
    
	// TODO: using temp getter for window group ids vs app uids
	//
	// Official implementation pending on new window server APIs expected to available be around W40 
	
    if ( iType == AknTransEffect::EParameterType )
        {
        // TODO TODO TODO TODO TODO TODO TODO
        //  THIS MUST BE FIXED IN ORDER TO HAVE APPLICATION START EFFECTS WORKING!
        //
        // THE WINDOWGROUP LIST FOR APPLICATIONS IS NOT UP-TO-DATE, BECAUSE WE CANNOT ASK IT ANYMORE DIRECTLY 
        // FROM WSERV (DEADLOCK ISSUES).
        // THUS IT IS UP TO CHANCE THAT WE GET A VALID REPLY IN THIS POINT.
        // WE WILL VERY LIKELY NOT INITIATE THE EFFECT AT ALL, WHEN APPLICATION IS REALLY STARTING INSTEAD OF
        // BEING BROUGHT FORWARD FROM BACKGROUND.
        // TODO TODO TODO TODO TODO TODO TODO
        iFromWg = iWindowManager->Bridge()->FindWgForAppUid(iFromUid);
        __ALFFXLOGSTRING2("Window group from from-Application UID: 0x%X wg: 0x%x", iFromUid, iFromWg);    
        //                                                    ---> YES --> id must be valid. continue
        //                        YES --> Is this exit event? 
        // Id found in cache? -->                             ---> NO  --> continue, but refreshed value should overwrite this valua in iEngine.
        //                        NO  --> we must wait for the value.                    
          
        
        if (!iToWg)
        	{
        	iToWg = iWindowManager->Bridge()->FindWgForAppUid(iToUid); // This call might be now obsolete
        	}
        
        __ALFFXLOGSTRING2("Window group from to-Application UID: 0x%X wg: 0x%x", iToUid, iToWg);    
        }
    
    // How do we handle the case where we have app id, parent id and focus wg?
    
    if ( iType == AknTransEffect::EParameterAvkonInternal )
        {
        // Is this "from" or "to" or do we just use iFocusWg?
        iToWg = iWindowManager->Bridge()->FindWgForAppUid(iToUid);
        
        __ALFFXLOGSTRING2("Window group from internal-Application UID: 0x%X wg: 0x%x", iToUid, iToWg);    
        // Is this "from" or "to" or do we just use iFocusWg?
        if ( iParentUid != KNullUid )
            {
            iFromWg = iWindowManager->Bridge()->FindWgForAppUid(iParentUid);
            __ALFFXLOGSTRING2("Window group from parent-Application UID: 0x%X wg: 0x%x", iParentUid,  iFromWg);    
            }
        }
        
    // What do we do if there are no windows?
    // We could use the built-in effect layer, but now we just stop here
    
    // We don't handle the EParameterAvkonInternal type
    // TODO: revise this condition, when appui is available from wserv
    /*if ( ( ( iFromWg == 0 || iFromWg == KErrNotFound ) && 
        ( iToWg == 0 || iToWg == KErrNotFound ) &&
        ( iFocusWg == 0 || iFocusWg == KErrNotFound ) ) ||
        iType == AknTransEffect::EParameterAvkonInternal )
        { // TODO: Uncomment, when appui available in alfbridge
        // bail out, cannot start an effect without any windows
        // We don't need to reset the WinIdLists as they have not been filled
    	iIdle->Start(TCallBack(FailedFullscreen,this));
        return;
        }
        */
    // If we don't have the target window, we bail out
    // This is because we get into trouble if another beginfullscreen
    // follows too fast.
    /*
    if ( iToWg == 0 || iToWg == KErrNotFound )
        {
    	iIdle->Start(TCallBack(FailedFullscreen,this));
        return;
        }
        */
        
    TBool blocked = iController->IsBlocked( iFromUid, iToUid );
    if (blocked)
        {
        return;
        }

    TBool isExit = ( iAction == AknTransEffect::EApplicationExit );
    
    // We should probably get out here if the uids are on the blocked list.
    
    // It appears that the exiting application is the second id
    // The same application appears as second id both when it starts and exits!

    // Get the wanted full screen effect from the policy handler
    
    TInt cachePriority = 0;
   	TInt wantedTime = 0;
	TInt minTime = 0;
	TPtrC resourceDir;
	TPtrC fileName;

    err = iPolicyHandler.GetFullscreenKml( iAction, iToUid, iFromUid, resourceDir, fileName,
        cachePriority, wantedTime, minTime );
    
    
    if ( err != KErrNone || fileName.Length() == 0 || !FileExistsL( resourceDir, fileName ) )
        {
        // Did not find an effect file - nothing to show
        __ALFFXLOGSTRING2(" <- CAlfServerDrawer:: Could not get full screen kml, error %d %S", err, &fileName)
        iFromWg = KErrNotFound;
        iToWg = KErrNotFound;
        iFromScreen = KErrNotFound;
        iToScreen = KErrNotFound;
    	// iIdle->Start( TCallBack( FailedFullscreen, this ) );
    	return;
        }
        
    // TODO: This context switch is done because matrix menu uses opposite context numbers
    // from the screen saver, and we want to handle folder open the same way as application
    // open and folder close the same way as application close.
    // We may need to change this after we have tested the system and seen how it works
    // (if at all)
    // We may need to assign some unique numbers for the folder open and close to make the system work.
    
    
    // TODO: We do the switch with screen saver hoping it is the only one using reverse logic 
    
    if ( iAction == 1001 && iToUid.iUid == KScreensaverUid )
        {
        iAction = AknTransEffect::EApplicationExit;
        }
    
    if ( iAction == 1002 && iToUid.iUid == KScreensaverUid )
        {
        iAction = AknTransEffect::EApplicationStart;
        }
    
/*    
    if ( iAction == 1001 && iToUid.iUid == KAknApplicationShellViewId )
       {
       iAction = AknTransEffect::EApplicationStart;
//       iAction = 1002;
       }
   if ( iAction == 1002 && iToUid.iUid == KAknApplicationShellViewId  )
       {
//       iAction = AknTransEffect::EApplicationExit;
       }
*/       
       
    
    // Send the data to CAlfAppUI via bridge
    
    TAlfBridgerData bridgerData;
    
    // We must make a stream of the data as the length may vary.
    // At the moment we only send some numbers, but we should probably include
    // also the effect file name or something else to identify the effect 
    // that is going to be used
    
    TInt bufferSize = 11 * sizeof(TInt); //operation, TYPE, 2 wg ids, 2 app uids, flags and rect
    bufferSize += sizeof(TPtrC);
    bufferSize += resourceDir.Length() * 2;
    bufferSize += sizeof(TPtrC);
    bufferSize += fileName.Length() * 2;
    
    // I don't think we need this
    TInt index = 0;

    IncreaseHandle();

    iTransitionEndObserver->Cancel();
    iIdle->Cancel(); //cancel if running.
    iFinishFullScreen->Cancel();
    iFullScreenTimeout->Cancel();

    // The first stage should actually just show some wait dialog - it is waiting for the second
    // stage of the effect to start.
    void* bridgeBuffer = (void*) iWindowManager->Bridge()->AppendEffectsDataL( bufferSize, index ); 
    if ( bridgeBuffer )
        {
        RMemWriteStream stream( bridgeBuffer, bufferSize );
        // The writes should not leave if we have calculated our buffer length correctly.
        stream.WriteInt32L( MAlfGfxEffectPlugin::EBeginFullscreen );
        stream.WriteInt32L( iCurrHandle );
        stream.WriteInt32L( iType );
      	if ( iType == AknTransEffect::EParameterType && isExit )
      	    {
            stream.WriteInt32L( iToWg );
            stream.WriteInt32L( 0 );

            // AppUid
            stream.WriteInt32L( iToUid.iUid );
            stream.WriteInt32L( iFromUid.iUid );
                        
            stream.WriteInt32L( KErrNotFound ); //  was iToScreen, obsolete
            stream.WriteInt32L( KErrNotFound ); // was iToScreen, obsolete
       	    }
       	else if ( iType == AknTransEffect::EParameterType )
       	    {
            stream.WriteInt32L( iToWg );
            stream.WriteInt32L( iFromWg );

            // AppUid
            stream.WriteInt32L( iToUid.iUid );
            stream.WriteInt32L( iFromUid.iUid );
                        
            stream.WriteInt32L( KErrNotFound );  // was iToScreen, obsolete
            stream.WriteInt32L( KErrNotFound ); // was iToScreen, obsolete
            }
        else
            {
            stream.WriteInt32L( KErrNotFound); // was iFocusWg 
            stream.WriteInt32L( KErrNotFound); // was iFocusWg 
            }
        stream.WriteInt32L( iFlags );
        stream.WriteInt32L( iEffectRect.iTl.iX );
        stream.WriteInt32L( iEffectRect.iTl.iY );
        stream.WriteInt32L( iEffectRect.iBr.iX );
        stream.WriteInt32L( iEffectRect.iBr.iY );
        stream << resourceDir;
        stream << fileName;    
        stream.CommitL();
        bridgerData.Set( EAlfEffectFx, iAction, bufferSize, (TAny*) index );
        __ALFFXLOGSTRING(" <- CAlfServerDrawer::sending bridgedata");
        iFullScreenEndSent = EFalse;
        iFullScreenFxSent = ETrue;
        
        iWindowManager->PostIt( bridgerData );
        
        stream.Close();
        iTransitionEndObserver->StartObserving( TCallBack( TransitionFinished, this ), iCurrHandle );
        }
    
    // iFlags and iAction will contain some extra information that can be used to control the effect:
    
    // All of these actions may not produce effects, they are here for now for debugging.
    
    switch ( iAction )
        {
        case AknTransEffect::EApplicationActivate:
            __ALFFXLOGSTRING("EApplicationActivate - 1");
            break;
        case AknTransEffect::EApplicationStart:
            __ALFFXLOGSTRING("EApplicationStart - 3");
            break;
        case AknTransEffect::EEmbeddedApplicationStart:
            __ALFFXLOGSTRING("EEmbeddedApplicationStart - 4");
            break;
        case AknTransEffect::EApplicationExit:
            __ALFFXLOGSTRING("EApplicationExit - 5");
            break;
        case AknTransEffect::EApplicationStartRect:
            __ALFFXLOGSTRING("EApplicationStartRect - 6");
            break;
        case AknTransEffect::EApplicationStartSwitch:
            __ALFFXLOGSTRING("EApplicationStartSwitch - 7");
            break;
        case AknTransEffect::EApplicationStartSwitchRect:
            __ALFFXLOGSTRING("EApplicationStartSwitchRect - 8");
            break;
        case AknTransEffect::EEmbeddedApplicationExit:
            __ALFFXLOGSTRING("EEmbeddedApplicationExit - 10");
            break;
        case AknTransEffect::EAppStartComplete:
            __ALFFXLOGSTRING("EAppStartComplete - 11");
            break;
        case AknTransEffect::ELayoutSwitch:
            __ALFFXLOGSTRING("ELayoutSwitch - 12");
            break;
        case AknTransEffect::ELayoutSwitchExit:
            __ALFFXLOGSTRING("ELayoutSwitchExit - 13");
            break;
        case AknTransEffect::ELayoutSwitchStart:
            __ALFFXLOGSTRING("ELayoutSwitchStart - 14");
            break;
        case AknTransEffect::EAppSpesificEvent:
            __ALFFXLOGSTRING("EAppSpesificEvent - 1000");
            break;
        case AknTransEffect::EAppStartupBackground:
            __ALFFXLOGSTRING("EAppStartupBackground - 15");
            break;
        default:
            __ALFFXLOGSTRING1("%d", iAction);
            break;
        }

    // This is a precaution for cases where we never get end full screen
    // the delay is too long for normal cases, but because of the slowness of the emulater
    // the delay must be long enough so that it does not interfere with actual
    // endfullscreen signals.
    
    // It appears that folder open and close never send endfullscreen, so for them the effect
    // must be started as soon as we get beginfullscreen
    
    iFullScreenTimeout->Start( KAlfLongEffectTimeout, TCallBack( FullScreenTimeout, this ) );
    }
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
TInt CAlfServerDrawer::SendEndFullscreen()
    {
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendEndFullscreen");
    
    if ( iFullScreenEndSent )
        {
        __ALFFXLOGSTRING("CAlfServerDrawer::SendEndFullscreen END no need");
        return KErrNone;
        }
    iFullScreenEndSent = ETrue;
        
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendEndFullscreen");
    iTransitionEndObserver->Cancel();
    iFullScreenTimeout->Cancel();
    iFinishFullScreen->Cancel();
	iIdle->Cancel(); //cancel if running.
    /*
    TUint action = iAction;   
    if ( iType == AknTransEffect::EParameterAvkonInternal )
        {
        action = iOldAction;
        }
    */
    // TEMPORARY HACK
    // REMOVE AFTER APPSHELL HAS BEEN FIXED
    //iDoNotClearEffectRect = EFalse;
    
    // This is where the second part of the effect should start
    // The new window should already have something on the screen
    
    // Send the data to CAlfAppUI via bridge
    
    TAlfBridgerData bridgerData;
    
    // Get the wanted full screen effect from the policy handler
    
	TPtrC resourceDir;
	TPtrC fileName;

    // We must make a stream of the data as the length may vary.
    // At the moment we only send some numbers, but we should probably include
    // also the effect file name or something else to identify the effect 
    // that is going to be used
    
    TInt bufferSize = 11 * sizeof(TInt); // operation, type, 2 wg ids, 2 app uids, flags and rect
    bufferSize += sizeof(TPtrC);
    bufferSize += resourceDir.Length() * 2;
    bufferSize += sizeof(TPtrC);
    bufferSize += fileName.Length() * 2;
    
    TInt index = 0;

    // Send End fullscreen indication. Note that most of the data is invalid
    // and those should not be used in alfbridge. Data cannot be guaranteed
    // to be valid as we may receive multiple BeginFullscreen before EndFullscreen.
    
    void* bridgeBuffer = NULL;
    // This function cannot actually leave
    TRAP_IGNORE( bridgeBuffer = (void*) iWindowManager->Bridge()->AppendEffectsDataL( bufferSize, index ) ); 
    if ( bridgeBuffer )
        {
        RMemWriteStream stream( bridgeBuffer, bufferSize );
        // The writes should not leave if we have calculated our buffer length correctly.
        TRAP_IGNORE(
            {
            stream.WriteInt32L( MAlfGfxEffectPlugin::EEndFullscreen );
            stream.WriteInt32L( iCurrHandle );
            stream.WriteInt32L( iType );

            stream.WriteInt32L( iToWg );
            stream.WriteInt32L( iFromWg );

            // AppUid for the future. alfbridge can figure out the windog groups based on that
            stream.WriteInt32L( iToUid.iUid );
            stream.WriteInt32L( iFromUid.iUid );

            if ( iType == AknTransEffect::EParameterType )
                {
                stream.WriteInt32L( iToScreen );
                stream.WriteInt32L( iFromScreen );
                }
            /*else
                {
                //stream.WriteInt32L( iFocusWg );
                //stream.WriteInt32L( iFocusWg );
//              }*/
            stream.WriteInt32L( iFlags ); 
            stream.WriteInt32L( iEffectRect.iTl.iX );
            stream.WriteInt32L( iEffectRect.iTl.iY );
            stream.WriteInt32L( iEffectRect.iBr.iX );
            stream.WriteInt32L( iEffectRect.iBr.iY );
            stream << resourceDir;
            stream << fileName;    
            stream.CommitL();    
            });    
                
        bridgerData.Set( EAlfEffectFx, iAction, bufferSize, (TAny*) index );
        __ALFFXLOGSTRING(" <- CAlfServerDrawer::sending bridgedata");
        iWindowManager->PostIt( bridgerData );
        stream.Close();
        iTransitionEndObserver->StartObserving( TCallBack( TransitionFinished, this ), iCurrHandle  );
        }

    iFullScreenFinished = EFalse;
    if ( iAction == AknTransEffect::EApplicationExit /*||
        iAction == 1001*/  ) 
        {
		// no more events expected
        iFinishFullScreen->Start( KAlfShortEffectTimeout, TCallBack( FinishFullScreenTimeout, this ) );
        }
    else
        {
        iFinishFullScreen->Start( KAlfLongEffectTimeout, TCallBack( FinishFullScreenTimeout, this ) );
        }
    return KErrNone;
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//	
TInt CAlfServerDrawer::SendAbortFullscreen()
    {
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendAbortFullscreen");
    // The windows may close any time now because we are aborting
   
    if (!iFullScreenFxSent)
        {
        return KErrNone;
        }

    iTransitionEndObserver->Cancel();
    iIdle->Cancel(); //cancel if running.

    iFullScreenFxSent = EFalse;
    iFullScreenEndSent = ETrue;
    
    // Send the data to CAlfAppUI via bridge
    TAlfBridgerData bridgerData;
    
    // We must make a stream of the data as the length may vary.
    // This function only sends numbers, others send filenames, too.
    
    TInt bufferSize = 11 * sizeof(TInt32); // type, 2 wg ids, 2 app uids, flags and rect
    
    TInt index = 0;
    void* bridgeBuffer = NULL;
    // This function cannot actually leave
    TRAP_IGNORE( bridgeBuffer = (void*) iWindowManager->Bridge()->AppendEffectsDataL( bufferSize, index ) ); 
    if ( bridgeBuffer )
        {
        RMemWriteStream stream( bridgeBuffer, bufferSize );
        // The writes should not leave if we have calculated our buffer length correctly.
        TRAP_IGNORE(
            {
            stream.WriteInt32L( MAlfGfxEffectPlugin::EAbortFullscreen );
            stream.WriteInt32L( iCurrHandle );
            stream.WriteInt32L( iType );
          	//if ( iType == AknTransEffect::EParameterType )
          	    {
                stream.WriteInt32L( iToWg );
                stream.WriteInt32L( iFromWg );
                stream.WriteInt32L( iToUid.iUid );
                stream.WriteInt32L( iFromUid.iUid );
                                    
                stream.WriteInt32L( iToScreen );
                stream.WriteInt32L( iFromScreen );
                }
            /*else
                {
                stream.WriteInt32L( iFocusWg );
                stream.WriteInt32L( iFocusWg );
                }*/
            stream.WriteInt32L( iFlags ); 
            stream.CommitL();    
            }
            );
        bridgerData.Set( EAlfStopEffectFx, iAction, bufferSize, (TAny*) index );
        __ALFFXLOGSTRING(" <- CAlfServerDrawer::sending bridgedata");
        iWindowManager->PostIt( bridgerData );
        stream.Close();
        }
        
    iFullScreenFinished = ETrue;
    return KErrNone;
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TInt CAlfServerDrawer::SendBeginControlTransition()
    {
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendBeginControlTransition");
    TInt cachePriority = 0;
   	TInt wantedTime = 0;
	TInt minTime = 0;
	TPtrC resourceDir;
	TPtrC fileName;
	TPtrC actionString;
	
	TInt err = KErrNone;
	err = iPolicyHandler.GetControlKml( iControlUid, iControlAction, resourceDir,
	    fileName, actionString, cachePriority, wantedTime, minTime );
	    
	if ( err != KErrNone )
	    {
        return err;
	    }
	
	TBool fileExists = EFalse;
	TRAP_IGNORE(fileExists = FileExistsL( resourceDir, fileName ));
	
	if ( fileName.Length() == 0 || !fileExists)
	    {
	    return KErrNotFound;
	    }
	    
	// We must append the action string to the filename to be able to use different actions
	// for control entry and exit.
	
	TParse parse;
	parse.Set( fileName, NULL, NULL );
	
	TFileName actionFile;
	if ( actionString.Length() > 0 )
	    {
    	actionFile.Copy( parse.Name() );
    	actionFile.Append( _L("_") );
    	actionFile.Append( actionString );
    	actionFile.Append( parse.Ext() );
    	}
    else
        {
    	actionFile.Copy( fileName );
        }
        
    // Send the data to CAlfAppUI via bridge
    TAlfBridgerData bridgerData;
    
    TInt bufferSize = 9 * sizeof(TInt); // operation, action
    bufferSize += sizeof(TPtrC);
    bufferSize += resourceDir.Length() * 2;
    bufferSize += sizeof(TPtrC);
    bufferSize += fileName.Length() * 2;

    TInt index = 0;

    IncreaseHandle();
    iTransitionEndObserver->Cancel();
    iFinishFullScreen->Cancel();
    

    // control transitions are not supposed to have the phasing of full screen transitions,
    // we should be ready to go immediately.
    
    // However, if we are doing control exit, we should reserve the window in order
    // to keep it on screen while the effect lasts.
 
    void* bridgeBuffer = NULL;
    // This function cannot actually leave
    TRAP_IGNORE( bridgeBuffer = (void*) iWindowManager->Bridge()->AppendEffectsDataL( bufferSize, index ) ); 
    if ( bridgeBuffer )
        {
        RMemWriteStream stream( bridgeBuffer, bufferSize );
        // The writes should not leave if we have calculated our buffer length correctly.
        TRAP_IGNORE(
            {
            stream.WriteInt32L( MAlfGfxEffectPlugin::EBeginComponentTransition );
            stream.WriteInt32L( iCurrHandle );
            stream.WriteInt32L( iControlHandle ); // window handle
            stream.WriteInt32L( iControlWindowGroup ); // window group id
            stream.WriteInt32L( 0 ); // "screen number"; not used; save place for future
            // should send starting and ending points and possible other position/rectange
            // data, too.
            // Also, should send the action string if the effect parser can handle it
            stream << resourceDir;
            stream << actionFile;    
            stream.CommitL();
            });
        bridgerData.Set( EAlfControlEffectFx, iControlAction, bufferSize, (TAny*) index );
        __ALFFXLOGSTRING(" <- CAlfServerDrawer::sending bridgedata");
        iWindowManager->PostIt( bridgerData );
        stream.Close();
        iTransitionEndObserver->StartObserving( TCallBack( TransitionFinished, this ), iCurrHandle );
        }
	
    iFullScreenFinished = EFalse;
    iFinishFullScreen->Start( KAlfLongEffectTimeout, TCallBack( ControlTimeout, this ) );
	
    return KErrNone;
    }
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TInt CAlfServerDrawer::SendFinishControlTransition()
    {
    // We should now delete the effects from any controls that remain active.
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendFinishControlTransition");
    iTransitionEndObserver->Cancel();
	iIdle->Cancel(); //cancel if running.
	iFinishFullScreen->Cancel();
    
    // Send the data to CAlfAppUI via bridge
    TAlfBridgerData bridgerData;
    
    // We must make a stream of the data as the length may vary.
    // This function only sends numbers, others send filenames, too.
    
    TInt bufferSize = 9 * sizeof(TInt); // type, 2 wg ids, flags and rect
    TInt index = 0;

    void* bridgeBuffer = NULL;
    // This function cannot actually leave
    TRAP_IGNORE( bridgeBuffer = (void*) iWindowManager->Bridge()->AppendEffectsDataL( bufferSize, index ) ); 
    if ( bridgeBuffer )
        {
        RMemWriteStream stream( bridgeBuffer, bufferSize );
        // The writes should not leave if we have calculated our buffer length correctly.
        TRAP_IGNORE(
            {
            stream.WriteInt32L( MAlfGfxEffectPlugin::EAbortComponentTransition );
            stream.WriteInt32L( iCurrHandle );
            stream.WriteInt32L( 0 );
            stream.WriteInt32L( 0 );
            stream.WriteInt32L( 0 );
            stream.WriteInt32L( 0 ); 
            stream.CommitL();    
            });
        bridgerData.Set( EAlfStopEffectFx, iAction, bufferSize, (TAny*) index );
        __ALFFXLOGSTRING(" <- CAlfServerDrawer::sending bridgedata");
        iWindowManager->PostIt( bridgerData );
        stream.Close();
        }
        
    return KErrNone;
    }
	
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TInt CAlfServerDrawer::SendAbortControlTransition()
    {
    __ALFFXLOGSTRING(" <- CAlfServerDrawer::SendAbortControlTransition");
    iTransitionEndObserver->Cancel();
    // We should now delete the effects from any controls that remain active.
    return SendFinishControlTransition();
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TUid& CAlfServerDrawer::FromUid()
	{
	return iFromUid;
	}
	
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TUid& CAlfServerDrawer::ToUid()
	{
	return iToUid;
	}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TUint& CAlfServerDrawer::Action()
	{
	return iAction;
	}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TInt& CAlfServerDrawer::Flags()
	{
	return iFlags;	
	}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
void CAlfServerDrawer::IncreaseHandle()
	{
	iCurrHandle++;
	}
	
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
TInt CAlfServerDrawer::CurrentHandle()
	{
	return iCurrHandle;
	}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
void CAlfServerDrawer::StartEndChecker()
	{
	iController->StartEndChecker();
	}
	
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//		
void CAlfServerDrawer::CancelEndChecker()
	{
	iController->CancelEndChecker();
	}

TInt CAlfServerDrawer::FullScreenTimeout( TAny* aServerDrawer )
    {
    static_cast<CAlfServerDrawer*>(aServerDrawer)->HandleFullScreenTimeout();
    return KErrNone;
    }

void CAlfServerDrawer::HandleFullScreenTimeout()
    {
    if ( iFullScreenTimeout->iStatus.Int() != KErrCancel )
        {
        iFullScreenTimeout->Cancel();
        // If we don't get an EndFullScreen in a timely manner, 
        // we generate an EndFullScreen signal by ourselves
        EndFullscreen();
        }
    }

TInt CAlfServerDrawer::FinishFullScreenTimeout( TAny* aServerDrawer )
    {
    static_cast<CAlfServerDrawer*>(aServerDrawer)->HandleFinishFullScreenTimeout();
    return KErrNone;
    }

void CAlfServerDrawer::HandleFinishFullScreenTimeout()
    {
    iTransitionEndObserver->Cancel();
    iFullScreenTimeout->Cancel();
    // if we haven't got a pubsub trigger,
    // we must finish the transition by calling AlfBridge.
    // If we gor the pubsub trigger, AlfBridge has done its part,
    // and all we have to do is release the reserved windows.
    iController->FullscreenFinished( iCurrHandle );
    }

TInt CAlfServerDrawer::ControlTimeout( TAny* aServerDrawer )
    {
    static_cast<CAlfServerDrawer*>(aServerDrawer)->HandleControlTimeout();
    return KErrNone;
    }

void CAlfServerDrawer::HandleControlTimeout()
    {
    iTransitionEndObserver->Cancel();
    iFullScreenFinished = EFalse;
    iFullScreenTimeout->Cancel();
    iController->EndControlTransition( iCurrHandle );
    }

TInt CAlfServerDrawer::TransitionFinished( TAny* aServerDrawer )
    {
    static_cast<CAlfServerDrawer*>(aServerDrawer)->HandleTransitionFinished();
    return KErrNone;
    }

void CAlfServerDrawer::HandleTransitionFinished()
    {
    iFullScreenFinished = ETrue;
    iIdle->Cancel(); //cancel if running.
	iFinishFullScreen->Cancel();
    iFullScreenTimeout->Cancel();
    iController->FullscreenFinished( iCurrHandle );
    }


// ---------------------------------------------------------------------------
TBool CAlfServerDrawer::FileExistsL( TPtrC& aResourceDir, TPtrC& aFileName )
	{
	HBufC* fullName = HBufC::NewL( aResourceDir.Length() + aFileName.Length() );
	CleanupStack::PushL( fullName );
	fullName->Des().Copy( aResourceDir );
	fullName->Des().Append( aFileName );
	TBool found = EFalse;
	if (iFs.Handle() && BaflUtils::FileExists( iFs, *fullName ))
		{
        __ALFFXLOGSTRING1("CAlfServerDrawer::FileExists : %S", fullName);
        found = ETrue;
		}
	else
	    {
	
#ifdef __WINS__
       // Check for valid effect names during loading. DO NOT ENABLE IN BUILDS
       // __ASSERT_DEBUG(0,USER_INVARIANT());
#endif
	    }
	CleanupStack::PopAndDestroy(fullName);
	return found;
	}
