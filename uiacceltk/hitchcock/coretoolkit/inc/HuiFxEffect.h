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
* Description:   
*
*/



#ifndef HUIFXEFFECT_H_
#define HUIFXEFFECT_H_

#include "HuiFxEngine.h"
#include <uiacceltk/HuiGc.h>

//FORWARD DECLARATIONS
class CHuiFxLayer;
class CHuiFxGroupLayer;
class MHuiEffectable;
// Hui Effect Flags
// The flags must be 1 bit flags to allow several to be set simultaneously (if needed)
const TInt KHuiFlagsNone = 0x00000000;
const TInt KHuiFadeEffectFlag = 0x00000001;
const TInt KHuiFxEffectDisableMarginsFlag = 0x2;
const TInt KHuiFxEffectExcludeChildrenFlag = 0x4;
const TInt KHuiFxWaitGroupSyncronization = 0x8;
const TInt KHuiFxDelayRunUntilFirstFrameHasBeenDrawn = 0x10;
const TInt KHuiFxDisableBackground = 0x20;
const TInt KHuiFxAlwaysBlend = 0x40;

class MAlfGfxEffectObserver
    {
    public:
    	/**
     	 * Function to be called when CHuiFxEffect class effect has ended
     	 * @param aHandle handle of the effect, given when the effect is started
     	 */
        virtual void AlfGfxEffectEndCallBack( TInt aHandle ) = 0;
    };

class CHuiFxEffect : public CBase
    {
public:
    IMPORT_C virtual ~CHuiFxEffect();
    IMPORT_C static CHuiFxEffect* NewL(CHuiFxEngine& aEngine);
    IMPORT_C void AddLayerL(const CHuiFxLayer* aLayer); // takes ownership
    IMPORT_C void AdvanceTime(TReal32 aElapsedTime);
    IMPORT_C TBool Draw(CHuiGc& aGc, const TRect& aDisplayRect);
    IMPORT_C CHuiFxEngine& Engine() const;
    IMPORT_C TBool VisualArea(TRect& aRect) const;
    IMPORT_C TBool Changed();
    IMPORT_C void SetEffectEndObserver( MAlfGfxEffectObserver* aEffectEndObserver, TInt aHandle );
    void NotifyEffectEndObserver();

    IMPORT_C TBool IsAnimated() const;
    IMPORT_C TBool IsTransformed() const;
    TBool IsSemitransparent() const;
    

public: // effect cache methods
    IMPORT_C CHuiFxEffect *CloneL() const;
    IMPORT_C void SetExtRect( TRect *aExtRect );
    IMPORT_C void SetVisual( CHuiVisual *aVisual );
    IMPORT_C void SetVisual( MHuiEffectable *aVisual );
    IMPORT_C void SetEngine( CHuiFxEngine *aEngine );

    IMPORT_C void SetEffectFlags( TInt aFlags );
    IMPORT_C void SetEffectGroup(TInt aGroupId);
    IMPORT_C TInt EffectFlags();
    IMPORT_C TInt GroupId();

    // Effect cached render target methods    
    TBool IsCachedRenderTargetSupported() const;
    TBool IsCachedRenderTargetPreferred() const;
    
    void ForceCachedRenderTargetUsage(TBool aUseCachedRenderTarget);
    
    void PrepareCachedRenderTarget(const TPoint& aPosition, const TSize& aSize, TBool aClear, TBool aEnableBackground);
    void ReleaseCachedRenderTarget();
    
    /*
     * CachedDraw is typically much faster than normal draw as it keeps effect result in pre-rendered format
     * instead of doing it on-the-fly as normal draw. There are however few issues that must be noted:
     * 
     * - If visual content has changed, caller is then responsible for setting param aRefreshCachedRenderTarget=ETrue
     *   so that effect gets refreshed.
     * - Caching does not make sense for animated effects, this method automatically defaults to normal
     *   drawing if the effect is animated
     * - All renderers do not (yet) support cached drawing
     * - If memory is low, cached drawing may not succed.    
     *   
     *  @param aGc
     *  @param aDisplayRect
     *  @param aRefreshCachedRenderTarget ETrue makes sure that effect is rendered, EFalse may use cached
     *         result if it is otherwise possible.
     *  @param  aOpaque, can be used for optimization so that when set to ETrue content behind visual is 
     *          not read from drawing surface.
     *  @param  aClipRegion If region contains rects, final composition to display is clipped according to
     *          defined region.          
     *                   
     *  @return ETrue if drawing was done, otherwise EFalse   
     */
    TBool CachedDraw(CHuiGc& aGc, const TRect& aDisplayRect, TBool aRefreshCachedRenderTarget, TBool aOpaque, const TRegion& aClipRegion, TInt aAlpha = 255);
    TBool CachedDraw(CHuiGc& aGc, const TRect& aDisplayRect, TBool aRefreshCachedRenderTarget, TBool aOpaque);

    void FxmlVisualInputs(RArray<THuiFxVisualSrcType> &aArray);
private:

    TBool IsAppliedToBackground();
    TBool IsFiltered() const;
    
    
protected:
    CHuiFxEffect( CHuiFxEngine& aEngine );
    void ConstructL();
        
    CHuiFxGroupLayer*        iRoot;
    CHuiFxEngine*            iEngine;
    // The observer that wants to be called when the effect finishes
    // If no observer has been set, the pointer is NULL
    // This pointer is not owned, so it must not be deleted
    MAlfGfxEffectObserver*   iEffectEndObserver;
    // The effect handle that will be returned to the observer when effect finishes
    TInt                     iHandle;
    // The flags will indicate special cases that will need special handling (like fade)
    TInt                     iFlags;
    // Cached render target which holds the effect result in pre-rendered format
    CHuiFxRenderbuffer* iCachedRenderTarget;
    
    TBool iForcedUseCachedRenderTarget;
    
    // Used for syncronizing effect start of effects with same group id. 
    // See also KHuiFxWaitGroupSyncronization
    TInt iGroupId;
	
    TInt iFramesDrawn;
    };

#endif /*HUIFXEFFECT_H_*/
