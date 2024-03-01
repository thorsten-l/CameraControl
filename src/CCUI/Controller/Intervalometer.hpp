#pragma once

#include <Arduino.h>
#include <ui/ui.h>

enum class IntervalState
{
  IDLE,

  IVT_IDLE,
  IVT_PRESS_SHUTTER,
  IVT_RELEASE_SHUTTER,
  IVT_RELEASE_SHUTTER_WAIT,

  XPT_IDLE,
  XPT_PRESS_SHUTTER1,
  XPT_RELEASE_SHUTTER1,
  XPT_RELEASE_SHUTTER1_WAIT,
  XPT_PRESS_SHUTTER2,
  XPT_RELEASE_SHUTTER2,
  XPT_RELEASE_SHUTTER2_WAIT,
};

class Intervalometer
{
private:
  IntervalState intervalState = IntervalState::IDLE;

  int pictureCounter = 0;

  time_t shutterPauseTime = 0;

  time_t intervalTime = 0;
  time_t intervalTimeMillis = 0;
  bool intervalTimeInMinutes = false;

  time_t exposureTime = 0;
  time_t exposureTimeMillis = 0;
  bool exposureTimeInMinutes = false;

  bool intervalRunning = false;
  time_t lastIntervalTimestamp = 0;
  time_t lastExposureTimestamp = 0;
  time_t lastFullPressedTimestamp = 0;
  time_t lastReleasedTimestamp = 0;

  int lastTab = 0;

  bool nextShot = false;
  bool aboartInterval = false;

  void shutterFullPressed();
  void shutterReleased();
  int getRollerDigitsValue(lv_obj_t *rollerDigits[], int digits);
  void setRollerDigitsValue(lv_obj_t *rollerDigits[], int digits, int value);

public:
  void startButtonClicked(lv_event_t *e);
  void pauseButtonClicked(lv_event_t *e);
  void stopButtonClicked(lv_event_t *e);

  void handler();
};

extern Intervalometer intervalometer;
