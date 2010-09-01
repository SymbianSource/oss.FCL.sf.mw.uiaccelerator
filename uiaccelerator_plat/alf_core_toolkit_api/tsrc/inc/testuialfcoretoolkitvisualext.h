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
* Description:  The derived class of CHuiVisual for testing the protected method
*
*/


#ifndef C_TESTPLATALFCORETOOLKITVISUALEXT_H
#define C_TESTPLATALFCORETOOLKITVISUALEXT_H

// INCLUDES
#include <uiacceltk\huivisual.h>

class CTestUiAifCoreToolkit;

// CLASS DECLARATION

/**
 *  Ctestplatalfcoretoolkitvisualext
 * 
 */
class CTestPlatALFCoreToolkitVisualExt : public CHuiVisual
    {
public:
    CTestPlatALFCoreToolkitVisualExt( MHuiVisualOwner& aOwner );
    
    friend CTestUiAifCoreToolkit;
    };

#endif // C_TESTPLATALFCORETOOLKITVISUALEXT_H
