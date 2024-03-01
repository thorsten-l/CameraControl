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

String CameraPtpControl::cameraMacAddress()
{
  return "-";
}

String CameraPtpControl::cameraSerialNumber()
{
  return "-";
}

String CameraPtpControl::cameraFirmwareVersion()
{
  return "0.8.15";
}

bool CameraPtpControl::connect(String ssid, String password)
{
  ALOG_E("Not implemented");
  return false;
}

bool CameraPtpControl::isConnected()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::isConnected()" << std::endl;

  return false;
}

void CameraPtpControl::disconnect()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::disconnect()" << std::endl;
}

bool CameraPtpControl::shutterReleased()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::shutterRelease()" << std::endl;
  return false;
}

bool CameraPtpControl::shutterHalfPressed()
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::shutterHalfPress()" << std::endl;
  return false;
}

bool CameraPtpControl::shutterFullPressed(bool movieMode)
{
  // Implementierung für CameraPtpControl
  std::cout << "CameraPtpControl::shutterFullPress()" << std::endl;
  return false;
}

bool CameraPtpControl::widePressed()
{
  std::cout << "CameraCcApiControl::widePressed()" << std::endl;
  return false;
}

bool CameraPtpControl::telePressed()
{
  std::cout << "CameraCcApiControl::telePressed()" << std::endl;
  return false;
}

void CameraPtpControl::handler() {}

String CameraPtpControl::getDefaultCameraClientIpAddress()
{
  return "192.168.1.2";
}

String CameraPtpControl::getDefaultCameraClientIpPort()
{
  return "15740";
}
