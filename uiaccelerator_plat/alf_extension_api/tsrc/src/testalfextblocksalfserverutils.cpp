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
* Description:  Test alfserverutils.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"

// CONSTANTS
const TInt KBufSize = 64;

// ============================ MEMBER FUNCTIONS =========================


// --------------------------------------------------------------------------
// CTestAlfExt::TestTimedValueUtil
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestTimedValueUtil( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestalftimedvalueutilitycopytimedvalue1, "In TestAlfTimedValueUtilityCopyTimedValue1");
    TestModuleIf().Printf(0, Kctestalfext, Ktestalftimedvalueutilitycopytimedvalue1);
    iLog->Log(Ktestalftimedvalueutilitycopytimedvalue1);
    
    TAlfTimedValue alfvalue( 0 );
    THuiTimedValue huivalue( 0 );
    AlfTimedValueUtility::CopyTimedValue( alfvalue, huivalue, *iInterface );
    AlfTimedValueUtility::CopyTimedValue( alfvalue, huivalue );
    AlfTimedValueUtility::CopyTimedValue( huivalue, alfvalue );

    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestTimedPointUtil
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestTimedPointUtil( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestalftimedvalueutilitycopytimedvalue2, "In TestAlfTimedValueUtilityCopyTimedValue2");
    TestModuleIf().Printf(0, Kctestalfext, Ktestalftimedvalueutilitycopytimedvalue2);
    iLog->Log(Ktestalftimedvalueutilitycopytimedvalue2);

    TAlfTimedPoint alfpoint;
    THuiTimedPoint huipoiint;
    AlfTimedPointUtility::CopyTimedPoint( alfpoint, huipoiint, *iInterface );
    AlfTimedPointUtility::CopyTimedPoint( alfpoint, huipoiint );
    AlfTimedPointUtility::CopyTimedPoint( huipoiint, alfpoint );
    return KErrNone;
    }

// --------------------------------------------------------------------------
// CTestAlfExt::TestFileTokenUtil
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestFileTokenUtil( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestalftimedvalueutilitycopytimedvalue3, "In TestAlfTimedValueUtilityCopyTimedValue3");
    TestModuleIf().Printf(0, Kctestalfext, Ktestalftimedvalueutilitycopytimedvalue3);
    iLog->Log(Ktestalftimedvalueutilitycopytimedvalue3);

    _LIT8( KFileName, "c:\\testframework\\tctestalfextalfserverutils.cfg" );
    TBuf8<KBufSize> buf( KFileName );
    RFile file;
    TRAPD( err, AlfFileTokenUtility::OpenFileForTokenL( file, buf ) );
    if ( err == KErrNone )
        {
        return KErrNone;
        }
    return KErrNone;
    }


// End of file

