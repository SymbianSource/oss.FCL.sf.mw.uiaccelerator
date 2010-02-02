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