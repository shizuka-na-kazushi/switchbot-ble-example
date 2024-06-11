

#include "SensorActions.h"
#include "SwitchbotApp.h"

static void printPayload(uint8_t *pPayload, size_t payloadLength)
{
#define PAYLOAD_BUFF_MAX (128)

  static char buff[PAYLOAD_BUFF_MAX];
  memset(buff, 0, PAYLOAD_BUFF_MAX);

  Serial.print("payload (");
  Serial.print(payloadLength);
  Serial.println(") ");
  for (int i = 0; i < payloadLength && i < PAYLOAD_BUFF_MAX - 1; i++)
  {
    // Serial.print(String(pPayload[i], 16).c_str());
    snprintf(buff + i * 3, PAYLOAD_BUFF_MAX - i * 3, "%02x:", pPayload[i]);
  }
  Serial.println(buff);
}

void MotionSensorAction::onBroadcastMessage(MotionSensorBroadcastMessage *pMessage)
{
  Serial.print(">>>  device type: ");
  Serial.print(String(pMessage->deviceType, 16).c_str());
  Serial.print(", lightIntensity: ");
  Serial.print(pMessage->lightIntensity);
  Serial.print(", sensingDistance: ");
  Serial.print(pMessage->sensingDistance);
  Serial.print(", (pirState) moving state: ");
  Serial.print(pMessage->pirState);
  Serial.print(", ledState: ");
  Serial.print(pMessage->ledState);
  Serial.println("");
}

void ContactSensorAction::onBroadcastMessage(ContactSensorBroadcastMessage *pMessage)
{
  Serial.print(">>> device type: ");
  Serial.print(String(pMessage->deviceType, 16).c_str());
  Serial.print(", open state: ");
  Serial.print(pMessage->openState);
  Serial.print(", moving state: ");
  Serial.print(pMessage->pirState);
  Serial.print(", blight: ");
  Serial.print(pMessage->blight);
  Serial.println("");

  ledDoor.setLight((pMessage->openState != 0));
  ledMove.setLight((pMessage->pirState != 0));
}
