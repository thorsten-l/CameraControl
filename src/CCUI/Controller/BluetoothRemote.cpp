#include <Arduino.h>
#include <alog.h>
#include <CameraControl/CameraControl.hpp>
#include <CCUI/CCUI.hpp>
#include <ui/ui.h>


// ---------------------------------------------------------------------------

void btHalfPressedPressed(lv_event_t *e)
{
  cameraControl->shutterHalfPressed();
}

void btHalfPressedReleased(lv_event_t *e)
{
  cameraControl->shutterReleased();
}

void btFullPressedPressed(lv_event_t *e)
{
  bool movieMode = lv_obj_has_state(ui_BTMovieModeSwitch, LV_STATE_CHECKED);
  ALOG_D( "btFullPressedPressed movieMode=%s", movieMode ? "true" : "false");
  cameraControl->shutterFullPressed(movieMode);
}

void btFullPressedReleased(lv_event_t *e)
{
  cameraControl->shutterReleased();
}

void btWidePressed(lv_event_t *e)
{
  ALOG_D("<->");
  cameraControl->widePressed();
}

void btWideReleased(lv_event_t *e)
{
  ALOG_D("<->");
}

void btTelePressed(lv_event_t *e)
{
  ALOG_D(">-<");
  cameraControl->telePressed();
}

void btTeleReleased(lv_event_t *e)
{
  ALOG_D(">-<");
}
