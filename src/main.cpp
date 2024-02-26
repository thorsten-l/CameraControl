#include <Arduino.h>
#include <ArduinoNvs.h>

#include <alog.h>
#include <esp32_smartdisplay.h>
#include <math.h>
#include <ui/ui.h>
#include <CameraControl/CameraControl.hpp>
#include <CCUI/CCUI.hpp>
#include <CCUI/Controller/Settings.hpp>
#include <CCUI/Controller/Intervalometer.hpp>

void setup()
{
  Serial.begin(115200);

  while (!Serial.availableForWrite())
  {
    delay(100);
  }

  Serial.println("\nCameraControl, Version: " APP_VERSION "\n");
  Serial.flush();
  
  settings.initialize();
}

void loop()
{
  lv_timer_handler();

  intervalometer.handler();
  settings.handler();
  ccui.handler();

  if ( cameraControl != nullptr )
  {
    cameraControl->handler();
  }

  delay(25);
}