#include <Arduino.h>
#include <ArduinoNvs.h>

#include <alog.h>
#include <bt/BluetoothController.h>
#include <CCUI/CCUI.hpp>
#include <esp32_smartdisplay.h>
#include <math.h>
#include <Settings/Settings.hpp>
#include <ui/ui.h>

#define APPNVS_WIFI_API_TYPE "wifiapi"

Settings settings;

CameraControlType wifiCameraControlType;

static ArduinoNvs appNvs;

static const lv_point_t full_touch_screen[] = {{0, 0}, {239, 160}, {120, 319}};
static const lv_point_t predef_touch_screen[] = {
    {15, 9}, {227, 151}, {122, 291}};

static const lv_point_t touch_points_ref[] = {{16, 16}, {223, 160}, {120, 303}};
static const char *touchPointNames[] = {"TOP LEFT", "MID RIGHT",
                                        "BOTTOM CENTER", "-"};
static lv_point_t touchPoint;
static int touchPointIndex;
static bool doTouchCalibration = false;
static time_t restartControllerTimestamp;
static time_t eraseAllSettingsTimestamp;
static lv_point_t touch_points_cal[6];

int pointDistance(const lv_point_t *p1, const lv_point_t *p2)
{
  return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

void calPointPressed(lv_event_t *e)
{
  lv_point_t touchPoint;

  lv_indev_get_point(lv_event_get_indev(e), &touchPoint);
  ALOG_D("touch point : [%d|%d]", touchPoint.x, touchPoint.y);
  if (doTouchCalibration && touchPointIndex >= 0 && touchPointIndex < 3)
  {
    int distance =
        pointDistance(&touchPoint, &touch_points_ref[touchPointIndex]);
    ALOG_D("  ref touch point : [%d|%d] distance : %d",
           touch_points_ref[touchPointIndex].x,
           touch_points_ref[touchPointIndex].y, distance);

    if (distance < 40)
    {
      touch_points_cal[touchPointIndex] = {touchPoint.x, touchPoint.y};
      touchPointIndex++;
      lv_label_set_text(ui_CalInfoLabel2, touchPointNames[touchPointIndex]);

      if (touchPointIndex == 3)
      {
#ifdef ALOG_LEVEL
        for (int i = 0; i < 3; i++)
        {
          ALOG_D("touch point cal[%d] : [%d|%d]", i, touch_points_cal[i].x,
                 touch_points_cal[i].y);
        }
#endif
        touch_calibration_data = smartdisplay_compute_touch_calibration(
            touch_points_ref, touch_points_cal);
        appNvs.setBlob("touchcal", (uint8_t *)touch_points_cal, 12, true);
        ccui.enableButton(ui_CalStartButton);
      }
    }
  }
}

void calStartButtonClicked(lv_event_t *e)
{
  ALOG_D("calStartButtonClicked");

  // uncalibrated
  touch_calibration_data = smartdisplay_compute_touch_calibration(
      full_touch_screen, full_touch_screen);

  touchPointIndex = 0;
  doTouchCalibration = true;

  lv_label_set_text(ui_CalInfoLabel2, touchPointNames[0]);
  ccui.disableButton(ui_CalStartButton);
}

void ccApiCheckboxClicked(lv_event_t *e)
{
  ALOG_D("ccApiCheckboxClicked");
  lv_obj_clear_state(ui_ptpCheckbox, LV_STATE_CHECKED);
  wifiCameraControlType = CameraControlType::CCAPI;
  appNvs.setInt(APPNVS_WIFI_API_TYPE, (uint64_t)wifiCameraControlType, true);
}

void ptpCheckboxClicked(lv_event_t *e)
{
  ALOG_D("ptpCheckboxClicked");
  lv_obj_clear_state(ui_ccApiCheckbox, LV_STATE_CHECKED);
  wifiCameraControlType = CameraControlType::PTP;
  appNvs.setInt(APPNVS_WIFI_API_TYPE, (uint64_t)wifiCameraControlType, true);
}

void restartControllerButtonClicked(lv_event_t *e)
{
  ALOG_D("restartControllerButtonClicked");
  ccui.showHandlerMessageBox(
    CCUIMessageBoxType::INFO,"Restarting Controller", false);
  restartControllerTimestamp = millis();
}

static void resetAllSettingsMessageBoxEventCallback(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_current_target(e);
  const char *result = lv_msgbox_get_active_btn_text(obj);
  ALOG_D("Button %s clicked", result);
  lv_msgbox_close(obj);

  if (strcmp("YES", result) == 0)
  {
    ccui.showHandlerMessageBox(
      CCUIMessageBoxType::INFO, "Erasing all settings.", false);
    eraseAllSettingsTimestamp = millis();
  }
}

void resetAllSettingsButtonClicked(lv_event_t *e)
{
  ALOG_D("resetAllSettingsButtonClicked");

  ccui.showHandlerMessageBoxNOYES(
    CCUIMessageBoxType::WARNING,"Erase all settings?", true,
    resetAllSettingsMessageBoxEventCallback);
}

// class -----------------------------------------------------------

void Settings::restartController()
{
  ALOG_D("Restarting Controller");
  ESP.restart();
  delay(10000);
}

void Settings::initialize()
{
  pinMode(RGB_LED_R, OUTPUT);
  pinMode(RGB_LED_G, OUTPUT);
  pinMode(RGB_LED_B, OUTPUT);
  pinMode(0, INPUT_PULLUP);
  digitalWrite(RGB_LED_R, true);
  digitalWrite(RGB_LED_G, true);
  digitalWrite(RGB_LED_B, true);

  NVS.begin();

  if (!appNvs.begin("appNvs"))
  {
    ALOG_D("NVS for appNvs not initialized.");
    digitalWrite(RGB_LED_R, false);
  }

  restartControllerTimestamp = 0l;
  eraseAllSettingsTimestamp = 0l;

  printf("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)\n", ESP.getChipModel(),
         ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
  printf("Free heap: %d bytes\n", ESP.getFreeHeap());
  printf("Free PSRAM: %d bytes\n", ESP.getPsramSize());
  printf("SDK version: %s\n", ESP.getSdkVersion());
  printf("LV version: %d.%d.%d\n", lv_version_major(), lv_version_minor(),
         lv_version_patch());
  printf("ESP32 Smart Display version: " ESP32_SMARTDISPLAY_VERSION "\n\n");

  if (appNvs.getBlob("touchcal", (uint8_t *)touch_points_cal, 12))
  {
    ALOG_D("using NVS stored touch point calibration");
    touch_calibration_data = smartdisplay_compute_touch_calibration(
        touch_points_ref, touch_points_cal);
  }
  else
  {
    ALOG_D("using predefined touch point calibration");
    touch_calibration_data = smartdisplay_compute_touch_calibration(
        full_touch_screen, predef_touch_screen);
  }

  cameraControl = CameraControl::getInstance(CameraControlType::BT);
  ALOG_D("Camera control API name: %s", cameraControl->apiName().c_str());

  smartdisplay_init();
  auto disp = lv_disp_get_default();
  lv_disp_set_rotation(disp, LV_DISP_ROT_NONE);
  ui_init();
  lv_label_set_text(ui_AppVersionLabel, APP_VERSION);

  if (appNvs.getInt(APPNVS_WIFI_API_TYPE) == 0l)
  {
    wifiCameraControlType = CameraControlType::CCAPI;
    lv_obj_clear_state(ui_ptpCheckbox, LV_STATE_CHECKED);
    lv_obj_add_state(ui_ccApiCheckbox, LV_STATE_CHECKED);
  }
  else
  {
    wifiCameraControlType = CameraControlType::PTP;
    lv_obj_clear_state(ui_ccApiCheckbox, LV_STATE_CHECKED);
    lv_obj_add_state(ui_ptpCheckbox, LV_STATE_CHECKED);
  }  
}

void Settings::handler()
{
  if (restartControllerTimestamp > 0l &&
      (millis() - restartControllerTimestamp) > 1000)
  {
    restartController();
  }

  if (eraseAllSettingsTimestamp > 0l &&
      (millis() - eraseAllSettingsTimestamp) > 1000)
  {
    ALOG_D("Ereasing all NVS data.");
    ArduinoNvs nvs;
    nvs.begin();
    nvs.eraseAll();
    nvs.close();
    appNvs.eraseAll();
    delay(1000);
    restartController();
  }  
}
