/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:   Implementation of CHuiS60Skin. CHuiS60Skin is a HUITK skin 
*                that uses resources from the current S60 skin.
*
*/



#include "uiacceltk/HuiS60Skin.h"  // Class definition
#include "uiacceltk/HuiStatic.h"
#include "HuiRenderPlugin.h"
#include "uiacceltk/HuiTextureManager.h"
#include "uiacceltk/HuiTexture.h"
#include "uiacceltk/HuiEnv.h"
#include "uiacceltk/HuiGc.h"
#include "uiacceltk/HuiUtil.h"
#include "uiacceltk/HuiDisplay.h"

#include <AknsDrawUtils.h>
#include <AknUtils.h>

#include "huiskinbackroundlayout.h"


struct TBackgroundTexture
    {
    TAknsItemID iID;
    CHuiTexture* iBackgroundTexture;    //not owned
    };
    
struct TPrivData
    {
    RArray<TBackgroundTexture> iBackgrounds;
    };


    
EXPORT_C CHuiS60Skin::CHuiS60Skin(CHuiEnv& aEnv)
    : CHuiSkin(aEnv)
    {
    iSpare = NULL;
    }


EXPORT_C void CHuiS60Skin::ConstructL()
    {
    iSkinControlContext = CAknsBasicBackgroundControlContext::NewL(
        KAknsIIDQsnBgScreen, TRect(TPoint(0, 0), HuiUtil::ScreenSize()), ETrue);
    iSpare = new (ELeave) TPrivData;
    iSkinChanged = ETrue;
    }


EXPORT_C CHuiS60Skin::~CHuiS60Skin()
    {
    FreeBackgrounds();
    delete (TPrivData*)(iSpare);
    delete iSkinControlContext;
    delete iBackgroundTexture;
    if (iSkinSrvConnected)
        iSkinSrvSession.Close();
        
   delete iBackgroundBitmap;
    }


EXPORT_C THuiSkinLocation CHuiS60Skin::Location(THuiSkinElement aElement)
    {
    // Changed so that correct cba location is asked from AknLayouUtils
    switch(aElement)
         {
         case EHuiSkinElementSoftKeys:
            {
            THuiSkinLocation retValue;
            AknLayoutUtils::TAknCbaLocation skLocation; 
            skLocation = (AknLayoutUtils::TAknCbaLocation)CHuiStatic::CbaLocation();
            switch ( skLocation )
                {
                default:
                    // falltrough
                case AknLayoutUtils::EAknCbaLocationBottom:
                    {
                    retValue = EHuiSkinLocationBottom;
                    break;
                    }
                case AknLayoutUtils::EAknCbaLocationRight:
                    {
                    retValue = EHuiSkinLocationRight;
                    break;
                    }
                case AknLayoutUtils::EAknCbaLocationLeft:
                    {
                    retValue = EHuiSkinLocationLeft;
                    break;
                    }
                }
            return retValue;
            }

        default:
            {
            return EHuiSkinLocationNone;
            }
        }
   }


MAknsSkinInstance* CHuiS60Skin::SkinInstance() const
    {
    MAknsSkinInstance* skin = 0;
    if ( CCoeEnv::Static())
        {
        skin = AknsUtils::SkinInstance();
        if(!skin )
            {
            TRAP_IGNORE( AknsUtils::InitSkinSupportL() )
            skin = AknsUtils::SkinInstance();
            }
        }
    return skin;
    }


void CHuiS60Skin::UpdateBackgroundL()
    {
    if(iBackgroundTexture)
         {
         iBackgroundTexture->Reset();
         delete iBackgroundTexture;
         iBackgroundTexture = 0;
         }

    HUI_DEBUG1(_L("CHuiS60Skin::UpdateBackgroundL - Free memory in the beginning: %i"), HuiUtil::FreeMemory());
    iBackgroundTexture = CreateSkinBackgroundL(KAknsIIDQsnBgScreen);
    iBackgroundTexture->SetSkinContent(ETrue);
    iBackgroundTexture->iContentObservers.AppendL(*this);

    HUI_DEBUG1(_L("CHuiS60Skin::UpdateBackgroundL - Free memory at exit: %i"), HuiUtil::FreeMemory());
    }


void CHuiS60Skin::SkinContentChanged()
    {
    iSkinChanged = ETrue;
    }

void CHuiS60Skin::SkinConfigurationChanged(
    const TAknsSkinStatusConfigurationChangeReason aReason )
    {
    
    }
void CHuiS60Skin::SkinPackageChanged(
    const TAknsSkinStatusPackageChangeReason aReason )
    {
    
    }


EXPORT_C const CHuiTexture& CHuiS60Skin::TextureL(TInt aSkinTextureId)
    {
    // Create S60 theme specific background texture

    // If Bitgdi renderer is used, do not create a copy of background 
    // image, but return the default dummy texture.
    if(aSkinTextureId == EHuiSkinBackgroundTexture && 
    	CHuiStatic::Renderer().Id () != EHuiRenderPluginBitgdi) 
        {
        if(!iBackgroundTexture || iReloadBackground || iSkinChanged)
            {
            UpdateBackgroundL();
            iReloadBackground = EFalse;
            }
        return *iBackgroundTexture;
        }
        
    // Otherwise use the default textures        
    return CHuiSkin::TextureL(aSkinTextureId);
    }


EXPORT_C void CHuiS60Skin::ReleaseTexture(TInt aSkinTextureResource)
    {
    HUI_DEBUG(_L("CHuiS60Skin::ReleaseTexture() - Called."));
    
    // Release background texture
    if(aSkinTextureResource == EHuiSkinBackgroundTexture)
        {
        HUI_DEBUG(_L("CHuiS60Skin::ReleaseTexture() - Destroying background texture."));
        
        delete iBackgroundTexture;
        iBackgroundTexture = NULL;
        }
    else
        {
        // Otherwise use the default method
        return CHuiSkin::ReleaseTexture(aSkinTextureResource);
        }                
    }


EXPORT_C void CHuiS60Skin::NotifyDisplaySizeChangedL()
    {
    // The background is now different.
    iReloadBackground = ETrue;
    SkinContentChanged(); // for changing the iSkinChanged flag
    Env().NotifySkinChangedL();
    Env().TextStyleManager().NotifyDisplaySizeChangedL();
    ReloadBgTexturesL();
    }


EXPORT_C TRgb CHuiS60Skin::StyleTextColor(THuiPreconfiguredTextStyle aStyle,
                                          THuiBackgroundType aBackgroundType) const
    {
    // Default text color depends directly on the background type.
    TRgb defaultColor = (aBackgroundType == EHuiBackgroundTypeLight? KRgbBlack : KRgbWhite);

    switch(aStyle)
        {
        default:
            break;

        case EHuiTextStyleSupplement:
            return TRgb(128, 128, 128);
        }

    return defaultColor;
    }


EXPORT_C void CHuiS60Skin::RestoreTextureContentL(CHuiTexture& aTexture)
    {
    if(&aTexture == iBackgroundTexture)
        {
        iReloadBackground = ETrue;
        TextureL(EHuiSkinBackgroundTexture);
        }
    else
        {
        CHuiSkin::RestoreTextureContentL(aTexture);
        }
    }

EXPORT_C void CHuiS60Skin::SkinExtension(const TUid& aExtensionUid, TAny** aExtensionParameters)
    {
    CHuiSkin::SkinExtension(aExtensionUid,aExtensionParameters);
    }
    
EXPORT_C THuiSkinOrientation CHuiS60Skin::Orientation() const
    {
    return CHuiSkin::Orientation();
    }
         
EXPORT_C void CHuiS60Skin::SetContext(CHuiGc& aGc)
    {
    CHuiSkin::SetContext(aGc);
    }

EXPORT_C CHuiGc& CHuiS60Skin::Context() const
    {
    return CHuiSkin::Context();
    }

EXPORT_C TInt CHuiS60Skin::GetTexture(TInt aSkinTextureResource, const CHuiTexture*& aOutTexture)
    {
    return CHuiSkin::GetTexture(aSkinTextureResource, aOutTexture);
    }


void CHuiS60Skin::FreeBackgrounds()
    {
    if (CHuiStatic::Renderer().Id () == EHuiRenderPluginBitgdi)
        {
        // no need to render the skin backgrounds separately on shitgdi
        return;
        }

    if (!iSpare)
        {
        return;
        }

    TBackgroundTexture bgTexture;
    TInt itemCount = ((TPrivData*)(iSpare))->iBackgrounds.Count(); 
    for (TInt index = 0; index < itemCount; index++)
        {
        bgTexture = ((TPrivData*)(iSpare))->iBackgrounds[index];
        delete bgTexture.iBackgroundTexture;
        bgTexture.iBackgroundTexture = NULL;
        }
    ((TPrivData*)(iSpare))->iBackgrounds.Reset(); 
    
    }
    
    
CHuiTexture* CHuiS60Skin::CreateSkinBackgroundL(const TAknsItemID& aID)
    {
    // Update the background image.
    if (!iSkinSrvConnected)
        {
        User::LeaveIfError(iSkinSrvSession.Connect(this));
        iSkinSrvConnected = ETrue;
        }
    
    MAknsSkinInstance* skin = SkinInstance();
    CHuiTexture* texture = CHuiTexture::NewL();
    
    CleanupStack::PushL(texture);            
    if(iSkinChanged)
         {
     
        delete iBackgroundBitmap; 
        iBackgroundBitmap = NULL;
        
        if (skin)
            {
            TRect dummy;
            TRect skinRect;
            GetRectForItem(aID, dummy, skinRect);
    
            iBackgroundBitmap = new (ELeave) CFbsBitmap();
            User::LeaveIfError( iBackgroundBitmap->Create(skinRect.Size(), EColor64K) );        
    
            CFbsBitmapDevice* device = CFbsBitmapDevice::NewL(iBackgroundBitmap);
            CleanupStack::PushL(device);
    
            CFbsBitGc* gc = 0;
            User::LeaveIfError( device->CreateContext(gc) );
            CleanupStack::PushL(gc);
            iSkinControlContext->SetRect(skinRect);
            iSkinControlContext->SetBitmap(aID);
    
            AknsDrawUtils::DrawBackground(skin, iSkinControlContext, NULL, *gc, TPoint(0,0), skinRect,
                              KAknsDrawParamDefault);
    
            CleanupStack::PopAndDestroy(gc);
            CleanupStack::PopAndDestroy(device);
            }
        else
            {
            iBackgroundBitmap = CHuiStatic::GetBgBitmapLC(aID);   
            CleanupStack::Pop( iBackgroundBitmap );
            }
         }
    texture->UploadL(*iBackgroundBitmap,NULL,EHuiTextureUploadFlagRetainResolution );            
    
    CleanupStack::Pop(texture);
    iSkinChanged = EFalse;
    return texture;
    }

void CHuiS60Skin::ReloadBgTexturesL()
    {
    if (CHuiStatic::Renderer().Id () == EHuiRenderPluginBitgdi )
        {
        // no need to render the skin backgrounds separately on bitgdi
        return;
        }
    TBackgroundTexture bgTexture;
    TInt itemCount = ((TPrivData*)(iSpare))->iBackgrounds.Count(); 
    for (TInt index = 0; index < itemCount; index++)
        {
        bgTexture = ((TPrivData*)(iSpare))->iBackgrounds[index];
        delete bgTexture.iBackgroundTexture;
        bgTexture.iBackgroundTexture = CreateSkinBackgroundL(bgTexture.iID);
        ((TPrivData*)(iSpare))->iBackgrounds[index] = bgTexture;
        }
    }

void CHuiS60Skin::UpdateBackgroundsL(const RArray<THuiDisplayBackgroundItem>& aItems)
    {
    if (CHuiStatic::Renderer().Id () == EHuiRenderPluginBitgdi)
        {
        // no need to render the skin backgrounds separately on shitgdi
        return;
        }
    FreeBackgrounds();    
    
    THuiDisplayBackgroundItem bgItem;
    TBackgroundTexture bgTexture;
    for (TInt index = 0; index < aItems.Count(); index++)
        {
        bgItem = aItems[index];
        if (bgItem.ClearMode() == CHuiDisplay::EClearWithSkinBackground)
            {
            bgTexture.iID = bgItem.SkinBackground();
            bgTexture.iBackgroundTexture = CreateSkinBackgroundL(bgItem.SkinBackground());
            ((TPrivData*)(iSpare))->iBackgrounds.Append(bgTexture);
            }
        }           
    }

EXPORT_C CHuiTexture* CHuiS60Skin::BackgroundTexture(const TAknsItemID& aID)
    {
    if (CHuiStatic::Renderer().Id () == EHuiRenderPluginBitgdi)
        {
        // only opengl has separate skin bg textures.
        return NULL;
        }
    if (!iSpare)
        {
        return NULL;
        }
    TBackgroundTexture bgTexture;
    TInt itemCount = ((TPrivData*)(iSpare))->iBackgrounds.Count(); 
    for (TInt index = 0; index < itemCount; index++)
        {
        bgTexture = ((TPrivData*)(iSpare))->iBackgrounds[index];
        if (bgTexture.iID == aID)
            {
            return bgTexture.iBackgroundTexture;
            }
        }
    return NULL;
    }
