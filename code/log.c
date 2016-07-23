#include "log.h"

#include "thread.h"
#include "scheduler.h"
#include "types.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#define CLOSE_DELAY 10000 // 10s
#define MAX_FILE_NAME_SIZE 128

static char			l_fileName[MAX_FILE_NAME_SIZE] = "";
static FILE			*l_file = NULL;
static Mutex		*l_mtx = NULL;

// check if is saving to file
static uint32_t		l_saving = 0;

// initialization check
static uint32_t		l_ok = 0;

static void CloseFile(void *unused)
{
	MTX_Lock(l_mtx);
	fclose(l_file);
	l_file = NULL;
	MTX_Unlock(l_mtx);

	printf("ireportu\n");
}

void LOG_Init()
{
	time_t curTime;
	struct tm *timeptr;

	if(l_ok == 0){
		// set name of the log file
		curTime = time(NULL);
		timeptr = localtime(&curTime);

		// name example: "Jan-01-1999-133700.log"
		strftime(l_fileName, MAX_FILE_NAME_SIZE, "%b-%d-%Y-%H%M%S.log", timeptr);

		// create mutex
		MTX_Create(&l_mtx);

		// set state variables
		// TODO: add a command line to disable log
		// saving so in a single execution you can
		// save or not. (no switching in between)
		l_saving = 0;
		l_ok = 1;
	}
}

void LOG_Cleanup()
{
	if(l_ok != 0){
		// clear file name
		memset(l_fileName, 0, MAX_FILE_NAME_SIZE);

		// destroy mutex
		MTX_Destroy(l_mtx);

		// clear state variables
		l_saving = 0;
		l_ok = 0;
	}

	if(l_file != NULL){
		fclose(l_file);
		l_file = NULL;
	}
}

void LOG_Add(LogType type, const char *fmt, ...)
{
	va_list ap;
	time_t curTime;
	struct tm *timeptr;
	char logTag[16];
	char timeStr[64];
	char logMessage[256];
	char logEntry[256];
	size_t entrySize;

	if(l_ok == 0)
		return;

	// log tag
	switch(type){
		default:
		case LOGTYPE_INFO:
			snprintf(logTag, 16, "INFO");
			break;

		case LOGTYPE_DEBUG:
			snprintf(logTag, 16, "DEBUG");
			break;

		case LOGTYPE_WARNING:
			snprintf(logTag, 16, "WARNING");
			break;

		case LOGTYPE_ERROR:
			snprintf(logTag, 16, "ERROR");
			break;
	}

	// time str
	curTime = time(NULL);
	timeptr = localtime(&curTime);
	// format example: "Jan 01 1999 13:37:00"
	strftime(timeStr, 64, "%b %d %Y %H:%M:%S", timeptr);

	// concatenate log message
	va_start(ap, fmt);
	vsnprintf(logMessage, 256, fmt, ap);
	va_end(ap);

	// concatenate log entry
	entrySize = snprintf(logEntry, 256, "[%s]<%s> %s\n", timeStr, logTag, logMessage);
	if(entrySize <= 0){
		printf("<ERROR> Failed to concatenate log entry of type %s!\n", logTag);
		return;
	}

	// output to console
	printf(logEntry);

	// if saving, output to log file
	if(l_saving != 0){
		MTX_Lock(l_mtx);
		// open file if it is closed
		if(l_file == NULL){
			l_file = fopen(l_fileName, "a");

			if(l_file != NULL)
				SCH_Add(CLOSE_DELAY, CloseFile, NULL);
			else
				printf("<ERROR> Failed to open log file for writing! (%s)\n", l_fileName);
		}

		if(l_file != NULL){
			if(fwrite(logEntry, entrySize, 1, l_file) != 1)
				printf("<ERROR> Failed to write log entry to file! (%s)\n", l_fileName);
		}

		MTX_Unlock(l_mtx);
	}
}