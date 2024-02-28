// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: CameraControl

#ifndef _CAMERACONTROL_UI_H
#define _CAMERACONTROL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_StartScreen
void ui_StartScreen_screen_init(void);
extern lv_obj_t *ui_StartScreen;
extern lv_obj_t *ui_StartTabView;
extern lv_obj_t *ui_WirelessTabPage;
void ui_event_StartBluetoothButton( lv_event_t * e);
extern lv_obj_t *ui_StartBluetoothButton;
void ui_event_Image2( lv_event_t * e);
extern lv_obj_t *ui_Image2;
extern lv_obj_t *ui_Label7;
extern lv_obj_t *ui_StartWiFiButton;
extern lv_obj_t *ui_Image4;
extern lv_obj_t *ui_Label8;
extern lv_obj_t *ui_SettingsTabPage;
extern lv_obj_t *ui_WiFiApiContainer;
extern lv_obj_t *ui_Label2;
void ui_event_ccApiCheckbox( lv_event_t * e);
extern lv_obj_t *ui_ccApiCheckbox;
void ui_event_ptpCheckbox( lv_event_t * e);
extern lv_obj_t *ui_ptpCheckbox;
extern lv_obj_t *ui_MaintenanceContainer;
extern lv_obj_t *ui_Label4;
void ui_event_RestartControllerButton( lv_event_t * e);
extern lv_obj_t *ui_RestartControllerButton;
extern lv_obj_t *ui_Label3;
void ui_event_CalibrateTouchPanelButton( lv_event_t * e);
extern lv_obj_t *ui_CalibrateTouchPanelButton;
extern lv_obj_t *ui_Label1;
void ui_event_ResetAllSettingsButton( lv_event_t * e);
extern lv_obj_t *ui_ResetAllSettingsButton;
extern lv_obj_t *ui_Label5;
extern lv_obj_t *ui_AboutTabPage;
extern lv_obj_t *ui_AppNameLabel;
extern lv_obj_t *ui_AppVersionLabel;
extern lv_obj_t *ui_AppCopyrightLabel;
extern lv_obj_t *ui_AppLicenseLabel;
extern lv_obj_t *ui_Apache2LicenseLabel;
// SCREEN: ui_BluetoothScreen
void ui_BluetoothScreen_screen_init(void);
void ui_event_BluetoothScreen( lv_event_t * e);
extern lv_obj_t *ui_BluetoothScreen;
void ui_event_BluetoothTabView( lv_event_t * e);
extern lv_obj_t *ui_BluetoothTabView;
extern lv_obj_t *ui_BTConnectTabPage;
void ui_event_BTPairingButton( lv_event_t * e);
extern lv_obj_t *ui_BTPairingButton;
extern lv_obj_t *ui_Label9;
void ui_event_BTConnectButton( lv_event_t * e);
extern lv_obj_t *ui_BTConnectButton;
extern lv_obj_t *ui_Label10;
extern lv_obj_t *ui_BTInfoContainer;
extern lv_obj_t *ui_BTCameraNameLabel;
extern lv_obj_t *ui_BTCameraAddressLabel;
extern lv_obj_t *ui_BTConnectLabel;
extern lv_obj_t *ui_BTRemoteTabPage;
extern lv_obj_t *ui_Container1;
void ui_event_BTHalfPressButton( lv_event_t * e);
extern lv_obj_t *ui_BTHalfPressButton;
extern lv_obj_t *ui_Label12;
void ui_event_BTFullPressButton( lv_event_t * e);
extern lv_obj_t *ui_BTFullPressButton;
extern lv_obj_t *ui_Label13;
extern lv_obj_t *ui_Container2;
extern lv_obj_t *ui_Label6;
extern lv_obj_t *ui_BTMovieModeSwitch;
extern lv_obj_t *ui_Container11;
void ui_event_BTWideButton( lv_event_t * e);
extern lv_obj_t *ui_BTWideButton;
extern lv_obj_t *ui_Label19;
void ui_event_BTTeleButton( lv_event_t * e);
extern lv_obj_t *ui_BTTeleButton;
extern lv_obj_t *ui_Label20;
extern lv_obj_t *ui_BTIntervalTabPane;
extern lv_obj_t *ui_PictureDigitRollerContainer;
extern lv_obj_t *ui_PRoller1000;
extern lv_obj_t *ui_PRoller100;
extern lv_obj_t *ui_PRoller10;
extern lv_obj_t *ui_PRoller1;
extern lv_obj_t *ui_IntervalDigitRollerContainer;
extern lv_obj_t *ui_IRoller100;
extern lv_obj_t *ui_IRoller10;
extern lv_obj_t *ui_IRoller1;
extern lv_obj_t *ui_IURoller;
extern lv_obj_t *ui_ExposureDigitRollerContainer;
extern lv_obj_t *ui_XRoller100;
extern lv_obj_t *ui_XRoller10;
extern lv_obj_t *ui_XRoller1;
extern lv_obj_t *ui_XURoller;
extern lv_obj_t *ui_IntervalProgressBar;
extern lv_obj_t *ui_IntervalProgressBarLabel;
extern lv_obj_t *ui_Label14;
extern lv_obj_t *ui_Label16;
extern lv_obj_t *ui_Label17;
void ui_event_BTIntStartButton( lv_event_t * e);
extern lv_obj_t *ui_BTIntStartButton;
extern lv_obj_t *ui_Image11;
void ui_event_BTIntPauseButton( lv_event_t * e);
extern lv_obj_t *ui_BTIntPauseButton;
extern lv_obj_t *ui_Image12;
void ui_event_BTIntStopButton( lv_event_t * e);
extern lv_obj_t *ui_BTIntStopButton;
extern lv_obj_t *ui_Image13;
void ui_event_CalHomeButton2( lv_event_t * e);
extern lv_obj_t *ui_CalHomeButton2;
extern lv_obj_t *ui_Image3;
// SCREEN: ui_CalibrationScreen
void ui_CalibrationScreen_screen_init(void);
void ui_event_CalibrationScreen( lv_event_t * e);
extern lv_obj_t *ui_CalibrationScreen;
extern lv_obj_t *ui_CalTitleLabel;
void ui_event_CalHomeButton( lv_event_t * e);
extern lv_obj_t *ui_CalHomeButton;
extern lv_obj_t *ui_Image10;
void ui_event_CalStartButton( lv_event_t * e);
extern lv_obj_t *ui_CalStartButton;
extern lv_obj_t *ui_Label15;
extern lv_obj_t *ui_CalInfoLabel1;
extern lv_obj_t *ui_Image5;
extern lv_obj_t *ui_Image6;
extern lv_obj_t *ui_Image1;
extern lv_obj_t *ui_CalInfoLabel2;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_bluetooth3_64_png);   // assets/bluetooth3_64.png
LV_IMG_DECLARE( ui_img_wifi3_64_png);   // assets/wifi3_64.png
LV_IMG_DECLARE( ui_img_1941201141);   // assets/start-32.png
LV_IMG_DECLARE( ui_img_1803052213);   // assets/pause-32.png
LV_IMG_DECLARE( ui_img_766493279);   // assets/stop-32.png
LV_IMG_DECLARE( ui_img_844469334);   // assets/home-32.png
LV_IMG_DECLARE( ui_img_626158203);   // assets/circle-xmark-32.png
LV_IMG_DECLARE( ui_img_1463026258);   // assets/gear-32.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
