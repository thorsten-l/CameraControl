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

/*
int CameraCcApiControl::pairing()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::pairing()" << std::endl;
  return 0;
}

int CameraCcApiControl::connect()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::connect()" << std::endl;
  return 0;
}
*/

int CameraCcApiControl::connect(String ssid, String password)
{
  ALOG_E("Not implemented");
  return 0;
}

/*
bool CameraCcApiControl::isPaired()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::isPaired()" << std::endl;

  return false;
}
*/

bool CameraCcApiControl::isConnected()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::isConnected()" << std::endl;

  return false;
}


int CameraCcApiControl::disconnect()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::disconnect()" << std::endl;
  return 0;
}

int CameraCcApiControl::shutterRelease()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::shutterRelease()" << std::endl;
  return 0;
}

int CameraCcApiControl::shutterHalfPress()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::shutterHalfPress()" << std::endl;
  return 0;
}

int CameraCcApiControl::shutterFullPress()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::shutterFullPress()" << std::endl;
  return 0;
}

void CameraCcApiControl::handler() {}

