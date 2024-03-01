#include <CCUI/CCUI.hpp>

CCUI ccui;

void CCUI::enableButton(lv_obj_t *button)
{
  lv_obj_set_style_bg_color(button, colorButtonEnabled, 0);
  lv_obj_add_flag(button, LV_OBJ_FLAG_CLICKABLE);
}

void CCUI::disableButton(lv_obj_t *button)
{
  lv_obj_set_style_bg_color(button, colorButtonDisabled, 0);
  lv_obj_clear_flag(button, LV_OBJ_FLAG_CLICKABLE);
}

void CCUI::showHandlerMessageBox(CCUIMessageBoxType type, const char *message,
                                 bool closeButton, lv_event_cb_t eventCallback,
                                 const char *buttons[])
{
  lv_obj_t *messageBox = lv_msgbox_create(NULL, messageBoxTypes[(int)type],
                                          message, buttons, closeButton);

  if (eventCallback != nullptr)
  {
    lv_obj_add_event_cb(messageBox, eventCallback, LV_EVENT_VALUE_CHANGED,
                        NULL);
  }

  lv_obj_center(messageBox);
}

void CCUI::showHandlerMessageBox(CCUIMessageBoxType type, const char *message,
                                 bool closeButton)
{
  static const char *buttons[] = {""};
  showHandlerMessageBox(type, message, closeButton, nullptr, buttons);
}

void CCUI::showHandlerMessageBoxNOYES(CCUIMessageBoxType type,
                                      const char *message, bool closeButton,
                                      lv_event_cb_t eventCallback)
{
  static const char *buttons[] = {"NO", "YES", ""};
  showHandlerMessageBox(type, message, closeButton, eventCallback, buttons);
}

void CCUI::showHandlerMessageBoxRETURN(CCUIMessageBoxType type,
                                       const char *message,
                                       lv_event_cb_t eventCallback)
{
  static const char *buttons[] = {"RETURN", ""};
  showHandlerMessageBox(type, message, false, eventCallback, buttons);
}

lv_obj_t *taskMessageBox;
lv_event_cb_t taskEventCallback;

void messageBoxTask(void *pvParameters)
{
  ALOG_D("task running (core:%d)", xPortGetCoreID());

  static lv_event_t event;
  event.current_target = taskMessageBox;
  event.target = taskMessageBox;
  event.user_data = pvParameters;

  if (taskEventCallback != nullptr)
  {
    taskEventCallback(&event);
  }

  lv_msgbox_close(taskMessageBox);
  ALOG_D("delete task");
  vTaskDelete(NULL);
}

void CCUI::showTaskMessageBox(const char *title, const char *message,
                              bool closeButton, lv_event_cb_t eventCallback,
                              const char *buttons[])
{
  taskMessageBox = lv_msgbox_create(NULL, title, message, buttons, closeButton);
  lv_obj_center(taskMessageBox);
  taskEventCallback = eventCallback;

  xTaskCreatePinnedToCore(&messageBoxTask, "messageBoxTask", 10000, NULL, 1,
                          NULL, 1);
}

void CCUI::initialize()
{
//
}

void CCUI::handler()
{
  //
}
