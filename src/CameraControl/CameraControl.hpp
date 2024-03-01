#pragma once

#include <memory>
#include <string>

enum class CameraControlType
{
  CCAPI = 0,
  PTP,
  BT
};

class CameraControl
{
protected:
  bool paired = false;
  bool connected = false;

public:
  virtual String apiName() = 0;
  virtual String cameraName() = 0;
  virtual String cameraMacAddress() = 0;
  virtual bool isConnected() = 0;
  virtual void disconnect() = 0;
  virtual bool shutterReleased() = 0;
  virtual bool shutterHalfPressed() = 0;
  virtual bool shutterFullPressed(bool movieMode) = 0;
  virtual bool widePressed() = 0;
  virtual bool telePressed() = 0;
  virtual CameraControlType type() = 0;
  virtual void handler() = 0;

  static std::shared_ptr<CameraControl> getInstance(CameraControlType type);
};

class BTCameraControl : public CameraControl
{
public:
  virtual int pairing() = 0;
  virtual bool isPaired() = 0;
  virtual bool connect() = 0;
};

class WifiCameraControl : public CameraControl
{
protected:
  String baseUrl;
  String cameraClientIpAddress;
  String cameraClientIpPort;

public:
  virtual String cameraSerialNumber() = 0;
  virtual String cameraFirmwareVersion() = 0;
  virtual String getDefaultCameraClientIpAddress() = 0;
  virtual String getDefaultCameraClientIpPort() = 0;
  virtual bool connect(String ssid, String password) = 0;

  void setCameraClientIpAddress(String _cameraClientIpAddress)
  {
    cameraClientIpAddress = _cameraClientIpAddress;
  };

  void setCameraClientIpPort(String _cameraClientIpPort)
  {
    cameraClientIpPort = _cameraClientIpPort;
  };
};

extern std::shared_ptr<CameraControl> cameraControl;
