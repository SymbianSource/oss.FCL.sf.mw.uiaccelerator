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



#include "HuiFxEffect.h"
#include "HuiFxGroupLayer.h"
#include "HuiRenderPlugin.h"
#include "HuiCmdBufferBrush.h" // MHuiEffectable

EXPORT_C CHuiFxEffect* CHuiFxEffect::NewL(CHuiFxEngine& aEngine)
    {
    CHuiFxEffect* e = new (ELeave) CHuiFxEffect( aEngine );
    CleanupStack::PushL(e);
    e->ConstructL();
    CleanupStack::Pop(e);
    return e;
    }

CHuiFxEffect::CHuiFxEffect( CHuiFxEngine& aEngine ) :
    iEngine( &aEngine )
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEffect::CHuiFxEffect - 0x%x"), this);
#endif
    }
EXPORT_C CHuiFxEffect *CHuiFxEffect::CloneL() const
{
   CHuiFxEffect *effect = new (ELeave)CHuiFxEffect(*iEngine);
   effect->iRoot = iRoot->CloneL();
   effect->iEffectEndObserver = iEffectEndObserver;
   effect->iHandle = iHandle;
   return effect;
}
EXPORT_C void CHuiFxEffect::SetExtRect( TRect *aExtRect )
    {
    iRoot->SetExtRect(aExtRect);
    }
EXPORT_C void CHuiFxEffect::SetVisual( CHuiVisual *aVisual )
    {
    iRoot->SetVisual(aVisual);
    }
EXPORT_C void CHuiFxEffect::SetVisual( MHuiEffectable *aEffectable )
    {
    iRoot->SetVisual(aEffectable);
    }
EXPORT_C void CHuiFxEffect::SetEngine( CHuiFxEngine *aEngine )
    {
    iEngine = aEngine;
    iEngine->AddEffectL(this);
    }

EXPORT_C void CHuiFxEffect::ConstructL( )
    {
    iRoot = CHuiFxGroupLayer::NewL(ETrue);
#ifndef HUIFX_EFFECTCACHE_ENABLED    
    iEngine->AddEffectL(this);
#endif
    }

EXPORT_C CHuiFxEffect::~CHuiFxEffect()
    {
    delete iRoot;
    iRoot = NULL;
    
    NotifyEffectEndObserver();
    
    ReleaseCachedRenderTarget();
    
    iEngine->RemoveEffect(this);
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEffect::~CHuiFxEffect - 0x%x"), this);
#endif
    }

void CHuiFxEffect::NotifyEffectEndObserver()
    {
    if ( iEffectEndObserver )
        {
        // The callback can be called only once when the effect finishes
        iEffectEndObserver->AlfGfxEffectEndCallBack( iHandle );
        iEffectEndObserver = NULL;
        iHandle = 0;
        }    
    }

EXPORT_C void CHuiFxEffect::AddLayerL(const CHuiFxLayer* aLayer)
    {
    iRoot->AddLayerL(aLayer);
    }

void CHuiFxEffect::ReleaseCachedRenderTarget()
    {
    if (iCachedRenderTarget)
        {
        iEngine->ReleaseRenderbuffer(iCachedRenderTarget);
        iCachedRenderTarget = NULL;
        }                
    }

void CHuiFxEffect::PrepareCachedRenderTarget(const TPoint& aPosition, const TSize& aSize, TBool aClear, TBool aEnableBackground)
    {
    // If size has chnaged, we must delete old one
    if (iCachedRenderTarget && 
        iCachedRenderTarget->Size() != aSize)
        {
        ReleaseCachedRenderTarget();
        }            
    
    // Accure new buffer
    if (!iCachedRenderTarget)
        {
        iCachedRenderTarget = iEngine->AcquireRenderbuffer(aSize, EFalse);                    
        }    
    
    if (iCachedRenderTarget)
        {
        // Set render buffer position in screen coordinates
        iCachedRenderTarget->SetPosition(aPosition);                 
        
        // Enable background if needed
       iCachedRenderTarget->EnableBackground(aEnableBackground);

       // Clear if requested
        if (aClear)
            {
            iCachedRenderTarget->PrepareForReuse(iCachedRenderTarget->Size());
            }        
        }    
    }

void CHuiFxEffect::ForceCachedRenderTargetUsage(TBool aUseCachedRenderTarget)
    {
    iForcedUseCachedRenderTarget = aUseCachedRenderTarget;
    }

TBool CHuiFxEffect::IsCachedRenderTargetPreferred() const
    {
    // Prefer use cached render target if 
    //
    // 1. I am filter effect. 
    //    Note that this does not provide good performance if effect 
    //    is animated, but noncached version does not work visually correctly 
    //    in rotated display if effect is applied to background as well.
    //    -> TODO: Return EFalse if effect has animated filter which does not use background pixels 
    // 
    // 2. User has set force flag
    //
    if (iForcedUseCachedRenderTarget || iRoot->IsFiltered())
        {
        return ETrue;
        }
    else
        {
        return EFalse;
        }
    }

TBool CHuiFxEffect::IsCachedRenderTargetSupported() const
    {
    // Can use cached render target if
    //
    // 1. Render supports it (openvg for now).
    // 2. Engine is not in low memory mode.
    //
    if (iEngine->EngineType() == EHuiFxEngineVg10 && 
        !iEngine->LowMemoryState()) // normal
        {
        return ETrue;
        }
    else
        {
        return EFalse;
        }
    }

TBool CHuiFxEffect::CachedDraw(CHuiGc& aGc, const TRect& aDisplayRect, TBool aRefreshCachedRenderTarget, TBool aOpaque)
    {
    RRegion dummy;
    TBool ret = CachedDraw(aGc, aDisplayRect, aRefreshCachedRenderTarget, aOpaque, dummy);
    dummy.Close();
    return ret;
    }

// TODO: effect area should be reduced if aClipRegion is smaller than aDisplayRect.
TBool CHuiFxEffect::CachedDraw(CHuiGc& aGc, const TRect& aDisplayRect, TBool aRefreshCachedRenderTarget, TBool aOpaque, const TRegion& aClipRegion, TInt aAlpha)
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEffect::CachedDraw - 0x%x"), this);
#endif    
    iFramesDrawn++;
    if (!CHuiStatic::Renderer().Allows(EHuiRenderPluginAllowVisualPBufferSurfaces))
        {
        return EFalse;
        }
            
    
    CHuiFxRenderbuffer* target = NULL;
    
    // Prepare all layers
    TRect displayArea = aGc.DisplayArea();
    TRect targetArea = aDisplayRect;
    targetArea.Intersection(displayArea);

    if (targetArea.Width() <= 0 || targetArea.Height() <= 0)
        {
        // Not visible
        return ETrue;
        }

    if (!iEngine || !iRoot)
        {
        return EFalse;
        }

    if (iEngine->LowMemoryState())
        {
        // No memory, no effects.
        return EFalse;
        }
    
    // Check if margins are allowed to be used for this effect
    if (EffectFlags() & KHuiFxEffectDisableMarginsFlag)
        {
        iRoot->EnableMargin(EFalse);
        }
    
    iRoot->SetTargetRect(targetArea);
    iRoot->SetSourceRect(targetArea);        
    iRoot->SetDisplayArea(displayArea);
    
    TRAPD(err, iRoot->PrepareDrawL(*iEngine));
    
    if (err != KErrNone)
        {
        return EFalse;
        }

    if (IsCachedRenderTargetSupported() && IsCachedRenderTargetPreferred())
        {
        // Background needs to be captured from surface if effect uses background AND 
        // Visual is transparent or margin is enabled AND
        // Background has not been disabled with a effect specific flag
        TBool enableBackground = IsAppliedToBackground() && (!aOpaque || iRoot->IsMarginEnabled()) && !(EffectFlags() & KHuiFxDisableBackground);
        
        // Check if cache is up-to date or does it need to be refreshed
        TBool cachedRenderTargetNeedsRefresh = (iRoot->Changed() || aRefreshCachedRenderTarget || enableBackground);

        // Try to apply also margins, we cannot just use aDisplayRect directly
        TRect targetRect = iRoot->VisualRect();
        
        // Size is always same as target rect. It contains margins if those are enabled.
        TSize cachedRenderTargetSize = targetRect.Size();        
                
        // Prepare cached offscreen render target
        PrepareCachedRenderTarget(targetRect.iTl, cachedRenderTargetSize, cachedRenderTargetNeedsRefresh, enableBackground);
        
        // If it is available, then lets do it 
        if (iCachedRenderTarget)
            {
            // Disable clipping, otherwise strange things happen.
            aGc.Disable(CHuiGc::EFeatureClipping);             
            if (cachedRenderTargetNeedsRefresh)
                {
                // Render to cached render target
                iRoot->Draw(*iEngine, aGc, *iCachedRenderTarget, *iCachedRenderTarget);                
#ifdef HUIFX_TRACE    
                RDebug::Print(_L("CHuiFxEffect::CachedDraw - refreshed cached render buffer 0x%x"), this);
#endif
                }            

            if (aClipRegion.Count())
                {
                aGc.Enable(CHuiGc::EFeatureClipping);
                aGc.PushClip();
                aGc.Clip(aClipRegion);
                }
            
            // Write cached buffer to the display
            iEngine->Composite(aGc, *iCachedRenderTarget, targetRect.iTl, aOpaque && !(EffectFlags() & KHuiFxAlwaysBlend), aAlpha);

            if (aClipRegion.Count())
                {
                aGc.PopClip();
                }
            
            aGc.Enable(CHuiGc::EFeatureClipping);
#ifdef HUIFX_TRACE    
            RDebug::Print(_L("CHuiFxEffect::CachedDraw - Cached render buffer drawn 0x%x"), this);
            RDebug::Print(_L("CHuiFxEffect::CachedDraw - displayrect: %i,%i, %i,%i "), 
                    aDisplayRect.iTl.iX,
                    aDisplayRect.iTl.iY,
                    aDisplayRect.iBr.iX,
                    aDisplayRect.iBr.iY);
#endif            
            }
        else
            {
            // It might not be available e.g. in low memory situations, just indiacte that we could not draw.
            return EFalse;
            }
        }
    else
        {
        // Release cached render target just in case it is reserved for some reason
        ReleaseCachedRenderTarget();

        // Use default onscreen render target
        if (!target)
            {
            target = iEngine->DefaultRenderbuffer();
            }
        
        if (!target)
            {
            return EFalse;
            }
        
        // Normal drawing
        iRoot->Draw(*iEngine, aGc, *target, *target);
        }
                
    return ETrue;    
    }

EXPORT_C TBool CHuiFxEffect::Draw(CHuiGc& aGc, const TRect& aDisplayRect)
    {
    // Prepare all layers
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEffect::Draw - 0x%x"), this);
#endif
    iFramesDrawn++;
    if (!CHuiStatic::Renderer().Allows(EHuiRenderPluginAllowVisualPBufferSurfaces))
        {
        return EFalse;
        }
            
    TRect displayArea = aGc.DisplayArea();
    TRect targetArea = aDisplayRect;
    targetArea.Intersection(displayArea);

    if (targetArea.Width() <= 0 || targetArea.Height() <= 0)
        {
        // Not visible
        return ETrue;
        }

    if (!iEngine || !iRoot)
        {
        return EFalse;
        }

    if (iEngine->LowMemoryState())
        {
        // No memory, no effects.
        return EFalse;
        }
    
    // Check if margins are allowed to be used for this effect
    if (EffectFlags() & KHuiFxEffectDisableMarginsFlag)
        {
        iRoot->EnableMargin(EFalse);
        }
    
    iRoot->SetDisplayArea(displayArea);
    iRoot->SetTargetRect(targetArea);
    iRoot->SetSourceRect(targetArea);
    
    TRAPD(err, iRoot->PrepareDrawL(*iEngine));
    
    if (err != KErrNone)
        {
        return EFalse;
        }
    
    CHuiFxRenderbuffer* target = iEngine->DefaultRenderbuffer();
    
    if (!target)
        {
        return EFalse;
        }

    iRoot->Draw(*iEngine, aGc, *target, *target);
    return ETrue;
    }

EXPORT_C TBool CHuiFxEffect::VisualArea(TRect& aRect) const
    {
    return iRoot->VisualArea(aRect);
    }

EXPORT_C CHuiFxEngine& CHuiFxEffect::Engine() const
    {
    return *iEngine;
    }

EXPORT_C TBool CHuiFxEffect::Changed()
    {
    TBool changed = iRoot->Changed();
    return changed;
    }
    
EXPORT_C void CHuiFxEffect::SetEffectEndObserver( MAlfGfxEffectObserver* aEffectEndObserver, TInt aHandle )
    {
    iEffectEndObserver = aEffectEndObserver;
    iHandle = aHandle;
    }

EXPORT_C void CHuiFxEffect::SetEffectFlags( TInt aFlags )
    {
    iFlags = aFlags;
    }

EXPORT_C void CHuiFxEffect::SetEffectGroup(TInt aGroupId)
    {
    iGroupId = aGroupId;
    }

EXPORT_C TInt CHuiFxEffect::EffectFlags()
    {
    return iFlags;
    }

EXPORT_C TInt CHuiFxEffect::GroupId()
    {
    return iGroupId;
    }

EXPORT_C void CHuiFxEffect::AdvanceTime(TReal32 aElapsedTime)
    {
    if (iFlags & KHuiFxDelayRunUntilFirstFrameHasBeenDrawn)
        {
        if (iFramesDrawn)
            {
            if (iFramesDrawn == 1)
                {
                aElapsedTime = 0;
                iFramesDrawn++;
                }
            iRoot->AdvanceTime(aElapsedTime);
            }
        else
            {
            }
        }
    else
        {
        iRoot->AdvanceTime(aElapsedTime);
        }
    }
    
EXPORT_C TBool CHuiFxEffect::IsAnimated() const
    {
    if (iRoot && iRoot->IsAnimated())
        {
        return ETrue;        
        }
    else
        {
        return EFalse;
        }    
    }

EXPORT_C TBool CHuiFxEffect::IsTransformed() const
    {
    if (iRoot && iRoot->IsTransformed())
        {
        return ETrue;        
        }
    else
        {
        return EFalse;
        }            
    }

TBool CHuiFxEffect::IsFiltered() const
    {
    if (iRoot && iRoot->IsFiltered())
        {
        return ETrue;        
        }
    else
        {
        return EFalse;
        }            
    }

TBool CHuiFxEffect::IsAppliedToBackground()
    {
    if (iRoot && iRoot->LayerCount())
        {
        if (iRoot->Layer(0).Type() == ELayerTypeGroup)
            {
            // If first layer after root is group, then effect is not applied to background (?)
            return EFalse;    
            }
        else
            {
            if (IsFiltered())
                {
                return ETrue;
                }
            else
                {
                // Not filter effect -> cannot be applied to background.
                return EFalse;
                }
            } 
        }            
    return EFalse;    
    }

TBool CHuiFxEffect::IsSemitransparent() const
    {
    if (iRoot && iRoot->IsSemitransparent())
        {
        return ETrue;        
        }
    else
        {
        return EFalse;
        }            
    }

void CHuiFxEffect::FxmlVisualInputs(RArray<THuiFxVisualSrcType> &aArray)
    {
    iRoot->FxmlVisualInputs(aArray);
    }
