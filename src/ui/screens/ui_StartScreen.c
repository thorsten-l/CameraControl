// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: CameraControl

#include "../ui.h"

void ui_StartScreen_screen_init(void)
{
ui_StartScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_StartScreen, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM );    /// Flags
lv_obj_set_scrollbar_mode(ui_StartScreen, LV_SCROLLBAR_MODE_OFF);

ui_StartTabView = lv_tabview_create(ui_StartScreen, LV_DIR_BOTTOM, 50);
lv_obj_set_width( ui_StartTabView, lv_pct(100));
lv_obj_set_height( ui_StartTabView, lv_pct(100));
lv_obj_clear_flag( ui_StartTabView, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags

lv_obj_set_style_pad_left(lv_tabview_get_tab_btns(ui_StartTabView), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(lv_tabview_get_tab_btns(ui_StartTabView), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(lv_tabview_get_tab_btns(ui_StartTabView), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(lv_tabview_get_tab_btns(ui_StartTabView), 0,  LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WirelessTabPage = lv_tabview_add_tab(ui_StartTabView, "Wireless");
lv_obj_set_flex_flow(ui_WirelessTabPage,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_WirelessTabPage, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_clear_flag( ui_WirelessTabPage, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_WirelessTabPage, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_pad_left(ui_WirelessTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_WirelessTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_WirelessTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_WirelessTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_StartBluetoothButton = lv_btn_create(ui_WirelessTabPage);
lv_obj_set_width( ui_StartBluetoothButton, 120);
lv_obj_set_height( ui_StartBluetoothButton, 100);
lv_obj_set_x( ui_StartBluetoothButton, 60 );
lv_obj_set_y( ui_StartBluetoothButton, 26 );
lv_obj_set_flex_flow(ui_StartBluetoothButton,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_StartBluetoothButton, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_add_flag( ui_StartBluetoothButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_StartBluetoothButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image2 = lv_img_create(ui_StartBluetoothButton);
lv_img_set_src(ui_Image2, &ui_img_bluetooth3_64_png);
lv_obj_set_width( ui_Image2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Image2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label7 = lv_label_create(ui_StartBluetoothButton);
lv_obj_set_width( ui_Label7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label7, LV_SIZE_CONTENT);   /// 1
lv_label_set_text(ui_Label7,"Bluetooth");

ui_StartWiFiButton = lv_btn_create(ui_WirelessTabPage);
lv_obj_set_width( ui_StartWiFiButton, 120);
lv_obj_set_height( ui_StartWiFiButton, 100);
lv_obj_set_x( ui_StartWiFiButton, 60 );
lv_obj_set_y( ui_StartWiFiButton, 147 );
lv_obj_set_flex_flow(ui_StartWiFiButton,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_StartWiFiButton, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_add_flag( ui_StartWiFiButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_StartWiFiButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image4 = lv_img_create(ui_StartWiFiButton);
lv_img_set_src(ui_Image4, &ui_img_wifi3_64_png);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Image4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label8 = lv_label_create(ui_StartWiFiButton);
lv_obj_set_width( ui_Label8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label8, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label8,"WiFi");

ui_SettingsTabPage = lv_tabview_add_tab(ui_StartTabView, "Settings");
lv_obj_set_flex_flow(ui_SettingsTabPage,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_SettingsTabPage, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);

ui_WiFiApiContainer = lv_obj_create(ui_SettingsTabPage);
lv_obj_remove_style_all(ui_WiFiApiContainer);
lv_obj_set_height( ui_WiFiApiContainer, 94);
lv_obj_set_width( ui_WiFiApiContainer, lv_pct(100));
lv_obj_set_flex_flow(ui_WiFiApiContainer,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_WiFiApiContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_WiFiApiContainer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label2 = lv_label_create(ui_WiFiApiContainer);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label2,"WiFi API");
lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ccApiCheckbox = lv_checkbox_create(ui_WiFiApiContainer);
lv_checkbox_set_text(ui_ccApiCheckbox,"Camera Connect API");
lv_obj_set_width( ui_ccApiCheckbox, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ccApiCheckbox, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_ccApiCheckbox, LV_ALIGN_CENTER );
lv_obj_add_state( ui_ccApiCheckbox, LV_STATE_CHECKED );     /// States
lv_obj_add_flag( ui_ccApiCheckbox, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags

ui_ptpCheckbox = lv_checkbox_create(ui_WiFiApiContainer);
lv_checkbox_set_text(ui_ptpCheckbox,"Picture Transfer Protocol");
lv_obj_set_width( ui_ptpCheckbox, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ptpCheckbox, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_ptpCheckbox, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ptpCheckbox, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags

ui_MaintenanceContainer = lv_obj_create(ui_SettingsTabPage);
lv_obj_remove_style_all(ui_MaintenanceContainer);
lv_obj_set_height( ui_MaintenanceContainer, 220);
lv_obj_set_width( ui_MaintenanceContainer, lv_pct(100));
lv_obj_set_align( ui_MaintenanceContainer, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_MaintenanceContainer,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_MaintenanceContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_MaintenanceContainer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label4 = lv_label_create(ui_MaintenanceContainer);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4,"Maintenance");
lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_RestartControllerButton = lv_btn_create(ui_MaintenanceContainer);
lv_obj_set_height( ui_RestartControllerButton, 50);
lv_obj_set_width( ui_RestartControllerButton, lv_pct(100));
lv_obj_set_align( ui_RestartControllerButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_RestartControllerButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_RestartControllerButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label3 = lv_label_create(ui_RestartControllerButton);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"Restart Controller");

ui_CalibrateTouchPanelButton = lv_btn_create(ui_MaintenanceContainer);
lv_obj_set_height( ui_CalibrateTouchPanelButton, 50);
lv_obj_set_width( ui_CalibrateTouchPanelButton, lv_pct(100));
lv_obj_set_align( ui_CalibrateTouchPanelButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_CalibrateTouchPanelButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_CalibrateTouchPanelButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label1 = lv_label_create(ui_CalibrateTouchPanelButton);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"Calibrate Touch-Panel");

ui_ResetAllSettingsButton = lv_btn_create(ui_MaintenanceContainer);
lv_obj_set_height( ui_ResetAllSettingsButton, 50);
lv_obj_set_width( ui_ResetAllSettingsButton, lv_pct(100));
lv_obj_set_align( ui_ResetAllSettingsButton, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ResetAllSettingsButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_ResetAllSettingsButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label5 = lv_label_create(ui_ResetAllSettingsButton);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"RESET all Settings");

ui_AboutTabPage = lv_tabview_add_tab(ui_StartTabView, "About");

ui_AppNameLabel = lv_label_create(ui_AboutTabPage);
lv_obj_set_width( ui_AppNameLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AppNameLabel, LV_SIZE_CONTENT);   /// 1
lv_label_set_text(ui_AppNameLabel,"CameraControl");
lv_obj_set_style_text_color(ui_AppNameLabel, lv_color_hex(0x69BCFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AppNameLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AppNameLabel, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AppVersionLabel = lv_label_create(ui_AboutTabPage);
lv_obj_set_width( ui_AppVersionLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AppVersionLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AppVersionLabel, 150 );
lv_obj_set_y( ui_AppVersionLabel, 0 );
lv_label_set_text(ui_AppVersionLabel,"0.0.1");
lv_obj_set_style_text_color(ui_AppVersionLabel, lv_color_hex(0x69BCFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AppVersionLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AppVersionLabel, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AppCopyrightLabel = lv_label_create(ui_AboutTabPage);
lv_obj_set_width( ui_AppCopyrightLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AppCopyrightLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AppCopyrightLabel, 0 );
lv_obj_set_y( ui_AppCopyrightLabel, 28 );
lv_label_set_text(ui_AppCopyrightLabel,"Copyright 2024 \nDr. Thorsten Ludewig\nt.ludewig@gmail.com");
lv_obj_set_style_text_color(ui_AppCopyrightLabel, lv_color_hex(0xE0E0E0), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AppCopyrightLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AppCopyrightLabel, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AppLicenseLabel = lv_label_create(ui_AboutTabPage);
lv_obj_set_width( ui_AppLicenseLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AppLicenseLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AppLicenseLabel, 0 );
lv_obj_set_y( ui_AppLicenseLabel, 84 );
lv_label_set_text(ui_AppLicenseLabel,"License:");
lv_obj_set_style_text_color(ui_AppLicenseLabel, lv_color_hex(0x69BCFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AppLicenseLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AppLicenseLabel, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Apache2LicenseLabel = lv_label_create(ui_AboutTabPage);
lv_obj_set_width( ui_Apache2LicenseLabel, 200);
lv_obj_set_height( ui_Apache2LicenseLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Apache2LicenseLabel, 0 );
lv_obj_set_y( ui_Apache2LicenseLabel, 104 );
lv_label_set_text(ui_Apache2LicenseLabel,"Licensed under the Apache License, Version 2.0 (the \"License\");\nyou may not use this file except in compliance with the License.\nYou may obtain a copy of the License at\n\n      http://www.apache.org/licenses/LICENSE-2.0\n\nUnless required by applicable law or agreed to in writing, software\ndistributed under the License is distributed on an \"AS IS\" BASIS,\nWITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\nSee the License for the specific language governing permissions and\nlimitations under the License.\n");
lv_obj_set_style_text_color(ui_Apache2LicenseLabel, lv_color_hex(0xE0E0E0), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Apache2LicenseLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Apache2LicenseLabel, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_Image2, ui_event_Image2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_StartBluetoothButton, ui_event_StartBluetoothButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_StartWiFiButton, ui_event_StartWiFiButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ccApiCheckbox, ui_event_ccApiCheckbox, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ptpCheckbox, ui_event_ptpCheckbox, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_RestartControllerButton, ui_event_RestartControllerButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_CalibrateTouchPanelButton, ui_event_CalibrateTouchPanelButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ResetAllSettingsButton, ui_event_ResetAllSettingsButton, LV_EVENT_ALL, NULL);

}
