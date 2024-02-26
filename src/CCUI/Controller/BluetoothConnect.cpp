#include <Arduino.h>
#include <alog.h>
#include <CameraControl/CameraControl.hpp>
#include <CCUI/CCUI.hpp>
#include <ui/ui.h>

static lv_obj_t *mbox1;
static int lastTab = 0;

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
