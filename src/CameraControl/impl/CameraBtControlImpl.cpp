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

String CameraBtControl::cameraAddress()
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

int CameraBtControl::connect()
{
  ALOG_D("Connecting...");
  return canon_ble.connect();
  ;
}

int CameraBtControl::disconnect()
{
  ALOG_D("Disconnecting...");
  canon_ble.disconnect();
  return 1;
}

/*
int CameraBtControl::connect(String ssid, String password)
{
  ALOG_E("Not implemented");
  return 0;
}
*/

int CameraBtControl::shutterRelease()
{
  ALOG_D("^--^");
  canon_ble.shutterReleased();
  return 1;
}

int CameraBtControl::shutterHalfPress()
{
  ALOG_D("V--V");
  canon_ble.shutterHalfPressed();
  return 1;
}

int CameraBtControl::shutterFullPress()
{
  ALOG_D("V__V");
  canon_ble.shutterFullPressed();
  return 1;
}

void CameraBtControl::handler() {}
