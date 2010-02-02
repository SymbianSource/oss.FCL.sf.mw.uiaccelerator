/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*
*/

#ifndef __THEMEREPOSITORYLISTENER_H__
#define __THEMEREPOSITORYLISTENER_H__

#include <centralrepository.h>

class CThemeRepositoryListener : public CActive
    {
    public:
        static CThemeRepositoryListener* NewL(TBool* aValueToChange);
        virtual ~CThemeRepositoryListener();
        void RunL();
        void DoCancel();
        void IssueRequest();
        void GPuMemLow(TBool aLow);
    protected:
        void ConstructL();
    private:
        CThemeRepositoryListener(TBool* aValueToChange);
    
        CRepository* iThemesRepository;
        TBool* iValueToChange;
        TInt iPreviousValue;
    };
    
#endif
