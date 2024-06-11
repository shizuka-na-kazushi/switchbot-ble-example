
#ifndef __SWITCHBOT_DEVICES_H__
#define __SWITCHBOT_DEVICES_H__

#include <Arduino.h>
#include <BLEDevice.h>

#define SWITCHOBT_MAX_DEVICES (8)

class SwitchbotBaseDevice
{
public:
  BLEAddress m_address;

  SwitchbotBaseDevice(BLEAddress addr) : m_address(addr) {}
  virtual ~SwitchbotBaseDevice(){};

  virtual void onBroadcastScanRspMessage(uint8_t *pMessage, size_t length) {};
  virtual void onBroadcastAdvIndMessage(uint8_t *pMessage, size_t length) {};
};

/*********************************************************************************************
 *
 * SwitchbotContactSensor
 *
 ********************************************************************************************/

#pragma pack(1)
typedef struct
{
  /* Byte0 */
  uint8_t deviceType : 7;
  uint8_t encrypt : 1;
  /* Byte1 */
  uint8_t reserve1 : 6;
  uint8_t pirState : 1;
  uint8_t scopeTested : 1;
  /* Byte2 */
  uint8_t battery : 7;
  uint8_t reserve2 : 1;
  /* Byte3 */
  uint8_t blight : 1;    /* 0: dark, 1: blight */
  uint8_t openState : 2; /* 0: door close, 1: door open, 2: timeout not close */
  uint8_t reserve3 : 3;
  uint8_t hiBitOfHalTime : 1;
  uint8_t hiBitOfPirTime : 1;
  /* Byte4, 5 */
  uint16_t ripTime;
  /* Byte6, 7 */
  uint16_t halTime;
  /* Byte8 */
  uint8_t countOfButton : 4;
  uint8_t countOfGoOut : 2;
  uint8_t countOfEntry : 2;
} ContactSensorBroadcastMessage;

class SwitchbotContactSensorBroadcastHandler
{
public:
  virtual void onBroadcastMessage(ContactSensorBroadcastMessage *pMessage) = 0;
};

class SwitchbotContactSensor : public SwitchbotBaseDevice
{
protected:
  SwitchbotContactSensorBroadcastHandler *m_pHandler;

public:
  SwitchbotContactSensor(BLEAddress addr) : SwitchbotBaseDevice(addr), m_pHandler(nullptr) {}
  virtual ~SwitchbotContactSensor(){};

public:
  void addBroadcastHandler(SwitchbotContactSensorBroadcastHandler *pHandler) { m_pHandler = pHandler; }
  virtual void onBroadcastScanRspMessage(uint8_t *pMessage, size_t length);
};

/*********************************************************************************************
 *
 * SwitchbotMotionSensor
 *
 ********************************************************************************************/

#pragma pack(1)
typedef struct
{
  /* Byte0 */
  uint8_t deviceType : 7;
  uint8_t encrypt : 1;
  /* Byte1 */
  uint8_t reserve1 : 6;
  uint8_t pirState : 1; /* PIR State 0: No one moves 1: Someone is moving */
  uint8_t scopeTested : 1;
  /* Byte2 */
  uint8_t battery : 7;
  uint8_t reserve2 : 1;
  /* Byte3, 4 */
  uint16_t pirTime; // need to swap bytes
  /* Byte5 */
  uint8_t lightIntensity : 2;  /* Light intensity 00:Rserve 01:dark 10:bright 11:Reserve */
  uint8_t sensingDistance : 2; /* Sensing distance 00:Long 01:Middle 10:Short 11:Reserve */
  uint8_t iotState : 1;        /* IOT state 0:disable 1:enable */
  uint8_t ledState : 1;        /* LED state 0:disable 1:enable */
  uint8_t reserve3 : 1;
  uint8_t hiBitOfPirTime : 1; /* Since the last trigger PIR time（s）Highest bit(*65536) */
} MotionSensorBroadcastMessage;

class SwitchbotMotionSensorBroadcastHandler
{
public:
  virtual void onBroadcastMessage(MotionSensorBroadcastMessage *pMessage) = 0;
};

class SwitchbotMotionSensor : public SwitchbotBaseDevice
{
protected:
  SwitchbotMotionSensorBroadcastHandler *m_pHandler;

public:
  SwitchbotMotionSensor(BLEAddress addr) : SwitchbotBaseDevice(addr), m_pHandler(nullptr) {}
  virtual ~SwitchbotMotionSensor(){};

  void addBroadcastHandler(SwitchbotMotionSensorBroadcastHandler *pHandler) { m_pHandler = pHandler; }
  virtual void onBroadcastScanRspMessage(uint8_t *pMessage, size_t length);
};

#endif // !__SWITCHBOT_DEVICES_H__
