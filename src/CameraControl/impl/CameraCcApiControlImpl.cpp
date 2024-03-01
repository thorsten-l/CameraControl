#include <CameraControl/impl/CameraCcApiControlImpl.hpp>
#include <WiFi.h>
#include <alog.h>

int CameraCcApiControl::httpGET(String uri, JsonDocument &result)
{
  http.begin(baseUrl + uri);
  int code = http.GET();
  ALOG_D("HTTP status=%d", code);

  if (code == 200)
  {
    WiFiClient stream = http.getStream();
    DeserializationError error = deserializeJson(result, stream);

    if (error)
    {
      ALOG_E("parse error : %s", error.c_str());
      code = -1;
    }
  }

  // http.end()
  return code;
}

int CameraCcApiControl::httpPOST(String uri, String body)
{
#ifdef ALOG_LEVEL
  time_t startTime = millis();
#endif
  http.begin(baseUrl + uri);
  http.addHeader("Content-Type", "application/json");
  int code = http.POST(body);
  ALOG_D("HTTP status=%d", code);
  // http.end();
#ifdef ALOG_LEVEL
  ALOG_D("request time = %dms", millis() - startTime);
#endif
  return code;
}

int CameraCcApiControl::httpPOST(String uri, JsonDocument &body)
{
  String jsonBody;
  serializeJson(body, jsonBody);
  return httpPOST(uri, jsonBody);
}

String CameraCcApiControl::apiName()
{
  return "Canon Camera Control API";
}

String CameraCcApiControl::cameraName()
{
  if ( deviceInformation != nullptr )
  {
    return deviceInformation["productname"];
  }
  return "-";
}

String CameraCcApiControl::cameraMacAddress()
{
  if ( deviceInformation != nullptr )
  {
    return deviceInformation["macaddress"];
  }
  return "-";
}

String CameraCcApiControl::cameraSerialNumber()
{
  if ( deviceInformation != nullptr )
  {
    return deviceInformation["serialnumber"];
  }
  return "-";
}

String CameraCcApiControl::cameraFirmwareVersion()
{
  if ( deviceInformation != nullptr )
  {
    return deviceInformation["firmwareversion"];
  }
  return "-";
}

bool CameraCcApiControl::connect(String ssid, String password)
{
  ALOG_V("wifi connect ssid='%s' pass='%s'", ssid.c_str(), password.c_str());
  baseUrl = "http://" + cameraClientIpAddress + ":" + cameraClientIpPort;
  connected = false;

  WiFi.mode(WIFI_OFF);
  WiFi.disconnect();
  delay(500);
  WiFi.mode(WIFI_MODE_STA);
  WiFi.setHostname("CameraConnect");
  WiFi.begin(ssid, password);
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);

  for (int i = 0; i < 60 && (WiFi.status() != WL_CONNECTED); i++)
  {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    return false;
  }

  JsonDocument result;
  bool success = httpGET("/ccapi", result) == 200;
  if (success)
  {
    http.setReuse(true);

    int status = httpGET("/ccapi/ver100/deviceinformation", deviceInformation);
    if (status == 200)
    {
      ALOG_D("result=");
      Serial.println(deviceInformation.as<String>());
      connected = true;
    }
    else
    {
      success = false;
    }
  }
  return success;
}

bool CameraCcApiControl::isConnected()
{
  return connected;
}

void CameraCcApiControl::disconnect()
{
  // Implementierung für CameraCcApiControl
  std::cout << "CameraCcApiControl::disconnect()" << std::endl;
}

bool CameraCcApiControl::shutterReleased()
{
  ALOG_D("shutterReleased");
  return httpPOST("/ccapi/ver100/shooting/control/shutterbutton/manual",
                  "{\"action\":\"release\",\"af\":false}") == 200;
}

bool CameraCcApiControl::shutterHalfPressed()
{
  ALOG_D("shutterHalfPressed");
  return httpPOST("/ccapi/ver100/shooting/control/shutterbutton/manual",
                  "{\"action\":\"half_press\",\"af\":true}") == 200;
}

bool CameraCcApiControl::shutterFullPressed(bool movieMode)
{
  ALOG_D("shutterFullPressed");
  return httpPOST("/ccapi/ver100/shooting/control/shutterbutton/manual",
                  "{\"action\":\"full_press\",\"af\":false}") == 200;
}

bool CameraCcApiControl::widePressed()
{
  std::cout << "CameraCcApiControl::widePressed()" << std::endl;
  return false;
}

bool CameraCcApiControl::telePressed()
{
  int status = httpGET("/ccapi/ver100/deviceinformation", deviceInformation);
  if (status == 200)
  {
    ALOG_D("result=");
    Serial.println(deviceInformation.as<String>());
  }
  return status;
}

void CameraCcApiControl::handler() {}

String CameraCcApiControl::getDefaultCameraClientIpAddress()
{
  return "192.168.1.2";
}

String CameraCcApiControl::getDefaultCameraClientIpPort()
{
  return "8080";
}
