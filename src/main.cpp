#include <Arduino.h>
#include <ArduinoNvs.h>

#include <CCUI/CCUI.hpp>
#include <CCUI/Controller/Intervalometer.hpp>
#include <CCUI/Controller/Settings.hpp>
#include <CameraControl/CameraControl.hpp>
#include <alog.h>
#include <esp32_smartdisplay.h>
#include <math.h>
#include <ui/ui.h>

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
  ccui.initialize();
}

void loop()
{
  lv_timer_handler();

  intervalometer.handler();
  settings.handler();
  ccui.handler();

  if (cameraControl != nullptr)
  {
    cameraControl->handler();
  }

  delay(25);
}

void startBluetooth(lv_event_t *e)
{
  ALOG_D("startBluetooth");
  if (cameraControl == nullptr)
  {
    ccui.disableButton(ui_StartWiFiButton);
    cameraControl = CameraControl::getInstance(CameraControlType::BT);
    ALOG_D("Camera control API name: %s", cameraControl->apiName().c_str());
  }
}

void startWiFi(lv_event_t *e)
{
  ALOG_D("startWiFi");
  if (cameraControl == nullptr)
  {
    ccui.disableButton(ui_StartBluetoothButton);
    cameraControl = CameraControl::getInstance(CameraControlType::CCAPI);
    lv_obj_set_parent(ui_BTRemoteTabPage, ui_WiFiRemoteTabPage);
    lv_obj_set_parent(ui_BTIntervalTabPage, ui_WifiIntervalTabPage);
    ALOG_D("Camera control API name: %s", cameraControl->apiName().c_str());
  }
}
