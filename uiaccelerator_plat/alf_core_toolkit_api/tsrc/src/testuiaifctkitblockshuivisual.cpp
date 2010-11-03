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
* Description:  for testing the method of the CHuiVisual
*
*/

#include <uiacceltk\huivisual.h>
#include <uiacceltk\huicontrol.h>
#include <uiacceltk\huidecklayout.h>
#include <uiacceltk\huiskin.h>


#include "testuialfcoretoolkitvisualext.h"
#include "testuiaifcoretoolkit.h"

const TInt KSessionId = 0x2001CB80;
const TInt KPointX = 100;
const TInt KPointY = 100;
const TInt KLength = 200;
const TInt KBufLength = 20;
const TInt KMovePoint = 20;
const TInt KFeedbackEvent0 = 0;
const TInt KFeedbackEvent1 = 1;
const TInt KFeedbackType0 = 0;
const TInt KFeedbackType1 = 1;
const TInt KFeedbackType2 = 2;

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualAddNewL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualAddNewL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualAddNewL, "In TestHuiVisualAddNewL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualAddNewL );
    // Print to log file
    iLog->Log( KTestHuiVisualAddNewL );
    
    iHuiNewControl = new( ELeave ) CHuiControl( *iHuiEnv );
    
    TRAPD( error, iHuiVisual->AddNewL( *iHuiNewControl ) );

    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualCHuiVisual
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualCHuiVisualL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualCHuiVisual, "In TestHuiVisualCHuiVisual" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualCHuiVisual );
    // Print to log file
    iLog->Log( KTestHuiVisualCHuiVisual );
    
    iHuiVisual = new( ELeave ) CHuiVisual( *iHuiControl );

    STIF_ASSERT_NOT_NULL( iHuiVisual );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualConstructL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualConstructL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualConstructL, "In TestHuiVisualConstructL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualConstructL );
    // Print to log file
    iLog->Log( KTestHuiVisualConstructL );

    TRAPD( error, iHuiVisual->ConstructL() );
    
    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDelete
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDelete( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDelete, "In TestHuiVisualDelete" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDelete );
    // Print to log file
    iLog->Log( KTestHuiVisualDelete );

    delete iHuiVisual;
    iHuiVisual = NULL;

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualRemoveAndDestroyAllD
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualRemoveAndDestroyAllD( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualRemoveAndDestroyAllD, "In TestHuiVisualRemoveAndDestroyAllD" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualRemoveAndDestroyAllD );
    // Print to log file
    iLog->Log( KTestHuiVisualRemoveAndDestroyAllD );

    iHuiVisual->RemoveAndDestroyAllD();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetTagL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetTagL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetTagL, "In TestHuiVisualSetTagL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetTagL );
    // Print to log file
    iLog->Log( KTestHuiVisualSetTagL );
    
    TRAPD( error, iHuiVisual->SetTagL( _L8( "huidisplaystring" ) ) );
    
    return error;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualTag
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualTag( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualTag, "In TestHuiVisualTag" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualTag );
    // Print to log file
    iLog->Log( KTestHuiVisualTag );

    iHuiVisual->Tag();

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualIsTagged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualIsTagged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualIsTagged, "In TestHuiVisualIsTagged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualIsTagged );
    // Print to log file
    iLog->Log( KTestHuiVisualIsTagged );

    TBool isTagged = iHuiVisual->IsTagged();
    
    STIF_ASSERT_TRUE( isTagged );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualFindTag
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualFindTag( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualFindTag, "In TestHuiVisualFindTag" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualFindTag );
    // Print to log file
    iLog->Log( KTestHuiVisualFindTag );

    CHuiVisual* huiVisual = iHuiVisual->FindTag( _L8("huidisplaystring") );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetFlag
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetFlag( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetFlag, "In TestHuiVisualSetFlag" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetFlag );
    // Print to log file
    iLog->Log( KTestHuiVisualSetFlag );

    iHuiVisual->SetFlag( EHuiVisualFlagManualSize );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetFlags
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetFlags( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetFlags, "In TestHuiVisualSetFlags" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetFlags );
    // Print to log file
    iLog->Log( KTestHuiVisualSetFlags );

    iHuiVisual->SetFlags( 
            EHuiVisualFlagManualSize || 
            EHuiVisualFlagDrawAfterOthers ||
            EHuiVisualFlagHOriginRight ||
            EHuiVisualFlagFreezeLayout);
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualClearFlag
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualClearFlag( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualClearFlag, "In TestHuiVisualClearFlag" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualClearFlag );
    // Print to log file
    iLog->Log( KTestHuiVisualClearFlag );

    iHuiVisual->ClearFlag( EHuiVisualFlagManualSize );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualClearFlags
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualClearFlags( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualClearFlags, "In TestHuiVisualClearFlags" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualClearFlags );
    // Print to log file
    iLog->Log( KTestHuiVisualClearFlags );

    iHuiVisual->ClearFlags(
            EHuiVisualFlagManualSize || 
            EHuiVisualFlagDrawAfterOthers ||
            EHuiVisualFlagHOriginRight ||
            EHuiVisualFlagFreezeLayout );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualFlags
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualFlags( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualFlags, "In TestHuiVisualFlags" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualFlags );
    // Print to log file
    iLog->Log( KTestHuiVisualFlags );

    iHuiVisual->Flags();
    
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualOwner
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualOwner( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualOwner, "In TestHuiVisualOwner" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualOwner );
    // Print to log file
    iLog->Log( KTestHuiVisualOwner );

    MHuiVisualOwner* visual = &( iHuiVisual->Owner() );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetOwner
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetOwnerL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetOwner, "In TestHuiVisualSetOwner" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetOwner );
    // Print to log file
    iLog->Log( KTestHuiVisualSetOwner );
    
    iHuiNewControl = new( ELeave ) CHuiControl( *iHuiEnv );
    
    iHuiVisual->SetOwner( *iHuiNewControl );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualCount
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualCount( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualCount, "In TestHuiVisualCount" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualCount );
    // Print to log file
    iLog->Log( KTestHuiVisualCount );

    TInt count = iHuiVisual->Count();
    
    STIF_ASSERT_EQUALS( count, 0 );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualVisual
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualVisual( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualVisual, "In TestHuiVisualVisual" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualVisual );
    // Print to log file
    iLog->Log( KTestHuiVisualVisual );

//    iHuiVisual->Visual( 0 );//always panic
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualLayout
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualLayoutL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualLayout, "In TestHuiVisualLayout" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualLayout );
    // Print to log file
    iLog->Log( KTestHuiVisualLayout );

    iHuiLayout = new( ELeave ) CHuiLayout( *iHuiControl ); 

    iHuiLayout->ConstructL();
    
    iHuiLayout->AppendL( iHuiVisual );
    
    CHuiVisual* huiVisual = iHuiVisual->Layout();
    
    STIF_ASSERT_NOT_NULL( huiVisual );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualEnv
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualEnv( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualEnv, "In TestHuiVisualEnv" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualEnv );
    // Print to log file
    iLog->Log( KTestHuiVisualEnv );

    CHuiEnv* env = &( iHuiVisual->Env() );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSkin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSkin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSkin, "In TestHuiVisualSkin" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSkin );
    // Print to log file
    iLog->Log( KTestHuiVisualSkin );

    CHuiSkin* skin = &( iHuiVisual->Skin() );
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDisplay
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDisplay( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDisplay, "In TestHuiVisualDisplay" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDisplay );
    // Print to log file
    iLog->Log( KTestHuiVisualDisplay );
    
    CHuiDisplay* display = iHuiVisual->Display();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetOrigin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetOrigin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetOrigin, "In TestHuiVisualSetOrigin" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetOrigin );
    // Print to log file
    iLog->Log( KTestHuiVisualSetOrigin );

    iHuiVisual->SetOrigin( EHuiVisualHOriginCenter, EHuiVisualVOriginCenter );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualHorizontalOrigin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualHorizontalOrigin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualHorizontalOrigin, "In TestHuiVisualHorizontalOrigin" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualHorizontalOrigin );
    // Print to log file
    iLog->Log( KTestHuiVisualHorizontalOrigin );

    THuiVisualHOrigin hOrigin = iHuiVisual->HorizontalOrigin();
    
    STIF_ASSERT_EQUALS( hOrigin, EHuiVisualHOriginCenter );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualVerticalOrigin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualVerticalOrigin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualVerticalOrigin, "In TestHuiVisualVerticalOrigin" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualVerticalOrigin );
    // Print to log file
    iLog->Log( KTestHuiVisualVerticalOrigin );

    THuiVisualVOrigin vOrigin = iHuiVisual->VerticalOrigin();
    
    STIF_ASSERT_EQUALS( vOrigin, EHuiVisualVOriginCenter );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualAlignByOrigin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualAlignByOrigin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualAlignByOrigin, "In TestHuiVisualAlignByOrigin" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualAlignByOrigin );
    // Print to log file
    iLog->Log( KTestHuiVisualAlignByOrigin );

    THuiRealPoint point( KPointX, KPointY );
    
    iHuiVisual->AlignByOrigin( point );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetMinTSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetMinTSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetMinTSizeL, "In TestHuiVisualSetMinTSizeL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetMinTSizeL );
    // Print to log file
    iLog->Log( KTestHuiVisualSetMinTSizeL );
    
    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    TSize minSize( 20, 30 );
    iHuiVisual->SetMinSize( minSize );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetMinHuiSizeL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetMinHuiSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetMinHuiSizeL, "In TestHuiVisualSetMinHuiSizeL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetMinHuiSizeL );
    // Print to log file
    iLog->Log( KTestHuiVisualSetMinHuiSizeL );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    THuiRealSize minSize( 20.4, 30.3 );
    iHuiVisual->SetMinSize( minSize );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMinSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMinSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMinSize, "In TestHuiVisualMinSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMinSize );
    // Print to log file
    iLog->Log( KTestHuiVisualMinSize );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    TSize minSize( 20, 30 );
    iHuiVisual->SetMinSize( minSize );
    
    TSize result = iHuiVisual->MinSize();
    STIF_ASSERT_EQUALS( minSize.iHeight , result.iHeight );
    STIF_ASSERT_EQUALS( minSize.iWidth , result.iWidth );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMinSizeInBaseUnits
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMinSizeInBaseUnitsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMinSizeInBaseUnits, "In TestHuiVisualMinSizeInBaseUnits" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMinSizeInBaseUnits );
    // Print to log file
    iLog->Log( KTestHuiVisualMinSizeInBaseUnits );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    THuiRealSize minSize( 20.4, 30.3 );
    iHuiVisual->SetMinSize( minSize );
    
    THuiRealSize result = iHuiVisual->MinSizeInBaseUnits();
    STIF_ASSERT_EQUALS( minSize.iHeight , result.iHeight );
    STIF_ASSERT_EQUALS( minSize.iWidth , result.iWidth );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetMaxTSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetMaxTSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetMaxTSize, "In TestHuiVisualSetMaxTSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetMaxTSize );
    // Print to log file
    iLog->Log( KTestHuiVisualSetMaxTSize );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    TSize maxSize( 20, 30 );
    iHuiVisual->SetMaxSize( maxSize );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetMaxHuiSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetMaxHuiSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetMaxHuiSize, "In TestHuiVisualSetMaxHuiSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetMaxHuiSize );
    // Print to log file
    iLog->Log( KTestHuiVisualSetMaxHuiSize );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    THuiRealSize maxSize( 20.4, 30.3 );
    iHuiVisual->SetMaxSize( maxSize );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMaxSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMaxSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMaxSize, "In TestHuiVisualMaxSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMaxSize );
    // Print to log file
    iLog->Log( KTestHuiVisualMaxSize );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    TSize maxSize( 20, 30 );
    iHuiVisual->SetMaxSize( maxSize );
    
    TSize result = iHuiVisual->MaxSize();
    STIF_ASSERT_EQUALS( maxSize.iHeight , result.iHeight );
    STIF_ASSERT_EQUALS( maxSize.iWidth , result.iWidth );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMaxSizeInBaseUnits
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMaxSizeInBaseUnitsL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMaxSizeInBaseUnits, "In TestHuiVisualMaxSizeInBaseUnits" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMaxSizeInBaseUnits );
    // Print to log file
    iLog->Log( KTestHuiVisualMaxSizeInBaseUnits );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    THuiRealSize maxSize( 20.4, 30.3 );
    iHuiVisual->SetMaxSize( maxSize );
    
    THuiRealSize result = iHuiVisual->MaxSizeInBaseUnits();
    STIF_ASSERT_EQUALS( maxSize.iHeight , result.iHeight );
    STIF_ASSERT_EQUALS( maxSize.iWidth , result.iWidth );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPosConst
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPosConst( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPosConst, "In TestHuiVisualPosConst" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPosConst );
    // Print to log file
    iLog->Log( KTestHuiVisualPosConst );

    const_cast< const CHuiVisual* >( iHuiVisual )->Pos();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualConstSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualConstSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualConstSize, "In TestHuiVisualConstSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualConstSize );
    // Print to log file
    iLog->Log( KTestHuiVisualConstSize );

    const_cast< const CHuiVisual* >( iHuiVisual )->Size();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSize, "In TestHuiVisualSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSize );
    // Print to log file
    iLog->Log( KTestHuiVisualSize );

    iHuiVisual->Size();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetPos
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetPos( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetPos, "In TestHuiVisualSetPos" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetPos );
    // Print to log file
    iLog->Log( KTestHuiVisualSetPos );

    THuiRealPoint huiRealPoint( KPointX, KPointY );
    
    iHuiVisual->SetPos( huiRealPoint );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetSize( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetSize, "In TestHuiVisualSetSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetSize );
    // Print to log file
    iLog->Log( KTestHuiVisualSetSize );

    THuiRealSize size( KPointX, KPointY );
    
    iHuiVisual->SetSize( size );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetRect, "In TestHuiVisualSetRect" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetRect );
    // Print to log file
    iLog->Log( KTestHuiVisualSetRect );

    THuiRealPoint leftTop( 0, 0 );
    THuiRealPoint rightBottom( KPointX, KPointY );
    
    THuiRealRect rect( leftTop, rightBottom );
    
    iHuiVisual->SetRect( rect );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualTMove
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualTMoveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualTMove, "In TestHuiVisualTMove" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualTMove );
    // Print to log file
    iLog->Log( KTestHuiVisualTMove );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    
    TPoint offset( 20, 12 );
    iHuiVisual->SetFlag( EHuiVisualFlagManualLayout );
    iHuiVisual->Move( offset );
    THuiTimedPoint visualPos = iHuiVisual->Pos();
    STIF_ASSERT_EQUALS( visualPos.Target().iX , offset.iX );
    STIF_ASSERT_EQUALS( visualPos.Target().iY , offset.iY );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualHuiMove
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualHuiMoveL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualHuiMove, "In TestHuiVisualHuiMove" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualHuiMove );
    // Print to log file
    iLog->Log( KTestHuiVisualHuiMove );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    THuiRealPoint huiRealPoint( KMovePoint, KMovePoint );
    
    THuiRealPoint offset( 20.4, 12.3 );
    iHuiVisual->SetFlag( EHuiVisualFlagManualLayout );
    iHuiVisual->Move( offset );
    THuiTimedPoint visualPos = iHuiVisual->Pos();    
    STIF_ASSERT_EQUALS( visualPos.iX.Target() , offset.iX );
    STIF_ASSERT_EQUALS( visualPos.iY.Target() , offset.iY );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMimic
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMimicL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMimic, "In TestHuiVisualMimic" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMimic );
    // Print to log file
    iLog->Log( KTestHuiVisualMimic );

    iHuiNewControl = new( ELeave ) CHuiControl( *iHuiEnv );
    
    CHuiVisual* visual = CHuiVisual::AddNewL( *iHuiNewControl );
    
    iHuiVisual->Mimic( *visual );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetCenteredPosAndTSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetCenteredPosAndTSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetCenteredPosAndTSize, "In TestHuiVisualSetCenteredPosAndTSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetCenteredPosAndTSize );
    // Print to log file
    iLog->Log( KTestHuiVisualSetCenteredPosAndTSize );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    TPoint centerPoint(20,30);
    TSize size(40,50);
    TInt tempX = centerPoint.iX-(size.iWidth/2.0);
    TInt tempY = centerPoint.iY-(size.iHeight/2.0);
    iHuiVisual->SetFlag( EHuiVisualFlagManualLayout );
    iHuiVisual->SetCenteredPosAndSize( centerPoint, size );
    THuiTimedPoint visualPos = iHuiVisual->Pos();
    THuiTimedPoint visualSize = iHuiVisual->Size();
    STIF_ASSERT_EQUALS(visualPos.Target().iX , tempX );
    STIF_ASSERT_EQUALS(visualPos.Target().iY , tempY ) ;
    STIF_ASSERT_EQUALS(visualSize.Target().iX, size.iWidth );
    STIF_ASSERT_EQUALS(visualSize.Target().iY, size.iHeight );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetCenteredPosAndHuiSize
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetCenteredPosAndHuiSizeL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetCenteredPosAndHuiSize, "In TestHuiVisualSetCenteredPosAndHuiSize" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetCenteredPosAndHuiSize );
    // Print to log file
    iLog->Log( KTestHuiVisualSetCenteredPosAndHuiSize );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    THuiRealPoint centerPoint(20.4,30.3);
    THuiRealSize size(40.3,50.4);
    TInt tempX = centerPoint.iX-(size.iWidth/2.0);
    TInt tempY = centerPoint.iY-(size.iHeight/2.0);
    iHuiVisual->SetFlag( EHuiVisualFlagManualLayout );
    iHuiVisual->SetCenteredPosAndSize( centerPoint, size );
    THuiTimedPoint visualPos = iHuiVisual->Pos();
    THuiTimedPoint visualSize = iHuiVisual->Size();
    STIF_ASSERT_EQUALS(visualPos.Target().iX , tempX );
    STIF_ASSERT_EQUALS(visualPos.Target().iY , tempY );
    STIF_ASSERT_EQUALS(visualSize.iX.Target(), size.iWidth );
    STIF_ASSERT_EQUALS(visualSize.iY.Target(), size.iHeight );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualUpdateChildrenLayout
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualUpdateChildrenLayout( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualUpdateChildrenLayout, "In TestHuiVisualUpdateChildrenLayout" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualUpdateChildrenLayout );
    // Print to log file
    iLog->Log( KTestHuiVisualUpdateChildrenLayout );

    iHuiVisual->UpdateChildrenLayout();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualUpdateSiblingLayout
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualUpdateSiblingLayout( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualUpdateSiblingLayout, "In TestHuiVisualUpdateSiblingLayout" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualUpdateSiblingLayout );
    // Print to log file
    iLog->Log( KTestHuiVisualUpdateSiblingLayout );

    iHuiVisual->UpdateSiblingLayout();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDisplayRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDisplayRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDisplayRect, "In TestHuiVisualDisplayRect" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDisplayRect );
    // Print to log file
    iLog->Log( KTestHuiVisualDisplayRect );
    
    iHuiVisual->DisplayRect();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDisplayRectTarget
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDisplayRectTarget( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDisplayRectTarget, "In TestHuiVisualDisplayRectTarget" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDisplayRectTarget );
    // Print to log file
    iLog->Log( KTestHuiVisualDisplayRectTarget );

    iHuiVisual->DisplayRectTarget();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualLocalBaseUnit
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualLocalBaseUnit( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualLocalBaseUnit, "In TestHuiVisualLocalBaseUnit" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualLocalBaseUnit );
    // Print to log file
    iLog->Log( KTestHuiVisualLocalBaseUnit );

    iHuiVisual->LocalBaseUnit();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualLocalPointInPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualLocalPointInPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualLocalPointInPixels, "In TestHuiVisualLocalPointInPixels" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualLocalPointInPixels );
    // Print to log file
    iLog->Log( KTestHuiVisualLocalPointInPixels );

    THuiRealPoint huiRealPoint( KPointX, KPointY );
    
    iHuiVisual->LocalPointInPixels( huiRealPoint );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualLocalPointInPixelsWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualLocalPointInPixelsWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualLocalPointInPixelsWithState, "In TestHuiVisualLocalPointInPixelsWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualLocalPointInPixelsWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualLocalPointInPixelsWithState );

    THuiRealPoint huiRealPoint( KPointX, KPointY );
    
    iHuiVisual->LocalPointInPixels( huiRealPoint, EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPixelPointInLocal
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPixelPointInLocal( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPixelPointInLocal, "In TestHuiVisualPixelPointInLocal" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPixelPointInLocal );
    // Print to log file
    iLog->Log( KTestHuiVisualPixelPointInLocal );

    THuiRealPoint huiRealPoint( KPointX, KPointY );
    
    iHuiVisual->PixelPointInLocal( huiRealPoint );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPixelPointInLocalWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPixelPointInLocalWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPixelPointInLocalWithState, "In TestHuiVisualPixelPointInLocalWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPixelPointInLocalWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualPixelPointInLocalWithState );

    THuiRealPoint huiRealPoint( KPointX, KPointY );
    
    iHuiVisual->PixelPointInLocal( huiRealPoint, EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMetricToPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMetricToPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMetricToPixels, "In TestHuiVisualMetricToPixels" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMetricToPixels );
    // Print to log file
    iLog->Log( KTestHuiVisualMetricToPixels );
    
    THuiMetric x( KLength );
    THuiMetric y( KLength );
    THuiXYMetric huiXYMetric( x, y );

    iHuiVisual->MetricToPixels( huiXYMetric );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMetricToPixelsWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMetricToPixelsWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMetricToPixelsWithState, "In TestHuiVisualMetricToPixelsWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMetricToPixelsWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualMetricToPixelsWithState );
    
    THuiMetric x( KLength );
    THuiMetric y( KLength );
    THuiXYMetric huiXYMetric( x, y );

    iHuiVisual->MetricToPixels( huiXYMetric, EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPixelsToMetric
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPixelsToMetric( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPixelsToMetric, "In TestHuiVisualPixelsToMetric" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPixelsToMetric );
    // Print to log file
    iLog->Log( KTestHuiVisualPixelsToMetric );

    THuiRealPoint huiRealPoint( KPointX, KPointX );
    
    THuiMetric x( KLength );
    THuiMetric y( KLength );
    THuiXYMetric huiXYMetric( x, y );
    
    iHuiVisual->PixelsToMetric( huiRealPoint, huiXYMetric );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPixelsToMetricWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPixelsToMetricWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPixelsToMetricWithState, "In TestHuiVisualPixelsToMetricWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPixelsToMetricWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualPixelsToMetricWithState );

    THuiRealPoint huiRealPoint( KPointX, KPointY );
    
    THuiMetric x( KLength );
    THuiMetric y( KLength );
    THuiXYMetric huiXYMetric( x, y );
    
    iHuiVisual->PixelsToMetric( huiRealPoint, huiXYMetric, EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMetricReferenceInPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMetricReferenceInPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMetricReferenceInPixels, "In TestHuiVisualMetricReferenceInPixels" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMetricReferenceInPixels );
    // Print to log file
    iLog->Log( KTestHuiVisualMetricReferenceInPixels );
    
    THuiMetric x( KLength );
    THuiMetric y( KLength );
    THuiXYMetric huiXYMetric( x, y );
    
    iHuiVisual->MetricReferenceInPixels( huiXYMetric );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMetricReferenceInPixelsWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMetricReferenceInPixelsWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMetricReferenceInPixelsWithState, "In TestHuiVisualMetricReferenceInPixelsWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMetricReferenceInPixelsWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualMetricReferenceInPixelsWithState );
    
    THuiMetric x( KLength );
    THuiMetric y( KLength );
    THuiXYMetric huiXYMetric( x, y );
    
    iHuiVisual->MetricReferenceInPixels( huiXYMetric, EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualLocalToDisplayT
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualLocalToDisplayT( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualLocalToDisplayT, "In TestHuiVisualLocalToDisplayT" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualLocalToDisplayT );
    // Print to log file
    iLog->Log( KTestHuiVisualLocalToDisplayT );

    TPoint point( KPointX, KPointY );
    
    iHuiVisual->LocalToDisplay( point );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualLocalToDisplayHui
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualLocalToDisplayHui( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualLocalToDisplayHui, "In TestHuiVisualLocalToDisplayHui" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualLocalToDisplayHui );
    // Print to log file
    iLog->Log( KTestHuiVisualLocalToDisplayHui );

    THuiRealPoint point( KPointX, KPointY );
    
    iHuiVisual->LocalToDisplay( point );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDisplayToLocalT
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDisplayToLocalT( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDisplayToLocalT, "In TestHuiVisualDisplayToLocalT" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDisplayToLocalT );
    // Print to log file
    iLog->Log( KTestHuiVisualDisplayToLocalT );

    TPoint point( KPointX, KPointY );
    
    iHuiVisual->DisplayToLocal( point );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDisplayToLocalHui
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDisplayToLocalHui( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDisplayToLocalHui, "In TestHuiVisualDisplayToLocalHui" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDisplayToLocalHui );
    // Print to log file
    iLog->Log( KTestHuiVisualDisplayToLocalHui );

    THuiRealPoint point( KPointX, KPointY );
    
    iHuiVisual->DisplayToLocal( point );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualBoxMetricToPixelRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualBoxMetricToPixelRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualBoxMetricToPixelRect, "In TestHuiVisualBoxMetricToPixelRect" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualBoxMetricToPixelRect );
    // Print to log file
    iLog->Log( KTestHuiVisualBoxMetricToPixelRect );

    THuiMetric size( KPointX );
    THuiBoxMetric boxMetric( size );
    

    THuiRealPoint leftTop( 0, 0 );
    THuiRealPoint rightBottom( KPointX, KPointY );
    
    THuiRealRect rect( leftTop, rightBottom );
    
    iHuiVisual->BoxMetricToPixelRect( boxMetric, rect );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualBoxMetricToPixelRectWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualBoxMetricToPixelRectWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualBoxMetricToPixelRectWithState, "In TestHuiVisualBoxMetricToPixelRectWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualBoxMetricToPixelRectWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualBoxMetricToPixelRectWithState );

    THuiMetric size( KPointX );
    THuiBoxMetric boxMetric( size );
    

    THuiRealPoint leftTop( 0, 0 );
    THuiRealPoint rightBottom( KPointX, KPointY );
    
    THuiRealRect rect( leftTop, rightBottom );
    
    iHuiVisual->BoxMetricToPixelRect( boxMetric, rect, EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualMoveToFront
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualMoveToFront( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualMoveToFront, "In TestHuiVisualMoveToFront" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualMoveToFront );
    // Print to log file
    iLog->Log( KTestHuiVisualMoveToFront );

    iHuiVisual->MoveToFront();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPos
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPos( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPos, "In TestHuiVisualPos" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPos );
    // Print to log file
    iLog->Log( KTestHuiVisualPos );

    iHuiVisual->Pos();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualEffectiveOpacity
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualEffectiveOpacity( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualEffectiveOpacity, "In TestHuiVisualEffectiveOpacity" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualEffectiveOpacity );
    // Print to log file
    iLog->Log( KTestHuiVisualEffectiveOpacity );

    iHuiVisual->EffectiveOpacity();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetClipping
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetClipping( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetClipping, "In TestHuiVisualSetClipping" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetClipping );
    // Print to log file
    iLog->Log( KTestHuiVisualSetClipping );

    iHuiVisual->SetClipping();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualClipping
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualClipping( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualClipping, "In TestHuiVisualClipping" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualClipping );
    // Print to log file
    iLog->Log( KTestHuiVisualClipping );

    TBool flag = iHuiVisual->Clipping();
    
    STIF_ASSERT_TRUE( flag );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualEnableTransformationL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualEnableTransformationL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualEnableTransformationL, "In TestHuiVisualEnableTransformationL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualEnableTransformationL );
    // Print to log file
    iLog->Log( KTestHuiVisualEnableTransformationL );

    iHuiVisual->EnableTransformationL();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualTransformation
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualTransformation( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualTransformation, "In TestHuiVisualTransformation" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualTransformation );
    // Print to log file
    iLog->Log( KTestHuiVisualTransformation );

    iHuiVisual->Transformation();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetPadding
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetPadding( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetPadding, "In TestHuiVisualSetPadding" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetPadding );
    // Print to log file
    iLog->Log( KTestHuiVisualSetPadding );

    TInt pad( KPointY );
    
    iHuiVisual->SetPadding( pad );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetPaddingWithPoint
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetPaddingWithPoint( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetPaddingWithPoint, "In TestHuiVisualSetPaddingWithPoint" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetPaddingWithPoint );
    // Print to log file
    iLog->Log( KTestHuiVisualSetPaddingWithPoint );

    TPoint point( KPointX, KPointY );
    
    iHuiVisual->SetPadding( point );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPadding
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetPaddingWithHuiBoxMetrix( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPadding, "In TestHuiVisualPadding" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPadding );
    // Print to log file
    iLog->Log( KTestHuiVisualPadding );

    THuiMetric size( KPointX );
    THuiBoxMetric boxMetric( size );
    
    iHuiVisual->SetPadding( boxMetric );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPadding
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPadding( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPadding, "In TestHuiVisualPadding" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPadding );
    // Print to log file
    iLog->Log( KTestHuiVisualPadding );

    iHuiVisual->Padding();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPaddingInPixels
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPaddingInPixels( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPaddingInPixels, "In TestHuiVisualPaddingInPixels" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPaddingInPixels );
    // Print to log file
    iLog->Log( KTestHuiVisualPaddingInPixels );

    iHuiVisual->PaddingInPixels();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPaddingInPixelsWithState
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPaddingInPixelsWithState( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPaddingInPixelsWithState, "In TestHuiVisualPaddingInPixelsWithState" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPaddingInPixelsWithState );
    // Print to log file
    iLog->Log( KTestHuiVisualPaddingInPixelsWithState );

    iHuiVisual->PaddingInPixels( EHuiReferenceStateTarget );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualPrepareDrawL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualPrepareDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualPrepareDrawL, "In TestHuiVisualPrepareDrawL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualPrepareDrawL );
    // Print to log file
    iLog->Log( KTestHuiVisualPrepareDrawL );

    TBool flag = iHuiVisual->PrepareDrawL();
    
    STIF_ASSERT_TRUE( flag );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDraw
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDrawL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDraw, "In TestHuiVisualDraw" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDraw );
    // Print to log file
    iLog->Log( KTestHuiVisualDraw );

    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();
    
    iHuiVisual->Draw( gc ); // Need Gc

    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDrawBrushes
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDrawBrushesL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDrawBrushes, "In TestHuiVisualDrawBrushes" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDrawBrushes );
    // Print to log file
    iLog->Log( KTestHuiVisualDrawBrushes );

    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();

    iHuiVisual->DrawBrushes( gc, EHuiBrushLayerBackground );// Need Gc
    
    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDrawSelf
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDrawSelfL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDrawSelf, "In TestHuiVisualDrawSelf" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDrawSelf );
    // Print to log file
    iLog->Log( KTestHuiVisualDrawSelf );
    
    const TRect KDisplayRect( 0,0,100,100 );

    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();
    
    iHuiVisual->DrawSelf( gc, KDisplayRect ); // Need Gc

    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetChanged, "In TestHuiVisualSetChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetChanged );
    // Print to log file
    iLog->Log( KTestHuiVisualSetChanged );

    iHuiVisual->SetChanged();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualChanged, "In TestHuiVisualChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualChanged );
    // Print to log file
    iLog->Log( KTestHuiVisualChanged );

    iHuiVisual->Changed();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualReportChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualReportChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualReportChanged, "In TestHuiVisualReportChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualReportChanged );
    // Print to log file
    iLog->Log( KTestHuiVisualReportChanged );

    iHuiVisual->ReportChanged();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualClearChanged
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualClearChanged( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualClearChanged, "In TestHuiVisualClearChanged" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualClearChanged );
    // Print to log file
    iLog->Log( KTestHuiVisualClearChanged );

    iHuiVisual->ClearChanged();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualEnableBrushesL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualEnableBrushesL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualEnableBrushesL, "In TestHuiVisualEnableBrushesL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualEnableBrushesL );
    // Print to log file
    iLog->Log( KTestHuiVisualEnableBrushesL );

    iHuiVisual->EnableBrushesL();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualBrushes
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualBrushes( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualBrushes, "In TestHuiVisualBrushes" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualBrushes );
    // Print to log file
    iLog->Log( KTestHuiVisualBrushes );

    iHuiVisual->Brushes();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDumpTree
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDumpTree( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDumpTree, "In TestHuiVisualDumpTree" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDumpTree );
    // Print to log file
    iLog->Log( KTestHuiVisualDumpTree );

    iHuiVisual->DumpTree();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualGetInstanceName
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualGetInstanceName( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualGetInstanceName, "In TestHuiVisualGetInstanceName" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualGetInstanceName );
    // Print to log file
    iLog->Log( KTestHuiVisualGetInstanceName );

    TBuf<KBufLength> instanceName;
    
    iHuiVisual->GetInstanceName( instanceName );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualGetClassName
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualGetClassName( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualGetClassName, "In TestHuiVisualGetClassName" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualGetClassName );
    // Print to log file
    iLog->Log( KTestHuiVisualGetClassName );

    TBuf<KBufLength> className;
    
    iHuiVisual->GetClassName( className );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualEnterLocalProjection
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualEnterLocalProjectionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualEnterLocalProjection, "In TestHuiVisualEnterLocalProjection" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualEnterLocalProjection );
    // Print to log file
    iLog->Log( KTestHuiVisualEnterLocalProjection );


    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();
    
    iHuiVisual->EnterLocalProjection( gc, ETrue ); // Need Gc

    CleanupStack::PopAndDestroy( ctrl );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualNotifySkinChangedL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualNotifySkinChangedL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualNotifySkinChangedL, "In TestHuiVisualNotifySkinChangedL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualNotifySkinChangedL );
    // Print to log file
    iLog->Log( KTestHuiVisualNotifySkinChangedL );

    iHuiVisual->NotifySkinChangedL();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetTactileFeedbackL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetTactileFeedbackL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetTactileFeedbackL, "In TestHuiVisualSetTactileFeedbackL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetTactileFeedbackL );
    // Print to log file
    iLog->Log( KTestHuiVisualSetTactileFeedbackL );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent0 , KFeedbackType0 );
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent1 , KFeedbackType1 );
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent1 , KFeedbackType0 );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualHasTactileFeedback
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualHasTactileFeedbackL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualHasTactileFeedback, "In TestHuiVisualHasTactileFeedback" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualHasTactileFeedback );
    // Print to log file
    iLog->Log( KTestHuiVisualHasTactileFeedback );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback() );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent0 , KFeedbackType0 );
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback() );
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    iHuiVisual->RemoveTactileFeedback();
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback() );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualRemoveTactileFeedback
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualRemoveTactileFeedbackL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualRemoveTactileFeedback, "In TestHuiVisualRemoveTactileFeedback" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualRemoveTactileFeedback );
    // Print to log file
    iLog->Log( KTestHuiVisualRemoveTactileFeedback );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback() );
    iHuiVisual->RemoveTactileFeedback(); // do nothing
    iHuiVisual->RemoveTactileFeedback( KFeedbackEvent0 ); // do nothing
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback() );
    
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent0 , KFeedbackType0 ); // add 0
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent1 , KFeedbackType1 ); // add 1
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    iHuiVisual->RemoveTactileFeedback( KFeedbackEvent0 ); // remove 0
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    iHuiVisual->SetTactileFeedbackL( KFeedbackEvent0 , KFeedbackType2 ); // add 0
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    iHuiVisual->RemoveTactileFeedback(); // remove all
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent0) );
    STIF_ASSERT_TRUE( !iHuiVisual->HasTactileFeedback(KFeedbackEvent1) );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiHuiVisualEnableDropShadowL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualEnableDropShadowL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualEnableDropShadowL, "In TestHuiVisualEnableDropShadowL" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualEnableDropShadowL );
    // Print to log file
    iLog->Log( KTestHuiVisualEnableDropShadowL );

    iHuiVisual = iHuiControl->AppendVisualL( EHuiVisualTypeVisual );
    // by default, the drop shadow should be disabled
    STIF_ASSERT_TRUE( !iHuiVisual->DropShadowHandler() );
    
    // enable
    iHuiVisual->EnableDropShadowL();
    STIF_ASSERT_NOT_NULL( iHuiVisual->DropShadowHandler() );
    
    // disable
    iHuiVisual->EnableDropShadowL(EFalse);
    STIF_ASSERT_TRUE( !iHuiVisual->DropShadowHandler() );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualDropShadowHandler
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualDropShadowHandler( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualDropShadowHandler, "In TestHuiVisualDropShadowHandler" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualDropShadowHandler );
    // Print to log file
    iLog->Log( KTestHuiVisualDropShadowHandler );

    CHuiDropShadow* dropShadow = iHuiVisual->DropShadowHandler();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualBrushOpacity
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualBrushOpacity( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualBrushOpacity, "In TestHuiVisualBrushOpacity" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualBrushOpacity );
    // Print to log file
    iLog->Log( KTestHuiVisualBrushOpacity );

    iHuiVisual->BrushOpacity();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualBrushRect
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualBrushRect( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualBrushRect, "In TestHuiVisualBrushRect" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualBrushRect );
    // Print to log file
    iLog->Log( KTestHuiVisualBrushRect );

    iHuiVisual->BrushRect();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualBrushSkin
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualBrushSkin( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualBrushSkin, "In TestHuiVisualBrushSkin" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualBrushSkin );
    // Print to log file
    iLog->Log( KTestHuiVisualBrushSkin );

    CHuiSkin* skin = &( iHuiVisual->BrushSkin() );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualType
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualType( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualType, "In TestHuiVisualType" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualType );
    // Print to log file
    iLog->Log( KTestHuiVisualType );

    iHuiVisual->Type();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSessionId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSessionId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSessionId, "In TestHuiVisualSessionId" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSessionId );
    // Print to log file
    iLog->Log( KTestHuiVisualSessionId );

    iHuiVisual->SessionId();
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualSetSessionId
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualSetSessionId( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualSetSessionId, "In TestHuiVisualSetSessionId" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualSetSessionId );
    // Print to log file
    iLog->Log( KTestHuiVisualSetSessionId );

    iHuiVisual->SetSessionId( KSessionId );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualTransform
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualTransformL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualTransform, "In TestHuiVisualTransform" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualTransform );
    // Print to log file
    iLog->Log( KTestHuiVisualTransform );

    iHuiVisualExt = new( ELeave ) CTestPlatALFCoreToolkitVisualExt( *iHuiControl );
    
    iHuiVisualExt->ConstructL();


    const TRect rect( 0, 0, 100, 100 );
    CHuiDisplayCoeControl* ctrl = CHuiDisplayCoeControl::NewL( *iHuiEnv, rect );

    CleanupStack::PushL( ctrl );

    CHuiEnv::RefreshCallBack( iHuiEnv );

    CHuiGc& gc = iHuiEnv->Skin().Context();

    iHuiVisualExt = new( ELeave ) CTestPlatALFCoreToolkitVisualExt( *iHuiControl );
    
    iHuiVisualExt->ConstructL();
    iHuiVisualExt->Transform( gc, ETrue ); // Need Gc

    CleanupStack::PopAndDestroy( ctrl );

    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualExpandRectWithContent
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualExpandRectWithContentL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualExpandRectWithContent, "In TestHuiVisualExpandRectWithContent" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualExpandRectWithContent );
    // Print to log file
    iLog->Log( KTestHuiVisualExpandRectWithContent );

    iHuiVisualExt = new( ELeave ) CTestPlatALFCoreToolkitVisualExt( *iHuiControl );
    
    iHuiVisualExt->ConstructL();
    
    TRect rect( TPoint( 0, 0 ), TPoint( KPointX, KPointX ) );
    
    iHuiVisualExt->ExpandRectWithContent( rect );
    
    return KErrNone;

    }

// -----------------------------------------------------------------------------
// Ctestplatalfcoretoolkit::TestHuiVisualVisualExtension
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiVisualVisualExtensionL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestplatalfcoretoolkit, "testplatalfcoretoolkit" );
    _LIT( KTestHuiVisualVisualExtension, "In TestHuiVisualVisualExtension" );
    TestModuleIf().Printf( 0, Ktestplatalfcoretoolkit, KTestHuiVisualVisualExtension );
    // Print to log file
    iLog->Log( KTestHuiVisualVisualExtension );

    iHuiVisualExt = new( ELeave ) CTestPlatALFCoreToolkitVisualExt( *iHuiControl );
    
    iHuiVisualExt->ConstructL();
    
    TUid uid = TUid::Null();
    TAny** any = NULL;
    
    iHuiVisualExt->VisualExtension( uid, any );
    
    return KErrNone;

    }

//  [End of File]
