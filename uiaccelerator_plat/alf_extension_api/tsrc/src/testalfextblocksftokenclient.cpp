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
* Description:  Test ftokenclient.h
 *
*/


// [INCLUDE FILES]
#include "testalfext.h"

// CONSTANTS
const TInt KBufSize = 64;

// ============================ MEMBER FUNCTIONS =========================

// --------------------------------------------------------------------------
// CTestAlfExt::TestRFTokenClientFuncL
// --------------------------------------------------------------------------
//
TInt CTestAlfExt::TestRFTokenClientFuncL( CStifItemParser& /*aItem*/ )
    {
    _LIT(Kctestalfext, "CTestAlfExt");
    _LIT(Ktestrftokenclientconnect, "In TestRFTokenClientConnect");
    TestModuleIf().Printf(0, Kctestalfext, Ktestrftokenclientconnect);
    iLog->Log(Ktestrftokenclientconnect);

    RFTokenClient rtoken;
    CleanupClosePushL( rtoken );
    User::LeaveIfError( rtoken.Connect() );
    _LIT( KFileName, "c:\\testframework\\ui_testalfextalfbrushhandlers.cfg" );
    TBuf<KBufSize> fileName( KFileName );
    TInt64 token = 0;
    TPckg<TInt64> tokenbuf(token); 
    token = 1;
    TPckg<TInt64> tokenbufexist(token);
    TSecureId consumerSecId(0x10282845);
    TSecurityPolicy policy( consumerSecId );
    TUid id = { 0x00000001 };
    
    rtoken.GenerateToken( fileName, policy, tokenbuf );
    rtoken.GenerateToken( tokenbufexist, policy, tokenbuf );
    rtoken.GenerateToken( fileName, id, tokenbuf );
    rtoken.GenerateToken( tokenbufexist, id, tokenbuf );
    RFile rfile;
    TInt err = rfile.Open( CEikonEnv::Static()->FsSession(), fileName, EFileRead );
    if ( err != KErrNone )
        {
        return KErrNone;
        }
    rtoken.GenerateToken( rfile, id, tokenbuf );
    rtoken.GenerateToken( rfile, policy, tokenbuf );
    rtoken.OpenFileForToken( rfile, tokenbuf );
    rfile.Close();
    CleanupStack::PopAndDestroy( &rtoken );

    return KErrNone;
    }


// End of file



