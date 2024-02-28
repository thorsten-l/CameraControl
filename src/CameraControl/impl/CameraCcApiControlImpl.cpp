#include <alog.h>
#include <CameraControl/impl/CameraCcApiControlImpl.hpp>

String CameraCcApiControl::apiName()
{
  return "Canon Camera Control API";
}

String CameraCcApiControl::cameraName()
{
  return "-";
}

String CameraCcApiControl::cameraAddress()
{
  return "-";
}

bool CameraCcApiControl::connect(String ssid, String password)
{
  ALOG_E("Not implemented");
  return false;
}

bool CameraCcApiControl::isConnected()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::isConnected()" << std::endl;

  return false;
}


void CameraCcApiControl::disconnect()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::disconnect()" << std::endl;
}

bool CameraCcApiControl::shutterReleased()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::shutterRelease()" << std::endl;
  return false;
}

bool CameraCcApiControl::shutterHalfPressed()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::shutterHalfPress()" << std::endl;
  return false;
}

bool CameraCcApiControl::shutterFullPressed(bool movieMode)
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::shutterFullPress()" << std::endl;
  return false;
}

bool CameraCcApiControl::widePressed()
{
  std::cout << "CameraCcApiControl::widePressed()" << std::endl;
  return false;
}

bool CameraCcApiControl::telePressed()
{
  std::cout << "CameraCcApiControl::telePressed()" << std::endl;
  return false;
}

void CameraCcApiControl::handler() {}

