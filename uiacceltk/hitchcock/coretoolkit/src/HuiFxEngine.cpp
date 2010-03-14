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



#include "HuiFxEngine.h"
#include "HuiFxEffectParser.h"
#include "HuiFxEffect.h"
#include "HuiFxEffectCache.h"
#include <uiacceltk/HuiEnv.h>
#include <uiacceltk/HuiStatic.h>
#include <uiacceltk/HuiUtil.h>
#include <bautils.h>
#include <uiacceltk/HuiDisplay.h>

#if 0
_LIT(cache1, "C:\\Data\\drop_shadow.fxml");
const TDesC *cache_array[]={ &cache1 };
TInt cache_array_size = sizeof(cache_array)/sizeof(cache_array[0]);
#endif

EXPORT_C void CHuiFxEngine::ConstructL(THuiFxEngineType aEngineType)
    {
    iType = aEngineType;
    iBuffersInUse = 0;
#ifdef HUIFX_RBCACHE_ENABLED
    iBuffersInCache = 0;
    // critical to be initialised to zeros: zero indicates an empty entry in array.
    memset(iBufferCache, '\0', sizeof(iBufferCache));
#endif
#ifdef HUIFX_EFFECTCACHE_ENABLED
    iCache = CHuiFxEffectCache::NewL();

#if 0
    // Preloading cache items
    for(int i=0;i<cache_array_size;i++)
        {
        const TDesC *filename = cache_array[i];
        if (!BaflUtils::FileExists( CHuiStatic::FsSession(), *filename ))
            {
            continue;
            }
        CHuiFxEffect *effect = NULL;
        TRect extRectI;
        TRect *extRect = &extRectI;
        CHuiFxEffectCacheEffectNode *node = new(ELeave) CHuiFxEffectCacheEffectNode(*filename, effect, 0, extRect, this);
        CleanupStack::PushL(node);
        iCache->FindOrCreateL(node); // moves ownership
        CleanupStack::Pop();
        //delete effect; // no need for this effect.
        }
#endif
#endif
    CHuiStatic::Env().AddMemoryLevelObserver(this);
    }

EXPORT_C TBool CHuiFxEngine::FxmlUsesInput1(const TDesC &aFileName)
    {
#ifdef HUIFX_EFFECTCACHE_ENABLED
    return iCache->FxmlUsesInput1(aFileName);
#endif
#ifndef HUIFX_EFFECTCACHE_ENABLED
    return EFalse;
#endif
    }

TBool CHuiFxEngine::FxmlUsesInput1(CHuiFxEffect& aEffect)
    {
    RArray<THuiFxVisualSrcType> array;
    aEffect.FxmlVisualInputs(array);
 
    TInt c = array.Count();
    for(TInt i = 0; i<c; i++)
        {
        THuiFxVisualSrcType val = array[i];
        if (val == EVisualSrcInput1)
            {
            array.Close();
            return ETrue;
            }
        }
    array.Close();
    return EFalse;    
    }

    
EXPORT_C void CHuiFxEngine::RegisterEffectL(const TDesC &aFileName)
    {
#ifdef HUIFX_EFFECTCACHE_ENABLED
    const TDesC *filename = &aFileName;
    if (!BaflUtils::FileExists( CHuiStatic::FsSession(), *filename ))
        {
        return;
        }
    CHuiFxEffect *effect = NULL;
    TRect extRectI;
    TRect *extRect = &extRectI;
    CHuiFxEffectCacheEffectNode *node = new(ELeave) CHuiFxEffectCacheEffectNode(*filename, effect, 0, extRect, this);
    CleanupStack::PushL(node);
    iCache->CreateL(node); // moves ownership
    CleanupStack::Pop();
#endif
    }

#ifdef HUIFX_EFFECTCACHE_ENABLED
EXPORT_C void CHuiFxEngine::UnRegisterEffectL(const TDesC &aFileName)
    {
    MHuiFxEffectCacheNode *node = iCache->FindDup(aFileName);
    if (node) 
        iCache->UnUse(node);
#else
EXPORT_C void CHuiFxEngine::UnRegisterEffectL(const TDesC &)
    {
#endif
    }

EXPORT_C void CHuiFxEngine::LoadEffectL(
    const TDesC& aFileName,
    CHuiFxEffect*& aEffect,
    MHuiEffectable* aVisual,
#ifndef HUIFX_EFFECTCACHE_ENABLED
    TRect* extRect,
#else
    TRect*,
#endif		
    MAlfGfxEffectObserver* aEffectEndObserver,
    TInt aHandle, 
    TInt aFlags )
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::LoadEffectL - %S, 0x%x, 0x%x"),&aFileName, aVisual, aEffect );
#endif
    if (aFileName.Length() == 0)
    	{
    	User::Leave( KErrNotFound);
    	}
    //TODO: reuse parser?
    if( aEffect != NULL ) User::Leave( KErrGeneral );
#ifndef HUIFX_EFFECTCACHE_ENABLED
    iExtRect = TRect(); // clear the extrect
    if ( extRect )
        {
        iExtRect = *extRect;
        }
    CHuiFxEffectParser* parser = CHuiFxEffectParser::NewL( *this, aVisual );
    CleanupStack::PushL( parser );
    parser->SetEffectEndObserver( aEffectEndObserver, aHandle );
    parser->SetEffectFlags( aFlags );
    // Parsing is asychronous, but we are not waiting for it to end.
    // CHuiFxEffectParser will take care of everything, and CHuiVisual
    // will kill the parser when parsing is finished or cancelled.
    aVisual->SetEffectParser( parser ); // ownership transferred
    CleanupStack::Pop( parser );    
    parser->ParseL( aFileName, iExtRect );
#endif
#ifdef HUIFX_EFFECTCACHE_ENABLED
    CHuiFxEffectCacheEffectNode *node = new (ELeave) CHuiFxEffectCacheEffectNode(aFileName, aEffect, aVisual, &iExtRect, this);
    node->SetEffectEndObserver( aEffectEndObserver, aHandle );
    node->SetEffectFlags( aFlags );
    CleanupStack::PushL(node);
    iCache->FindOrCreateL(node); // takes ownership
    CleanupStack::Pop();
#endif
    }

EXPORT_C void CHuiFxEngine::LoadGroupEffectL(
    const TDesC& aFileName,
    CHuiFxEffect*& aEffect,
    MHuiEffectable* aVisual,
    TInt aGroup,
#ifndef HUIFX_EFFECTCACHE_ENABLED
    TRect* extRect,
#else
    TRect*,
#endif		
    MAlfGfxEffectObserver* aEffectEndObserver,
    TInt aHandle,
    TInt aFlags )
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::LoadEffectL - %S, 0x%x, 0x%x"),&aFileName, aVisual, aEffect );
#endif
    if (aFileName.Length() == 0)
    	{
    	User::Leave( KErrNotFound);
    	}
    //TODO: reuse parser?
    if( aEffect != NULL ) User::Leave( KErrGeneral );
#ifndef HUIFX_EFFECTCACHE_ENABLED
    iExtRect = TRect(); // clear the extrect
    if ( extRect )
        {
        iExtRect = *extRect;
        }
    CHuiFxEffectParser* parser = CHuiFxEffectParser::NewL( *this, aVisual );
    CleanupStack::PushL( parser );
    parser->SetEffectEndObserver( aEffectEndObserver, aHandle );
    parser->SetEffectFlags( aFlags );
    // Parsing is asychronous, but we are not waiting for it to end.
    // CHuiFxEffectParser will take care of everything, and CHuiVisual
    // will kill the parser when parsing is finished or cancelled.
    aVisual->SetEffectParser( parser ); // ownership transferred
    CleanupStack::Pop( parser );    
    parser->ParseL( aFileName, iExtRect );
#endif
#ifdef HUIFX_EFFECTCACHE_ENABLED
    CHuiFxEffectCacheEffectNode *node = new (ELeave) CHuiFxEffectCacheEffectNode(aFileName, aEffect, aVisual, &iExtRect, this);
    node->SetEffectEndObserver( aEffectEndObserver, aHandle );
    if (aGroup != KErrNotFound)
    	{
		aFlags |= KHuiFxWaitGroupSyncronization;
		node->SetEffectGroup(aGroup);
    	}
    node->SetEffectFlags( aFlags );
    
    CleanupStack::PushL(node);
    iCache->FindOrCreateL(node); // takes ownership
    CleanupStack::Pop();
#endif
    }
EXPORT_C CHuiFxEngine::~CHuiFxEngine()
    {  
    iActiveEffects.ResetAndDestroy();
    iActiveEffects.Close();
#ifdef HUIFX_EFFECTCACHE_ENABLED
    delete iCache;
#endif
    CHuiStatic::Env().RemoveMemoryLevelObserver(this);
    }

EXPORT_C void CHuiFxEngine::Release()
    {
    ASSERT(iBuffersInUse == 0);
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::Release - 0x%x"),this);
#endif
#ifdef HUIFX_RBCACHE_ENABLED
    int freedBuffers = 0;
    for(int i = 0; i < CACHE_SIZE; i++)
        {
        CHuiFxRenderbuffer *entry = iBufferCache[i];
        if(entry)
            {
            ReleaseNativeRenderbuffer(entry);
            iBufferCache[i] = 0;
            freedBuffers++;
            }
        }
    // there should be as many freed buffers as there were free buffers.
    ASSERT(freedBuffers == iBuffersInCache);
#endif
    }

EXPORT_C void CHuiFxEngine::RestoreL()
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::RestoreL - 0x%x "), this);
#endif
#ifdef HUIFX_RBCACHE_ENABLED
    memset(iBufferCache, '\0', sizeof(iBufferCache));
    iBuffersInCache = 0;
#endif
    iBuffersInUse = 0;
    }

void CHuiFxEngine::NotifyEffectEndObservers()
    {
    for ( TInt i = iActiveEffects.Count() - 1; i >= 0; i-- )
        {
        CHuiFxEffect* effect = iActiveEffects[i];
        if (!effect->Changed())
            {
            effect->NotifyEffectEndObserver();
            }
        }    
    }

EXPORT_C void CHuiFxEngine::AdvanceTime(TReal32 aElapsedTime)
    {
    // TODO: Can we do anything about all this polling?
    TInt i;
    TBool refreshRequired = EFalse;
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::AdvanceTime - 0x%x "), this);   
#endif
    // Go through the list in reverse order.
// If the effect has ended, and has the callback set,
// the effect will be removed, and will no longer be part of iActiveEffects set.
// We must check if the effect is still in our list, but the indices change
// if something is removed from the middle of the list
    for ( i = iActiveEffects.Count() - 1; i >= 0; i-- )
        {
        CHuiFxEffect* effect = iActiveEffects[i];
        if (effect->Changed())
            {
            refreshRequired = ETrue;
            }
        if ( i < iActiveEffects.Count() && effect == iActiveEffects[i] && !(effect->EffectFlags() & KHuiFxWaitGroupSyncronization))
            {
            // The effect is still in its place, it did not go away yet
            effect->AdvanceTime(aElapsedTime);
            }
        }
    
    if (refreshRequired)
        {
#ifdef HUIFX_TRACE    
        RDebug::Print(_L("CHuiFxEngine::AdvanceTime - manually continue refresh "));
#endif
        CHuiStatic::Env().ContinueRefresh();
        }
    }

EXPORT_C void CHuiFxEngine::AddEffectL(CHuiFxEffect* aEffect)
    {
#ifdef HUIFX_TRACE        
    RDebug::Print(_L("CHuiFxEngine::AddEffectL - 0x%x "), aEffect);
#endif // #ifdef HUIFX_TRACE    

    iActiveEffects.AppendL(aEffect);

    // Performance improvement, but this would be better to be a special hint param in the fxml
    if (aEffect && FxmlUsesInput1(*aEffect))
        {
        TInt flags = aEffect->EffectFlags();
        flags |= KHuiFxOpaqueHint;
        aEffect->SetEffectFlags(flags);        
        }
    }

EXPORT_C void CHuiFxEngine::RemoveEffect(CHuiFxEffect* aEffect)
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::RemoveEffect - 0x%x "), aEffect);
#endif    
    TInt i = iActiveEffects.Find(aEffect);
    if (i >= 0)
        {
        iActiveEffects.Remove(i);
        }
    }

EXPORT_C TReal32 CHuiFxEngine::GetReferenceValue(THuiFxReferencePoint aPoint)
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::GetReferenceValue - %d "), aPoint);
#endif
    switch (aPoint)
        {
        case EReferencePointDisplayWidth:
        case EReferencePointDisplayRight:
            {
            CHuiDisplay* display = &CHuiStatic::Env().PrimaryDisplay(); 
            return display->VisibleArea().Size().iWidth; // was DefaultRenderbuffer()->Size().iWidth
            }
        case EReferencePointDisplayHeight:
        case EReferencePointDisplayBottom:
            {
            CHuiDisplay* display = &CHuiStatic::Env().PrimaryDisplay(); 
            return display->VisibleArea().Size().iHeight; // was DefaultRenderbuffer()->Size().iHeight
            }
        default:
            break;
        }
    // display left and top return 0
    return 0.0f;
    }

EXPORT_C THuiFxEngineType CHuiFxEngine::EngineType()
    {
    return iType;
    }

EXPORT_C CHuiFxRenderbuffer* CHuiFxEngine::AcquireRenderbuffer(const TSize& aDesiredSize)
    {
    return AcquireRenderbuffer(aDesiredSize, ETrue);
    }

CHuiFxRenderbuffer* CHuiFxEngine::AcquireRenderbuffer(const TSize& aDesiredSize, TBool aAllowLarger)
    {
    CHuiFxRenderbuffer *buffer = 0;
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::AcquireRenderbuffer - w: %d h: %d "), aDesiredSize.iWidth, aDesiredSize.iHeight);
#endif    
    
#ifdef HUIFX_RBCACHE_ENABLED
    if(!IsCacheEmpty())
        {
        buffer = LookupFreeRenderbuffer(aDesiredSize, aAllowLarger);
        }

    if(buffer == 0)     // no free or no suitable buffer available --- create new
        {
#endif        
        buffer = AcquireNativeRenderbuffer(aDesiredSize);
#ifdef HUIFX_RBCACHE_ENABLED
        if(!IsCacheEmpty())
            {
#ifdef HUIFX_TRACE                
            RDebug::Print(_L("CHuiFxEngine::AcquireRenderbuffer() --- no suitable buffer found from cache even if it is populated. Needed buffer size: %dx%d"), aDesiredSize.iWidth, aDesiredSize.iHeight);
#endif
            }
        }
    else
        {
        buffer->SetPosition(TPoint(0,0));
        buffer->EnableBackground(EFalse);
        buffer->PrepareForReuse(aDesiredSize);   // clean up the buffer
        }
#endif
    iBuffersInUse++;
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::AcquireRenderbuffer - buffer 0x%x "), buffer);
#endif
    return (CHuiFxRenderbuffer *)buffer;
    }

// try to find a reusable buffer from iFreeBufferList
#ifdef HUIFX_RBCACHE_ENABLED

CHuiFxRenderbuffer* CHuiFxEngine::LookupFreeRenderbuffer(const TSize& aDesiredSize, TBool aAllowLarger)
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::LookupFreeRenderbuffer - w: %d h: %d "), aDesiredSize.iWidth, aDesiredSize.iHeight);
#endif
#ifdef _DEBUG    
    const int preFreeBuffers = iBuffersInCache;
#endif
    CHuiFxRenderbuffer *buffer = 0;
    int i;

    for(i = 0; i < CACHE_SIZE; i++)
        {
        if(iBufferCache[i])
            {
            const TSize& bufferSize = iBufferCache[i]->Size();
            
            if (aAllowLarger)
                {
                if ((aDesiredSize.iHeight <= bufferSize.iHeight) && (aDesiredSize.iWidth <= bufferSize.iWidth))
                    {
                    buffer = iBufferCache[i];
                    iBufferCache[i] = 0;     // mark entry as empty
                    iBuffersInCache--;
                    break;                      // we've found a suitable buffer 
                    }                
                }
            else
                {
                if ((aDesiredSize.iHeight == bufferSize.iHeight) && (aDesiredSize.iWidth == bufferSize.iWidth))
                    {
                    buffer = iBufferCache[i];
                    iBufferCache[i] = 0;     // mark entry as empty
                    iBuffersInCache--;
                    break;                      // we've found a suitable buffer 
                    }                
                
                }
            }
        }
    
    // sanity check
    ASSERT(((buffer != 0) ? (preFreeBuffers == iBuffersInCache + 1) : (preFreeBuffers == iBuffersInCache)));
    
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::LookupFreeRenderbuffer - buffer 0x%x "), buffer);
#endif
    return buffer;
    }
#endif

EXPORT_C void CHuiFxEngine::ReleaseRenderbuffer(CHuiFxRenderbuffer* aBuffer)
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::ReleaseRenderbuffer - buffer: 0x%x "), aBuffer);
#endif
    ASSERT((aBuffer) && (iBuffersInUse > 0));

#ifdef HUIFX_RBCACHE_ENABLED
    if(iLowGraphicsMemoryMode || IsCacheFull())
        {
#ifdef HUIFX_TRACE            
        RDebug::Print(_L("CHuiFxEngine::ReleaseRenderbuffer() --- Renderbuffer cache full! Suspectible for memory fragmentation! Cache size is %d entries."), CACHE_SIZE);
#endif
#endif        
        ReleaseNativeRenderbuffer(aBuffer);
        aBuffer = 0;
#ifdef HUIFX_RBCACHE_ENABLED
        }
    else
        {
        InsertFreeRenderbuffer(aBuffer);        
        }
#endif
    iBuffersInUse--;
    }

#ifdef HUIFX_RBCACHE_ENABLED
void CHuiFxEngine::InsertFreeRenderbuffer(CHuiFxRenderbuffer* aBuffer)
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::InsertFreeRenderbuffer - buf: 0x%x "), aBuffer);
#endif
#ifdef _DEBUG    
	const int preiFreeBuffers = iBuffersInCache;
#endif
    
    ASSERT((aBuffer) && (!IsCacheFull()));
    
    for(int i = 0; i < CACHE_SIZE; i++)
        {
        if(iBufferCache[i] == 0)
            {
            iBufferCache[i] = aBuffer;
            iBuffersInCache++;
            aBuffer = 0;
            break;
            }
        }
    
    ASSERT((aBuffer == 0) && (preiFreeBuffers + 1 == iBuffersInCache));   // we have actually inserted the aBuffer into iFreeBufferList successfully?
    }

inline TBool CHuiFxEngine::IsCacheEmpty() const 
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::IsCacheEmpty - %d "), (iBuffersInCache == 0));
#endif
    if(iBuffersInCache == 0)
        {
        return ETrue;
        }
    else
        {
        return EFalse;
        }
    }

inline TBool CHuiFxEngine::IsCacheFull() const  
    {
#ifdef HUIFX_TRACE    
    RDebug::Print(_L("CHuiFxEngine::IsCacheFull - %d "), (iBuffersInCache == CACHE_SIZE));
#endif
    if(iBuffersInCache == CACHE_SIZE)
        {
        return ETrue;
        }
    else
        {
        return EFalse;
        }
    }
#endif

EXPORT_C void CHuiFxEngine::EnableLowMemoryState(TBool /*aEnable*/)
    {
    // deprecated
    }
    
EXPORT_C void  CHuiFxEngine::SetMemoryLevel(THuiMemoryLevel aLevel)
    {
    iLowGraphicsMemoryMode = aLevel;
    if(iLowGraphicsMemoryMode) // != Normal
        {
        ClearCache();
        }
    }

EXPORT_C void CHuiFxEngine::Composite(CHuiGc& /*aGc*/, CHuiFxRenderbuffer& /*aSource*/, const TPoint& /*aTargetPoint*/, TBool /*aOpaque*/, TInt /*aAlpha*/)
    {
    // Default implementation does nothing
    }

TInt CHuiFxEngine::LowMemoryState()
    {
    return iLowGraphicsMemoryMode;
    }

TBool CHuiFxEngine::HasActiveEffects() const
    {
    return iActiveEffects.Count() > 0;
    }

void CHuiFxEngine::ClearCache()
    {
    // Release cached render targets from effects
    for (TInt j=0; j<iActiveEffects.Count();j++)
        {
        iActiveEffects[j]->ReleaseCachedRenderTarget();
        }
    
    if(IsCacheEmpty())
        {
        return;
        }
    else
        {
        //clear cache
        for(TInt i = 0; i < CACHE_SIZE; i++)
                {
                if(iBufferCache[i] != 0)
                    {
                    ReleaseNativeRenderbuffer(iBufferCache[i]);
                    iBufferCache[i] = 0;
                    iBuffersInCache--;
                    }
                }
        }
    
    ASSERT(iBuffersInCache == 0);    
    }
	
EXPORT_C void CHuiFxEngine::BeginGroupEffect(TInt aGroup)
	{
	TInt index = iActiveEffectGroups.Find(aGroup);
	if (index == KErrNotFound)
		{
		iActiveEffectGroups.Append(aGroup);
		}
	else
		{
		// group already exists
		}
	}

EXPORT_C TInt CHuiFxEngine::ActiveGroupEffect()
	{
	if (iActiveEffectGroups.Count() > 0)
		{
		return iActiveEffectGroups[iActiveEffectGroups.Count()-1];
		}
	else
		{
		return KErrNotFound;
		}
	}

EXPORT_C void CHuiFxEngine::StartGroupEffect(TInt aGroup)
	{
	TInt index = iActiveEffectGroups.Find(aGroup);
	if (index != KErrNotFound)
		{
		iActiveEffectGroups.Remove(index);
	
		for ( TInt i = iActiveEffects.Count() - 1; i >= 0; i-- )
			{
			CHuiFxEffect* effect = iActiveEffects[i];
			TInt flags = effect->EffectFlags();
			if ((flags & KHuiFxWaitGroupSyncronization) && (effect->GroupId() == aGroup))
				{
				flags &= ~KHuiFxWaitGroupSyncronization;
				effect->SetEffectFlags(flags);
				}
			}
		}
	}
