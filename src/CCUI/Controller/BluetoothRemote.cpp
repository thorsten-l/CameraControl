#include <Arduino.h>
#include <alog.h>
#include <CameraControl/CameraControl.hpp>
#include <CCUI/CCUI.hpp>
#include <ui/ui.h>


// ---------------------------------------------------------------------------

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
