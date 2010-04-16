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

#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <sensrvchannelfinder.h> 
#include <sensrvchannel.h> 
#include <sensrvdatalistener.h>

NONSHARABLE_CLASS(CSensorListener) : public CBase
    {
    public:
        static CSensorListener* NewL(MSensrvDataListener* aDataListener, TUint32 aSensorType);
        virtual ~CSensorListener();
    protected:
        void ConstructL(TUint32 aSensorType);
        CSensorListener(MSensrvDataListener* aDataListener);
    private:
        MSensrvDataListener* iDataListener;
        CSensrvChannel* iSensrvChannel;
    };

#endif