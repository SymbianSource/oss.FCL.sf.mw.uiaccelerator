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



#ifndef HUIEFFECTABLE_H_
#define HUIEFFECTABLE_H_

#include "HuiFxConstants.h"

class THuiRealRect;
class CHuiFxEffect;
class CHuiGc;
class CFbsBitmap;
class CHuiTexture;

class MHuiEffectable
    {
public:
    virtual ~MHuiEffectable() { }
    virtual void EffectSetEffect(CHuiFxEffect* aEffect)=0;
    virtual TReal32 EffectOpacity() const=0;
    // Sets the effect opacity to be given value if bigger than current. Use aReplace to set any value.
    // This can be used to evaluate the greatest opacity of all effect layers for this effect, so that
    // drawing can determine if effect as a whole will hide the effected visual or not
    virtual void EffectSetOpacityAdditive(TReal32 aOpacity, TBool aReplace)=0;
    virtual void EffectDrawSelf( CHuiGc &aGc, const TRect & aDisplayRect) const=0;
    virtual THuiRealRect EffectDisplayRect() const __SOFTFP=0;
    virtual void SetLoadingEffect(TBool aLoading)=0;
    virtual void EffectSetSource( THuiFxVisualSrcType aSource )=0;
    virtual THuiFxVisualSrcType EffectGetSource() const=0;
    virtual void SetExternalTexture(CHuiTexture* aTexture)=0;
    virtual CHuiTexture* ExternalTexture()=0;
    virtual TBool EffectReadyToDrawNextFrame() const = 0;
    };
    
#endif    
