/**
 * File: RunnerSupport.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#include "PlatformManager.h"
#include "ErrorManager.h"
#include "StringManager.h"
#include "MemoryManager.h"
#include "ThreadManager.h"
#include "EngineManager.h"
#include "ProfileManager.h"
#include "InfoManager.h"

#include "RunnerSupport.h"
#include "TextualRepresentation.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/**
 * InitializeRunner function.
 */
MatrixBenchMatrixMicroBench_Application_cmd* initializeRunner() {
	MatrixBenchMatrixMicroBench_Application_cmd *context;
	DSPEElement *element;

	/* Context initialization */
	errno = 0;
	context = (MatrixBenchMatrixMicroBench_Application_cmd*) memorySupport_allocate(sizeof(MatrixBenchMatrixMicroBench_Application_cmd));
	if (errno || context == NULL) {
		printf("EXIT - Error during application allocation");
		return NULL;
	}
	initDSPEApplication((DSPEApplication*) context);
	element = (DSPEElement*) context;

	/* Init DSPEElement application */
	// REMARK: initialized here since element->application is used within
	// error and info manager!
	((DSPEElement*) context)->application = (DSPEApplication*) context;

	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMicroBench_Application_runnerPreProcess;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMicroBench_Application_runnerPostProcess;
	/* Log file init */
	context->logFile = NULL;

	/* Info manager collect info support initialization */
	context->collectedInfo = (unsigned int*) memoryManager_allocateAndInit(element, infoIDCount, sizeof(unsigned int));
	context->collectedLog = (unsigned int*) memoryManager_allocateAndInit(element, infoIDCount, sizeof(unsigned int));

	/* Error manager initialization */
	errorManager_initialize(element);	

	/* Engine manager initialization */
	engineManager_initialize(element);

	/* Profile manager initialization */
	profileManager_initialize(element);

	/* Init profileFile */
	context->profileFile = NULL;


	/* DSPESettings initialization */
	context->settings.changed = 0;

	/* MultiRun settings initialization */
	context->settings.numMultiRuns = 3;


	/* DSPEInputParameters initialization */
	context->inputParametersNumElements = 0;
	context->inputParametersCurr = NULL;
	context->inputParametersHead = NULL;
	context->inputParametersTail = NULL;

	/* Benchmark handler initialization */
	profileManager_initBenchmarkHandler((DSPEApplication*) context);

	/* Open log file */
	openLogFile(context, 1);

	/* Application startup */
	MatrixBenchMatrixMicroBench_Application_startup((DSPEApplication*) context);

	/* Show errors occurred during application startup */
	if (errorManager_hasErrorOccurred(element, FATAL_ERROR))
		errorManager_showErrors(element, FATAL_ERROR, "Fatal errors occurred during application startup.");
	if (errorManager_hasErrorOccurred(element, SEVERE_ERROR))
		errorManager_showErrors(element, SEVERE_ERROR, "Severe errors occurred during application startup.");
	if (errorManager_hasErrorOccurred(element, MAJOR_ERROR))
		errorManager_showErrors(element, MAJOR_ERROR, "Major errors occurred during application startup.");
	if (errorManager_hasErrorOccurred(element, MINOR_ERROR))
		errorManager_showErrors(element, MINOR_ERROR, "Minor errors occurred during application startup.");
	/* From now on all error messages are immediately displayed on the screen */
	context->errorAlwaysCollect = 0;

	/* Initialize cur values */
	initializeCurValues(context);

	return context;
}

/**
 * DestroyRunner function.
 */
void destroyRunner(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	DSPEElement *element = (DSPEElement*) context;

	/* During application shutdown, errors are not displayed on the screen */
	context->errorAlwaysCollect = 1;

	/* Application shutdown() function call */
	MatrixBenchMatrixMicroBench_Application_shutdown((DSPEApplication*) context);


	/* DSPEInputParameters dispose */
	context->inputParametersNumElements = 0;
	context->inputParametersCurr = NULL;
	context->inputParametersTail = NULL;
	while (context->inputParametersHead != NULL) {
		DSPEInputParameters *params = context->inputParametersHead;	
		context->inputParametersHead = params->next;
		
		params->next = NULL;
		DSPEInputParameters_dispose((DSPEApplication*) context, params);
	}

	/* Dispose cur values */
	disposeCurValues(context);

	/* Show errors occurred during application shutdown */
	if (errorManager_hasErrorOccurred(element, FATAL_ERROR))
		errorManager_showErrors(element, FATAL_ERROR, "Fatal errors occurred during application shutdown.");
	if (errorManager_hasErrorOccurred(element, SEVERE_ERROR))
		errorManager_showErrors(element, SEVERE_ERROR, "Severe errors occurred during application shutdown.");
	if (errorManager_hasErrorOccurred(element, MAJOR_ERROR))
		errorManager_showErrors(element, MAJOR_ERROR, "Major errors occurred during application shutdown.");
	if (errorManager_hasErrorOccurred(element, MINOR_ERROR))
		errorManager_showErrors(element, MINOR_ERROR, "Minor errors occurred during application shutdown.");

	/* Profile manager dispose */
	profileManager_dispose(element);

	/* Info manager collect info support dispose */
	memorySupport_dispose(context->collectedInfo);
	/* Info manager collect log support dispose */
	memorySupport_dispose(context->collectedLog);

	/* Error manager dispose */
	errorManager_dispose(element);

	/* Close log file */
	closeLogFile(context);

	/* Context dispose */
	memorySupport_dispose(context);

}

/**
 * ResetProfileData function.
 */
static INLINE void resetProfileData(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	profile *profileData = NULL;
	profileNode *curNode = NULL;
	DSPEProfileNode **profileQueue;
	size_t i;
	
	// Reset times and counters
	profileData = context->profileData;
	DSPEProfileTime_init(profileData->startTime);
	DSPEProfileTime_init(profileData->endTime);
	profileData->samplesCount = 0;
	profileData->processCount = 0;
	DSPEProfileTime_init(profileData->ticks);

	// Reset queue
	profileQueue = (CAST_TO_OWNER((DSPEApplication*) context))->profileQueue;
	for (i = 0; i < profileIDCount; i++) {
		curNode = (profileNode*) profileQueue[i];
		DSPEProfileTime_init(curNode->startTime);
		DSPEProfileTime_init(curNode->totalTicks);
		DSPEProfileTime_initMin(curNode->minTicks);
		DSPEProfileTime_init(curNode->maxTicks);
		curNode->count = 0;
	}

	// Reset lag counters
	profileData->lagCountEnabled = 0;
	profileData->lag = 0;
	profileData->totalLag = 0;
	profileData->minLag = UINT_MAX;
	profileData->maxLag = 0;
	profileData->lagCount = 0;

	// Reset latency counters
	DSPEProfileTime_init(profileData->startLatency);
	DSPEProfileTime_init(profileData->totalLatency);
	DSPEProfileTime_initMin(profileData->minLatency);
	DSPEProfileTime_init(profileData->maxLatency);
	profileData->latencyCount = 0;
	
	// Reset responseTime counters
	DSPEProfileTime_init(profileData->startResponse);
	DSPEProfileTime_init(profileData->totalResponse);
	DSPEProfileTime_initMin(profileData->minResponse);
	DSPEProfileTime_init(profileData->maxResponse);
	profileData->responseCount = 0;	
}

/**
 * ResetInputParameters function.
 * Updates application parameter input values by copying
 * current last values to application parameter inputs.
 */
static INLINE void resetInputParameters(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	MatrixBenchMatrixMicroBench_Application *application = (MatrixBenchMatrixMicroBench_Application*) context;
	/* Reset application parameter inputs. */
	if (*application->paramIn_SignalDelay != *context->paramIn_SignalDelay_curValue) {
		MicroBenchCounter_StandardGate_set((DSPEElement*) context, application->paramIn_SignalDelay, context->paramIn_SignalDelay_curValue);
	}
	if (*application->paramIn_AutomaticStop != *context->paramIn_AutomaticStop_curValue) {
		MicroBenchFlag_StandardGate_set((DSPEElement*) context, application->paramIn_AutomaticStop, context->paramIn_AutomaticStop_curValue);
	}
	if (*application->paramIn_SamplesToProcess != *context->paramIn_SamplesToProcess_curValue) {
		MicroBenchCounter_StandardGate_set((DSPEElement*) context, application->paramIn_SamplesToProcess, context->paramIn_SamplesToProcess_curValue);
	}
	if (*application->paramIn_ShowInfo != *context->paramIn_ShowInfo_curValue) {
		MicroBenchFlag_StandardGate_set((DSPEElement*) context, application->paramIn_ShowInfo, context->paramIn_ShowInfo_curValue);
	}
	if (*application->paramIn_SignalSource != *context->paramIn_SignalSource_curValue) {
		MicroBenchFlag_StandardGate_set((DSPEElement*) context, application->paramIn_SignalSource, context->paramIn_SignalSource_curValue);
	}
}

/**
 * Loads a new set of input parameters.
 */
static INLINE void loadNewInputParameterSet(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	const DSPEElement *element = (const DSPEElement*) context;
	DSPEInputParameters *params = context->inputParametersCurr;
	DSPEInputParameterValue *value = NULL;
	size_t i;

	if (params == NULL)
		return;

	/* Update parameters to next */
	context->inputParametersCurr = params->next;

	infoManager_writeInfo(element, "Loading input parameters");
	infoManager_writeInfo(element, "-------------------------------------------");

	value = params->headParam;
	for (i = 0; i < params->numParams; i++) {
		int error = 0;
		// Remark: optionPn may modify optionPnString in case of group gate! 
		// A copy is therefore made and sent to optionPn function to keep the original information.
		int len = stringSupport_length(value->optionPnString);
		char *optionPnStr = allocateAndInitMemory(element, len + 1, sizeof(char));
		memorySupport_copyBlock(optionPnStr, value->optionPnString, len * sizeof(char));
		optionPn(context, optionPnStr, value->value, &error);
		disposeMemory(optionPnStr);

		if (error)
			infoManager_writeInfo(element, "failed to set %s\t(%s) = %s", value->optionPnString, value->gateName, value->value);
		else
			infoManager_writeInfo(element, "%s\t(%s): %s", value->optionPnString, value->gateName, value->value);

		value = value->nextValue;
	}
	infoManager_writeInfo(element, "-------------------------------------------");
}

/**
 * RunnerPreProcess function.
 */
void MatrixBenchMatrixMicroBench_Application_runnerPreProcess(DSPEComponent *component) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) component;
	DSPEElement *element = (DSPEElement*) context;

		if (profileManager_isBenchmarkingDone((DSPEElement*) context)) {
		// Load new set of input parameters
		loadNewInputParameterSet(context);
	}
	infoManager_writeInfo(element, "--- RUN STARTED ---");
	/* Application preprocessing; forces the output parameters update */
	MatrixBenchMatrixMicroBench_Application_preProcess(component);

	/* Capture application process start time */
	profileManager_captureStartTime(element, MatrixMicroBench_ID);
}

/**
 * RunnerPostProcess function.
 */
void MatrixBenchMatrixMicroBench_Application_runnerPostProcess(DSPEComponent *component) {
	register size_t i;
	unsigned int count;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) component;
	DSPEElement *element = (DSPEElement*) context;


	/* Capture application process end time */
	profileManager_captureEndTime(element, MatrixMicroBench_ID);

	/* Application postprocessing; forces the output parameters update */
	MatrixBenchMatrixMicroBench_Application_postProcess(component);
	/* Display parameter output values */
	displayOutput(context);
	/* Application reset */
	MatrixBenchMatrixMicroBench_Application_reset(component);
	resetInputParameters(context);

	/* Display collected info - Don't need to lock since the application is stopped */
	for (i = 0; i < infoIDCount; i++) {
		count = context->collectedInfo[i];
		if (count == 0)
			continue;

		/* Write info to the screen */
		printf("%s (%u times)\n", infoSupport_getCollectedInfoString((infoID) i), count);
	}
	/* Write collected log - Don't need to lock since the application is stopped */
	for (i = 0; i < infoIDCount; i++) {
		count = context->collectedLog[i];
		if (count == 0)
			continue;

		/* Write info to log file */
		fprintf(context->logFile, "%s (%u times)\n", infoSupport_getCollectedInfoString((infoID) i), count);
	}

	/* Show application profile */
	profileManager_showProfileInfo(element, MatrixMicroBench_ID);

	/* Write application profile */
	profileManager_writeProfileInfo(element, MatrixMicroBench_ID);

	/* Write profile info header */
	profileManager_writeProfileInfoHeader(element);
	/* Show profile info */
	infoManager_writeInfo(element, "ID\tmin [ms]\tmean [ms]\tmax [ms]\tnum measures\ttotal [ms]");
	infoManager_writeInfo(element, "--------------------------------------------------------------------------------");
	for (i = 0;  i < profileIDCount; i++) {
		if (i == MatrixMicroBench_ID)
			/* Application profile info has already been shown */ 
			continue;
		profileManager_showProfileInfo(element, (profileID) i);
		/* Write to profile file */
		profileManager_writeProfileInfo(element, (profileID) i);
	}
	infoManager_writeInfo(element, "--------------------------------------------------------------------------------");

	/* Reset profile data */
	resetProfileData(context);

	infoManager_writeInfo(element, "--- RUN TERMINATED ---");
	/* Benchmark support */
	if (!profileManager_updateBenchmarking(element))
		engineManager_run(element);
	else {
		/* Close profileFile */
		profileManager_closeProfileFile(element);
	}
	/* inputParameters support */
	if (context->inputParametersCurr != NULL) {
		engineManager_run(element);
	}
}

/**
 * Run function.
 * Executes the application processing until the command stop is called.
 */
void run(MatrixBenchMatrixMicroBench_Application_cmd *context,long int iter) {
	long int i;
	DSPEElement *element = (DSPEElement*) context;

	// Check for errors occurred during application startup
	if (context->errorForceApplicationStop) {
		// REMARK: For all other events, nothing has to be done since the
		// application is already on stop.
		if (errorManager_hasErrorOccurred(element, FATAL_ERROR)) {
			errorManager_showErrors(element, FATAL_ERROR, "The application has terminated since some fatal errors occurred while running.");
			errorManager_clearErrors(element, FATAL_ERROR);
			engineManager_quit(element);
		}
	}

	while (engineManager_isRunning(element)) {

		MatrixBenchMatrixMicroBench_Application_runnerPreProcess((DSPEComponent*) context);

		if (context->errorForceApplicationStop) {
			engineManager_stop(element);
		}

		if (iter == 0) {
			printf("\n\nPress CTRL+C to quit!\n\n");
			fflush(stdout);
			while (!engineManager_isStopped(element) && !engineManager_isStopping(element)) {
				MatrixBenchMatrixMicroBench_Application_process((DSPEComponent*) context);
			}
		} else {
			for (i = 0; (i < iter) && (!engineManager_isStopped(element) && !engineManager_isStopping(element)); i++) {
				MatrixBenchMatrixMicroBench_Application_process((DSPEComponent*) context);
			}
		}

		MatrixBenchMatrixMicroBench_Application_runnerPostProcess((DSPEComponent*) context);

		if (context->errorForceApplicationStop) {
			context->errorForceApplicationStop = 0;
			if (errorManager_hasErrorOccurred(element, FATAL_ERROR)) {
				errorManager_showErrors(element, FATAL_ERROR, "The application has terminated since some fatal errors occurred while running.");
				errorManager_clearErrors(element, FATAL_ERROR);
				engineManager_quit(element);
			} else if (errorManager_hasErrorOccurred(element, SEVERE_ERROR)) {
				errorManager_showErrors(element, SEVERE_ERROR, "The application has stopped since some severe errors occurred while running.");
				errorManager_clearErrors(element, SEVERE_ERROR);
				// REMARK: Do nothing since the application is already on stop.
			} else if (errorManager_hasErrorOccurred(element, MAJOR_ERROR)) {
				errorManager_showErrors(element, MAJOR_ERROR, "The application has restarted since some major errors occurred while running.");
				errorManager_clearErrors(element, MAJOR_ERROR);
				engineManager_run(element);
			}
		}
	}
}

