#include <Arduino.h>
#include <alog.h>
#include <CameraControl/CameraControl.hpp>
#include <CCUI/CCUI.hpp>
#include <ui/ui.h>

#define SHUTTER_PAUSE_TIME 250

#define INTERVAL_STATE_IDLE 0

#define INTERVAL_STATE_IVT_IDLE 1
#define INTERVAL_STATE_IVT_PRESS_SHUTTER 3
#define INTERVAL_STATE_IVT_RELEASE_SHUTTER 4
#define INTERVAL_STATE_IVT_RELEASE_SHUTTER_WAIT 5

#define INTERVAL_STATE_XPT_IDLE 20
#define INTERVAL_STATE_XPT_PRESS_SHUTTER1 21
#define INTERVAL_STATE_XPT_RELEASE_SHUTTER1 22
#define INTERVAL_STATE_XPT_RELEASE_SHUTTER1_WAIT 23
#define INTERVAL_STATE_XPT_PRESS_SHUTTER2 24
#define INTERVAL_STATE_XPT_RELEASE_SHUTTER2 25
#define INTERVAL_STATE_XPT_RELEASE_SHUTTER2_WAIT 26

static int pictureCounter = 0;

static time_t intervalTime = 0;
static time_t intervalTimeMillis = 0;
static bool intervalTimeInMinutes = false;

static time_t exposureTime = 0;
static time_t exposureTimeMillis = 0;
static bool exposureTimeInMinutes = false;

static bool intervalRunning = false;
static time_t lastIntervalTimestamp = 0;
static time_t lastExposureTimestamp = 0;
static time_t lastFullPressedTimestamp = 0;
static time_t lastReleasedTimestamp = 0;

static lv_obj_t *mbox1;
static int lastTab = 0;

static bool nextShot = false;
static bool aboartInterval = false;
static int intervalState = INTERVAL_STATE_IDLE;

// ---------------------------------------------------------------------------

void btScreenLoaded(lv_event_t *e)
{
  ALOG_D("btScreenLoaded");

  if (!(std::static_pointer_cast<BTCameraControl>(cameraControl))->isPaired())
  {
    ccui.disableButton(ui_BTConnectButton);
  }
  else
  {
    lv_label_set_text(ui_BTCameraNameLabel, cameraControl->cameraName().c_str());
    lv_label_set_text(ui_BTCameraAddressLabel, cameraControl->cameraAddress().c_str());
  }

  lv_label_set_text(ui_BTConnectLabel, cameraControl->isConnected()
                                           ? "Camera is connected."
                                           : "Camera NOT connected!");
}

static void msgbox_event_cb(lv_event_t *e)
{
  lv_obj_t *obj = lv_event_get_current_target(e);
  ALOG_D("Button %s clicked", lv_msgbox_get_active_btn_text(obj));
  lv_msgbox_close(obj);
  lv_tabview_set_act(ui_BluetoothTabView, 0, LV_ANIM_OFF);
}

void btBluetoothTabViewValueChanged(lv_event_t *e)
{
  ALOG_D("btBluetoothTabViewValueChanged=%d", e->code);

  int activeTab = lv_tabview_get_tab_act(e->current_target);

  if (lastTab != activeTab)
  {
    ALOG_D("current_target tab %d active", activeTab);
    lastTab = activeTab;

    if (activeTab != 0 && !cameraControl->isConnected())
    {
      ccui.showHandlerMessageBoxRETURN(
        CCUIMessageBoxType::ERROR, "Camera NOT connected.", msgbox_event_cb);
    }
  }
}

void btHalfPressedPressed(lv_event_t *e)
{
  cameraControl->shutterHalfPress();
}

void btHalfPressedReleased(lv_event_t *e)
{
  cameraControl->shutterRelease();
}

void btFullPressedPressed(lv_event_t *e)
{
  cameraControl->shutterFullPress();
}

void btFullPressedReleased(lv_event_t *e)
{
  cameraControl->shutterRelease();
}

void checkCameraConnect(lv_event_t *e)
{
  ALOG_D("checkCameraConnect");

  std::shared_ptr<BTCameraControl> btCameraControl =
    std::static_pointer_cast<BTCameraControl>(cameraControl);

  if (btCameraControl->isConnected() || btCameraControl->connect())
  {
    ALOG_I("camera is connected");
  }
  else
  {
    ALOG_I("camera NOT connected");
  }
  ALOG_D("done.");
  btScreenLoaded(nullptr);
}

void checkCameraParing(lv_event_t *e)
{
  ALOG_D("checkCameraParing");
 
  if ((std::static_pointer_cast<BTCameraControl>(cameraControl))->pairing())
  {
    ALOG_I("camera is paired");
  }
  else
  {
    ALOG_I("camera NOT paired");
  }
  ALOG_D("done.");
  btScreenLoaded(nullptr);
}

void btPairingClicked(lv_event_t *e)
{
  ALOG_D("btPairingClicked");
  static const char *buttons[] = {""};
  ccui.showTaskMessageBox(
    "Pairing", "Please wait...\nTimeout about 40s", false, checkCameraParing, buttons);
}

void btConnectButtonClicked(lv_event_t *e)
{
  ALOG_D("btConnectButtonClicked");

  static const char *buttons[] = {""};

  ccui.showTaskMessageBox(
    "Connecting", "Please wait...", false, checkCameraConnect, buttons);
}

void shutterFullPressed()
{
  cameraControl->shutterFullPress();
  lastFullPressedTimestamp = millis();
}

void shutterReleased()
{
  cameraControl->shutterRelease();
  lastReleasedTimestamp = millis();
}

int getRollerDigitsValue(lv_obj_t *rollerDigits[], int digits)
{
  int value = 0;
  for (int i = 0; i < digits; i++)
  {
    value *= 10;
    value += lv_roller_get_selected(rollerDigits[i]);
  }
  return value;
}

void setRollerDigitsValue(lv_obj_t *rollerDigits[], int digits, int value)
{
  for (int i = digits; i > 0; i--)
  {
    lv_roller_set_selected(rollerDigits[i - 1], value % 10, LV_ANIM_ON);
    value /= 10;
  }
}

void btIntervalStartButtonClicked(lv_event_t *e)
{
  ALOG_D("btIntervalStartButtonClicked");

  lv_obj_t *pRollerDigits[] = {ui_PRoller1000, ui_PRoller100, ui_PRoller10,
                               ui_PRoller1};
  lv_obj_t *iRollerDigits[] = {ui_IRoller100, ui_IRoller10, ui_IRoller1};
  lv_obj_t *xRollerDigits[] = {ui_XRoller100, ui_XRoller10, ui_XRoller1};

  pictureCounter = getRollerDigitsValue(pRollerDigits, 4);
  intervalTime = getRollerDigitsValue(iRollerDigits, 3);
  exposureTime = getRollerDigitsValue(xRollerDigits, 3);

  intervalTimeInMinutes = lv_roller_get_selected(ui_IURoller) == 1;
  exposureTimeInMinutes = lv_roller_get_selected(ui_XURoller) == 1;

  intervalTimeMillis = intervalTime * 1000l;
  if (intervalTimeInMinutes)
  {
    intervalTimeMillis *= 60;
  }

  exposureTimeMillis = exposureTime * 1000l;
  if (exposureTimeInMinutes)
  {
    exposureTimeMillis *= 60;
  }

  if (exposureTimeMillis >= intervalTimeMillis)
  {
    intervalTimeMillis = intervalTime = 0l;
    setRollerDigitsValue(iRollerDigits, 3, 0);
  }

  intervalState = (exposureTime > 0) ? INTERVAL_STATE_XPT_PRESS_SHUTTER1
                                     : INTERVAL_STATE_IVT_PRESS_SHUTTER;

  ALOG_D("intervalState=%d", intervalState);
  ALOG_D("pictureCounter=%d", pictureCounter);
  ALOG_D("intervalTime=%ld", intervalTime);
  ALOG_D("intervalTimeInMinutes=%s", intervalTimeInMinutes ? "true" : "false");
  ALOG_D("intervalTimeMillis=%ld", intervalTimeMillis);
  ALOG_D("exposureTime=%ld", exposureTime);
  ALOG_D("exposureTimeInMinutes=%s", exposureTimeInMinutes ? "true" : "false");
  ALOG_D("exposureTimeMillis=%ld", exposureTimeMillis);

  if (pictureCounter > 0 && (intervalTime > 0 || exposureTime > 0))
  {
    lastIntervalTimestamp = lastExposureTimestamp = millis();
    ccui.enableButton(ui_BTIntPauseButton);
    ccui.disableButton(ui_BTIntStartButton);
    aboartInterval = false;
    intervalRunning = true;
    nextShot = false;
  }
}

void btIntervalPauseButtonClicked(lv_event_t *e)
{
  ALOG_D("btIntervalPauseButtonClicked");
  ccui.disableButton(ui_BTIntPauseButton);
  ccui.enableButton(ui_BTIntStartButton);
  intervalRunning = false;
  aboartInterval = true;
}

void btIntervalStopButtonClicked(lv_event_t *e)
{
  lv_obj_t *pRollerDigits[] = {ui_PRoller1000, ui_PRoller100, ui_PRoller10,
                               ui_PRoller1};
  lv_obj_t *iRollerDigits[] = {ui_IRoller100, ui_IRoller10, ui_IRoller1};
  lv_obj_t *xRollerDigits[] = {ui_XRoller100, ui_XRoller10, ui_XRoller1};

  ALOG_D("btIntervalStopButtonClicked");

  ccui.disableButton(ui_BTIntPauseButton);
  ccui.enableButton(ui_BTIntStartButton);
  intervalRunning = false;
  aboartInterval = true;

  pictureCounter = 0;
  intervalTime = 0;
  exposureTime = 0;
  intervalTimeInMinutes = false;
  exposureTimeInMinutes = false;

  lv_bar_set_value(ui_IntervalProgressBar, 0, LV_ANIM_OFF);
  lv_label_set_text(ui_IntervalProgressBarLabel, "0.0s");

  setRollerDigitsValue(pRollerDigits, 4, pictureCounter);
  setRollerDigitsValue(iRollerDigits, 3, intervalTime);
  setRollerDigitsValue(xRollerDigits, 3, exposureTime);

  lv_roller_set_selected(ui_IURoller, 0, LV_ANIM_ON);
  lv_roller_set_selected(ui_XURoller, 0, LV_ANIM_ON);
}

void btIntervalHandler()
{
  time_t leftSec;

  if (intervalRunning)
  {
    int intervalProgressBarValue;
    double duration;
    char buf[10];

    if (intervalTimeMillis > exposureTimeMillis)
    {
      duration = millis() - lastIntervalTimestamp;
      leftSec = intervalTimeMillis - duration;
      duration /= intervalTimeMillis;
    }
    else
    {
      duration = millis() - lastExposureTimestamp;
      leftSec = exposureTimeMillis - duration;
      duration /= exposureTimeMillis;
    }

    leftSec /= 100;
    leftSec = leftSec > 0 ? leftSec : 0;

    duration *= 100.0;
    intervalProgressBarValue = 100 - duration;

    intervalProgressBarValue =
        intervalProgressBarValue < 0 ? 0 : intervalProgressBarValue;

    lv_bar_set_value(ui_IntervalProgressBar, intervalProgressBarValue,
                     LV_ANIM_OFF);
    sprintf(buf, "%0.1fs", ((double)leftSec) / 10.0);
    lv_label_set_text(ui_IntervalProgressBarLabel, buf);
  }

  if (nextShot)
  {
    nextShot = false;
    lv_obj_t *pRollerDigits[] = {ui_PRoller1000, ui_PRoller100, ui_PRoller10,
                                 ui_PRoller1};
    pictureCounter--;
    setRollerDigitsValue(pRollerDigits, 4, pictureCounter);
    if (pictureCounter == 0)
    {
      btIntervalStopButtonClicked(nullptr);
    }
  }

  switch (intervalState)
  {

    // IVT ---------------------------------------------------------------------

  case INTERVAL_STATE_IVT_IDLE:
    if (leftSec <= 0)
    {
      lastIntervalTimestamp = millis();
      intervalState = INTERVAL_STATE_IVT_PRESS_SHUTTER;
    }
    if (aboartInterval)
    {
      intervalState = INTERVAL_STATE_IDLE;
    }
    break;

  case INTERVAL_STATE_IVT_PRESS_SHUTTER:
    ALOG_D("pictures left %d", pictureCounter);
    shutterFullPressed();
    intervalState = INTERVAL_STATE_IVT_RELEASE_SHUTTER;
    break;

  case INTERVAL_STATE_IVT_RELEASE_SHUTTER:
    if ((millis() - lastFullPressedTimestamp) >= SHUTTER_PAUSE_TIME)
    {
      shutterReleased();
      intervalState = INTERVAL_STATE_IVT_RELEASE_SHUTTER_WAIT;
    }
    if (aboartInterval)
    {
      intervalState = INTERVAL_STATE_IDLE;
    }
    break;

  case INTERVAL_STATE_IVT_RELEASE_SHUTTER_WAIT:
    if ((millis() - lastReleasedTimestamp) >= SHUTTER_PAUSE_TIME)
    {
      intervalState = INTERVAL_STATE_IVT_IDLE;
      if (pictureCounter > 0)
      {
        nextShot = true;
      }
      else
      {
        intervalState = INTERVAL_STATE_IDLE;
      }
    }
    if (aboartInterval)
    {
      intervalState = INTERVAL_STATE_IDLE;
    }
    break;

    // XPT ---------------------------------------------------------------------

  case INTERVAL_STATE_XPT_IDLE:
    if (leftSec <= 0)
    {
      lastIntervalTimestamp = lastExposureTimestamp = millis();
      intervalState = INTERVAL_STATE_XPT_PRESS_SHUTTER1;
      if (pictureCounter > 0)
      {
        nextShot = true;
      }
      else
      {
        intervalState = INTERVAL_STATE_IDLE;
      }
    }
    if (aboartInterval)
    {
      intervalState = INTERVAL_STATE_IDLE;
    }
    break;

  case INTERVAL_STATE_XPT_PRESS_SHUTTER1:
    if (pictureCounter > 0)
    {
      ALOG_D("shutter1 - pictures left %d", pictureCounter);
      shutterFullPressed();
      intervalState = INTERVAL_STATE_XPT_RELEASE_SHUTTER1;
    }
    else
    {
      intervalState = INTERVAL_STATE_IDLE;
    }
    break;

  case INTERVAL_STATE_XPT_RELEASE_SHUTTER1:
    if ((millis() - lastFullPressedTimestamp) >= SHUTTER_PAUSE_TIME)
    {
      shutterReleased();
      intervalState = INTERVAL_STATE_XPT_RELEASE_SHUTTER1_WAIT;
    }
    break;

  case INTERVAL_STATE_XPT_RELEASE_SHUTTER1_WAIT:
    if ((leftSec > 0 && aboartInterval) ||
        (millis() - lastExposureTimestamp) >= exposureTimeMillis)
    {
      intervalState = INTERVAL_STATE_XPT_PRESS_SHUTTER2;
    }
    break;

  case INTERVAL_STATE_XPT_PRESS_SHUTTER2:
    ALOG_D("shutter2");
    shutterFullPressed();
    intervalState = INTERVAL_STATE_XPT_RELEASE_SHUTTER2;
    break;

  case INTERVAL_STATE_XPT_RELEASE_SHUTTER2:
    if ((millis() - lastFullPressedTimestamp) >= SHUTTER_PAUSE_TIME)
    {
      shutterReleased();
      intervalState = INTERVAL_STATE_XPT_RELEASE_SHUTTER2_WAIT;
    }
    break;

  case INTERVAL_STATE_XPT_RELEASE_SHUTTER2_WAIT:
    if ((millis() - lastReleasedTimestamp) >= 3000)
    {
      intervalState = INTERVAL_STATE_XPT_IDLE;
    }
    if (aboartInterval)
    {
      intervalState = INTERVAL_STATE_IDLE;
    }
    break;

  default:
    break;
  }
}
