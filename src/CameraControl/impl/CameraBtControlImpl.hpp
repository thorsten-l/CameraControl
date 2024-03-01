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
  String cameraMacAddress() override;
  int pairing() override;
  bool connect() override;
  bool isPaired();
  bool isConnected();
  void disconnect() override;
  bool shutterReleased() override;
  bool shutterHalfPressed() override;
  bool shutterFullPressed(bool movieMode) override;
  bool widePressed() override;
  bool telePressed() override;
  CameraControlType type() override { return CameraControlType::BT; };

  void handler();
};
