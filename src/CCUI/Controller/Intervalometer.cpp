#include <Arduino.h>
#include <alog.h>
#include <CameraControl/CameraControl.hpp>
#include <CCUI/CCUI.hpp>
#include <CCUI/Controller/Intervalometer.hpp>

Intervalometer intervalometer;

// ---------------------------------------------------------------------------

void Intervalometer::shutterFullPressed()
{
  cameraControl->shutterFullPressed(false);
  lastFullPressedTimestamp = millis();
}

void Intervalometer::shutterReleased()
{
  cameraControl->shutterReleased();
  lastReleasedTimestamp = millis();
}

int Intervalometer::getRollerDigitsValue(lv_obj_t *rollerDigits[], int digits)
{
  int value = 0;
  for (int i = 0; i < digits; i++)
  {
    value *= 10;
    value += lv_roller_get_selected(rollerDigits[i]);
  }
  return value;
}

void Intervalometer::setRollerDigitsValue(lv_obj_t *rollerDigits[], int digits, int value)
{
  for (int i = digits; i > 0; i--)
  {
    lv_roller_set_selected(rollerDigits[i - 1], value % 10, LV_ANIM_ON);
    value /= 10;
  }
}

void Intervalometer::startButtonClicked(lv_event_t *e)
{
  ALOG_D("Intervalometer::startButtonClicked");

  lv_obj_t *pRollerDigits[] = {ui_PRoller1000, ui_PRoller100, ui_PRoller10,
                               ui_PRoller1};
  lv_obj_t *iRollerDigits[] = {ui_IRoller100, ui_IRoller10, ui_IRoller1};
  lv_obj_t *xRollerDigits[] = {ui_XRoller100, ui_XRoller10, ui_XRoller1};

  pictureCounter = getRollerDigitsValue(pRollerDigits, 4);
  intervalTime = getRollerDigitsValue(iRollerDigits, 3);
  exposureTime = getRollerDigitsValue(xRollerDigits, 3);

  if ( cameraControl->type() == CameraControlType::BT )
  {
    shutterPauseTime = 250;
  }
  else
  {
    shutterPauseTime = 750;
  }

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

  intervalState = (exposureTime > 0) ? IntervalState::XPT_PRESS_SHUTTER1
                                     : IntervalState::IVT_PRESS_SHUTTER;

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

void Intervalometer::pauseButtonClicked(lv_event_t *e)
{
  ALOG_D("Intervalometer::pauseButtonClicked");
  ccui.disableButton(ui_BTIntPauseButton);
  ccui.enableButton(ui_BTIntStartButton);
  intervalRunning = false;
  aboartInterval = true;
}

void Intervalometer::stopButtonClicked(lv_event_t *e)
{
  lv_obj_t *pRollerDigits[] = {ui_PRoller1000, ui_PRoller100, ui_PRoller10,
                               ui_PRoller1};
  lv_obj_t *iRollerDigits[] = {ui_IRoller100, ui_IRoller10, ui_IRoller1};
  lv_obj_t *xRollerDigits[] = {ui_XRoller100, ui_XRoller10, ui_XRoller1};

  ALOG_D("Intervalometer::stopButtonClicked");

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


void Intervalometer::handler()
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
      stopButtonClicked(nullptr);
    }
  }

  switch (intervalState)
  {

    // IVT ---------------------------------------------------------------------

  case IntervalState::IVT_IDLE:
    if (leftSec <= 0)
    {
      lastIntervalTimestamp = millis();
      intervalState = IntervalState::IVT_PRESS_SHUTTER;
    }
    if (aboartInterval)
    {
      intervalState = IntervalState::IDLE;
    }
    break;

  case IntervalState::IVT_PRESS_SHUTTER:
    ALOG_D("pictures left %d", pictureCounter);
    shutterFullPressed();
    intervalState = IntervalState::IVT_RELEASE_SHUTTER;
    break;

  case IntervalState::IVT_RELEASE_SHUTTER:
    if ((millis() - lastFullPressedTimestamp) >= shutterPauseTime)
    {
      shutterReleased();
      intervalState = IntervalState::IVT_RELEASE_SHUTTER_WAIT;
    }
    if (aboartInterval)
    {
      intervalState = IntervalState::IDLE;
    }
    break;

  case IntervalState::IVT_RELEASE_SHUTTER_WAIT:
    if ((millis() - lastReleasedTimestamp) >= shutterPauseTime)
    {
      intervalState = IntervalState::IVT_IDLE;
      if (pictureCounter > 0)
      {
        nextShot = true;
      }
      else
      {
        intervalState = IntervalState::IDLE;
      }
    }
    if (aboartInterval)
    {
      intervalState = IntervalState::IDLE;
    }
    break;

    // XPT ---------------------------------------------------------------------

  case IntervalState::XPT_IDLE:
    if (leftSec <= 0)
    {
      lastIntervalTimestamp = lastExposureTimestamp = millis();
      intervalState = IntervalState::XPT_PRESS_SHUTTER1;
      if (pictureCounter > 0)
      {
        nextShot = true;
      }
      else
      {
        intervalState = IntervalState::IDLE;
      }
    }
    if (aboartInterval)
    {
      intervalState = IntervalState::IDLE;
    }
    break;

  case IntervalState::XPT_PRESS_SHUTTER1:
    if (pictureCounter > 0)
    {
      ALOG_D("shutter1 - pictures left %d", pictureCounter);
      shutterFullPressed();
      intervalState = IntervalState::XPT_RELEASE_SHUTTER1;
    }
    else
    {
      intervalState = IntervalState::IDLE;
    }
    break;

  case IntervalState::XPT_RELEASE_SHUTTER1:
    if ((millis() - lastFullPressedTimestamp) >= shutterPauseTime)
    {
      shutterReleased();
      intervalState = IntervalState::XPT_RELEASE_SHUTTER1_WAIT;
    }
    break;

  case IntervalState::XPT_RELEASE_SHUTTER1_WAIT:
    if ((leftSec > 0 && aboartInterval) ||
        (millis() - lastExposureTimestamp) >= exposureTimeMillis)
    {
      intervalState = IntervalState::XPT_PRESS_SHUTTER2;
    }
    break;

  case IntervalState::XPT_PRESS_SHUTTER2:
    ALOG_D("shutter2");
    shutterFullPressed();
    intervalState = IntervalState::XPT_RELEASE_SHUTTER2;
    break;

  case IntervalState::XPT_RELEASE_SHUTTER2:
    if ((millis() - lastFullPressedTimestamp) >= shutterPauseTime)
    {
      shutterReleased();
      intervalState = IntervalState::XPT_RELEASE_SHUTTER2_WAIT;
    }
    break;

  case IntervalState::XPT_RELEASE_SHUTTER2_WAIT:
    if ((millis() - lastReleasedTimestamp) >= 3000)
    {
      intervalState = IntervalState::XPT_IDLE;
    }
    if (aboartInterval)
    {
      intervalState = IntervalState::IDLE;
    }
    break;

  default:
    break;
  }
}

// UI event wrapper ---------------------------------------------------------

void intervalStartButtonClicked(lv_event_t *e)
{
  intervalometer.startButtonClicked(e);
}

void intervalPauseButtonClicked(lv_event_t *e)
{
  intervalometer.pauseButtonClicked(e);
}

void intervalStopButtonClicked(lv_event_t *e)
{
  intervalometer.stopButtonClicked(e);
}
