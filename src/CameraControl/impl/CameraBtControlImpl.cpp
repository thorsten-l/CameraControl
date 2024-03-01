#include <alog.h>
#include <CameraControl/impl/CameraBtControlImpl.hpp>

CameraBtControl::CameraBtControl()
{
  ALOG_D("constructor");
  canon_ble.init();
}

String CameraBtControl::apiName()
{
  return "Canon Bluetooth API";
}

String CameraBtControl::cameraName()
{
  return btCameraName;
}

String CameraBtControl::cameraMacAddress()
{
  return canon_ble.getPairedAddressString();
}

int CameraBtControl::pairing()
{
  ALOG_D("Bluetooth Pairing...");
  paired = canon_ble.pair(20);
  return paired == true ? 1 : 0;
}

bool CameraBtControl::isPaired()
{
  paired = false;
  if (btCameraName != nullptr && btCameraName.length() > 0 &&
      strcmp("00:00:00:00:00:00", btCameraName.c_str()) != 0)
  {
    paired = true;
  }
  ALOG_D("is paired = %s", paired ? "true" : "false");
  return paired;
}

bool CameraBtControl::isConnected()
{
  connected = canon_ble.isConnected();
  ALOG_D("is connected = %s", connected ? "true" : "false");
  return connected;
}

bool CameraBtControl::connect()
{
  ALOG_D("Connecting...");
  return canon_ble.connect();
}

void CameraBtControl::disconnect()
{
  ALOG_D("Disconnecting...");
  canon_ble.disconnect();
}

bool CameraBtControl::shutterReleased()
{
  ALOG_D("^--^");
  return canon_ble.shutterReleased();
}

bool CameraBtControl::shutterHalfPressed()
{
  ALOG_D("V--V");
  return canon_ble.shutterHalfPressed();
}

bool CameraBtControl::shutterFullPressed(bool movieMode)
{
  ALOG_D("V__V");
  return canon_ble.shutterFullPressed(movieMode);
}

bool CameraBtControl::widePressed()
{
  return canon_ble.widePressed();
}

bool CameraBtControl::telePressed()
{
  return canon_ble.telePressed();
}

void CameraBtControl::handler() {}
