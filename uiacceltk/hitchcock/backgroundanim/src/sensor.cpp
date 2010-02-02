#include <sensrvaccelerometersensor.h>

#include "sensor.h"


CSensorListener* CSensorListener::NewL(MSensrvDataListener* aDataListener, TUint32 aSensorType)
    {
    CSensorListener* self = new (ELeave) CSensorListener(aDataListener);
    CleanupStack::PushL(self);
    self->ConstructL(aSensorType);
    CleanupStack::Pop();
    return self;    
    }
    
void CSensorListener::ConstructL(TUint32 aSensorType)
    {
    CSensrvChannelFinder* sensrvChannelFinder = CSensrvChannelFinder::NewLC();
 
    RSensrvChannelInfoList channelInfoList;
    CleanupClosePushL(channelInfoList);
 
    TSensrvChannelInfo mySearchConditions;
 
    mySearchConditions.iChannelType = aSensorType;
    
    sensrvChannelFinder->FindChannelsL(channelInfoList,mySearchConditions);
 
    if (channelInfoList.Count())
        {
        iSensrvChannel = CSensrvChannel::NewL(channelInfoList[0]);
        iSensrvChannel->OpenChannelL();
        iSensrvChannel->StartDataListeningL( iDataListener, 1,1,0);
        }
 
    channelInfoList.Close();
    CleanupStack::Pop( &channelInfoList );
    CleanupStack::PopAndDestroy( sensrvChannelFinder );
    }
    
CSensorListener::CSensorListener(MSensrvDataListener* aDataListener) : iDataListener(aDataListener)
    {
    }
    
CSensorListener::~CSensorListener()
    {
    if (iSensrvChannel)
        {
        iSensrvChannel->StopDataListening(); 
        iSensrvChannel->CloseChannel();
        }
        
    delete iSensrvChannel;
    }
        


