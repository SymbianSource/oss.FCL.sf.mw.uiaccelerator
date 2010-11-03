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
#include <stifparser.h>
#include <fbs.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huiutil.h>

#include "testuiaifcoretoolkit.h"

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilPower2
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilPower2( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilPower2" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    STIF_ASSERT_EQUALS(HuiUtil::Power2(128), 128);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(256), 256);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(1), 1);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(2), 2);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(3), 4);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(127), 128);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(129), 256);
    STIF_ASSERT_EQUALS(HuiUtil::Power2(255), 256);

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilPower2RoundDown
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilPower2RoundDown( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilPower2RoundDown" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(128), 128);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(256), 256);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(1), 1);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(2), 2);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(3), 2);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(127), 64);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(129), 128);
    STIF_ASSERT_EQUALS(HuiUtil::Power2RoundDown(255), 128);

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilInterpolate
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilInterpolate( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilInterpolate" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::Interpolate( 1.1, 0, 10 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilWrapValue
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilWrapValue( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilWrapValue" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TReal32 value = 10;
    HuiUtil::WrapValue( value, 0, 10 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilRandomInt
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilRandomInt( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilRandomInt" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::RandomInt( 0, 10 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilRandomReal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilRandomReal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilRandomReal" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::RandomReal( 0.1, 10.5 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilQuickLengthWithPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilQuickLengthWithPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilQuickLengthWithPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    THuiRealPoint vector( 1, 1 );
    HuiUtil::QuickLength( vector );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilQuickLength
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilQuickLength( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilQuickLength" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::QuickLength( 1, 1 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilQuickNormalizeWithPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilQuickNormalizeWithPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilQuickNormalizeWithPoint" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    THuiRealPoint vector( 1, 1 );
    HuiUtil::QuickNormalize( vector );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilQuickNormalize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilQuickNormalize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilQuickNormalize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TReal32 vector[3] = { 1, 1, 1 };
    HuiUtil::QuickNormalize( vector );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilCrossProduct
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilCrossProduct( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilCrossProduct" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TReal32 vectorA[3] = { 1, 1, 1 };
    TReal32 vectorB[3] = { 10, 10, 10 };
    TReal32 product[3] = { 0.1, 0.1, 0.1 };
    HuiUtil::CrossProduct( vectorA, vectorB, product );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilNormalFromPoints
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilNormalFromPoints( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilNormalFromPoints" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TReal32 point[3][3] = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
    TReal32 normal[3] = { 0.1, 0.1, 0.1 };
    HuiUtil::NormalFromPoints( point, normal );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilShadowMatrix
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilShadowMatrix( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilShadowMatrix" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TReal32 planePoint[3] = { 1, 1, 1 };
    TReal32 planeNormal[3] = { 0.1, 0.1, 0.1 };
    TReal32 lightPos[4] = { 1, 1, 1, 1 };
    TReal32 destMat[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; 
    HuiUtil::ShadowMatrix( planePoint, planeNormal, lightPos, destMat );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilFreeMemory
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilFreeMemory( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilFreeMemory" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::FreeMemory();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilScreenSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilScreenSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilScreenSize" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::ScreenSize();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilLengthUnit
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilLengthUnit( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilLengthUnit" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::LengthUnit();

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilColorLightness
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilColorLightness( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilColorLightness" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    HuiUtil::ColorLightness( KRgbBlack );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilScaleFbsBitmapL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilScaleFbsBitmapL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilScaleFbsBitmapL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    CFbsBitmap *srcBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( srcBmp );
    TSize size( 256, 256 );
    User::LeaveIfError( srcBmp->Create( size, EColor16M ) );
    CFbsBitmap *scaledBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( scaledBmp );
    User::LeaveIfError( scaledBmp->Create( size, EColor16MA ) );
    HuiUtil::ScaleFbsBitmapL( *srcBmp, *scaledBmp );
    CleanupStack::PopAndDestroy( scaledBmp );
    CleanupStack::PopAndDestroy( srcBmp );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilCombineMaskFbsBitmapL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilCombineMaskFbsBitmapL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilCombineMaskFbsBitmapL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    CFbsBitmap *srcBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( srcBmp );
    TSize size( 10, 10 );
    User::LeaveIfError( srcBmp->Create( size, EColor16M ) );
    CFbsBitmap *srcMaskBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( srcMaskBmp );
    User::LeaveIfError( srcMaskBmp->Create( size, EGray2 ) );
    CFbsBitmap *combinedBmp = new ( ELeave ) CFbsBitmap;
    CleanupStack::PushL( combinedBmp );
    User::LeaveIfError( combinedBmp->Create( size, EColor16MA ) );

    HuiUtil::CombineMaskFbsBitmapL( *srcBmp, *srcMaskBmp, *combinedBmp );
    CleanupStack::PopAndDestroy( combinedBmp );
    CleanupStack::PopAndDestroy( srcMaskBmp );
    CleanupStack::PopAndDestroy( srcBmp );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilCropFbsBitmapL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilCropFbsBitmapL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilCropFbsBitmapL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    CFbsBitmap *srcBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( srcBmp );
    TSize size( 10, 10 );
    User::LeaveIfError( srcBmp->Create( size, EColor16M ) );
    CFbsBitmap *cropedBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( cropedBmp );
    User::LeaveIfError( cropedBmp->Create( size, EGray2 ) );
    TPoint cropPos;
    HuiUtil::CropFbsBitmapL( *srcBmp, *cropedBmp, cropPos );
    CleanupStack::PopAndDestroy( cropedBmp );
    CleanupStack::PopAndDestroy( srcBmp );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilScaleImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilScaleImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilScaleImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TUint8* sourceimage = 0;
    THuiTextureFormat aFormat = EHuiTextureFormatRgba8888;
    TInt imageSize = 4 * 320 * 300;
    sourceimage = new (ELeave) TUint8[imageSize];
    CleanupStack::PushL(sourceimage);
    // fill with
    for (TInt t=0; t<imageSize;) {
        sourceimage[t++] = 16; // red
        sourceimage[t++] = 24; // green
        sourceimage[t++] = 32; // blue
        sourceimage[t++] = 255; // alpha
    }
    STIF_ASSERT_TRUE( sourceimage != NULL );
    STIF_ASSERT_TRUE( sourceimage[0] == 16 );
    STIF_ASSERT_TRUE( sourceimage[imageSize-1] == 255 );

    // try to allocate dummy image buffer for 320x300 image
    TUint8* targetimage = 0;
    targetimage = new (ELeave) TUint8[4*16*16];
    CleanupStack::PushL(targetimage);
    // fill with zero pixels
    for (TInt t=0; t<4*16*16; t++) targetimage[t] = 0;

    HuiUtil::ScaleImage((aFormat == EHuiTextureFormatRgb888 ? 3 : 4),
                         TSize(320,200),
                         sourceimage,
                         TSize(16,16),
                         targetimage);

    // assert that we got correct pixel data to the bottom-right cornder
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 0] == 16 );
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 1] == 24 );
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 2] == 32 );
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 3] == 255 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilCropImageL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilCropImageL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilCropImageL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    TUint8 value;
    // try to allocate dummy image buffer for 320x300 image
    TUint8* sourceimage = 0;
    TInt imageSize = 4 * 160 * 100;
    sourceimage = new (ELeave) TUint8[imageSize];
    STIF_ASSERT_TRUE( sourceimage != NULL );
    CleanupStack::PushL(sourceimage);
    // fill with
    TInt t;
    for (t=0; t<imageSize;) {
        // fill the target crop area a bit differently
        if ((t>=16*160*4) && (t<=32*160*4))
            {
            sourceimage[t++] = 16; // red
            sourceimage[t++] = 24; // green
            sourceimage[t++] = 32; // blue
            sourceimage[t++] = 255; // alpha
            }
        else
            {
            sourceimage[t++] = 1; // red
            sourceimage[t++] = 1; // green
            sourceimage[t++] = 1; // blue
            sourceimage[t++] = 1; // alpha
            }
    }
    STIF_ASSERT_TRUE( sourceimage != NULL );
    STIF_ASSERT_TRUE( sourceimage[0] == 1 );

    // try to allocate dummy image buffer for 320x300 image
    TUint8* targetimage = 0;
    imageSize = 4*16*16;
    targetimage = new (ELeave) TUint8[imageSize];
    STIF_ASSERT_TRUE( targetimage != NULL );
    CleanupStack::PushL(targetimage);
    // fill with zero pixels
    for (t=0; t<4*16*16; t++)
        {
        targetimage[t] = 0;
        }

    value = targetimage[0];
    STIF_ASSERT_TRUE( value == 0 );

    HuiUtil::CropImage(4,
                         TSize(160,100),
                         sourceimage,
                         TPoint(0,16),
                         TSize(16,16),
                         targetimage);

    // assert that we got correct pixel data
    value = targetimage[0];
    STIF_ASSERT_TRUE( value == 16 );
    value = targetimage[1];
    STIF_ASSERT_TRUE( value == 24 );
    value = targetimage[2];
    STIF_ASSERT_TRUE( value == 32 );
    value = targetimage[3];
    STIF_ASSERT_TRUE( value == 255 );
    value = targetimage[15*16*4 + 0];
    STIF_ASSERT_TRUE( value == 16 );
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 1] == 24 );
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 2] == 32 );
    STIF_ASSERT_TRUE( targetimage[15*16*4 + 3] == 255 );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilTagMatches
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilTagMatches( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilTagMatches" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    _LIT8( KTagTxt, "Caption" );
    _LIT8( KTagsColonSeparatedTxt, "Test:Caption" );
    HuiUtil::TagMatches( KTagsColonSeparatedTxt, KTagTxt );

    return KErrNone;
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiUtilConvertBitmapToDisplayModeLCL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiUtilConvertBitmapToDisplayModeLCL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( KTestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KHuiUtil, "In TestHuiUtilConvertBitmapToDisplayModeLCL" );
    TestModuleIf().Printf( 0, KTestuiaifcoretoolkit, KHuiUtil );
    // Print to log file
    iLog->Log( KHuiUtil );

    CFbsBitmap *srcBmp = new ( ELeave ) CFbsBitmap();
    CleanupStack::PushL( srcBmp );
    TSize size( 10, 10 );
    User::LeaveIfError( srcBmp->Create( size, EColor16M ) );
    CFbsBitmap* desBmp = HuiUtil::ConvertBitmapToDisplayModeLC( *srcBmp, EGray2 );
    CleanupStack::PopAndDestroy( desBmp );
    CleanupStack::PopAndDestroy( srcBmp );

    return KErrNone;
    }
