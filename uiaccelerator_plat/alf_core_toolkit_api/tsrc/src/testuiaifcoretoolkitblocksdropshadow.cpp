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
#include <e32math.h>
#include <stifparser.h>
#include <AknsConstants.h>
#include <uiacceltk/huienv.h>
#include <stiftestinterface.h>
#include <uiacceltk/huienv.h>
#include <uiacceltk/huistatic.h>
#include <uiacceltk/huidropshadow.h>

#include <uiacceltk/huidisplay.h>
#include <uiacceltk/huidisplaybackgrounditem.h>
#include <uiacceltk/huicontrol.h>
#include <uiacceltk/huicontrolgroup.h>
#include <uiacceltk/huiimagevisual.h>
#include <uiacceltk/huiutil.h>

#include "testuiaifcoretoolkit.h"

#define FLOAT_COMPARE(a, b) (Abs(a-b)<0.001f)

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHSetOffsetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHSetOffsetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHSetOffsetL, "In TestTHSetOffsetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHSetOffsetL );
    // Print to log file 
    iLog->Log( KTestTHSetOffsetL );
    
    TBool temp = ETrue;
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    huiVisual->EnableDropShadowL( temp );
    CHuiDropShadow* dropShadow = huiVisual->DropShadowHandler();
    
    // polar coorinates
    const TReal32 angle = 123.2f;
    const THuiMetric distance( 1234.6f, EHuiUnitS60 );
    const TInt transitionTime = 23;
    
    dropShadow->SetOffset( angle, distance, transitionTime );
    
    // wait the result
    CHuiEnv::RefreshCallBack( iHuiEnv );
    User::After( 1.2f*transitionTime );
    CHuiEnv::RefreshCallBack( iHuiEnv );
    
    // verify:
    TReal shouldBeX;
    Math::Cos( shouldBeX, 2.0*KPi*angle/360.0 );
    shouldBeX*=distance.iMagnitude;
    
    TReal shouldBeY;
    Math::Sin( shouldBeY, 2.0*KPi*angle/360.0 );
    shouldBeY*=-1.0*distance.iMagnitude;
    
    STIF_ASSERT_TRUE( FLOAT_COMPARE( dropShadow->iOffset.iX.Now(), shouldBeX ) );
    STIF_ASSERT_TRUE( FLOAT_COMPARE( dropShadow->iOffset.iY.Now(), shouldBeY ) );
    STIF_ASSERT_TRUE( FLOAT_COMPARE( dropShadow->iOffsetUnit, distance.iUnit ) );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHSetColorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHSetColorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHSetColorLL, "In TestTHSetColorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHSetColorLL );
    // Print to log file 
    iLog->Log( KTestTHSetColorLL );
    
    TBool temp = ETrue;
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    huiVisual->EnableDropShadowL( temp );
    CHuiDropShadow* dropShadow = huiVisual->DropShadowHandler();
    
    const TRgb color1( KRgbCyan );
    dropShadow->SetColor( color1 );
    
    return KErrNone;
    
    }

// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestTHSetColorTAknsItemIDL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestTHSetColorTAknsItemIDL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestTHSetColorTAknsItemIDL, "In TestTHSetColorTAknsItemIDL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestTHSetColorTAknsItemIDL );
    // Print to log file 
    iLog->Log( KTestTHSetColorTAknsItemIDL );
    
    TBool temp = ETrue;
    CHuiVisual* huiVisual = CHuiVisual::AddNewL( *iHuiControl );
    huiVisual->EnableDropShadowL( temp );
    CHuiDropShadow* dropShadow = huiVisual->DropShadowHandler();
    
    // change timed
    const TRgb color2( KRgbGreen );
    const TInt transitionTime = 23;
    
    dropShadow->SetColor( color2, transitionTime );
    
    const TAknsItemID color1( KAknsIIDQsnTextColors );
    const TInt index1( EAknsCIQsnTextColorsCG5 );
    dropShadow->SetColor( color1, index1 );
    
    // change timed
    const TAknsItemID color3( KAknsIIDQsnComponentColors );
    const TInt index2( EAknsCIQsnComponentColorsCG14 );
    const TInt transitionTime1 = 23;
    
    dropShadow->SetColor( color3, index2, transitionTime1 );
    
    return KErrNone;
    
    }

//  [End of File]
