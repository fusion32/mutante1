#ifndef __LOG_H__
#define __LOG_H__

typedef enum LogType{
	LOGTYPE_INFO = 0,
	LOGTYPE_DEBUG = 1,
	LOGTYPE_WARNING = 2,
	LOGTYPE_ERROR = 3
} LogType;

void LOG_Init();
void LOG_Cleanup();

void LOG_Add(LogType type, const char *fmt, ...);

#define LOG(fmt, ...) LOG_Add(LOGTYPE_INFO, (fmt), __VA_ARGS__);
#define LOG_WARNING(fmt, ...) LOG_Add(LOGTYPE_WARNING, (fmt), __VA_ARGS__)
#define LOG_ERROR(fmt, ...) LOG_Add(LOGTYPE_ERROR, (fmt), __VA_ARGS__)

#ifdef _DEBUG
#define LOG_DEBUG(fmt, ...) LOG_Add(LOGTYPE_DEBUG, (fmt), __VA_ARGS__);
#else
#define LOG_DEBUG(fmt, ...)
#endif

#endif //__LOG_H__