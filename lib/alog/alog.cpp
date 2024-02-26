#include <Arduino.h>
#include <alog.h>

#ifdef ALOG_LEVEL 

void alog(const char *tag, const char *file, const int line, const char *function, const char *format, ...)
{
  char buf[ALOG_BUFFER_SIZE];
  va_list args;
  Serial.printf("[%lu][%s][%s:%d] %s(): ", millis(), tag, file, line, function);
  va_start(args, format);
  vsnprintf(buf,ALOG_BUFFER_SIZE-1,format,args);
  va_end(args);
  Serial.println(buf);
}

#endif
