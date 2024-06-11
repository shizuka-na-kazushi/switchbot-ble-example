
#include "SwitchbotApp.h"
#include "SwitchbotAdvCallbacks.h"
#include "SensorActions.h"
#include "DeviceAddr.h"

CLedIndicator LedIndicator;
CSwitchbotApp SwitchbotApp;

void CSwitchbotApp::createDevices()
{
  m_pContactSensor = new SwitchbotContactSensor(contactSensorAddr);
  m_pContactSensor->addBroadcastHandler(new ContactSensorAction());
 
  // m_pMotionSensor = new SwitchbotMotionSensor(motionSensorAddr);
  // m_pMotionSensor->addBroadcastHandler(new MotionSensorAction());

  /** add these devices to internal list */
  devices[numOfDevice++] = m_pContactSensor;
  // devices[numOfDevice++] = m_pMotionSensor;
}

void CSwitchbotApp::doScan()
{
  BLEScan *pBLEScan = BLEDevice::getScan(); // create new scan

  pBLEScan->setAdvertisedDeviceCallbacks(new SwitchbotAdvCallbacks(devices, numOfDevice), true);
  pBLEScan->setActiveScan(false);                    // active scan uses more power, but get results faster
  BLEScanResults foundDevices = pBLEScan->start(0); // scanTime = 0, = infinite
}

void CSwitchbotApp::setup()
{
  BLEDevice::init("");
  createDevices();
  doScan();
}

