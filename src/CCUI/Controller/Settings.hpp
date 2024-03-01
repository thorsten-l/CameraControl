#pragma once

#include <Arduino.h>
#include <ArduinoNvs.h>
#include <CameraControl/CameraControl.hpp>
#include <ui/ui.h>
#include <ArduinoNvs.h>


class Settings
{
private:
  void restartController();

public:
  void initialize();
  void handler();
};

extern CameraControlType wifiCameraControlType;
extern Settings settings;
extern ArduinoNvs appNvs;
