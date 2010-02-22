/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
#include <e32base.h>
#include <w32std.h>
#include <apgwgnam.h> 
#include <sensrvdatalistener.h>


#include <EGL/egl.h>

#include "highrestimer.h"
#include "plugininterface.h"
#include "themerepositorylistener.h"
#include "screensaverpropertylistener.h"
#include "sensor.h"

#include "../../../../uiaccelerator_plat/alf_visual_api/inc/alf/alfcompositionutility.h"

class CBgAnimHost : public CBase, public MAlfCompositionObserver, public MSensrvDataListener
    {
    public:
        void ConstructL();
        CBgAnimHost();
        ~CBgAnimHost();
        void ExecuteL();
        
        static TInt TimerFunc(TAny* aPtr);
        
        // from MAlfCompositionObserver
        void FrameReady(TInt aScreenNumber);
        void RunningLowOnGraphicsMemory();
        void GraphicsMemoryGood(); 
        void CompositionTargetHidden();
        void CompositionTargetVisible();
        
        // from MSensrvDataListener
        void DataReceived( CSensrvChannel& aChannel, TInt aCount, TInt aDataLost );
        void DataError( CSensrvChannel& aChannel, TSensrvErrorSeverity aError );
        void GetDataListenerInterfaceL( TUid aInterfaceUid, TAny*& aInterface);
        
        
    protected:
        void CreateWindowL();
        void DestroyWindow();
        void InitEGLL();
        void ReleaseEGL();
        void CreateWindowSurfaceL();
        void ReleaseWindowSurface(TBool aReleaseObserver = ETrue);
        void LoadPluginL();
        void NewFrame();
        void HandleScreenSaverEvent();
        static TInt ScreenSaverCallback(TAny* aPtr);
    private:
        // windowing stuff
        RWsSession iWsSession;
        RWindowGroup iWindowGroup;
        RWindow iWindow;
        CApaWindowGroupName* iWindGroupName;
        CWsScreenDevice* iScreenDevice;
        TSize iDisplaySize;
        TSize iRealDisplaySize;
        
        // EGL stuff
        EGLDisplay iEGLDisplay;
        EGLConfig  iEGLConfig;
        EGLContext iEGLContext;
        EGLSurface iEGLSurface;
        
        // plugin
        RLibrary iPluginLibrary;
        plugin_export_v1_t* iPlugin;

        // timer
        CHighResTimer* iTimer;
        TBool iTimerRunning;
        
        TBool iEGLInitialized;
        TBool iSurfaceInitialized;
        
        // composition API
        CAlfCompositionSource* iCompSource;
        
        TBool iRunning;
    
        CThemeRepositoryListener* iThemeRepositoryListener;
        CScreenSaverPropertyListener* iSCPropertyListener;

        RPointerArray<CSensorListener> iSensorListeners;

    };