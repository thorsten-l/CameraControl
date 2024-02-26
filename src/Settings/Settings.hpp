#pragma once

#include <Arduino.h>
#include <ArduinoNvs.h>
#include <CameraControl/CameraControl.hpp>
#include <ui/ui.h>

extern CameraControlType wifiCameraControlType;

extern void initializeSettings();
extern void settingsHandler();

class Settings
{
private:
  void restartController();

public:
  void initialize();
  void handler();
};

extern Settings settings;
