#pragma once

#include <Arduino.h>
#include <CameraControl/CameraControl.hpp>
#include <iostream>

class CameraPtpControl : public WifiCameraControl
{
public:
  String apiName() override;
  String cameraName() override;
  String cameraAddress() override;
  int connect(String ssid, String password);
  bool isConnected();
  int disconnect() override;
  int shutterRelease() override;
  int shutterHalfPress() override;
  int shutterFullPress() override;
  void handler();
};
