
#ifndef __SWITCHBOT_APP_H__
#define __SWITCHBOT_APP_H__

#include <Arduino.h>
#include "SwitchbotDevices.h"

#define SBA_DEVICES_NUM SWITCHOBT_MAX_DEVICES

class CSwitchbotApp
{
protected:
  SwitchbotBaseDevice *devices[SBA_DEVICES_NUM];
  uint32_t numOfDevice = 0;

public:
  void doScan();
  void onScanStart();
  void onScanEnded();

  /** specific devices */
  SwitchbotContactSensor *m_pContactSensor = nullptr;
  SwitchbotMotionSensor *m_pMotionSensor = nullptr;

  /** device related operations */
  void createDevices();

public:
  CSwitchbotApp(){};
  virtual ~CSwitchbotApp(){};

  void setup();
  void loop();
};

extern CSwitchbotApp SwitchbotApp;

#endif // !__SWITCHBOT_APP_H__
