#include <Arduino.h>
#include <CCUI/CCUI.hpp>
#include <CameraControl/CameraControl.hpp>
#include <alog.h>
#include <ui/ui.h>

#include <Esp.h>
#include <WiFi.h>

#include <CCUI/Controller/WiFiConnect.hpp>

// UI events ----------------------------------------------------------------

void wifiScreenLoadStart(lv_event_t *e)
{
  ALOG_D("wifiScreenLoadStart");

  std::shared_ptr<WifiCameraControl> wifiCameraControl =
      std::static_pointer_cast<WifiCameraControl>(cameraControl);

  String v = appNvs.getString("wssid");
  String ssid = (v != nullptr && v.length() > 0) ? v : "Canon Camera";

  v = appNvs.getString("wpass");
  String password = (v != nullptr && v.length() > 0) ? v : "12345678";

  v = appNvs.getString("caddr");
  String cameraIpAddress =
      (v != nullptr && v.length() > 0)
          ? v
          : wifiCameraControl->getDefaultCameraClientIpAddress();

  v = appNvs.getString("cport");
  String cameraIpPort = (v != nullptr && v.length() > 0)
                            ? v
                            : wifiCameraControl->getDefaultCameraClientIpPort();
  //
  lv_dropdown_set_options(ui_WiFiSsidDropdown, ssid.c_str());
  lv_textarea_set_text(ui_WiFiPasswordTextArea, password.c_str());
  lv_textarea_set_text(ui_WiFiCameraIpAddressTextArea, cameraIpAddress.c_str());
  lv_textarea_set_text(ui_WiFiCameraIpPortTextArea, cameraIpPort.c_str());
}

void wifiScreenLoaded(lv_event_t *e)
{
  ALOG_D("wifiScreenLoaded");
}

void wifiPasswordTextAreaClicked(lv_event_t *e)
{
  ALOG_D("wifiPasswordTextAreaClicked");
  lv_keyboard_set_textarea(ui_wifiSettingsKeyboard, ui_WiFiPasswordTextArea);
  lv_keyboard_set_mode(ui_wifiSettingsKeyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
  lv_obj_set_pos(ui_wifiSettingsContainer, 0, 0);
  lv_obj_clear_flag(ui_wifiSettingsKeyboard, LV_OBJ_FLAG_HIDDEN);
}

void wifiCameraIpAddressTextAreaClicked(lv_event_t *e)
{
  ALOG_D("wifiCameraIpAddressTextAreaClicked");
  lv_keyboard_set_textarea(ui_wifiSettingsKeyboard,
                           ui_WiFiCameraIpAddressTextArea);
  lv_keyboard_set_mode(ui_wifiSettingsKeyboard, LV_KEYBOARD_MODE_NUMBER);
  lv_obj_set_pos(ui_wifiSettingsContainer, 0, 0);
  lv_obj_clear_flag(ui_wifiSettingsKeyboard, LV_OBJ_FLAG_HIDDEN);
}

void wifiCameraIpPortTextAreaClicked(lv_event_t *e)
{
  ALOG_D("wifiCameraIpPortTextAreaClicked");
  lv_keyboard_set_textarea(ui_wifiSettingsKeyboard,
                           ui_WiFiCameraIpPortTextArea);
  lv_keyboard_set_mode(ui_wifiSettingsKeyboard, LV_KEYBOARD_MODE_NUMBER);
  lv_obj_set_pos(ui_wifiSettingsContainer, 0, -64);
  lv_obj_clear_flag(ui_wifiSettingsKeyboard, LV_OBJ_FLAG_HIDDEN);
}

void wifiKeyboardCancelClicked(lv_event_t *e)
{
  ALOG_D("wifiKeyboardCancelClicked");
  lv_obj_set_pos(ui_wifiSettingsContainer, 0, 0);
  lv_obj_add_flag(ui_wifiSettingsKeyboard, LV_OBJ_FLAG_HIDDEN);
}

void wifiKeyboardReadyClicked(lv_event_t *e)
{
  ALOG_D("wifiKeyboardReadyClicked");
  lv_obj_set_pos(ui_wifiSettingsContainer, 0, 0);
  lv_obj_add_flag(ui_wifiSettingsKeyboard, LV_OBJ_FLAG_HIDDEN);
}

void wifiNetworkScan(lv_event_t *e)
{
  ALOG_D("WiFi-Scan gestartet...");
  int n = WiFi.scanNetworks();
  ALOG_D("Anzahl gefundener Netzwerke: %d", n);

  for (int i = 0; i < n; ++i)
  {
    ALOG_D("%d %s (ch %d, %d dBm)", i + 1, WiFi.SSID(i).c_str(),
           WiFi.channel(i), WiFi.RSSI(i));

    if (strstr(lv_dropdown_get_options(ui_WiFiSsidDropdown),
               WiFi.SSID(i).c_str()) == nullptr)
    {
      ALOG_D("Adding %s", WiFi.SSID(i).c_str());
      lv_dropdown_add_option(ui_WiFiSsidDropdown, WiFi.SSID(i).c_str(), 1);
    }
  }

  ALOG_D("WiFi-Scan abgeschlossen.");
}

void wifiNetworkScanClicked(lv_event_t *e)
{
  ALOG_D("wifiRescanClicked");
  static const char *buttons[] = {""};
  ccui.showTaskMessageBox("WiFi",
                          "Scanning WiFi networks.\nPlease wait a few seconds.",
                          false, wifiNetworkScan, buttons);
}

void wifiConnectClicked(lv_event_t *e)
{
  ALOG_D("wifiConnectClicked");
  static char buffer[64];

  lv_dropdown_get_selected_str(ui_WiFiSsidDropdown, buffer, 63);
  String ssid = String(buffer);

  String password = String(lv_textarea_get_text(ui_WiFiPasswordTextArea));
  String cameraIpAddress =
      String(lv_textarea_get_text(ui_WiFiCameraIpAddressTextArea));
  String cameraIpPort =
      String(lv_textarea_get_text(ui_WiFiCameraIpPortTextArea));

  ALOG_D("WiFi SSID = %s", ssid.c_str());
  ALOG_D("WiFi PASS = %s", password.c_str());
  ALOG_D("WiFi CADDR = %s", cameraIpAddress.c_str());
  ALOG_D("WiFi CPORT = %s", cameraIpPort.c_str());

  ALOG_D("writeConfig");
  appNvs.setString("wssid", ssid);
  appNvs.setString("wpass", password);
  appNvs.setString("caddr", cameraIpAddress);
  appNvs.setString("cport", cameraIpPort);

  std::shared_ptr<WifiCameraControl> wifiCameraControl =
      std::static_pointer_cast<WifiCameraControl>(cameraControl);

  wifiCameraControl->setCameraClientIpAddress(cameraIpAddress);
  wifiCameraControl->setCameraClientIpPort(cameraIpPort);
  if ( wifiCameraControl->connect(ssid, password))
  {
    lv_label_set_text(ui_WifiCameraConnectLabel, cameraControl->cameraName().c_str());
    lv_textarea_set_text(ui_CameraNameTextArea, wifiCameraControl->cameraName().c_str());
    lv_textarea_set_text(ui_CameraMacAddressTextArea, wifiCameraControl->cameraMacAddress().c_str());
    lv_textarea_set_text(ui_CameraSerialNumberTextArea, wifiCameraControl->cameraSerialNumber().c_str());
    lv_textarea_set_text(ui_CameraFirmwareVersionTextArea, wifiCameraControl->cameraFirmwareVersion().c_str());
  }
}
