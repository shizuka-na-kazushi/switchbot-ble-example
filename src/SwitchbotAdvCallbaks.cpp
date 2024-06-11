
#include "SwitchbotAdvCallbacks.h"

void SwitchbotAdvCallbacks::onResult(BLEAdvertisedDevice advertisedDevice)
{
  BLEAddress addr = advertisedDevice.getAddress();
  for (int i = 0; i < numOfDevice; i++)
  {
    if (addr.equals(devices[i]->m_address))
    {
      callDevice(devices[i], advertisedDevice.getPayload(), advertisedDevice.getPayloadLength());
    }
  }
}

typedef struct
{
  uint8_t length;
  uint8_t type;
  uint8_t payload[];
} BlePacketAdvStruct;

void SwitchbotAdvCallbacks::callDevice(SwitchbotBaseDevice *device, uint8_t *pPayload, size_t payloadLength)
{
  if (!device)
  {
    return;
  }

  BlePacketAdvStruct *packetAdvStruct = (BlePacketAdvStruct *)pPayload;
  while (0 < payloadLength)
  {
    size_t len = packetAdvStruct->length;

    switch(packetAdvStruct->type) {
      case 0x01:
        /** nothing todo */
        break;
      case 0xff:
        /** ADV_IND */
        device->onBroadcastAdvIndMessage(packetAdvStruct->payload, len);
        break;
      case 0x16:
        /** Scan_RSP */
        device->onBroadcastScanRspMessage(packetAdvStruct->payload, len);
        break;
      default:
        /** unknown type*/
        break;
    }

    pPayload += (len + 1);
    payloadLength -= (len + 1);
    packetAdvStruct = (BlePacketAdvStruct *)pPayload;
  }
}
