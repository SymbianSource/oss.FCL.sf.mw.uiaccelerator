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

#include <eikenv.h>

#include "testuiaifblocksmanagerchild.h"

CTestUiAifBlocksManagerChild::CTestUiAifBlocksManagerChild():CHuiTextureManager(*gEnv)
    {
    // No implementation required
    }

CTestUiAifBlocksManagerChild::~CTestUiAifBlocksManagerChild()
    {
    // No implementation required
    }

void CTestUiAifBlocksManagerChild::RestoreL()
    {   
    }

void CTestUiAifBlocksManagerChild::RemoveTexture(CHuiTexture& /*aTexture*/)
    {   
    }

void CTestUiAifBlocksManagerChild::AppendTextureL(CHuiTexture* /*aTexture*/, TInt /*aId*/)
    {   
    }

CHuiTexture& CTestUiAifBlocksManagerChild::CreateTextureL(
    CFbsBitmap& /*aBitmap*/, const CFbsBitmap* /*aMask*/, THuiTextureUploadFlags /*aFlags*/, TInt /*aId*/)
    {
    CHuiTexture * aTexture = NULL;
    return *aTexture;
    }

TBool CTestUiAifBlocksManagerChild::Release()
    {   
    return ETrue;
    }

void CTestUiAifBlocksManagerChild::RunL()
    {   
    }

void CTestUiAifBlocksManagerChild::DoCancel()
    {   
    }

TInt CTestUiAifBlocksManagerChild::RunError(TInt /*aError*/)
    {
    return KErrNone;    
    }
