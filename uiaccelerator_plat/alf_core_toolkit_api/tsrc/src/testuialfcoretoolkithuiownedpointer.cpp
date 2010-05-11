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
#include <uiacceltk/huiownedpointer.h>
#include <uiacceltk/HuiBorderBrush.h>

#include "testuiaifcoretoolkit.h"
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerCloseL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerCloseL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerCloseL, "In TestHuiOwnerdPointerCloseL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerCloseL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerCloseL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    huiOwnedPointer.Close();
    CleanupStack::PopAndDestroy( brush );
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerOperatorTL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerOperatorTL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerOperatorTL, "In TestHuiOwnerdPointerOperatorTL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerOperatorTL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerOperatorTL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;

    RHuiOwnedPointer<CHuiBorderBrush> huiTemp = huiOwnedPointer;
    CHuiBorderBrush* temp= huiTemp;
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerOperatorConstTL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerOperatorConstTL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerOperatorConstTL, "In TestHuiOwnerdPointerOperatorConstTL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerOperatorConstTL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerOperatorConstTL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    //test operator const T*() const
    
    const RHuiOwnedPointer<CHuiBorderBrush> huiTemp = huiOwnedPointer;
    const CHuiBorderBrush* temp= huiTemp;
    
    CleanupStack::PopAndDestroy( brush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerOperatorL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerOperatorL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerOperatorL, "In TestHuiOwnerdPointerOperatorL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerOperatorL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerOperatorL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
//    test T* operator -> ()
    RHuiOwnedPointer<CHuiBorderBrush> a = huiOwnedPointer;
    a->SetChanged();
//    test const T* operator -> () const
    THuiBrushLayer layer = 
    ( ( const RHuiOwnedPointer<CHuiBorderBrush> ) huiOwnedPointer )->Layer();
    CleanupStack::PopAndDestroy( brush );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerPtrL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerPtrL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerPtrL, "In TestHuiOwnerdPointerPtrL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerPtrL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerPtrL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    huiOwnedPointer.Ptr();
    CleanupStack::PopAndDestroy( brush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerRefL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerRefL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerRefL, "In TestHuiOwnerdPointerRefL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerRefL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerRefL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    huiOwnedPointer.Ref();
    CleanupStack::PopAndDestroy( brush );
    
    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerNonConstRefL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerNonConstRefL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerNonConstRefL, "In TestHuiOwnerdPointerNonConstRefL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerNonConstRefL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerNonConstRefL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    huiOwnedPointer.NonConstRef();
    CleanupStack::PopAndDestroy( brush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerSetL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerSetL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerSetL, "In TestHuiOwnerdPointerSetL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerSetL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerSetL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    CleanupStack::PopAndDestroy( brush );

    return KErrNone;
    }
// -----------------------------------------------------------------------------
// CTestUiAifCoreToolkit::TestHuiOwnerdPointerOwnershipL
// -----------------------------------------------------------------------------
//
TInt CTestUiAifCoreToolkit::TestHuiOwnerdPointerOwnershipL( CStifItemParser& /*aItem*/ )
    {

    // Print to UI
    _LIT( Ktestuiaifcoretoolkit, "testuiaifcoretoolkit" );
    _LIT( KTestHuiOwnerdPointerOwnershipL, "In TestHuiOwnerdPointerOwnershipL" );
    TestModuleIf().Printf( 0, Ktestuiaifcoretoolkit, KTestHuiOwnerdPointerOwnershipL );
    // Print to log file
    iLog->Log( KTestHuiOwnerdPointerOwnershipL );

    RHuiOwnedPointer<CHuiBorderBrush> huiOwnedPointer;
    CHuiBorderBrush* brush = CHuiBorderBrush::NewL( 0, 0, 0, 0 );
    CleanupStack::PushL( brush );
    huiOwnedPointer.Set( brush, EHuiDoesNotHaveOwnership );
    THuiOwnership ownerShip = huiOwnedPointer.Ownership();
    CleanupStack::PopAndDestroy( brush );
    
    return KErrNone;
    }

//End of file.
