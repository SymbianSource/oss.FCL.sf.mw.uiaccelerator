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
* Description:   AlfEffectUtils contains small classes that enable layout switch and transition effects.
*
*/
#include <e32cmn.h>
#include <s32mem.h>
#include "alfeffectutils.h"
#include <akntransitionutils.h>
#include <alflogger.h>

const TInt KRosterFreezeEndTimeoutInMs = 100;
const TInt KFirstTimeoutForApplicationEndFullScreenInMs = 20;
const TReal KMinimumPaintedAreaBeforeForcedEffect = 0.75;

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
    __ALFLOGSTRING("CAlfRosterFreezeEndTimer::Start");
    if (!IsActive())
        {
        After( aPeriod );
        }
    }

void CAlfRosterFreezeEndTimer::RunL()
    {
    __ALFLOGSTRING("CAlfRosterFreezeEndTimer::RunL");
	
	TBool timeout = EFalse;
	
	if (iSafeCounter >= 0)	
	    {
		iSafeCounter++;
		if (iSafeCounter == 10)
			{
			timeout = ETrue;
			iSafeCounter = 0;
			}
		}

    if (!iBridge.IsFullScreenDrawn(0) && !timeout)
        {
        __ALFLOGSTRING("CAlfRosterFreezeEndTimer::RunL - Not ready in new orientation. waiting 50ms more");
        After( 50000 );
        return;
        }
    else
        {
        __ALFLOGSTRING("CAlfRosterFreezeEndTimer::RunL - ready in new orientation. ");
        iBridge.iHuiEnv->Display(0).SetDirty();
        iBridge.iHuiEnv->iPauseDrawing = EFalse;
	    TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(EFalse));
        iBridge.SetVisualTreeVisibilityChanged(ETrue);
        }
    }

void CAlfRosterFreezeEndTimer::DoCancel()
    {
    CTimer::DoCancel();
    }



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
    if (iRosterFreezeEndTimer)
        {
		iRosterFreezeEndTimer->Cancel();
		}

    if (!iLayoutSwitchEffectContext && !( iBridge.iHuiEnv->MemoryLevel() <= EHuiMemoryLevelLowest ))
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
                TRAP_IGNORE(iBridge.iHuiEnv->Display(0).Roster().FreezeVisibleContentL(ETrue));
                
                // Remove all other effects
                iBridge.HandleGfxStopEvent( EFalse );
                iBridge.RemoveAllTemporaryPresenterVisuals();

                // Set remove freeze timer
                __ALFLOGSTRING("CAlfLayoutSwitchEffectCoordinator::BeginLayoutSwitch - Freeze timer started");
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
    iHandles.ReserveL(5);
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
    iHandles.Close();
    }

void CAlfEffectEndTimer::Start( TTimeIntervalMicroSeconds32 aPeriod )
    {
    After( aPeriod );
    }

void CAlfEffectEndTimer::AddFinishedHandleL(TInt aHandle)
    {
    iHandles.Append(aHandle);
    }

void CAlfEffectEndTimer::RunL()
    {
    //
    // timer completes and control is returned to caller
    //
    while(iHandles.Count())
        {
        iBridge.TransitionFinishedHandlerL( iHandles[0]);
        iHandles.Remove(0);
        }
    // We don't become active unless we are explicitly restarted
    }

void CAlfEffectEndTimer::DoCancel()
    {
    CTimer::DoCancel();
    }


CEffectState::CEffectState()
    {
    // CBase clears all variables
    }

CEffectState::~CEffectState()
    {
    delete iEffectName;
    }

void CEffectState::ResolveFileNameL(RMemReadStream& aStream)
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


CFullScreenEffectState::~CFullScreenEffectState()
    {
    iPaintedRegion.Close();
    if (iDrawingCompleteTimer)
        {
        iDrawingCompleteTimer->Cancel();
        delete iDrawingCompleteTimer;
        iDrawingCompleteTimer = NULL;
        }
    }


void CFullScreenEffectState::ConstructL(
        TInt aAction,
        RMemReadStream& aStream)
    {
    iAction = aAction;

    iHandle = aStream.ReadInt32L();

    iType = aStream.ReadInt32L();
    iToWg = aStream.ReadInt32L();
    iFromWg = aStream.ReadInt32L();
    iToAppId = aStream.ReadInt32L();
    iFromAppId = aStream.ReadInt32L();

    if (iType == AknTransEffect::EParameterType)
        {
        iToSecureId = aStream.ReadInt32L();
        iFromSecureId = aStream.ReadInt32L();
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

TInt doNotifyDrawingTimeout( TAny* aPtr )
    {
    ((CFullScreenEffectState*)aPtr)->NotifyDrawingTimeout();
    return 0; // must return something
    }

TBool CFullScreenEffectState::InitDelayedEffectL(CAlfBridge* aBridge, TSize aDisplaySize)
    {
    iBridge = aBridge;
    iDisplaySize = aDisplaySize;
    if (!iDrawingCompleteTimer)
        {
        iDrawingCompleteTimer = CPeriodic::NewL( EPriorityNormal );
        iDrawingCompleteTimer->Start( 
                KFirstTimeoutForApplicationEndFullScreenInMs * 1000 , 
                KFirstTimeoutForApplicationEndFullScreenInMs * 1000 , TCallBack( doNotifyDrawingTimeout, this ));
        return ETrue;
        }
    return EFalse;
    }

void CFullScreenEffectState::NotifyDrawingTimeout()
    {
    
    iPaintedRegion.ClipRect(TRect(0,0, iDisplaySize.iWidth, iDisplaySize.iHeight));
    iPaintedRegion.Tidy(); // remove overlapping regions
    TInt size(0);
    for(TInt i=0; i< iPaintedRegion.Count();i++ )
        {
        size += iPaintedRegion[i].Width()*iPaintedRegion[i].Height();
        }
    // lets continue, if the covered area is more than 75% of the screen. This is usually enough.
    if ( size > KMinimumPaintedAreaBeforeForcedEffect  * (iDisplaySize.iWidth * iDisplaySize.iHeight))
        {
        iBridge->HandleGfxEndFullScreenTimeout(this);
        delete iDrawingCompleteTimer;
        iDrawingCompleteTimer = NULL;
        }
    }

void CControlEffectState::ConstructL(TInt aAction,
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

