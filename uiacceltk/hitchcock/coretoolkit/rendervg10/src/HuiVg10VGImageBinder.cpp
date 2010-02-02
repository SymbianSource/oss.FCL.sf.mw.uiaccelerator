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
* Description:   Class HuiVg10VGImageBinder
*
*/

#include "HuiVg10VgImageBinder.h"
#include "HuiVg10RenderPlugin.h"
#include "uiacceltk/HuiUtil.h"

CHuiVg10VgImageBinder::CHuiVg10VgImageBinder(CHuiVg10RenderPlugin* aRenderPlugin):
    iRenderPlugin(aRenderPlugin)
    {
    }

void CHuiVg10VgImageBinder::ConstructL()
    {
    }

CHuiVg10VgImageBinder::~CHuiVg10VgImageBinder()
    {
    if (iEglPBufferSurface_Client)
        {
        eglDestroySurface( iRenderPlugin->EglDisplay(), iEglPBufferSurface_Client );
        iEglPBufferSurface_Client = EGL_NO_SURFACE;
        }
    // Not owned, don't delete.
    iRenderPlugin = NULL;
    }

CHuiVg10VgImageBinder* CHuiVg10VgImageBinder::NewL(CHuiVg10RenderPlugin* aRenderPlugin)
    {   
    CHuiVg10VgImageBinder* self = new (ELeave) CHuiVg10VgImageBinder(aRenderPlugin);
    self->ConstructL();
    return self;
    }

TInt CHuiVg10VgImageBinder::BindClientBuffer(TUint aBuffer)
    {
    // Check whether we should use the Alpha format bit
    VGImageFormat imageFormat = (VGImageFormat)vgGetParameteri(aBuffer, VG_IMAGE_FORMAT);
    TInt maskBit = 0;
    if (imageFormat == VG_sRGBA_8888_PRE)
        {
        maskBit = EGL_VG_ALPHA_FORMAT_PRE_BIT;
        }
    
    const TInt BITS_PER_CHANNEL = 8;
    // Choose an EGL config
    const EGLint attrs[] =
        {
        EGL_RENDERABLE_TYPE,    EGL_OPENVG_BIT,
        EGL_SURFACE_TYPE,       EGL_PBUFFER_BIT | maskBit,
        EGL_RED_SIZE,           BITS_PER_CHANNEL,
        EGL_GREEN_SIZE,         BITS_PER_CHANNEL,
        EGL_BLUE_SIZE,          BITS_PER_CHANNEL,
        EGL_ALPHA_SIZE,         BITS_PER_CHANNEL,
        EGL_NONE
        };
    
    // Create a context
    TInt configCount = iRenderPlugin->EglChooseConfig(attrs);
    EGLConfig config = iRenderPlugin->EglConfig(0);
    
    // Create a pbuffer surface
    iEglPBufferSurface_Client = eglCreatePbufferFromClientBuffer(iRenderPlugin->EglDisplay(),
            EGL_OPENVG_IMAGE, 
            static_cast<EGLClientBuffer>(aBuffer),    // Use the param image as buffer
            config, NULL);
    
    if (iEglPBufferSurface_Client == EGL_NO_SURFACE)
        {
        HUI_DEBUG1(_L("CHuiVg10VgImageBinder::BindClientBuffer() - EGL Surface could not be created, eglErr: %04x"), eglGetError() );
        return KErrGeneral;
        }

    // Save current context and surfaces
    iSavedContext = eglGetCurrentContext();
    iSavedDrawSurface = eglGetCurrentSurface(EGL_DRAW);
    iSavedReadSurface = eglGetCurrentSurface(EGL_READ);

    EGLContext context = iRenderPlugin->EglSharedContext();
    
    // Bind our own PBuffer surface (from VGImage)
    if ( eglMakeCurrent(iRenderPlugin->EglDisplay(), iEglPBufferSurface_Client, iEglPBufferSurface_Client, context /*iSavedContext*/) == EGL_FALSE )
        {
        HUI_DEBUG1(_L("CHuiVg10VgImageBinder::BindClientBuffer() - EGL Surface could not be made current, eglErr: %04x"), eglGetError());
        return KErrGeneral;
        }
    
    // Alles in Ordnung!
    return KErrNone;
    }

TInt CHuiVg10VgImageBinder::UnBindClientBuffer()
    {
    if ( eglMakeCurrent(iRenderPlugin->EglDisplay(), iSavedDrawSurface, iSavedReadSurface, iSavedContext) == EGL_FALSE )
        {
        HUI_DEBUG1(_L("CHuiVg10VgImageBinder::BindClientBuffer() - EGL Surface could not be made current, eglErr: %04x"), eglGetError());
        return KErrGeneral;
        }
    
    iSavedDrawSurface = 0;
    iSavedReadSurface = 0;
    iSavedContext = 0;

    if (iEglPBufferSurface_Client)
        {
        eglDestroySurface( iRenderPlugin->EglDisplay(), iEglPBufferSurface_Client );
        iEglPBufferSurface_Client = EGL_NO_SURFACE;
        }
    
    // Everything went fine
    return KErrNone;
    }

// End of file

