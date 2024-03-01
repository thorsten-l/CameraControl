// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: CameraControl

#include "../ui.h"

void ui_WiFiScreen_screen_init(void)
{
ui_WiFiScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_WiFiScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_WiFiTabView = lv_tabview_create(ui_WiFiScreen, LV_DIR_BOTTOM, 50);
lv_obj_set_width( ui_WiFiTabView, lv_pct(100));
lv_obj_set_height( ui_WiFiTabView, lv_pct(100));
lv_obj_set_align( ui_WiFiTabView, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_WiFiTabView, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_WiFiTabView, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_WiFiTabView, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_WiFiTabView, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_WiFiTabView, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_text_font(lv_tabview_get_tab_btns(ui_WiFiTabView), &lv_font_montserrat_12,  LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WiFiConnectTabPage = lv_tabview_add_tab(ui_WiFiTabView, "Connect");

ui_wifiSettingsContainer = lv_obj_create(ui_WiFiConnectTabPage);
lv_obj_remove_style_all(ui_wifiSettingsContainer);
lv_obj_set_height( ui_wifiSettingsContainer, 410);
lv_obj_set_width( ui_wifiSettingsContainer, lv_pct(100));
lv_obj_set_flex_flow(ui_wifiSettingsContainer,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_wifiSettingsContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_wifiSettingsContainer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Container3 = lv_obj_create(ui_wifiSettingsContainer);
lv_obj_remove_style_all(ui_Container3);
lv_obj_set_width( ui_Container3, lv_pct(100));
lv_obj_set_height( ui_Container3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container3, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container3,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label11 = lv_label_create(ui_Container3);
lv_obj_set_width( ui_Label11, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label11, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label11, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label11,"WiFi SSID");
lv_obj_set_style_pad_left(ui_Label11, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label11, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label11, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label11, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WiFiSsidDropdown = lv_dropdown_create(ui_Container3);
lv_dropdown_set_options( ui_WiFiSsidDropdown, "-" );
lv_obj_set_width( ui_WiFiSsidDropdown, lv_pct(100));
lv_obj_set_height( ui_WiFiSsidDropdown, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_WiFiSsidDropdown, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_WiFiSsidDropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags



ui_Container6 = lv_obj_create(ui_wifiSettingsContainer);
lv_obj_remove_style_all(ui_Container6);
lv_obj_set_width( ui_Container6, lv_pct(100));
lv_obj_set_height( ui_Container6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container6, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container6,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container6, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container6, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container6, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container6, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container6, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container4 = lv_obj_create(ui_Container6);
lv_obj_remove_style_all(ui_Container4);
lv_obj_set_width( ui_Container4, lv_pct(100));
lv_obj_set_height( ui_Container4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container4, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container4,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container4, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label18 = lv_label_create(ui_Container4);
lv_obj_set_width( ui_Label18, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label18, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label18, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label18,"WiFi Password");
lv_obj_set_style_pad_left(ui_Label18, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label18, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label18, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label18, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WiFiPasswordTextArea = lv_textarea_create(ui_Container4);
lv_obj_set_width( ui_WiFiPasswordTextArea, lv_pct(100));
lv_obj_set_height( ui_WiFiPasswordTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_WiFiPasswordTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_WiFiPasswordTextArea,64);
lv_textarea_set_placeholder_text(ui_WiFiPasswordTextArea,"Placeholder...");
lv_textarea_set_one_line(ui_WiFiPasswordTextArea,true);



ui_Container5 = lv_obj_create(ui_wifiSettingsContainer);
lv_obj_remove_style_all(ui_Container5);
lv_obj_set_width( ui_Container5, lv_pct(100));
lv_obj_set_height( ui_Container5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container5, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container5,LV_FLEX_FLOW_ROW);
lv_obj_set_flex_align(ui_Container5, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button1 = lv_btn_create(ui_Container5);
lv_obj_set_width( ui_Button1, 90);
lv_obj_set_height( ui_Button1, 50);
lv_obj_set_align( ui_Button1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label21 = lv_label_create(ui_Button1);
lv_obj_set_width( ui_Label21, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label21, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label21, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label21,"WiFi-\nscan");
lv_label_set_recolor(ui_Label21,"true");

ui_Button2 = lv_btn_create(ui_Container5);
lv_obj_set_width( ui_Button2, 90);
lv_obj_set_height( ui_Button2, 50);
lv_obj_set_align( ui_Button2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Button2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label22 = lv_label_create(ui_Button2);
lv_obj_set_width( ui_Label22, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label22, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label22, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label22,"Connect");

ui_WifiCameraConnectLabel = lv_label_create(ui_wifiSettingsContainer);
lv_obj_set_width( ui_WifiCameraConnectLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_WifiCameraConnectLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_WifiCameraConnectLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_WifiCameraConnectLabel,"Camera not connected!");

ui_Container7 = lv_obj_create(ui_wifiSettingsContainer);
lv_obj_remove_style_all(ui_Container7);
lv_obj_set_width( ui_Container7, lv_pct(100));
lv_obj_set_height( ui_Container7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container7, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container7,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container7, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container7, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container7, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container7, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container7, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container8 = lv_obj_create(ui_Container7);
lv_obj_remove_style_all(ui_Container8);
lv_obj_set_width( ui_Container8, lv_pct(100));
lv_obj_set_height( ui_Container8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container8, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container8,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container8, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container8, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container8, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label24 = lv_label_create(ui_Container8);
lv_obj_set_width( ui_Label24, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label24, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label24, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label24,"Camera IP-Address");
lv_obj_set_style_pad_left(ui_Label24, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label24, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label24, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label24, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WiFiCameraIpAddressTextArea = lv_textarea_create(ui_Container8);
lv_obj_set_width( ui_WiFiCameraIpAddressTextArea, lv_pct(100));
lv_obj_set_height( ui_WiFiCameraIpAddressTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_WiFiCameraIpAddressTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_WiFiCameraIpAddressTextArea,64);
lv_textarea_set_placeholder_text(ui_WiFiCameraIpAddressTextArea,"192.168.1.2");
lv_textarea_set_one_line(ui_WiFiCameraIpAddressTextArea,true);



ui_Container9 = lv_obj_create(ui_wifiSettingsContainer);
lv_obj_remove_style_all(ui_Container9);
lv_obj_set_width( ui_Container9, lv_pct(100));
lv_obj_set_height( ui_Container9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container9, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container9,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container9, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container9, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container9, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container9, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container9, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container9, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container10 = lv_obj_create(ui_Container9);
lv_obj_remove_style_all(ui_Container10);
lv_obj_set_width( ui_Container10, lv_pct(100));
lv_obj_set_height( ui_Container10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container10, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container10,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container10, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container10, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container10, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container10, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container10, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container10, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label25 = lv_label_create(ui_Container10);
lv_obj_set_width( ui_Label25, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label25, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label25, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label25,"Camera IP-Port");
lv_obj_set_style_pad_left(ui_Label25, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label25, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label25, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label25, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WiFiCameraIpPortTextArea = lv_textarea_create(ui_Container10);
lv_obj_set_width( ui_WiFiCameraIpPortTextArea, lv_pct(100));
lv_obj_set_height( ui_WiFiCameraIpPortTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_WiFiCameraIpPortTextArea, 1 );
lv_obj_set_y( ui_WiFiCameraIpPortTextArea, 0 );
lv_obj_set_align( ui_WiFiCameraIpPortTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_WiFiCameraIpPortTextArea,64);
lv_textarea_set_placeholder_text(ui_WiFiCameraIpPortTextArea,"8080");
lv_textarea_set_one_line(ui_WiFiCameraIpPortTextArea,true);



ui_WifiInfoTabPage = lv_tabview_add_tab(ui_WiFiTabView, "Info");
lv_obj_set_flex_flow(ui_WifiInfoTabPage,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_WifiInfoTabPage, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_WifiInfoTabPage, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
lv_obj_set_scrollbar_mode(ui_WifiInfoTabPage, LV_SCROLLBAR_MODE_OFF);

ui_Container14 = lv_obj_create(ui_WifiInfoTabPage);
lv_obj_remove_style_all(ui_Container14);
lv_obj_set_width( ui_Container14, lv_pct(100));
lv_obj_set_height( ui_Container14, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container14, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container14,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container14, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container14, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container14, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container14, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container14, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container14, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container12 = lv_obj_create(ui_Container14);
lv_obj_remove_style_all(ui_Container12);
lv_obj_set_width( ui_Container12, lv_pct(100));
lv_obj_set_height( ui_Container12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container12, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container12,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container12, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container12, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container12, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label26 = lv_label_create(ui_Container12);
lv_obj_set_width( ui_Label26, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label26, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label26, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label26,"Name");
lv_obj_set_style_pad_left(ui_Label26, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label26, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label26, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label26, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CameraNameTextArea = lv_textarea_create(ui_Container12);
lv_obj_set_width( ui_CameraNameTextArea, lv_pct(100));
lv_obj_set_height( ui_CameraNameTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_CameraNameTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_CameraNameTextArea,64);
lv_textarea_set_placeholder_text(ui_CameraNameTextArea,"Placeholder...");
lv_textarea_set_one_line(ui_CameraNameTextArea,true);
lv_obj_clear_flag( ui_CameraNameTextArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags



ui_Container13 = lv_obj_create(ui_WifiInfoTabPage);
lv_obj_remove_style_all(ui_Container13);
lv_obj_set_width( ui_Container13, lv_pct(100));
lv_obj_set_height( ui_Container13, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container13, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container13,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container13, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container13, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container13, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container13, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container13, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container13, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container15 = lv_obj_create(ui_Container13);
lv_obj_remove_style_all(ui_Container15);
lv_obj_set_width( ui_Container15, lv_pct(100));
lv_obj_set_height( ui_Container15, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container15, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container15,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container15, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container15, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container15, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container15, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container15, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container15, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label23 = lv_label_create(ui_Container15);
lv_obj_set_width( ui_Label23, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label23, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label23, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label23,"MAC address");
lv_obj_set_style_pad_left(ui_Label23, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label23, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label23, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label23, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CameraMacAddressTextArea = lv_textarea_create(ui_Container15);
lv_obj_set_width( ui_CameraMacAddressTextArea, lv_pct(100));
lv_obj_set_height( ui_CameraMacAddressTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_CameraMacAddressTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_CameraMacAddressTextArea,64);
lv_textarea_set_placeholder_text(ui_CameraMacAddressTextArea,"Placeholder...");
lv_textarea_set_one_line(ui_CameraMacAddressTextArea,true);
lv_obj_clear_flag( ui_CameraMacAddressTextArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags



ui_Container16 = lv_obj_create(ui_WifiInfoTabPage);
lv_obj_remove_style_all(ui_Container16);
lv_obj_set_width( ui_Container16, lv_pct(100));
lv_obj_set_height( ui_Container16, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container16, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container16,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container16, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container16, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container16, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container16, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container16, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container16, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container17 = lv_obj_create(ui_Container16);
lv_obj_remove_style_all(ui_Container17);
lv_obj_set_width( ui_Container17, lv_pct(100));
lv_obj_set_height( ui_Container17, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container17, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container17,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container17, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container17, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container17, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container17, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container17, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container17, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label27 = lv_label_create(ui_Container17);
lv_obj_set_width( ui_Label27, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label27, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label27, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label27,"Serial number");
lv_obj_set_style_pad_left(ui_Label27, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label27, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label27, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label27, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CameraSerialNumberTextArea = lv_textarea_create(ui_Container17);
lv_obj_set_width( ui_CameraSerialNumberTextArea, lv_pct(100));
lv_obj_set_height( ui_CameraSerialNumberTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_CameraSerialNumberTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_CameraSerialNumberTextArea,64);
lv_textarea_set_placeholder_text(ui_CameraSerialNumberTextArea,"Placeholder...");
lv_textarea_set_one_line(ui_CameraSerialNumberTextArea,true);
lv_obj_clear_flag( ui_CameraSerialNumberTextArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE );    /// Flags



ui_Container18 = lv_obj_create(ui_WifiInfoTabPage);
lv_obj_remove_style_all(ui_Container18);
lv_obj_set_width( ui_Container18, lv_pct(100));
lv_obj_set_height( ui_Container18, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container18, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container18,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container18, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container18, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_set_style_pad_left(ui_Container18, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container18, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container18, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container18, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Container19 = lv_obj_create(ui_Container18);
lv_obj_remove_style_all(ui_Container19);
lv_obj_set_width( ui_Container19, lv_pct(100));
lv_obj_set_height( ui_Container19, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Container19, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Container19,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Container19, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
lv_obj_clear_flag( ui_Container19, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_pad_left(ui_Container19, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Container19, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Container19, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Container19, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label28 = lv_label_create(ui_Container19);
lv_obj_set_width( ui_Label28, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label28, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label28, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label28,"Firmware version");
lv_obj_set_style_pad_left(ui_Label28, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Label28, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Label28, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Label28, 4, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CameraFirmwareVersionTextArea = lv_textarea_create(ui_Container19);
lv_obj_set_width( ui_CameraFirmwareVersionTextArea, lv_pct(100));
lv_obj_set_height( ui_CameraFirmwareVersionTextArea, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_CameraFirmwareVersionTextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_CameraFirmwareVersionTextArea,64);
lv_textarea_set_placeholder_text(ui_CameraFirmwareVersionTextArea,"Placeholder...");
lv_textarea_set_one_line(ui_CameraFirmwareVersionTextArea,true);
lv_obj_clear_flag( ui_CameraFirmwareVersionTextArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE );    /// Flags



ui_WiFiRemoteTabPage = lv_tabview_add_tab(ui_WiFiTabView, "Remote");
lv_obj_set_style_pad_left(ui_WiFiRemoteTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_WiFiRemoteTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_WiFiRemoteTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_WiFiRemoteTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WifiIntervalTabPage = lv_tabview_add_tab(ui_WiFiTabView, "Interval");
lv_obj_set_style_pad_left(ui_WifiIntervalTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_WifiIntervalTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_WifiIntervalTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_WifiIntervalTabPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_CalHomeButton3 = lv_btn_create(ui_WiFiScreen);
lv_obj_set_width( ui_CalHomeButton3, 32);
lv_obj_set_height( ui_CalHomeButton3, 32);
lv_obj_set_align( ui_CalHomeButton3, LV_ALIGN_TOP_RIGHT );
lv_obj_add_flag( ui_CalHomeButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_CalHomeButton3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_CalHomeButton3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_CalHomeButton3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_src( ui_CalHomeButton3, &ui_img_844469334, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_pad_left(ui_CalHomeButton3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_CalHomeButton3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_CalHomeButton3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_CalHomeButton3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_wifiSettingsKeyboard = lv_keyboard_create(ui_WiFiScreen);
lv_obj_set_height( ui_wifiSettingsKeyboard, 130);
lv_obj_set_width( ui_wifiSettingsKeyboard, lv_pct(100));
lv_obj_set_align( ui_wifiSettingsKeyboard, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_wifiSettingsKeyboard, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_scrollbar_mode(ui_wifiSettingsKeyboard, LV_SCROLLBAR_MODE_OFF);

lv_obj_add_event_cb(ui_WiFiPasswordTextArea, ui_event_WiFiPasswordTextArea, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_WiFiCameraIpAddressTextArea, ui_event_WiFiCameraIpAddressTextArea, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_WiFiCameraIpPortTextArea, ui_event_WiFiCameraIpPortTextArea, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_CalHomeButton3, ui_event_CalHomeButton3, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_wifiSettingsKeyboard,ui_WiFiPasswordTextArea);
lv_obj_add_event_cb(ui_wifiSettingsKeyboard, ui_event_wifiSettingsKeyboard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_WiFiScreen, ui_event_WiFiScreen, LV_EVENT_ALL, NULL);

}