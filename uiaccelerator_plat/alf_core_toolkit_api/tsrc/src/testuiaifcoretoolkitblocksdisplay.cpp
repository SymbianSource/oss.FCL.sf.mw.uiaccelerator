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


// [INCLUDE FILES]
#include <e32svr.h>
#include <gdi.h>
#include <stifparser.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huistatic.h>
#include <uiacceltk/huidisplay.h>
#include <uiacceltk/huidisplaycoecontrol.h>
#include <uiacceltk/huigc.h>

#include "testuiaifcoretoolkit.h"

// Test class

NONSHARABLE_CLASS(CTestScreenBufferObserver) : public CBase, public MHuiScreenBufferObserver
    {
public:

    TBool ScreenBufferComplete(TUid aBufferUid, TRect& aDisplayRect, TRect& aDirtyRect)
        {
        iScreenBufferComplete_Count++;
        iScreenBufferComplete_LastBufferUid = aBufferUid;
        iScreenBufferComplete_LastDisplayRect = aDisplayRect;
        iScreenBufferComplete_LastDirtyRect = aDirtyRect;
        
        return iScreenBufferComplete_ReturnValue;
        };
        
    void HandleScreenBufferEvent(TUid aBufferUid, TInt aEvent)
        {
        iHandleScreenBufferEvent_LastBufferUid = aBufferUid; 
        if ( aEvent == MHuiScreenBufferObserver::EDeleted )
            iHandleScreenBufferEvent_DeleteEventCount++;
        else 
            /*EUNIT_ASSERT_DESC( EFalse, "HandleScreenBufferEvent(). Error: Invalid event.")*/
            ;
    
        };
public:
    TInt iScreenBufferComplete_Count;
    TUid iScreenBufferComplete_LastBufferUid;
    TRect iScreenBufferComplete_LastDisplayRect;
    TRect iScreenBufferComplete_LastDirtyRect;
 
    TBool iScreenBufferComplete_ReturnValue;
   
    TInt iHandleScreenBufferEvent_DeleteEventCount; 
    TUid iHandleScreenBufferEvent_LastBufferUid;
    
    };

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHuiEnvL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHuiEnvL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHuiEnvL, "In TestTHuiEnvL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHuiEnvL );
    // Print to log file 
    iLog->Log( KTestTHuiEnvL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Env();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayActivateL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayActivateL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayActivateL, "In TestTDisplayActivateL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTDisplayActivateL );
    // Print to log file 
    iLog->Log( KTestTDisplayActivateL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Activate( ETrue );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayActiveL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayActiveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayActiveL, "In TestTDisplayActive" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTDisplayActiveL );
    // Print to log file 
    iLog->Log( KTestTDisplayActiveL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Active();
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetSizeLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetSizeLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetSizeLL, "In TestTDisplaySetSizeLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTDisplaySetSizeLL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetSizeLL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    TSize newSize = TSize(42,43);
    huiDisplay->SetSizeL( newSize );
    
    STIF_ASSERT_EQUALS( huiDisplay->Size(), newSize );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySizeL, "In TestTDisplaySizeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTDisplaySizeL );
    // Print to log file 
    iLog->Log( KTestTDisplaySizeL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Size();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetVisibleAreaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetVisibleAreaL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetVisibleAreaL, "In TestTDisplaySetVisibleAreaL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTDisplaySetVisibleAreaL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetVisibleAreaL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    TRect newRect(1,2,30,40);
    huiDisplay->SetVisibleArea( newRect );
    
    STIF_ASSERT_EQUALS( huiDisplay->VisibleArea(), newRect );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayVisibleAreaL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayVisibleAreaL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayVisibleAreaL, "In TestTDisplayVisibleAreaL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTDisplayVisibleAreaL );
    // Print to log file 
    iLog->Log( KTestTDisplayVisibleAreaL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    TRect visibleArea = huiDisplay->VisibleArea();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetOrientationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetOrientationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetOrientationL, "In TestTDisplaySetOrientationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetOrientationL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetOrientationL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetOrientation( CHuiGc::EOrientationCCW90 );
    STIF_ASSERT_EQUALS( huiDisplay->Orientation( ), CHuiGc::EOrientationCCW90 );
    huiDisplay->SetOrientation( CHuiGc::EOrientationNormal );
    STIF_ASSERT_EQUALS( huiDisplay->Orientation( ), CHuiGc::EOrientationNormal );
    huiDisplay->SetOrientation( CHuiGc::EOrientationCW90 );
    STIF_ASSERT_EQUALS( huiDisplay->Orientation( ), CHuiGc::EOrientationCW90 );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayOrientationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayOrientationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayOrientationL, "In TestTDisplayOrientationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayOrientationL );
    // Print to log file 
    iLog->Log( KTestTDisplayOrientationL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Orientation();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetUseDepthL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetUseDepthL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetUseDepthL, "In TestTDisplaySetUseDepthL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetUseDepthL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetUseDepthL);
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->SetUseDepth( ETrue );
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetClearBackgroundLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetClearBackgroundLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetClearBackgroundLL, "In TestTDisplaySetClearBackgroundLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetClearBackgroundLL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetClearBackgroundLL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetClearBackgroundL( CHuiDisplay::EClearNone );
    huiDisplay->SetClearBackgroundL( CHuiDisplay::EClearWithColor );
    huiDisplay->SetClearBackgroundL( CHuiDisplay::EClearWithSkinBackground );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetBackgroundColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetBackgroundColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetBackgroundColor, "In TestTDisplaySetBackgroundColor" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetBackgroundColor );
    // Print to log file 
    iLog->Log( KTestTDisplaySetBackgroundColor );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetBackgroundColor( KRgbBlue );
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetBackgroundItemsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetBackgroundItemsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetBackgroundItemsL, "In TestTDisplaySetBackgroundItemsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetBackgroundItemsL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetBackgroundItemsL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);


    RArray<THuiDisplayBackgroundItem> backgroundItems;
    
    TRect rect = TRect(1,2,30,40);
    TRect rect2 = TRect(2,3,40,50);

    // Skin backgrounds           

    TAknsItemID item = KAknsIIDQsnBgScreenIdle; 
    TAknsItemID item2 = KAknsIIDQsnBgScreenMp; 

    THuiDisplayBackgroundItem newItem1(rect, item);
    newItem1.SetRect(rect2);

    newItem1.SetSkinBackground(item2);
    backgroundItems.AppendL(newItem1);
                
    // Skin colors

    TAknsItemID skinnedColorGroup1 = KAknsIIDQsnTextColors; 
    TInt skinnedColorIndex1 = 1;
     
    THuiDisplayBackgroundItem newItem2(
        rect, skinnedColorGroup1, skinnedColorIndex1);
    newItem2.SetRect(rect2);

    newItem2.SetColor(skinnedColorGroup1, skinnedColorIndex1);
    backgroundItems.AppendL(newItem2);

    // Colors
    THuiDisplayBackgroundItem newItem3(rect, KRgbBlack);
    newItem3.SetRect(rect2);
    newItem3.SetColor(KRgbBlue);
    backgroundItems.AppendL(newItem3);

    // Empty
                
    THuiDisplayBackgroundItem newItem4(rect);
    newItem4.SetRect(rect2);
    backgroundItems.AppendL(newItem4);

    // Finally set to display
    huiDisplay->SetBackgroundItemsL(backgroundItems);
    backgroundItems.Close();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayCaptureLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayCaptureLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayCaptureLCL, "In TestTDisplayCaptureLCL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayCaptureLCL );
    // Print to log file  
    iLog->Log( KTestTDisplayCaptureLCL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    TSize captureSize = TSize(42,55);
    TUint8* ptr = NULL;
    ptr = huiDisplay->CaptureLC( captureSize );
    STIF_ASSERT_NOT_NULL( ptr );
    CleanupStack::PopAndDestroy( ptr );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayTransformationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayTransformationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayTransformationL, "In TestTDisplayTransformationL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayTransformationL);
    // Print to log file 
    iLog->Log( KTestTDisplayTransformationL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Transformation();

    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayRosterL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayRosterL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayRosterL, "In TestTDisplayRosterL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayRosterL);
    // Print to log file 
    iLog->Log( KTestTDisplayRosterL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    huiDisplay->Roster();

    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayConstRosterL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayConstRosterL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayConstRosterL, "In TestTDisplayConstRosterL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayConstRosterL);
    // Print to log file 
    iLog->Log( KTestTDisplayConstRosterL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    ( (const CHuiDisplay* )huiDisplay )->Roster();

    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayShowL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayShowL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayShowL, "In TestTDisplayConstRosterL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayShowL);
    // Print to log file 
    iLog->Log( KTestTDisplayShowL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->Show( ETrue );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetDirtyL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetDirtyL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetDirtyL, "In TestTDisplaySetDirtyL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetDirtyL);
    // Print to log file 
    iLog->Log( KTestTDisplaySetDirtyL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetDirty();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetQualityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetQualityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetQualityL, "In TestTDisplaySetQualityL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetQualityL);
    // Print to log file 
    iLog->Log( KTestTDisplaySetQualityL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetQuality( EHuiQualityAccurate );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayQualityL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayQualityL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayQualityL, "In TestTDisplayQualityL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayQualityL);
    // Print to log file 
    iLog->Log( KTestTDisplayQualityL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->Quality();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetUsageLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetUsageLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetUsageLL, "In KTestTDisplaySetUsageLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetUsageLL);
    // Print to log file 
    iLog->Log( KTestTDisplaySetUsageLL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetUsageL( EHuiDisplayUsageGeneric );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayReleaseL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayReleaseL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayReleaseL, "In TestTDisplayReleaseL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayReleaseL);
    // Print to log file 
    iLog->Log( KTestTDisplayReleaseL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->Release();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayRestoreLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayRestoreLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayRestoreLL, "In TestTDisplayRestoreLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayRestoreLL);
    // Print to log file 
    iLog->Log( KTestTDisplayRestoreLL );
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->RestoreL();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetScreenBufferLockL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetScreenBufferLockL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetScreenBufferLockL, 
            "In TestTDisplaySetScreenBufferLockL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetScreenBufferLockL);
    // Print to log file 
    iLog->Log( KTestTDisplaySetScreenBufferLockL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetScreenBufferLock(ETrue);    
    huiDisplay->SetScreenBufferLock(EFalse);
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayIsScreenBufferLockedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayIsScreenBufferLockedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayIsScreenBufferLockedL, 
            "In TestTDisplaySetScreenBufferLockL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayIsScreenBufferLockedL );
    // Print to log file 
    iLog->Log( KTestTDisplayIsScreenBufferLockedL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetScreenBufferLock(ETrue);
    TBool result = huiDisplay->IsScreenBufferLocked();
    STIF_ASSERT_TRUE( result );
    
    huiDisplay->SetScreenBufferLock(EFalse);
    result = huiDisplay->IsScreenBufferLocked();
    STIF_ASSERT_TRUE( !result );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayGetDrawingInterfaceL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayGetDrawingInterfaceL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayGetDrawingInterfaceL, 
            "In TestTDisplayGetDrawingInterfaceL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayGetDrawingInterfaceL );
    // Print to log file 
    iLog->Log( KTestTDisplayGetDrawingInterfaceL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    TUid dummyUid = {0x1234};
    MHuiBufferDrawer* result = huiDisplay->GetDrawingInterface( dummyUid );
    STIF_ASSERT_EQUALS( result, (MHuiBufferDrawer*)NULL );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayGetGraphicsContextL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayGetGraphicsContextL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayGetDrawingInterfaceL, 
            "In TestTDisplayGetDrawingInterfaceL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayGetDrawingInterfaceL );
    // Print to log file 
    iLog->Log( KTestTDisplayGetDrawingInterfaceL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    TUid dummyUid = {0x1234};
    MHuiGc* result = huiDisplay->GetGraphicsContext( dummyUid );
    STIF_ASSERT_EQUALS( result, (MHuiGc*)NULL );
    
    TUid KHuiInternalFbsBitmapBufferGcUid = {0x2000e5a3};
    result = huiDisplay->GetGraphicsContext( KHuiInternalFbsBitmapBufferGcUid );
    result->ReleaseGc();
    STIF_ASSERT_NOT_EQUALS( result , (MHuiGc*)NULL );
    
    // *** Get internal bitmap handle

    MHuiFbsBitmapBufferGc* gc = 
        (MHuiFbsBitmapBufferGc*)huiDisplay->GetGraphicsContext( 
            KHuiInternalFbsBitmapBufferGcUid );
    STIF_ASSERT_NOT_EQUALS( gc , (MHuiFbsBitmapBufferGc*)NULL );
    CFbsBitmap* bitmap = gc->Bitmap();
    STIF_ASSERT_NOT_EQUALS( bitmap , (CFbsBitmap*)NULL );
    STIF_ASSERT_NOT_EQUALS( bitmap->Handle() , 0 );
    result->ReleaseGc();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayAddScreenBufferObserverLL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayAddScreenBufferObserverLL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayAddScreenBufferObserverLL, 
            "In TestTDisplayAddScreenBufferObserverLL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayAddScreenBufferObserverLL );
    // Print to log file 
    iLog->Log( KTestTDisplayAddScreenBufferObserverLL );
    
    TUid bufferUid = {KTestScreenBufferUidValue};
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayOffScreenBuffer, bufferUid);
    
    huiDisplay->AddScreenBufferObserverL( NULL );
    
    // Currently address is not checked in this method   
    huiDisplay->AddScreenBufferObserverL( (MHuiScreenBufferObserver*)1234 );  
    huiDisplay->RemoveScreenBufferObserver();
    
    // *** Delete display: Generate one EDeleted event
    
    CTestScreenBufferObserver* obs = new(ELeave) CTestScreenBufferObserver();
    CleanupStack::PushL(obs);
    huiDisplay->AddScreenBufferObserverL( obs );
   
    delete huiDisplay; 
    huiDisplay = NULL; 
    
    STIF_ASSERT_EQUALS( obs->iScreenBufferComplete_Count, 0 );
    STIF_ASSERT_TRUE( obs->iScreenBufferComplete_LastBufferUid.iUid == 0 );
    STIF_ASSERT_EQUALS( obs->iScreenBufferComplete_LastDisplayRect, TRect() );
    STIF_ASSERT_EQUALS( obs->iScreenBufferComplete_LastDirtyRect.Size(), TSize() );
    STIF_ASSERT_EQUALS( obs->iHandleScreenBufferEvent_DeleteEventCount, 1 );
    STIF_ASSERT_TRUE( obs->iHandleScreenBufferEvent_LastBufferUid.iUid ==
         KTestScreenBufferUidValue );

    CleanupStack::PopAndDestroy(obs);        

    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayRemoveScreenBufferObserverL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayRemoveScreenBufferObserverL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayRemoveScreenBufferObserverL, 
            "In TestTDisplayRemoveScreenBufferObserverL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayRemoveScreenBufferObserverL );
    // Print to log file 
    iLog->Log( KTestTDisplayRemoveScreenBufferObserverL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    CTestScreenBufferObserver* obs = new(ELeave) CTestScreenBufferObserver();
    CleanupStack::PushL(obs);
    huiDisplay->AddScreenBufferObserverL( obs );
    huiDisplay->RemoveScreenBufferObserver();
    CleanupStack::PopAndDestroy(obs);
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayScreenBufferObserverL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayScreenBufferObserverL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayScreenBufferObserverL, 
            "In TestTDisplayScreenBufferObserverL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayScreenBufferObserverL );
    // Print to log file 
    iLog->Log( KTestTDisplayScreenBufferObserverL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->ScreenBufferObserver();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayScreenBufferUidL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayScreenBufferUidL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayScreenBufferUidL, 
            "In TestTDisplayScreenBufferUidL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayScreenBufferUidL );
    // Print to log file 
    iLog->Log( KTestTDisplayScreenBufferUidL );
    
    TUid bufferUid = {KTestScreenBufferUidValue};
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL,
        CHuiDisplay::EDisplayOffScreenBuffer, bufferUid);
    
    TUid result = huiDisplay->ScreenBufferUid( );
    STIF_ASSERT_TRUE( result.iUid == KTestScreenBufferUidValue ); 
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayDisplayTypeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayDisplayTypeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayDisplayTypeL, 
            "In TestTDisplayDisplayTypeL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayDisplayTypeL );
    // Print to log file 
    iLog->Log( KTestTDisplayDisplayTypeL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayOffScreenBuffer);
    
    TInt result = huiDisplay->DisplayType();
    STIF_ASSERT_TRUE( result == CHuiDisplay::EDisplayOffScreenBuffer ); 
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayShowDirtyRegionsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayShowDirtyRegionsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayShowDirtyRegionsL, 
            "In TestTDisplayShowDirtyRegionsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayShowDirtyRegionsL );
    // Print to log file 
    iLog->Log( KTestTDisplayShowDirtyRegionsL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->ShowDirtyRegions();
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplayGetPreferredTextureFormatsL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplayGetPreferredTextureFormatsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplayGetPreferredTextureFormatsL, 
            "In TestTDisplayGetPreferredTextureFormatsL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplayGetPreferredTextureFormatsL );
    // Print to log file 
    iLog->Log( KTestTDisplayGetPreferredTextureFormatsL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    RPointerArray<CHuiDisplay::CTextureBitmapFormat> textureFormats;
    huiDisplay->GetPreferredTextureFormats( textureFormats );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetDrawVisualOutlineL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetDrawVisualOutlineL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetDrawVisualOutlineL, 
            "In TestTDisplaySetDrawVisualOutlineL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetDrawVisualOutlineL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetDrawVisualOutlineL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    TUint  temp = 0;
    huiDisplay->SetDrawVisualOutline( temp );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTDisplaySetVisibleAreaClippingRectL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTDisplaySetVisibleAreaClippingRectL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTDisplaySetVisibleAreaClippingRectL, 
            "In TestTDisplaySetVisibleAreaClippingRectL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit,
            KTestTDisplaySetVisibleAreaClippingRectL );
    // Print to log file 
    iLog->Log( KTestTDisplaySetVisibleAreaClippingRectL );
    
    CHuiDisplay* huiDisplay = &iHuiEnv->NewDisplayL(iDisplayRect, NULL, 0, NULL, 
        CHuiDisplay::EDisplayNormal);
    
    huiDisplay->SetVisibleAreaClippingRect( iDisplayRect );
    
    return KErrNone;
    
    }

//  [End of File]
