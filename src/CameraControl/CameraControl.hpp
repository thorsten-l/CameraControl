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
  virtual String cameraAddress() = 0;
  virtual bool isConnected() = 0;
  virtual int disconnect() = 0;
  virtual int shutterRelease() = 0;
  virtual int shutterHalfPress() = 0;
  virtual int shutterFullPress() = 0;
  virtual void handler() = 0;

  static std::shared_ptr<CameraControl> getInstance(CameraControlType type);
};

class BTCameraControl : public CameraControl
{
protected:
  bool paired = false;
  bool connected = false;

public:
  virtual int pairing() = 0;
  virtual bool isPaired() = 0;
  virtual int connect() = 0;
};

class WifiCameraControl : public CameraControl
{
protected:
  bool paired = false;
  bool connected = false;

public:
  virtual int connect(String ssid, String password) = 0;
};

extern std::shared_ptr<CameraControl> cameraControl;
