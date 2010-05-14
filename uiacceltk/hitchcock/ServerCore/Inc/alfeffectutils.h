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
* Description:   internal for Nokia
*
*/

#include <s32mem.h>
#include <akntranseffect.h>
#include "alfbridge.h"

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
        void Start( TTimeIntervalMicroSeconds32 aPeriod, TCallBack aCallBack  );
        
    protected:  // Functions from base classes
        void DoCancel();

    private:
        CAlfRosterFreezeEndTimer( CAlfBridge& aBridge );
        void ConstructL();
        void RunL();
      
    private:    // Data
        CAlfBridge& iBridge;
 	public:
	   	TInt iSafeCounter;
        TCallBack iCallBack;        
    };



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
        void Start( TTimeIntervalMicroSeconds32 aPeriod );
        void AddFinishedHandleL(TInt aHandle);
        
    protected:  // Functions from base classes
        void DoCancel();

    private:
        CAlfEffectEndTimer( CAlfBridge& aBridge );
        void ConstructL();
        void RunL();
      
    private:    // Data
        CAlfBridge& iBridge;
        RArray<TInt> iHandles;
    };

// ---------------------------------------------------------
// CAlfLayoutSwitchEffectcoordinator
// ---------------------------------------------------------
//
NONSHARABLE_CLASS( CAlfLayoutSwitchEffectCoordinator ) : public CBase, public MAlfGfxEffectObserver
    {
    public:
        enum TEvent
            {
            EEventLayoutSwitch,
            EEventBlankOn,
            EEventBlankOff,
            EEventLowMemory
            };
    
        enum TState
            {
            EStateIdle,
            EStateFreezeFx,
            EStateBlankFx,
            EStateThemeFx
            };

        typedef TState (*TStateFunction)(TEvent aEvent);

    public:  // Constructors and destructor
        CAlfLayoutSwitchEffectCoordinator( CAlfBridge& aBridge );
        virtual ~CAlfLayoutSwitchEffectCoordinator();
    
    public: // MAlfGfxEffectObserver           
        void AlfGfxEffectEndCallBack( TInt aHandle );
    
    public:
        void Blank(TBool aEnabled);
        void LowMemoryEvent();
        void BeginLayoutSwitch();
        
        void Event(TEvent aEvent);
        void Transition(TState aNewState, TState aPreviousState);

    private:
        TState NextIdleState(TEvent aEvent);
        TState NextFreezeState(TEvent aEvent);
        TState NextBlankState(TEvent aEvent);
        TState NextThemeState(TEvent aEvent);

        void FreezeFinished();

    public:            
        TBool IsThemeEffectEnabled() const;
        TBool LayoutSwitchEffectsExist() const;

		void EnableSafeCounter(TBool aEnable)
			{
			if (iRosterFreezeEndTimer)
				{
				if (aEnable)
					{
					iRosterFreezeEndTimer->iSafeCounter = 0;
					}
				else
					{
					iRosterFreezeEndTimer->iSafeCounter = KErrNotFound;
					}
				}
			}        
    
    private:
        AknTransEffect::TContext NextLayoutSwitchContext();
        void SetLayoutSwitchEffect(AknTransEffect::TContext aContext);
        
        void FreezeRoster(TBool aFrozen);
        
        static TInt DoFreezeFinished(TAny* aAny);
        
    private: // Data
        
        CAlfBridge& iBridge;
        AknTransEffect::TContext iLayoutSwitchEffectContext;
        TThreadPriority iOriginalPriority;
        CAlfRosterFreezeEndTimer* iRosterFreezeEndTimer;
        TBool iBlankEnabled;
        
        TState iCurrentState;
        TBool iLayoutSwitchNotCompleted;
	};

// ---------------------------------------------------------
// Effects states are used for effects request that arrive before the effected 
// window has been created. This is very common with fullscreen effects and 
// occational with control effects.
//
// NOTE: control effects support currently only one "delayed" effect. This is propably
//       not sufficient for all sitations.
// ---------------------------------------------------------
//
NONSHARABLE_CLASS(CEffectState) : public CBase
        {
    public:    
        
        CEffectState();
        virtual ~CEffectState();
         
    protected:
       /**
        * ResolveFileNameL
        *
        * Reads filename from stream and composes it to iEffectName variable.
        */
         void ResolveFileNameL(RMemReadStream& aStream);
         
    public:
         
         TInt iAction;
         TInt iHandle;
            
         HBufC* iEffectName;
         // Handle using which client should be informed of completion.
         TInt iCompletionHandle;
         // State information
         TInt iOperation;
         
        };
    
    NONSHARABLE_CLASS(CControlEffectState ) : public CEffectState
        {
    public:
        
        TUint32 iClientHandle;
        TUint32 iClientGroupHandle;
        
        enum TDistractionType
            {
            ENoOperation = 0,
            ESetDistractionWindow = 100,
            ERemoveDistractionWindow
            };
        
        TDistractionType iSetDistractionWindow;
        
        void ConstructL(TInt aAction, RMemReadStream& aStream);
        
        void ConstructL(TUint32 aClientHandle, TUint32 aClientGroupHandle, TBool aSetDistractionWindow);
        };

    NONSHARABLE_CLASS(CFullScreenEffectState ) : public CEffectState
        {
    public:
        ~CFullScreenEffectState();
        
        void ConstructL(TInt aAction, RMemReadStream& aStream);
        
        // Information from BeginFullScreen
        TInt iType;
        TInt iToWg;
        TInt iFromWg;
        TInt iToAppId;
        TInt iFromAppId;
        TInt iToSecureId;
        TInt iFromSecureId;
        TRect iRect;
        
        // ETrue if waiting for window group to appear
        TBool iWaitingWindowGroup;
        // ETrue if end fullscreen has been performed
        TBool iEndFullScreen;
        // ETrue if setup effect container has been done
        TBool iSetupDone;

        // used for resolving the iCleanupStackItem that holds the frozen app layout underneath the starting application
        TInt iAppStartScreenshotItemHandle;
        
        
        enum TEffectType
        {
            ENotDefinedEffect = 0,
            EStartEffect,
            EExitEffect
        };
        
        TEffectType iEffectType;
        
        // Display dimension, iPaintedRegion is clipped to this when determining, if there is enough drawing to the group
        TSize iDisplaySize;
        
        // gathers the painted region for the effected application. When enough region has been painted, the effect is forced.
        RRegion iPaintedRegion;
        
        CAlfBridge* iBridge; // for callback. not own.
        
        // If the visual is shown by some other visual by a screenshot, this is set ETrue.
        TBool iCanDestroyOrHideImmediately;
        
        CPeriodic* iDrawingCompleteTimer;
        };
