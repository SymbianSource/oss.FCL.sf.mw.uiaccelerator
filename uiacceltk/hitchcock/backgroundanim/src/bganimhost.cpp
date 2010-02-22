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
#include <stdio.h>
#include <stdlib.h>
#include <AknsSrvClient.h>
#include <AknsSrvChunkLookup.h>
#include <AknsConstants.h>
#include <AknsItemDef.h>

#include "bganimhost.h"


typedef void* (*plugingetinterfacefunc)(int);

const TInt KRefreshTarget = 15;
_LIT(KExeCaption,"BG anim host");

static const TUint KMaxGPUMemUsage = 1024*1024*4;


CBgAnimHost::CBgAnimHost() 
    {
    }
    
CBgAnimHost::~CBgAnimHost() 
    {
    delete iTimer;
    if (iPlugin)
        {
        iPlugin->destroy();
        free(iPlugin);
        }
    iPluginLibrary.Close();
    delete iSCPropertyListener;
    delete iThemeRepositoryListener;
    while (iSensorListeners.Count())
        {
        delete iSensorListeners[0];
        iSensorListeners.Remove(0);
        }
    iSensorListeners.Close();
    delete CActiveScheduler::Current();
    CActiveScheduler::Install(NULL);
    ReleaseWindowSurface();
    ReleaseEGL();
    DestroyWindow();
    }

void CBgAnimHost::ConstructL() 
    {
    User::LeaveIfError(iWsSession.Connect());
    TUid wgUid;
    wgUid.iUid = 0x200286D3;
    TInt id = 0;
    CApaWindowGroupName::FindByAppUid(wgUid, iWsSession, id);
    if (id != KErrNotFound)
        {
        User::Leave(KErrAlreadyExists);
        }

    iWsSession.ComputeMode(RWsSession::EPriorityControlDisabled);
    iWsSession.EnableWindowSizeCacheL();
        
    CActiveScheduler *ac = new (ELeave) CActiveScheduler;
    CActiveScheduler::Install(ac);
    iTimer = CHighResTimer::NewL(TCallBack(TimerFunc, this),CActive::EPriorityStandard);
    iThemeRepositoryListener = CThemeRepositoryListener::NewL(&iRunning);
    iSCPropertyListener = CScreenSaverPropertyListener::NewL(TCallBack(ScreenSaverCallback, this));
    
    CreateWindowL();

    // load the initial plugin
    LoadPluginL();
    InitEGLL();
    CreateWindowSurfaceL();
    
    User::LeaveIfError(iPlugin->gpuresourcesavailable(1));
    iThemeRepositoryListener->IssueRequest();
    iSCPropertyListener->IssueRequest();
    }
    
void CBgAnimHost::CreateWindowL()
    {
    iScreenDevice = new (ELeave) CWsScreenDevice(iWsSession);
    User::LeaveIfError(iScreenDevice->Construct(0));
    
    TPixelsAndRotation rot;
    TInt screenmode = iScreenDevice->CurrentScreenMode(); 
    iScreenDevice->GetScreenModeSizeAndRotation(screenmode, rot);
    if (rot.iRotation == CFbsBitGc::EGraphicsOrientationNormal)
        {
        iDisplaySize = rot.iPixelSize;
        }
    else
        {
        iDisplaySize.iWidth = rot.iPixelSize.iHeight;
        iDisplaySize.iHeight = rot.iPixelSize.iWidth;
        }
    
    iRealDisplaySize = iDisplaySize;
    iDisplaySize.iWidth/=2;
    iDisplaySize.iHeight/=2;
    
    iWindowGroup=RWindowGroup(iWsSession);
    User::LeaveIfError(iWindowGroup.Construct((TUint32)&iWindowGroup));
	iWindowGroup.SetOrdinalPosition(-1,-1000);
	
	iWindow=RWindow(iWsSession);
	User::LeaveIfError(iWindow.Construct(iWindowGroup, (TUint32)&iWindow));
	User::LeaveIfError(iWindow.SetExtentErr(TPoint(0,0),iDisplaySize));
    iWindow.SetVisible(ETrue);
	iWindow.Activate();

    iWindGroupName = CApaWindowGroupName::NewL(iWsSession, iWindowGroup.Identifier());

    TUid wgUid;
    wgUid.iUid = 0x200286D3;
    
    iWindGroupName->SetAppUid(wgUid);
    iWindGroupName->SetCaptionL(KExeCaption);
    iWindGroupName->SetHidden(ETrue);
    iWindGroupName->SetAppReady(ETrue);
    iWindGroupName->SetSystem(ETrue);
    iWindGroupName->SetWindowGroupName(iWindowGroup);

	iWsSession.Flush();
    }
    
void CBgAnimHost::DestroyWindow()
    {
    delete iWindGroupName;
    iWindow.Close();
    iWindowGroup.Close();
    delete iScreenDevice;
    iWsSession.Close();
    }
    
void CBgAnimHost::InitEGLL()
    {
    iEGLDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    TInt minorVersion;
    TInt majorVersion;
    if (!iEGLDisplay)
        {
        User::Leave(KErrHardwareNotAvailable);
        }
  	if( !eglInitialize( iEGLDisplay, &majorVersion, &minorVersion ) ) 
  	    {
        User::Leave(KErrHardwareNotAvailable);
  	    }
  	iEGLInitialized = ETrue;
    }

void CBgAnimHost::ReleaseEGL()
    {
    if (iEGLInitialized)
        {
        eglTerminate( iEGLDisplay );   
        iEGLInitialized = EFalse;
        }
    }
    
void CBgAnimHost::ReleaseWindowSurface(TBool aReleaseObserver)
    {
    if (iEGLInitialized && iSurfaceInitialized)
        {
        eglDestroyContext( iEGLDisplay, iEGLContext );
        eglDestroySurface( iEGLDisplay, iEGLSurface );
        eglMakeCurrent( iEGLDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );
        iWsSession.Flush();
        
        iSurfaceInitialized = EFalse;
        
        if (aReleaseObserver)
            {
            iCompSource->RemoveObserver(*this);
            delete iCompSource;
            iCompSource = NULL;
            }
        }
    }

const EGLint openvg_surface_attrs[] = 
        { 
        EGL_VG_ALPHA_FORMAT, EGL_VG_ALPHA_FORMAT_PRE,
        EGL_NONE
        };

const EGLint opengl_es2_context_attrs[] = 
        {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
        };

    
void CBgAnimHost::CreateWindowSurfaceL()
    {
    const EGLint* conf = iPlugin->getpreferredconfig();
   
    TInt numItems = 1;
    while (conf[numItems-1] != EGL_NONE)
        {
        numItems++;
        }

    EGLint* preferredConfig = (EGLint*)malloc(sizeof(EGLint)*numItems);
    for (TInt count = 0; count < numItems;count++)
        {
        EGLint val = conf[count];
        preferredConfig[count] = val;
        switch (val)
            {
            case EGL_BUFFER_SIZE:
                if (conf[count+1] != 16)
                    {
                    preferredConfig[count+1] = 16;
                    count++;
                    }
                break;
            case EGL_ALPHA_SIZE:
                if (conf[count+1] != 0)
                    {
                    preferredConfig[count+1] = 0;
                    count++;
                    }

                break;
            case EGL_RED_SIZE:
                if (conf[count+1] != 5)
                    {
                    preferredConfig[count+1] = 5;
                    count++;
                    }

                break;
            case EGL_GREEN_SIZE:
                if (conf[count+1] != 6)
                    {
                    preferredConfig[count+1] = 6;
                    count++;
                    }

                break;
            case EGL_BLUE_SIZE:
                if (conf[count+1] != 5)
                    {
                    preferredConfig[count+1] = 5;
                    count++;
                    }
                break;
            default:
                break;
            }
        }
    
    TInt index = 0;
    
    // figure out what API was requested
    EGLint api = EGL_NONE;
    while (conf[index] != EGL_NONE)
        {
        if (conf[index] == EGL_RENDERABLE_TYPE)
            {
            if (conf[index+1]&EGL_OPENVG_BIT)
                {
                api = EGL_OPENVG_BIT;
                if (!eglBindAPI(EGL_OPENVG_API))
                    {
                    User::Leave(KErrAbort);
                    }
                }
            else if ( (conf[index+1]&EGL_OPENGL_ES_BIT) ||
                      (conf[index+1]&EGL_OPENGL_ES2_BIT) )
                {
                api = conf[index+1];
                if (!eglBindAPI(EGL_OPENGL_ES_API))                
                    {
                    User::Leave(KErrAbort);
                    }
                }
            index++;
            }
        index++;
        }         
    EGLConfig *configList = NULL;
    EGLint numConfigs = 0;
    EGLint configSize   = 0;

    // Get the number of possible EGLConfigs
    if ( !eglGetConfigs( iEGLDisplay, configList, configSize, &numConfigs ) )
       {
       User::Leave(KErrAbort);

       }
    configSize = numConfigs;
    
    configList = (EGLConfig*)malloc(sizeof(EGLConfig)*configSize);
    if (!configList)
        {
        User::Leave(KErrNoMemory);
        }
    
	if( !eglChooseConfig( iEGLDisplay, preferredConfig, configList, configSize, &numConfigs ) )
		{
        User::Leave(KErrAbort);
		}

	TInt confIndex = 0;
	// we should now have a list of configs matching our preferred attributes
    for (TInt count = 0;count<numConfigs;count++)
        {
        EGLint buffer_size;
        EGLint red_size;
        EGLint green_size;
        EGLint blue_size;
        EGLint alpha_size;
        
        eglGetConfigAttrib(iEGLDisplay, configList[count],EGL_BUFFER_SIZE,&buffer_size);
        eglGetConfigAttrib(iEGLDisplay, configList[count],EGL_RED_SIZE,&red_size);
        eglGetConfigAttrib(iEGLDisplay, configList[count],EGL_GREEN_SIZE,&green_size);
        eglGetConfigAttrib(iEGLDisplay, configList[count],EGL_BLUE_SIZE,&blue_size);
        eglGetConfigAttrib(iEGLDisplay, configList[count],EGL_ALPHA_SIZE,&alpha_size);

        if (buffer_size == 16 && red_size == 5 && green_size == 6 && blue_size == 5 && alpha_size == 0)
            {
            confIndex = count;
            break;
            }
        }
        
    EGLint* context_attrs = NULL;
    if (api == EGL_OPENGL_ES2_BIT)
        {
        context_attrs = (EGLint*)opengl_es2_context_attrs;
        }

	iEGLContext = eglCreateContext( iEGLDisplay, configList[confIndex], NULL, context_attrs );
	if( !iEGLContext )
        {
        User::Leave(KErrAbort);
        }

    EGLint* surface_attrs = NULL;
#if !defined(__WINS__) // no pre multiplied surfaces on wins (yet)
    if (api == EGL_OPENVG_BIT)
        {
        surface_attrs = (EGLint*)openvg_surface_attrs;
        }
#endif
        
	iEGLSurface = eglCreateWindowSurface( iEGLDisplay, configList[confIndex], &iWindow, surface_attrs );
	if( !iEGLSurface )
        {
        User::Leave(KErrAbort);
        }
	
	eglMakeCurrent( iEGLDisplay, iEGLSurface, iEGLSurface, iEGLContext );        


    free(configList);
    free(preferredConfig);
	
    FOREVER
        {
        TRAPD(cerr, iCompSource = CAlfCompositionSource::NewL(iWindow));
        if (!cerr)
            {
            iCompSource->AddCompositionObserverL(*this);
            iCompSource->SetIsBackgroundAnim(ETrue);
            iCompSource->SetExtent(TRect(TPoint(0,0),iRealDisplaySize),0);
            break;
            }
        else
            {
            User::After(5000000);
            }
        }

    iSurfaceInitialized = ETrue;
    
    }
    
void CBgAnimHost::LoadPluginL()
    {
    // dig out the skin config from skin server
    HBufC* configstr = NULL;
    RAknsSrvSession skinsrv;
    User::LeaveIfError(skinsrv.Connect());
    CleanupClosePushL(skinsrv);
    CAknsSrvChunkLookup* cl = skinsrv.CreateChunkLookupL();
    CleanupStack::PushL(cl);
    CAknsStringItemDef* configitem = static_cast<CAknsStringItemDef*>(cl->LookupAndCreateDefL( KAknsIIDPropertyAnimBgParam )); 
    User::LeaveIfNull(configitem);
    CleanupStack::PushL(configitem);
    configstr = configitem->String().AllocL();
    CleanupStack::PopAndDestroy(3); // skinsrv, cl, configitem
    CleanupStack::PushL(configstr);
    RDebug::Print(_L("----------------------"));
    RDebug::Print(_L("backgroundhost config:"));
    RDebug::Print(*configstr);
    RDebug::Print(_L("----------------------"));
    
    TLex lex(*configstr);
    TPtrC dllname = lex.NextToken();
    if (!dllname.Length())
        {
        User::Leave(KErrNotFound);
        }
    
    User::LeaveIfError(iPluginLibrary.Load(dllname));
    plugingetinterfacefunc getif = (plugingetinterfacefunc)iPluginLibrary.Lookup(1);
    if (!getif)
        {
        iPluginLibrary.Close();
        User::Leave(KErrNotFound);
        }
    
    iPlugin = (plugin_export_v1_t*) getif(1);

    TPtrC configpath = lex.NextToken();
    if (!configpath.Length())
        {
        User::Leave(KErrNotFound);
        }
    TBuf8<256> pluginpath;
    pluginpath.Copy(configpath);
    User::LeaveIfError(iPlugin->initialize((const char*)pluginpath.PtrZ(), KMaxGPUMemUsage));

//        }
//    else
//        {
//        User::LeaveIfError(iPlugin->initialize("z:\\private\\200286D3", KMaxGPUMemUsage));
//        }

    CleanupStack::PopAndDestroy(); // configstr
    
    iPlugin->setdisplaydimensions(iDisplaySize.iWidth, iDisplaySize.iHeight);
    if (iPlugin->desiredsensors && iPlugin->receivesensordata)
        {
        const unsigned int* sensors = iPlugin->desiredsensors();
        while (*sensors)
            {
            CSensorListener* listener = NULL;
            TRAPD(serr, listener = CSensorListener::NewL(this, *sensors++));
            if (!serr)
                {
                iSensorListeners.Append(listener);
                }
            }
        }
    }
    
void CBgAnimHost::NewFrame()
    {
    if (!iRunning)
        {
        // Stop and exit
        CActiveScheduler::Stop();
        return;
        }
    if (!iSurfaceInitialized)
        {
        return;
        }
    TTime start;
    start.UniversalTime();
    iPlugin->produceframe();
    eglSwapBuffers(iEGLDisplay, iEGLSurface);
    TTime end;
    end.UniversalTime();
    TInt64 elapsed = end.MicroSecondsFrom(start).Int64();
    elapsed/=1000; // convert to milliseconds
    
    TInt nextcallback = KRefreshTarget-(TInt)elapsed;
    if (nextcallback < 1)
        nextcallback = 1;
    
    iTimer->CallBack(nextcallback);
    }
    
    
TInt CBgAnimHost::TimerFunc(TAny* aPtr)
    {
    CBgAnimHost* me = (CBgAnimHost*)(aPtr);
    me->NewFrame();
    return ETrue;
    }

    
void CBgAnimHost::ExecuteL() 
    {
    // finally start our timer and scheduler...
    iTimer->CallBack(100);
    iTimerRunning = ETrue;
    iRunning = ETrue;
    CActiveScheduler::Start();
    }

void CBgAnimHost::FrameReady(TInt /*aScreenNumber*/)
    {
    }
    
void CBgAnimHost::RunningLowOnGraphicsMemory()
    {
/*    iThemeRepositoryListener->GPuMemLow(ETrue);
    CompositionTargetHidden();*/
    }


void CBgAnimHost::GraphicsMemoryGood()
    {
/*    CompositionTargetVisible();
    iThemeRepositoryListener->GPuMemLow(EFalse);*/
    }
    
void CBgAnimHost::CompositionTargetHidden()
    {
    if (!iSurfaceInitialized)
        {
        // don't bother if we are already in
        // a correct state..
        return;
        }

    RDebug::Print(_L("!!! - HIDDEN - !!!"));
    // release gpu resources...
    iTimer->Cancel();
    iTimerRunning = EFalse;
    iPlugin->gpuresourcesavailable(0);
    ReleaseWindowSurface(EFalse);
    }

void CBgAnimHost::CompositionTargetVisible()
    {
    if (iSurfaceInitialized)
        {
        // don't bother if we are already in
        // a correct state..
        return;
        }

    RDebug::Print(_L("!!! - VISIBLE - !!!"));

    if (!iSurfaceInitialized && iCompSource)
        {
        iCompSource->RemoveObserver(*this);
        delete iCompSource;
        iCompSource = NULL;            
        }
        
    TRAPD(err,CreateWindowSurfaceL());
    // reclaim gpu resources
    if (!err)
        {
        iPlugin->gpuresourcesavailable(1);
        iTimer->CallBack(1);
        iTimerRunning = ETrue;
        }
    }

void CBgAnimHost::HandleScreenSaverEvent()
    {
    RDebug::Print(_L("-----------------------------------"));
    RDebug::Print(_L("CBgAnimHost::HandleScreenSaverEvent"));
    TInt scStatus = iSCPropertyListener->GetScreenSaverStatus();
    RDebug::Print(_L("status: %d, timerrunning %d, surfacecreated %d"),scStatus, iTimerRunning, iSurfaceInitialized);
    RDebug::Print(_L("-----------------------------------"));
    if (scStatus)
        {
        // screensaver is ON
        if (iTimerRunning)
            {
            RDebug::Print(_L("--- screensaver on, stopping timer ---"));
            iTimer->Cancel();
            iTimerRunning = EFalse;
            }
        }
    else
        {
        // screensaver is OFF
        if (!iTimerRunning && iSurfaceInitialized)
            {
            RDebug::Print(_L("--- screensaver off, starting timer ---"));
    
            iTimerRunning = ETrue;
            iTimer->CallBack(1);
            }
        }
    }

TInt CBgAnimHost::ScreenSaverCallback(TAny* aPtr)
    {
    CBgAnimHost* me = (CBgAnimHost*) aPtr;
    me->HandleScreenSaverEvent();
    return EFalse;
    }

void CBgAnimHost::DataReceived( CSensrvChannel& aChannel, TInt aCount, TInt aDataLost )
    {
    if (iPlugin && iPlugin->receivesensordata)
        {
        iPlugin->receivesensordata((void*)&aChannel, aCount, aDataLost);
        }
    }
    
void CBgAnimHost::DataError( CSensrvChannel& aChannel, TSensrvErrorSeverity aError )
    {
    }

void CBgAnimHost::GetDataListenerInterfaceL( TUid aInterfaceUid, TAny*& aInterface)
    {
    }