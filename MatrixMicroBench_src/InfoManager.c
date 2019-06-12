/**
 * File: InfoManager.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "InfoManager.h"

#include "RunnerGround.h"

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/**
 * InfoManager_writeInfo function
 */
void infoManager_writeInfo(const DSPEElement *element, const char *info, ...) {
	va_list args;
	va_list copy;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	va_start(args, info);
	// REMARK: cannot reuse the same va_list, need a copy!
	va_copy(copy, args);
	vprintf(info, copy);
	va_end(copy);
	vfprintf(context->logFile, info, args);
	va_end(args);
	printf("\n");
	fprintf(context->logFile, "\n");
}

/**
 * InfoManager_logInfo function
 */
void infoManager_logInfo(const DSPEElement *element, const char *info, ...) {
	va_list args;
	va_list copy;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	va_start(args, info);
	// REMARK: cannot reuse the same va_list, need a copy!
	va_copy(copy, args);
	vprintf(info, copy);
	va_end(copy);
	vfprintf(context->logFile, info, args);
	va_end(args);
	printf("\n");
	fprintf(context->logFile, "\n");
}

/**
 * InfoSupport_getCollectedInfoString function.
 */
const char* infoSupport_getCollectedInfoString(const infoID id) {
	switch (id) {

	default:
		return "Invalid info id";
	}
}

/**
 * CollectInfo function.
 */
static INLINE void collectInfo(const DSPEElement *element, const infoID id, const unsigned int increment, int isLog) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (isLog) {
		if (context->collectedLog[id] > UINT_MAX - increment)
			context->collectedLog[id] = UINT_MAX;
		else
			context->collectedLog[id] += increment;
		if (context->collectedLog[id] == UINT_MAX) {
			/* MAX_COUNT reached; show collected log */
			fprintf(context->logFile, "%s (MAX_COUNT times)\n", infoSupport_getCollectedInfoString(id));
			context->collectedLog[id] = 0;
		}
	} else {
		if (context->collectedInfo[id] > UINT_MAX - increment)
			context->collectedInfo[id] = UINT_MAX;
		else
			context->collectedInfo[id] += increment;
		if (context->collectedInfo[id] == UINT_MAX) {
			/* MAX_COUNT reached; show collected info */
			printf("%s (MAX_COUNT times)\n", infoSupport_getCollectedInfoString(id));
			context->collectedInfo[id] = 0;
		}
	}
}

/**
 * InfoManager_collectAndWriteInfo function
 */
void infoManager_collectAndWriteInfo(const DSPEElement *element, const infoID id, const unsigned int increment) {

	collectInfo(element, id, increment, 0);
}

/**
 * InfoManager_collectAndLogInfo function
 */
void infoManager_collectAndLogInfo(const DSPEElement *element, const infoID id, const unsigned int increment) {

	collectInfo(element, id, increment, 1);
}

