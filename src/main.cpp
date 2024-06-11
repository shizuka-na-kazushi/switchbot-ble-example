#include <Arduino.h>
#include "SwitchbotApp.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("board started!");
  
  SwitchbotApp.setup();
}

void loop()
{
}
