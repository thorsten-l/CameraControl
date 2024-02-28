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
  bool connect(String ssid, String password);
  bool isConnected();
  void disconnect() override;
  bool shutterReleased() override;
  bool shutterHalfPressed() override;
  bool shutterFullPressed(bool movieMode) override;
  bool widePressed() override;
  bool telePressed() override;
  void handler();
};
