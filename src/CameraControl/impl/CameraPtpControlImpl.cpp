#include <alog.h>
#include <CameraControl/impl/CameraPtpControlImpl.hpp>

String CameraPtpControl::apiName()
{
  return "Picture Transfer Protocol (PTP)";
}

String CameraPtpControl::cameraName()
{
  return "-";
}

String CameraPtpControl::cameraAddress()
{
  return "-";
}

/*
int CameraPtpControl::pairing()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::pairing()" << std::endl;
  return 0;
}


int CameraPtpControl::connect()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::connect()" << std::endl;
  return 0;
}
*/

int CameraPtpControl::connect(String ssid, String password)
{
  ALOG_E("Not implemented");
  return 0;
}

/*
bool CameraPtpControl::isPaired()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::isPaired()" << std::endl;

  return false;
}
*/

bool CameraPtpControl::isConnected()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::isConnected()" << std::endl;

  return false;
}

int CameraPtpControl::disconnect()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::disconnect()" << std::endl;
  return 0;
}

int CameraPtpControl::shutterRelease()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::shutterRelease()" << std::endl;
  return 0;
}

int CameraPtpControl::shutterHalfPress()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::shutterHalfPress()" << std::endl;
  return 0;
}

int CameraPtpControl::shutterFullPress()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::shutterFullPress()" << std::endl;
  return 0;
}

void CameraPtpControl::handler() {}

