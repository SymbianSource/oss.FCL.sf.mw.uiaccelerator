/*
* Copyright (c) 2002 - 2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  test api of alf_core_toolkit
*
*/



#ifndef C_TESTUIAIFCORETOOLKIT_H
#define C_TESTUIAIFCORETOOLKIT_H

//  INCLUDES
#include <stiflogger.h>
#include <testscripterinternal.h>
#include <stiftestmodule.h>
#include <testclassassert.h>
#include <eikenv.h>
#include <coemain.h>

#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huicontrolgroup.h>
#include <uiacceltk/huidisplay.h>
#include <uiacceltk/huianchorlayout.h>
#include <uiacceltk/huicommand.h>
#include <uiacceltk/huidisplaycoecontrol.h>

// MACROS
#define TEST_CLASS_VERSION_MAJOR 0
#define TEST_CLASS_VERSION_MINOR 0
#define TEST_CLASS_VERSION_BUILD 0

// const variable
const TInt KTestDisplayPosX = 20;
const TInt KTestDisplayPosY = 10;
const TInt KTestDisplayWidth = 100;
const TInt KTestDisplayHeight = 200;
const TInt KTestScreenBufferUidValue = 2007;

const TInt KHuiCtrlGroupId = 1;

// Logging path
_LIT( KtestuiaifcoretoolkitLogPath, "\\logs\\testframework\\testuiaifcoretoolkit\\" ); 
// Log file
_LIT( KtestuiaifcoretoolkitLogFile, "testuiaifcoretoolkit.txt" ); 
_LIT( KtestuiaifcoretoolkitLogFileWithTitle, "testuiaifcoretoolkit_[%S].txt" );

class CHuiAnchorLayout;
class CTestPlatALFCoreToolkitVisualExt;
class CHuiTextVisual;
class CHuiViewportLayout;
class CHuiGridLayout;
class CHuiFlowLayout;
class CHuiImageLoaderUtil;

/**
*  CTestUiAifCoreToolkit test class for STIF Test Framework TestScripter.
*  @since S60 5.0
*/
NONSHARABLE_CLASS( CTestUiAifCoreToolkit ) : public CScriptBase
    {
public:  // Constructors and destructor

    /**
    * Two-phased constructor.
    */
    static CTestUiAifCoreToolkit* NewL( CTestModuleIf& aTestModuleIf );

    /**
    * Destructor.
    */
    virtual ~CTestUiAifCoreToolkit();

public: // Functions from base classes

    /**
    * From CScriptBase Runs a script line.
    * @since S60 5.0
    * @param aItem Script line containing method name and parameters
    * @return Symbian OS error code
    */
    virtual TInt RunMethodL( CStifItemParser& aItem );

private:

    /**
    * C++ default constructor.
    */
    CTestUiAifCoreToolkit( CTestModuleIf& aTestModuleIf );

    /**
    * By default Symbian 2nd phase constructor is private.
    */
    void ConstructL();

    
    /**
     * Method used to log version of test class
     */
    void SendTestClassVersion();
    
        /**
     * Turn off ScreenSaver
     * @since S60 5.0
     * @return Symbian OS error code.
     */
    void TurnOffScreenSaver();

    /**
     * Restore ScreenSaver
     * @since S60 5.0
     * @return Symbian OS error code.
     */
    void RestoreScreenSaver();
    /**
     * ConstructNeededMember
     * @since S60 5.0
     * @return Symbian OS error code.
     */ 
    void ContructNeededMemberL();


	// [TestMethods]
private:// for testing the HuiAnchorLayout.h	
    /**
    * TestCHuiAnLayAddNewL test method for testing the AddNewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayAddNewL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayDestructL test method for testing the ~CHuiAnchorLayout method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayDestructL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayResetL test method for testing the Reset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayResetL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLaySetAnchorL test method for testing the SetAnchor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLaySetAnchorL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLaySetRelativeAnchorRectL test method for testing the SetRelativeAnchorRectL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLaySetRelativeAnchorRectL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayRemoveAnchorL test method for testing the RemoveAnchor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayRemoveAnchorL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayAttachOriginL test method for testing the Attach method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayAttachOriginL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayAttachOriginTopLeftL test method for testing the Attach method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayAttachOriginTopLeftL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayAttachOriginNoneL test method for testing the Attach method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayAttachOriginNoneL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayDetachL test method for testing the Detach method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayDetachL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayDetachAnchorL test method for testing the Detach method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayDetachAnchorL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLaySetSizeL test method for testing the SetSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLaySetSizeL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayChildSizeL test method for testing the ChildSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayChildSizeL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayChildPosL test method for testing the ChildPos method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayChildPosL( CStifItemParser& aItem );
    /**
    * TestCHuiAnLayChildRectL test method for testing the ChildRect method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiAnLayChildRectL( CStifItemParser& aItem );
    
private:// for testing the HuiBorderBrush.h    
    /*
    * TestCHuiBdeBrshNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshNewL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshNewCL test method for testing the NewLC method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshNewCL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshOtherNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshOtherNewL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshOtherNewCL test method for testing the NewLC method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshOtherNewCL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshSetImageL test method for testing the SetImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshSetImageL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshSetColorL test method for testing the SetColor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshSetColorL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshSetThicknessL test method for testing the SetThickness method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshSetThicknessL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshSetEdgeOffsetL test method for testing the SetEdgeOffset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshSetEdgeOffsetL( CStifItemParser& aItem );
    /*
    * TestCHuiBdeBrshSetImageOffsetL test method for testing the SetImageOffset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
   */
    virtual TInt TestCHuiBdeBrshSetImageOffsetL( CStifItemParser& aItem );
private:// for testing the HuiAnimatedTexture.h    
    /*
    * TestCHuiATextDestructL test method for testing the ~CHuiAnimatedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextDestructL( CStifItemParser& aItem );
    /*
    * TestCHuiATextTextureL test method for testing the Texture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextTextureL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentTextureL test method for testing the SegmentedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentTextureL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentTextureConstL test method for testing the SegmentedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentTextureConstL( CStifItemParser& aItem );
    /*
    * TestCHuiATextShadowedTextureL test method for testing the ShadowedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextShadowedTextureL( CStifItemParser& aItem );
    /*
    * TestCHuiATextShadowedTextureConstL test method for testing the ShadowedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextShadowedTextureConstL( CStifItemParser& aItem );
    /*
    * TestCHuiATextHasContentL test method for testing the HasContent method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextHasContentL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSizeL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentCountL test method for testing the SegmentCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentCountL( CStifItemParser& aItem );
    /*
    * TestCHuiATextTextureChangedL test method for testing the TextureChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextTextureChangedL( CStifItemParser& aItem );
    /*
    * TestCHuiATextTextureClearChangedL test method for testing the TextureClearChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextTextureClearChangedL( CStifItemParser& aItem );
    /*
    * TestCHuiATextTextureConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextTextureConstructorL( CStifItemParser& aItem );
    /*
    * TestCHuiATextBaseConstructL test method for testing the BaseConstruct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextBaseConstructL( CStifItemParser& aItem );
    /*
    * TestCHuiATextTextureExtensionL test method for testing the TextureExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextTextureExtensionL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentNameL test method for testing the SegmentName method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentNameL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentSizeL test method for testing the SegmentSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentSizeL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentTextureSizeL test method for testing the SegmentTextureSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentTextureSizeL( CStifItemParser& aItem );
    /*
    * TestCHuiATextSegmentOffsetL test method for testing the SegmentOffset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiATextSegmentOffsetL( CStifItemParser& aItem );
    
private:// for testing the HuiControl.h 
    /*
    * TestCHuiControlL test method for testing the CHuiControl method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlL( CStifItemParser& aItem );
    /*
    * TestCHuiControlDestructL test method for testing the ~CHuiControl method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlDestructL( CStifItemParser& aItem );
    /*
    * TestCHuiControlSetIdL test method for testing the SetId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlSetIdL( CStifItemParser& aItem );
    /*
    * TestCHuiControlIdL test method for testing the Id method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlIdL( CStifItemParser& aItem );
    /*
    * TestCHuiControlEnvL test method for testing the Env method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlEnvL( CStifItemParser& aItem );
    /*
    * TestCHuiControlControlGroupL test method for testing the ControlGroup method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlControlGroupL( CStifItemParser& aItem );
    /*
    * TestCHuiControlTextureManagerL test method for testing the TextureManager method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlTextureManagerL( CStifItemParser& aItem );
    /*
    * TestCHuiControlDisplayL test method for testing the Display method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlDisplayL( CStifItemParser& aItem );
    /*
    * TestCHuiControlBindDisplayL test method for testing the BindDisplay method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlBindDisplayL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAppendL test method for testing the AppendL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAppendL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAppendLayoutL test method for testing the AppendL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAppendLayoutL( CStifItemParser& aItem );
    /*
    * TestCHuiControlRemoveL test method for testing the Remove method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlRemoveL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAppendVisualL test method for testing the AppendVisualL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAppendVisualL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAppendTypeLayoutL test method for testing the AppendLayoutL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAppendTypeLayoutL( CStifItemParser& aItem );
    /*
    * TestCHuiControlVisualL test method for testing the Visual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlVisualL( CStifItemParser& aItem );
    /*
    * TestCHuiControlVisualCountL test method for testing the VisualCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlVisualCountL( CStifItemParser& aItem );
    /*
    * TestCHuiControlFindTagL test method for testing the FindTag method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlFindTagL( CStifItemParser& aItem );
    /*
    * TestCHuiControlHostL test method for testing the Host method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlHostL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAddConnectionL test method for testing the AddConnectionL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAddConnectionL( CStifItemParser& aItem );
    /*
    * TestCHuiControlRemoveConnectionL test method for testing the RemoveConnection method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlRemoveConnectionL( CStifItemParser& aItem );
    /*
    * TestCHuiControlFindConnectionL test method for testing the FindConnection method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlFindConnectionL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionCountL test method for testing the ConnectionCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionCountL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionL test method for testing the Connection method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionByOrdinalL test method for testing the ConnectionByOrdinal method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionByOrdinalL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionRoleL test method for testing the ConnectionRole method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionRoleL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionOrdinalL test method for testing the ConnectionOrdinal method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionOrdinalL( CStifItemParser& aItem );
    /*
    * TestCHuiControlRoleL test method for testing the Role method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlRoleL( CStifItemParser& aItem );
    /*
    * TestCHuiControlSetRoleL test method for testing the SetRole method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlSetRoleL( CStifItemParser& aItem );
    /*
    * TestCHuiControlHostIdL test method for testing the HostId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlHostIdL( CStifItemParser& aItem );
    /*
    * TestCHuiControlSetHostIdL test method for testing the SetHostId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlSetHostIdL( CStifItemParser& aItem );
    /*
    * TestCHuiControlSetHostL test method for testing the SetHost method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlSetHostL( CStifItemParser& aItem );
    /*
    * TestCHuiControlContainerLayoutL test method for testing the ContainerLayout method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlContainerLayoutL( CStifItemParser& aItem );
    /*
    * TestCHuiControlHostToDisplayL test method for testing the HostToDisplay method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlHostToDisplayL( CStifItemParser& aItem );
    /*
    * TestCHuiControlDisplayToHostL test method for testing the DisplayToHost method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlDisplayToHostL( CStifItemParser& aItem );
    /*
    * TestCHuiControlBoundsL test method for testing the Bounds method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlBoundsL( CStifItemParser& aItem );
    /*
    * TestCHuiControlHitTestL test method for testing the HitTest method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlHitTestL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAcquireFocusL test method for testing the AcquireFocus method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAcquireFocusL( CStifItemParser& aItem );
    /*
    * TestCHuiControlFocusL test method for testing the Focus method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlFocusL( CStifItemParser& aItem );
    /*
    * TestCHuiControlIsFocusingL test method for testing the IsFocusing method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlIsFocusingL( CStifItemParser& aItem );
    /*
    * TestCHuiControlFocusChangedL test method for testing the FocusChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlFocusChangedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlAcceptInputL test method for testing the AcceptInput method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlAcceptInputL( CStifItemParser& aItem );
    /*
    * TestCHuiControlOfferEventL test method for testing the OfferEventL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlOfferEventL( CStifItemParser& aItem );
    /*
    * TestCHuiControlDisplayAreaL test method for testing the DisplayArea method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlDisplayAreaL( CStifItemParser& aItem );
    /*
    * TestCHuiControlDisplayCenterL test method for testing the DisplayCenter method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlDisplayCenterL( CStifItemParser& aItem );
    /*
    * TestCHuiControlCancelAllCommandsL test method for testing the CancelAllCommands method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlCancelAllCommandsL( CStifItemParser& aItem );
    /*
    * TestCHuiControlVisualLayoutUpdatedL test method for testing the VisualLayoutUpdated method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlVisualLayoutUpdatedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlVisualDestroyedL test method for testing the VisualDestroyed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlVisualDestroyedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlEventHandlerL test method for testing the EventHandler method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlEventHandlerL( CStifItemParser& aItem );
    /*
    * TestCHuiControlNotifyVisibilityL test method for testing the NotifyControlVisibility method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlNotifyVisibilityL( CStifItemParser& aItem );
    /*
    * TestCHuiControlVisualAddedL test method for testing the VisualAddedL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlVisualAddedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlVisualRemovedL test method for testing the VisualRemoved method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlVisualRemovedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionAddedL test method for testing the ConnectionAddedL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionAddedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlConnectionRemovedL test method for testing the ConnectionRemoved method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlConnectionRemovedL( CStifItemParser& aItem );
    /*
    * TestCHuiControlHostChangingL test method for testing the HostChangingL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlHostChangingL( CStifItemParser& aItem );
    /*
    * TestCHuiControlBaseConstructL test method for testing the BaseConstructL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlBaseConstructL( CStifItemParser& aItem );
    /*
    * TestCHuiControlControlExtensionL test method for testing the ControlExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlControlExtensionL( CStifItemParser& aItem );
    /*
    * TestCHuiControlTypeL test method for testing the Type method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlTypeL( CStifItemParser& aItem );
    /*
    * TestCHuiControlSessionIdL test method for testing the SessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlSessionIdL( CStifItemParser& aItem );
    /*
    * TestCHuiControlSetSessionIdL test method for testing the SetSessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiControlSetSessionIdL( CStifItemParser& aItem );
private:// for testing the HuiControlGroup.h 
    /*
    * TestCHuiCntlGroupAppendL test method for testing the AppendL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlGroupAppendL( CStifItemParser& aItem );  
    /*
    * TestCHuiCntlGroupAppendAndPopL test method for testing the AppendAndPopL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlGroupAppendAndPopL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCntlGroupRemoveL test method for testing the Remove method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlGroupRemoveL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCntlCountL test method for testing the Count method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlCountL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCntlControlL test method for testing the Control method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlControlL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCntlFindControlL test method for testing the FindControl method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlFindControlL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCntlEnableTsfomatonL test method for testing the 
    * EnableTransformationL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlEnableTsfomatonL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCntlIsTransformedL test method for testing the IsTransformed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlIsTransformedL( CStifItemParser& aItem );
    /*
    * TestCHuiCntlTransformationL test method for testing the Transformation method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlTransformationL( CStifItemParser& aItem );
    /*
    * TestCHuiCntlAcceptInputL test method for testing the AcceptInput method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlAcceptInputL( CStifItemParser& aItem );
    /*
    * TestCHuiCntlSetAcceptInputL test method for testing the SetAcceptInput method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlSetAcceptInputL( CStifItemParser& aItem );
    /*
    * TestCHuiCntlTypeL test method for testing the Type method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlTypeL( CStifItemParser& aItem );
    /*
    * TestCHuiCntlSessionIdL test method for testing the SessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlSessionIdL( CStifItemParser& aItem );
    /*
    * TestCHuiCntlSetSessionIdL test method for testing the SetSessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCntlSetSessionIdL( CStifItemParser& aItem );
private:// for testing the HuiCurvePath.h 
    /*
    * TestCHuiCurvePathNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathNewL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathNewCL test method for testing the NewLC method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathNewCL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathDestructL test method for testing the ~CHuiCurvePath method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathDestructL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathResetL test method for testing the Reset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathResetL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathEnableLoopL test method for testing the EnableLoop method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathEnableLoopL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathLoopL test method for testing the Loop method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathLoopL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathSetOriginL test method for testing the SetOrigin method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathSetOriginL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathAppendLineL test method for testing the AppendLineL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathAppendLineL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathAppendRealLineL test method for testing the AppendRealLineL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathAppendRealLineL( CStifItemParser& aItem );
    /*
    * TestCHuiCurvePathAppendArcL test method for testing the AppendArcL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathAppendArcL( CStifItemParser& aItem );
    /*
    * TestCHuiCurvePathAppendHuiArcL test method for testing the AppendArcL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathAppendHuiArcL( CStifItemParser& aItem );
    /*
    * TestCHuiCurvePathLengthL test method for testing the Length method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathLengthL( CStifItemParser& aItem );
    /*
    * TestCHuiCurvePathEvaluateL test method for testing the Evaluate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathEvaluateL( CStifItemParser& aItem );
private:// for testing the HuiCurvePathLayout.h 
    /*
    * TestCHuiCurvePathLayAddNewL test method for testing the AddNewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathLayAddNewL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCurvePathLayCurvePathL test method for testing the CurvePath method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCurvePathLayCurvePathL( CStifItemParser& aItem );
private:// for testing the HuiDeckLayout.h 
    /*
    * TestCHuiDeckLayoutAddNewL test method for testing the AddNewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiDeckLayoutAddNewL( CStifItemParser& aItem ); 
    /*
    * TestCHuiDeckLayoutDestructL test method for testing the Destruct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiDeckLayoutDestructL( CStifItemParser& aItem );
private:// for testing the HuiCommand.h 
    /*
    * TestCHuiCommandDestructL test method for testing the ~THuiCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandDestructL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandObjectCommandL test method for testing the ObjectCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandObjectCommandL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandSetSenderL test method for testing the SetSender method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandSetSenderL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandTypeL test method for testing the Type method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandTypeL( CStifItemParser& aItem ); 
    /*
    * TestCHuiSenderTypeL test method for testing the SenderType method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiSenderTypeL( CStifItemParser& aItem ); 
    /*
    * TestCHuiSenderL test method for testing the Sender method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiSenderL( CStifItemParser& aItem ); 
    /*
    * TestCHuiSenderVisualL test method for testing the SenderVisual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiSenderVisualL( CStifItemParser& aItem );
    /*
    * TestCHuiSenderControlL test method for testing the SenderControl method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiSenderControlL( CStifItemParser& aItem ); 
    /*
    * TestCHuiSenderControlGroupL test method for testing the SenderControlGroup method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiSenderControlGroupL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandConstructL test method for testing the Construct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandConstructL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandExtensionL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandTActionCommandL test method for testing the THuiActionCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandTActionCommandL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandExecuteL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandSizeL( CStifItemParser& aItem ); 
    /*
    * TestCHuiCommandIdL test method for testing the Id method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiCommandIdL( CStifItemParser& aItem );
    /*
    * TestCHuiActionCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiActionCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandL test method for testing the ObjectCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandSizeL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandObjectL test method for testing the Object method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandObjectL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandOperationL test method for testing the Operation method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandOperationL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandConstructL test method for testing the Construct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandConstructL( CStifItemParser& aItem );
    /*
    * TestCHuiObjectCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiObjectCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiGroupCommandL test method for testing the THuiGroupCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiGroupCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiGroupCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiGroupCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiGroupCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiGroupCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiGroupCommandControlGroupL test method for testing the ControlGroup method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiGroupCommandControlGroupL( CStifItemParser& aItem );
    /*
    * TestTHuiGroupCommandDisplayL test method for testing the Display method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiGroupCommandDisplayL( CStifItemParser& aItem );
    /*
    * TestTHuiGroupCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiGroupCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiControlCommandL test method for testing the THuiControlCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiControlCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiControlCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiControlCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiControlCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiControlCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiControlCommandControlL test method for testing the Control method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiControlCommandControlL( CStifItemParser& aItem );
    /*
    * TestTHuiControlCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiControlCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandL test method for testing the THuiVisualCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandVisualL test method for testing the Visual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandVisualL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandFlagsToSetL test method for testing the FlagsToSet method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandFlagsToSetL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandFlagsToClearL test method for testing the FlagsToClear method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandFlagsToClearL( CStifItemParser& aItem );
    /*
    * TestTHuiVisualCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiVisualCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiImageCommandL test method for testing the THuiImageCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiImageCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiImageCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiImageCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiImageCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiImageCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiImageCommandVisualL test method for testing the ImageVisual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiImageCommandVisualL( CStifItemParser& aItem );
    /*
    * TestTHuiImageCommandImageL test method for testing the Image method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiImageCommandImageL( CStifItemParser& aItem );
    /*
    * TestTHuiImageCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiImageCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiTextCommandL test method for testing the THuiTextCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiTextCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiTextCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiTextCommandTextVisualL test method for testing the TextVisual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCommandTextVisualL( CStifItemParser& aItem );
    /*
    * TestTHuiTextCommandTextL test method for testing the Text method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCommandTextL( CStifItemParser& aItem );
    /*
    * TestTHuiTextCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandL test method for testing the THuiValueCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandMutiRefL test method for testing the THuiValueCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandMutiRefL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandTimedValueL test method for testing the TimedValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandTimedValueL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandTargetL test method for testing the Target method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandTargetL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandTransitionTimeL test method for testing the TransitionTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandTransitionTimeL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandSpeedL test method for testing the Speed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandSpeedL( CStifItemParser& aItem );
    /*
    * TestTHuiValueCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiValueCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandL test method for testing the THuiPointCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandMutiRefL test method for testing the THuiPointCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandMutiRefL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandMutiRefOtherL test method for testing the THuiPointCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandMutiRefOtherL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandTimedPointL test method for testing the TimedPoint method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandTimedPointL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandTargetL test method for testing the Target method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandTargetL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandTransitionTimeL test method for testing the TransitionTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandTransitionTimeL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandSpeedL test method for testing the Speed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandSpeedL( CStifItemParser& aItem );
    /*
    * TestTHuiPointCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPointCommandExtensionL( CStifItemParser& aItem );
    /*
    * THuiTransformationCommand test method for testing the THuiTransformationCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandTransmasnL test method for testing the Transformation method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandTransmasnL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandStepL test method for testing the Step method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandStepL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandSetXL test method for testing the SetX method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandSetXL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandSetYL test method for testing the SetY method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandSetYL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandSetZL test method for testing the SetZ method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandSetZL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandSetAngleL test method for testing the SetAngle method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandSetAngleL( CStifItemParser& aItem );
    /*
    * TestTHuiTransformationCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTransformationCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiMarkerCommandL test method for testing the THuiMarkerCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiMarkerCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiMarkerCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiMarkerCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiMarkerCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiMarkerCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiMarkerCommandIdL test method for testing the Id method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiMarkerCommandIdL( CStifItemParser& aItem );
    /*
    * TestTHuiMarkerCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiMarkerCommandExtensionL( CStifItemParser& aItem );
    /*
    * TestTHuiCustomEventCommandL test method for testing the THuiCustomEventCommand method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiCustomEventCommandL( CStifItemParser& aItem );
    /*
    * TestTHuiCustomEventCommandExecuteL test method for testing the ExecuteL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiCustomEventCommandExecuteL( CStifItemParser& aItem );
    /*
    * TestTHuiCustomEventCommandSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiCustomEventCommandSizeL( CStifItemParser& aItem );
    /*
    * TestTHuiCustomEventCommandRecipientL test method for testing the Recipient method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiCustomEventCommandRecipientL( CStifItemParser& aItem );
    /*
    * TestTHuiCustomEventCommandParamL test method for testing the Param method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiCustomEventCommandParamL( CStifItemParser& aItem );
    /*
    * TestTHuiCustomEventCommandExtensionL test method for testing the CommandExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiCustomEventCommandExtensionL( CStifItemParser& aItem );
    
    
    
private:
    //test the method of HuiVisual.h

    /**
    * TestHuiVisualAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualAddNewL( CStifItemParser& aItem );

    /**
    * TestHuiVisualCHuiVisual test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualCHuiVisualL( CStifItemParser& aItem );

    /**
    * TestHuiVisualConstructL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualConstructL( CStifItemParser& aItem );

    /**
    * TestHuiVisualDelete test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDelete( CStifItemParser& aItem );

    /**
    * TestHuiVisualRemoveAndDestroyAllD test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualRemoveAndDestroyAllD( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetTagL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetTagL( CStifItemParser& aItem );

    /**
    * TestHuiVisualTag test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualTag( CStifItemParser& aItem );

    /**
    * TestHuiVisualIsTagged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualIsTagged( CStifItemParser& aItem );

    /**
    * TestHuiVisualFindTag test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualFindTag( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetFlag test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetFlag( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetFlags test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetFlags( CStifItemParser& aItem );

    /**
    * TestHuiVisualClearFlag test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualClearFlag( CStifItemParser& aItem );

    /**
    * TestHuiVisualAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualClearFlags( CStifItemParser& aItem );

    /**
    * TestHuiVisualFlags test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualFlags( CStifItemParser& aItem );

    /**
    * TestHuiVisualOwner test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualOwner( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetOwner test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetOwnerL( CStifItemParser& aItem );

    /**
    * TestHuiVisualCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualCount( CStifItemParser& aItem );

    /**
    * TestHuiVisualVisual test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualVisual( CStifItemParser& aItem );

    /**
    * TestHuiVisualLayout test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualLayoutL( CStifItemParser& aItem );

    /**
    * TestHuiVisualEnv test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualEnv( CStifItemParser& aItem );

    /**
    * TestHuiVisualSkin test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSkin( CStifItemParser& aItem );

    /**
    * TestHuiVisualDisplay test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDisplay( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetOrigin test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetOrigin( CStifItemParser& aItem );

    /**
    * TestHuiVisualHorizontalOrigin test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualHorizontalOrigin( CStifItemParser& aItem );

    /**
    * TestHuiVisualVerticalOrigin test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualVerticalOrigin( CStifItemParser& aItem );

    /**
    * TestHuiVisualAlignByOrigin test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualAlignByOrigin( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetMinTSizeL test method with TSize type parameter.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetMinTSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetMinHuiSizeL test method with THuiRealSize type parameter.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetMinHuiSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualMinSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMinSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualMinSizeInBaseUnits test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMinSizeInBaseUnitsL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetMaxTSize test method with TSize type parameter.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetMaxTSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetMaxHuiSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetMaxHuiSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualAddNewL test method with THuiRealSize type parameter.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMaxSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMaxSizeInBaseUnitsL( CStifItemParser& aItem );

    /**
    * TestHuiVisualPos test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPosConst( CStifItemParser& aItem );

    /**
    * TestHuiVisualConstSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualConstSize( CStifItemParser& aItem );

    /**
    * TestHuiVisualSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSize( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetPos test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetPos( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetSize( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetRect test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetRect( CStifItemParser& aItem );

    /**
    * TestHuiVisualMove test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualTMoveL( CStifItemParser& aItem );

    /**
    * TestHuiVisualHuiMove test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualHuiMoveL( CStifItemParser& aItem );

    /**
    * TestHuiVisualMimic test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMimicL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetCenteredPosAndSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetCenteredPosAndTSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetCenteredPosAndHuiSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetCenteredPosAndHuiSizeL( CStifItemParser& aItem );

    /**
    * TestHuiVisualUpdateChildrenLayout test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualUpdateChildrenLayout( CStifItemParser& aItem );

    /**
    * TestHuiVisualUpdateSiblingLayout test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualUpdateSiblingLayout( CStifItemParser& aItem );

    /**
    * TestHuiVisualDisplayRect test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDisplayRect( CStifItemParser& aItem );

    /**
    * TestHuiVisualDisplayRectTarget test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDisplayRectTarget( CStifItemParser& aItem );

    /**
    * TestHuiVisualLocalBaseUnit test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualLocalBaseUnit( CStifItemParser& aItem );

    /**
    * TestHuiVisualLocalPointInPixels test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualLocalPointInPixels( CStifItemParser& aItem );

    /**
    * TestHuiVisualLocalPointInPixelsWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualLocalPointInPixelsWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualPixelPointInLocal test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPixelPointInLocal( CStifItemParser& aItem );

    /**
    * TestHuiVisualPixelPointInLocalWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPixelPointInLocalWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualMetricToPixels test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMetricToPixels( CStifItemParser& aItem );

    /**
    * TestHuiVisualMetricToPixelsWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMetricToPixelsWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualPixelsToMetric test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPixelsToMetric( CStifItemParser& aItem );

    /**
    * TestHuiVisualPixelsToMetricWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPixelsToMetricWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualMetricReferenceInPixels test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMetricReferenceInPixels( CStifItemParser& aItem );

    /**
    * TestHuiVisualMetricReferenceInPixelsWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMetricReferenceInPixelsWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualLocalToDisplayT test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualLocalToDisplayT( CStifItemParser& aItem );

    /**
    * TestHuiVisualLocalToDisplayHui test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualLocalToDisplayHui( CStifItemParser& aItem );

    /**
    * TestHuiVisualDisplayToLocalT test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDisplayToLocalT( CStifItemParser& aItem );

    /**
    * TestHuiVisualDisplayToLocalHui test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDisplayToLocalHui( CStifItemParser& aItem );

    /**
    * TestHuiVisualBoxMetricToPixelRect test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualBoxMetricToPixelRect( CStifItemParser& aItem );

    /**
    * TestHuiVisualBoxMetricToPixelRectWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualBoxMetricToPixelRectWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualMoveToFront test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualMoveToFront( CStifItemParser& aItem );

    /**
    * TestHuiVisualPos test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPos( CStifItemParser& aItem );

    /**
    * TestHuiVisualEffectiveOpacity test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualEffectiveOpacity( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetClipping test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetClipping( CStifItemParser& aItem );

    /**
    * TestHuiVisualClipping test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualClipping( CStifItemParser& aItem );

    /**
    * TestHuiVisualEnableTransformationL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualEnableTransformationL( CStifItemParser& aItem );

    /**
    * TestHuiVisualTransformation test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualTransformation( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetPadding test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetPadding( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetPaddingWithPoint test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetPaddingWithPoint( CStifItemParser& aItem );

    /**
    * TestHuiVisualPaddingWithHuiBoxMetrix test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetPaddingWithHuiBoxMetrix( CStifItemParser& aItem );

    /**
    * TestHuiVisualPadding test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPadding( CStifItemParser& aItem );
    
    /**
    * TestHuiVisualPaddingInPixels test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPaddingInPixels( CStifItemParser& aItem );

    /**
    * TestHuiVisualPaddingInPixelsWithState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPaddingInPixelsWithState( CStifItemParser& aItem );

    /**
    * TestHuiVisualPrepareDrawL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualPrepareDrawL( CStifItemParser& aItem );

    /**
    * TestHuiVisualDraw test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDrawL( CStifItemParser& aItem );

    /**
    * TestHuiVisualDrawBrushes test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDrawBrushesL( CStifItemParser& aItem );

    /**
    * TestHuiVisualDrawSelf test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDrawSelfL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetChanged( CStifItemParser& aItem );

    /**
    * TestHuiVisualChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualChanged( CStifItemParser& aItem );

    /**
    * TestHuiVisualReportChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualReportChanged( CStifItemParser& aItem );

    /**
    * TestHuiVisualClearChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualClearChanged( CStifItemParser& aItem );

    /**
    * TestHuiVisualEnableBrushesL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualEnableBrushesL( CStifItemParser& aItem );

    /**
    * TestHuiVisualBrushes test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualBrushes( CStifItemParser& aItem );

    /**
    * TestHuiVisualDumpTree test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDumpTree( CStifItemParser& aItem );

    /**
    * TestHuiVisualGetInstanceName test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualGetInstanceName( CStifItemParser& aItem );

    /**
    * TestHuiVisualGetClassName test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualGetClassName( CStifItemParser& aItem );

    /**
    * TestHuiVisualEnterLocalProjection test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualEnterLocalProjectionL( CStifItemParser& aItem );

    /**
    * TestHuiVisualNotifySkinChangedL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualNotifySkinChangedL( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetTactileFeedbackL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetTactileFeedbackL( CStifItemParser& aItem );

    /**
    * TestHuiVisualHasTactileFeedback test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualHasTactileFeedbackL( CStifItemParser& aItem );

    /**
    * TestHuiVisualRemoveTactileFeedback test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualRemoveTactileFeedbackL( CStifItemParser& aItem );

    /**
    * TestHuiVisualEnableDropShadowL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualEnableDropShadowL( CStifItemParser& aItem );

    /**
    * TestHuiVisualDropShadowHandler test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualDropShadowHandler( CStifItemParser& aItem );

    /**
    * TestHuiVisualBrushOpacity test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualBrushOpacity( CStifItemParser& aItem );

    /**
    * TestHuiVisualBrushRect test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualBrushRect( CStifItemParser& aItem );

    /**
    * TestHuiVisualBrushSkin test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualBrushSkin( CStifItemParser& aItem );

    /**
    * TestHuiVisualType test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualType( CStifItemParser& aItem );

    /**
    * TestHuiVisualSessionId test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSessionId( CStifItemParser& aItem );

    /**
    * TestHuiVisualSetSessionId test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualSetSessionId( CStifItemParser& aItem );

    /**
    * TestHuiVisualTransform test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualTransformL( CStifItemParser& aItem );

    /**
    * TestHuiVisualExpandRectWithContent test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualExpandRectWithContentL( CStifItemParser& aItem );

    /**
    * TestHuiVisualVisualExtension test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiVisualVisualExtensionL( CStifItemParser& aItem );
    
private: // For testing the HuiBrushArray.h
    /**
    * TestHuiBrushArrayNewLL test method NewL of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayNewLL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayNewLCL test method NewLC of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayNewLCL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayResetL test method Reset of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayResetL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayAppendL test method AppendL of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayAppendL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayInsertL test method InsertL of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayInsertL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayRemoveL test method Remove of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayRemoveL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayCountL test method Count of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayCountL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayOperatorL test method operator of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayOperatorL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayAtL test method At of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayAtL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayLayerBrushCountL test method LayerBrushCount of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayLayerBrushCountL( CStifItemParser& aItem );
    /**
    * TestHuiBrushArrayDrawL test method Draw of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushArrayDrawL( CStifItemParser& aItem );
    
private:// For testing huibrush.h
    /**
    * TestHuiBrushExpandVisualRectL test method ExpandVisualRect of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushExpandVisualRectL( CStifItemParser& aItem );
    /**
    * TestHuiBrushSetChangedL test method SetChanged of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushSetChangedL( CStifItemParser& aItem );
    /**
    * TestHuiBrushChangedL test method Changed of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushChangedL( CStifItemParser& aItem );
    /**
    * TestHuiBrushClearChangedL test method ClearChanged of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushClearChangedL( CStifItemParser& aItem );
    /**
    * TestHuiBrushSetClipToVisualL test method SetClipToVisual of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushSetClipToVisualL( CStifItemParser& aItem );
    /**
    * TestHuiBrushClipToVisualL test method ClipToVisual of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushClipToVisualL( CStifItemParser& aItem );
    /**
    * TestHuiBrushSetLayerL test method SetLayer of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushSetLayerL( CStifItemParser& aItem );
    /**
    * TestHuiBrushLayerL test method Layer of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushLayerL( CStifItemParser& aItem );
    /**
    * TestHuiBrushBeginDrawL test method BeginDraw of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushBeginDrawL( CStifItemParser& aItem );
    /**
    * TestHuiBrushDrawL test method Draw of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushDrawL( CStifItemParser& aItem );
    /**
    * TestHuiBrushEndDrawL test method EndDraw of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushEndDrawL( CStifItemParser& aItem );
    /**
    * TestHuiBrushTypeL test method Type of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushTypeL( CStifItemParser& aItem );
    /**
    * TestHuiBrushSessionIdL test method SessionId of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushSessionIdL( CStifItemParser& aItem );
    /**
    * TestHuiBrushSetSessionIdL test method SetSessionId of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushSetSessionIdL( CStifItemParser& aItem );
    /**
    * TestHuiBrushCHuiBrushL test method CHuiBrush of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushCHuiBrushL( CStifItemParser& aItem );
    /**
    * TestHuiBrushBrushExtensionL test method BrushExtension of CHuiBrushArray.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiBrushBrushExtensionL( CStifItemParser& aItem );
    
private:// For testing huiframebrush.h
    /**
    * TestHuiFrameBrushNewLL test method NewL of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFrameBrushNewLL( CStifItemParser& aItem );
    /**
    * TestHuiFrameBrushNewLCL test method NewLC of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFrameBrushNewLCL( CStifItemParser& aItem );
    /**
    * TestHuiFrameBrushSetFrameRectsLL test method SetFrameRectsL of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFrameBrushSetFrameRectsLL( CStifItemParser& aItem );
    /**
    * TestHuiFrameBrushSetEdgeOffsetL test method SetEdgeOffset of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFrameBrushSetEdgeOffsetL( CStifItemParser& aItem );
    /**
    * TestHuiFrameBrushSetImageL test method SetImage of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFrameBrushSetImageL( CStifItemParser& aItem );
    
private:// For testing huiGradientBrush.h
    /**
    * TestHuiGradientBrushNewLL test method NewL of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushNewLL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushNewLCL test method NewLC of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushNewLCL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushSetDirectionL test method SetDirection of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushSetDirectionL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushSetColorL test method SetColor of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushSetColorL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushSetImageL test method SetImage of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushSetImageL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushColorL test method Color of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushColorL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushOpacityL test method Opacity of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushOpacityL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushImageL test method Image of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushImageL( CStifItemParser& aItem );
    /**
    * TestHuiGradientBrushAppendColorLL test method AppendColorL of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGradientBrushAppendColorLL( CStifItemParser& aItem );
    
private:// For testing huigc.h
    /**
    * TestHuiGcTHuiPathPointL test method THuiPathPoint of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcTHuiPathPoint( CStifItemParser& aItem );
    /**
    * TestHuiGcDrawImageL test method DrawImage of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcDrawImageL( CStifItemParser& aItem );
    /**
    * TestHuiGcDrawImagesL test method DrawImages of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcDrawImagesL( CStifItemParser& aItem );
    /**
    * TestHuiGcFontL test method Font of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcFontL( CStifItemParser& aItem );
    /**
    * TestHuiGcNearClipDistanceL test method NearClipDistance of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcNearClipDistanceL( CStifItemParser& aItem );
    /**
    * TestHuiGcFarClipDistanceL test method FarClipDistance of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcFarClipDistanceL( CStifItemParser& aItem );
    /**
    * TestHuiGcFovFactorL test method FovFactor of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcFovFactorL( CStifItemParser& aItem );
    /**
    * TestHuiGcOffset2DL test method Offset2D of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcOffset2DL( CStifItemParser& aItem );
    /**
    * TestHuiGcSetWindowTransformationL test method SetWindowTransformation of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcSetWindowTransformationL( CStifItemParser& aItem );
    /**
    * TestHuiGcLocaleTextAlignmentL test method LocaleTextAlignment of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGcLocaleTextAlignmentL( CStifItemParser& aItem );
    
private:// For testing HuiOwnedPointer.h
    /**
    * TestHuiOwnerdPointerCloseL test method Close of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerCloseL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerOperatorTL test method operator T of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerOperatorTL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerOperatorConstTL test method operator const T of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerOperatorConstTL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerOperatorL test method operator -> of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerOperatorL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerPtrL test method Ptr of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerPtrL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerRefL test method Ref of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerRefL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerNonConstRefL test method NonConstRef of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerNonConstRefL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerSetL test method Set of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerSetL( CStifItemParser& aItem );
    /**
    * TestHuiOwnerdPointerOwnershipL test method Ownership of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiOwnerdPointerOwnershipL( CStifItemParser& aItem );
    
private:// For testing huigifanimationtexture.h
    /**
    * TestHuiGifAnimationTextureNewLL test method NewL of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGifAnimationTextureNewLL( CStifItemParser& aItem );
    /**
    * TestHuiGifAnimationTextureIdL test method Id of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGifAnimationTextureIdL( CStifItemParser& aItem );
    /**
    * TestHuiGifAnimationTextureStartL test method Start of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGifAnimationTextureStartL( CStifItemParser& aItem );
    /**
    * TestHuiGifAnimationTextureStopL test method Stop of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGifAnimationTextureStopL( CStifItemParser& aItem );
    /**
    * TestHuiGifAnimationTextureEnableAnimationL test method EnableAnimation of CHuiFrameBrush.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGifAnimationTextureEnableAnimationL( CStifItemParser& aItem );
    //zhong
private://huitextstyle.h
    /*
    * TestTHuiTextTHuiTextStyle test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTHuiTextStyle( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTFont test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTFont( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTFontConst test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTFontConst( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetFont test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetFont( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTParentId test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTParentId( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetParentId test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetParentId( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTId test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTId( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTTextColor test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTTextColor( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetTextColor test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetTextColor( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTBackgroundColor test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTBackgroundColor( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetBackgroundColor test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetBackgroundColor( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTTextSizeInTwips test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTTextSizeInTwips( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetTextSizeInTwips test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetTextSizeInTwips( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTextSizeInPixels test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTextSizeInPixels( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetTextSizeInPixels test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetTextSizeInPixels( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextStrokeWeight test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextStrokeWeight( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetStrokeWeight test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetStrokeWeight( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTPosture test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTPosture( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetPosture test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetPosture( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTUnderline test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTUnderline( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetUnderline test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetUnderline( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTStrikeThrough test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTStrikeThrough( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTSetStrikeThrough test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTSetStrikeThrough( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTFontStyleId test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTFontStyleId( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextGetTypeface test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextGetTypeface( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextSetTextPaneHeightInPixels test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextSetTextPaneHeightInPixels( CStifItemParser& aItem );
    
    //huitextstylemanager.h
    /*
    * TestTHuiTextCHuiEnvL test method for huitextstylemanager.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCHuiEnvL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextTextStyle test method for huitextstylemanager.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextTextStyle( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextCopyTextStyleL test method for huitextstylemanager.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextCopyTextStyleL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextDeleteTextStyle test method for huitextstylemanager.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextDeleteTextStyle( CStifItemParser& aItem );
    
    //huitexture.h
    /*
    * TestTHuiTextNewL test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextNewL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextNewLC test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextNewLC( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextImageFileNameL test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextImageFileNameL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextHasContentL test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextHasContentL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextHasAlphaL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextHasAlphaL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextMaxTextureSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextMaxTextureSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextClearLL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextClearLL( CStifItemParser& aItem );
    
    /*
    * TestTHuiClearWithAlphaLL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiClearWithAlphaLL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentedTextureL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentedTextureL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentedTextureConstL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentedTextureConstL( CStifItemParser& aItem );
    
    /*
    * TestTHuiShadowedTextureL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiShadowedTextureL( CStifItemParser& aItem );
    
    /*
    * TestTHuiShadowedTextureConstL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiShadowedTextureConstL( CStifItemParser& aItem );
    
    /*
    * TestTHuiEnableShadowL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiEnableShadowL( CStifItemParser& aItem );
    
    /*
    * TestTHuiIsShadowEnabledL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiIsShadowEnabledL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetShadowStyleL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetShadowStyleL( CStifItemParser& aItem );
    
    /*
    * TestTHuiShadowStyleL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiShadowStyleL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentCountL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentCountL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentNameL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentNameL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentTextureSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentTextureSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSegmentOffsetL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSegmentOffsetL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextureChangedL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextureChangedL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTextureClearChangedL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTextureClearChangedL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSegmentOffsetL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSegmentOffsetL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSegmentCountL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSegmentCountL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSegmentNameL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSegmentNameL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSegmentSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSegmentSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSegmentTextureSizeL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSegmentTextureSizeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSkinContentL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSkinContentL( CStifItemParser& aItem );
    
    /*
    * TestTHuiIsSkinContentL  test method for huitexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiIsSkinContentL( CStifItemParser& aItem );
    
    /*
    * TestTHuiTypeL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiTypeL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSessionIdL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSessionIdL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetSessionIdL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetSessionIdL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetPriorityL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetPriorityL( CStifItemParser& aItem );
    
    /*
    * TestTHuiPriorityL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiPriorityL( CStifItemParser& aItem );
    
    /*
    * TestTHuiEnableAutoSizeCalculationL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiEnableAutoSizeCalculationL( CStifItemParser& aItem );
    
    /*
    * TestTHuiSetAutoSizeParamsL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiSetAutoSizeParamsL( CStifItemParser& aItem );
    
    /*
    * TestTHuiAutoSizeParamsL  test method for huitextstyle.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiAutoSizeParamsL( CStifItemParser& aItem );
    
    //huidisplay.h
    /*
    * TestTHuiEnvL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHuiEnvL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayActivateL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayActivateL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayActiveL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayActiveL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetSizeLL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetSizeLL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySizeL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySizeL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetVisibleAreaL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetVisibleAreaL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayVisibleAreaL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayVisibleAreaL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetOrientationL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetOrientationL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayOrientationL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayOrientationL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetUseDepthL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetUseDepthL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetClearBackgroundLL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetClearBackgroundLL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetBackgroundColor  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetBackgroundColorL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetBackgroundColor  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetBackgroundItemsL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayCaptureLCL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayCaptureLCL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayTransformationL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayTransformationL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayRosterL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayRosterL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayConstRosterL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayConstRosterL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayShowL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayShowL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetDirtyL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetDirtyL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetQualityL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetQualityL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayQualityL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayQualityL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetUsageLL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetUsageLL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayReleaseL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayReleaseL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayRestoreLL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayRestoreLL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetScreenBufferLockL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetScreenBufferLockL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayIsScreenBufferLockedL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayIsScreenBufferLockedL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayGetDrawingInterfaceL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayGetDrawingInterfaceL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayGetGraphicsContextL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayGetGraphicsContextL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayAddScreenBufferObserverLL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayAddScreenBufferObserverLL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayRemoveScreenBufferObserverL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayRemoveScreenBufferObserverL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayScreenBufferObserverL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayScreenBufferObserverL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayScreenBufferUidL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayScreenBufferUidL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayDisplayTypeL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayDisplayTypeL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayShowDirtyRegionsL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayShowDirtyRegionsL( CStifItemParser& aItem );
    
    /*
    * TestTDisplayGetPreferredTextureFormatsL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplayGetPreferredTextureFormatsL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetDrawVisualOutlineL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetDrawVisualOutlineL( CStifItemParser& aItem );
    
    /*
    * TestTDisplaySetVisibleAreaClippingRectL  test method for huidisplay.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTDisplaySetVisibleAreaClippingRectL( CStifItemParser& aItem );
    
    //huidisplaybackgrounditem.h
    /*
    * TestTTHuiDisplayBackgroundItemL  test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiDisplayBackgroundItemL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiDisplayBackgroundItemRectL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiDisplayBackgroundItemRectL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiDisplayBackgroundItemItemIDL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiDisplayBackgroundItemItemIDL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiDisplayBackgroundColorL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiDisplayBackgroundColorL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiDisplayBackgroundTRgbL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiDisplayBackgroundTRgbL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiTestTSetRectLL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiTestTSetRectLL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiSetColorL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiSetColorL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiSetColorItemL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiSetColorItemL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiSetSkinBackgroundL test method for huidisplaybackgrounditem.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiSetSkinBackgroundL( CStifItemParser& aItem );
    
    //HuiDisplayCoeControl.h
    /*
    * TestTTHuiCCNewLL test method for HuiDisplayCoeControl.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCNewLL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCNewLCL test method for HuiDisplayCoeControl.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCNewLCL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCEnvL test method for HuiDisplayCoeControl.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCEnvL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCDisplayL test method for HuiDisplayCoeControl.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCDisplayL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCHandlePointerEventL test method for HuiDisplayCoeControl.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCHandlePointerEventL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCDisplayCoeCntrlExtensionL test method for HuiDisplayCoeControl.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCDisplayCoeCntrlExtensionL( CStifItemParser& aItem );
    
    //huienv.h
    /*
    * TestTTHuiCEnvHuiEnvLC test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvHuiEnvLC( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvRenderer test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvRenderer( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvNewDisplayL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvNewDisplayL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvNewDisplayLL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvNewDisplayLL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvDisplayCount test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvDisplayCount( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvSetRefreshMode test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvSetRefreshMode( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvRefreshMode test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvRefreshMode( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvSetMaxFrameRate test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvSetMaxFrameRate( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvContinueRefresh test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvContinueRefresh( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvPauseRefresh test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvPauseRefresh( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvNewControlGroupL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvNewControlGroupL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvDeleteControlGroup test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvDeleteControlGroup( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvLoadControlGroupL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvLoadControlGroupL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvControlGroup test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvControlGroup( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCEnvLoadBitmapsL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCEnvLoadBitmapsL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCVisualFactory test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCVisualFactory( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCTextureManager test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCTextureManager( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCFontManager test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCFontManager( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCTextStyleManager test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCTextStyleManager( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCFindControl test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCFindControl( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCSendL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCSendL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCSendLL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCSendLL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCancelCommandsL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCancelCommandsL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCancelCommandsEventHandlerL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCancelCommandsEventHandlerL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCancelCommandsTHuiOpL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCancelCommandsTHuiOpL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCCancelCommandsTIntL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCCancelCommandsTIntL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCTimeUntilCommandL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCTimeUntilCommandL( CStifItemParser& aItem );
    
    /*
    * TestTTHuiCSkin test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTTHuiCSkin( CStifItemParser& aItem );
    
    /*
    * TestTStartRefresh test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTStartRefresh( CStifItemParser& aItem );
    
    /*
    * TestTHandleKeyEventLL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHandleKeyEventLL( CStifItemParser& aItem );
    
    /*
    * TestTSetIdleThreshold test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTSetIdleThreshold( CStifItemParser& aItem );
    
    /*
    * TestTBroadcastEventLL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTBroadcastEventLL( CStifItemParser& aItem );
    
    /*
    * TestTPrimaryDisplayL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTPrimaryDisplayL( CStifItemParser& aItem );
    
    /*
    * TestTCHuiEnvDisplayL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCHuiEnvDisplayL( CStifItemParser& aItem );
    
    /*
    * TestTCNotifySkinChangedLL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCNotifySkinChangedLL( CStifItemParser& aItem );
    
    /*
    * TestTCRefreshCallBack test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCRefreshCallBack( CStifItemParser& aItem );
    
    /*
    * TestTCRelease test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCRelease( CStifItemParser& aItem );
    
    /*
    * TestTCRestoreLL test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCRestoreL( CStifItemParser& aItem );
    
    /*
    * TestTCSetMaxCpuTime test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCSetMaxCpuTime( CStifItemParser& aItem );
    
    /*
    * TestTCStatic test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCStatic( CStifItemParser& aItem );
    
    /*
    * TestTCThemeManager test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCThemeManager( CStifItemParser& aItem );
    
    /*
    * TestTCSetFPSCounterThreshold test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCSetFPSCounterThreshold( CStifItemParser& aItem );
    
    /*
    * TestTCChangeRefreshLoopPriority test method for huienv.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTCChangeRefreshLoopPriority( CStifItemParser& aItem );
    
    //huievent.h
    /*
    * TestTHETHuiEventL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHETHuiEventL( CStifItemParser& aItem );
    
    /*
    * TestTHETPointerEventL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHETPointerEventL( CStifItemParser& aItem );
    
    /*
    * TestTHETypeL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHETypeL( CStifItemParser& aItem );
    
    /*
    * TestTHEIsCustomEventL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEIsCustomEventL( CStifItemParser& aItem );
    
    /*
    * TestTHEIsKeyEventL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEIsKeyEventL( CStifItemParser& aItem );
    
    /*
    * TestTHEIsPointerEventL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEIsPointerEventL( CStifItemParser& aItem );
    
    /*
    * TestTHEDisplayL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEDisplayL( CStifItemParser& aItem );
    
    /*
    * TestTHEPointerDownL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEPointerDownL( CStifItemParser& aItem );
    
    /*
    * TestTHEPointerUpL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEPointerUpL( CStifItemParser& aItem );
    
    /*
    * TestTHEPointerLongTapL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEPointerLongTapL( CStifItemParser& aItem );
    
    /*
    * TestTHESetVisualL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHESetVisualL( CStifItemParser& aItem );
    
    /*
    * TestTHEVisualL test method for huievent.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHEVisualL( CStifItemParser& aItem );
    
    //huidropshadow.h
    /*
    * TestTHSetOffsetL test method for huidropshadow.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHSetOffsetL( CStifItemParser& aItem );
    
    /*
    * TestTHSetColorL test method for huidropshadow.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHSetColorL( CStifItemParser& aItem );
    
    /*
    * TestTHSetColorTAknsItemIDL test method for huidropshadow.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHSetColorTAknsItemIDL( CStifItemParser& aItem );
    
    //huidropshadowbrush.h
    /*
    * TestShadowBrushNewLL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowBrushNewLL( CStifItemParser& aItem );
    
    /*
    * TestShadowBrushNewLCL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowBrushNewLCL( CStifItemParser& aItem );
    
    /*
    * TestShadowBrushNewLTIntL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowBrushNewLTIntL( CStifItemParser& aItem );
    
    /*
    * TestShadowBrushNewLTIntLCL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowBrushNewLTIntLCL( CStifItemParser& aItem );
    
    /*
    * TestShadowBrushSetDepthL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowBrushSetDepthL( CStifItemParser& aItem );
    
    /*
    * TestShadowSetSoftnessL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowSetSoftnessL( CStifItemParser& aItem );
    
    /*
    * TestShadowSetColorL test method for huidropshadowbrush.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestShadowSetColorL( CStifItemParser& aItem );
    
    //huiskin.h
    /*
    * TestHSkinOrientationL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinOrientationL( CStifItemParser& aItem );
    
    /*
    * TestHSkinLocationL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinLocationL( CStifItemParser& aItem );
    
    /*
    * TestHSkinNotifyDisplaySizeChangedLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinNotifyDisplaySizeChangedL( CStifItemParser& aItem );
    
    /*
    * TestHSkinNotifyDisplaySizeChangedLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinSetContextL( CStifItemParser& aItem );
    
    /*
    * TestHSkinContextL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinContextL( CStifItemParser& aItem );
    
    /*
    * TestHSkinStyleTextColorL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinStyleTextColorL( CStifItemParser& aItem );
    
    /*
    * TestHSkinTextureLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinTextureL( CStifItemParser& aItem );
    
    /*
    * TestHSkinReleaseTextureL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinReleaseTextureL( CStifItemParser& aItem );
    
    /*
    * TestHSkinGetTextureL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinGetTextureL( CStifItemParser& aItem );
    
    /*
    * TestHSkinTextureContentUploadedL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinTextureContentUploadedL( CStifItemParser& aItem );
    
    /*
    * TestHSkinTextureContentReleasedL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinTextureContentReleasedL( CStifItemParser& aItem );
    
    /*
    * TestHSkinRestoreTextureContentLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHSkinRestoreTextureContentLL( CStifItemParser& aItem );
    
    //huisegmentedtexture.h
    /*
    * TestHuisegmentedTextureHandleL test method for huisegmentedtexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuisegmentedTextureHandleL( CStifItemParser& aItem );
    
    /*
    * TestHuisegmentedTextureBindL test method for huisegmentedtexture.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuisegmentedTextureBindL( CStifItemParser& aItem );
    
   //huis60skin.h
    /*
    * TestH60SkinCHuiS60SkinL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinCHuiS60SkinL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinConstructLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinConstructLL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinLocationL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinLocationL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinTextureLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinTextureLL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinReleaseTextureL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinReleaseTextureL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinNotifyDisplaySizeChangedLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinNotifyDisplaySizeChangedLL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinStyleTextColorL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinStyleTextColorL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinRestoreTextureContentLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinRestoreTextureContentLL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinOrientationL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinOrientationL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinSetContextL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinSetContextL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinContextL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinContextL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinGetTextureL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinGetTextureL( CStifItemParser& aItem );
    
    /*
    * TestH60SkinSkinExtensionL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60SkinSkinExtensionL( CStifItemParser& aItem );
    
    //huishadowborderbrush.h
    /*
    * TestH60BordBrushNewLL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60BordBrushNewLL( CStifItemParser& aItem );
    
    /*
    * TestH60BordBrushNewLCL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60BordBrushNewLCL( CStifItemParser& aItem );
    
    /*
    * TestH60BordBrushNewLTIntL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60BordBrushNewLTIntL( CStifItemParser& aItem );
    
    /*
    * TestH60BordBrushNewLCTIntL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60BordBrushNewLCTIntL( CStifItemParser& aItem );
    
    /*
    * TestH60BordBrushSetWidthL test method for huiskin.h
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestH60BordBrushSetWidthL( CStifItemParser& aItem );
    
    //HuiLayout.h CHuiLayout
    /*
    * TestCHuiControlAddConnectionL test method for testing the AddNewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutAddNewL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutConstructorL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutDestructorL test method for testing the Destructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutDestructorL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutConstructL test method for testing the ConstructL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutConstructL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutRemoveAndDestroyAllDL test method for testing the RemoveAndDestroyAllD method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutRemoveAndDestroyAllDL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutFindTagL test method for testing the FindTag method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutFindTagL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutAppendL test method for testing the AppendL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutAppendL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutInsertL test method for testing the InsertL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutInsertL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutRemoveL test method for testing the Remove method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutRemoveL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutCountL test method for testing the Count method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutCountL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutVisualL test method for testing the Visual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutVisualL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutFindVisualL test method for testing the FindVisual method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutFindVisualL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetPosL test method for testing the SetPos method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetPosL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetSizeL test method for testing the SetSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetSizeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutUpdateChildrenLayoutL test method for testing the UpdateChildrenLayout method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutUpdateChildrenLayoutL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutUpdateChildLayoutL test method for testing the UpdateChildLayout method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutUpdateChildLayoutL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetInnerPaddingL test method for testing the SetInnerPadding method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetInnerPaddingL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetInnerPaddingWithMetricL test method for testing the SetInnerPadding method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetInnerPaddingWithMetricL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutInnerPaddingL test method for testing the InnerPadding method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutInnerPaddingL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutHorizontalInnerPaddingL test method for testing the HorizontalInnerPadding method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutHorizontalInnerPaddingL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutVerticalInnerPaddingL test method for testing the VerticalInnerPadding method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutVerticalInnerPaddingL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutInnerPaddingInBaseUnitsL test method for testing the InnerPaddingInBaseUnits method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutInnerPaddingInBaseUnitsL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutEnableScrollingL test method for testing the EnableScrollingL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutEnableScrollingL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutScrollingL test method for testing the Scrolling method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutScrollingL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutScrollOffsetL test method for testing the ScrollOffset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutScrollOffsetL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutScrollOffsetWithconstL test method for testing the ScrollOffset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutScrollOffsetWithconstL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetScrollOffsetInBaseUnitsL test method for testing the SetScrollOffsetInBaseUnits method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetScrollOffsetInBaseUnitsL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutVirtualSizeL test method for testing the VirtualSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutVirtualSizeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutEffectiveLayoutOrdinalL test method for testing the EffectiveLayoutOrdinal method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutEffectiveLayoutOrdinalL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutReorderL test method for testing the Reorder method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutReorderL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutMoveVisualToFrontL test method for testing the MoveVisualToFront method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutMoveVisualToFrontL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutMoveVisualToBackL test method for testing the MoveVisualToBack method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutMoveVisualToBackL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutNotifySkinChangedL test method for testing the NotifySkinChangedL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutNotifySkinChangedL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetTransitionTimeL test method for testing the SetTransitionTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetTransitionTimeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutTransitionTimeL test method for testing the TransitionTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutTransitionTimeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutChildOrdinalL test method for testing the ChildOrdinal method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutChildOrdinalL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutPrepareDrawL test method for testing the PrepareDrawL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutPrepareDrawL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutDrawL test method for testing the Draw method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutDrawL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutReportChangedL test method for testing the ReportChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutReportChangedL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutClearChangedL test method for testing the ClearChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutClearChangedL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutChangedL test method for testing the Changed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutChangedL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutDumpTreeL test method for testing the DumpTree method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutDumpTreeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetBaseUnitL test method for testing the SetBaseUnit method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetBaseUnitL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetBaseUnitXYL test method for testing the SetBaseUnit method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetBaseUnitXYL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutBaseUnitL test method for testing the BaseUnit method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutBaseUnitL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutInnerSizeL test method for testing the InnerSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutInnerSizeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutInnerTopLeftL test method for testing the InnerTopLeft method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutInnerTopLeftL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutChildSizeL test method for testing the ChildSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutChildSizeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutChildPosL test method for testing the ChildPos method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutChildPosL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutChildRectL test method for testing the ChildRect method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutChildRectL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutBrushOpacityL test method for testing the BrushOpacity method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutBrushOpacityL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutBrushRectL test method for testing the BrushRect method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutBrushRectL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutBrushSkinL test method for testing the BrushSkin method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutBrushSkinL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutGetInstanceNameL test method for testing the GetInstanceName method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutGetInstanceNameL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutGetClassNameL test method for testing the GetClassName method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutGetClassNameL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutTypeL test method for testing the Type method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutTypeL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSessionIdL test method for testing the SessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSessionIdL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutSetSessionIdL test method for testing the SetSessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutSetSessionIdL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutDrawSelfL test method for testing the DrawSelf method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutDrawSelfL( CStifItemParser& aItem );

    /*
    * TestHLMetricReferenceForLayoutInPixelsWithLayoutL test method
    * for testing the MetricReferenceForLayoutInPixels method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHLMetricReferenceForLayoutInPixelsWithLayoutL( CStifItemParser& aItem );

    /*
    * TestHLMetricReferenceForLayoutInPixelsL test method
    * for testing the MetricReferenceForLayoutInPixels method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHLMetricReferenceForLayoutInPixelsL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutExpandRectWithContentL test method
    * for testing the ExpandRectWithContent method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutExpandRectWithContentL( CStifItemParser& aItem );

    /*
    * TestCHuiLayoutVisualExtensionL test method for testing the VisualExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiLayoutVisualExtensionL( CStifItemParser& aItem );

private://HuiLineVisual.h CHuiLineVisual
    /*
    * TestCHLVAddNewL test method for testing the AddNewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVAddNewL( CStifItemParser& aItem );

    /*
    * TestCHLVSetPathL test method for testing the SetPath method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVSetPathL( CStifItemParser& aItem );

    /*
    * TestCHLVPathL test method for testing the Path method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVPathL( CStifItemParser& aItem );

    /*
    * TestCHLVSetImageL test method for testing the SetImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVSetImageL( CStifItemParser& aItem );

    /*
    * TestCHLVSetAlphaFunctionL test method for testing the SetAlphaFunction method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVSetAlphaFunctionL( CStifItemParser& aItem );

    /*
    * TestCHLVSetWidthFunctionL test method for testing the SetWidthFunction method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVSetWidthFunctionL( CStifItemParser& aItem );

    /*
    * TestCHLVSetColorL test method for testing the SetColor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHLVSetColorL( CStifItemParser& aItem );

    // huim3gmesh.h CHuiM3GMesh
    /*
    * TestCHM3GMLoadSceneL test method for testing the LoadSceneL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHM3GMLoadSceneL( CStifItemParser& aItem );

    /*
    * TestCHM3GMSetAnimationPositionL test method for testing the SetAnimationPosition method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHM3GMSetAnimationPositionL( CStifItemParser& aItem );

    /*
    * TestCHM3GMStartAnimationControllerL test method for testing the StartAnimationController method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHM3GMStartAnimationControllerL( CStifItemParser& aItem );

    /*
    * TestCHM3GMStopAnimationControllerL test method for testing the StopAnimationController method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHM3GMStopAnimationControllerL( CStifItemParser& aItem );

private: // HuiMappingFunctions.h THuiConstantMappingFunction
    /*
    * TestTHCMFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHCMFConstructorL( CStifItemParser& aItem );

    /*
    * TestTHCMFMapValueL test method for testing the MapValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHCMFMapValueL( CStifItemParser& aItem );

    // HuiMappingFunctions.h THuiLinearMappingFunction
    /*
    * TestTHLMFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHLMFConstructorL( CStifItemParser& aItem );

    /*
    * TestTHLMFMapValueL test method for testing the MapValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHLMFMapValueL( CStifItemParser& aItem );

    // HuiMappingFunctions.h THuiSineMappingFunction
    /*
    * TestTHSMFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHSMFConstructorL( CStifItemParser& aItem );

    /*
    * TestTHSMFMapValueL test method for testing the MapValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHSMFMapValueL( CStifItemParser& aItem );

    // HuiMappingFunctions.h THuiCosineMappingFunction
    /*
    * TestTHCosineMFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHCosineMFConstructorL( CStifItemParser& aItem );

    /*
    * TestTHCosineMFMapValueL test method for testing the MapValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHCosineMFMapValueL( CStifItemParser& aItem );

    // HuiMappingFunctions.h THuiAverageMappingFunction
    /*
    * TestTHAMFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHAMFConstructorL( CStifItemParser& aItem );

    /*
    * TestTHAMFMapValueL test method for testing the MapValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHAMFMapValueL( CStifItemParser& aItem );

    /*
    * TestTHAMFMappingFunctionChangedL test method for testing the MappingFunctionChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHAMFMappingFunctionChangedL( CStifItemParser& aItem );

    /*
    * TestTHAMFMappingFunctionClearChangedL test method 
    * for testing the MappingFunctionClearChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHAMFMappingFunctionClearChangedL( CStifItemParser& aItem );

private:// HuiMesh.h CHuiMesh
    /*
    * TestCHuiMeshNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshNewL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshNewLCL test method for testing the NewLC method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshNewLCL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshDestructL test method for testing the Destruct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshDestructL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshMeshTypeL test method for testing the MeshType method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshMeshTypeL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshResetL test method for testing the Reset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshResetL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshStretchUniformlyL test method for testing the StretchUniformly method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshStretchUniformlyL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshScaleUniformlyL test method for testing the ScaleUniformly method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshScaleUniformlyL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshTypeL test method for testing the Type method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshTypeL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshSessionIdL test method for testing the SessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshSessionIdL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshSetSessionIdL test method for testing the SetSessionId method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshSetSessionIdL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshAnimationControllerCountL test method for testing the AnimationControllerCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshAnimationControllerCountL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshSetAnimationPositionL test method for testing the SetAnimationPosition method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshSetAnimationPositionL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshStartAnimationControllerL test method for testing the StartAnimationController method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshStartAnimationControllerL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshStopAnimationControllerL test method for testing the StopAnimationController method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshStopAnimationControllerL( CStifItemParser& aItem );

private:// huimeshvisual.h CHuiMeshVisual
    /*
    * TestCHuiMeshVisualAddNewL test method for testing the AddNewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualAddNewL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualCreateMeshL test method for testing the CreateMeshL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualCreateMeshL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualSetImageL test method for testing the SetImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualSetImageL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualSetSecondaryImageL test method for testing the SetSecondaryImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualSetSecondaryImageL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualSetSpecularImageL test method for testing the SetSpecularImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualSetSpecularImageL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualMeshL test method for testing the Mesh method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualMeshL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualProceduralMeshL test method for testing the ProceduralMesh method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualProceduralMeshL( CStifItemParser& aItem );

    /*
    * TestCHuiMeshVisualM3GMeshL test method for testing the M3GMesh method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiMeshVisualM3GMeshL( CStifItemParser& aItem );

private:// huimetric.h THuiMetric
    /*
    * TestTHMConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHMConstructor( CStifItemParser& aItem );

    /*
    * TestTHMConstructorWithPixel test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHMConstructorWithPixel( CStifItemParser& aItem );

    /*
    * TestTHMAbs test method for testing the Abs method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHMAbs( CStifItemParser& aItem );

    /*
    * TestTHMoperator test method for testing the operator * method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHMoperator( CStifItemParser& aItem );

    // huimetric.h THuiXYMetric
    /*
    * TestTHXYMConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHXYMConstructor( CStifItemParser& aItem );

    /*
    * TestTHXYMConstructorWithMetric test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHXYMConstructorWithMetric( CStifItemParser& aItem );

    /*
    * TestTHXYMConstructorWithTwo test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHXYMConstructorWithTwo( CStifItemParser& aItem );

    /*
    * TestTHXYMoperator test method for testing the operator * method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHXYMoperator( CStifItemParser& aItem );

    /*
    * TestTHXYMAbs test method for testing the Abs method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHXYMAbs( CStifItemParser& aItem );

    // huimetric.h THuiBoxMetric
    /*
    * TestTHBMConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHBMConstructor( CStifItemParser& aItem );

    /*
    * TestTHBMConstructorWithMetric test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHBMConstructorWithMetric( CStifItemParser& aItem );

    /*
    * TestTHBMConstructorWithXYMetric test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHBMConstructorWithXYMetric( CStifItemParser& aItem );

    /*
    * TestTHBMConstructorWithTwo test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHBMConstructorWithTwo( CStifItemParser& aItem );

    /*
    * TestTHBMConstructorWithTwo test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHBMConstructorWithFour( CStifItemParser& aItem );

private:// huirealpoint.h THuiRealPoint
    /*
    * TestTHRPConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPConstructor( CStifItemParser& aItem );

    /*
    * TestTHRPConstructorWithTReal test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPConstructorWithTReal( CStifItemParser& aItem );

    /*
    * TestTHRPConstructorWithTPoint test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPConstructorWithTPoint( CStifItemParser& aItem );

    /*
    * TestTHRPAsSize test method for testing the AsSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPAsSize( CStifItemParser& aItem );

    /*
    * TestTHRPTPoint test method for testing the operator TPoint method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPTPoint( CStifItemParser& aItem );

    /*
    * TestTHRPRound test method for testing the Round method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPRound( CStifItemParser& aItem );

    /*
    * TestTHRPoperator1 test method for testing the operator + method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPoperator1( CStifItemParser& aItem );

    /*
    * TestTHRPoperator2 test method for testing the operator += method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPoperator2( CStifItemParser& aItem );

    /*
    * TestTHRPoperator3 test method for testing the operator -= method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPoperator3( CStifItemParser& aItem );

    /*
    * TestTHRPoperator4 test method for testing the operator - method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPoperator4( CStifItemParser& aItem );

    /*
    * TestTHRPoperator5 test method for testing the operator - method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPoperator5( CStifItemParser& aItem );

    /*
    * TestTHRPoperator6 test method for testing the operator * method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPoperator6( CStifItemParser& aItem );

    /*
    * TestTHRPAbs test method for testing the Abs method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRPAbs( CStifItemParser& aItem );

private:// HuiRealRect.h THuiRealRect
    /*
    * TestTHRRConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRConstructor( CStifItemParser& aItem );

    /*
    * TestTHRRConstructorWithPoint test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRConstructorWithPoint( CStifItemParser& aItem );

    /*
    * TestTHRRConstructorWithPointAndSize test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRConstructorWithPointAndSize( CStifItemParser& aItem );

    /*
    * TestTHRRConstructorWithTRect test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRConstructorWithTRect( CStifItemParser& aItem );

    /*
    * TestTHRRWidth test method for testing the Width method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRWidth( CStifItemParser& aItem );

    /*
    * TestTHRRHeight test method for testing the Height method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRHeight( CStifItemParser& aItem );

    /*
    * TestTHRRTopRight test method for testing the TopRight method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRTopRight( CStifItemParser& aItem );

    /*
    * TestTHRRBottomLeft test method for testing the BottomLeft method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRBottomLeft( CStifItemParser& aItem );

    /*
    * TestTHRRSize test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRSize( CStifItemParser& aItem );

    /*
    * TestTHRRCenter test method for testing the Center method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRCenter( CStifItemParser& aItem );

    /*
    * TestTHRRGrow test method for testing the Grow method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRGrow( CStifItemParser& aItem );

    /*
    * TestTHRRShrink test method for testing the Shrink method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRShrink( CStifItemParser& aItem );

    /*
    * TestTHRRShrinkPoint test method for testing the Grow method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRShrinkTPoint( CStifItemParser& aItem );

    /*
    * TestTHRRShrinkTHuiRealPoint test method for testing the Shrink method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRShrinkTHuiRealPoint( CStifItemParser& aItem );

    /*
    * TestTHRRShrinkTHuiRealRect test method for testing the Grow method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRShrinkTHuiRealRect( CStifItemParser& aItem );

    /*
    * TestTHRRMove test method for testing the Move method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRMove( CStifItemParser& aItem );

    /*
    * TestTHRRoperatorTRect test method for testing the operator TRect method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRoperatorTRect( CStifItemParser& aItem );

    /*
    * TestTHRRRound test method for testing the Round method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRRound( CStifItemParser& aItem );

    /*
    * TestTHRRBoundingRect test method for testing the BoundingRect method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRRBoundingRect( CStifItemParser& aItem );

private:// huirealsize.h THuiRealSize
    /*
    * TestTHRSConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRSConstructor( CStifItemParser& aItem );

    /*
    * TestTHRSConstructorWithTReal test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRSConstructorWithTReal( CStifItemParser& aItem );

    /*
    * TestTHRSConstructorWithTSize test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRSConstructorWithTSize( CStifItemParser& aItem );

    /*
    * TestTHRSoperatorTSize test method for testing the operator TSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRSoperatorTSize( CStifItemParser& aItem );

    /*
    * TestTHRSRound test method for testing the Round method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRSRound( CStifItemParser& aItem );

    /*
    * TestTHRSoperatorPlus test method for testing the operator * method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHRSoperatorPlus( CStifItemParser& aItem );

private:// huiproceduralmesh.h CHuiProceduralMesh
    /*
    * TestHPMDeleteL test method for testing the destruct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMDeleteL( CStifItemParser& aItem );

    /*
    * TestHPMResetL test method for testing the Reset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMResetL( CStifItemParser& aItem );

    /*
    * TestHPMMakeCubeL test method for testing the MakeCubeL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMMakeCubeL( CStifItemParser& aItem );

    /*
    * TestHPMMakeSphereL test method for testing the MakeSphereL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMMakeSphereL( CStifItemParser& aItem );

    /*
    * MakeTorusL test method for testing the MakeTorusL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMMakeTorusL( CStifItemParser& aItem );

    /*
    * TestHPMStretchUniformlyL test method for testing the StretchUniformly method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMStretchUniformlyL( CStifItemParser& aItem );

    /*
    * TestHPMScaleUniformlyL test method for testing the ScaleUniformly method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHPMScaleUniformlyL( CStifItemParser& aItem );

private:// huistatic.h CHuiStatic
    /*
    * TestCHuiStaticEnv test method for testing the Env method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticEnv( CStifItemParser& aItem );

    /*
    * TestCHuiStaticTime test method for testing the Time method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticTime( CStifItemParser& aItem );

    /*
    * TestCHuiStaticSetTimeFactor test method for testing the SetTimeFactor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticSetTimeFactor( CStifItemParser& aItem );

    /*
    * TestCHuiStaticTimeFactor test method for testing the TimeFactor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticTimeFactor( CStifItemParser& aItem );

    /*
    * TestCHuiStaticPauseTime test method for testing the PauseTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticPauseTime( CStifItemParser& aItem );

    /*
    * TestCHuiStaticContinueTime test method for testing the ContinueTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticContinueTime( CStifItemParser& aItem );

    /*
    * TestCHuiStaticTimePaused test method for testing the TimePaused method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticTimePaused( CStifItemParser& aItem );

    /*
    * TestCHuiStaticElapsedSeconds test method for testing the ElapsedSeconds method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticElapsedSeconds( CStifItemParser& aItem );

    /*
    * TestCHuiStaticSecondsSinceStart test method for testing the SecondsSinceStart method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticSecondsSinceStart( CStifItemParser& aItem );

    /*
    * TestCHuiStaticMilliSecondsSinceStart test method for testing the MilliSecondsSinceStart method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticMilliSecondsSinceStart( CStifItemParser& aItem );

    /*
    * TestCHuiStaticFrameCount test method for testing the FrameCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticFrameCount( CStifItemParser& aItem );

    /*
    * TestCHuiStaticAverageFrameRate test method for testing the AverageFrameRate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticAverageFrameRate( CStifItemParser& aItem );

    /*
    * TestCHuiStaticFrameRate test method for testing the FrameRate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticFrameRate( CStifItemParser& aItem );

    /*
    * TestCHuiStaticPrintfTDesC8 test method for testing the Printf method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticPrintfTDesC8( CStifItemParser& aItem );

    /*
    * TestCHuiStaticPrintfTDesC16 test method for testing the Printf method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticPrintfTDesC16( CStifItemParser& aItem );

    /*
    * TestCHuiStaticEnableLogging test method for testing the EnableLogging method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticEnableLogging( CStifItemParser& aItem );

    /*
    * TestCHuiStaticLogging test method for testing the Logging method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticLogging( CStifItemParser& aItem );

    /*
    * TestCHuiStaticTic test method for testing the Tic method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticTic( CStifItemParser& aItem );

    /*
    * TestCHuiStaticToc test method for testing the Toc method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticToc( CStifItemParser& aItem );

    /*
    * TestCHuiStaticFsSession test method for testing the FsSession method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticFsSession( CStifItemParser& aItem );

    /*
    * TestCHuiStaticSetLayoutTransitionTime test method for testing the SetLayoutTransitionTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticSetLayoutTransitionTime( CStifItemParser& aItem );

    /*
    * TestCHuiStaticLayoutTransitionTime test method for testing the LayoutTransitionTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticLayoutTransitionTime( CStifItemParser& aItem );

    /*
    * TestCHuiStaticSetProbe test method for testing the SetProbe method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHuiStaticSetProbe( CStifItemParser& aItem );

private:// huisoftkeycontrol.h CHuiSoftKeyControl
    /*
    * TestCHSKCNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCNewL( CStifItemParser& aItem );

    /*
    * TestCHSKCNewLCL test method for testing the NewLCL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCNewLCL( CStifItemParser& aItem );

    /*
    * TestCHSKCDestructL test method for testing the destruct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCDestructL( CStifItemParser& aItem );

    /*
    * TestCHSKCSetLabelL test method for testing the SetLabelL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCSetLabelL( CStifItemParser& aItem );

    /*
    * TestCHSKCSetBackgroundL test method for testing the SetBackgroundL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCSetBackgroundL( CStifItemParser& aItem );

    /*
    * TestCHSKCSetAnimationTimesL test method for testing the SetAnimationTimes method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCSetAnimationTimesL( CStifItemParser& aItem );

    /*
    * TestCHSKCEnterViewL test method for testing the EnterView method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCEnterViewL( CStifItemParser& aItem );

    /*
    * TestCHSKCExitViewL test method for testing the ExitView method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCExitViewL( CStifItemParser& aItem );

    /*
    * TestCHSKCSetBackgroundTypeL test method for testing the SetBackgroundType method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHSKCSetBackgroundTypeL( CStifItemParser& aItem );

private:// huiutil.h HuiUtil
    /*
    * TestHuiUtilPower2 test method for testing the Power2 method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilPower2( CStifItemParser& aItem );

    /*
    * TestHuiUtilPower2RoundDown test method for testing the Power2RoundDown method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilPower2RoundDown( CStifItemParser& aItem );

    /*
    * TestHuiUtilInterpolate test method for testing the Interpolate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilInterpolate( CStifItemParser& aItem );

    /*
    * TestHuiUtilWrapValue test method for testing the WrapValue method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilWrapValue( CStifItemParser& aItem );

    /*
    * TestHuiUtilRandomInt test method for testing the RandomInt method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilRandomInt( CStifItemParser& aItem );

    /*
    * TestHuiUtilRandomReal test method for testing the RandomReal method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilRandomReal( CStifItemParser& aItem );

    /*
    * TestHuiUtilQuickLengthWithPoint test method for testing the QuickLength method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilQuickLengthWithPoint( CStifItemParser& aItem );

    /*
    * TestHuiUtilQuickLength test method for testing the QuickLength method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilQuickLength( CStifItemParser& aItem );

    /*
    * TestHuiUtilQuickNormalizeWithPoint test method for testing the QuickNormalize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilQuickNormalizeWithPoint( CStifItemParser& aItem );

    /*
    * TestHuiUtilQuickNormalize test method for testing the QuickNormalize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilQuickNormalize( CStifItemParser& aItem );

    /*
    * TestHuiUtilCrossProduct test method for testing the CrossProduct method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilCrossProduct( CStifItemParser& aItem );

    /*
    * TestHuiUtilNormalFromPoints test method for testing the NormalFromPoints method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilNormalFromPoints( CStifItemParser& aItem );

    /*
    * TestHuiUtilShadowMatrix test method for testing the ShadowMatrix method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilShadowMatrix( CStifItemParser& aItem );

    /*
    * TestHuiUtilFreeMemory test method for testing the FreeMemory method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilFreeMemory( CStifItemParser& aItem );

    /*
    * TestHuiUtilScreenSize test method for testing the ScreenSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilScreenSize( CStifItemParser& aItem );

    /*
    * TestHuiUtilLengthUnit test method for testing the LengthUnit method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilLengthUnit( CStifItemParser& aItem );

    /*
    * TestHuiUtilColorLightness test method for testing the ColorLightness method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilColorLightness( CStifItemParser& aItem );

    /*
    * TestHuiUtilScaleFbsBitmapL test method for testing the ScaleFbsBitmapL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilScaleFbsBitmapL( CStifItemParser& aItem );

    /*
    * TestHuiUtilCombineMaskFbsBitmapL test method for testing the CombineMaskFbsBitmapL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilCombineMaskFbsBitmapL( CStifItemParser& aItem );

    /*
    * TestHuiUtilCropFbsBitmapL test method for testing the CropFbsBitmapL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilCropFbsBitmapL( CStifItemParser& aItem );

    /*
    * TestHuiUtilScaleImageL test method for testing the ScaleImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilScaleImageL( CStifItemParser& aItem );

    /*
    * TestHuiUtilCropImageL test method for testing the CropImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilCropImageL( CStifItemParser& aItem );

    /*
    * TestHuiUtilTagMatches test method for testing the TagMatches method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilTagMatches( CStifItemParser& aItem );

    /*
    * TestHuiUtilConvertBitmapToDisplayModeLCL test method for testing the ConvertBitmapToDisplayModeLC method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiUtilConvertBitmapToDisplayModeLCL( CStifItemParser& aItem );

private://huitimedvalue.h MHuiMappingFunction
    /*
    * TestMHMFMappingFunctionChangedL test method for testing the MappingFunctionChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestMHMFMappingFunctionChangedL( CStifItemParser& aItem );

    /*
    * TestMHMFMappingFunctionClearChangedL test method for testing the MappingFunctionClearChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestMHMFMappingFunctionClearChangedL( CStifItemParser& aItem );

    // THuiTimedValue
    /*
    * TestTHTVConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVConstructor( CStifItemParser& aItem );

    /*
    * TestTHTVConstructorWithValue test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVConstructorWithValue( CStifItemParser& aItem );

    /*
    * TestTHTVStyle test method for testing the Style method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVStyle( CStifItemParser& aItem );

    /*
    * TestTHTVSetStyle test method for testing the SetStyle method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSetStyle( CStifItemParser& aItem );

    /*
    * SetFunction test method for testing the SetFunction method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSetFunction( CStifItemParser& aItem );

    /*
    * TestTHTVSetMappingMode test method for testing the SetMappingMode method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSetMappingMode( CStifItemParser& aItem );

    /*
    * TestTHTVNow test method for testing the Now method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVNow( CStifItemParser& aItem );

    /*
    * TestTHTVUnmappedNow test method for testing the UnmappedNow method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVUnmappedNow( CStifItemParser& aItem );

    /*
    * TestTHTVTarget test method for testing the Target method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVTarget( CStifItemParser& aItem );

    /*
    * TestTHTVSetValue test method for testing the Set method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSetValue( CStifItemParser& aItem );

    /*
    * TestTHTVSetValueTime test method for testing the Set method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSetValueTime( CStifItemParser& aItem );

    /*
    * TestTHTVSetWithSpeed test method for testing the SetWithSpeed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSetWithSpeed( CStifItemParser& aItem );

    /*
    * TestTHTVRemainingTime test method for testing the RemainingTime method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVRemainingTime( CStifItemParser& aItem );

    /*
    * TestTHTVFinish test method for testing the Finish method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVFinish( CStifItemParser& aItem );

    /*
    * TestTHTVChanged test method for testing the Changed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVChanged( CStifItemParser& aItem );

    /*
    * TestTHTVInterpolating test method for testing the Interpolating method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVInterpolating( CStifItemParser& aItem );

    /*
    * TestTHTVClearChanged test method for testing the ClearChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVClearChanged( CStifItemParser& aItem );

    /*
    * TestTHTVEnableClock test method for testing the EnableClock method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVEnableClock( CStifItemParser& aItem );

    /*
    * TestTHTVSuspend test method for testing the Suspend method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVSuspend( CStifItemParser& aItem );

    /*
    * TestTHTVoperatorEqualTo test method for testing the operator = method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTVoperatorEqualTo( CStifItemParser& aItem );

private:// huiimage.h THuiImage
    /*
    * TestTHIConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIConstructor( CStifItemParser& aItem );

    /*
    * TestTHIConstructorWithParaL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIConstructorWithParaL( CStifItemParser& aItem );

    /*
    * TestTHISegmentCountL test method for testing the SegmentCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHISegmentCountL( CStifItemParser& aItem );

    /*
    * TestTHIGetVertexCoordsL test method for testing the GetVertexCoords method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIGetVertexCoordsL( CStifItemParser& aItem );

    /*
    * TestTHIGetTexCoordsL test method for testing the GetTexCoords method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIGetTexCoordsL( CStifItemParser& aItem );

    /*
    * TestTHISetTexCoords test method for testing the SetTexCoords method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHISetTexCoordsL( CStifItemParser& aItem );

    /*
    * TestTHITopLeft test method for testing the TopLeft method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHITopLeftL( CStifItemParser& aItem );

    /*
    * TestTHIBottomRight test method for testing the BottomRight method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIBottomRightL( CStifItemParser& aItem );

    /*
    * TestTHIHasTexture test method for testing the HasTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIHasTextureL( CStifItemParser& aItem );

    /*
    * TestTHIHasTextureL test method for testing the SetTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHISetTextureL( CStifItemParser& aItem );

    /*
    * TestTHITextureL test method for testing the Texture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHITextureL( CStifItemParser& aItem );

    /*
    * TestTHITextureIfL test method for testing the TextureIf method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHITextureIfL( CStifItemParser& aItem );

    /*
    * TestTHIHasShadow test method for testing the HasShadow method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIHasShadow( CStifItemParser& aItem );

    /*
    * TestTHIShadowTexture test method for testing the ShadowTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIShadowTexture( CStifItemParser& aItem );

    /*
    * TestTHITranslate test method for testing the Translate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHITranslate( CStifItemParser& aItem );

    /*
    * TestTHIScale test method for testing the Scale method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIScale( CStifItemParser& aItem );

private:// huiimagebrush.h CHuiImageBrush
    /*
    * TestCHIBNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBNewL( CStifItemParser& aItem );

    /*
    * TestCHIBNewLCL test method for testing the NewLC method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBNewLCL( CStifItemParser& aItem );

    /*
    * TestCHIBSetScaleModeL test method for testing the SetScaleMode method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBSetScaleModeL( CStifItemParser& aItem );

    /*
    * TestCHIBSetImageL test method for testing the SetImage method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBSetImageL( CStifItemParser& aItem );

    /*
    * TestCHIBSetBordersL test method for testing the SetBorders method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBSetBordersL( CStifItemParser& aItem );

    /*
    * TestCHIBBorderDrawingEnabledL test method for testing the BorderDrawingEnabled method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBBorderDrawingEnabledL( CStifItemParser& aItem );

    /*
    * TestCHIBCenterDrawingEnabledL test method for testing the CenterDrawingEnabled method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBCenterDrawingEnabledL( CStifItemParser& aItem );

    /*
    * TestCHIBExpandVisualRectL test method for testing the ExpandVisualRect method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBExpandVisualRectL( CStifItemParser& aItem );

    /*
    * TestCHIBBorderDrawingEnabledL test method for testing the BorderDrawingEnabled method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHIBDrawL( CStifItemParser& aItem );

private:// huitimedpoint.h THuiTimedPoint
    /*
    * TestTHTPConstructor test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPConstructor( CStifItemParser& aItem );

    /*
    * TestTHTPConstructorWithTReal test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPConstructorWithTReal( CStifItemParser& aItem );

    /*
    * TestTHTPSetStyle test method for testing the SetStyle method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPSetStyle( CStifItemParser& aItem );

    /*
    * TestTHTPSetFunctionL test method for testing the SetFunction method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPSetFunctionL( CStifItemParser& aItem );

    /*
    * TestTHTPSet test method for testing the Set method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPSet( CStifItemParser& aItem );

    /*
    * TestTHTPSetTReal test method for testing the Set method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPSetTReal( CStifItemParser& aItem );

    /*
    * TestTHTPSetWithSpeed test method for testing the SetWithSpeed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPSetWithSpeed( CStifItemParser& aItem );

    /*
    * TestTHTPSetWithSpeedTReal test method for testing the SetWithSpeed method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPSetWithSpeedTReal( CStifItemParser& aItem );

    /*
    * TestTHTPNow test method for testing the Now method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPNow( CStifItemParser& aItem );

    /*
    * TestTHTPRealNow test method for testing the RealNow method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPRealNow( CStifItemParser& aItem );

    /*
    * TestTHTPTarget test method for testing the Target method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPTarget( CStifItemParser& aItem );

    /*
    * TestTHTPRealTarget test method for testing the RealTarget method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPRealTarget( CStifItemParser& aItem );

    /*
    * TestTHTPFinish test method for testing the Finish method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTPFinish( CStifItemParser& aItem );

private:// huitexturehandle.h THuiTextureHandle
    /*
    * TestTHTHConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHConstructorL( CStifItemParser& aItem );

    /*
    * TestTHTHConstructorWithParaL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHConstructorWithParaL( CStifItemParser& aItem );

    /*
    * TestTHTHIsNullL test method for testing the IsNull method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHIsNullL( CStifItemParser& aItem );

    /*
    * TestTHTHHasContentL test method for testing the HasContent method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHHasContentL( CStifItemParser& aItem );

    /*
    * TestTHTHReleaseL test method for testing the Release method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHReleaseL( CStifItemParser& aItem );

    /*
    * TestTHTHSetL test method for testing the Set method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSetL( CStifItemParser& aItem );

    /*
    * TestTHTHSetNameL test method for testing the SetName method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSetNameL( CStifItemParser& aItem );

    /*
    * TestTHTHSetSizeL test method for testing the SetSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSetSizeL( CStifItemParser& aItem );

    /*
    * TestTHTHSetTextureSizeL test method for testing the SetTextureSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSetTextureSizeL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentedTextureL test method for testing the SegmentedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentedTextureL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentedTextureconstL test method for testing the SetTextureSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentedTextureconstL( CStifItemParser& aItem );

    /*
    * TestTHTHShadowedTextureL test method for testing the ShadowedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHShadowedTextureL( CStifItemParser& aItem );

    /*
    * TestTHTHShadowedTextureconstL test method for testing the ShadowedTexture method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHShadowedTextureconstL( CStifItemParser& aItem );

    /*
    * TestTHTHTextureChangedL test method for testing the TextureChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHTextureChangedL( CStifItemParser& aItem );

    /*
    * TestTHTHTextureClearChangedL test method for testing the TextureClearChanged method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHTextureClearChangedL( CStifItemParser& aItem );

    /*
    * TestTHTHNameL test method for testing the Name method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHNameL( CStifItemParser& aItem );

    /*
    * TestTHTHSizeL test method for testing the Size method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSizeL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentCountL test method for testing the SegmentCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentCountL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentNameL test method for testing the SegmentName method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentNameL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentSizeL test method for testing the SegmentSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentSizeL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentTextureSizeL test method for testing the SegmentTextureSize method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentTextureSizeL( CStifItemParser& aItem );

    /*
    * TestTHTHSegmentOffsetL test method for testing the SegmentOffset method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHSegmentOffsetL( CStifItemParser& aItem );

    /*
    * TestTHTHTextureExtensionL test method for testing the TextureExtension method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHTHTextureExtensionL( CStifItemParser& aItem );

private:// huitransformation.h CHuiTransformation
    /*
    * TestCHTranNewL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranNewL( CStifItemParser& aItem );

    /*
    * TestCHTranNewLCL test method for testing the NewL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranNewLCL( CStifItemParser& aItem );

    /*
    * TestCHTranCountL test method for testing the Count method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranCountL( CStifItemParser& aItem );

    /*
    * TestCHTranNonIdentityCountL test method for testing the NonIdentityCount method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranNonIdentityCountL( CStifItemParser& aItem );

    /*
    * TestCHTranStepL test method for testing the Step method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranStepL( CStifItemParser& aItem );

    /*
    * TestCHTranoperatorL test method for testing the operator [] method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranoperatorL( CStifItemParser& aItem );

    /*
    * TestCHTranLoadIdentityL test method for testing the LoadIdentity method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranLoadIdentityL( CStifItemParser& aItem );

    /*
    * TestCHTranTranslateL test method for testing the Translate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranTranslateL( CStifItemParser& aItem );

    /*
    * TestCHTranTranslateWithValueL test method for testing the Translate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranTranslateWithValueL( CStifItemParser& aItem );

    /*
    * TestCHTranScaleL test method for testing the Scale method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranScaleL( CStifItemParser& aItem );

    /*
    * TestCHTranScaleL test method for testing the Scale method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranScaleWithValueL( CStifItemParser& aItem );

    /*
    * TestCHTranScaleL test method for testing the Scale method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranScaleWithThreeL( CStifItemParser& aItem );

    /*
    * TestCHTranScaleL test method for testing the Scale method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranScaleWithThreeValueL( CStifItemParser& aItem );

    /*
    * TestCHTranRotateL test method for testing the Rotate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranRotateL( CStifItemParser& aItem );

    /*
    * TestCHTranRotateValueL test method for testing the Rotate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranRotateValueL( CStifItemParser& aItem );

    /*
    * TestCHTranRotateFourL test method for testing the Rotate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranRotateFourL( CStifItemParser& aItem );

    /*
    * TestCHTranRotateValueThreeL test method for testing the Rotate method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestCHTranRotateValueThreeL( CStifItemParser& aItem );

private:// huifixmath.h HuiFixMath
    /*
    * TestHFMFixHypot test method for testing the FixHypot method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFixHypot( CStifItemParser& aItem );

    /*
    * TestHFMFixSin test method for testing the FixSin method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFixSin( CStifItemParser& aItem );

    /*
    * TestHFMFixCos test method for testing the FixCos method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFixCos( CStifItemParser& aItem );

    /*
    * TestHFMFixMul test method for testing the FixMul method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFixMul( CStifItemParser& aItem );

    /*
    * TestHFMFixDiv test method for testing the FixDiv method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFixDiv( CStifItemParser& aItem );

    /*
    * TestHFMFloatToFix test method for testing the FloatToFix method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFloatToFix( CStifItemParser& aItem );

    /*
    * TestHFMFixToFloat test method for testing the FixToFloat method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHFMFixToFloat( CStifItemParser& aItem );

private:// huifont.h THuiFont
    /*
    * TestTHFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFConstructorL( CStifItemParser& aItem );

    /*
    * TestTHFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFConstructorWithParaL( CStifItemParser& aItem );

    /*
    * TestTHFConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFConstructorWithFontL( CStifItemParser& aItem );

    /*
    * TestTHFoperatorEqualL test method for testing the operator = method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFoperatorEqual( CStifItemParser& aItem );

    /*
    * TestTHFIdL test method for testing the Id method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFIdL( CStifItemParser& aItem );

    /*
    * TestTHFCategoryL test method for testing the Category method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFCategoryL( CStifItemParser& aItem );

    /*
    * TestTHFFontSpecL test method for testing the FontSpec method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFFontSpecL( CStifItemParser& aItem );

private:// huifontmanager.h THuiFontManager
    /*
    * TestTHFMEnumerateFontsL test method for testing the EnumerateFontsL method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHFMEnumerateFontsL( CStifItemParser& aItem );

private:// huiinteractioninterval.h THuiInteractionInterval
    /*
    * TestTHIIConstructorL test method for testing the Constructor method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIIConstructorL( CStifItemParser& aItem );

    /*
    * TestTHIISetScalarL test method for testing the SetScalar method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIISetScalarL( CStifItemParser& aItem );

    /*
    * TestTHIIScalarL test method for testing the Scalar method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIIScalarL( CStifItemParser& aItem );

    /*
    * TestTHIIIntervalL test method for testing the Interval method
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestTHIIIntervalL( CStifItemParser& aItem );

private: // for test the huitextvisual.h
    
    /**
    * TestHuiTextVisualAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualAddNewL( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetTextL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetTextL( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualText test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualText( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetAlign test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetAlign( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetLineSpacing test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetLineSpacing( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetStyle test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetStyle( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetTextStyle test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetTextStyle( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualStyle test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualStyle( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualTextStyle test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualTextStyle( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetMaxLineCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetMaxLineCount( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualMaxLineCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualMaxLineCount( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualWrapping test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualWrapping( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetWrapping test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetWrapping( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualBackgroundType test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualBackgroundType( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualOffset test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualOffset( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualOffsetConst test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualOffsetConst( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualTextExtents test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualTextExtentsL( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualPrepareDrawL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualPrepareDrawL( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetColor test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetColor( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetColorWithIndex test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetColorWithIndex( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSubstringExtents test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSubstringExtents( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualEnableShadow test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualEnableShadow( CStifItemParser& aItem );
    
    /**
    * TestHuiTextVisualSetHighlightRange test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTextVisualSetHighlightRange( CStifItemParser& aItem );
    
private: //for test the huiviewportlayout.h
    
    
    /**
    * TestHuiViewPortLayoutAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiViewPortLayoutAddNewL( CStifItemParser& aItem );
    
    /**
    * TestHuiViewPortLayoutSetVirtualSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiViewPortLayoutSetVirtualSize( CStifItemParser& aItem );
    
    /**
    * TestHuiViewPortLayoutSetViewportSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiViewPortLayoutSetViewportSize( CStifItemParser& aItem );
    
    /**
    * TestHuiViewPortLayoutSetViewportPos test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiViewPortLayoutSetViewportPos( CStifItemParser& aItem );
    
private: // for test the huiimagevisual.h
    
    /**
    * TestHuiImageVisualAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualAddNewL( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetScaleMode test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetScaleMode( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetImage test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetImageL( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetSecondaryImage test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetSecondaryImageL( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualImage test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualImage( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSecondaryImage test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSecondaryImage( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetColor test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetColor( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetColorMode test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetColorMode( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetStretch test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetStretch( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetStretchMode test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetStretchMode( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetDropShadow test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetDropShadow( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetDropShadowWithHuiMetrix test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetDropShadowWithHuiMetric( CStifItemParser& aItem );
    
    /**
    * TestHuiImageVisualSetDropShadowWithHuiXYMetric test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageVisualSetDropShadowWithHuiXYMetric( CStifItemParser& aItem );
    
private:// for testing huigridlayout.h
    
    
    /**
    * TestHuiGridLayoutAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutAddNewL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutConstructor test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutConstructor( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutConstructL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutConstructL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutDelete test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutDelete( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetSize( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutChildOrdinal test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutChildOrdinalL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutChildPos test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutChildPos( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutChildSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutChildSize( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutChildRect test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutChildRect( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutBaseUnit test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutBaseUnit( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutRemoveAndDestroyAllD test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutRemoveAndDestroyAllD( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutFindTag test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutFindTagL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutCount( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutVisual test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutVisualL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetPos test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetPos( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutUpdateChildrenLayout test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutUpdateChildrenLayout( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutPrepareDrawL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutPrepareDrawL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutDraw test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutDrawL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutDrawSelf test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutDrawSelfL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutChanged( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutReportChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutReportChanged( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutClearChanged test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutClearChanged( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutNotifySkinChangedL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutNotifySkinChangedL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutExpandRectWithContent test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutExpandRectWithContent( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutVisualExtension test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutVisualExtension( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetColumnsL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetColumnsL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetRowsL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetRowsL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetColumnsLWithArray test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetColumnsLWithArray( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetRowsLWithArray test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetRowsLWithArray( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutFillWeightsL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutFillWeightsL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutAppendWeightL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutAppendWeightL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutInsertWeightL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutInsertWeightL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutReplaceWeightL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutReplaceWeightL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutRemoveWeightL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutRemoveWeightL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutWeight test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutWeight( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutDimensionCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutDimensionCount( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetExpanding test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetExpanding( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutRowCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutRowCount( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutColumnCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutColumnCount( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutOrdinalToBlock test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutOrdinalToBlock( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetLayoutModeFlags test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetLayoutModeFlags( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutClearLayoutModeFlags test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutClearLayoutModeFlags( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutLayoutModeFlags test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutLayoutModeFlags( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutGetClassName test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutGetClassName( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutDumpTree test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutDumpTree( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutGetInstanceName test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutGetInstanceNameL( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutType test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutType( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSessionId test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSessionId( CStifItemParser& aItem );
    
    /**
    * TestHuiGridLayoutSetSessionId test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiGridLayoutSetSessionId( CStifItemParser& aItem );
    
private: // for test the HuiTextureManager.h
    
    /**
    * TestHuiTxureManagerEnv test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerEnvL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerTexture test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerTextureL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerTextureConst test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerTextureConstL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerTextureL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerTextureLL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerSetImagePathL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerSetImagePathL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerImagePath test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerImagePath( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerBlankTextureConstL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerBlankTextureConstL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerBlankTexture test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerBlankTextureL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerLoadTextureL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerLoadTextureL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerLoadTextureLWithSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerLoadTextureLWithIdL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerLoadTextureLWithSizeImage test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerLoadTextureLWithSizeImageL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerCreateTextureL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerCreateTextureL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerUpdateTextureFromBitmapL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerUpdateTextureFromBitmapL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerUnloadTexture test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerUnloadTexture( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerUnloadTextureWithID test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerUnloadTextureWithID( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerDefineFileNameL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerDefineFileNameL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerLoadQueueCount test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerLoadQueueCount( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerState test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerState( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerProcessor test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerProcessorL( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerPrependImagePath test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerPrependImagePath( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerSetTextureId test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerSetTextureId( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerIsLoaded test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerIsLoaded( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerIsLoadedWithID test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerIsLoadedWithID( CStifItemParser& aItem );
    
    /**
    * TestHuiTxureManagerIsLoadedWithTexture test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTxureManagerIsLoadedWithTexture( CStifItemParser& aItem );
    
private: // for testing huiflowlayout.h api
    
    /**
    * TestHuiFlowLayoutAddNewL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutAddNewL( CStifItemParser& aItem );
    
    /**
    * TestHuiFlowLayoutDelete test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutDelete( CStifItemParser& aItem );
    
    /**
    * TestHuiFlowLayoutSetSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutSetSize( CStifItemParser& aItem );
    
    /**
    * TestHuiFlowLayoutSetFlowDirection test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutSetFlowDirection( CStifItemParser& aItem );
    
    /**
    * TestHuiFlowLayoutSetCentering test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutSetCentering( CStifItemParser& aItem );
    
    /**
    * TestHuiFlowLayoutSetMode test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutSetMode( CStifItemParser& aItem );
    
    /**
    * TestHuiFlowLayoutMode test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiFlowLayoutMode( CStifItemParser& aItem );
    
private: // for testing the huiimageloaderutil.h
    
    /**
    * TestHuiImageLoaderUtilConstructor test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilConstructorL( CStifItemParser& aItem );
    
    /**
    * TestHuiImageLoaderUtilDelete test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilDelete( CStifItemParser& aItem );
    
    /**
    * TestHuiImageLoaderUtilCreateImageLoaderL test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilCreateImageLoaderL( CStifItemParser& aItem );
    
    /**
    * TestHuiImageLoaderUtilCreateImageLoaderLWithAppUid test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilCreateImageLoaderLWithAppUidL( CStifItemParser& aItem );
    
    /**
    * TestHuiImageLoaderUtilSetSize test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilSetSize( CStifItemParser& aItem );
    
    /**
    * TestHuiImageLoaderUtilSetSkinInstance test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilSetSkinInstance( CStifItemParser& aItem );
    
    /**
    * TestHuiImageLoaderUtilImageLoaderExtension test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiImageLoaderUtilImageLoaderExtension( CStifItemParser& aItem );
    
private:  // for testing the huitextureautosizeparams.h
    
    /**
    * TestHuiTexureAutoSizeParaConstructor test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaConstructor( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaSizeLowerThreshold test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaSizeLowerThreshold( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaSetSizeLowerThreshold test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaSetSizeLowerThreshold( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaSizeUpperThreshold test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaSizeUpperThreshold( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaSetSizeUpperThreshold test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaSetSizeUpperThreshold( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaMinSizeChange test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaMinSizeChange( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaSetMinSizeChange test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaSetMinSizeChange( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaDownsizeSettleThreshold test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaDownsizeSettleThreshold( CStifItemParser& aItem );
    
    /**
    * TestHuiTexureAutoSizeParaSetDownsizeSettleThreshold test method.
    * @since S60 5.0
    * @param aItem Script line containing parameters.
    * @return Symbian OS error code.
    */
    virtual TInt TestHuiTexureAutoSizeParaSetDownsizeSettleThreshold( CStifItemParser& aItem );


private:    // Data

    /**
     * ScreenSaver Property
     */
    TInt iOldScreenSaverProperty;
    /*
     * The environment
    */

    CHuiEnv* iHuiEnv;

    /*
     * The Display
    */

    CHuiDisplay* iHuiDisplay;

    /*
     * The iHuiControl of visual
    */

    CHuiControl* iHuiControl;


    /*
    * The iHuiControl group
    */

    CHuiControlGroup* iHuiControlGroup;
    
    
    /**
     * The instance of CHuiVisual class
     * own.
     */
    CHuiVisual* iHuiVisual;
    
    /*
     * The instance of CHuiLayout
     */
    CHuiLayout* iHuiLayout;
    
    /*
     * New control of visual 
     */
    CHuiControl* iHuiNewControl;
    
    /*
     * The extended visual class instance
     */
    CTestPlatALFCoreToolkitVisualExt* iHuiVisualExt;
    
    /*
     * The display rectangle
     */
    
    TRect iDisplayRect;
    
    /*
     * The instance for test the huitextvisual api
     */
    CHuiTextVisual* iHuiTextVisual;
    
    /*
     * The instance for test the huiviewportlayout api
     */
    CHuiViewportLayout* iHuiViewPortLayout;
    
    /*
     * The instance for test the huiimagevisual.h api
     */
    CHuiImageVisual* iHuiImageVisual;
    
    /*
     * The instance for test the huigridlayout.h api
     */
    CHuiGridLayout* iHuiGridLayout;
    
    /*
     * The texture uid
     */
    TInt iTextureUid;
    
    /*
     * The instance for testing the huiflowlayout.h api
     */
    CHuiFlowLayout* iHuiFlowLayout;
    
    /*
     * The instance for testing the huiimageloaderutil.h api
     */
    CHuiImageLoaderUtil* iHuiImageLoaderUtil;

    /*
     * The control for getting display
     */
    CHuiDisplayCoeControl* iHuiCtrl;

    };

#endif      // C_TESTUIAIFCORETOOLKIT_H

// End of File
