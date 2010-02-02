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
* Description:   Server declaration, internal for Nokia
*
*/



#ifndef __ALF_BRIDGE_H__
#define __ALF_BRIDGE_H__

#include <e32hashtab.h>

#include "alfscreen.h"
#include "alfstreamerbridge.h"
#include "alfdecoderserverclient.h"

#include <alf/alfconstants.h>

#include "HuiFxEffect.h"
#include <alf/AlfTransEffectPlugin.h>
#include <uiacceltk/HuiDisplay.h>

class CAlfEffectEndTimer;
class CAlfCommandDebug;
class CAlfLayoutSwitchEffectCoordinator;
class RMemReadStream;

const TInt KAlfBridgeRegionGranularity = 10;

NONSHARABLE_CLASS(CAlfBridge): 
	public CBase, 
    public MAlfStreamerListener, 
    public MHuiDisplayRefreshObserver, 
    public MHuiBitmapProvider,
    public MAlfGfxEffectObserver,
    public MHuiRosterObserver
    {
	// Helper class for keeping ongoing effects in order. Kept in iEffectCleanupStack
    private:

        struct TEffectCleanupStruct
            {
            public:
                TEffectCleanupStruct(
                        TInt aHandle,
                        CHuiVisual* aEffectedVisual,
                        CHuiVisual* aTemporaryPresenterVisual,
                        TBool aIsLayout, 
                        TBool aHideWhenFinished) 
                : iHandle(aHandle), 
                iEffectedVisual(aEffectedVisual),
                iTemporaryPresenterVisual(aTemporaryPresenterVisual),
                iIsLayout(aIsLayout),
                iHideWhenFinished(aHideWhenFinished)
                        {
//                        RDebug::Printf("TEffectCleanupStruct - 0x%x 0x%x, %d", iEffectedVisual, iTemporaryPresenterVisual, iIsLayout );
                        };

                TInt iHandle;

                TBool iIsLayout;

                TBool iHideWhenFinished;
				
				// not own, unless iEffectedVisual has EShouldDestroy flag enabled
                CHuiVisual* iEffectedVisual;
				// owned
                CHuiVisual* iTemporaryPresenterVisual;
            };
            
public:

    static CAlfBridge* NewL( CAlfStreamerBridge** aHost, CHuiEnv* aEnv );
    ~CAlfBridge();
    
	void AddNewScreenL(CAlfSharedDisplayCoeControl* aSharedCoeControl);
	void AddNewScreenFromWindowL(RWindow* aWindow);
    /**
     * This method returns the index of first alf controlgroup in the roster.
     * 
     */
    TInt FirstAlfControlGroupIndex( TInt aScreenNumber );
        
    /**
     * This method returns the index of last alf controlgroup in the roster.
     * 
     */
    TInt LastAlfControlGroupIndex( TInt aScreenNumber );        
    
    /**
     * Sets flag to indicated that visual tree has changed (in every screen).
     * 
     */
    void SetVisualTreeVisibilityChanged(TBool aChanged);
    
    /**
     * Solution to reduce active visuals until we handle window tree hierarchy correctly
     */
    void HandleVisualVisibility( TInt aScreenNumber );

    /**
     * Solution to reduce active visuals until we handle window tree hierarchy correctly. 
	 *  Note: Recursive method
     */
    TBool HandleLayoutVisualVisibility(
            CHuiLayout* aLayout,
            CHuiControlGroup& aControlGroup,
            CHuiControl& aControl,
            TBool& aFullscreenCovered, 
            TRect& aFullscreen,
            CAlfScreen* aScreen,
            TBool& aSubtreeVisible,
            TBool aChildCanBeOpaque );
    /**
     * This method shows the control group in roster, however the aWhere param
     * is modified so that controlgroup appears at the right position depending on
     * controlgroup type
     *
     */
    void ShowControlGroupL(
            CHuiRoster& aRoster, 
            CHuiControlGroup& aGroup, 
            TInt aWhere, 
            TInt aScreenNumber );

    /**
     * This method sets the windowgroup id for the alf window.
     * 
     */
    void SetAlfWindowGroupId(TInt aAlfWindowGroupId);
    
    CHuiDisplay* Display(TInt aScreenNum);
    
    /**
     * AlfAppUi delegates the QT command buffer posting functionality to bridge 
     * through this function. It identifies the corrcet CHuiCanvasVisual, 
     * from the RWindow::ClientId(), that it has got from client
     * and posts the command buffer to that visual. 
     *
     * @param params  QTParams containg window information and command buffer
     * 
     */
    void PostQTCommandBufferL( TAlfQtCommandBufferParams params );
       
    /**
     * Set the client window where the visual or layout will be drawn to.
     * @param aWindowGroupId Window group id.
     * @param aClientWindowHandle Client side window handle.
     * @param aVisual Visual or layout.
     */
    void SetClientWindowForDrawingL(TInt aWindowGroupId, TInt aClientWindowHandle, CHuiVisual* aVisual);

    // This is the final callback that does the actual work
    // AlfGfxEffectEndCallBack starts a timer, and when the timer finishes,
    // it calls this function

    void TransitionFinishedHandlerL( TInt aHandle );
    
    // from  MAlfGfxEffectObserver
    
  	/**
 	 * Function to be called when CHuiFxEffect class effect has ended
  	 * @param aHandle handle of the effect, given when the effect is started
  	 */
    void AlfGfxEffectEndCallBack( TInt aHandle );
   
    TInt FindClientWindowGroupId( TInt aScreenNumber, CHuiControlGroup& aControlGroup );
    
    void RemoveAllTemporaryPresenterVisuals();

    /**
     * Helper function to abort fullscreen effect
     * @param aClientRequest ETrue if requested by client.
     */
    void HandleGfxStopEvent( TBool aClientRequest );
    
    void EnableSwRenderingL(TBool aEnable = ETrue);
    void UploadSwRenderingTargetL( CAlfScreen* aScreen );
    TBool PrepareSwRenderingTarget( CAlfScreen* aScreen );

    /**
     * Sets memory level.
     * @param aMemoryLevel memory level.
     */
    void SetMemoryLevel(THuiMemoryLevel aMemoryLevel);
    
    /**
     * Sets low memory. This is used by this class.
     * @param aEnabled ETrue if enabled, EFalse if disabled.
     */
    void SetLowMemory(TBool aEnabled);
    
    /**
     * Requests to force SW rendering to be used.
     * @param aEnabled enabled status.
     * @return error code.
     */
    TInt ForceSwRendering(TBool aEnabled);
    
    /**
     * Chooses appropriate memory level and informs
     * core toolkit.
     */
    void DoUpdateMemoryLevel();
    
    /**
     * Cancels all effects due to low memory.
     */
    void LowMemoryCancelAllEffects();
    
    // From MHuiRosterObserver
    void NotifyRosterDrawStart(CHuiDisplay& aDisplay);
    void NotifyRosterDrawEnd(CHuiDisplay& aDisplay);
    
private:    
    
    class CFullScreenEffectState;
    
    class CControlEffectState;
    
    CAlfBridge( CAlfStreamerBridge** aHost );
    
    void ConstructL(CHuiEnv* aEnv);
    
	/**
	* RegisterFadeEffectL
	*
	* Register existing fade effect from MMC (RND ONLY) or ROM.
	*/
    void RegisterFadeEffectL();

    /**
	* DoSetCachedFadeEffectL
	*
	* Resolves the fade effect filename. Speeds up fade effect loading.
	*/    
    void DoSetCachedFadeEffectL();
    
	void HandleDestroyDisplay( TInt aScreenNumber );
	
	void HandleRegisterEffectL( TAlfBridgerData data );
	
	/**
	* DoRegisterEffectL
	*
	* Register effect filename to a certain action in HuiFxEngine
	*/
	void DoRegisterEffectL(const TDesC& aFilename, TInt aAction);
	
	// effect handling
	void HandleGfxEffectsL( TAlfBridgerData data );

    // remove effect
    // This is needed if we have to abort an effect
    void HandleGfxStopEffectsL( TAlfBridgerData data );
    
	/**
	*	RemoveEffectFromApp
	*
	*	Removes effects on appui.
	*/
    void RemoveEffectFromApp(TInt aAppUid);
    
    // component effect handling
    void HandleGfxControlEffectsL( TAlfBridgerData data );
    
    /**
     * Handles begin and end fullscreen events
     */
    TBool HandleGfxEventL(CFullScreenEffectState& aEvent, CHuiLayout* aToLayout, CHuiLayout *aFromLayout);
    
	/**
	*	FreezeLayoutUntilEffectDestroyedL
	*
	*	Tries to take screenshot of the layout. If that fails, the layout will not be effected at all.
	*/
    void FreezeLayoutUntilEffectDestroyedL(CHuiLayout* aLayout, TInt aHandle);

    /**
     * Handles control effect events
     */    
    void HandleGfxControlEventL(CControlEffectState& aEvent, CHuiCanvasVisual* aCanvasVisual);
    
    /*
     * SetupEffectLayoutContainerL
     * 
     * This method creates an own layout into iFullScreenEffectControlGroup. Then it creates
     * temporary presenter visual visuals for each visual in aSourceLayout and binds them
     * using SetExternalContentL. Finally the effect entry is added to iEffectCleanupStack, 
     * thus it can be cleaned after effect completion.
	 *
	 *
	 *	@return	ETrue, 	if layout have been initialized succesfully for the effect
	 			EFalse,	if any visuals have been removed. Effect should not be applied.
     */
    TBool SetupEffectLayoutContainerL(TInt aHandle,CHuiLayout* aSourceLayout, TBool aIsExitEffect);

    /*
     *	AddEffectItemL
	 *
	 *	Prepares visual for the effect. Removes previous effect if necessary. @aItemDestroyed will return EFalse,
	 *	if the visual has been destroyed during the previous effect.
	 *	
	 *	@param	aItemDestroyed	
     */
    CHuiCanvasVisual* AddEffectItemL(
            TInt aEffectHandle,
            CHuiVisual* aSourceVisual, 
            CHuiLayout* aTargetLayout, 
            CHuiControl* aEffectControl,
            TBool aInsertTemporaryVisual,
            TBool& aItemDestroyed,
            TBool aIsExitEffect = EFalse);
            

    /*
     *	AddToEffectLayoutContainerL
     */
    void AddToEffectLayoutContainerL(
            TInt aEffectHandle,
            CHuiLayout* aSourceLayout, 
            CHuiLayout* aTargetLayout,
            CHuiControl* aEffectControlGroup,
            TInt& aItemsDestroyed,
            TBool aAddLayout = ETrue,
            TBool aIsExitEffect = EFalse);

    /*
     *	ListFamilyTreeL
     */   
    void ListFamilyTreeL( RPointerArray<CHuiLayout>& aArray, const CHuiLayout* aLayout );
    /*
     * SetupEffectLayoutContainerL
     * 
     * This method creates an own temporary presenter visual visual and binds it to aSourceVisul
     * using SetExternalContentL. Finally the effect entry is added to iEffectCleanupStack, 
     * thus it can be cleaned after effect completion.
     */
    void SetupEffectContainerL(TInt aHandle, CHuiCanvasVisual* aSourceVisual, TBool aIsExitEffect);

    /*
     * RemoveTemporaryPresenterItem
     * 
     * Effects are shown indirectly by a another visual, that is in iFullScreenEffect control group. 
     * This methods unbinds the external content and the removes temporary presenter visual 
	 * from iFullScreenEffect group and . It does not delete the CHuiFxEffect 
	 * object associated with the content visual. See also iEffectCleanupStack.  
     */
    TBool RemoveTemporaryPresenterItem(TEffectCleanupStruct& aEffectItem);

    /*
     * FindTemporaryPresenterLayout
     * 
     * Finds temporary presenter layout based on a visual.
     *
     * @param   aVisual 
     * 
     * @return  NULL, if visual does not have temporary presenter visual in the active effect list
     */
    CHuiLayout* FindTemporaryPresenterLayout(CHuiVisual* aVisual);
    
    /*
     * FindLayoutByEffectHandle
     * 
     * Application exit effect for application that does not stay background is destroyed and removed
     * from normal control groups. FindLayoutByEffectHandle is used to find the correct group 
     * in order to apply the exit effect on already "destroyed" application. 
     *
     * @param   aHandle     Effect handle.
     * 
     * @return  NULL, if visual does not have temporary presenter visual in the active effect list
     */
    CHuiLayout* FindLayoutByEffectHandle(TInt aHandle);
    
    /*
     * HasActiveEffect
     */
    TBool HasActiveEffect(CHuiVisual* aVisual);
    
   /*
	*	FindEffectHandle
	*
	*	@return 	Returns the effect handle number, which is associated with this visual. If none found, then 
	*               returns KErrNotFound.
	*/
    TInt FindEffectHandle(CHuiVisual* aVisual);
    /*
     * RemoveTemporaryPresenterVisual
     * 
     * Effects are shown indirectly by a another visual, that is in iFullScreenEffect control group. 
     * This methods unbinds the external content and the removes temporary presenter visual 
	 * from iFullScreenEffect group and . It does not delete the CHuiFxEffect 
	 * object associated with the content visual. See also iEffectCleanupStack.  
     */
    TBool RemoveTemporaryPresenterVisual(CHuiVisual* aVisual, TInt aHandle = KErrNotFound);
    
    /*
     *	RemoveTemporaryPresenterVisuals
     *	
     *	See above. 
     */
    TBool RemoveTemporaryPresenterVisuals();
    
	void HandleNewWindowL( TAlfBridgerData& aData );
	
	void DestroyWindow(CHuiVisual* aVisual, TBool aForce = EFalse);
	
	void HandleDestroyWindowL( TAlfBridgerData& aData );
	
	void HandleSetWindowPosL( TAlfBridgerData& aData );
	
	void HandleSetWindowSizeL( TAlfBridgerData& aData );
	
	void HandleSetWindowRotationL( TAlfBridgerData& aData );
	
	void HandleSetWindowOpacityL( TAlfBridgerData& aData );
	
	void HandleReorderWindowL( TAlfBridgerData& aData );
	
	void HandlePostCanvasBufferL( TAlfBridgerData& aData );
	
	void HandleSetWindowFlagL( TAlfBridgerData& aData, TInt aOp );
	
	void SetWindowActiveL(CHuiVisual* aVisual, TBool aActive);
	
	void HandleSetWindowActiveL( TAlfBridgerData& aData );
	
	void HandleSetSurfaceExtentL( TAlfBridgerData& aData );
	
	void HandleLayerUsesAlphaFlagChanged( TAlfBridgerData& aData );
	
	void HandleGetNativeWindowDataL( TAlfBridgerData& aData );

	void HandleSetCoveringBitmapL( TAlfBridgerData& aData );
	
	void HandleSetCursorDataL( TAlfBridgerData& aData );
	
	void HandleSetNodeTracking( TAlfBridgerData& aData );
	
	void HandleSetFadeEffectL( TAlfBridgerData& aData );

    void HandleSetLayoutSwitchEffectL();
	
    void ClearCanvasVisualCommandSets(TBool aInactiveOnly);
    
    void ClipVisualRect(TRect& aRect, const TRect& aClippingRect);

    TBool IsRectCoveredByRegion(TRect aRect, TRegion& aCoveringRegion);

    void ShowSessionContainerControlGroupL(
            CHuiRoster& aRoster, 
            CHuiControlGroup& aGroup, 
            TInt aWhere, 
            TInt aScreenNumber );

    void ShowWindowGroupControlGroupL(CHuiRoster& aRoster, CHuiControlGroup& aGroup, TInt aWhere, TInt aScreenNumber );
    
private:
         
    /**
     * Provide a bitmap and mask from the given UID.
     * This method should create a bitmap and its mask, usually by loading it from disk.
     *
     * @param aId      TextureManager id of this bitmap, may be used for extracting
     *                 an icon resource.
     * @param aBitmap  Output parameter for the provider: On return, has to store 
     *                 a pointer to the generated bitmap. Ownership transferred to caller.
	 *                 The support for input CFbsBitmap formats varies between 
	 *                 different renderers. See \ref cfbsbitmapsupport 
	 *                 Table describing renderer bitmap support.      
	 * @param aMaskBitmap  
	 *                 Output parameter for the provider: On return, has to store 
     *                 a pointer to the generated alpha mask or <code>NULL</code> 
     * 				   if there is no mask. Ownership of the bitmap is transferred 
     *                 to the caller.
     * 
     * @see CHuiTextureManager::CreateTextureL()
     */
    virtual void ProvideBitmapL(TInt /*aId*/, CFbsBitmap*& aBitmap, CFbsBitmap*& aMaskBitmap);
    
    /**
     * InsertVisualL
     *  
     * @param  aKey    The key object of type K to add to the array.
     * @param  aVisual  The value object of type V to associate with aKey.
     * @leave  KErrNoMemory if memory could not be allocated to store the copies of aKey and aValue.
     */
    void AddVisual( TInt aKey, TInt aClientSideId, TInt aClientSideGroupId, CHuiCanvasVisual* aVisual );
    
    /**
     * RemoveVisual
     * 
     * @param  aKey    The key to be removed.
     * @return         KErrNone if the key object and corresponding value object were
     *                 removed successfully. KErrNotFound if the key object was not present in the array.
     */
    void RemoveVisual( TInt aWindowNodeId );
    
    /**
     * FindVisual
     * 
     * AddVisual and FindVisual set the iPreviouslySearchedVisual, which speeds
     * up the sequential search of the same visual.
     * 
     * @param  aKey    The key to be removed.
     * @return         NULL if the key object is not found. Otherwise returns 
     *                 the pointer to visual corresponding the key.
     */    
    CHuiCanvasVisual* FindVisual( TInt aKey );
 
     /**
     * FindVisualByClientSideIds
     * 
     * Finds a visual based on the provided client side ids. 
	 *
     * @param  aClientSideId    The key to be removed.
     * @param  aClientSideId    The key to be removed.
     * @return         NULL if the visual was not not found. Otherwise returns 
     *                 the pointer to visual corresponding the client side keys.
     */       
    CHuiCanvasVisual* FindVisualByClientSideIds(TUint32 aClientSideId, TUint32 aClientSideGroupId );

    /**
     * This method finds controlgroup which has been assosiated with given window group id. 
     * Control group may or may not be active in roster.
     *
     * @param aWindowGroupNodeId Node id of the window group, internal.
     */
    CHuiControlGroup* FindControlGroup(TInt aWindowGroupNodeId, TInt aScreenNumber );

    /**
     * This method finds controlgroup which has been assosiated with window server window group id. 
     *
     * @param aWindowGroupNodeId window server window group id of the window group, internal.
     * @param aScreenNumber Screen number where to search, if not known KErrNotFound
     *        at return will contain the screen number where the group was found
     * @return pointer to the window group if found, NULL if not found.
     */
    CHuiControlGroup* FindControlGroupByWindowGroupId( 
            TInt aWindowGroupId, 
            TInt& aScreenNumber, 
            TAlfControlGroupEntry** aAlfGroup = NULL );

    CHuiControlGroup* FindControlGroupByAppId( TInt aAppId );
    /**
     * This method deletes controlgroup which has been assosiated with given window group id. 
     * Control group may or may not be active in roster.
     *
     * @param aWindowGroupNodeId Node id of the window group, internal.
     */
    void DeleteControlGroupL(TInt aWindowGroupNodeId, TInt aScreenNumber );

    /**
     * Creates a control group
     *
     * @param aWindowGroupNodeId Node id of the window group, internal.
     * @param aClientWindowGroupId External window group id.
     */
    CHuiControlGroup& CreateControlGroupL(
            TInt aWindowGroupNodeId, 
            TInt aClientWindowGroupId,
            TInt aSecureId,
            TInt aScreenNumber );

    /**
     * This method prepares cached and HW accelerarted versions of texts & images from
     * canvas command buffers if those buffers has not yet been handled before. 
     */
    void PrepareCanvasVisualCaches( TInt aScreenNumber );

    /**
     * This method reorders alf controlgroups to just above alf servers
     * windowgroup.
     * 
     */

    void ReorderAlfControlGroupsL( TInt aScreenNumber );
        
    /**
     * Called to notify the observer that a display refresh is about to begin.
     * The observer should prepare its state for the display.
     */
    TInt ResolveScreenNumber( CHuiDisplay& aDisplay );
    
    void NotifyDisplayRefreshStarted(CHuiDisplay& aDisplay);

    /**
     * 
     */
    TBool IsVisualOpaque(CHuiVisual& aVisual);

    /**
     * Enables default transformation steps
     */
    void EnableVisualDefaultTransformationsL(CHuiVisual& aVisual);

    /**
     * 
     */
    void HandleCallback(TInt aStatus);
    
    /**
     * 
     */
    void DoDispatchL(TInt aStatus);

    void InsertImageBrushL(CHuiVisual& aVisual, TInt aBitmapHandle);
    void UpdateImageBrushL(CHuiVisual& aVisual, TInt aBitmapHandle);
    void RemoveImageBrushL(CHuiVisual& aVisual);

    
    void DebugPrintControlGroupOrder(
            CAlfScreen& aScreen, 
            CHuiRoster& aRoster, 
            CHuiControlGroup& aGroup);
    
    void VisualizeControlGroupOrderL(
            CHuiRoster& aRoster, 
            CHuiControlGroup& aGroup);
    
    void PrintAllocMem();

    // Fading methods
    TBool SetupFadeEffectL(CHuiCanvasVisual& aVisual);
    void PrepareFadeEffects( CHuiCanvasVisual& aVisual );    
    TBool LoadFadeEffectsL( CHuiCanvasVisual& aVisual );        

    // Fading related utility methods
    static TBool CanFadeChildren( CHuiCanvasVisual& aParent );
    static TInt RecursiveChildCount( CHuiCanvasVisual& aParent, TInt aCanvasFlags );
    static TBool IsFadedByParent( CHuiCanvasVisual& aVisual );
    static TBool IsNearestParentEffectFade( CHuiCanvasVisual& aVisual );
    static TBool HasActivePaintedAreas( CHuiCanvasVisual& aVisual, TBool aIncludeChildren );
    static TBool HasActiveFadedChildren( CHuiCanvasVisual& aVisual );

private:

    RPointerArray<CAlfScreen> iAlfScreens;
    void SetCursorTimerL(TUint aTime = 0, CHuiVisual* aCursor = 0);

NONSHARABLE_CLASS ( TDeadControlGroup )
    {
public:
    TDeadControlGroup():
        iDeadGroup( 0 ),
        iScreen( 0 ),
        iLayout(NULL)
            {
            }
    TInt iDeadGroup;
    TInt iScreen;
    CHuiLayout* iLayout;
    };
    
NONSHARABLE_CLASS( TEffectControlGroupEntry )  
    {
public:
    TEffectControlGroupEntry() :    
        iHandle( KErrNotFound ),
        iVisual( NULL ),
        iEffect( NULL ),
        iAction( 0 ),
        iWindowGroupNodeId( 0 ),
        iClientWindowGroupId( 0 ),
        iScreenNumber( 0 )
            {
            }

    /** Handle of the attached effect */
    TInt iHandle;
    // Visual to which the effect has been attached */
    // This controls the case where a new effect replaces an old one.
    // If a new effect has been added to the same visual, the old one does not need
    // to be removed as adding the later effect has already removed the previous one.
    // Pointer not owned, value only saved for reference
    CHuiVisual* iVisual;
    // The effect that has been attached to the visual
    // Pointer not owned, value only saved for reference
    CHuiFxEffect* iEffect;
    // The action that is the cause of the effect (control appear or disappear)
    TInt iAction;
    /** Window group node id, internal */
    TInt iWindowGroupNodeId; 
    /** Window group id, external id seen e.g. by the application using wserv */
    TInt iClientWindowGroupId;
    TUint8 iScreenNumber;
    };

    // Array of window groups that have attached full screen effects
    RArray<TInt> iEffectWindowGroups;
    // Array of control groups that should have been deleted,
    // but have been left alive until the effect has run its course.
    RArray<TDeadControlGroup> iDeadControlGroups;
    // Array of individual controls that have attached effects
    RArray<TEffectControlGroupEntry> iEffectControls;
    
    // Array of callback data structures
    // The structures contain the handle that identifies the initiator of the effect
    // and a pointer to CAlfBridge instance to allow handling via static functions
    RArray<TInt> iEffectHandles;
        
    // iEffectCleanupStack contains the entries for effects that are currently associated 
    // with visuals in iFullscreenEffectControlGroup
    RArray<TEffectCleanupStruct> iEffectCleanupStack;
    
    // Effects that have finished by their own, or framework requested to end them
    RArray<TInt> iFinishedEffects;
    
    // Same as iEffectCleanupStack, but only the ones that can be now cleaned away.
    // See method RemoveTemporaryPresenterVisuals.
    RArray<TInt> iFinishedCleanupStackEffects;
    
	// Effects states are used for effects request that arrive before the effected 
	// window has been created. This is very common with fullscreen effects and 
	// occational with control effects.
	//
	// NOTE: control effects support currently only one "delayed" effect. This is propably
	// not sufficient for all sitations.
    NONSHARABLE_CLASS(CEffectState) : public CBase
        {
    public:    
        
        CEffectState();
         ~CEffectState();
         
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
    
    NONSHARABLE_CLASS( CControlEffectState ) : public CEffectState
        {
    public:

        TUint32 iClientHandle;
        TUint32 iClientGroupHandle;
    
        void ConstructL(TInt aAction, RMemReadStream& aStream);
        };

    NONSHARABLE_CLASS( CFullScreenEffectState ) : public CEffectState
        {
    public:
       // CFullScreenEffectState();
       // ~CFullScreenEffectState();
        
        void ConstructL(TInt aAction, RMemReadStream& aStream);

        // Information from BeginFullScreen
        TInt iType;
        TInt iWg1;
        TInt iWg2;
        TInt iToAppId;
        TInt iFromAppId;
        TRect iRect;
        
        // ETrue if waiting for window group to appear
        TBool iWaitingWindowGroup;
        // ETrue if end fullscreen has been performed
        TBool iEndFullScreen;
        // ETrue if setup effect container has been done
        TBool iSetupDone;

        // used for resolving the iCleanupStackItem that holds the frozen app layout underneath the starting application
        TInt iAppStartScreenshotItemHandle;
        };

    /**
     * Full screen effect state.
     * Own.
     */
    CFullScreenEffectState* iFullScreenEffectData;
    
    /**
     * Control effect state.
     * Own.
     */
    CControlEffectState* iControlEffectData;
        
    // these save the current full screen transition data
    // so that the correct transition can be ended from the callback
    // when the effect ends
    TInt iLastFullScreenEffectWindowGroup;
    TInt iLastFullScreenScreen;
    TInt iLastAction;
    TInt iLastEffectHandle;
    CAlfEffectEndTimer* iEffectEndTimer;
    TBool iLayoutInitializedForExitEffect;
    
    CAlfStreamerBridge** iHost;

    TInt iAlfWindowGroupId;
    TInt iAlfWindowGroupNodeId;


    CFbsBitmap* iHack; // not excactly owned..
    CFbsBitmap* iDummyMask; // not excactly owned..
    
    TBool iActivated;
    RAlfBridgerClient iBridgerClient;
    
    class THashVisualStruct
        {
    public:
        THashVisualStruct( 
                CHuiCanvasVisual* aVisual, 
                TUint32 aClientSideId,
                TUint32 aClientSideGroupId) : 
            iVisual( aVisual ), 
            iClientSideId(aClientSideId),
            iClientSideGroupId(aClientSideGroupId)
                {};
        
    public:
        CHuiCanvasVisual* iVisual;  // not own
        TInt32 iClientSideId;
        TInt32 iClientSideGroupId;
        };
    
    RHashMap<TUint32,THashVisualStruct> iWindowHashArray;
    class TRegisteredEffectsStruct
        {
    public:
        TRegisteredEffectsStruct()
            {
            iAction = 0;
            iEffectFile = NULL;
            }
    public:
        TInt iAction;
        HBufC* iEffectFile; 
        };
		
public:
    
    RArray<TRegisteredEffectsStruct> iAlfRegisteredEffects;
    CHuiEnv* iHuiEnv;
	CAlfAppUi* iAppUi;

private:    

    HBufC16* iFadeEffectFile;
    
	CHuiCanvasVisual* iPreviouslySearchedVisual;
    
	TInt iPreviouslySearchedVisualId;
	
	// For textcursor opacity
    CPeriodic* iCursorTimer;
    TUint iCursorInterval;
    CHuiVisual* iCursorVisual;

#ifdef SYMBIAN_BUILD_GCE    
    TBool iPrintFPS;
#endif

    CAlfCommandDebug* iCommandDebug;

    mutable RRegionBuf<KAlfBridgeRegionGranularity> iTempVisualRegion;
    mutable RRegionBuf<KAlfBridgeRegionGranularity> iTempIntersectingRegion;
    mutable RRegionBuf<KAlfBridgeRegionGranularity> iTempRegion;
    TBool iBgSurfaceFound;
    TBool iInLowMemMode;
    CAlfLayoutSwitchEffectCoordinator* iLayoutSwitchEffectCoordinator;
    TInt iAlfSecureId; 	    
    TBool iSwRenderingEnabled;
    
    TBool iForcedSwRendering;
    TBool iLowMemoryMode;
    THuiMemoryLevel iCurrentMemoryLevel;
    };    

#endif // __ALF_BRIDGE_H__