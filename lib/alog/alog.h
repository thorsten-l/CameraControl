#pragma once

#ifdef ALOG_LEVEL 

#define ALOG_BUFFER_SIZE 120

#if ALOG_LEVEL > 0
#define ALOG_E(format, ...) alog("E",__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#else
#define ALOG_E(format, ...)
#endif

#if ALOG_LEVEL > 1
#define ALOG_W(format, ...) alog("W",__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#else
#define ALOG_W(format, ...)
#endif

#if ALOG_LEVEL > 2
#define ALOG_I(format, ...) alog("I",__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#else
#define ALOG_I(format, ...)
#endif

#if ALOG_LEVEL > 3
#define ALOG_D(format, ...) alog("D",__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#else
#define ALOG_D(format, ...)
#endif

#if ALOG_LEVEL > 4
#define ALOG_V(format, ...) alog("V",__FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#else
#define ALOG_V(format, ...)
#endif

extern void alog(const char *tag, const char *file, const int line, const char *function, const char *format, ...);

#else
#define ALOG_E(format, ...)
#define ALOG_W(format, ...)
#define ALOG_I(format, ...)
#define ALOG_D(format, ...)
#define ALOG_V(format, ...)
#endif
