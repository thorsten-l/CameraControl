#pragma once

#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJSON.h>
#include <CameraControl/CameraControl.hpp>
#include <iostream>

class CameraCcApiControl : public WifiCameraControl
{
private:
  HTTPClient http;
  JsonDocument deviceInformation;

  int httpGET(String uri, JsonDocument &result);
  int httpPOST(String uri, String body);
  int httpPOST(String uri, JsonDocument &body);

public:
  String apiName() override;
  String cameraName() override;
  String cameraMacAddress() override;
  String cameraSerialNumber() override;
  String cameraFirmwareVersion() override;
  bool connect(String ssid, String password);
  bool isConnected();
  void disconnect() override;
  bool shutterReleased() override;
  bool shutterHalfPressed() override;
  bool shutterFullPressed(bool movieMode) override;
  bool widePressed() override;
  bool telePressed() override;
  CameraControlType type() override
  {
    return CameraControlType::CCAPI;
  };
  String getDefaultCameraClientIpAddress();
  String getDefaultCameraClientIpPort();
  void handler();
};
