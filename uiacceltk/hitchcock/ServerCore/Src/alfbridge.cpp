/*
* Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies). 
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
#include <s32mem.h>
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
#include <uiacceltk/HuiImageBrush.h>
#include <uiacceltk/HuiRoster.h>

#ifdef ALF_USE_CANVAS
#include <uiacceltk/HuiCanvasVisual.h>
#endif

#include "alflogger.h"
#include "alf/alfappsrvsessionbase.h"
#include "alfsrvresourcemanager.h"
#include "alfsrvsettingshandler.h"
#include <uiacceltk/HuiTextureManager.h>
#include "alfsrvtexturemanager.h"

#include "alfstreamerserver.h"
#include "alfshareddisplaycoecontrol.h"
#include "alfbridge.h"
#include "alfstreamerconsts.h"
#include "alfscreen.h"
#include <akntranseffect.h>

#include "alfwindowmanager.h"
#include "alfwindowstructs.h"
#include <e32property.h>
#include "HuiFxEffect.h"
#include <akntransitionutils.h>
#include <alf/AlfTransEffectPlugin.h>
#include "alfwindowdata.h"
#include "huieffectable.h"
#include <akntranseffect.h>
#include "HuiRenderPlugin.h"
#include "huicanvasgc.h"
#include "huicanvasrenderbuffer.h"

#include "alfrenderstageutils.h" // for KAlfPSUidSynchronizer & KAlfPSKeySynchronizer

#ifdef HUI_DEBUG_TRACK_DRAWING
#include <alfcommanddebug.h>
#endif

#ifdef _ALF_FXLOGGING
#include <alfcommanddebug.h>
#endif

#ifdef SYMBIAN_BUILD_GCE
#include <bautils.h>
#endif

const TInt KVisualTransformationStepRotate    = 0;

const TReal32 KAlfVisualDefaultOpacity = 1.0f;
//const TReal32 KAlfVisualDefaultOpacity = 0.5f;

_LIT8(KAlfWindowGroupContainerControlTag, "WGROUP");

// This debug option prints window group order with __ALFLOGSTRING
//#define ALF_DEBUG_PRINT_WINDOWGROUP_ORDER

// This debug option shows window groups in a grid
//#define ALF_DEBUG_VISUALIZE_WINDOWGROUP_ORDER


const TInt KFadeAction = 6000;

const TInt KRosterFreezeEndTimeoutInMs = 400;

// Timer to send finish full screen effect
// ---------------------------------------------------------
// CAlfFinishTimer
// ---------------------------------------------------------
//
NONSHARABLE_CLASS( CAlfRosterFreezeEndTimer ):public CTimer
    {
    public:  // Constructors and destructor
        static CAlfRosterFreezeEndTimer* NewL( CAlfBridge& aBridge );
        virtual ~CAlfRosterFreezeEndTimer();

    public: // New functions
        void Start( TTimeIntervalMicroSeconds32 aPeriod );
        
    protected:  // Functions from base classes
        void DoCancel();

    private:
        CAlfRosterFreezeEndTimer( CAlfBridge& aBridge );
        void ConstructL();
        void RunL();
      
    private:    // Data
        CAlfBridge& iBridge;
                
    };


// ---------------------------------------------------------
// CAlfRosterFreezeEndTimer
// ---------------------------------------------------------
//
CAlfRosterFreezeEndTimer::CAlfRosterFreezeEndTimer( CAlfBridge& aBridge )
    :CTimer ( EPriorityStandard ),
    iBridge( aBridge )
    {   
    }

void CAlfRosterFreezeEndTimer::ConstructL()
    {
    CTimer::ConstructL();
    CActiveScheduler::Add( this );
    }

CAlfRosterFreezeEndTimer* CAlfRosterFreezeEndTimer::NewL( CAlfBridge& aBridge )
    {
    CAlfRosterFreezeEndTimer* self = new ( ELeave ) CAlfRosterFreezeEndTimer( aBridge );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop( self );
    return self;
    }

CAlfRosterFreezeEndTimer::~CAlfRosterFreezeEndTimer()
    {
    Cancel();        
    }

void CAlfRosterFreezeEndTimer::Start( TTimeIntervalMicroSeconds32 aPeriod )
    {
    if (!IsActive())
        {
        After( aPeriod );
        }
    }

void CAlfRosterFreezeEndTimer::RunL()
    {
    iBridge.iHuiEnv->Display(0).SetDirty();
    TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(EFalse));
    iBridge.SetVisualTreeVisibilityChanged(ETrue);    
    }

void CAlfRosterFreezeEndTimer::DoCancel()
    {
    CTimer::DoCancel();
    }

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectcoordinator
// ---------------------------------------------------------
//
NONSHARABLE_CLASS( CAlfLayoutSwitchEffectCoordinator ) : public CBase, public MAlfGfxEffectObserver
    {
    public:  // Constructors and destructor
        CAlfLayoutSwitchEffectCoordinator( CAlfBridge& aBridge );
        virtual ~CAlfLayoutSwitchEffectCoordinator();
    
    public: // MAlfGfxEffectObserver           
        void AlfGfxEffectEndCallBack( TInt aHandle );
    
    public:
        void BeginLayoutSwitch();
        void Cancel();
        
    private:
        AknTransEffect::TContext NextLayoutSwitchContext();
        void SetLayoutSwitchEffect(AknTransEffect::TContext aContext);
        TBool LayoutSwitchEffectsExist();
        
    private: // Data
        
        CAlfBridge& iBridge;
        AknTransEffect::TContext iLayoutSwitchEffectContext;
        TThreadPriority iOriginalPriority;
        CAlfRosterFreezeEndTimer* iRosterFreezeEndTimer;
    };

CAlfLayoutSwitchEffectCoordinator::CAlfLayoutSwitchEffectCoordinator( CAlfBridge& aBridge ) :
    iBridge( aBridge ),
    iLayoutSwitchEffectContext(AknTransEffect::ENone)    
    {
    RThread me = RThread();
    iOriginalPriority = me.Priority();    
    me.Close();
    }

CAlfLayoutSwitchEffectCoordinator::~CAlfLayoutSwitchEffectCoordinator()
    {   
    }

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectCoordinator::AlfGfxEffectEndCallBack
//
// This method is callback which gets called when layout 
// switch effect has ended.
// ---------------------------------------------------------
//
void CAlfLayoutSwitchEffectCoordinator::AlfGfxEffectEndCallBack( TInt aHandle )
    {
    //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::AlfGfxEffectEndCallBack"));
    if (iLayoutSwitchEffectContext == aHandle)
        {
        AknTransEffect::TContext nextContext = NextLayoutSwitchContext();

        // Unfreeze visible content. This reveals real roster content (in new orientation).
        if (nextContext == AknTransEffect::ELayoutSwitchExit)
            {
            #ifdef HUI_DEBUG_TRACK_DRAWING
            RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::AlfGfxEffectEndCallBack unfreezing roster content"));
            #endif
            iBridge.iHuiEnv->Display(0).SetDirty();
            TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(EFalse));
            iBridge.SetVisualTreeVisibilityChanged(ETrue);
            }
        
        // Set next effect
        SetLayoutSwitchEffect(nextContext);
        
        if (nextContext == AknTransEffect::ENone)
            {
            // Restore normal priority
            RThread me = RThread();
            me.SetPriority(iOriginalPriority);    
            me.Close();

            // Just in case refresh everything
            iBridge.iHuiEnv->Display(0).SetDirty();
            }        
        }
    else
        {
        //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::AlfGfxEffectEndCallBack - got different handle (normal, dont worry...) - %i"), aHandle);        
        }
    }

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectCoordinator::Cancel
// ---------------------------------------------------------
//
void CAlfLayoutSwitchEffectCoordinator::Cancel()
    {
    // Disable effect
    SetLayoutSwitchEffect( AknTransEffect::ENone );

    // Unfreeze visible content
    if ( iRosterFreezeEndTimer )
        {
		iRosterFreezeEndTimer->Cancel();
    	}

    iBridge.iHuiEnv->Display(0).SetDirty();
    TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(EFalse));
    iBridge.SetVisualTreeVisibilityChanged(ETrue);
    
    // Restore normal priority
    RThread me = RThread();
    me.SetPriority(iOriginalPriority);    
    me.Close();
	}

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch
//
// This method starts the layout switch effect procedure.
// ---------------------------------------------------------
//
void CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch()
    {
    // Hm. what to do if earlier is already in progress ?
    //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch"));
    if ( iBridge.iHuiEnv->MemoryLevel() <= EHuiMemoryLevelLowest )
        {
        // No effects in low memory mode
        return;
        }
    
    if (!iLayoutSwitchEffectContext)
        {
        TBool tfxOn = CAknTransitionUtils::TransitionsEnabled(AknTransEffect::ELayoutswitchTransitionsOff );
        TBool tfxExists = LayoutSwitchEffectsExist();
        if (tfxOn && tfxExists)
            {
            // Boost priority so that we are able to draw more frames for the effect
            RThread me = RThread();
            me.SetPriority(EPriorityAbsoluteHigh);    
            me.Close();
            
            // Freeze visual content
            //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch freezing roster content"));
            iBridge.iHuiEnv->Display(0).SetDirty();
            TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(ETrue));
            
            // Remove all other effects
            iBridge.HandleGfxStopEvent( EFalse );
            iBridge.RemoveAllTemporaryPresenterVisuals();
            
            // Set first layout switch effect 
            SetLayoutSwitchEffect(AknTransEffect::ELayoutSwitchStart);
            }
        else
            {
            if (!iRosterFreezeEndTimer)
                {
                TRAP_IGNORE(iRosterFreezeEndTimer = CAlfRosterFreezeEndTimer::NewL(iBridge));
                }
            
            if (iRosterFreezeEndTimer)
                {
                iBridge.iHuiEnv->Display(0).SetDirty();
                TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(ETrue));
                
                // Remove all other effects
                iBridge.HandleGfxStopEvent( EFalse );
                iBridge.RemoveAllTemporaryPresenterVisuals();

                // Set remove freeze timer
                iRosterFreezeEndTimer->Start(KRosterFreezeEndTimeoutInMs*1000); 
                }            
            //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch - tfx are set OFF -> I am not starting effect."));                        
            }
        }
    else
        {
        //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch - old effect exists - %i"), iLayoutSwitchEffectContext);
        }
    }

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectCoordinator::NextLayoutSwitchContext
//
// This method automatically selects the next context in the 
// layout switch procedure.
//
// Contextes change in the following order during layout switch:
//
// 1. AknTransEffect::ENone
// 2. AknTransEffect::ELayoutSwitchStart
// 3. AknTransEffect::ELayoutSwitchExit
// 4. AknTransEffect::ENone
//
// After new context is selected, appropriate effect is set 
// (and/or removed) from the roster.
//
// ---------------------------------------------------------
//
AknTransEffect::TContext CAlfLayoutSwitchEffectCoordinator::NextLayoutSwitchContext()
    {
    // Resolve next context based on current context
    AknTransEffect::TContext newContext = AknTransEffect::ENone;    
    switch (iLayoutSwitchEffectContext)
        {
        case AknTransEffect::ENone:
            {
            newContext = AknTransEffect::ELayoutSwitchStart;            
            break;
            }
        case AknTransEffect::ELayoutSwitchStart:
            {
            newContext = AknTransEffect::ELayoutSwitchExit;                    
            break;
            }
        case AknTransEffect::ELayoutSwitchExit: // fallthrough
        default:
            {
            newContext = AknTransEffect::ENone;            
            break;
            }              
        }

    //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::NextLayoutSwitchEffectL old ctx = %i, new ctx = %i"), iLayoutSwitchEffectContext, newContext);
    return newContext;
    }

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectCoordinator::SetLayoutSwitchEffectL
//
// This method sets correct effect based on the given 
// layout switch context.
//
// ---------------------------------------------------------
//
void CAlfLayoutSwitchEffectCoordinator::SetLayoutSwitchEffect(AknTransEffect::TContext aContext)
    {
    MHuiEffectable* effectable = iBridge.iHuiEnv->Display(0).Roster().Effectable();
    CHuiFxEffect* effect = NULL;
    CHuiFxEngine* engine = iBridge.iHuiEnv->EffectsEngine();
    
    if (!effectable || !engine)
        {
        return;
        }    
            
    // Update current context
    iLayoutSwitchEffectContext = aContext;           
    
    if (aContext == AknTransEffect::ENone)
        {
        // Just remove effect
        //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::NextLayoutSwitchEffectL - removing effect"));
        effectable->EffectSetEffect(NULL); // This calls AlfGfxEffectEndCallBack         
        }
    else
        {    
        // Load correct effect
        for ( TInt i = 0; i<iBridge.iAlfRegisteredEffects.Count(); i++ )
            {             
            if ( iBridge.iAlfRegisteredEffects[i].iAction == aContext)
                {
                //RDebug::Print(_L("CAlfLayoutSwitchEffectCoordinator::SetLayoutSwitchEffectL - loading effect"));
                TRAP_IGNORE(engine->LoadEffectL(*iBridge.iAlfRegisteredEffects[i].iEffectFile, effect, effectable, NULL, this, iLayoutSwitchEffectContext, 0 ) );                    
                break;
                }
            }
        }    
    }

TBool CAlfLayoutSwitchEffectCoordinator::LayoutSwitchEffectsExist()
    {
    TBool appearExists = EFalse;
    TBool disAppearExists = EFalse;
    
    for ( TInt i = 0; i<iBridge.iAlfRegisteredEffects.Count(); i++ )
        {             
        if ( iBridge.iAlfRegisteredEffects[i].iAction == AknTransEffect::ELayoutSwitchStart)
            {
            disAppearExists = ETrue;
            break;
            }
        else if ( iBridge.iAlfRegisteredEffects[i].iAction == AknTransEffect::ELayoutSwitchExit)
            {
            appearExists = ETrue;
            break;
            }
        }
    
    return (appearExists || disAppearExists);    
    }

// Timer to send finish full screen effect
// ---------------------------------------------------------
// CAlfFinishTimer
// ---------------------------------------------------------
//
NONSHARABLE_CLASS( CAlfEffectEndTimer ):public CTimer
    {
    public:  // Constructors and destructor
        static CAlfEffectEndTimer* NewL( CAlfBridge& aBridge );
        virtual ~CAlfEffectEndTimer();

    public: // New functions
        void Start( TTimeIntervalMicroSeconds32 aPeriod, TInt aHandle );
        
    protected:  // Functions from base classes
        void DoCancel();

    private:
        CAlfEffectEndTimer( CAlfBridge& aBridge );
        void ConstructL();
        void RunL();
      
    private:    // Data
        CAlfBridge& iBridge;
        TInt iHandle;
                
    };


// ---------------------------------------------------------
// CAlfFinishTimer
// ---------------------------------------------------------
//
CAlfEffectEndTimer::CAlfEffectEndTimer( CAlfBridge& aBridge )
    :CTimer(EPriorityHigh), 
	iBridge(aBridge)
    {   
    }

void CAlfEffectEndTimer::ConstructL()
    {
    CTimer::ConstructL();
    CActiveScheduler::Add( this );
    }

CAlfEffectEndTimer* CAlfEffectEndTimer::NewL( CAlfBridge& aBridge )
    {
    CAlfEffectEndTimer* self = new ( ELeave ) CAlfEffectEndTimer( aBridge );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop( self );
    return self;
    }

CAlfEffectEndTimer::~CAlfEffectEndTimer()
    {
    Cancel();        
    }

void CAlfEffectEndTimer::Start( TTimeIntervalMicroSeconds32 aPeriod, TInt aHandle )
    {
    iHandle = aHandle;
    After( aPeriod );
    }

void CAlfEffectEndTimer::RunL()
    {
    //
    // timer completes and control is returned to caller
    //
    iBridge.TransitionFinishedHandlerL( iHandle );
    // We don't become active unless we are explicitly restarted
    }

void CAlfEffectEndTimer::DoCancel()
    {
    CTimer::DoCancel();
    }


// ======== MEMBER FUNCTIONS ========

// ======== MEMBER FUNCTIONS ========

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
CAlfBridge* CAlfBridge::NewL( CAlfStreamerBridge** aHost, CHuiEnv* aEnv )
    {
    CAlfBridge* self = new (ELeave) CAlfBridge( aHost );
    CleanupStack::PushL( self );
    self->ConstructL( aEnv );
    CleanupStack::Pop( self );
    return self;
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ProvideBitmapL(TInt /*aId*/, CFbsBitmap*& aBitmap, CFbsBitmap*& aMaskBitmap)
    {
    aBitmap = iHack;
    aMaskBitmap = iDummyMask;
    };


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
CAlfBridge::CAlfBridge(CAlfStreamerBridge** aHost)
    : iHost(aHost), iCurrentMemoryLevel(EHuiMemoryLevelNormal)
	{
	}
    

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
CAlfBridge::~CAlfBridge()
	{
	delete iFadeEffectFile;
	iWindowHashArray.Close();
	for( TInt i = 0; i< iAlfRegisteredEffects.Count(); i++ )
	    {
	    delete iAlfRegisteredEffects[i].iEffectFile;
	    }
	iAlfRegisteredEffects.Close();
    delete iEffectEndTimer;
    iDeadControlGroups.Close();
    iEffectWindowGroups.Close();
    delete iFullScreenEffectData;

    if (iActivated)
        {
        iBridgerClient.Close();        
        }

#ifdef HUI_DEBUG_TRACK_DRAWING
    delete iCommandDebug;
#endif
    delete iCursorTimer;
    delete iLayoutSwitchEffectCoordinator;
	}
    

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ConstructL(CHuiEnv* aEnv)
    {
    iHuiEnv = aEnv;

#ifdef SYMBIAN_BUILD_GCE
    iPrintFPS = EFalse;
#ifndef __WINSCW__
    _LIT(KRDSupport, "c:\\resource\\errrd" );
    RFs& fs = CHuiStatic::FsSession();
    if (fs.Handle() && BaflUtils::FileExists( fs, KRDSupport ))
        {
        iPrintFPS = ETrue;
        }
#endif
#endif //SYMBIAN_BUILD_GCE
    // create the key for indication transition ends
    // No access restrictions for starters
    TInt err = RProperty::Define( KPSAlfDomain, KAlfTransitionStatus,
        RProperty::EInt );
    if (!err)
        {
        // Initialize to no transition    
        RProperty::Set( KPSAlfDomain, KAlfTransitionStatus, 0 );
        }

    iEffectEndTimer = CAlfEffectEndTimer::NewL( *this );
    iWindowHashArray.ReserveL( 500 );
    iAlfRegisteredEffects.ReserveL(10);
    
#ifdef HUI_DEBUG_TRACK_DRAWING
    iCommandDebug = CAlfCommandDebug::NewL();
#endif
    
    iLayoutSwitchEffectCoordinator = new (ELeave) CAlfLayoutSwitchEffectCoordinator(*this);
    iAlfSecureId = RThread().SecureId();
    RegisterFadeEffectL();
    }

// ---------------------------------------------------------------------------
//  RegisterFadeEffectL
//
//  Note, If theme DOES NOT register its own fade effect, another hardcoded fade 
//  effect will be used instead. For example, if theme effects are turned off, 
//  a fade that does not belong to the theme may be in use.
// ---------------------------------------------------------------------------
void CAlfBridge::RegisterFadeEffectL()
    {
    // TODO: RND, REMOVE MMC DRIVE-F, WHEN NOT REQUIRED FOR TESTING
    _LIT(KDrivePrefence,"FZC"); 
    // Force register fade effect. Try first MMC, then ROM.
    CHuiFxEngine* engine = iHuiEnv->EffectsEngine();
    RFs& fs = CHuiStatic::FsSession();
    if (fs.Handle() && engine)
        {
        _LIT(KFadeEffectPath, ":\\resource\\effects\\fade_effect.fxml");
        TBufC<4> drives(KDrivePrefence);
        HBufC* effectFullName = HBufC::NewLC(KFadeEffectPath().Length() + 1);
        
        for(TInt i=0; i< drives.Length(); i++)
            {
            effectFullName->Des().Copy(drives.Mid(i,1));
            effectFullName->Des().Append(KFadeEffectPath);
    
            if (BaflUtils::FileExists( fs, *effectFullName ))
                {
                DoRegisterEffectL(*effectFullName, KFadeAction);
                break;
                }
            }
        CleanupStack::PopAndDestroy(effectFullName);
        DoSetCachedFadeEffectL();
        }
    }

// ---------------------------------------------------------------------------
// DoSetCachedFadeEffectL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::DoSetCachedFadeEffectL()
    {
    for (TInt i = 0; i < iAlfRegisteredEffects.Count(); i++)
        {
        //KFadeAction = 6000, indicating the action corroposnds to fading
        if (iAlfRegisteredEffects[i].iAction == KFadeAction)
            {
            delete iFadeEffectFile;
            iFadeEffectFile = NULL;
            iFadeEffectFile = iAlfRegisteredEffects[i].iEffectFile->AllocL();
            __ALFLOGSTRING1( ">> Setting fade effect file  %S", iFadeEffectFile );
            break;
            }
        }
    }

// ---------------------------------------------------------------------------
// AddNewScreenL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::AddNewScreenL(CAlfSharedDisplayCoeControl* aSharedCoeControl)
    {
    TInt screenNumber = iAlfScreens.Count(); // \todo this might not be the same as real WServ screen number
    
    // We do not yet support drawing winGC draw commands to other than primary screen.
    // As fully functional and tested implementation is not there, better to panic here.
    if (screenNumber!=0)
        {
        __ALFLOGSTRING("CAlfBridge::AddNewScreenL. Fatal error! Only screen 0 is supported in Alf server!");
        User::Invariant();
        }
         
    CAlfScreen* screen = new(ELeave) CAlfScreen(); 
    CleanupStack::PushL(screen);
    screen->ConstructL(screenNumber, *this, *iHuiEnv, aSharedCoeControl);
    iAlfScreens.AppendL( screen );
    CleanupStack::Pop(screen);

	ShowControlGroupL(screen->iDisplay->Roster(), *(screen->iFloatingSpriteControlGroup), KHuiRosterShowAtTop, screenNumber); 
	ShowControlGroupL(screen->iDisplay->Roster(), *(screen->iFullscreenEffectControlGroup), KHuiRosterShowAtTop, screenNumber); 
    
	screen->iFloatingSpriteControlGroup->SetAcceptInput(EFalse);
	screen->iFullscreenEffectControlGroup->SetAcceptInput(EFalse);
	
	if ( screen->iFpsControlGroup )
	    {
	    ShowControlGroupL(screen->iDisplay->Roster(), *(screen->iFpsControlGroup), KHuiRosterShowAtTop, screenNumber); 
	    screen->iFpsControlGroup->SetAcceptInput(EFalse);
	    }
    }

//------------------------------------------------------------------------------
// Dumdidumdidum..
//------------------------------------------------------------------------------
void CAlfBridge::AddNewScreenFromWindowL(RWindow* aWindow)
    {
    TInt screenNumber = iAlfScreens.Count(); // \todo this might not be the same as real WServ screen number
         
    CAlfScreen* screen = new(ELeave) CAlfScreen(); 
    CleanupStack::PushL(screen);
    screen->ConstructL(screenNumber, *this, *iHuiEnv, aWindow);
    iAlfScreens.AppendL( screen );
    CleanupStack::Pop(screen);

	ShowControlGroupL(screen->iDisplay->Roster(), *(screen->iFloatingSpriteControlGroup), KHuiRosterShowAtTop, screenNumber); 
	ShowControlGroupL(screen->iDisplay->Roster(), *(screen->iFullscreenEffectControlGroup), KHuiRosterShowAtTop, screenNumber); 
    
    screen->iFloatingSpriteControlGroup->SetAcceptInput(EFalse);
    screen->iFullscreenEffectControlGroup->SetAcceptInput(EFalse);
    
    if ( screen->iFpsControlGroup )
	    {
	    ShowControlGroupL(screen->iDisplay->Roster(), *(screen->iFpsControlGroup), KHuiRosterShowAtTop, screenNumber); 
	    screen->iFpsControlGroup->SetAcceptInput(EFalse);
	    }
    }



// ---------------------------------------------------------------------------
// AddVisual
// ---------------------------------------------------------------------------
// 
void CAlfBridge::AddVisual( 
        TInt aWindowNodeId, 
        TInt aClientSideId, 
        TInt aClientSideGroupId,
        CHuiCanvasVisual* aVisual )
    {
    __ALFFXLOGSTRING1("CAlfBridge::AddVisual 0x%x", aWindowNodeId);
    THashVisualStruct visualStruct( aVisual, aClientSideId, aClientSideGroupId);
    iWindowHashArray.Insert( aWindowNodeId, visualStruct );
    iPreviouslySearchedVisualId = aWindowNodeId;
    iPreviouslySearchedVisual = aVisual;
    }

// ---------------------------------------------------------------------------
// RemoveVisual
// ---------------------------------------------------------------------------
// 
void CAlfBridge::RemoveVisual( TInt aWindowNodeId )
    {
    __ALFFXLOGSTRING1("CAlfBridge::RemoveVisual 0x%x", aWindowNodeId);
    iWindowHashArray.Remove( aWindowNodeId );
    iPreviouslySearchedVisualId = 0;
    }
    
// ---------------------------------------------------------------------------
// FindVisual
// ---------------------------------------------------------------------------
// 
CHuiCanvasVisual* CAlfBridge::FindVisual(TInt aWindowNodeId )
    {
    if ( iPreviouslySearchedVisualId == aWindowNodeId )
        {
        return iPreviouslySearchedVisual;
        }
    
    THashVisualStruct* visualStruct = iWindowHashArray.Find( aWindowNodeId );
    if ( visualStruct )
        {
        iPreviouslySearchedVisualId = aWindowNodeId;
        iPreviouslySearchedVisual = visualStruct->iVisual;
        return iPreviouslySearchedVisual; 
        }
    __ALFFXLOGSTRING1("CAlfBridge::FindVisual - Visual 0x%x not found", aWindowNodeId);
    return NULL;
    }

// ---------------------------------------------------------------------------
// FindVisualByClientSideId
// ---------------------------------------------------------------------------
// 
CHuiCanvasVisual* CAlfBridge::FindVisualByClientSideIds(
    TUint32 aClientSideId, 
	TUint32 aClientSideGroupId )
    {
    THashMapIter<TUint32, THashVisualStruct> iter(iWindowHashArray);
    THashVisualStruct const * node = 0;
    do
        {
        node = iter.NextValue();
        if (node 
                && (*node).iClientSideId==aClientSideId
                && (*node).iClientSideGroupId==aClientSideGroupId )
            {
            return (*node).iVisual;
            }
        }
    while(node);
	return NULL;
    }
	
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
CHuiControlGroup* CAlfBridge::FindControlGroup(TInt aWindowGroupNodeId, TInt aScreenNumber )
    {
    for (TInt i=0; i<iAlfScreens[aScreenNumber]->iControlGroups.Count();i++)
        {
        if (iAlfScreens[aScreenNumber]->iControlGroups[i].iWindowGroupNodeId == aWindowGroupNodeId)
            {
            return iAlfScreens[aScreenNumber]->iControlGroups[i].iControlGroup;
            }
        }        
    return NULL;       
    }

// ---------------------------------------------------------------------------
// FindClientWindowGroupId
// ---------------------------------------------------------------------------
//
TInt CAlfBridge::FindClientWindowGroupId( TInt aScreenNumber, CHuiControlGroup& aControlGroup  )
    {
    for (TInt i=0; i<iAlfScreens[aScreenNumber]->iControlGroups.Count();i++)
        {
        if( iAlfScreens[aScreenNumber]->iControlGroups[i].iControlGroup == &aControlGroup )
            {
            return iAlfScreens[aScreenNumber]->iControlGroups[i].iClientWindowGroupId;
            }
        }
    return KErrNotFound;
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
CHuiControlGroup* CAlfBridge::FindControlGroupByWindowGroupId( TInt aWindowGroupId, TInt& aScreenNumber, TAlfControlGroupEntry** aAlfGroup )
    {
    TInt firstWin = aScreenNumber;
    TInt lastWin = aScreenNumber;
    if ( aScreenNumber == KErrNotFound )
        {
        firstWin = 0;
        lastWin = iAlfScreens.Count()-1;
        }
    
    for ( TInt j = firstWin; j <= lastWin; j++ )
        {
        for ( TInt i = 0; i < iAlfScreens[j]->iControlGroups.Count(); i++ )
            {
            if ( iAlfScreens[j]->iControlGroups[i].iClientWindowGroupId == aWindowGroupId )
                {
                aScreenNumber = j;
                if ( aAlfGroup != NULL )
                    {
                    *aAlfGroup = &iAlfScreens[j]->iControlGroups[i];
                    }
                return iAlfScreens[j]->iControlGroups[i].iControlGroup;
                }
            }        
        }
    return NULL;       
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//
CHuiControlGroup* CAlfBridge::FindControlGroupByAppId( TInt aAppId )
    {
    for ( TInt i = 0; i < iAlfScreens[0]->iControlGroups.Count(); i++ )
        {
        if ( iAlfScreens[0]->iControlGroups[i].iSecureId == aAppId )
            {
            return iAlfScreens[0]->iControlGroups[i].iControlGroup;
            }
        }        
    return NULL;       
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
//

void CAlfBridge::ListFamilyTreeL( RPointerArray<CHuiLayout>& aArray, const CHuiLayout* aLayout )
    {
    if (aLayout->Count())
        {
        aArray.Append(aLayout);
        
        for(TInt i = 0; i< aLayout->Count(); i++)
            {
            ListFamilyTreeL(aArray, (CHuiLayout*)&aLayout->Visual(i));
            }
        }
    else
        {
        aArray.Append(aLayout);
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::DeleteControlGroupL(TInt aWindowGroupNodeId, TInt aScreenNumber )
    {
    for (TInt i=0; i<iAlfScreens[aScreenNumber]->iControlGroups.Count();i++)
        {
        if (iAlfScreens[aScreenNumber]->iControlGroups[i].iWindowGroupNodeId == aWindowGroupNodeId)
            {
            if (iAlfScreens[aScreenNumber]->iDisplay)
                {
                CHuiControl& control = iAlfScreens[aScreenNumber]->iControlGroups[i].iControlGroup->Control(0);
                CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
                // wserv has notifed that this control group and its layout should be destroyed. However, we might be
                // have effect on the layout itself or layout is being drawn as external content. This indicates that
                // we should not delete the control group at this point, but add it to iDeadControlGroup list, which 
                // is cleared when effect has finished.
                RPointerArray<CHuiLayout> familyTree;
                ListFamilyTreeL(familyTree, layout); // recursively dig the family tree
                TBool anyVisualHasEffect(EFalse);
                TInt familyIndex(0);
                TInt familySize = familyTree.Count();
                while(familyIndex < familySize && !anyVisualHasEffect)
                    {
                    anyVisualHasEffect = HasActiveEffect(familyTree[familyIndex++]);
                    }
                
                if (anyVisualHasEffect)
                    {
                    __ALFFXLOGSTRING1("Layout 0x%x has external content", layout);
                    // EHuiVisualFlagShouldDestroy destroy flag should have come for the windows in this layout already
                    layout->SetFlags(EHuiVisualFlagShouldDestroy);
                    // move this layout to effect control group, where it can still be shown. this control group may be deleted.
                    CHuiControl& control = iAlfScreens[aScreenNumber]->iControlGroups[i].iControlGroup->Control(0);
                    CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
                    
                    for(TInt familyIndex = 0; familyIndex < familyTree.Count();familyIndex++)
                        {
                        control.Remove(familyTree[familyIndex]); // remove ownership from original group
                        }
                        
                    control.Remove(layout); // remove ownership from original group
                    // move visuals to safe place. the original group must be destroyed.
                    __ALFFXLOGSTRING1("MOVING 0x%x to effect group", layout);
                    CHuiControl& effectControlGroup = iAlfScreens[0]->iFullscreenEffectControlGroup->Control(0);
                    CHuiLayout* effectControlGroupLayout = (CHuiLayout*) &effectControlGroup.Visual(0);
                    // Transfers ownership of visuals. 
                    effectControlGroup.AppendL(layout, effectControlGroupLayout); // this will remove it from the previous layout
                    layout->SetOwner(effectControlGroup);
                    
                    for(TInt familyIndex = 0; familyIndex < familyTree.Count();familyIndex++)
                        {
                        familyTree[familyIndex]->SetOwner(effectControlGroup);
                        }
                    }
                else
                    {
                    // check once more, that the windows in this group are not having effects. 
                    // the layout is not have effect, but some child window might.
                    // in this case, the child window effects WILL BE REMOVED.
                     for(TInt familyIndex = 0; familyIndex < familyTree.Count();familyIndex++)
                         {
                         RemoveTemporaryPresenterVisual(familyTree[familyIndex]);
                         }
                    }
                familyTree.Close();
                iAlfScreens[aScreenNumber]->iDisplay->Roster().Hide(*iAlfScreens[aScreenNumber]->iControlGroups[i].iControlGroup);
                __ALFFXLOGSTRING("CAlfBridge::DeleteControlGroupL - Deleting group");
                iAlfScreens[aScreenNumber]->iControlGroups.Remove(i);
                iHuiEnv->DeleteControlGroup(aWindowGroupNodeId);
                __ALFFXLOGSTRING("CAlfBridge::DeleteControlGroupL - Deleting group done");
                }
            break;
            }
        }        
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
CHuiControlGroup& CAlfBridge::CreateControlGroupL(
            TInt aWindowGroupNodeId, 
            TInt aClientWindowGroupId,
            TInt aSecureId,
            TInt aScreenNumber )
    {
    CHuiControlGroup* group = FindControlGroup(aWindowGroupNodeId,aScreenNumber);
    if (!group)
        {
        group = &iHuiEnv->NewControlGroupL(aWindowGroupNodeId); 
        CleanupStack::PushL(group);
        CHuiControl*  cntrl = new (ELeave) CHuiControl(*iHuiEnv);
        CleanupStack::PushL(cntrl);
        CHuiLayout* layout = NULL;
        
        cntrl->ConstructL();
        group->AppendL(cntrl);
        CleanupStack::Pop(cntrl);
        cntrl->SetRole(EAlfWindowGroupContainer);

        layout = CHuiCanvasVisual::AddNewL(*cntrl);
        layout->SetTagL(KAlfWindowGroupContainerControlTag);
        layout->ClearFlag(EHuiVisualFlagClipping); // No need to clip, should be faster without clipping 
        // IsVisualOpaque should return true if there is no effect. 
        // So that's why opaque flag is set to this layout.
        layout->SetFlag(EHuiVisualFlagOpaqueHint); 
        
        TAlfControlGroupEntry entry;
        entry.iControlGroup = group;
        entry.iWindowGroupNodeId = aWindowGroupNodeId;
        entry.iClientWindowGroupId = aClientWindowGroupId;  
        entry.iSecureId = aSecureId;
        // we have received start effect for this group, but the group did not exist in alf universe at the time. hide the group.
        if (iFullScreenEffectData
                && iFullScreenEffectData->iWaitingWindowGroup
                && iFullScreenEffectData->iToAppId == aSecureId)
            {
            CHuiControlGroup* fromGroup = NULL;
            CHuiLayout* fromLayout = NULL; 
            fromGroup = FindControlGroupByAppId(iFullScreenEffectData->iFromAppId);
            if (fromGroup)
                {
                CHuiControl& control2 = fromGroup->Control(0);
                fromLayout = (CHuiLayout*)&control2.Visual(0);
                }
            
            
            // First HandleGfxEvent, then clear iWaitingWindowGroup.
            TBool failed = HandleGfxEventL( *iFullScreenEffectData, layout, fromLayout );
            if ( iFullScreenEffectData )
                {
                iFullScreenEffectData->iWaitingWindowGroup = EFalse;
                }
            if ( failed )
                {
                // Effect failed, reset state
                HandleGfxStopEvent( EFalse ); // destroys iFullScreenEffectData
                }
            }     
        entry.iScreenNumber = aScreenNumber;
//        entry.iRole = EAlfWindowGroupContainer;

        iAlfScreens[aScreenNumber]->iControlGroups.Append(entry);
        CleanupStack::Pop(group);                

        if (iAlfScreens[aScreenNumber]->iDisplay)
            ShowControlGroupL(iAlfScreens[aScreenNumber]->iDisplay->Roster(), *group, KHuiRosterShowAtTop, aScreenNumber); 
        }
    

    return *group;       
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ShowControlGroupL(CHuiRoster& aRoster, CHuiControlGroup& aGroup, TInt aWhere, TInt aScreenNumber )
    {        
    CAlfScreen* screen = iAlfScreens[aScreenNumber];

#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
        DebugPrintControlGroupOrder(*screen, aRoster, aGroup);
#endif

#ifdef ALF_DEBUG_VISUALIZE_WINDOWGROUP_ORDER
    if (!aGroup.IsTransformed())
        {
        aGroup.EnableTransformationL();
        aGroup.Transformation().Translate(0,0);                    
        aGroup.Transformation().Scale(0.3,0.3);                    
        }
#endif

    TInt last = aRoster.Count() - 1;
    
    
// when an application exits, it must be shown on top util the effect has run its course.
// But this tends to mess up the order of other groups, and application menu softkeys will
// disappear.
    if ( aGroup.Control(0).Visual(0).Effect() )
        {
        if ( aGroup.Control(0).Role() != EAlfWindowGroupContainer )
            {
            // The case where the application control group is deleted by window server
            // has been solved by deleting the tag when window server wants to delete
            // the group. Window server no longer has it, but we keep it alive for a while
            // to show the effect. The group will be deleted when the effect ends.
            aWhere = aRoster.Count() - screen->FixedControlGroupCount();
            }
        }

    if (aGroup.Control(0).Role() == EAlfWindowGroupContainer)      
        {
        // Window group control groups
        ShowWindowGroupControlGroupL(aRoster, aGroup, aWhere, aScreenNumber);
        aGroup.SetAcceptInput(EFalse);
        }
    else if (aGroup.Control(0).Role() == EAlfSessionContainer)      
        {
        // ALF application control groups    
        ShowSessionContainerControlGroupL(aRoster, aGroup, aWhere, aScreenNumber);
        }
    else
        {
        aRoster.ShowL(aGroup, aWhere);
        aGroup.SetAcceptInput(EFalse);
        }                                    

#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER        
        DebugPrintControlGroupOrder(*screen, aRoster, aGroup);
#endif

#ifdef ALF_DEBUG_VISUALIZE_WINDOWGROUP_ORDER
        VisualizeControlGroupOrderL(*screen, aRoster, aGroup);
#endif
    
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ShowSessionContainerControlGroupL(CHuiRoster& aRoster, CHuiControlGroup& aGroup, TInt aWhere, TInt aScreenNumber )
    {
    TInt last = aRoster.Count() - 1;

    CAlfScreen* screen = iAlfScreens[aScreenNumber];

    if (aWhere == KHuiRosterShowAtBottom)
        {
        // Most bottom one of alf control groups
        aRoster.ShowL(aGroup, FirstAlfControlGroupIndex(aScreenNumber));    
        }
    else if (aWhere == KHuiRosterShowAtTop)
        {
        // Most top one of alf control groups
        TInt newIndex = LastAlfControlGroupIndex(aScreenNumber);
    
        // check if the aGroup is already in a roster
        for (TInt j=0; j<newIndex;j++)
                { 
                if( &aRoster.ControlGroup(j) == &aGroup )
                    {
                    // adjust position a bit because this is in fact "move" operation
                    // move would move alf event window and place this control group
                    // on top of it if we don't do this adjusment
                    newIndex--;    
                    break;
                    }
                }               
        
        aRoster.ShowL(aGroup, newIndex);    
        }
    else
        {
        TInt index = 0; // Index for ALF group control groups
        TBool added = EFalse;
        TBool move = EFalse; // indicates that controlgroup is already in the roster somewhere below the new index.
        for (TInt i=FirstAlfControlGroupIndex(aScreenNumber); i<last; i++)
            {
            if (index == aWhere)
                {
                if( move )
                    {
                    // adjust the new index because of ShowL call
                    // will first remove the controlgroup from original position
                    index--; 
                    }
                aRoster.ShowL(aGroup, i);        
                added = ETrue;
                break;
                }

            if( &aRoster.ControlGroup(i) == &aGroup )
                {
                move = ETrue;
                }
            
            if (aRoster.ControlGroup(i).Control(0).Role() == EAlfSessionContainer)
                {
                index++;                                                
                }                    
            }
        
        // Too large index was given, just add it to topmost    
        if (!added)
            {
            // Topmost alf group
            ShowSessionContainerControlGroupL( aRoster, aGroup, KHuiRosterShowAtTop, aScreenNumber );
            }        
        }                        
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ShowWindowGroupControlGroupL(CHuiRoster& aRoster, CHuiControlGroup& aGroup, TInt aWhere, TInt aScreenNumber )
    {
    CAlfScreen* screen = iAlfScreens[aScreenNumber];

    if (aWhere == KHuiRosterShowAtBottom)
        {
        // Most bottom one of any control groups
        aRoster.ShowL(aGroup, KHuiRosterShowAtBottom);    
        }
    else if (aWhere == KHuiRosterShowAtTop)
        {
        // Topmost
        aRoster.ShowL(aGroup, aRoster.Count() - screen->FixedControlGroupCount());
        }
    else
        {
        TInt index = 0; // Index for Window group control groups
        TBool added = EFalse;
        for (TInt i=0; i<aRoster.Count() - screen->FixedControlGroupCount(); i++)
            {
            if (index == aWhere)
                {
                aRoster.ShowL(aGroup, i);        
                added = ETrue;
                break;
                }

            if (aRoster.ControlGroup(i).Control(0).Role() == EAlfWindowGroupContainer &&
                &aRoster.ControlGroup(i) != &aGroup)
                {
                index++;                                                
                }                    
            }
        
        // Too large index was given, just add it to topmost    
        if (!added)
            {
            // Topmost
            for (TInt i=aRoster.Count() - screen->FixedControlGroupCount(); i >= 0; i--)
                {
                if (aRoster.ControlGroup(i).Control(0).Role() == EAlfWindowGroupContainer)
                    {
                    aRoster.ShowL(aGroup, i); 
                    break;
                    }                    
                }                                                             
            }
        }                                            
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::SetAlfWindowGroupId(TInt aAlfWindowGroupId)
    {
    iAlfWindowGroupId = aAlfWindowGroupId;        
    // check if hithcock window group was already there
    TInt secureId = RThread().SecureId(); 
    if (iAlfScreens.Count())
        {
        for ( TInt i = 0; i < iAlfScreens[0]->iControlGroups.Count(); i++ )
            {
            if ( iAlfScreens[0]->iControlGroups[i].iSecureId == secureId && 
                 iAlfScreens[0]->iControlGroups[i].iClientWindowGroupId != CHuiStatic::RootWin(0)->Identifier())
                {
                iAlfWindowGroupNodeId = iAlfScreens[0]->iControlGroups[i].iWindowGroupNodeId;
                return;
                }
            }        
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
CHuiDisplay* CAlfBridge::Display(TInt aScreenNum)
    {
    for ( TInt i = 0 ; i < iAlfScreens.Count() ; i++ )
        {
        if ( iAlfScreens[i]->iScreenNum == aScreenNum )
            {
             return iAlfScreens[i]->iDisplay;
            }
        }
    return NULL;
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ReorderAlfControlGroupsL( TInt aScreenNumber )
    {
    if (iAlfScreens[aScreenNumber]->iDisplay)
        {
        RPointerArray<CHuiControlGroup> controlGroupOrder;
        CHuiRoster& roster = iAlfScreens[aScreenNumber]->iDisplay->Roster();
        for (TInt j=0; j<roster.Count();j++)
            {
            CHuiControlGroup& controlGroup = roster.ControlGroup(j);
            if (controlGroup.Control(0).Role() == EAlfSessionContainer)
                {
                controlGroupOrder.Append(&controlGroup);
                roster.Hide(controlGroup);
                j--; // roster.Hide does remove controlGroup from the roster 
                }
            }
            
        for (TInt k=0;k<controlGroupOrder.Count();k++)
            {
            ShowControlGroupL(roster, *controlGroupOrder[k], KHuiRosterShowAtTop, aScreenNumber);    
            }                                                        
        
        controlGroupOrder.Close();
        }
    }
        

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TInt CAlfBridge::FirstAlfControlGroupIndex( TInt aScreenNumber )
    {
    if (iAlfScreens[aScreenNumber]->iDisplay)
        {
        CHuiRoster& roster = iAlfScreens[aScreenNumber]->iDisplay->Roster();
        for (TInt j=0; j<roster.Count();j++)
            {
            if( roster.ControlGroup(j).Control(0).Role() == EAlfSessionContainer 
                || roster.ControlGroup(j).ResourceId() == iAlfWindowGroupNodeId )
                {
                return j; // Alf groups positioned just above alf servers window group   
                }
            }                                        
        }
    return 0; // Not found      
    }
        

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TInt CAlfBridge::LastAlfControlGroupIndex( TInt aScreenNumber )
    {
    if (iAlfScreens[aScreenNumber]->iDisplay)
        {                
        CHuiRoster& roster = iAlfScreens[aScreenNumber]->iDisplay->Roster();
        for (TInt j=0; j<roster.Count();j++)
            { // last is always a index of pointer event window position
            if( roster.ControlGroup(j).ResourceId() == iAlfWindowGroupNodeId )
                {
                return j; // Alf groups positioned just above alf servers window group   
                }
            }                
        }
    return 0;    
    }
    
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TInt CAlfBridge::ResolveScreenNumber( CHuiDisplay& aDisplay )
        {
        for ( TInt i = 0 ; i < iAlfScreens.Count() ; i++ )
            {
            if ( iAlfScreens[i]->iDisplay == &aDisplay )
                {
                return iAlfScreens[i]->iScreenNum;
                }
            }
        return KErrNotFound;
        }
    

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::NotifyDisplayRefreshStarted(CHuiDisplay& aDisplay)
    {
    // Look for the correct display
    TInt screenNumber = ResolveScreenNumber(aDisplay);
    RemoveTemporaryPresenterVisuals();
    if ( screenNumber != KErrNotFound )
        {
        // FPS Counter with hitchcock drawing
#ifdef SYMBIAN_BUILD_GCE
        if(iPrintFPS)
            {
            TReal fps = CHuiStatic::FrameRate();
            if(fps > 0)
                {
                TBuf<8> numBuf;
                numBuf.AppendNum(fps, TRealFormat(5,1));
                TRAP_IGNORE(
                        {
                        iAlfScreens[screenNumber]->iFPSText->SetTextL( numBuf );
                        })
                }
            }
#endif
        
        if (iAlfScreens[screenNumber]->IsVisualTreeVisibilityChanged())
            {
            HandleVisualVisibility( screenNumber );    
            iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(EFalse);
            }

        if (!iActivated)            
            {
            iBridgerClient.Connect();
            iActivated = ETrue;            
            }
        }
    }

// ---------------------------------------------------------------------------
// Check if there is effect and it's not fade effect.
// ---------------------------------------------------------------------------
// 
static TBool IsNonFadeEffect(CHuiFxEffect* aEffect)
    {
    return aEffect && !(aEffect->EffectFlags() & KHuiFadeEffectFlag);
    }

// ---------------------------------------------------------------------------
// Check if effect has been flagged as opaque
// ---------------------------------------------------------------------------
// 
static TBool IsOpaqueEffect(CHuiFxEffect* aEffect)
    {
    return aEffect && (aEffect->EffectFlags() & KHuiFxOpaqueHint);
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TBool CAlfBridge::IsVisualOpaque(CHuiVisual& aVisual)
    {
    // Effect with opaque hint overrides everything else.
    if (IsOpaqueEffect( aVisual.Effect() ))
        {
        return ETrue; // Opaque
        }    

    TBool transparent = EFalse;
    
    // TODO: We should check transformation too and perhaps parent transformations as well ?
    //transparent |= aVisual.IsTransformed(); 

    // if the control has an attached effect which is transformed, it must be considered transparent
    // as it may not cover the full screen
    if ( IsNonFadeEffect( aVisual.Effect() ) )
        {
        return EFalse;
        }
    if ( aVisual.Layout() && IsNonFadeEffect( aVisual.Layout()->Effect() ) )
        {
        return EFalse;
        }

    if (aVisual.Flags() & EHuiVisualFlagDrawOnlyAsExternalContent)
        {
        return EFalse; // not transparent
        }

    transparent |= (!((aVisual.Flags() & EHuiVisualFlagOpaqueHint) == EHuiVisualFlagOpaqueHint));
    transparent |= (aVisual.iOpacity.Now() < KAlfVisualDefaultOpacity);
    transparent |= (aVisual.iOpacity.Target() < KAlfVisualDefaultOpacity);
    
    return  !transparent;            
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ClipVisualRect(TRect& aRect, const TRect& aClippingRect)
    {    
    if (aRect.Intersects(aClippingRect))
        {
        // Clip to visible area, there are windows larger than screen for some reason.                
        aRect.Intersection(aClippingRect);     
        }
    else
        {
        // no intersection with the clipping rect -> outside of the screen -> not visible
        aRect = TRect(0,0,0,0);
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TBool CAlfBridge::IsRectCoveredByRegion(TRect aRect, TRegion& aCoveringRegion)
    {
    TBool isCovered = EFalse;

    // Zero sized rects are considered as covered (although it is a bit philosphical question)
    if (aRect.Size() == TSize(0,0))
        {
        isCovered = ETrue;    
        }
            
    // First check if it is covered by one of the rects in the covering region...
    if (!isCovered)
        {            
        TPoint topLeft = aRect.iTl;
        TPoint bottomRight = aRect.iBr;
        bottomRight.iX--;
        bottomRight.iY--;

        for (TInt i=0; i < aCoveringRegion.Count(); i++)
            {
            if (aCoveringRegion[i].Contains(topLeft) && 
                aCoveringRegion[i].Contains(bottomRight))
                {
                isCovered = ETrue;
                }                                    
            }
        }        

    // ...it may still cover it with a combination of several rects
    if (!isCovered)
        {            
        iTempVisualRegion.Clear();
        iTempIntersectingRegion.Clear();

        iTempVisualRegion.AddRect(aRect);
        
        iTempIntersectingRegion.Intersection(aCoveringRegion, iTempVisualRegion);
        iTempIntersectingRegion.Tidy();
        
        if (iTempIntersectingRegion.Count() == 1)
            {
            if (iTempIntersectingRegion[0] == aRect)
                {
                isCovered = ETrue;    
                }
            }        
        }
    
    return isCovered;
    }



// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleVisualVisibility( TInt aScreenNumber )
    {
    if (!iAlfScreens.Count())
        return;
            
    iTempRegion.Clear();
    
    CAlfScreen* screen = iAlfScreens[aScreenNumber];
    TRect fullscreen = TRect(TPoint(0,0), screen->Size());
    TBool fadeEffectInScreen = EFalse;
    
    
    // Prepare SW render target (if needed)
    if (iSwRenderingEnabled)
        {
        TBool modified = PrepareSwRenderingTarget( screen );
        
        if ( modified )
            {
            // To avoid debug panic, we need to reset foreground bitmap.
            TRAP_IGNORE( screen->iDisplay->SetForegroundBitmapL( 
                screen->iSwRenderingTarget ) );
            }
        }
    
    TBool fullscreenCovered = EFalse;
    //iActiveVisualCount = 0;
    iBgSurfaceFound = EFalse;
    //iPaintedArea = 0;  
    
    // Check if effect group has an effect with opaque hint.
    CHuiControlGroup& fxcontrolgroup = *(iAlfScreens[aScreenNumber]->iFullscreenEffectControlGroup);
    CHuiControl& fxcontrol = fxcontrolgroup.Control(0);
    CHuiCanvasVisual* fxlayout = (CHuiCanvasVisual*)&fxcontrol.Visual(0);
    CHuiVisual* fxExternalContent = fxlayout->ExternalContent();
    
    if (fxlayout && IsOpaqueEffect(fxlayout->Effect()))
        {
        fullscreenCovered = ETrue;    
        }
    else if (fxExternalContent && IsOpaqueEffect(fxExternalContent->Effect()))
        {
        fullscreenCovered = ETrue;
        }    
    
    #ifdef USE_MODULE_TEST_HOOKS_FOR_ALF
    iTempTotalActiveVisualCount = 0;
    iTempTotalPassiveVisualCount = 0;
    #endif
	
    // skip the topmost (effect) layer, start from floating sprite group
    for (TInt j=screen->iDisplay->Roster().Count() - screen->FixedControlGroupCount(); j>=0; j--)
        {                
#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
        TInt activevisualcount = 0;
        TInt passivevisualcount = 0;
#endif

        CHuiControlGroup& controlgroup = iAlfScreens[aScreenNumber]->iDisplay->Roster().ControlGroup(j);
        CHuiControl& control = controlgroup.Control(0);

        if (control.Role() == EAlfFpsIndicatorContainer)
            {
            // FPS container doesn't contain canvas visuals
            continue;
            }

        CHuiCanvasVisual* layout = (CHuiCanvasVisual*)&control.Visual(0);
#ifdef HUI_DEBUG_TRACK_DRAWING	
        if ( layout->Tracking() )
            {
            RDebug::Print(_L("CAlfBridge::HandleVisualVisibility: tracked visual 0x%x"), canvasVisual);
            }
#endif            
            
        // Dont mess with alf control group visuals, alf session handling does it for us
        // just add the rect to covered region because alf draws solid background.
        if (control.Role() == EAlfSessionContainer)
            {
            iTempRegion.AddRect(fullscreen);
            iTempRegion.Tidy();                                    
            continue;
            }
        
        // For optimization reasons, check if all visuals below in Z-order are covered    
        if (!fullscreenCovered)
            {
            fullscreenCovered = IsRectCoveredByRegion(fullscreen, iTempRegion);            
#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
            if (fullscreenCovered)
                __ALFLOGSTRING("Full screen covered!");                    
#endif
            }
        
        if (!fullscreenCovered)
            {
            fullscreenCovered = screen->iDisplay->Roster().IsVisibleContentFrozen();
#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
            if (fullscreenCovered)
                __ALFLOGSTRING("Full screen covered because of frozen roster content");                    
#endif
            }
        
        TBool subTreeCovered = EFalse;
        TBool hasActiveVisualsInVisualTree = HandleLayoutVisualVisibility( layout, controlgroup, control, fullscreenCovered, fullscreen, screen, subTreeCovered, IsVisualOpaque(*layout)  );    
        TBool hasFadeEffectsInVisualTree = (layout->CanvasFlags() & EHuiCanvasFlagExternalFadeExistsInsideVisualTree);        

        // If root visuals effect is marked as opaque, then add whole screen area as covered.
        if (!fullscreenCovered)
            {
            fullscreenCovered = IsOpaqueEffect(layout->Effect());
            }                    
        
		// If we layout is active setup the fade effects. Also if it is inactive, but has been
		// flagged as containing fade effect, then run the setup as well so that effects which
		// are no more needed get removed.
        if (hasActiveVisualsInVisualTree || (!hasActiveVisualsInVisualTree && hasFadeEffectsInVisualTree))
            {
            fadeEffectInScreen = ETrue;
            
            // Prepare fade effects to whole visual tree  below layout
            PrepareFadeEffects( *layout );
    
            // Load needed fade effects (or remove them)
            TBool visualTreeHasFadeEffects = LoadFadeEffectsL( *layout );
            
            // Set flag so that next time we can optimize
            if (visualTreeHasFadeEffects)
                {
                layout->SetCanvasFlags(EHuiCanvasFlagExternalFadeExistsInsideVisualTree);
                }
            else
                {
                layout->ClearCanvasFlags(EHuiCanvasFlagExternalFadeExistsInsideVisualTree);            
                }
            }
        
        if (!hasActiveVisualsInVisualTree)
            {
            // Setting also the root visual (layout) as inactive, if it had none
			// active children. This is because otherwise the Inactive checks won't
			// work correctly within RosterImpl ScanDirty & ClearChanged phases.
            layout->SetFlag(EHuiVisualFlagInactive);
            }
        else
            {
            layout->ClearFlag(EHuiVisualFlagInactive);
            }
        
#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
        __ALFLOGSTRING1(">>>> HandleVisualVisibility: Control group index: %d", j );
        __ALFLOGSTRING1(">>>> HandleVisualVisibility: Active visuals : %d", activevisualcount );
        __ALFLOGSTRING1(">>>> HandleVisualVisibility: Passive visuals: %d", passivevisualcount );
#endif
            
        }
    if (iBgSurfaceFound)
        {
        if (!iInLowMemMode)
            {
            SetLowMemory(ETrue);
            iBridgerClient.SendBlind(KAlfCompositionTargetHidden, TIpcArgs());
            iInLowMemMode = ETrue;            
            }
        }
    else if (iInLowMemMode)
        {
        SetLowMemory(EFalse);
        iBridgerClient.SendBlind(KAlfCompositionTargetVisible, TIpcArgs());
        iInLowMemMode = EFalse;
        }


    // Finally, if there are fadeeffects applied to windowgroups, make sure first one does not
    // blend itself, but other windowgroups do blend. Otherwise windowgrouops above others
    // would clear the screen areas where they do not really draw.
    if (fadeEffectInScreen)
        {
        TBool firstFadedWindowGroupFound = EFalse;
        for (TInt j=0; j<screen->iDisplay->Roster().Count() - screen->FixedControlGroupCount(); j++) // skip the topmost (effect) layer 
            {                
            CHuiControlGroup& controlgroup = iAlfScreens[aScreenNumber]->iDisplay->Roster().ControlGroup(j);
            CHuiControl& control = controlgroup.Control(0);
            CHuiVisual* layout = &control.Visual(0);
            if (layout->Effect() && (layout->Effect()->EffectFlags() & KHuiFadeEffectFlag))
                {
                if (firstFadedWindowGroupFound)
                    {
                    TInt flags = layout->Effect()->EffectFlags();
                    flags |= KHuiFxAlwaysBlend;
                    layout->Effect()->SetEffectFlags(flags);
                    }
                firstFadedWindowGroupFound = ETrue;
                }
            }
        }

    AMT_FUNC_EXC(AMT_DATA()->iActiveVisualCount = iTempTotalActiveVisualCount;
                 AMT_DATA()->iPassiveVisualCount = iTempTotalPassiveVisualCount;
                 AMT_DATA()->PrintState()
                 );
    }

TBool CAlfBridge::HandleLayoutVisualVisibility(
        CHuiLayout* aLayout, 
        CHuiControlGroup& aControlGroup,
        CHuiControl& aControl,
        TBool& aFullscreenCovered, 
        TRect& aFullscreen,
        CAlfScreen* aScreen,
        TBool& aSubtreeVisible, 
        TBool aChildCanBeOpaque )
    {
    TBool visualTreeActive = EFalse;
    TRect visualDisplayRect;
    TBool visualRectIsCovered = EFalse;
    TBool visualIsOpaque = EFalse;
    TBool visualIsActive = EFalse;
    CHuiCanvasVisual* canvasVisual = NULL;

    for (TInt i=aLayout->Count()-1; i >= 0; i--)
        {
        visualDisplayRect = TRect(0,0,0,0);
        visualRectIsCovered = EFalse;
        visualIsOpaque = EFalse;
        visualIsActive = EFalse;
        TBool visualSubtreeVisible = EFalse;
        
        // Check first if visual itself is hidden or does hide other visuals below 
        // in z-order. If it does not hide, then we do not add its displayrect to covering 
        // region.
        canvasVisual = (CHuiCanvasVisual*)(&aLayout->Visual(i));
        
        // Child can be considered to be opaque only if all parents are opaque and
        // visual itself is opaque.
        // For example, parent can have opacity < 1 and that affects children as well.
        // As another example, parent can have scaling transformation.
        visualIsOpaque = aChildCanBeOpaque && IsVisualOpaque(*canvasVisual);
        if (canvasVisual->Count())
            {
            visualTreeActive |= HandleLayoutVisualVisibility( canvasVisual, aControlGroup, aControl, aFullscreenCovered, aFullscreen, aScreen, visualSubtreeVisible, visualIsOpaque );
            }
    #ifdef HUI_DEBUG_TRACK_DRAWING  
        if ( canvasVisual->Tracking() )
            {
            RDebug::Print(_L("CAlfBridge::HandleVisualVisibility: tracked visual 0x%x"), canvasVisual);
            }
    #endif                
        
        if (visualSubtreeVisible)
            {
            aSubtreeVisible = ETrue;
            }
            
        // Optimization, it is faster to check fullscreen than read visuals displayrect
        if (aFullscreenCovered)
            {
            visualRectIsCovered = ETrue;    
            }
        else
            {
            // Check where visual is            
            visualDisplayRect = canvasVisual->DisplayRect();
    
            // Make sure we clip visual rect to visible screen area
            ClipVisualRect(visualDisplayRect, aFullscreen);
            
            // Check if this visual is covered by other opaque visuals which rects are in "covered" region           
            visualRectIsCovered = IsRectCoveredByRegion(visualDisplayRect, iTempRegion);                    
            }
    
    /*            if ( layout->Effect() || canvasVisual->Effect() )
            {
            visualRectIsCovered = EFalse;
            }
    */
        TBool wasInactive = canvasVisual->Flags() & 
            ( EHuiVisualFlagInactive | EHuiVisualFlagUnderOpaqueHint ); 
        
        if (visualRectIsCovered)
            {                                        
            // We clear texture cache here to avoid running out of texture memory  
            if (!(canvasVisual->Flags() & EHuiVisualFlagAlwaysDraw)) // The window has been hidden. However it has exit effect and it must stay active until effect has stopped
                {
                if (visualSubtreeVisible)
                    {
                    canvasVisual->SetFlag(EHuiVisualFlagUnderOpaqueHint);
                    canvasVisual->ClearFlags(EHuiVisualFlagInactive); 
                    }
                else
                    {
                    canvasVisual->SetFlag(EHuiVisualFlagInactive);
                    canvasVisual->ClearFlags(EHuiVisualFlagUnderOpaqueHint); 
                    }
                
                canvasVisual->ClearCache();
                // For SW rendering, disable capturing buffer
                canvasVisual->SetCapturingBufferL(NULL);
                }
            else
                { // this should be drawn, but inactivate when effect is done
                canvasVisual->ClearFlags(
                    EHuiVisualFlagInactive | EHuiVisualFlagUnderOpaqueHint |
                    EHuiVisualFlagShouldBeInactive | EHuiVisualFlagShouldBeUnderOpaqueHint );
                if (visualSubtreeVisible)
                    {
                    canvasVisual->SetFlag(EHuiVisualFlagShouldBeUnderOpaqueHint);
                    }
                else
                    {
                    canvasVisual->SetFlag(EHuiVisualFlagShouldBeInactive);
                    }
                canvasVisual->PrepareCache();
                // For SW rendering, set capturing buffer if it exists)
                canvasVisual->SetCapturingBufferL(aScreen->iSwRenderingTarget);                

                if (wasInactive)
                    {
                    canvasVisual->SetChanged();
                    }
                }
                
            if (!wasInactive)
                {
                aScreen->iDisplay->SetDirty();
                }                
            
            #ifdef USE_MODULE_TEST_HOOKS_FOR_ALF
            iTempTotalPassiveVisualCount++;
            #endif
            
    #ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
            passivevisualcount++;
    #endif
            }
        else
            {
			aSubtreeVisible = ETrue;
            canvasVisual->ClearFlags( 
                EHuiVisualFlagInactive | EHuiVisualFlagShouldBeInactive |
                EHuiVisualFlagUnderOpaqueHint | EHuiVisualFlagShouldBeUnderOpaqueHint );
            canvasVisual->PrepareCache();
            canvasVisual->SetCapturingBufferL(aScreen->iSwRenderingTarget);                

            // we've found non-inactive window which has background surface
            // attached..
            if (canvasVisual->IsBackgroundDrawingEnabled() &&
                canvasVisual->LayerExtent() != TRect() &&
                !canvasVisual->LayerUsesAlphaFlag() )
                {
                // if paintedareacount is exactly one, it means that the window
                // has background surface but no drawing commands
                if (canvasVisual->PaintedAreaCount() == 1) 
                    {
                    THuiCanvasPaintedArea pa = canvasVisual->PaintedArea(0);
                    TRect r = pa.iPaintedRect.Round();
                    // if we found a fullscreen surface with no other drawing commands
                    // we can safely assume that it's about the only thing to be visible
                    // and we can release memory occupied by other parts of the system
                    // 
                    // NOTE: this mechanism keeps the system in low mem state
                    // if the surface is visible, meaning that for example
                    // opening an options menu does not instantly trigger normal
                    // memory state. We want to do it like this as otherwise
                    // we would be triggering for example background animation
                    // on / off quite rapidly........
                    if ( r == Display(0)->VisibleArea())
                        {
                        // Final test. Surface must not be ALF surface, but some other surface.                        
                        CHuiControlGroup* alfControlGroup = FindControlGroupByAppId( iAlfSecureId );
                        if (alfControlGroup != &aControlGroup)
                            {                        
                            iBgSurfaceFound = ETrue;
                            }
                        }
                    }
                }

            if (wasInactive)
                {
                canvasVisual->SetChanged();
                }
    #ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
            activevisualcount++;
    #endif
            }
            
        // Finally check the area that this visual covers and add it to covered region
        visualIsActive = !(canvasVisual->Flags() & EHuiVisualFlagInactive);
    
        // Sprites and effects as we consider them always as transparent and also
        // if controlgroup is transformed somehow    
        
        if (aControl.Role() == EAlfFullScreenEffectContainer 
            || aControl.Role() == EAlfWindowFloatingSpriteContainer ||
            aControlGroup.IsTransformed())
            {
            visualIsOpaque = EFalse;    
            }
    
        if (visualIsActive && visualIsOpaque && !visualRectIsCovered)
            { 
    #ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
            if (canvasVisual->PaintedAreaCount())
                __ALFLOGSTRING2("Visual has painted areas: displayrect: iTl: %i, %i", visualDisplayRect.iTl.iX, visualDisplayRect.iTl.iY);                    
                __ALFLOGSTRING2("Visual has painted areas: displayrect: iBr: %i, %i", visualDisplayRect.iBr.iX,visualDisplayRect.iBr.iY);
                #endif
            for (TInt k=0; k < canvasVisual->PaintedAreaCount(); k++)
                {                                
                THuiCanvasPaintedArea paintArea = canvasVisual->PaintedArea(k);
                TRect coveredRect = paintArea.iPaintedRect;
                                
                // Clip to visible area, there are windows larger than screen for some reason.                
                ClipVisualRect(coveredRect, aFullscreen);
                
                // Only add to covering region if the painted area is defined as opaque
                if (paintArea.iPaintType == EHuiCanvasPaintTypeOpaque)
                    {
    #ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
                    __ALFLOGSTRING2("Covered rect: iTl: %i, %i", coveredRect.iTl.iX, coveredRect.iTl.iY);                    
                    __ALFLOGSTRING2("Covered rect: iBr: %i, %i", coveredRect.iBr.iX,coveredRect.iBr.iY);
    #endif
                    iTempRegion.AddRect(coveredRect);
                    iTempRegion.Tidy();                                    
                    }
                }
            
            // If effect is marked as opaque, then add whole visual area as covered.
            if (IsOpaqueEffect(canvasVisual->Effect()))
                {
                iTempRegion.AddRect(visualDisplayRect);
                iTempRegion.Tidy();
                }            
            }                                        
        visualTreeActive |= visualIsActive;
        } // for loop end : children checking loop
     
    return visualTreeActive;
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::ClearCanvasVisualCommandSets(TBool aInactiveOnly)
    {
    if (!iAlfScreens.Count())
        return;
            
    CAlfScreen* screen = iAlfScreens[0]; // TODO  
    for (TInt j=screen->iDisplay->Roster().Count() - screen->FixedControlGroupCount(); j>=0; j--) // skip the topmost (effect) layer 
        {                
        CHuiControlGroup& controlgroup = iAlfScreens[0]->iDisplay->Roster().ControlGroup(j);
        CHuiControl& control = controlgroup.Control(0);

        if ( control.Role() == EAlfSessionContainer ||
             control.Role() == EAlfFpsIndicatorContainer )
            {
            continue;
            }
        
        CHuiVisual* layout = &control.Visual(0);
        for (TInt i=layout->Count()-1; i >= 0; i--)
            {
            CHuiCanvasVisual* canvasVisual = (CHuiCanvasVisual*)(&layout->Visual(i));
            if (!aInactiveOnly)
                {
                canvasVisual->ClearCommandSet();
                }
            else if (aInactiveOnly && (canvasVisual->Flags() & EHuiVisualFlagInactive))
                {
                canvasVisual->ClearCommandSet();                        
                }
            else
                {
                // dont clear
                }
            }
        }
    }


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::EnableVisualDefaultTransformationsL(CHuiVisual& aVisual)
    {
    aVisual.EnableTransformationL();
    if (!aVisual.Transformation().Count())
        {
        aVisual.Transformation().Rotate(0);
        aVisual.Transformation().Scale(1,1);
        aVisual.Transformation().Translate(0,0);                                                
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleCallback(TInt aStatus)
    {
    TInt err = KErrNone;
    if (aStatus >= 0)
        {
        TRAP(err, DoDispatchL(aStatus))
        }            
    
    if (aStatus < 0 || err)
        {
        __ALFLOGSTRING2("CAlfBridge::HandleCallback status: %d error: %d",aStatus,err);
        
        CEikonEnv* eikenv = CEikonEnv::Static();
        if ( eikenv )
        		{
        		eikenv->HandleError(err?err:aStatus);
            }
        }
    }
        

// ---------------------------------------------------------------------------
// DoDispatchL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::DoDispatchL(TInt aStatus)
    {
    if (*iHost)
        {
        TAlfBridgerData data = (*iHost)->GetData(aStatus);
        // dispatch
        __ALFLOGSTRING1( "CAlfBridge::DoDispatchL: %d",data.iOp );

        switch (data.iOp)
            {
            case EAlfDSSynchronize:
                {
                TInt id = data.iInt1;
                if ( iHuiEnv )
                    {
                    iHuiEnv->Synchronize( id, this );
                    }
                }
                break;
                
            case EAlfDSCreateNewDisplay:
                {
                AddNewScreenL(NULL);
                break;
                }
            case EAlfDSDestroyDisplay:
                {
                HandleDestroyDisplay( data.iInt1 );
                break;
                }
            case EAlfDSNewWindow:
                {
                HandleNewWindowL( data );
                break;
                }
            case EAlfDSDestroyWindow:
            	{
                HandleDestroyWindowL( data );
            	break;
                }
            case EAlfDSSetWindowPos:
                {
                HandleSetWindowPosL( data );
                break;
                }
            case EAlfDSSetWindowSize:
                {
                HandleSetWindowSizeL( data );
                break;
                }
            case EAlfDSSetWindowRotation:
                {
                HandleSetWindowRotationL( data );
                break;
                }
            case EAlfDSSetWindowOpacity:
                {
                HandleSetWindowOpacityL( data );
                break;
                }
            case EAlfDSRefreshCallback:
                {
                iHuiEnv->ContinueRefresh();
                break;
                }
            case EAlfDSReorder:
                {
                HandleReorderWindowL( data );
                break;
                }                    
            case EAlfDSPostCanvasBuffer:
            	{
                HandlePostCanvasBufferL( data );
            	break;
            	}
            case EAlfDSSetWindowActive:
                {
                HandleSetWindowActiveL( data );
                break;
                }
            case EAlfDSSetWindowFlag:
            case EAlfDSClearWindowFlag:
                {
                HandleSetWindowFlagL(data, data.iOp);
                break;
                }
            case EAlfDSSetSurfaceExtent:
                {
                HandleSetSurfaceExtentL( data );
                break;
                }
            case EAlfDsLayerUsesAlphaFlagChanged:
                { 
                HandleLayerUsesAlphaFlagChanged( data );
                break;
                }
            case EAlfDSGetAlfNativeWindowData:
                {
//                HandleGetNativeWindowDataL( data );
                break;
                }
            case EAlfDSGroupChained:
            	{
            	__ALFLOGSTRING("CAlfBridge::DoDispatchL, EAlfDSGroupChained");    
            	// TODO, link groups 
            	break;
            	}
            case EAlfDSGroupChainBroken:
            	{
            	__ALFLOGSTRING("CAlfBridge::DoDispatchL, EAlfDSGroupChainBroken");    
            	// TODO, break link
            	break;
            	}
            case EAlfDSMoveWindowToNewGroup:
            	{
            	/*
            	RDebug::Print(_L("CAlfBridge::DoDispatchL, EAlfDSMoveWindowToNewGroup, THIS METHOD IS UNTESTED. EXPECT TROUBLE!"));
            	// TODO: TEST!
            	TInt windowGroupNodeId = data.iInt1;
            	TInt windowNodeId = data.iInt2;
            	TInt newGroupId = (TInt)data.iPtr;
            	CHuiLayout* layout = NULL;
            	CHuiCanvasVisual* viz = (CHuiCanvasVisual*)FindVisual(windowNodeId, windowGroupNodeId,screenNumber);
            	if (viz)
            		{
            		// #1 remove visual from old group
            		layout = viz->Layout();
            		layout->Remove(viz);                           
            		viz->Owner().Remove(viz);
            		// #2 insert visual to the beginning of the new group
            		CHuiControlGroup* controlGroup = FindControlGroup(newGroupId,screenNumber);
            		if (controlGroup)
            			{
            			CHuiControl& control = controlGroup->Control(0);
            			CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
            			layout->AppendL( viz );
            			}
            		}*/
            		break;
            	}
            case EAlfEffectFx:
                {
                HandleGfxEffectsL( data );
                break;
                }
            case EAlfStopEffectFx:
                {
                HandleGfxStopEffectsL( data );
                break;
                }
            case EAlfControlEffectFx:
                {
                HandleGfxControlEffectsL( data );
                break;
                }
            // TODO: implement these    
            case EAlfRegisterEffectFx:
                {
                HandleRegisterEffectL( data );
                break;
                }
            case EAlfUnregisterEffectFx:
                {
                for (TInt i = 0; i < iAlfRegisteredEffects.Count(); i++)
                    {
                    if (iAlfRegisteredEffects[i].iAction == data.iInt1)
                        {
                        TRegisteredEffectsStruct removed =
                                iAlfRegisteredEffects[i];
                        iAlfRegisteredEffects.Remove(i);
                        CHuiFxEngine* engine = NULL;
                        engine = iHuiEnv->EffectsEngine();
                        if (engine)
                            {
                            engine->UnRegisterEffectL(*removed.iEffectFile);
                            }
                        delete removed.iEffectFile;
						// if this happened to be the fade effect, the cached fade effect filename should
						// be cleared
                        if ( data.iInt1 == KFadeAction)
                            {
                            RegisterFadeEffectL();
                            }
                        break;
                        }
                    }
                break;
                }
            case EAlfUnregisterAllFx:
                {
                while (iAlfRegisteredEffects.Count())
                    {
                    TRegisteredEffectsStruct removed =
                            iAlfRegisteredEffects[0];
                    iAlfRegisteredEffects.Remove(0);
                    CHuiFxEngine* engine = NULL;
                    engine = iHuiEnv->EffectsEngine();
                    if (engine)
                        {
                        engine->UnRegisterEffectL(*removed.iEffectFile);
                        }

                    delete removed.iEffectFile;
                    }
                // fade file might have changed. This will be resolved when next fade effect request arrives.
                RegisterFadeEffectL();
                break;
                }
            case EAlfDSSetCursorData:
                {
                HandleSetCursorDataL( data );
                break;
                }
            case EAlfDSSetFadeEffect:
                {
                HandleSetFadeEffectL( data );
                break;
                }
            case EAlfDSSetNodeTracking:
                {
                HandleSetNodeTracking( data );
                break;
                }
           case EAlfBridgeSetScreenRotation:
                {
                //short cut..  
                __ALFLOGSTRING1("CAlfBridge::DoDispatchL: EAlfBridgeSetScreenRotation: %d",data.iInt1);  
                CHuiGc::TOrientation huiOrientation(CHuiGc::EOrientationNormal);
	            switch(data.iInt1)
	                {
	                case 1: // 90    
                    huiOrientation = CHuiGc::EOrientationCCW90;
                    break;
	            case 2: // 180    
                    huiOrientation = CHuiGc::EOrientation180;
                    break;
	            case 3: // 270    
                    huiOrientation = CHuiGc::EOrientationCW90;
                    break;
                default:
                    break;
                    }
	            if (iAlfScreens[0]->iDisplay->Orientation() != huiOrientation)
	                {
                    HandleSetLayoutSwitchEffectL();
	                iAlfScreens[0]->iDisplay->SetOrientation(huiOrientation);
	                if (iAppUi)
	                	{
	                	iAppUi->AdjustWindowGroupPositionL(0,CAlfAppServer::EAlfWindowSize); // hackish, but one way to enforce alf window resizing
	                	}
	                __ALFLOGSTRING1("AlfScreens[0]->iDisplay->SetOrientation: %d",huiOrientation);  	                
	                }
	            
                break;         
                }
           case EAlfEffectFxBeginSyncronizedGroup:
        	   {
        	   CHuiFxEngine* engine = iHuiEnv->EffectsEngine();
        	   if (engine)
        		   {
				   engine->BeginGroupEffect(data.iInt1);
        		   }
        	   break;
        	   }
           case EAlfEffectFxEndSyncronizedGroup:
        	   {
        	   TInt groupId = data.iInt1;
        	   //TBool forced = data.iInt2;
        	   __ALFLOGSTRING1("CAlfBridge::DoDispatchL - Ending for group %d requested.", 
        			   groupId ); 
        	   CHuiFxEngine* engine = iHuiEnv->EffectsEngine();
        	   if (engine)
        		   {
				   engine->StartGroupEffect(groupId);
        		   }
        	   iHuiEnv->ContinueRefresh();
        	   break;
        	   }
           case KUnInitialized:
               {
               __ALFLOGSTRING1("CAlfBridge::DoDispatchL: Received KUnInitialized: %d - CRITICAL ERROR!",data.iOp);
               USER_INVARIANT();
               }
            default:
              {
              // Should not happen
              __ALFLOGSTRING1("CAlfBridge::DoDispatchL: Received Unknown op: %d",data.iOp);
              }
            }
        }
   }

// ---------------------------------------------------------------------------
// HandleDestroyDisplay
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleDestroyDisplay( TInt aScreenNumber )
    {
    iAlfScreens[aScreenNumber]->iDisplay->iRefreshObservers.Remove( *this );
    // TODO: Following delete iAlfScreens[aScreenNumber] crashes when display is trying to delete roster. 
    // RosterEntry is trying to refer to display, which is appareantly alrady destroyed. The roster should have no iRootVisual when display is removed. 
    
    iAlfScreens[aScreenNumber]->iDisplay->Roster().Hide(*(iAlfScreens[aScreenNumber]->iFloatingSpriteControlGroup)); 
    iAlfScreens[aScreenNumber]->iDisplay->Roster().Hide(*(iAlfScreens[aScreenNumber]->iFullscreenEffectControlGroup));
    if ( iAlfScreens[aScreenNumber]->iFpsControlGroup )
        {
        iAlfScreens[aScreenNumber]->iDisplay->Roster().Hide(*(iAlfScreens[aScreenNumber]->iFpsControlGroup));
        }
    delete iAlfScreens[aScreenNumber];
    iAlfScreens.Remove( aScreenNumber );
    }

// ---------------------------------------------------------------------------
// HandleNewWindowL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleNewWindowL( TAlfBridgerData& aData )
	{
	TInt windowGroupNodeId = aData.iInt1;
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber; 
	__ALFLOGSTRING1("CAlfBridge::HandleNewWindowL: new window %d!",windowNodeId);    
	                
	switch (windowAttributes->iWindowNodeType)
		{
		case EAlfWinTreeNodeGroup:
			{
			CHuiControlGroup& controlGroup = CreateControlGroupL(
			        windowGroupNodeId, 
			        windowAttributes->iClientHandle, 
			        windowAttributes->iSecureId,
			        screenNumber);                            

			// We just received notification for our own window group creation, store its node id for doing
			// faster lookups later...
			if (windowAttributes->iClientHandle == iAlfWindowGroupId)
				{
				iAlfWindowGroupNodeId = windowGroupNodeId;    
				}
			break;    
			}
		case EAlfWinTreeNodeClient:
		case EAlfWinTreeNodeRoot: // TODO: Root window receives drawing commands too
		case EAlfWinTreeNodeAnim:
		case EAlfWinTreeNodeSprite:
		case EAlfWinTreeNodeTextCursor:
			{
			CHuiControlGroup* controlGroup = FindControlGroup(windowGroupNodeId,screenNumber);
			// Floating sprites only require own group. Normal sprites should behave as normal visuals.
			if (!controlGroup && windowAttributes->iWindowNodeType == EAlfWinTreeNodeSprite )
				{                            
				controlGroup = iAlfScreens[screenNumber]->iFloatingSpriteControlGroup;
				}

			if (controlGroup)
				{
				CHuiControl& control = controlGroup->Control(0);
				CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
				CHuiCanvasVisual* viz = NULL;
				CHuiCanvasVisual* parentViz = NULL;             
				parentViz = (CHuiCanvasVisual*)FindVisual(windowAttributes->iParentNodeId);             
				if (parentViz)
				    {
                    viz = CHuiCanvasVisual::AddNewL(control, parentViz);
				    }
				else
				    {
                    viz = CHuiCanvasVisual::AddNewL(control, layout);
				    }
				__ALFFXLOGSTRING2("CAlfBridge::HandleNewWindowL visual: 0x%x, id 0x%x", viz, windowNodeId);
				AddVisual( 
				    windowNodeId, 
					windowAttributes->iClientHandle, 
					windowAttributes->iClientGroupHandle, 
					viz );

                // check , if a window is having already defined effect.
                if (iControlEffectData 
                        && iControlEffectData->iClientHandle == windowAttributes->iClientHandle
                        && iControlEffectData->iClientGroupHandle == windowAttributes->iClientGroupHandle)
                    {
                    HandleGfxControlEventL(*iControlEffectData, viz);
                    delete iControlEffectData;
                    iControlEffectData = NULL;
                    }
				viz->SetCommandType( CHuiCanvasVisual::ECommandBufferSgc );
				viz->SetFlags(EHuiVisualFlagManualLayout | EHuiVisualFlagInactive);
#ifdef HUI_DEBUG_TRACK_DRAWING
				if ( windowAttributes->iTrackWindow )
				    {
				    viz->SetTracking( windowAttributes->iTrackWindow );
				    }
#endif
				// draw sprites and anims the last inside their windowgroup
				/*if (windowAttributes->iWindowNodeType == EAlfWinTreeNodeSprite || windowAttributes->iWindowNodeType == EAlfWinTreeNodeAnim )
					{
					viz->SetFlag(EHuiVisualFlagDrawAfterOthers);
					}
*/
				// Store identifier / tag to get handle of this visual later
				TBuf8<16> buf;
				buf.AppendNum(windowNodeId);
				viz->SetTagL(buf);                    
				viz->SetPos(windowAttributes->iPosition, windowAttributes->iTransitionTime);
				viz->SetSize(windowAttributes->iSize, windowAttributes->iTransitionTime);

				// Keep window invisible until activated, for now we use opacity for that.
				viz->iOpacity.Set(0, 0);
				
				// Set up parent link for clipping calculations
	            if (parentViz)
	                {
	                viz->SetCanvasFlags(EHuiCanvasFlagEnableCanvasClipping);
	                viz->SetParentCanvas(parentViz);	                
	                }
	            else
	                {
	                __ALFLOGSTRING1("CAlfBridge::HandleNewWindowL: Parent not found for visual %d!",windowNodeId);    
	                }								
				}
			else
				{
				__ALFLOGSTRING1("CAlfBridge::HandleNewWindowL: Control group not found for visual %d!",windowNodeId);    
				}    

			break; 
			}
		default:
			{
			__ALFLOGSTRING("CAlfBridge::HandleNewWindowL: Unknown window node type received !");
			}
		}
	iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue);
	}

// ---------------------------------------------------------------------------
// HandleDestroyWindow
// ---------------------------------------------------------------------------
// 
void CAlfBridge::DestroyWindow(CHuiVisual* aVisual, TBool aUseForce)
    {
    TInt index;
    TBool visualParticipatingInEffect = HasActiveEffect(aVisual, index);
    
    TBool effectIsExitEffect(ETrue);
    if (index != KErrNotFound)
        {
        effectIsExitEffect = iEffectCleanupStack[index].iHideWhenFinished;
        }
    // effects inside application may need to destroy window to get the new content visible. 
    // Even when there is effect on the layout, destruction of a child window must be allowed.
    if ( !aUseForce && visualParticipatingInEffect && effectIsExitEffect )
        {
        // this visual will be destroyed on the effect call back.
        __ALFFXLOGSTRING1("CAlfBridge::DestroyWindow - not destroying 0x%x", aVisual);
        aVisual->SetFlag(EHuiVisualFlagShouldDestroy);
        // TODO: Revise
        // move to effect controlgroup
        //CHuiControl& effectControlGroup = iAlfScreens[0]->iFullscreenEffectControlGroup->Control(0);
        //CHuiLayout* effectControlGroupLayout = (CHuiLayout*) &effectControlGroup.Visual(0);
        // Transfers ownership of visuals. 
        //effectControlGroup.AppendL(aVisual, effectControlGroupLayout); // this will remove it from the previous layout
        //aVisual->SetOwner(effectControlGroup);
        return;
        }
    __ALFFXLOGSTRING1("CAlfBridge::DestroyWindow 0x%x", aVisual);
    RemoveImageBrushL(*aVisual);
    CHuiLayout* layout = aVisual->Layout();
    if (layout)
        layout->Remove(aVisual);
    aVisual->Owner().Remove(aVisual);
    __ALFLOGSTRING1("CAlfBridge::HandleDestroyWindow - destroying visual 0x%x", aVisual);
    // check if visual is having an effect at the moment. This could occur, if options menu is exited (with effect) and then 
    // application is exited. EHuiVisualFlagDrawOnlyAsExternalContent is indication that
    // there might be effect on this visual. It is not guaranteen.
    
    if (!aUseForce)
        {
        // we can remove from iEffectCleanupStack only when this method was called from HandleDestroyWindow. Otherwise
        // messing iEffectCleanupStack is likely to cause forever loop in some RemoveTemporaryPresenterVisuals method
        for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
            {
            TEffectCleanupStruct& effectItem = iEffectCleanupStack[i];
            if (aVisual == effectItem.iEffectedVisual)
                {
                iEffectCleanupStack.Remove(i);
                AMT_DEC_COUNTER(iAlfBridgeEffectCleanupStackCount);
                break;
                }
            }
        }
    delete aVisual;
    }
// ---------------------------------------------------------------------------
// HandleDestroyWindowL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleDestroyWindowL( TAlfBridgerData& aData )
	{
	TInt windowGroupNodeId = aData.iInt1;
	TInt windowNodeId = aData.iInt2;

	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;

	switch (windowAttributes->iWindowNodeType)
		{
		case EAlfWinTreeNodeGroup:
			{
			DeleteControlGroupL(windowGroupNodeId, screenNumber);                            
			break;    
			}
		case EAlfWinTreeNodeClient:
		case EAlfWinTreeNodeRoot:
		case EAlfWinTreeNodeAnim:
		case EAlfWinTreeNodeSprite:                            
		case EAlfWinTreeNodeFloatingSprite:  
		case EAlfWinTreeNodeTextCursor:    
			{
            // close cursor timer
            if (windowAttributes->iWindowNodeType == EAlfWinTreeNodeTextCursor)
                {
	            iCursorTimer->Cancel();
	            }

			//just remove the visual
			CHuiCanvasVisual* viz;
			
			viz = (CHuiCanvasVisual*)FindVisual(windowNodeId);
			CHuiControlGroup* controlGroup = FindControlGroup( windowGroupNodeId, screenNumber );
		     // Sprite is in its own group, and can be deleted normally.
			if ( !controlGroup  && windowAttributes->iWindowNodeType != EAlfWinTreeNodeSprite )
			    {
			    __ALFLOGSTRING("CAlfBridge::HandleDestroyWindowL: group containing this visual has been destroyed.!");
			    // the group containing this visual has been destroyed. Thus the visual itself has been destroyed by 
			    // the group. Ignore this.
			    }
			else
			    {
			    // = (CHuiCanvasVisual*)de(windowNodeId, windowGroupNodeId,screenNumber);
			    if (viz)
			        {
#ifdef HUI_DEBUG_TRACK_DRAWING
        if ( viz->Tracking() )
            {
            RDebug::Print(_L("CAlfBridge::HandleDestroyWindowL - Tracked visual"));
            }
#endif
		            DestroyWindow(viz);
			        }
			    else
			        {
			        __ALFLOGSTRING("CAlfBridge::HandleDestroyWindowL: visual not found!");
			        }
			    }
			RemoveVisual( windowNodeId );
			break;
			}                                                     
		default:
			{
			__ALFLOGSTRING("CAlfBridge::HandleDestroyWindowL: Unknown window node type received !");
			break;
			}
		}
	// TODO: Toolkit does not support recycling (of visuals),
	// this is not in line with Nokia environmental policy...
	iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue);
	}

// ---------------------------------------------------------------------------
// HandleSetWindowPosL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetWindowPosL( TAlfBridgerData& aData )
	{
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;
	// fetch visual
	CHuiVisual* viz = FindVisual(windowNodeId);
	if (viz)
		{
#ifdef HUI_DEBUG_TRACK_DRAWING
		if ( viz->Tracking() )
		    {
		    RDebug::Print(_L("CAlfBridge::HandleSetWindowPosL - Tracked visual"));
		    }
#endif

		viz->SetPos(windowAttributes->iPosition, windowAttributes->iTransitionTime);
		  iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue); // TODO: Check if really changed   
		}
	else
		{
		__ALFLOGSTRING("CAlfBridge::HandleSetWindowPosL, EAlfDSSetWindowPos: Visual not found!");    
		}   
	}

// ---------------------------------------------------------------------------
// HandleSetWindowSizeL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetWindowSizeL( TAlfBridgerData& aData )
	{
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;
	// fetch visual
	CHuiVisual* viz = FindVisual(windowNodeId);
	if (viz)
		{
#ifdef HUI_DEBUG_TRACK_DRAWING
        if ( viz->Tracking() )
            {
            RDebug::Print(_L("CAlfBridge::HandleSetWindowSizeL - Tracked visual"));
            }
#endif
		viz->SetSize(windowAttributes->iSize, windowAttributes->iTransitionTime);
		}
	else
		{
		__ALFLOGSTRING("CAlfBridge::HandleSetWindowSizeL, EAlfDSSetWindowSize: Visual not found!");    
		}   
    iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue);
	}

// ---------------------------------------------------------------------------
// HandleSetWindowRotationL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetWindowRotationL( TAlfBridgerData& aData )
	{
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	// fetch visual
	CHuiVisual* viz = FindVisual(windowNodeId);
	if (viz)
		{
#ifdef HUI_DEBUG_TRACK_DRAWING
        if ( viz->Tracking() )
            {
            RDebug::Print(_L("CAlfBridge::HandleSetWindowRotationL - Tracked visual"));
            }
#endif
		EnableVisualDefaultTransformationsL(*viz);
		viz->Transformation()[KVisualTransformationStepRotate].iParams[0].Set(windowAttributes->iRotation, 
				windowAttributes->iTransitionTime);                                                        
		}
	else
		{
		__ALFLOGSTRING("CAlfBridge::HandleSetWindowRotationL, EAlfDSSetWindowRotation: Visual not found!");                    
		}    
	}

// ---------------------------------------------------------------------------
// HandleSetWindowOpacityL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetWindowOpacityL( TAlfBridgerData& aData )
	{
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;
	// fetch visual
	CHuiVisual* viz = FindVisual(windowNodeId);
	if (viz)
		{
#ifdef HUI_DEBUG_TRACK_DRAWING
        if ( viz->Tracking() )
            {
            RDebug::Print(_L("CAlfBridge::HandleSetWindowOpacityL - Tracked visual"));
            }
#endif
		viz->iOpacity.Set(windowAttributes->iOpacity, windowAttributes->iTransitionTime);
		  iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue);  // TODO: Check if really changed  
		}
	else
		{
		__ALFLOGSTRING("CAlfBridge::HandleSetWindowOpacityL, EAlfDSSetWindowOpacity: Visual not found!");                                                
		}  
	}

// ---------------------------------------------------------------------------
// HandleReorderWindowL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleReorderWindowL( TAlfBridgerData& aData )
	{
	TInt windowGroupNodeId = aData.iInt1;
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;
	TInt ordinalPosition = windowAttributes->iOrdinalPosition;

	switch (windowAttributes->iWindowNodeType)
		{
		case EAlfWinTreeNodeGroup:
			{        

			// HACK !!!!                                                
			#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
			if (windowGroupNodeId == iAlfWindowGroupNodeId)
				{
				__ALFLOGSTRING1("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Alf window group going to: %d ",windowAttributes->iOrdinalPosition);    
				}
			else
				{
				__ALFLOGSTRING1("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: WS window group going to: %d ",windowAttributes->iOrdinalPosition);                                        
				}    
			#endif

			CHuiControlGroup* controlGroup = FindControlGroup(windowGroupNodeId,screenNumber);
			
                        if (!controlGroup)
                            {
                            User::Leave(KErrNotFound);
                            }

			// Window server nodes are in inverted Z-order, we switch it here.
			iAlfScreens[screenNumber]->iDisplay->Roster().Hide(*controlGroup);                            
			TInt wsWindowGroupCount = 0;
			for (TInt i=0; i<iAlfScreens[screenNumber]->iDisplay->Roster().Count();i++)
				{
                if (iAlfScreens[screenNumber]->iDisplay->Roster().ControlGroup(i).Control(0).Role()==EAlfWindowGroupContainer)
					{
					wsWindowGroupCount++;    
					}
				}
			ordinalPosition = wsWindowGroupCount - windowAttributes->iOrdinalPosition;
			
			#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
			__ALFLOGSTRING1("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: wsWindowGroupCount: %d ", wsWindowGroupCount);                                        
			__ALFLOGSTRING1("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Wimpautettu: %d ", ordinalPosition);                                        
			//RDebug::Print(_L("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Last total pos: %d "), iDisplay->Roster().Count() - 1);                                        
			#endif
			
			if (ordinalPosition < -1)
				{
				ordinalPosition = -1; // show at top ?    
				}
			
			if (iAlfScreens[screenNumber]->iDisplay && controlGroup)
				{
				ShowControlGroupL(iAlfScreens[screenNumber]->iDisplay->Roster(), *controlGroup, ordinalPosition, screenNumber); 
				}
			else
				{
				__ALFLOGSTRING2("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Control group not found! Screen: %d, Id: %d ", screenNumber, windowNodeId );        
				}
			
			ReorderAlfControlGroupsL(screenNumber);                                        
			break;    
			}
		case EAlfWinTreeNodeClient:
		case EAlfWinTreeNodeRoot:
		case EAlfWinTreeNodeAnim:
		case EAlfWinTreeNodeSprite:                            
		case EAlfWinTreeNodeFloatingSprite:
		case EAlfWinTreeNodeTextCursor:
			{
			
			// fetch visual
			CHuiLayout* layout = NULL;
			CHuiVisual* viz = FindVisual(windowNodeId);
			if (viz)
				{
#ifdef HUI_DEBUG_TRACK_DRAWING
                                if ( viz->Tracking() )
                                    {
                                    __ALFLOGSTRING("CAlfBridge::HandleReorderWindowL - Tracked visual");
                                    }
#endif
				layout = viz->Layout();
				__ALFLOGSTRING3("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Id: %d, position %d, layout count %d", windowNodeId, windowAttributes->iOrdinalPosition, layout->Count() );
				TInt pos = windowAttributes->iOrdinalPosition;
				TInt layoutCount = layout->Count();
				
				if (windowAttributes->iOrdinalPosition > layoutCount - 1 )
					{
					__ALFLOGSTRING("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Illegal visual index !");                                            
					pos = layoutCount - 1; // FixMe !!!
					}

				pos = layoutCount - pos - 1;    
				layout->Reorder(*viz, pos);
				}
			else
				{
				__ALFLOGSTRING2("CAlfBridge::HandleReorderWindowL, EAlfDSReorder: Visual not found! Screen: %d, Id: %d ", screenNumber, windowNodeId );    
				}                       
			break;
			}
		default:
			{
			__ALFLOGSTRING("CAlfBridge::HandleReorderWindowL: Unknown window node type received !");    
			break;
			}
		}
  
	iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue); // TODO: Check if really changed   
	}

// ---------------------------------------------------------------------------
// HandlePostCanvasBufferL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandlePostCanvasBufferL( TAlfBridgerData& aData )
	{
	TInt windowGroupNodeId = aData.iInt1;
	TInt windowNodeId = aData.iInt2;
	TAlfWindowCommandBufferAttributes* bufferAttributes = (TAlfWindowCommandBufferAttributes*)(*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = bufferAttributes->iScreenNumber;

	CHuiCanvasVisual* viz = (CHuiCanvasVisual*)FindVisual(windowNodeId);
	
	// For now we omit drawing commands to ALF window group because in some configurations it causes issues
	// TODO: Possible viz->Flags() & EHuiVisualFlagDrawAf.. is not needed anymore. To be checked. Currently this enables floating sprites on the "root visual"
	if (viz && iAlfWindowGroupNodeId != windowGroupNodeId
	        ||  ( viz && viz->Flags() & EHuiVisualFlagDrawAfterOthers )/* THIS LINE IS HACK FOR DRAWING FLOATING SPRITES */ )
		{
#ifdef HUI_DEBUG_TRACK_DRAWING
        TBool tracking( EFalse );
	CHuiControlGroup* controlGroup = FindControlGroup( windowGroupNodeId, screenNumber );
	CAlfScreen* screen = iAlfScreens[screenNumber];
	
	//TInt clientWindowGroupId = FindClientWindowGroupId( screenNumber, *controlGroup );
	// NOTE, THE FOLLOWING WServClientFileName MAY CAUSE DEADLOCK. 
	// THIS DOES NOT HAPPEN IF HUI_DEBUG_TRACK_DRAWING IS NOT ENABLED (DEFAULT)
	TFileName processName;/* = iCommandDebug->WServClientFileName( clientWindowGroupId, CHuiStatic::WsSession() );
	
	if ( viz->Tracking() || 
	        ( processName.Length() > 0 && iCommandDebug->TrackProcess( (HBufC16*)processName.Ptr() ) ) )
            {
            tracking = ETrue; 
            }*/
#endif
		// Now when we receive actual drawing commands, we can set the window as opaque (unless the flags say it isn't opaque).		
	    if (bufferAttributes->iWindowNodeFlags & EAlfWinNodeFlagOpaque)
			{
			viz->SetFlag(EHuiVisualFlagOpaqueHint); 
			}
	    
	    if (!viz->HasCommandBuffers(EFalse))
	        {
            // For performance resons, only set visual tree changed if this 
            // was the first buffer for the window. 
	        iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue);
	        }

		TPtrC8 commands((TUint8*)bufferAttributes->iBuffer, bufferAttributes->iBufferLength);
		if ( bufferAttributes->iEmptyThisBuffer )
			{
			viz->ClearCommandSet();
			}
		// If tracking has been enabled for this CHuiCanvasVisual object, the buffers will be marked for tracking aswell in CHuiCanvasVisual
		switch( bufferAttributes->iPartStatus )
			{
			case TAlfWindowCommandBufferAttributes::EPartComplete:
				{
				viz->AddCommandSetL( commands );
#ifdef HUI_DEBUG_TRACK_DRAWING
				viz->SetTrackCommandSet( processName, tracking );
#endif
				break;
				}
			case TAlfWindowCommandBufferAttributes::ENotComplete: // ENotComplete part should be eventually followed by ELastPart
				{
				viz->AddPartialCommandSetL( commands, EFalse );
				break;
				}
			case TAlfWindowCommandBufferAttributes::ELastPart:
				{
				viz->AddPartialCommandSetL( commands, ETrue );
#ifdef HUI_DEBUG_TRACK_DRAWING
                viz->SetTrackCommandSet( processName, tracking );
#endif
				break;
				}
			default:
			    __ALFLOGSTRING("CAlfBridge::HandlePostCanvasBufferL, EAlfDSPostCanvasBuffer: Unknown iPartStatus !!!!");                                                         	
				USER_INVARIANT();
				break;
			}
		}
	else
		{
		__ALFLOGSTRING3("CAlfBridge::HandlePostCanvasBufferL, EAlfDSPostCanvasBuffer: Visual not found! Screen: %d, Id: %d, GroupId: %d ", screenNumber, windowNodeId, windowGroupNodeId );                                 
		}    
	}

// ---------------------------------------------------------------------------
// SetWindowActiveL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::SetWindowActiveL(CHuiVisual* aVisual, TBool aActive)
    {
    TInt effectIndex;
    if (!HasActiveEffect(aVisual, effectIndex))
        {
        // Does not have effect
        if (aActive)
            {
            aVisual->ClearFlags(EHuiVisualFlagShouldBeHidden | EHuiVisualFlagShouldBeShown);
            aVisual->iOpacity.Set(KAlfVisualDefaultOpacity);
            }
        else
            {
            aVisual->ClearFlags(EHuiVisualFlagShouldBeShown | EHuiVisualFlagShouldBeHidden);
            aVisual->iOpacity.Set(0.0f);
            }
        }
    else
        {
        // Has effect
		// these flags are put to action in RemoveTemporaryPresenterItem
        if (aActive)
            {
			// this prevents windows appearing before their "effected" time
            if (!iEffectCleanupStack[effectIndex].iHideWhenFinished)
                {
                // this is appear effect. Lets show it
                aVisual->iOpacity.Set(KAlfVisualDefaultOpacity);
                }
            else
                {
                aVisual->SetFlag(EHuiVisualFlagShouldBeShown);
                }
            aVisual->ClearFlag(EHuiVisualFlagShouldBeHidden);
            }
        else
            {
			// this prevents windows disappearing before their effect has finished
            aVisual->SetFlag(EHuiVisualFlagShouldBeHidden);
            aVisual->ClearFlag(EHuiVisualFlagShouldBeShown);
            }
        }
    }

// ---------------------------------------------------------------------------
// HandleSetWindowActiveL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetWindowActiveL( TAlfBridgerData& aData )
	{
	TInt windowGroupNodeId = aData.iInt1;
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*)(*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;

    if (windowAttributes->iWindowNodeType == EAlfWinTreeNodeTextCursor && iCursorTimer)
	    {
		if (!windowAttributes->iActive)
		    {
		    iCursorTimer->Cancel();
		    }
        else
            {
            SetCursorTimerL(); // continue with set interwal
            }   
		}


	switch (windowAttributes->iWindowNodeType)
		{
		case EAlfWinTreeNodeGroup:
			{
			CHuiControlGroup* controlGroup = FindControlGroup(windowGroupNodeId,screenNumber);
			if (controlGroup)
				{
				CHuiControl& control = controlGroup->Control(0);
				CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
                // Uses opacity for now
                SetWindowActiveL(layout, windowAttributes->iActive);
                }
            else
                {
				__ALFLOGSTRING("CAlfBridge::HandleSetWindowActiveL, EAlfDSSetWindowActive: EAlfWinTreeNodeGroup not found!");         
				}    
			break;    
			}
		case EAlfWinTreeNodeClient:
		case EAlfWinTreeNodeRoot:
		case EAlfWinTreeNodeAnim:
		case EAlfWinTreeNodeSprite:                            
		case EAlfWinTreeNodeFloatingSprite:
		case EAlfWinTreeNodeTextCursor:
			{                                                        
			CHuiVisual* viz = FindVisual(windowNodeId);
			if (viz)
				{
#ifdef HUI_DEBUG_TRACK_DRAWING
                if ( viz->Tracking() )
                   {
                   RDebug::Print(_L("CAlfBridge::HandleSetWindowActiveL - Tracked visual"));
                   }
#endif
				// Uses opacity for now                            
                SetWindowActiveL(viz, windowAttributes->iActive);
                }
			else
				{
				__ALFLOGSTRING("CAlfBridge::HandleSetWindowActiveL, EAlfDSSetWindowActive: Visual not found!");     
				}    
			break;
			}
		default:
			{
			__ALFLOGSTRING("CAlfBridge::HandleSetWindowActiveL, EAlfDSSetWindowActive: Unknown iWindowNodeType!");                                                         	
			USER_INVARIANT();
			break;                       	        
			}
		}
    iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue);	// TODO: Check if really changed                       
	}


// ---------------------------------------------------------------------------
// HandleSetWindowFlagL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetWindowFlagL( TAlfBridgerData& aData, TInt aOp )
    {
    TInt windowGroupNodeId = aData.iInt1;
    TInt windowNodeId = aData.iInt2;
    TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*)(*iHost)->GetVarDataL( (TInt)aData.iPtr );
    TInt screenNumber = windowAttributes->iScreenNumber;
    TInt windowFlag = windowAttributes->iActive;
    THuiVisualFlags visualFlag = (THuiVisualFlags)0;
    switch(windowFlag)
        {
        case TAlfWindowData::EShouldInactivate:
            {
            visualFlag = EHuiVisualFlagShouldBeHidden;
            break;
            }
        case TAlfWindowData::EShouldDestroy:
            {
            visualFlag = EHuiVisualFlagShouldDestroy;
            break;
            }
        default:;
        }
    
    switch (windowAttributes->iWindowNodeType)
        {
        case EAlfWinTreeNodeGroup:
            {
            CHuiControlGroup* controlGroup = FindControlGroup(windowGroupNodeId,screenNumber);
            if (controlGroup)
                {
                CHuiControl& control = controlGroup->Control(0);
                CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
                // Uses opacity for now                            
                if (aOp == EAlfDSSetWindowFlag)
                    {
                    layout->SetFlag(visualFlag);
                    }
                else
                    {
                    layout->ClearFlag(visualFlag);
                    } 
                }
            else
                {
                __ALFLOGSTRING("CAlfBridge::HandleSetWindowActiveL, EAlfDSSetWindowActive: EAlfWinTreeNodeGroup not found!");         
                }    
            break;    
            }
        case EAlfWinTreeNodeClient:
        case EAlfWinTreeNodeRoot:
        case EAlfWinTreeNodeAnim:
        case EAlfWinTreeNodeSprite:                            
        case EAlfWinTreeNodeFloatingSprite:
        case EAlfWinTreeNodeTextCursor:
            {                                                        
            CHuiVisual* viz = FindVisual(windowNodeId);
            if (viz)
                {
                if (aOp == EAlfDSSetWindowFlag)
                    {
                    viz->SetFlag(visualFlag);
                    if (visualFlag == EHuiVisualFlagShouldDestroy )
                        {
                        if (windowAttributes->iWindowNodeType == EAlfWinTreeNodeTextCursor && iCursorTimer)
                            {
                            iCursorTimer->Cancel();
                            }        
                        RemoveVisual(windowNodeId); // Only the effect will have pointer to this visual from here on
                        }
                    }
                else
                    {
                    viz->ClearFlag(visualFlag);
                    }
                }
            else
                {
                __ALFLOGSTRING("CAlfBridge::HandleSetWindowFlagL, HandleSetWindowFlagL: Visual not found!");     
                }    
            break;
            }
        default:
            {
            __ALFLOGSTRING("CAlfBridge::HandleSetWindowFlagL, HandleSetWindowFlagL: Unknown iWindowNodeType!");                                                          
            USER_INVARIANT();
            break;                                  
            }
        }
    iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue); // TODO: Check if really changed                       
    }

// ---------------------------------------------------------------------------
// InsertImageBrushL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::InsertImageBrushL(CHuiVisual& aVisual, TInt aBitmapHandle)
    {
    // NOTE: We wssume that image brush is always the only brush
    CHuiTexture* texture = CHuiTexture::NewL();
    CleanupStack::PushL(texture);
    THuiImage image(*texture);	        				        				    
    CHuiImageBrush* imageBrush = CHuiImageBrush::NewL(image);				            				        
    imageBrush->SetLayer(EHuiBrushLayerForeground);
    CleanupStack::Pop(texture);

    aVisual.EnableBrushesL(ETrue);
    aVisual.Brushes()->InsertL(0, imageBrush, EHuiHasOwnership);    				        				            
    
    UpdateImageBrushL(aVisual, aBitmapHandle);
    }

// ---------------------------------------------------------------------------
// UpdateImageBrushL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::UpdateImageBrushL(CHuiVisual& aVisual, TInt aBitmapHandle)
    {
    // NOTE: We wssume that image brush is always the only brush with EImageBrush type
    const TInt KAlfCanvasVisualImageBrushIndex = 0;    

	if (aVisual.Brushes() && aVisual.Brushes()->BrushWithTypeCount(CHuiBrush::EImageBrush))
	    {    				            
        CFbsBitmap* bitmap = new (ELeave) CFbsBitmap;
        CleanupStack::PushL(bitmap);
        bitmap->Duplicate(aBitmapHandle);

	    CHuiImageBrush* imageBrush = (CHuiImageBrush*) aVisual.Brushes()->BrushWithTypeAt(CHuiBrush::EImageBrush, KAlfCanvasVisualImageBrushIndex);    	    	    
	    CHuiTexture* texture = (CHuiTexture*) &imageBrush->Image().Texture();            
        
        // Use of direct upload here would give much better performance, but is
        // it too risky ? 
        texture->UploadL(*bitmap, NULL);
        imageBrush->SetChanged();

        CleanupStack::PopAndDestroy(bitmap);    				                
	    }
    }

// ---------------------------------------------------------------------------
// RemoveImageBrushL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::RemoveImageBrushL(CHuiVisual& aVisual)
    {
    // NOTE: We wssume that image brush is always the only brush with EImageBrush type
    const TInt KAlfCanvasVisualImageBrushIndex = 0;
    
    if (aVisual.Brushes() && aVisual.Brushes()->BrushWithTypeCount(CHuiBrush::EImageBrush))
        {
	    CHuiImageBrush* imageBrush = (CHuiImageBrush*) aVisual.Brushes()->BrushWithTypeAt(CHuiBrush::EImageBrush, KAlfCanvasVisualImageBrushIndex);    
        CHuiTexture* texture = (CHuiTexture*) &imageBrush->Image().Texture();
	    THuiImage image;
        imageBrush->SetImage(image);
        delete texture;
        }
    
    if (aVisual.Brushes())
        {
        aVisual.EnableBrushesL(EFalse);				                
        }            
    }


// ---------------------------------------------------------------------------
// HandleSetSurfaceExtentL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetSurfaceExtentL( TAlfBridgerData& aData )
	{
	TInt windowGroupNodeId = aData.iInt1;
	TInt windowNodeId = aData.iInt2;
	TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*)(*iHost)->GetVarDataL( (TInt)aData.iPtr );
	TInt screenNumber = windowAttributes->iScreenNumber;
	// fetch visual
	CHuiCanvasVisual* viz = FindVisual(windowNodeId);

    // We should not do this for alf window, but renderstage does not know if it is
    // handling alf window or other window, so we ignore the request here if needed.
    // TODO: When alf apps work in multiple display, check here for every displays alf groups...
	if (viz && iAlfWindowGroupNodeId != windowGroupNodeId)
		{
        viz->SetLayerExtent(windowAttributes->iSurfaceExtent);
		// Set surface extend area to be cleared with fully transparent color
		// Note: does not support extend that is bigger that the visual
		// if surface extent is (0,0,0,0) then the background item array is reseted 
		// and surface extent will not be cleared.	
		if (windowAttributes->iSurfaceExtent != TRect())
			{
			// Set surface extend area to be cleared with fully transparent color
			// Note: does not support extend that is bigger that the visual
			TRgb fullyTransparentColor(255,0,0,0); // Red but fully transparent. Red color component has been set only for debug purposes, it is not visible.
			viz->SetClearBackground(CHuiDisplay::EClearWithColor);
			viz->SetBackgroundColor(fullyTransparentColor);
			}
		else
			{
			viz->SetClearBackground(CHuiDisplay::EClearNone);
			}		
		}
	else
		{
		if (iAlfWindowGroupNodeId != windowGroupNodeId)
		    __ALFLOGSTRING("CAlfBridge::HandleSetSurfaceExtentL, EAlfDSSetSurfaceExtent: Visual not found!");    
		}                            
    iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue); // TODO: Check if really changed   
	}

// ---------------------------------------------------------------------------
// HandleLayerUsesAlphaFlagChanged
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleLayerUsesAlphaFlagChanged( TAlfBridgerData& aData )
    {
    TInt windowGroupNodeId = aData.iInt1;
    TInt windowNodeId = aData.iInt2;
    TAlfWindowAttributes* windowAttributes = (TAlfWindowAttributes*)(*iHost)->GetVarDataL( (TInt)aData.iPtr );
    TInt screenNumber = windowAttributes->iScreenNumber;
    
    // fetch visual
    CHuiCanvasVisual* viz = (CHuiCanvasVisual*)FindVisual(windowNodeId);

    // We should not do this for alf window, but renderstage does not know if it is
    // handling alf window or other window, so we ignore the request here if needed.
    // TODO: When alf apps work in multiple display, check here for every displays alf groups...
    if (viz && iAlfWindowGroupNodeId != windowGroupNodeId)
        {
        viz->SetLayerUsesAlphaFlag(windowAttributes->iLayerUsesAlphaFlagEnabled);
        }
    else
        {
        if (iAlfWindowGroupNodeId != windowGroupNodeId)
            __ALFLOGSTRING("CAlfBridge::HandleLayerUsesAlphaFlagChanged: Visual not found!");    
        }                            
    iAlfScreens[screenNumber]->SetVisualTreeVisibilityChanged(ETrue); // TODO: Check if really changed   
    }


// ---------------------------------------------------------------------------
// HandleGetNativeWindowDataL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleGetNativeWindowDataL( TAlfBridgerData& aData )
	{
	// Get the data from original Render Stage message
	RMessage2* rsMessage = (RMessage2*)aData.iInt1;
	TAlfNativeWindowData winData;
	TPckg<TAlfNativeWindowData> winDataPckg(winData);
	rsMessage->Read(0, winDataPckg);

	if(winData.iScreenNumber == 0)
		{
		// primary screen
		CHuiDisplay& disp = iHuiEnv->PrimaryDisplay();
		if (disp.NativeWindow())
			{
			winData.iAlfWindowHandle = disp.NativeWindow()->ClientHandle();                    
			winData.iAlfWindowGrpId = disp.NativeWindow()->WindowGroupId();	
			}
		}
	else
		{
		// other than primary screen 
		for (TInt i = 1; i < iAlfScreens.Count(); i++)
			{
			if (iAlfScreens[i]->iScreenNum == winData.iScreenNumber)
				{
				RDrawableWindow* win = iAlfScreens[i]->iCoeControl->DrawableWindow();
				winData.iAlfWindowHandle = win->ClientHandle();
				winData.iAlfWindowGrpId = win->WindowGroupId();
				}
			}
		}

	// write result	
	rsMessage->Write(0, winDataPckg);

	if (winData.iAlfWindowHandle == 0)
		{
		__ALFLOGSTRING("CAlfBridge::HandleGetNativeWindowDataL, EAlfDSGetAlfNativeWindowData. Error: window data not found!");    
		}
	}


void CAlfBridge::PrepareFadeEffects( CHuiCanvasVisual& aVisual )
    {
    TBool faded = aVisual.CanvasFlags() & EHuiCanvasFlagExternalFade;     
    if (faded)
        {
        if (IsFadedByParent( aVisual ))
            {            
            // Faded by parent
            aVisual.SetCanvasFlags(EHuiCanvasFlagExternalFadeByParent);

            // Faded by parent, include to parent effect
            aVisual.ClearCanvasFlags(EHuiCanvasFlagExcludeFromParentEffect);            

            // Does not fade own children because parent already does that.
            aVisual.ClearCanvasFlags(EHuiCanvasFlagExternalFadeToChildren);
            }
        else
            {
            //  Not faded by parent 
            aVisual.ClearCanvasFlags(EHuiCanvasFlagExternalFadeByParent);

            // Not faded by parent, exclude from parent effect
            aVisual.SetCanvasFlags(EHuiCanvasFlagExcludeFromParentEffect);                

            // Does (or does not) fade own children if it can. 
            if (CanFadeChildren(aVisual))
                {
                aVisual.SetCanvasFlags(EHuiCanvasFlagExternalFadeToChildren);
                }
            else
                {
                aVisual.ClearCanvasFlags(EHuiCanvasFlagExternalFadeToChildren);
                }
            }
        }
    else
        {
        // Not faded 
        aVisual.ClearCanvasFlags(EHuiCanvasFlagExternalFadeByParent);

        if (IsNearestParentEffectFade( aVisual ))
            {
            // Exclude from parent effect to avoid getting faded by parent.
            aVisual.SetCanvasFlags(EHuiCanvasFlagExcludeFromParentEffect);
            }
        else
            {
            // By default included into parent effects.  
            aVisual.ClearCanvasFlags(EHuiCanvasFlagExcludeFromParentEffect);
            }
        
        // Does not fade own children because it is not faded itself. 
        aVisual.ClearCanvasFlags(EHuiCanvasFlagExternalFadeToChildren);
        }

    // Handle children
    TInt count = aVisual.Count();
    for (TInt i=0; i<count; i++)
        {
        CHuiCanvasVisual* child = (CHuiCanvasVisual*) (&aVisual.Visual(i));                        
        PrepareFadeEffects(*child);        
        }    
    }

TBool CAlfBridge::LoadFadeEffectsL( CHuiCanvasVisual& aVisual )
    {
    TBool fadeEffectLoadedInsideTree = EFalse;
    
    // Load fade effect (or remove existing)
    fadeEffectLoadedInsideTree |= SetupFadeEffectL(aVisual);
    
    // Handle children
    TInt count = aVisual.Count();
    for (TInt i=0; i<count; i++)
        {
        CHuiCanvasVisual* child = (CHuiCanvasVisual*) (&aVisual.Visual(i));                        
        fadeEffectLoadedInsideTree |= LoadFadeEffectsL(*child);        
        }
    
    return fadeEffectLoadedInsideTree;
    }


TBool CAlfBridge::CanFadeChildren( CHuiCanvasVisual& aParent )
    {
    // NOTE! This function is not yet implemented optimally !!!! 
    //       Below is some initial description how it could behave, but even that has some downsides. 
    //       Ultimate solution which would implement legacy symbian fading functionality and
    //       on the other hand fully effectable solution needs to be developed at some point.
    //        
    //
    // This function shold determine wheter we can fade whole visual tree starting from aParent with just
    // one fade effect. Even if visual tree has non-fading windows, it is possible to use tree fading
    // in some cases where children can be excluded from parent visual effects using EHuiCanvasFlagExcludeFromParentEffect
    // flag. However it changes drawing order of the childern (visuals with EHuiCanvasFlagExcludeFromParentEffect
    // are drawn after other children) so it cannot be used in those cases without side-effect.
    //    
    //
    //  V1 = Visual 1, parent of Visual 2 etc. Index number refers to order how visuals are drawn.
    // (f) = Visal is faded 
    //
    // Example scenario 1) CanFadeChildren(V1) (YES) 
    //                     CanFadeChildren(V2) (YES) (Can fade because faded child is drawn first, but no need because parent can fade as well)
    //
    //       V4     V3(f)
    //         \    /
    //          \  /
    //   V5(f)   V2(f)
    //     \    /
    //      \  /    
    //       V1(f)
    //
    // Example Scenario 2) CanFadeChildren(V1) (NO) (Cant fade because nonfading grandchild draw before faded)
    //                     CanFadeChildren(V2) (NO) (Can't fade children because non-faded child is drawn first)
    //               
    //       V4(f)   V3                     
    //         \    /                       
    //          \  /
    //   V5(f)   V2(f)
    //     \    /
    //      \  /    
    //       V1(f)
    //
    // Example scenario 3) CanFadeChildren(V1) (YES) (Can fade because faded child (V2) is drawn first)
    //                     CanFadeChildren(V2) (YES) (Can fade because all children are faded, but no need because parent can fade as well)
    //               
    //       V4(f)   V3(f)
    //         \    /
    //          \  /
    //   V5     V2(f)
    //     \    /
    //      \  /    
    //       V1(f)
    //
    // Scenario 4) CanFadeChildren(V1) (NO) (Can't fade because non-faded child is drawn first)
    //             CanFadeChildren(V2) (NO) (It would be YES, but V2 it self is not faded -> NO)
    //               
    //       V4(f)   V3(f)
    //         \    /
    //          \  /
    //   V5(f)   V2
    //     \    /
    //      \  /    
    //       V1(f)
    //
    // Scenario 5) CanFadeChildren(V1) (NO) (Can't fade because non-faded child is drawn first)
    //             CanFadeChildren(V2) (NO) (Can't fade children because it does not have children)
    //             CanFadeChildren(V3) (YES) (All children are faded)
    //               
    //       V4(f)   V4(f)
    //         \    /
    //          \  /
    //           V3(f)  V2
    //            \    /
    //             \  /    
    //             V1(f)
    //
    //
    // TODO: Real implementation for algorithm which takes into account the order of non-fading and
    //       fading children. Current implentation has side-effect where drawing order of non-fading
    //       children may get altered. But on the other hand without visual treefader (i.e each visual 
    //       faded with separate effects) there still exists a potential problem with faded transparent 
    //       windows above faded windows (double fade)!
    //
    
    // For now this function just checks if there are children to be faded... 
    return HasActiveFadedChildren( aParent ); 
    }
    

TInt CAlfBridge::RecursiveChildCount( CHuiCanvasVisual& aParent, TInt aCanvasFlags )
    {
    TInt childCount = 0;
    TInt count = aParent.Count();
    for (TInt i=0; i<count; i++)
        {
        CHuiCanvasVisual* child = (CHuiCanvasVisual*) (&aParent.Visual(i));        
        if (aCanvasFlags)
            {
            if (child->CanvasFlags() & aCanvasFlags)
                {
                childCount++;
                }
            }
        else
            {            
            childCount++;
            }
        childCount += RecursiveChildCount( *child, aCanvasFlags );        
        }
    return childCount;
    }

TBool CAlfBridge::IsNearestParentEffectFade( CHuiCanvasVisual& aVisual )
    {
    TBool nearestParentEffectFade = EFalse;
    CHuiCanvasVisual* parent = (CHuiCanvasVisual*) (aVisual.Layout()); 
    while (parent)
        {
        if (parent->Effect())
            {
            nearestParentEffectFade |= (parent->Effect() && (parent->Effect()->EffectFlags() & KHuiFadeEffectFlag));    
            return nearestParentEffectFade;            
            }        
        parent = (CHuiCanvasVisual*) (parent->Layout());
        }
    return EFalse;
    }


TBool CAlfBridge::IsFadedByParent( CHuiCanvasVisual& aVisual )
    {
    CHuiCanvasVisual* parent = (CHuiCanvasVisual*) (aVisual.Layout()); 
    while (parent)
        {
        TInt flags = parent->CanvasFlags();
        if ((flags & EHuiCanvasFlagExternalFade) && (flags & EHuiCanvasFlagExternalFadeToChildren))
            {
            return ETrue;
            }        
        parent = (CHuiCanvasVisual*) (parent->Layout());
        }
    return EFalse;
    }

TBool CAlfBridge::HasActivePaintedAreas( CHuiCanvasVisual& aVisual, TBool aIncludeChildren )
    {
    TBool visualHasPaintedAreas = aVisual.PaintedAreaCount() > 0;         
    if (!visualHasPaintedAreas && aIncludeChildren)
        {
        TInt count = aVisual.Count();        
        for (TInt i=0; i<count; i++)
            {
            CHuiCanvasVisual* child = (CHuiCanvasVisual*) (&aVisual.Visual(i)); 
            TBool childIsActive = !(child->Flags() & EHuiVisualFlagInactive);            
            if (childIsActive && child->PaintedAreaCount())
                {
                visualHasPaintedAreas = ETrue;
                break;
                }        
            }    
        }
    return visualHasPaintedAreas;
    }

TBool CAlfBridge::HasActiveFadedChildren( CHuiCanvasVisual& aVisual )
    {
    TBool has = EFalse;
    TInt count = aVisual.Count();        
    for (TInt i=0; i<count; i++)
        {
        CHuiCanvasVisual* child = (CHuiCanvasVisual*) (&aVisual.Visual(i)); 
        TBool active = !(child->Flags() & EHuiVisualFlagInactive);            
        TBool faded = child->CanvasFlags() & EHuiCanvasFlagExternalFade; 
        
        if (active && faded && child->PaintedAreaCount())
            {
            has = ETrue;
            break;
            }        
        }    
    return has;
    }


// ---------------------------------------------------------------------------
// SetupFadeEffectL
//
// NOTE: This method gets called very often, so we should not do anything time
//       consuming here (unless we really need to).
//
// ---------------------------------------------------------------------------
// 
TBool CAlfBridge::SetupFadeEffectL( CHuiCanvasVisual& aVisual )
    {
    TBool didFadeEffectLoad = EFalse;
    
    TBool faded = (aVisual.CanvasFlags() & EHuiCanvasFlagExternalFade);

    // Just in case, check if we are alrady faded to avoid unnecassary effect loadings.
    TBool alreadyFaded = aVisual.Effect() && (aVisual.Effect()->EffectFlags() & KHuiFadeEffectFlag);
        
    TBool fadesChildren = EFalse; 
    
    if (faded)
        {                
        fadesChildren = (aVisual.CanvasFlags() & EHuiCanvasFlagExternalFadeToChildren);
        
        // Inactive visuals are not faded.
        TBool visualIsActive = !(aVisual.Flags() & EHuiVisualFlagInactive);
        
        // Avoid interrupting other effects. 
        TBool otherEffectActive = aVisual.Effect() && !(aVisual.Effect()->EffectFlags() & KHuiFadeEffectFlag);

        // Check if we really need to fade. Note the order of if-conditions, fastest checks first to optimize performance.
        if (visualIsActive && !alreadyFaded && !otherEffectActive && !IsFadedByParent(aVisual) && HasActivePaintedAreas(aVisual, fadesChildren))
        	{        
        	CHuiFxEffect* effect = NULL;
        	CHuiFxEngine* engine = iHuiEnv->EffectsEngine();

            if (engine && iFadeEffectFile )
                {
                 __ALFLOGSTRING1( ">> Using cached fade effect file name: %S", iFadeEffectFile );
                TInt err = 0;
                // CHuiFxParser sets the effect to visual if loading succeeds.
                TInt effectFlags = 0;
                effectFlags |= KHuiFadeEffectFlag;
                effectFlags |= KHuiFxEffectDisableMarginsFlag; // Margins cannot safely be used in fade usecase, artefacts may appear depending on window location in window tree        			                    

                // For top level canvas visuals (window group visuals) disable background for 
                // performance reasons (in case canvas visual is not opaque).
                if (!aVisual.Layout())
                    {
                    effectFlags |= KHuiFxDisableBackground;
                    }

                if (fadesChildren)
                    {
                    /*
                     TInt children = RecursiveChildCount( aVisual, 0 );
                     TInt faded = RecursiveChildCount( aVisual, EHuiCanvasFlagExternalFade );
                     TInt fadedbyparent = RecursiveChildCount( aVisual, EHuiCanvasFlagExternalFadeByParent );
                     TInt excludedfromparenteffect = RecursiveChildCount( aVisual, EHuiCanvasFlagExcludeFromParentEffect );
                     RDebug::Print(_L("CAlfBridge::SetupFadeEffectL - faded parent has %i children"), children);
                     RDebug::Print(_L("CAlfBridge::SetupFadeEffectL - faded parent has %i faded children"), faded);
                     RDebug::Print(_L("CAlfBridge::SetupFadeEffectL - faded parent fades %i children"), fadedbyparent);
                     RDebug::Print(_L("CAlfBridge::SetupFadeEffectL - faded parent has %i children which are excluded from parent fx"), excludedfromparenteffect);
                     */
                    }
                else
                    {
                    // All children in the tree are not faded, do not apply effect on children.
                    effectFlags |= KHuiFxEffectExcludeChildrenFlag;
                    //RDebug::Print(_L("CAlfBridge::SetupFadeEffectL - no children faded by parent"));
                    }
                TRAP( err, engine->LoadEffectL(*iFadeEffectFile, effect, aVisual.Effectable(), NULL, NULL, 0, effectFlags ) );
                didFadeEffectLoad = ETrue;
        		}
        	}
        }
    else
        {
        // remove only an old fade effect, leave any others intact
        if (alreadyFaded)
            {
            aVisual.SetEffect( NULL );
            alreadyFaded = EFalse;
            }
        }
    
    // If we did load and fade children we must re-prepare the flags again
    // Maybe there is more elegant way to avoid this. 
    if (didFadeEffectLoad && fadesChildren)
        {
        PrepareFadeEffects( aVisual );
        }
    
    return (didFadeEffectLoad || alreadyFaded);
    }


// ---------------------------------------------------------------------------
// HandleSetFadeEffect
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetFadeEffectL( TAlfBridgerData& aData )
    {
    TInt windowNodeId = aData.iInt1;  
    TBool faded = aData.iInt2;
    MWsWindowTreeNode::TType type = (MWsWindowTreeNode::TType)(TInt)aData.iPtr;
    CHuiVisual* viz = NULL;
    if (type != MWsWindowTreeNode::EWinTreeNodeGroup)
        {
        viz = (CHuiVisual*)FindVisual(windowNodeId);
        }
    else
        {
        CHuiControlGroup* cg = FindControlGroup(windowNodeId, 0); // TODO: Screen            
        if (cg) 
            {
            CHuiControl& control = cg->Control(0);
            viz = &control.Visual(0);
            }        
        }
    
    if ( viz )
        {
        CHuiCanvasVisual* canvasviz = (CHuiCanvasVisual*)viz;        
        if (faded)
            {
            canvasviz->SetCanvasFlags(EHuiCanvasFlagExternalFade);
            }
        else
            {
            canvasviz->ClearCanvasFlags(EHuiCanvasFlagExternalFade);
            }        
        iAlfScreens[0]->SetVisualTreeVisibilityChanged(ETrue); // TODO: Screen 
        }
    }

void CAlfBridge::HandleSetLayoutSwitchEffectL()
    {
    ClearCanvasVisualCommandSets(EFalse); 
    iLayoutSwitchEffectCoordinator->BeginLayoutSwitch();
    }

TInt Blink(TAny* aVisual)
    {
    CHuiVisual* visual = (CHuiVisual*)aVisual;
    if (visual->iOpacity.Now() > 0.01 ) // kind of an epsilon
        {
        visual->iOpacity.Set(0);
        }
    else
        {
        visual->iOpacity.Set(1);
        }

    return ETrue; // call me again
    }                          
    
void CAlfBridge::SetCursorTimerL(TUint aTime, CHuiVisual* aCursor)
    {
    if (aTime)
        {
        iCursorInterval = aTime;
        }
        
    if (aCursor)    
        {
        iCursorVisual = aCursor;
        }   
         
    if (iCursorInterval && iCursorVisual)        
        {
        if (iCursorTimer)
            {
            iCursorTimer->Cancel();
            }
    
        if (!iCursorTimer)
            {
            iCursorTimer = CPeriodic::NewL(CActive::EPriorityHigh);
            }
    
        iCursorTimer->Start(iCursorInterval, iCursorInterval, TCallBack(Blink, aCursor));                
        }
    }        
    
// ---------------------------------------------------------------------------
// HandleSetCursorDataL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::HandleSetCursorDataL( TAlfBridgerData& aData )
    {
    TInt windowNodeId = aData.iInt2;
    
    TAlfCursorDataBufferAttributes* windowAttributes = (TAlfCursorDataBufferAttributes*) (*iHost)->GetVarDataL( (TInt)aData.iPtr );
    CHuiVisual* viz = (CHuiVisual*)FindVisual(windowNodeId);
    if (viz)
        {
        viz->SetFlags(windowAttributes->iFlags);
        SetCursorTimerL(windowAttributes->iFlashInterval, viz);
        }
    else
        {
        __ALFLOGSTRING1("CAlfBridge::HandleSetCursorDataL - WARNING! Cursor node 0x%x not found!", windowNodeId);
        }
    }

// ---------------------------------------------------------------------------
// HandleSetNodeTracking
// ---------------------------------------------------------------------------
// 
#ifdef HUI_DEBUG_TRACK_DRAWING
void CAlfBridge::HandleSetNodeTracking( TAlfBridgerData& aData )
    {
    TInt windowNodeId = aData.iInt1;
    CHuiCanvasVisual* viz = (CHuiCanvasVisual*)FindVisual(windowNodeId);
    if ( aData.iInt2 )
        {
        viz->SetTracking( aData.iInt2 );
        }
#else
void CAlfBridge::HandleSetNodeTracking( TAlfBridgerData& )
    {
#endif
    }
	
void RecursiveStoreRenderBufferL(CHuiVisual *aVisual)
    {
    CHuiCanvasVisual *canvasvisual = dynamic_cast<CHuiCanvasVisual*>(aVisual);
    if (canvasvisual && canvasvisual->Layout()) 
        {
        canvasvisual->StoreRenderBufferL();
        }

    TInt c = aVisual->Count();
    for(int i=0;i<c;i++)
        {
        CHuiVisual &vis = aVisual->Visual(i);
        RecursiveStoreRenderBufferL(&vis);
        }
    }

void StoreRenderBufferStartL(CHuiLayout *aLayout)
    {
    // assumes that the layout takes full screen area.
    CHuiRenderPlugin& renderplugin = CHuiStatic::Renderer();
    CHuiCanvasGc *canvasGc = renderplugin.CreateCanvasGcL();
    CleanupStack::PushL(canvasGc);
    
    CHuiCanvasRenderBuffer *renderBuffer;
    renderBuffer = canvasGc->CreateRenderBufferL(TSize(0,0));
    CleanupStack::PushL(renderBuffer);
    renderBuffer->InitializeL(CHuiStatic::Env().Display(0).VisibleArea().Size());
    renderBuffer->Copy(TPoint(0,0));    
    CleanupStack::Pop(renderBuffer);
    aLayout->SetStoredRenderBuffer(renderBuffer); // moves ownership

    CleanupStack::PopAndDestroy();
    }
TBool NeedsStoredBuffers(CHuiFxEngine *aEngine, const TDesC &aFileName)
    {
    return aEngine->FxmlUsesInput1(aFileName);
    }
	
TBool CAlfBridge::HandleGfxEventL(CFullScreenEffectState& aEvent, CHuiLayout* aToLayout, CHuiLayout *aFromLayout)
    {
    TInt err = KErrNone;
    TBool failed = EFalse;
    
    // Check if there is an effects engine in HuiEnv
    CHuiFxEffect* effect = NULL;
    // We need to pass the filenamerta from the transeffect plugin that handles the controls
    // that define which effect is used for the selected skin or the selected application
    // For full screen effects the skin should determine the effect, or there should be
    // some default effects.
    
    CHuiFxEngine* engine = NULL;
    // engine is not owned by us, it is a member of HuiEnv
    engine = iHuiEnv->EffectsEngine();

    if ( engine )
        { 
        switch(aEvent.iOperation)
            {
            case MAlfGfxEffectPlugin::EBeginFullscreen:
                {
                aToLayout->SetStoredRenderBufferModificationsEnabled(ETrue);
                TBool needStoredBuffers = NeedsStoredBuffers(engine, *aEvent.iEffectName);
                if (needStoredBuffers)
                    {
                    TRAP(err,StoreRenderBufferStartL(aToLayout));
                    if (err == KErrNone)
                        {
                        aToLayout->SetFreezeState(ETrue);
                        }
                    else
                        {
                        return ETrue; // failed, effect will be canceled
                        }
                    }

                switch(aEvent.iAction)
                    {
                    case AknTransEffect::EApplicationStart:
                    case AknTransEffect::EApplicationStartRect:
                        {
                        aToLayout->iOpacity.Set(0.0f);    // these are meant for applications that yet dont have anything to show
                        FreezeLayoutUntilEffectDestroyedL(aFromLayout, aEvent.iHandle);
                        break;
                        }
                    case AknTransEffect::EApplicationStartSwitch:
                    case AknTransEffect::EApplicationStartSwitchRect:
                        {
                        aToLayout->iOpacity.Set(0.0f);    // this is meant for applications that are in the background.
                        FreezeLayoutUntilEffectDestroyedL(aFromLayout, aEvent.iHandle);
                        break;
                        }

                    case AknTransEffect::EApplicationExit:
                        {
                        // The effect should start when the new view is ready,
                        // but we have no signal telling us that, so we just have to do our best

                        // Effect end observer is given to engine in LoadEffectL
                        // It will be set to effect there and called when the effect ends or is deleted

                        // The layout should be visible at this time. if not, then this is assumed
                        // as effect to an background application and ignored.
                        if (aToLayout->Effect())
                            {
                            // effect on a layout must be an application start effect. 
                            // External content visual is not used for that.
                            __ALFFXLOGSTRING2("CAlfBridge::HandleGfxEventL - Found effect on layout 0x%x. Removing effect 0x%x", aToLayout, aToLayout->Effect());
                            aToLayout->SetEffect(NULL);
                            }
                        if (!(aToLayout->Flags() & EHuiVisualFlagInactive))
                            {
                            // this will tag the visual, that they cannot be hidden by HandleVisualVisibility
                            // Initialize layout for the exit effect  
                            iLayoutInitializedForExitEffect = SetupEffectLayoutContainerL(aEvent.iHandle, aToLayout, ETrue);
                            aEvent.iSetupDone = iLayoutInitializedForExitEffect; 
                            }
                        else
                            {
                            iLayoutInitializedForExitEffect = EFalse;
                            }
                         return failed;
                         }
                    default:
                        break;
                    }
                break;
                }
            case MAlfGfxEffectPlugin::EEndFullscreen:
                {
                TBool layoutEffectable(EFalse);
                if (aEvent.iAction != 5000)
                    {
                    if ( aEvent.iAction != AknTransEffect::EApplicationExit && aToLayout->Flags() & EHuiVisualFlagInactive)
                        {
                        aToLayout->iOpacity.Set(1.0f);
                        }
                        
                    if (aToLayout)
                        {
                        aToLayout->iOpacity.Set(1.0f);
                        __ALFFXLOGSTRING1("HandleGfxEventL - loading effect, handle %d", aEvent.iHandle );
                        if (aEvent.iAction == AknTransEffect::EApplicationExit)
                            {
                        	// Exit effect was initialized earlier with EBeginFullscreen event
						    layoutEffectable = iLayoutInitializedForExitEffect;
                            }
                        else
                        	{
                            // add visuals to visual cleanupstack
                            aToLayout->SetStoredRenderBufferModificationsEnabled(EFalse);
                            layoutEffectable = SetupEffectLayoutContainerL(aEvent.iHandle,aToLayout, EFalse);
                            aEvent.iSetupDone = layoutEffectable; 
                            aToLayout->SetStoredRenderBufferModificationsEnabled(ETrue);
                            }

                        if (layoutEffectable)
                            {
                            if (aEvent.iRect != TRect())
                                {
                                TRAP( err, engine->LoadGroupEffectL( *aEvent.iEffectName, effect, aToLayout->Effectable(), engine->ActiveGroupEffect(), &aEvent.iRect, this, aEvent.iHandle, KHuiFxDelayRunUntilFirstFrameHasBeenDrawn ));
                                }
                            else
                                {
                                TRAP( err, engine->LoadGroupEffectL( *aEvent.iEffectName, effect, aToLayout->Effectable(), engine->ActiveGroupEffect(), NULL, this, aEvent.iHandle, KHuiFxDelayRunUntilFirstFrameHasBeenDrawn ) );
                                }
                            effect = NULL;
                            // only use the effect if the effect file was correctly parsed
                            if (err != KErrNone)
                                {
                                // visuals added to "active effect visual" stack, but they wont be used, because effect loading has failed. cleanup.
                                RemoveTemporaryPresenterVisual(NULL, aEvent.iHandle);
                                aToLayout->SetEffect(NULL);
                                failed = ETrue;
                                }
                            }
                        else
                            {
                            failed = ETrue;                            
                            __ALFFXLOGSTRING2("CAlfBridge::HandleGfxEventL - Effect layout initialization failed. Skipping effect handle: %d, Visual: 0x%x", aEvent.iHandle, aToLayout);
                            }
                        }
                    }
                break;
                }
            default:
                {
                // just in case...
                break;
                }
            }
        }
    iLastAction = aEvent.iAction; // TODO: useless?
    return failed;
    }

void CAlfBridge::FreezeLayoutUntilEffectDestroyedL(CHuiLayout* aLayout, TInt aHandle)
    {
    if (aLayout)
        {
		TRAPD(err, StoreRenderBufferStartL(aLayout));
		if (err == KErrNone)
			{
            // Freeze only, if buffer was reserved succesfully 
            aLayout->SetFreezeState(ETrue);
        	TBool itemsDestroyed;
    	    AddEffectItemL(aHandle, aLayout, NULL, NULL, EFalse, itemsDestroyed, EFalse);
	        iFullScreenEffectData->iAppStartScreenshotItemHandle = aHandle;
			}
        }
    }

void CAlfBridge::HandleGfxStopEvent( TBool aClientRequest )
    {
    __ALFFXLOGSTRING("CAlfBridge::HandleGfxStopEvent BEGIN");
    if (!iFullScreenEffectData)
        {
        __ALFFXLOGSTRING("CAlfBridge::HandleGfxStopEvent - END: none");
        return;
        }
    
    CFullScreenEffectState* fxData = iFullScreenEffectData;
    iFullScreenEffectData = NULL;
    CleanupStack::PushL( fxData );
    
     __ALFFXLOGSTRING2(" - handle: %d, toAppUid: 0x%x", fxData->iHandle, fxData->iToAppId);
    
    // clean effects with this handle       
    RemoveTemporaryPresenterVisual(NULL, fxData->iHandle);
    // this was abort, so we might have received earlier event hiding this window. Here we'll bring it 
    // back
    if (fxData->iToAppId && fxData->iToAppId != KErrNotFound)
        {
        RemoveEffectFromApp(fxData->iToAppId);
        RemoveEffectFromApp(fxData->iFromAppId);
        }
    else
        {
        // abort ALL effects
        RemoveAllTemporaryPresenterVisuals();
        }
    
    iHuiEnv->ContinueRefresh();
    
    if ( !aClientRequest )
        {
        // Aborted errornously, signal client side
        RProperty::Set( KPSAlfDomain, KAlfTransitionStatus, fxData->iCompletionHandle );
        }
    
    CleanupStack::PopAndDestroy( fxData );
    __ALFFXLOGSTRING("CAlfBridge::HandleGfxStopEvent - END");
    }

void CAlfBridge::RemoveEffectFromApp(TInt aAppUid)
    {
    if(aAppUid <= 0)
        {
        return;
        }
    CHuiControlGroup* group = FindControlGroupByAppId(aAppUid);
    if (group)
        {
        CHuiControl& control = group->Control(0);
        CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
    
        TInt handle = FindEffectHandle(layout);
        if (handle != KErrNotFound)
            {
            __ALFFXLOGSTRING2("CAlfBridge::HandleGfxStopEvent - layout visual: 0x%x ; handle: %d ", layout, handle);
            RemoveTemporaryPresenterVisual(NULL, handle);
            }
        layout->iOpacity.Set(1.0f); 
        }
    }

CAlfBridge::CEffectState::CEffectState()
    {
    // CBase clears all variables
    }

CAlfBridge::CEffectState::~CEffectState()
    {
    delete iEffectName;
    }

void CAlfBridge::CEffectState::ResolveFileNameL(RMemReadStream& aStream)
    {
    HBufC* effectDirectory = HBufC::NewLC(aStream, 256);
    HBufC* effectFile = HBufC::NewLC(aStream, 256);

    // Add one extra because we want to be able to append a number to the filename
    HBufC* effectFullName = HBufC::NewL(effectDirectory->Des().Length()
            + effectFile->Des().Length() + 1);
    CleanupStack::PushL(effectFullName);

    effectFullName->Des().Copy(*(effectDirectory));
    effectFullName->Des().Append(*(effectFile));
    delete iEffectName;
    iEffectName = effectFullName; // ownership transferred
    CleanupStack::Pop(effectFullName);
    CleanupStack::PopAndDestroy(2, effectDirectory);
    }

void CAlfBridge::CFullScreenEffectState::ConstructL(
        TInt aAction,
        RMemReadStream& aStream)
    {
    iAction = aAction;

    iHandle = aStream.ReadInt32L();

    iType = aStream.ReadInt32L();
    iWg1 = aStream.ReadInt32L();
    iWg2 = aStream.ReadInt32L();
    iToAppId = aStream.ReadInt32L();
    iFromAppId = aStream.ReadInt32L();

    if (iType == AknTransEffect::EParameterType)
        {
        /*screen1 =*/aStream.ReadInt32L();
        /*screen2 =*/aStream.ReadInt32L();
        }
    /*TInt flags =*/
    aStream.ReadInt32L();
    iRect.iTl.iX = aStream.ReadInt32L();
    iRect.iTl.iY = aStream.ReadInt32L();
    iRect.iBr.iX = aStream.ReadInt32L();
    iRect.iBr.iY = aStream.ReadInt32L();

    ResolveFileNameL(aStream);

    iCompletionHandle = iHandle;
    }

void CAlfBridge::CControlEffectState::ConstructL(TInt aAction,
        RMemReadStream& aStream)
    {
    iAction = aAction;
    TInt operation = aStream.ReadInt32L();
    iHandle = aStream.ReadInt32L();
    iClientHandle = aStream.ReadInt32L();
    iClientGroupHandle = aStream.ReadInt32L();
    TInt screenNumber = aStream.ReadInt32L(); // this has always value 0 
    // Are Symbian full filename+directory combinations still max 256 characters long?
    ResolveFileNameL(aStream);
    }

// ---------------------------------------------------------------------------
// HandleGfxEffectsL
// ---------------------------------------------------------------------------
//

void CAlfBridge::HandleGfxEffectsL( TAlfBridgerData data )
    {
    // This method is called when "Begin fullscreen" and "End fullscreen" are
    // invoked. Data in "Begin fullscreen" is used, "End fullscreen" and
    // "Abort fullscreen" (HandleStopGfxEffectsL) are just signals.
    // As a general limitation, there can be exactly one fullscreen effect
    // ongoing at once.
    
    TInt action = data.iInt1;
    TInt length = data.iInt2;
    __ALFFXLOGSTRING1("CAlfBridge::HandleGfxEffectsL - BEGIN (bridge data %d)", (TInt)data.iPtr);
    void* bridgeBuffer = (void*) (*iHost)->GetEffectsDataL( (TInt)data.iPtr );    
    RMemReadStream stream( bridgeBuffer, length );
    
    // operation tells if this is begin full screen or end full screen
    TInt operation = stream.ReadInt32L();
    
    if ( operation == MAlfGfxEffectPlugin::EBeginFullscreen )
        {
        if ( !iFullScreenEffectData || !iFullScreenEffectData->iSetupDone )
            {
            // No fullsceen effect ongoing or fullscreen effect hasn't yet been set up, 
            // so we can initialize iFullScreenEffectData from stream.
            
            __ALFFXLOGSTRING("HandleGfxEffectsL - fresh start");
            
            CFullScreenEffectState* fxData = new (ELeave) CFullScreenEffectState;
            CleanupStack::PushL( fxData );
            fxData->ConstructL( action, stream );
            CleanupStack::Pop( fxData );
        	
			// the effect handle of freezed layout (iAppStartScreenshotItemHandle) must match the actual
			// effect handle that is run. Only then frozen application can be freed at the end of the effect
			if (iFullScreenEffectData)
			{
            	for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
            	{
               	 TEffectCleanupStruct& effectItem = iEffectCleanupStack[i];
               	 if (iFullScreenEffectData->iAppStartScreenshotItemHandle == effectItem.iHandle)
               	     {
               	     effectItem.iHandle = fxData->iHandle;
               	     }
               	}
			}
            
            if (iFullScreenEffectData && iFullScreenEffectData->iToAppId != fxData->iToAppId)
                {
				__ALFFXLOGSTRING("CAlfBridge::HandleGfxEffectsL - WARNING - Another fullscreen effect to different app. Deleting the previous ongoing effect"); 
                RemoveEffectFromApp(iFullScreenEffectData->iToAppId);// Fullscreen effect for another app has arrived, and the previous has not finished and abort effect was not called.
                RemoveEffectFromApp(iFullScreenEffectData->iFromAppId);
                // Fullscreen effect for another 
                }
            
            delete iFullScreenEffectData;
            iFullScreenEffectData = fxData;
            iFullScreenEffectData->iAppStartScreenshotItemHandle = fxData->iHandle;
            
            stream.Release();
            }
        else
            {
            // Fullscreen effect is ongoing. We could either use new data
            // and abort the ongoing effect, or just continue ongoing.
            // For now, we continue ongoing.
            
            __ALFFXLOGSTRING("HandleGfxEffectsL - END: ongoing");
            
            // Client expects completion to be signalled with this handle.
            iFullScreenEffectData->iCompletionHandle = stream.ReadInt32L();
            
            stream.Release();           
            return ; 
            }
        }
    else // MAlfGfxEffectPlugin::EEndFullscreen
        {
        stream.Release();

        // End fullscreen signal received. We proceed only if there is really
        // effect ongoing and "end fullscreen" hasn't already been processed.
        
        if ( !iFullScreenEffectData || iFullScreenEffectData->iEndFullScreen )
            {
            __ALFFXLOGSTRING("CAlfBridge::HandleGfxEffectsL - END: fx ready");
            return;
            }

        __ALFFXLOGSTRING("HandleGfxEffectsL - process end");
        iFullScreenEffectData->iEndFullScreen = ETrue;
        }

    CFullScreenEffectState* fxData = iFullScreenEffectData;
    fxData->iOperation = operation;
    fxData->iWaitingWindowGroup = EFalse;

    __ALFFXLOGSTRING3("Operation: %d, handle: %d, type: %d", operation, fxData->iHandle, fxData->iType);
    __ALFFXLOGSTRING2("wg1: %d, wg2: %d", fxData->iWg1, fxData->iWg2);

    // find root nodes and attach effects to them
    // First we need a windowgroup node id. So far we have a list of window ids

    // wg2 is the window group that is supposed to disappear from view
    // when a new application starts. We don't have any use for it now...

    // This is the group that is disappearing
    // Currently we don't add an effect to it.

    // TODO: when ids available from wserv...
    // if ( appUid2 )
    //{
    //	 group2 = FindControlGrouAppUId( appUid2, screen2, &alfGroup );
    // }
    //if ( toAppId2 )
    //    {
    //    group2 = FindControlGroupByAppId(toAppId2);
    //    }
    //if ( wg2 && wg2 != KErrNotFound )
    //    {
    //        group2 = FindControlGroupByWindowGroupId( wg2, screen2 );
    //        }
    //    if ( group2 )
    //        {
    //        CHuiControl& control = group2->Control(0);
    //        layout2 = (CHuiLayout*)&control.Visual(0);
    //        }

    // This effect is triggered either by BeginFullScreen or by EndFullScreen
    // depending on if we have an application that is already running or not

    //    TAlfControlGroupEntry* alfGroup = NULL;
    // TODO: 
    //wg1 = (*iHost)->FindWgForAppUid(TUid::Uid(toAppId1));
    //if (!wg1 && action != AknTransEffect::EApplicationExit )
    // 	{
    // 	// window group is not available yet, but it will be created in short while.
    //  	iEffectWaitingWindowgroup.Append(toAppId1);
    //  	}
    // TODO: when ids available from wserv...
    // if ( appUid1 )
    //{
    //	 group1 = FindControlGrouAppUId( appUid1, screen1, &alfGroup );
    // }

    TBool failed = EFalse;
    if (fxData->iToAppId && fxData->iToAppId != KErrNotFound)
        {        
        CHuiControlGroup* toGroup = NULL;
        CHuiLayout* toLayout = NULL; 
        toGroup = FindControlGroupByAppId(fxData->iToAppId);

        CHuiControlGroup* fromGroup = NULL;
        CHuiLayout* fromLayout = NULL; 
        fromGroup = FindControlGroupByAppId(fxData->iFromAppId);

        if (!toGroup) // group has been destroyed and moved to effectControlGroup for waiting the application exit effect EndFullScreen trigger 
            {
            toLayout = FindLayoutByEffectHandle(fxData->iHandle);
            }
        else
            {
            CHuiControl& control = toGroup->Control(0);
            toLayout = (CHuiLayout*)&control.Visual(0);
            }
        if (fromGroup)
            {
            CHuiControl& control2 = fromGroup->Control(0);
            fromLayout = (CHuiLayout*)&control2.Visual(0);
            }
        
        if (toLayout)
            {
            failed = HandleGfxEventL(*fxData, toLayout, fromLayout);
            }
        else
            {
            __ALFFXLOGSTRING("HandleGfxEffectsL - waiting window group");            
            fxData->iWaitingWindowGroup = ETrue;
            }
        }

    if ( failed )
        {
        // Effect failed, reset state
        HandleGfxStopEvent( EFalse ); // destroys iFullScreenEffectData
        }
    
    for (TInt i = 0; i < iAlfScreens.Count(); i++)
        {
        iAlfScreens[i]->iDisplay->SetDirty();
        }
    iAlfScreens[0]->iVisualTreeVisibilityChanged = ETrue;
    iHuiEnv->ContinueRefresh();

    __ALFFXLOGSTRING("CAlfBridge::HandleGfxEffectsL - END");
    }

// TODO: add effect type to effect struct. remove all fullscreen effects. currently some might hang around
void CAlfBridge::HandleGfxStopEffectsL(TAlfBridgerData data)
    {
    // Fullscreen effect is aborted. Clear the state. 
    
    //TInt action = data.iInt1;
    TInt length = data.iInt2;
    __ALFFXLOGSTRING1("CAlfBridge::HandleGfxStopEffectsL - Reading bridge data %d", (TInt)data.iPtr);
    void* bridgeBuffer = (void*) (*iHost)->GetEffectsDataL( (TInt)data.iPtr );    
    RMemReadStream stream( bridgeBuffer, length );
    
    TInt operation = stream.ReadInt32L();
    TInt handle = stream.ReadInt32L();
    TInt type = stream.ReadInt32L();
    TInt wg1 = stream.ReadInt32L();
    TInt wg2 = stream.ReadInt32L();
    TInt toAppUi = stream.ReadInt32L();
    stream.Release();

    // operation tells if this is abort full screen or something else
    // When this function is used to abort control transitions, all data is 0s
    if ( iFullScreenEffectData )
        {
        __ALFFXLOGSTRING("CAlfBridge::HandleGfxStopEffectsL - kill fullscreen");        
        HandleGfxStopEvent( ETrue );
        }
    
    if ( !toAppUi )
        {
        __ALFFXLOGSTRING("CAlfBridge::HandleGfxStopEffectsL - kill all");
        RemoveAllTemporaryPresenterVisuals();
        iHuiEnv->ContinueRefresh();
        }
    __ALFFXLOGSTRING("CAlfBridge::HandleGfxStopEffectsL - end");
    }

void CAlfBridge::HandleRegisterEffectL( TAlfBridgerData data )
    {     
    TInt action = data.iInt1;
    TInt length = data.iInt2;    
    
    void* bridgeBuffer = (void*) (*iHost)->GetEffectsDataL( (TInt)data.iPtr );    
    RMemReadStream stream( bridgeBuffer, length );
  
   
    HBufC* effectDirectory = HBufC::NewL( stream, 256 );
    CleanupStack::PushL( effectDirectory );
    HBufC* effectFile = HBufC::NewL( stream, 256 );
    CleanupStack::PushL( effectFile );
    HBufC* effectFullName = HBufC::NewL( effectDirectory->Des().Length() + effectFile->Des().Length() );
    CleanupStack::PushL( effectFullName );
    effectFullName->Des().Copy( *effectDirectory );
    effectFullName->Des().Append( *effectFile );  
    
    stream.Release();
    __ALFFXLOGSTRING2("CAlfBridge::HandleRegisterEffectL - dir: %S, file: %S", effectDirectory, effectFile);
    DoRegisterEffectL(*effectFullName, action);
    
    if (action == KFadeAction)
        {
        DoSetCachedFadeEffectL();
        }
    
    CleanupStack::PopAndDestroy(effectFullName);
    CleanupStack::PopAndDestroy(effectFile);
    CleanupStack::PopAndDestroy(effectDirectory);
    }

void CAlfBridge::DoRegisterEffectL(const TDesC& aFilename, TInt aAction)
    {
    TRegisteredEffectsStruct newEntry;
    newEntry.iAction = aAction;
    newEntry.iEffectFile = HBufC::NewL(aFilename.Length());
    newEntry.iEffectFile->Des().Append(aFilename);
    iAlfRegisteredEffects.AppendL(newEntry);

    CHuiFxEngine* engine = NULL;
    engine = iHuiEnv->EffectsEngine();
    if (engine)
        {
        engine->RegisterEffectL(aFilename);
        }
    }

CHuiCanvasVisual* CAlfBridge::AddEffectItemL(
        TInt aEffectHandle, 
        CHuiVisual* aSourceVisual, 
        CHuiLayout* aTargetLayout, 
        CHuiControl* aEffectControl, 
        TBool aInsertTemporaryVisual,
        TInt& aItemDestroyed,
        TBool aIsExitEffect)
    {
    CHuiCanvasVisual* temporaryPresenterVisual = NULL;
    TInt enableEffect = ETrue;
    
    if (aSourceVisual->iOpacity.Now() >= 0.01)
        {
        aSourceVisual->SetFlag(EHuiVisualFlagShouldBeShown);
        }
    
    aSourceVisual->ClearFlags(EHuiVisualFlagShouldBeInactive | EHuiVisualFlagShouldBeUnderOpaqueHint);
    if (aIsExitEffect) 
        {
        aSourceVisual->SetFlag(EHuiVisualFlagAlwaysDraw);   // forces drawing during exit effect. handlevisualvisibility will set the EShouldbeInactive flag, if visual is determined inactive while this flag is set 
        }
    
    if (HasActiveEffect(aSourceVisual))
        {
        // this visual is having effect and we are closing down the layout this visual inhabits.
        // Propably this is the case, when application is closed while the options menu is 
        // still having effect animation.
    
        // removes the effect, and the visual (if EShouldDestroy flag enabled). Removes from effect
        // cleanup stack iEffectCleanupStack
        enableEffect = aSourceVisual->Flags() & EHuiVisualFlagShouldDestroy ? 0 : 1;
        __ALFFXLOGSTRING2("CAlfBridge::SetupEffectLayoutContainerL - visual 0x%x is having effect. EShouldBeDestroyed flag state %d", &aSourceVisual, enableEffect );
        RemoveTemporaryPresenterVisual(aSourceVisual);
        if (!enableEffect)
            {
            aItemDestroyed++;
            }
        }
    if ( enableEffect )
        {
    // RDebug::Print(_L("CAlfBridge::SetupEffectLayoutContainerL - binding visual 0x%x (source)--> 0x%x (presenter) layout 0x%x (presenter layout)"), &sourceVisual, temporaryPresenterVisual, temporaryPresenterLayout);
        if (aInsertTemporaryVisual)
            {
            temporaryPresenterVisual = CHuiCanvasVisual::AddNewL(*aEffectControl, aTargetLayout);
        
            temporaryPresenterVisual->SetExternalContentL(aSourceVisual);
            temporaryPresenterVisual->SetSize(THuiRealSize(640, 640));
            temporaryPresenterVisual->SetPos(aSourceVisual->Pos().Target());
            aSourceVisual->SetFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
            temporaryPresenterVisual->SetChanged();
            TEffectCleanupStruct item = TEffectCleanupStruct(
                    aEffectHandle,
                    aSourceVisual, 
                    temporaryPresenterVisual,
                    ETrue,
                    aIsExitEffect);
            iEffectCleanupStack.AppendL(item);
            }
        else
            {
            // this will be a child of another visual, and draw by its parent external content visual
            // aSourceVisual->SetFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
            TEffectCleanupStruct item = TEffectCleanupStruct(aEffectHandle,
                        aSourceVisual, NULL, EFalse,
                        aIsExitEffect);
            iEffectCleanupStack.AppendL(item);
            }
     }
    return temporaryPresenterVisual;
    }

void CAlfBridge::AddToEffectLayoutContainerL(
        TInt aEffectHandle,
        CHuiLayout* aSourceLayout, 
        CHuiLayout* aTargetLayout, 
        CHuiControl* aEffectControl,
        TInt& aItemsDestroyed,
        TBool aAddLayout,
        TBool aIsExitEffect)
    {
    __ALFFXLOGSTRING2("CAlfBridge::AddToEffectLayoutContainerL 0x%x is having %d children", aSourceLayout, aSourceLayout->Count());
    if (aAddLayout)
        {
        AddEffectItemL(aEffectHandle, aSourceLayout, aTargetLayout, aEffectControl, EFalse, aItemsDestroyed, aIsExitEffect);
        }
        
    for (TInt i = 0; i < aSourceLayout->Count(); i++)
           {
           CHuiCanvasVisual& sourceVisual = static_cast<CHuiCanvasVisual&> (aSourceLayout->Visual(i));
           
           if (sourceVisual.Count())
               {
               CHuiLayout& layout = static_cast<CHuiLayout&> (aSourceLayout->Visual(i));
               AddToEffectLayoutContainerL(aEffectHandle, &layout, NULL, aEffectControl, aItemsDestroyed, EFalse,aIsExitEffect );
               }
           AddEffectItemL(aEffectHandle, &sourceVisual, aTargetLayout, aEffectControl, EFalse, aItemsDestroyed, aIsExitEffect);
           }
    __ALFFXLOGSTRING2("CAlfBridge::AddToEffectLayoutContainerL 0x%x end of children", aSourceLayout, aSourceLayout->Count());
    }

TBool CAlfBridge::SetupEffectLayoutContainerL(TInt aHandle,CHuiLayout* aSourceLayout, TBool aIsExitEffect)
    {
    if (aSourceLayout->Flags() & EHuiVisualFlagDrawOnlyAsExternalContent)
        {
        // the requested visual is already having an effect. 
        __ALFFXLOGSTRING("CAlfBridge::SetupEffectLayoutContainerL - WE ARE ALREADY HAVING EFFECT! WHAT TO DO??");
        // layout is having already effect. this is tricky. This might be place to panic. Resolve later. 
        }
    // duplicate the layout to effect window group
    CHuiControl& effectControlGroup =  iAlfScreens[0]->iFullscreenEffectControlGroup->Control(0);
    CHuiLayout& effectControlGroupLayout = (CHuiLayout&) effectControlGroup.Visual(0);

    // CHuiCanvasVisual* temporaryPresenterLayout = CHuiCanvasVisual::AddNewL( effectControlGroup, &effectControlGroupLayout);
    // create presenter visual and set bindings
    TInt itemsDestroyed(0);
    AddToEffectLayoutContainerL(aHandle, aSourceLayout, NULL, &effectControlGroup, itemsDestroyed, EFalse, aIsExitEffect);

    if (aIsExitEffect)
        {
        CHuiCanvasVisual* temporaryPresenterVisual = AddEffectItemL(aHandle, aSourceLayout, &effectControlGroupLayout, &effectControlGroup, ETrue, itemsDestroyed, aIsExitEffect);
        aSourceLayout->SetFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
        __ALFFXLOGSTRING3("CAlfBridge::SetupEffectLayoutContainerL - adding handle: %d, 0x%x (source layout)-> 0x%x (presenter layout) to iEffectCleanupStack", aHandle, aSourceLayout, temporaryPresenterVisual);
        }
    else
        {
        AddEffectItemL(aHandle, aSourceLayout, NULL, &effectControlGroup, EFalse, itemsDestroyed, EFalse);
        __ALFFXLOGSTRING2("CAlfBridge::SetupEffectLayoutContainerL - adding handle: %d, 0x%x (source layout), NO presenter layout) to iEffectCleanupStack", aHandle, aSourceLayout);
        }
    iAlfScreens[0]->iVisualTreeVisibilityChanged = ETrue;
    iAlfScreens[0]->iDisplay->SetDirty();
    if (itemsDestroyed)
        {
        __ALFFXLOGSTRING3("CAlfBridge::SetupEffectLayoutContainerL - trying to put effect on destroyed visuals. Skipping effect visual: 0x%x, handle %d, %d items destroyed", aSourceLayout, aHandle, itemsDestroyed);
        }
    __ALFFXLOGSTRING("CAlfBridge::SetupEffectLayoutContainerL");
    return ETrue; // TBool(!itemsDestroyed);
    }

void CAlfBridge::SetupEffectContainerL(TInt aHandle,
        CHuiCanvasVisual* aSourceVisual, TBool aIsExitEffect)
    {
    // if the original visual is having an effect, then remove it.
    if (HasActiveEffect(aSourceVisual))
        {
        RemoveTemporaryPresenterVisual(aSourceVisual); 
        }
        
    // Create new temporary presenter visual for the effect
    CHuiControl& effectControlGroup =
            iAlfScreens[0]->iFullscreenEffectControlGroup->Control(0);
    CHuiLayout* layout = (CHuiLayout*) &effectControlGroup.Visual(0);
    CHuiCanvasVisual* temporaryPresenterVisual = NULL;
    temporaryPresenterVisual = CHuiCanvasVisual::AddNewL(effectControlGroup, layout);
    // attach the source to the presenter visual
    temporaryPresenterVisual->SetExternalContentL(aSourceVisual);
    aSourceVisual->SetFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
    temporaryPresenterVisual->ClearFlag(EHuiVisualFlagInactive);
    aSourceVisual->SetChanged();
    // append to cleanup stack. this is cleaned in RemoveTemporaryVisuals after effect has finished
    iEffectCleanupStack.AppendL(TEffectCleanupStruct(aHandle, aSourceVisual, temporaryPresenterVisual, EFalse /*iIsLayout*/, aIsExitEffect));
    __ALFFXLOGSTRING3("CAlfBridge::SetupEffectContainerL - adding handle: %d, 0x%x (source visual)-> 0x%x (presenter visual)", aHandle, aSourceVisual, temporaryPresenterVisual);
    }

void CAlfBridge::HandleGfxControlEffectsL( TAlfBridgerData data )
    {
    TInt action = data.iInt1;
    TInt length = data.iInt2;
    __ALFFXLOGSTRING1("HandleGfxControlEffectsL - Reading bridge data %d", (TInt)data.iPtr);
    void* bridgeBuffer = (void*) (*iHost)->GetEffectsDataL((TInt) data.iPtr);
    RMemReadStream stream(bridgeBuffer, length);
    if (iControlEffectData)
        {
        delete iControlEffectData;
        iControlEffectData = NULL;
        }
    CControlEffectState* fxData = new (ELeave) CControlEffectState;
    CleanupStack::PushL(fxData);
    fxData->ConstructL(action, stream);
    iControlEffectData = fxData;
    CleanupStack::Pop(fxData);

    // We now have all the data sent to us.
    stream.Release();

    // We need to pass the filename from the transeffect plugin that handles the controls
    // that define which effect is used for the selected skin or the selected application
    // For full screen effects the skin should determine the effect, or there should be
    // some default effects.

    CHuiCanvasVisual* visual = FindVisualByClientSideIds(fxData->iClientHandle, fxData->iClientGroupHandle);

    if (visual)
        {
        HandleGfxControlEventL(*iControlEffectData, visual);
        }
    else
        {
        __ALFFXLOGSTRING2("CAlfBridge::HandleGfxControlEffectsL - Control not found. iClientHandle 0x%x, iClientGroupHandle 0x%x", 
                iControlEffectData->iClientHandle, 
                iControlEffectData->iClientGroupHandle);
        return;
        }
    iAlfScreens[0]->iDisplay->SetDirty();
    iHuiEnv->ContinueRefresh();

    delete iControlEffectData;
    iControlEffectData = NULL;

    __ALFFXLOGSTRING("HandleGfxControlEffectsL - end");
    }

void CAlfBridge::HandleGfxControlEventL(CControlEffectState& aEvent,
        CHuiCanvasVisual* aCanvasVisual)
    {
    TInt err = KErrNone;
    // Check if there is an effects engine in HuiEnv
    CHuiFxEffect* effect = NULL;
    CHuiFxEngine* engine = NULL;
    // engine is not owned by us, it is a member of HuiEnv
    engine = iHuiEnv->EffectsEngine();
    if (NeedsStoredBuffers(engine, *aEvent.iEffectName))
        {
        RecursiveStoreRenderBufferL(aCanvasVisual);
        }

    if (engine)
        {
        // clear out old effect if this visual has one
        __ALFFXLOGSTRING1("HandleGfxControlEffectsL - loading effect %S", &aEvent.iEffectName );
        __ALFFXLOGSTRING1("HandleGfxControlEffectsL - loading control effect, handle %d", aEvent.iHandle );
        if (HasActiveEffect(aCanvasVisual))
            {
            __ALFFXLOGSTRING1("HandleGfxControlEffectsL - 0x%x has active effect. Requesting removal.", aCanvasVisual);
            // another effect coming to already effected visual. E.g. close options menu, while opening effect still ongoing
            RemoveTemporaryPresenterVisual(aCanvasVisual);
            }
        TBool layoutEffectable(EFalse);
        aCanvasVisual->iOpacity.Set(KAlfVisualDefaultOpacity);
        if (aEvent.iAction == KGfxControlDisappearAction)
            { // TODO: revise
            // The control stays visible because the inactive flag is not set
            // if the window is reserved.
            /*if (aCanvasVisual->iOpacity.Target() == 0.0f)
                {
                // this visual was hidden, before the effect arrived. sounds like trouble.
                // Lets make it visible again, and ask it to be hidden in the end of the effect
                // this enables at least the notes disappear effects
                aCanvasVisual->iOpacity.Set(KAlfVisualDefaultOpacity);
                // visual->SetFlag(EHuiVisualFlagShouldBeHidden);
                }*/
            layoutEffectable = SetupEffectLayoutContainerL(aEvent.iHandle, aCanvasVisual, ETrue);
            }
        else
            {
            layoutEffectable = SetupEffectLayoutContainerL(aEvent.iHandle, aCanvasVisual, EFalse);
            }
        if (layoutEffectable)
            {
            TRAP( err, engine->LoadGroupEffectL(*aEvent.iEffectName, effect, aCanvasVisual->Effectable(), engine->ActiveGroupEffect(), NULL, this, aEvent.iHandle, KHuiFxDelayRunUntilFirstFrameHasBeenDrawn ) );
            }
        else
            {
            err = KErrNotFound;
            }
        //            RDebug::Print(_L("HandleGfxControlEffectsL - loading effect returned %d"), err );
        // only use the effect if the effect file was correctly parsed
        if (err == KErrNone)
            {
            iLastEffectHandle = aEvent.iHandle;

#ifdef HUI_DEBUG_TRACK_DRAWING  
            visual->SetTracking(ETrue);
#endif                
            // HuiVisual takes ownership of the effect, but we save the value for reference
            // add new visual to iFullscreenEffectControlGroup. This enables multiple effects in the group, and their 
            // destruction in any order
            }
        else
            {
            // visuals added to "active effect visual" stack, but they wont be used, because effect loading has failed. cleanup.
            RemoveTemporaryPresenterVisual(NULL, aEvent.iHandle);
            }
        effect = NULL; // HuiVisual has taken ownership
        }
    }

TBool CAlfBridge::RemoveTemporaryPresenterItem(TEffectCleanupStruct& aEffectItem)
    {
    CHuiVisual* sourceViz = aEffectItem.iEffectedVisual;
    CHuiCanvasVisual* sourceViz2 = dynamic_cast<CHuiCanvasVisual*> (aEffectItem.iEffectedVisual);
    // wserv has already hidden this window. Effect has finished, so lets do what 
    // was asked. Also hide, if this is supposed to be destroyed by now.
    sourceViz->SetFreezeState(EFalse);    
    sourceViz->SetStoredRenderBuffer(NULL); // free render buffer from visual
    if (sourceViz2 && sourceViz2->Layout()) 
        {
        sourceViz2->FreeRenderBuffer();
        }
    sourceViz->ClearFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
    TBool hideVisual = sourceViz->Flags() & EHuiVisualFlagShouldBeHidden;
    TBool showVisual = sourceViz->Flags() & EHuiVisualFlagShouldBeShown;
    TBool destroyVisual = sourceViz->Flags() & EHuiVisualFlagShouldDestroy;
    TBool shouldInactivate = sourceViz->Flags() & EHuiVisualFlagShouldBeInactive;
    TBool shouldBeUnderOpaqueHint = sourceViz->Flags() & EHuiVisualFlagShouldBeUnderOpaqueHint;
    __ALFFXLOGSTRING3("CAlfBridge::RemoveTemporaryPresenterItem - cleaning handle: %d, 0x%x -> 0x%x", aEffectItem.iHandle, aEffectItem.iEffectedVisual, aEffectItem.iTemporaryPresenterVisual);
    __ALFFXLOGSTRING3("CAlfBridge::RemoveTemporaryPresenterItem - hide %d, destroy %d, should inactivate: %d", TBool(hideVisual), TBool(destroyVisual), TBool(shouldInactivate));
    
    sourceViz->ClearFlag(EHuiVisualFlagAlwaysDraw);
    if (hideVisual)
        {
        // this was exit effect, and window was not really destroyed.
        sourceViz->iOpacity.Set(0.0f);
        sourceViz->ClearFlag(EHuiVisualFlagShouldBeHidden); // it is now hidden
        }
	
    if (showVisual)
        {
        sourceViz->iOpacity.Set(KAlfVisualDefaultOpacity);
        sourceViz->ClearFlag(EHuiVisualFlagShouldBeShown); // it is now hidden
        }
    
    if (destroyVisual)
    	{
    	sourceViz->iOpacity.Set(0.0f);
    	}
    if (shouldInactivate)
        {
        sourceViz->SetFlag(EHuiVisualFlagInactive);
        
        if (sourceViz2)
            {
            sourceViz2->ClearCache();
            }
        sourceViz->ClearFlags(EHuiVisualFlagShouldBeInactive);
        }
    if (shouldBeUnderOpaqueHint)
        {
        sourceViz->SetFlag(EHuiVisualFlagUnderOpaqueHint);
        if (sourceViz2)
             {
             sourceViz2->ClearCache();
             }
        sourceViz->ClearFlags(EHuiVisualFlagShouldBeUnderOpaqueHint);
        }
    if (sourceViz->Effect())
        {
        sourceViz->SetEffect(NULL);
        }

        // first delete the temporary presenter visual, because this will unbind the external content
    if (aEffectItem.iTemporaryPresenterVisual)
        {
        CHuiVisual* viz = aEffectItem.iTemporaryPresenterVisual;
        
        if (viz)
            {
            if (viz->Effect())
                {
                // temporary presenter visual should not have effect, because the effect is 
                // applied to the original visual. However, if somebody misuses this API, it
                // is good to cleap up the effect here.
                viz->SetEffect(NULL);
                }
            if (viz->Layout())
                {
                viz->Layout()->Remove(viz);
                }
            viz->Owner().Remove(viz);
            delete viz;
            aEffectItem.iTemporaryPresenterVisual = NULL;
            }
        }
    // although layout does not support EHuiVisualFlagDrawOnlyAsExternalContent flag, it is being used to indicate a layout that has effect. flag must be cleared, that the layout can be drawn normally after the effect. 
    if (aEffectItem.iIsLayout)
    	{
    	aEffectItem.iEffectedVisual->ClearFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
    	// sourceViz->iOpacity.Set(1.0f);
    	}
    
    if (destroyVisual)
        {
        // window has been destroyed during effect. Kill it once and for all
        // DeleteControlGroupL and DestroyWindow can do their duty, when this flag is cleared
        sourceViz->ClearFlags(EHuiVisualFlagShouldDestroy | EHuiVisualFlagDrawOnlyAsExternalContent); 
        if (aEffectItem.iIsLayout)
            {
            if (sourceViz->Layout())
                {
                sourceViz->Layout()->Remove(sourceViz);
                }
            sourceViz->Owner().Remove(sourceViz);
             
            delete sourceViz;
            __ALFFXLOGSTRING1("CAlfBridge::RemoveTemporaryPresenterItem - Destroying sourceViz: 0x%x", sourceViz);
            aEffectItem.iEffectedVisual = NULL;
            }
        else
            {
            TLex8 lex(sourceViz->Tag());
            TInt nodeId;
            lex.Val(nodeId);
            DestroyWindow(sourceViz, ETrue);
            }
        }
    return TBool(destroyVisual);
    }

// RemoveTemporaryPresenterVisual removes the temporary presenter visual, and unbinds it from the source. 
TBool CAlfBridge::RemoveTemporaryPresenterVisual(CHuiVisual* aVisual,
        TInt aHandle)
    {
    __ALFFXLOGSTRING2("CAlfBridge::RemoveTemporaryPresenterVisual - cleaning handle: %d, 0x%x", aHandle, aVisual);
    TInt visualsRemoved = 0;
    for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
        {
        TEffectCleanupStruct& effectItem = iEffectCleanupStack[i];
        if (aVisual == effectItem.iEffectedVisual || 
		    aHandle == effectItem.iHandle)
            {
            if (RemoveTemporaryPresenterItem(effectItem))
                {
                visualsRemoved++;
                }
            // must remove from finished effects to keep it in sync
            for(TInt k = 0; k < iFinishedCleanupStackEffects.Count(); k++)
                {
                if (iFinishedCleanupStackEffects[k] == effectItem.iHandle)
                    {
                    iFinishedCleanupStackEffects.Remove(k);
                    k--;
                    }
                }
            iEffectCleanupStack.Remove(i);
            i--;
            }
        }
    return TBool(visualsRemoved);
    }
	
CHuiLayout* CAlfBridge::FindTemporaryPresenterLayout(CHuiVisual* aVisual)
    {
    for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
        {
        if (aVisual == iEffectCleanupStack[i].iEffectedVisual)
            {
            ASSERT(iEffectCleanupStack[i].iIsLayout);
            return (CHuiLayout*)iEffectCleanupStack[i].iTemporaryPresenterVisual;
            }
        }
    return NULL;
    }

TBool CAlfBridge::HasActiveEffect(CHuiVisual* aVisual)
    {
    TInt dummy;
    return HasActiveEffect(aVisual, dummy);
    }

TBool CAlfBridge::HasActiveEffect(CHuiVisual* aVisual, TInt& aIndex)
    {
    aIndex = KErrNotFound;
    for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
        {
        if (aVisual == iEffectCleanupStack[i].iEffectedVisual)
            {
            aIndex = i;
            return ETrue;
            }
        }
    return EFalse;
    }

TInt CAlfBridge::FindEffectHandle(CHuiVisual* aVisual)
    {
    for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
        {
        if (aVisual == iEffectCleanupStack[i].iEffectedVisual)
            {
            return iEffectCleanupStack[i].iHandle;
            }
        }
    __ALFFXLOGSTRING1(" CAlfBridge::SetupEffectLayoutContainerL - Could not find handle for 0x%x", aVisual);
    return KErrNotFound;
    }

CHuiLayout* CAlfBridge::FindLayoutByEffectHandle(TInt aHandle)
    {
    for (TInt i = 0; i < iEffectCleanupStack.Count(); i++)
        {
        if (aHandle == iEffectCleanupStack[i].iHandle && iEffectCleanupStack[i].iIsLayout)
            {
            return (CHuiLayout*)iEffectCleanupStack[i].iEffectedVisual;
            }
        }
    return NULL;
    }


TBool CAlfBridge::RemoveTemporaryPresenterVisuals()
    {
    if (!iFinishedCleanupStackEffects.Count())
        {
        return 0;
        }
    TInt itemsRemoved(0);
    CHuiControl& effectControlGroup =  iAlfScreens[0]->iFullscreenEffectControlGroup->Control(0);
    CHuiLayout* effectControlGroupLayout = (CHuiLayout*) &effectControlGroup.Visual(0);
    __ALFFXLOGSTRING1("CAlfBridge::RemoveTemporaryPresenterVisuals - BEGIN - effects in layout %d", effectControlGroupLayout->Count());

    while (iFinishedCleanupStackEffects.Count())
        {
        for (TInt i = 0; i < iEffectCleanupStack.Count() && iFinishedCleanupStackEffects.Count(); i++)
            {
            __ALFFXLOGSTRING2("CAlfBridge::RemoveTemporaryPresenterVisuals - looping, finished count: %d, index in active effecs: %d", iFinishedCleanupStackEffects.Count(), i );
       
            TEffectCleanupStruct& effectItem = iEffectCleanupStack[i];
            if (iFinishedCleanupStackEffects[0] == effectItem.iHandle)
                {
                if (RemoveTemporaryPresenterItem(effectItem))
                    {
                    itemsRemoved++;
                    }
                if (iEffectCleanupStack.Count() > i)
                    {
                    iEffectCleanupStack.Remove(i);
                    }
                iFinishedCleanupStackEffects.Remove(0);
                i--;
                }
            }
        }
    iAlfScreens[0]->iVisualTreeVisibilityChanged = ETrue; // TODO: Check if really changed   
    iAlfScreens[0]->iDisplay->SetDirty();
	__ALFFXLOGSTRING1("CAlfBridge::RemoveTemporaryPresenterVisuals - END - effects in layout %d", effectControlGroupLayout->Count());
    return itemsRemoved;
    }

void CAlfBridge::RemoveAllTemporaryPresenterVisuals()
    {
    CHuiControl& effectControlGroup =  iAlfScreens[0]->iFullscreenEffectControlGroup->Control(0);
    CHuiLayout* effectControlGroupLayout = (CHuiLayout*) &effectControlGroup.Visual(0);
    __ALFFXLOGSTRING1("CAlfBridge::RemoveAllTemporaryPresenterVisuals - BEGIN - effects in layout %d", effectControlGroupLayout->Count());

    while(iEffectCleanupStack.Count())
        {
        TEffectCleanupStruct& effectItem = iEffectCleanupStack[0];
        RemoveTemporaryPresenterItem(effectItem);
        iEffectCleanupStack.Remove(0);
        }
    
    while(iFinishedCleanupStackEffects.Count())
        {
        iFinishedCleanupStackEffects.Remove(0);
        }    
    }

void CAlfBridge::AlfGfxEffectEndCallBack(TInt aHandle)
    {
    // We need a delay to prevent the refresh from being messed up
    // We try a short delay before clearing everything up.
    __ALFFXLOGSTRING1("AlfGfxEffectEndCallBack, handle %d", aHandle );
    //    RDebug::Print(_L("AlfGfxEffectEndCallBack, append handle %d"), aHandle );
    // If the handle cannot be appended, the function returns an error.
    // However, if the memory is low, there is nothing we can do about it.
    // We try to handle the transition finish anyway.
    // If there are already other handles in the queue, the handler will not
    // be called for this handle, but all handles that have been left hanging
    // around will be cleared when HandleGfxStopEffectsL is called

    // iFinishedCleanupStackEffects.Append(aHandle);
    if (!iEffectEndTimer->IsActive())
        {
        iEffectEndTimer->Start( 10000, aHandle );
        }

    // We should do visual visibility scan after effect is ended
    iAlfScreens[0]->SetVisualTreeVisibilityChanged(ETrue);
    }

void CAlfBridge::TransitionFinishedHandlerL(TInt aHandle)
    {
    for (TInt i=0;i<iEffectCleanupStack.Count();i++)
    	{
    	if(aHandle==iEffectCleanupStack[i].iHandle)
    		{
    		// effect might have been cleaned even without this callback. e.g. closing of applicaion while option menu disappear 
    		// effect is running, would cause it. There is no need to request cleaning again.
    		iFinishedCleanupStackEffects.Append(aHandle);
    		}
    	}
    // If the finish request comes from the plugin, the plugin is not interested
    // in getting a notification of the transition end.
    __ALFFXLOGSTRING1("Gfx transition finished, handle %d", aHandle );
    if ( aHandle == KErrNotFound )
        {
        __ALFFXLOGSTRING("invalid handle");
        }
    // alftranstion plugin may cancel end timers connected to this effect
    TBool fsEffectDone = iFullScreenEffectData && aHandle == iFullScreenEffectData->iHandle;
    if ( fsEffectDone )
        {
        aHandle = iFullScreenEffectData->iCompletionHandle;
        }
    RProperty::Set( KPSAlfDomain, KAlfTransitionStatus, aHandle );

    // Effect finished
    if ( fsEffectDone )
        {
        delete iFullScreenEffectData;
        iFullScreenEffectData = NULL;
        }
    }
    

void CAlfBridge::PrintAllocMem()
    {
#ifdef _ALF_LOGGING
    TInt allocCells = 0;
    TInt allocSpace = 0;
    TInt freeSpace = 0;
    TInt largestFreeBlock = 0;
    allocCells = User::AllocSize( allocSpace );
    freeSpace = User::Available( largestFreeBlock );
    __ALFLOGSTRING2("CAlfBridge::PrintAllocMem - alloc cells %d, alloc space %d", allocCells, allocSpace );
    __ALFLOGSTRING2("CAlfBridge::PrintAllocMem - free space %d, largest free block %d", freeSpace, largestFreeBlock );
#endif
    }
      
// ---------------------------------------------------------------------------
// DebugPrintControlGroupOrder
//
// Note, that HUI_DEBUG_TRACK_DRAWING must be enabled if you want to see the 
// real process names
// ---------------------------------------------------------------------------
// 

#ifdef ALF_DEBUG_PRINT_WINDOWGROUP_ORDER
void CAlfBridge::DebugPrintControlGroupOrder(CAlfScreen& aScreen, CHuiRoster& aRoster, CHuiControlGroup& aGroup)
    {
    __ALFLOGSTRING(">> ---AFTER-----");    
    for (TInt i=0; i<aRoster.Count();i++)
        {
        CHuiControlGroup& indexedGroup = aRoster.ControlGroup(i);
        
        if (&indexedGroup == &aGroup)
            {
            __ALFLOGSTRING("<<");                                        
            }
#ifdef  HUI_DEBUG_TRACK_DRAWING
        TInt clientWindowGroupId = FindClientWindowGroupId( aScreen.iScreenNum, indexedGroup );

        TFileName processName = iCommandDebug->WServClientFileName( clientWindowGroupId, CHuiStatic::WsSession() );
#endif         
        if (indexedGroup.Control(0).Role() == EAlfWindowGroupContainer)
            {
            if (aRoster.ControlGroup(i).ResourceId() == iAlfWindowGroupNodeId)
                {
#ifdef  HUI_DEBUG_TRACK_DRAWING
                __ALFLOGSTRING2(">> %d WINDOW GROUP (ALF), %d", i, clientWindowGroupId);                                    
#endif         
                }
            else
                {
#ifdef  HUI_DEBUG_TRACK_DRAWING
                __ALFLOGSTRING3(">> %d WINDOW GROUP %S, %d", i, &processName, clientWindowGroupId);
#else
                __ALFLOGSTRING1(">> %d WINDOW GROUP", i);            
#endif
                }                    
            }
        else if (indexedGroup.Control(0).Role() == EAlfSessionContainer)
            {
#ifdef  HUI_DEBUG_TRACK_DRAWING
            __ALFLOGSTRING2(">> %d ALF GROUP, %d", i, clientWindowGroupId);                        
#endif
            }
        else if (indexedGroup.Control(0).Role() == EAlfWindowFloatingSpriteContainer)
            {
#ifdef  HUI_DEBUG_TRACK_DRAWING			
            __ALFLOGSTRING3(">> %d FLOATING SPRITE GROUP %S, %d", i, &processName, clientWindowGroupId);                                            
#else
            __ALFLOGSTRING1(">> %d FLOATING SPRITE GROUP", i);                                            
#endif
            }
        else if (indexedGroup.Control(0).Role() == EAlfFullScreenEffectContainer)
            {
#ifdef  HUI_DEBUG_TRACK_DRAWING
            __ALFLOGSTRING3(">> %d EFFECT GROUP %S, %d", i, &processName, clientWindowGroupId );                                                                
#else
            __ALFLOGSTRING1(">> %d EFFECT GROUP", i);                                                                
#endif
            }
        else if (indexedGroup.Control(0).Role() == EAlfFpsIndicatorContainer)
            {
#ifdef  HUI_DEBUG_TRACK_DRAWING
            __ALFLOGSTRING3(">> %d FPS GROUP %S, %d", i, &processName, clientWindowGroupId );                                                                
#else
            __ALFLOGSTRING1(">> %d FPS GROUP", i);                                                                
#endif
            }
        else 
            {
#ifdef  HUI_DEBUG_TRACK_DRAWING
            __ALFLOGSTRING3(">> %d UNKNOWN GROUP ?!!? %S, %d", i, &processName, clientWindowGroupId );
#endif
            }                                                

        if (&indexedGroup == &aGroup)
            {
            __ALFLOGSTRING("<<");                                        
            }            
        }
    
    // Print the group that has keyboard focus
    TInt focusWindowGroupId = CHuiStatic::WsSession().GetFocusWindowGroup();
    TFileName processName;
    TThreadId threadId;
    TInt error = CHuiStatic::WsSession().GetWindowGroupClientThreadId( focusWindowGroupId, threadId );
    RThread thread;
    TInt err = thread.Open( threadId );
    if( !err )
        {
        RProcess process;
        err = thread.Process( process );
        if( !err )
            {
            processName = process.FileName();
            __ALFLOGSTRING2( ">> Keyboard focus group: %S, %d", &processName, focusWindowGroupId );
            }
        process.Close();
        thread.Close();
        }      
    __ALFLOGSTRING(">> ---------------");                
    }
#else
void CAlfBridge::DebugPrintControlGroupOrder(CAlfScreen& /*aScreen*/, CHuiRoster& /*aRoster*/, CHuiControlGroup& /*aGroup*/)
    {
    }
#endif        

#ifdef ALF_DEBUG_VISUALIZE_WINDOWGROUP_ORDER
void CAlfBridge::VisualizeControlGroupOrderL(CAlfScreen& aScreen, CHuiRoster& aRoster, CHuiControlGroup& /*aGroup*/)
    {       
    TInt nbrofcolums = 3;
    TInt nbrofrows = 3;
    TInt gridIndex = 0;
    TBool skipEmpty = EFalse;
    TInt skipCount = aScreen.FixedControlGroupCount() + 1;
    if (aRoster.Count() > skipCount)
        {
        for (TInt i=aRoster.Count() - skipCount; i>0; i--)
            {
            CHuiControl& control = aRoster.ControlGroup(i).Control(0);
            if (skipEmpty)
                {                        
                TBool empty = ETrue;
                CHuiLayout* layout = (CHuiLayout*)&control.Visual(0);
                for (TInt j=layout->Count()-1; j >= 0; j--)
                    {
                    CHuiCanvasVisual* canvasVisual = (CHuiCanvasVisual*) &layout->Visual(j);
                    if (canvasVisual && canvasVisual->DisplayRect().Size().Round() != TSize(0,0) && canvasVisual->PaintedAreaCount())
                        {
                        empty = EFalse;        
                        break;
                        }                        
                    }
                
                if (empty && skipEmpty)
                    {
                    continue;   
                    }                    
                }
            
            TSize screensize = HuiUtil::ScreenSize();
            CHuiTransformation::TTransform& step = aRoster.ControlGroup(i).Transformation().Step(0);
            step.iParams[EHuiTransformParamTranslateX].Set((gridIndex % nbrofcolums) * (screensize.iWidth/nbrofcolums), 500);
            step.iParams[EHuiTransformParamTranslateY].Set((gridIndex / nbrofrows) * (screensize.iHeight/nbrofrows), 500);
            gridIndex++;
            }                        
        }
    iAlfScreens[0]->iDisplay->SetClearBackgroundL(CHuiDisplay::EClearWithSkinBackground);            
    }
#else
void CAlfBridge::VisualizeControlGroupOrderL(CAlfScreen& /*aScreen*/, CHuiRoster& /*aRoster*/, CHuiControlGroup& /*aGroup*/)
    {       
    }
#endif    

// ---------------------------------------------------------------------------
// PostQTCommandBufferL
// ---------------------------------------------------------------------------
// 
void CAlfBridge::PostQTCommandBufferL( TAlfQtCommandBufferParams params )
    {       
    CHuiCanvasVisual* huiVisual = NULL;       
    if ((*iHost))
        {
        if( (*iHost)->StreamerServer() )
            { 
            if ((*iHost)->StreamerServer()->WindowMgr())
                {
                RArray<TAlfWServInfo> winInfoList;
                
                (*iHost)->StreamerServer()->WindowMgr()->GetWinInfoListL( params.iWsWgId, 
                        params.iWsClientId, winInfoList );
                    
                for ( TInt i= 0; i<winInfoList.Count(); i++ )
                    {
                    if( winInfoList[i].iClientSideId.iWindowIdentifer == params.iWsClientId )
                        {
						 huiVisual = FindVisual( winInfoList[i].iRefId.iWindowIdentifer );
						 break;
	                  }    
                    }
				 winInfoList.Close();                                
                }
            }
        }
    
    if ( huiVisual )
       {
       TPtrC8 commands( (TUint8 *)params.iPtr, params.iLength );
       TAlfCommandBufferStatus bufferStatus =  params.iBufferStatus;
       huiVisual->SetCommandType( 1 ); // set to ECommandBufferWs should it be some QT specific?
       if ( bufferStatus == EComplete )
           {         
           huiVisual->ClearCommandSet();
           huiVisual->AddCommandSetL(commands);
           }
       else if ( bufferStatus == EPartial )
           {
           huiVisual->AddPartialCommandSetL( commands, EFalse );
           }
       else if ( bufferStatus == ELastPart )
           {
           huiVisual->AddPartialCommandSetL( commands, ETrue );
           }
       }    
    }
    

// ---------------------------------------------------------------------------
// SetClientWindowForDrawingL
//
// Note: One external content visual can exist in one canvas visual at the 
// time. When external content visual is deleted, in destructor, it removes 
// pointers to it from all canvas visuals. So canvasVisual->ExternalContent() 
// always returns a valid pointer, or NULL. The parameter aRootVisual can 
// be NULL, which means that the external content is removed from the canvas 
// visual
// ---------------------------------------------------------------------------
// 
void CAlfBridge::SetClientWindowForDrawingL(TInt aWindowGroupId, TInt aClientWindowHandle, 
	CHuiVisual* aExternalContentVisual)
	{    	
    RArray<TAlfWServInfo> winInfoList;
    CleanupClosePushL(winInfoList);

	// Find canvas visual for the RWindow
	
	(*iHost)->StreamerServer()->WindowMgr()->GetWinInfoListL(aWindowGroupId, aClientWindowHandle, winInfoList );
	if(winInfoList.Count() != 1)
		{
		User::Leave(KErrArgument);
		}

	CHuiCanvasVisual* canvasVisual = (CHuiCanvasVisual*)FindVisual(winInfoList[0].iRefId.iWindowIdentifer);
	if (!canvasVisual)
		{
		User::Leave(KErrNotFound);
		}
			
	// Current external content 
	CHuiVisual* currentContent = canvasVisual->ExternalContent();
	
	if (!aExternalContentVisual)
		{	
		// Do not draw external content any more. 
			
		// Disable external content for the canvas visual	
		canvasVisual->SetExternalContentL(NULL);
		// For the current content, enable drawing it in the original visual tree. 
		if (currentContent)
			{
			currentContent->ClearFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
			}
		}
	else if (!(aExternalContentVisual->Flags() & EHuiVisualFlagDrawOnlyAsExternalContent))
		{
		// The visual is not yet used by other canvas visual
		
		// Enable external content for the canvas visual	
		canvasVisual->SetExternalContentL(aExternalContentVisual);
		// For the current content, enable drawing it in the original visual tree. 
		if (currentContent)
			{
			currentContent->ClearFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
			}
		// Disable normal drawing and start using as external content	
		aExternalContentVisual->SetFlag(EHuiVisualFlagDrawOnlyAsExternalContent);
		}   
	else
		{
		// aExternalContentVisual is already used as an external content for some visual
		User::Leave(KErrAlreadyExists);
		}
		
	CleanupStack::PopAndDestroy(); // winInfoList
	}

void CAlfBridge::SetVisualTreeVisibilityChanged(TBool aChanged)
    {
    for (TInt i=0; i<iAlfScreens.Count();i++)
        {
        iAlfScreens[i]->iVisualTreeVisibilityChanged = aChanged;
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::EnableSwRenderingL(TBool aEnable)
    {    
    if (aEnable == iSwRenderingEnabled)
        {
        return;
        }
    
    iSwRenderingEnabled = aEnable;    
    for (TInt i=0; i<iAlfScreens.Count();i++)
        {
        PrepareSwRenderingTarget(iAlfScreens[i]);        
     
        if (iSwRenderingEnabled)
            {
            CHuiTexture* texture = CHuiTexture::NewL();
            CleanupStack::PushL(texture);
            iAlfScreens[i]->iDisplay->SetForegroundBitmapL( iAlfScreens[i]->iSwRenderingTarget );
            CleanupStack::Pop(texture);
            iAlfScreens[i]->iDisplay->SetForegroundTexture(texture);
            iAlfScreens[i]->iDisplay->iRosterObservers.AppendL(*this);
            }
        else
            {
            iAlfScreens[i]->iDisplay->SetForegroundBitmapL(NULL);            
            iAlfScreens[i]->iDisplay->SetForegroundTexture(NULL);
            iAlfScreens[i]->iDisplay->iRosterObservers.Remove(*this);            
            }
            
        // SetCapturingBufferL is called from HandleVisualVisibility.
        iAlfScreens[i]->SetVisualTreeVisibilityChanged(ETrue);
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::UploadSwRenderingTargetL(CAlfScreen* aScreen)
    {
    if (iSwRenderingEnabled)
        {
        CHuiTexture* texture = aScreen->iDisplay->ForegroundTexture();                        
        if (texture && aScreen->iSwRenderingTarget)
            {
            texture->UploadL(*aScreen->iSwRenderingTarget, NULL);                
            }           
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TBool CAlfBridge::PrepareSwRenderingTarget( CAlfScreen* aScreen )
    {
    TBool modified = EFalse;
    
    // Check ultra low memory mode here
    if (iHuiEnv->MemoryLevel() <= EHuiMemoryLevelLowest)
        {        
        if (!aScreen->iSwRenderingTarget)
            {
            // screen owns this bitmap
            aScreen->iSwRenderingTarget = new CFbsBitmap;
            if (aScreen->iSwRenderingTarget)
                {
                aScreen->iSwRenderingTarget->Create(aScreen->Size(), EColor16MAP); 
                modified = ETrue;
                }
            }
        
        if (aScreen->iSwRenderingTarget)
            {
            if (aScreen->iSwRenderingTarget->SizeInPixels() != aScreen->Size())
                {
                aScreen->iSwRenderingTarget->Resize(aScreen->Size());
                modified = ETrue;
                }        
            // For tests
            //TUint32* data = aScreen->iSwRenderingTarget->DataAddress();
            }
        }
    else
        {
        delete aScreen->iSwRenderingTarget;
        aScreen->iSwRenderingTarget = NULL;
        modified = ETrue;
        }
        
    return modified;
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::SetMemoryLevel(THuiMemoryLevel aMemoryLevel)
    {
    iCurrentMemoryLevel = aMemoryLevel;
    DoUpdateMemoryLevel();    
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::SetLowMemory(TBool aEnabled)
    {
    iLowMemoryMode = aEnabled;
    DoUpdateMemoryLevel();
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
TInt CAlfBridge::ForceSwRendering(TBool aEnabled)
    {
    iForcedSwRendering = aEnabled;
    DoUpdateMemoryLevel();
    return KErrNone;        
    }

// ---------------------------------------------------------------------------
// This decides memory level for core toolkit. This should the only place
// where core toolkit memory level is modified.
// ---------------------------------------------------------------------------
// 
void CAlfBridge::DoUpdateMemoryLevel()
    {
    THuiMemoryLevel memoryLevel = iCurrentMemoryLevel;
    if ( iLowMemoryMode && ( memoryLevel > EHuiMemoryLevelLow ) )
        {
        memoryLevel = EHuiMemoryLevelLow;
        }
    if ( iForcedSwRendering && ( memoryLevel > EHuiMemoryLevelLowest ) )
        {
        // For now, we use memory level to force SW rendering
        // to be used.
        memoryLevel = EHuiMemoryLevelLowest;
        }
    
    if ( memoryLevel != iHuiEnv->MemoryLevel() )
        {    
        __ALFLOGSTRING1("CAlfBridge::DoUpdateMemoryLevel -> %d", memoryLevel);
        if ( memoryLevel <= EHuiMemoryLevelLowest)
            {
            LowMemoryCancelAllEffects();
            }
            
        iHuiEnv->NotifyMemoryLevel(memoryLevel);
        if (memoryLevel <= EHuiMemoryLevelLowest)
            {
            TRAP_IGNORE(EnableSwRenderingL(ETrue));
            }
        else
            {
            TRAP_IGNORE(EnableSwRenderingL(EFalse));        
            }
        }
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::LowMemoryCancelAllEffects()
    {
    __ALFLOGSTRING("CAlfBridge::LowMemoryCancelAllEffects");
    iLayoutSwitchEffectCoordinator->Cancel();
    HandleGfxStopEvent( EFalse );
	__ALFLOGSTRING("CAlfBridge::LowMemoryCancelAllEffects done");
	}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::NotifyRosterDrawStart(CHuiDisplay& /*aDisplay*/)
    {
    // Do nothing
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::NotifyRosterDrawEnd(CHuiDisplay& aDisplay)
    {
    TInt screenNumber = ResolveScreenNumber(aDisplay);    
    TRAP_IGNORE(UploadSwRenderingTargetL(iAlfScreens[screenNumber]));
    }

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// 
void CAlfBridge::Synchronized(TInt aId)
    {
    // Use P&S for now.
    RProperty::Set( KAlfPSUidSynchronizer, KAlfPSKeySynchronizer, aId );
    }

// end of file