/**
 * File: RunnerGround.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "RunnerGround.h"
#include "MemoryManager.h"
#include "ErrorManager.h"

#include <time.h>

/* LOG FILE SUPPORT */

/**
 * OpenLogFile function.
 */
void openLogFile(MatrixBenchMatrixMicroBench_Application_cmd *context, int logCurrentTime) {
	time_t currentTime;

	/* Open log file */
	context->logFile = fopen("MatrixMicroBench.txt", "a");
	if (context->logFile == NULL)
		errorManager_appendError((DSPEElement*) context, SEVERE_ERROR, "Error opening log file.");
	else {
		if (logCurrentTime) {
			/* Write current time to log file */
			time(&currentTime);
			fprintf(context->logFile,
					"--------------------------------------------------------------------------------\n"
					"                            %s"
					"--------------------------------------------------------------------------------\n\n", ctime(&currentTime));
		}
	}
}

/**
 * CloseLogFile function.
 */
void closeLogFile(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	/* Close log file */
	if (context->logFile != NULL) {
		fclose(context->logFile);
		context->logFile = NULL;
	}
}

/* 
 * REMARK: Managers using these functions cannot directly include the
 * corresponding manager header file (MemoryManager or ThreadManager)
 * to avoid circular inclusions when inline support is active.
 */

/* MEMORY SUPPORT */

/**
 * AllocateMemory function.
 */
void* allocateMemory(const DSPEElement *element, size_t size) {
	if (element == NULL)
		return memorySupport_allocate(size);
	return memoryManager_allocate(element, size);
}

/**
 * AllocateAndInitMemory function.
 */
void* allocateAndInitMemory(const DSPEElement *element, size_t blockSize, unsigned int size) {
	if (element == NULL)
		return memorySupport_allocateAndInit(blockSize, size);
	return memoryManager_allocateAndInit(element, blockSize, size);
}

/**
 * ReallocateMemory function.
 */
void* reallocateMemory(void *pointer, size_t newSize) {
	return memorySupport_realloc(pointer, newSize);
}

/**
 * DisposeMemory function.
 */
void disposeMemory(void *pointer) {
	memorySupport_dispose(pointer);
}

/* DSPEInputParameters SUPPORT */

DSPEInputParameters* DSPEInputParameters_create(DSPEApplication *application) {
	DSPEInputParameters *params = (DSPEInputParameters*) allocateMemory((DSPEElement*) application, sizeof(DSPEInputParameters));

	params->headParam = NULL;
	params->tailParam = NULL;
	params->numParams = 0;
	params->next = NULL;

	return params;
}

void DSPEInputParameters_dispose(DSPEApplication *application, DSPEInputParameters *params) {
	const DSPEElement *element = (DSPEElement*) application;

	while (params->headParam != NULL) {
		DSPEInputParameterValue *paramValue = params->headParam;
		params->headParam = paramValue->nextValue;

		paramValue->nextValue = NULL;
		paramValue->gateName = NULL;
		paramValue->optionPnString = NULL;
		disposeMemory(paramValue->value);
		disposeMemory(paramValue);
	}
	disposeMemory(params);
}

