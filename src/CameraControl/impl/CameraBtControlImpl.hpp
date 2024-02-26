#pragma once

#include <Arduino.h>
#include <CameraControl/CameraControl.hpp>
#include <iostream>
#include <CanonBLERemote.hpp>


class CameraBtControl : public BTCameraControl
{
private:
  CanonBLERemote canon_ble = CanonBLERemote("CameraControl");

public:
  CameraBtControl();

  String apiName() override;
  String cameraName() override;
  String cameraAddress() override;
  int pairing() override;
  int connect() override;
  bool isPaired();
  bool isConnected();
  int disconnect() override;
  int shutterRelease() override;
  int shutterHalfPress() override;
  int shutterFullPress() override;
  void handler();
};
