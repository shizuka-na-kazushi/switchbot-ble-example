
#ifndef __SENSOR_ACTIONS_H__
#define __SENSOR_ACTIONS_H__

#include "SwitchbotDevices.h"

class CLedIndicator {
protected:
  uint8_t pin = 0;

public:
  void setup(uint8_t _pin) {
    pin = _pin;
    pinMode(pin, OUTPUT);
  }
  void setLight(boolean enable) {
    digitalWrite(pin, enable ? 1 : 0);
  }
};

class MotionSensorAction : public SwitchbotMotionSensorBroadcastHandler
{
public:
  virtual void onBroadcastMessage(MotionSensorBroadcastMessage *pMessage);
};

#define LED_PIN_DOOR    (12)
#define LED_PIN_MOVE    (13)

class ContactSensorAction : public SwitchbotContactSensorBroadcastHandler
{
protected:
  CLedIndicator ledDoor;
  CLedIndicator ledMove;
public:
  ContactSensorAction() {
    ledDoor.setup(LED_PIN_DOOR);
    ledMove.setup(LED_PIN_MOVE);
  }
  virtual void onBroadcastMessage(ContactSensorBroadcastMessage *pMessage);
};

#endif // !__SENSOR_ACTIONS_H__