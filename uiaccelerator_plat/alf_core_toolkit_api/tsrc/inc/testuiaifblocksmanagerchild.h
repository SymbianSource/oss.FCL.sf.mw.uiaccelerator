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
* Description:  For test alf core toolkit api modules
*
*/


#ifndef TESTUIAIFBLOCKSMANAGERCHILD_H
#define TESTUIAIFBLOCKSMANAGERCHILD_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <uiacceltk/huianimatedtexture.h>
#include <uiacceltk/huitexturemanager.h>

// CLASS DECLARATION

/**
 *  CTestUiAifBlocksManagerChild
 * 
 */
class CTestUiAifBlocksManagerChild : public CHuiTextureManager
    {
public:

    CTestUiAifBlocksManagerChild();
    virtual ~CTestUiAifBlocksManagerChild();


public: // CHuiTextureManager
    virtual void RestoreL();
    virtual void RemoveTexture(CHuiTexture& aTexture);
    virtual void AppendTextureL(CHuiTexture* aTexture, TInt aId);
    virtual CHuiTexture& CreateTextureL(CFbsBitmap& aBitmap, const CFbsBitmap* aMask, 
                                        THuiTextureUploadFlags aFlags, TInt aId);
    virtual TBool Release();


protected: // CHuiTextureManager
    
    virtual void RunL();
    virtual void DoCancel();
    virtual TInt RunError(TInt aError);
    
    
private:
    
    CHuiEnv* gEnv;
    
    };

#endif // TESTUIAIFBLOCKSMANAGERCHILD_H
