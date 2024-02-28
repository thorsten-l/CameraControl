#pragma once

#include <Arduino.h>
#include <alog.h>
#include <ui/ui.h>

enum class CCUIMessageBoxType
{
  INFO = 0,
  WARNING,
  ERROR
};

class CCUI
{
private:
  lv_color_t colorButtonDisabled = lv_color_hex(0x404040);
  lv_color_t colorButtonEnabled = lv_color_hex(0x2196F3);
  const char *messageBoxTypes[3] = { "INFO", "WARNING", "ERROR" };

public:
  void enableButton(lv_obj_t *button);
  void disableButton(lv_obj_t *button);

  void showHandlerMessageBox(
    CCUIMessageBoxType type, const char *message, bool closeButton,
    lv_event_cb_t eventCallback, const char *buttons[]);

/* create a task based message box for blocking io  */
  void showTaskMessageBox(
    const char* title, const char *message, bool closeButton,
    lv_event_cb_t eventCallback, const char *buttons[]);

  void showHandlerMessageBox(
    CCUIMessageBoxType type, const char *message, bool closeButton);

  void showHandlerMessageBoxNOYES(
    CCUIMessageBoxType type, const char *message, 
    bool closeButton, lv_event_cb_t eventCallback);

  void showHandlerMessageBoxRETURN(
    CCUIMessageBoxType type, const char *message, lv_event_cb_t eventCallback);

  void handler();
};

extern CCUI ccui;
