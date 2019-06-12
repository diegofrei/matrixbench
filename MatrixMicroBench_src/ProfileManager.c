/**
 * File: ProfileManager.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:53 CEST 2019
 */
#include "ProfileManager.h"

#include "StringManager.h"
#include "InfoManager.h"
#include "ErrorManager.h"
#include "MemoryManager.h"
#include "RunnerGround.h"

#include <limits.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

// Measures support enum
typedef enum measures {
	MEASURES_MIN,
	MEASURES_MEAN,
	MEASURES_MAX,
	MEASURES_COUNT,
	MEASURES_TOTAL
} measures_e;

static INLINE const char* getMeasures_typeText(measures_e type) {
	switch (type) {
	case MEASURES_MIN	: return "Min";
	case MEASURES_MEAN	: return "Mean";
	case MEASURES_MAX	: return "Max";
	case MEASURES_COUNT : return "Measures";
	case MEASURES_TOTAL : return "Total";
	default				: return "";
	}
}

static INLINE int getMeasures_columnIndex(measures_e type) {
	switch (type) {
	case MEASURES_MIN	: return 2;
	case MEASURES_MEAN	: return 3;
	case MEASURES_MAX	: return 4;
	case MEASURES_COUNT : return 5;
	case MEASURES_TOTAL	: return 6;
	default				: return 0;
	}
}
/* PROFILE SUPPORT */

/**
 * ProfileManager_initProfileQueue function
 */
DSPEProfileNode** profileManager_initProfileQueue(const DSPEElement *element) {
	size_t i;
	profileNode *node;
	DSPEProfileNode **profileQueue = (DSPEProfileNode**) allocateMemory(element, profileIDCount * sizeof(profileNode*));
	for (i = 0; i < profileIDCount; i++) {
		// Initialize profileNode
		node = (profileNode*) allocateMemory(element, sizeof(profileNode));
		DSPEProfileTime_init(node->startTime);
		DSPEProfileTime_init(node->totalTicks);
		DSPEProfileTime_initMin(node->minTicks);
		DSPEProfileTime_init(node->maxTicks);
		node->count = 0;
		((DSPEProfileNode*) node)->id = i;

		profileQueue[i] = (DSPEProfileNode*) node;
	}
	return profileQueue;
}

/**
 * ProfileManager_disposeProfileQueue function
 */
void profileManager_disposeProfileQueue(const DSPEElement *element, DSPEProfileNode **profileQueue) {
	size_t i;

	for (i = 0; i < profileIDCount; i++)
		disposeMemory(profileQueue[i]);
	disposeMemory(profileQueue);
}

/**
 * ProfileManager_initialize function
 */
void profileManager_initialize(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = (profile*) allocateMemory(element, sizeof(profile));

	// Initialize queue
	(CAST_TO_OWNER((DSPEApplication*) context))->profileQueue = profileManager_initProfileQueue(element);

	// Initialize times and counters
	DSPEProfileTime_init(profileData->startTime);
	DSPEProfileTime_init(profileData->endTime);
	profileData->samplesCount = 0;
	profileData->processCount = 0;
	DSPEProfileTime_init(profileData->ticks);

	// Initialize lag counters
	profileData->lagCountEnabled = 0;
	profileData->lag = 0;
	profileData->totalLag = 0;
	profileData->minLag = UINT_MAX;
	profileData->maxLag = 0;
	profileData->lagCount = 0;

	// Initialize latency counters
	DSPEProfileTime_init(profileData->startLatency);
	DSPEProfileTime_init(profileData->totalLatency);
	DSPEProfileTime_initMin(profileData->minLatency);
	DSPEProfileTime_init(profileData->maxLatency);
	profileData->latencyCount = 0;

	// Initialize responseTime counters
	DSPEProfileTime_init(profileData->startResponse);
	DSPEProfileTime_init(profileData->totalResponse);
	DSPEProfileTime_initMin(profileData->minResponse);
	DSPEProfileTime_init(profileData->maxResponse);
	profileData->responseCount = 0;

	// Initialize profile unit
	profileData->profileUnit = MatrixMicroBench_MatrixTarget_ID;

	context->profileData = profileData;
}

/**
 * ProfileManager_dispose function
 */
void profileManager_dispose(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	profileManager_disposeProfileQueue(element, ((DSPEElement*) context)->owner->profileQueue);
	disposeMemory(profileData);
}

/**
 * ProfileSupport_getProfileString function
 */
const char* profileSupport_getProfileString(const profileID id) {
	switch (id) {
	case MatrixMicroBench_MatrixSource_ID:
		return "MatrixMicroBench_MatrixSource";
	case MatrixMicroBench_MatrixMultiplier_ID:
		return "MatrixMicroBench_MatrixMultiplier";
	case MatrixMicroBench_MatrixTarget_ID:
		return "MatrixMicroBench_MatrixTarget";
	case MatrixMicroBench_Evaluator_ID:
		return "MatrixMicroBench_Evaluator";
	case MatrixMicroBench_ID:
		return "MatrixMicroBench";
	default:
		return "Invalid profile id";
	}
}

/**
 * ProfileSupport_getProfileID function
 */
profileID profileSupport_getProfileID(char *unitID, char *typeID) {
	if (stringSupport_compare(unitID, "MatrixMicroBench_MatrixSource") == 0)
		return MatrixMicroBench_MatrixSource_ID;
	if (stringSupport_compare(unitID, "MatrixMicroBench_MatrixMultiplier") == 0)
		return MatrixMicroBench_MatrixMultiplier_ID;
	if (stringSupport_compare(unitID, "MatrixMicroBench_MatrixTarget") == 0)
		return MatrixMicroBench_MatrixTarget_ID;
	if (stringSupport_compare(unitID, "MatrixMicroBench_Evaluator") == 0)
		return MatrixMicroBench_Evaluator_ID;
	return (profileID) 0;
}

/**
 * GetProfileNode function.
 */
static INLINE profileNode* getProfileNode(const DSPEElement *element, profileID id) {
	return (profileNode*) ((DSPEProfileNode**) element->owner->profileQueue)[id];
}

/**
 * ProfileManager_captureStartTime function
 */
void profileManager_captureStartTime(const DSPEElement *element, profileID id) {
	profile *profileData = NULL;
	profileNode *node = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (id == MatrixMicroBench_ID) {
		// Application profile
		DSPEProfileTime_setCurrentTicks(profileData->startTime);
		DSPEProfileTime_init(profileData->endTime);
		profileData->samplesCount = 0;
		profileData->processCount = 0;
		DSPEProfileTime_init(profileData->ticks);
		return;
	}
	// Unit profile - Find node
	node = getProfileNode(element, id);
	// Capture start time
	DSPEProfileTime_setCurrentTicks(node->startTime);
}

/**
 * ProfileManager_captureEndTime function
 */
void profileManager_captureEndTime(const DSPEElement *element, profileID id) {
	profile *profileData = NULL;
	profileNode *node = NULL;
	DSPEProfileTime ticks;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (id == MatrixMicroBench_ID) {
		// Application profile
		profileData = context->profileData;
		DSPEProfileTime_setCurrentTicks(profileData->endTime);
		profileData->ticks = profileData->endTime;
		DSPEProfileTime_sub(profileData->ticks, profileData->startTime);
		return;
	}
	// Unit profile - Find node
	node = getProfileNode(element, id);
	if (DSPEProfileTime_isSet(node->startTime) == 0)
		// CaptureStartTime has not been called
		return;

	// Compute elapsed ticks
	DSPEProfileTime_setCurrentTicks(ticks);
	DSPEProfileTime_sub(ticks, node->startTime);
	DSPEProfileTime_add(node->totalTicks, ticks);
	if (DSPEProfileTime_cmp(ticks, node->minTicks, <))
		node->minTicks = ticks;
	if (DSPEProfileTime_cmp(ticks, node->maxTicks, >))
		node->maxTicks = ticks;
	node->count++;
}

/**
 * ProfileManager_incrementSamplesCount function
 */
void profileManager_incrementSamplesCount(const DSPEElement *element, const unsigned int increment) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	context->profileData->samplesCount += increment;
	context->profileData->processCount++;
}

/**
 * ProfileManager_getSamplesCount function
 */
unsigned int profileManager_getSamplesCount(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	return context->profileData->samplesCount;
}

/**
 * ProfileManager_getElapsedTime function
 * Returns the elapsed time in seconds
 */
double profileManager_getElapsedTime(const DSPEElement *element) {
	DSPEProfileTime ticks;
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (DSPEProfileTime_isSet(profileData->endTime) == 0)
		// The application is still running, compute elapsed time in seconds
		DSPEProfileTime_setCurrentTicks(ticks);
	else
		// The application is stopped, compute elapsed time in seconds
		ticks = profileData->endTime;

	DSPEProfileTime_sub(ticks, profileData->startTime);
	return DSPEProfileTime_getMilliseconds(ticks) / 1000.0;
}

/**
 * ProfileManager_getMeanProcessTime function
 * Returns the mean process time in milliseconds
 */
double profileManager_getMeanProcessTime(const DSPEElement *element, profileID id) {
	DSPEProfileTime ticks;
	profile *profileData = NULL;
	profileNode *node = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (id == MatrixMicroBench_ID) {
		// Application profile
		profileData = context->profileData;
		if (profileData->processCount == 0)
			return 0.0;
		// Compute mean process time in milliseconds
		ticks = profileData->endTime;
		DSPEProfileTime_sub(ticks, profileData->startTime);
		return DSPEProfileTime_getMilliseconds(ticks) / (double) profileData->processCount;
	}

	// Unit profile - Find node
	node = getProfileNode(element, id);
	if (node->count == 0)
		// CaptureEndTime has not been called
		return 0.0;

	// Compute mean process time in milliseconds
	return DSPEProfileTime_getMilliseconds(node->totalTicks) / (double) node->count;
}

/**
 * ProfileManager_getMinProcessTime function
 * Returns the min process time in milliseconds
 */
double profileManager_getMinProcessTime(const DSPEElement *element, profileID id) {
	profileNode *node = NULL;

	if (id == MatrixMicroBench_ID)
		// Application min process time not avaiable
		return 0.0;

	// Unit profile - Find node
	node = getProfileNode(element, id);
	if (node->count == 0)
		return 0.0;
	// Compute min process time in milliseconds
	return DSPEProfileTime_getMilliseconds(node->minTicks);
}

/**
 * ProfileManager_getMaxProcessTime function
 * Returns the max process time in milliseconds
 */
double profileManager_getMaxProcessTime(const DSPEElement *element, profileID id) {
	profileNode *node = NULL;

	if (id == MatrixMicroBench_ID)
		// Application max process time not avaiable
		return 0.0;

	// Unit profile - Find node
	node = getProfileNode(element, id);
	if (node->count == 0)
		return 0.0;
	// Compute max process time in milliseconds
	return DSPEProfileTime_getMilliseconds(node->maxTicks);
}

/**
 * ProfileManager_getTotalProcessTime function
 * Returns the total process time in milliseconds
 */
double profileManager_getTotalProcessTime(const DSPEElement *element, profileID id) {
	DSPEProfileTime ticks;
	profile *profileData = NULL;
	profileNode *node = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (id == MatrixMicroBench_ID) {
		// Application profile
		profileData = context->profileData;
		if (profileData->processCount == 0)
			return 0.0;
		// Compute total process time in milliseconds
		ticks = profileData->endTime;
		DSPEProfileTime_sub(ticks, profileData->startTime);
		return DSPEProfileTime_getMilliseconds(ticks);
	}

	// Unit profile - Find node
	node = getProfileNode(element, id);
	if (node->count == 0)
		// CaptureEndTime has not been called
		return 0.0;

	// Compute total process time in milliseconds
	return DSPEProfileTime_getMilliseconds(node->totalTicks);
}

/**
 * ProfileManager_getThroughput function
 */
double profileManager_getThroughput(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (DSPEProfileTime_isSet(profileData->ticks) == 0)
		return 0.0;
	return profileData->samplesCount * 1000.0 / DSPEProfileTime_getMilliseconds(profileData->ticks);
}

/**
 * ProfileManager_isProfileUnit function
 */
int profileManager_isProfileUnit(const DSPEElement *element, profileID id) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	return context->profileData->profileUnit == id;
}

/* LAG AND LATENCY SUPPORT */

/**
 * ProfileManager_sendSignal function
 */
void profileManager_sendSignal(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (profileData->lagCountEnabled)
		return;

	profileData->lag = 0;
	profileData->lagCountEnabled = 1;
	DSPEProfileTime_setCurrentTicks(profileData->startLatency);
}

/**
 * ProfileManager_receiveSignal function
 */
void profileManager_receiveSignal(const DSPEElement *element) {
	profile *profileData = NULL;
	DSPEProfileTime ticks;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (!profileData->lagCountEnabled)
		return;

	profileData->lagCountEnabled = 0;
	// Compute lag
	profileData->totalLag += profileData->lag;
	if (profileData->lag < profileData->minLag)
		profileData->minLag = profileData->lag;
	if (profileData->lag > profileData->maxLag)
		profileData->maxLag = profileData->lag;
	profileData->lagCount++;

	// Compute latency
	DSPEProfileTime_setCurrentTicks(ticks);
	DSPEProfileTime_sub(ticks, profileData->startLatency);
	DSPEProfileTime_add(profileData->totalLatency, ticks);
	if (DSPEProfileTime_cmp(ticks, profileData->minLatency, <))
		profileData->minLatency = ticks;
	if (DSPEProfileTime_cmp(ticks, profileData->maxLatency, >))
		profileData->maxLatency = ticks;
	profileData->latencyCount++;
}

/**
 * ProfileManager_isSignalSent function
 */
int profileManager_isSignalSent(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	return context->profileData->lagCountEnabled;
}

/**
 * ProfileManager_incrementLag function
 */
void profileManager_incrementLag(const DSPEElement *element, const unsigned int increment) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (!profileData->lagCountEnabled)
		return;
	profileData->lag += increment;
}

/**
 * ProfileManager_getMeanLag function
 */
unsigned int profileManager_getMeanLag(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (profileData->lagCount == 0)
		return 0;
	return profileData->totalLag / profileData->lagCount;
}

/**
 * ProfileManager_getMinLag function
 */
unsigned int profileManager_getMinLag(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (context->profileData->lagCount == 0)
		return 0;
	return context->profileData->minLag;
}

/**
 * ProfileManager_getMaxLag function
 */
unsigned int profileManager_getMaxLag(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (context->profileData->lagCount == 0)
		return 0;
	return context->profileData->maxLag;
}

/**
 * ProfileManager_getMeanLatency function
 * Returns the mean latency in milliseconds
 */
double profileManager_getMeanLatency(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (profileData->latencyCount == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(profileData->totalLatency) / (double) profileData->latencyCount;
}

/**
 * ProfileManager_getMinLatency function
 * Returns the min latency in milliseconds
 */
double profileManager_getMinLatency(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (context->profileData->latencyCount == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(context->profileData->minLatency);
}

/**
 * ProfileManager_getMaxLatency function
 * Returns the max latency in milliseconds
 */
double profileManager_getMaxLatency(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (context->profileData->latencyCount == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(context->profileData->maxLatency);
}

/**
 * ProfileManager_receiveData function
 */
void profileManager_receiveData(const DSPEElement *element) {
	profile *profileData = NULL;
	DSPEProfileTime ticks;
	DSPEProfileTime curTicks;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;

	DSPEProfileTime_setCurrentTicks(curTicks);

	// First time we start counters
	if (DSPEProfileTime_isSet(profileData->startResponse) == 0) {
		profileData->startResponse = curTicks;
		return;
	}

	ticks = curTicks;
	DSPEProfileTime_sub(ticks, profileData->startResponse);
	profileData->startResponse = curTicks;

	// Compute responseTime
	DSPEProfileTime_add(profileData->totalResponse, ticks);
	if (DSPEProfileTime_cmp(profileData->minResponse, ticks, >))
		profileData->minResponse = ticks;
	if (DSPEProfileTime_cmp(profileData->maxResponse, ticks, <))
		profileData->maxResponse = ticks;
	profileData->responseCount++;
}

/**
 * ProfileManager_getMeanResponseTime function
 * Returns the mean responseTime in milliseconds
 */
double profileManager_getMeanResponseTime(const DSPEElement *element) {
	profile *profileData = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	profileData = context->profileData;
	if (profileData->responseCount == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(profileData->totalResponse) / (double) profileData->responseCount;
}

/**
 * ProfileManager_getMinResponseTime function
 * Returns the min responseTime in milliseconds
 */
double profileManager_getMinResponseTime(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (context->profileData->responseCount == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(context->profileData->minResponse);
}

/**
 * ProfileManager_getMaxResponse function
 * Returns the max response time in milliseconds
 */
double profileManager_getMaxResponseTime(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (context->profileData->responseCount == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(context->profileData->maxResponse);
}

/**
 * ProfileManager_getTotalUnitProcessTime function
 */
double profileManager_getTotalUnitProcessTime(const DSPEElement *element) {
	DSPEProfileTime totalTicks;
	profileNode *node = NULL;
	DSPEProfileTime_init(totalTicks);
	node = getProfileNode(element, MatrixMicroBench_MatrixSource_ID);
	if (node->count > 0) DSPEProfileTime_add(totalTicks, node->totalTicks);
	node = getProfileNode(element, MatrixMicroBench_MatrixMultiplier_ID);
	if (node->count > 0) DSPEProfileTime_add(totalTicks, node->totalTicks);
	node = getProfileNode(element, MatrixMicroBench_MatrixTarget_ID);
	if (node->count > 0) DSPEProfileTime_add(totalTicks, node->totalTicks);
	node = getProfileNode(element, MatrixMicroBench_Evaluator_ID);
	if (node->count > 0) DSPEProfileTime_add(totalTicks, node->totalTicks);
	if (DSPEProfileTime_isSet(totalTicks) == 0)
		return 0.0;
	return DSPEProfileTime_getMilliseconds(totalTicks);
}

/**
 * ProfileManager_showProfileInfo function
 */
void profileManager_showProfileInfo(const DSPEElement *element, profileID id) {
	const char *applID;
	profile *profileData = NULL;
	profileNode *node = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;


	if (id == MatrixMicroBench_ID) {
		// Application
		profileData = context->profileData;
		applID = profileSupport_getProfileString(id);

		infoManager_writeInfo(element, "\n%s elapsed time:\t%.6f\ts", applID, profileManager_getElapsedTime(element));
		infoManager_writeInfo(element, "%s total process time of units:\t%.6f\ts", applID, profileManager_getTotalUnitProcessTime(element) / 1000);
		infoManager_writeInfo(element, "%s mean process time for sample (average of %u measures):\t%.6f\tms", applID, profileData->processCount, profileManager_getMeanProcessTime(element, MatrixMicroBench_ID));
		if (profileData->samplesCount > 0)
			infoManager_writeInfo(element, "%s throughput:\t%.6f\tsamples/second", applID, profileManager_getThroughput(element));
		if (profileData->lagCount > 0)
			infoManager_writeInfo(element, "%s lag (average of %u measures, min mean max):\t%u\t%u\t%u\tsamples", applID, profileData->lagCount, profileManager_getMinLag(element), profileManager_getMeanLag(element), profileManager_getMaxLag(element));
		if (profileData->latencyCount > 0)
			infoManager_writeInfo(element, "%s latency (average of %u measures, min mean max):\t%.6f\t%.6f\t%.6f\tms", applID, profileData->latencyCount, profileManager_getMinLatency(element), profileManager_getMeanLatency(element), profileManager_getMaxLatency(element));
		if (profileData->responseCount > 0)
			infoManager_writeInfo(element, "%s response (average of %u measures, min mean max):\t%.6f\t%.6f\t%.6f\tms", applID, profileData->responseCount, profileManager_getMinResponseTime(element), profileManager_getMeanResponseTime(element), profileManager_getMaxResponseTime(element));
		infoManager_writeInfo(element, "");
		return;
	}
	// Unit - Find node
	node = getProfileNode(element, id);
	if (node->count > 0)
		infoManager_writeInfo(element, "%s process time:\t%.6f\t%.6f\t%.6f\t%u\t%.6f", profileSupport_getProfileString(id), DSPEProfileTime_getMilliseconds(node->minTicks), profileManager_getMeanProcessTime(element, id), DSPEProfileTime_getMilliseconds(node->maxTicks), node->count, DSPEProfileTime_getMilliseconds(node->totalTicks));
}


/******************************************************************************
 * BENCHMARKING SUPPORT
 ******************************************************************************/

/**
 * GetBenchmarkHandler function.
 */
static INLINE DSPEBenchmarkHandler* getBenchmarkHandler(const DSPEElement *element) {
	DSPEOwner *owner = CAST_TO_OWNER(element->application);
	return (DSPEBenchmarkHandler*) owner->handlers[HANDLER_INDEX_BENCHMARK];
}

/**
 * addBenchmarkHandler function.
 */
static INLINE void addBenchmarkHandler(DSPEApplication *application, DSPEBenchmarkHandler *handler) {
	DSPEOwner *ownerExt = CAST_TO_OWNER(application);
	DSPEHandler **handlers = ownerExt->handlers;

	/* lazy initialization of handlers array */
	if (handlers == NULL) {
		memoryManager_allocateHandlerPool((DSPEElement*) application, ownerExt);
		handlers = ownerExt->handlers;
	}

	/* Add BenchmarkHandler to handlers */
	handlers[HANDLER_INDEX_BENCHMARK] = (DSPEHandler*) handler;
}

/**
 * resetBenchmarkHandler function
 */
static INLINE void resetBenchmerkHandler(DSPEHandler *handler) {
}

/**
 * disposeBenchmarkHandler function
 */
static void disposeBenchmerkHandler(DSPEHandler *handler) {
	disposeMemory(handler);
}

/**
 * ProfileManager_initBenchmarkHandler function
 */
void profileManager_initBenchmarkHandler(DSPEApplication *application) {
	DSPEBenchmarkHandler *handler = (DSPEBenchmarkHandler*) allocateMemory((DSPEElement*) application, sizeof(DSPEBenchmarkHandler));
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) application;

	initDSPEElement((DSPEElement*) handler, (DSPEElement*) application);
	initDSPEHandler((DSPEHandler*) handler, (DSPEElement*) application);

	((DSPEHandler*) handler)->reset = resetBenchmerkHandler;
	((DSPEHandler*) handler)->dispose = disposeBenchmerkHandler;

	addBenchmarkHandler(application, handler);

	/* MultiRun benchmarking support */
	handler->curNumRun = 0;
	handler->numRunMin = 0;
	handler->numRunMax = context->settings.numMultiRuns;
}

/**
 * ProfileManager_updateBenchmarking function
 */
int profileManager_updateBenchmarking(const DSPEElement *element) {
	DSPEBenchmarkHandler *context = getBenchmarkHandler(element);

	context->curNumRun++;
	if (context->curNumRun < context->numRunMax) {
		/* Write runCount */
		profileManager_writeNumRun(element, context->curNumRun);
		// benchmark not yet completed
		return 0;
	}
	context->curNumRun = context->numRunMin;
	/* Write averages */
	profileManager_writeAverages(element, context->numRunMax);

	/* Close worksheet */
	profileManager_writeWorksheetTail(element);

	return 1;
}

/**
 * ProfileManager_initBenchmarking function
 */
void profileManager_initBenchmarking(const DSPEElement *element) {
	DSPEBenchmarkHandler *handler = getBenchmarkHandler(element);
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;


	/* Update default handler with settings */
	if (context->settings.changed) {
		context->settings.changed = 0;

		/* Set multiRun override */
		if (handler->numRunMax != context->settings.numMultiRuns) {
			infoManager_writeInfo(element, "[SettingsOverride] multiRun from %u to %u", handler->numRunMax, (size_t) context->settings.numMultiRuns);
			handler->numRunMax = (size_t) context->settings.numMultiRuns;
		}
	}
}

/**
 * ProfileManager_isBenchmarkingDone function
 */
int profileManager_isBenchmarkingDone(const DSPEElement *element) {
	DSPEBenchmarkHandler *handler = getBenchmarkHandler(element);
	return handler->curNumRun == handler->numRunMin;
}

/**
 * profileManager_resetBenchmarkHandler function
 */
void profileManager_resetBenchmarkHandler(const DSPEElement *element) {
	DSPEBenchmarkHandler *handler = getBenchmarkHandler(element);

	/* MultiRun benchmarking support */
	handler->curNumRun = 0;
}

/**
 * profileManager_getBenchmarkMaxNumRuns function
 */
size_t profileManager_getBenchmarkMaxNumRuns(DSPEElement *element) {
	DSPEBenchmarkHandler *context = getBenchmarkHandler(element);
return context->numRunMax;
}

/**
 * profileManager_getBenchmarkCurNumRuns function
 */
size_t profileManager_getBenchmarkCurNumRuns(DSPEElement *element) {
	DSPEBenchmarkHandler *context = getBenchmarkHandler(element);
return context->curNumRun;
}

/**
 * profileManager_getBenchmarkMinBlocksize function
 */
size_t profileManager_getBenchmarkMinBlocksize(DSPEElement *element) {
	return 0;
}

/**
 * profileManager_getBenchmarkMaxBlocksize function
 */
size_t profileManager_getBenchmarkMaxBlocksize(DSPEElement *element) {
	return 0;
}

/**
 * profileManager_getBenchmarkCurBlocksize function
 */
size_t profileManager_getBenchmarkCurBlocksize(DSPEElement *element) {
	return 0;
}

/**
 * profileManager_getBenchmarkMaxEngines function
 */
size_t profileManager_getBenchmarkMaxEngines(DSPEElement *element) {
	return 0;
}

/**
 * profileManager_getBenchmarkCurNumEngines function
 */
size_t profileManager_getBenchmarkCurNumEngines(DSPEElement *element) {
	return 0;
}

/******************************************************************************
 * PROFILING FILE SUPPORT
 ******************************************************************************/


/**
 * ProfileManager_openProfileFile function
 */
void profileManager_openProfileFile(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	char buffer[21];
	DSPEBenchmarkHandler *handler = getBenchmarkHandler(element);

	if (context->profileFile != NULL || !profileManager_isBenchmarkingDone(element))
		return;

	buffer[0] = '\0';
	sprintf(buffer, "MatrixMicroBench.xml");

	/* Open log file */
	context->profileFile = fopen(buffer, "w");
	if (context->profileFile == NULL)
		errorManager_appendError((DSPEElement*) context, SEVERE_ERROR, "Error opening profile file.");
	else {
		fprintf(context->profileFile,
				"<?xml version=\"1.0\"?>\n"
				"<?mso-application progid=\"Excel.Sheet\"?>\n"
				"<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n"
				"\txmlns:o=\"urn:schemas-microsoft-com:office:office\"\n"
				"\txmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n"
				"\txmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n"
				"\txmlns:html=\"http://www.w3.org/TR/REC-html40\">\n");
	}

	/* Ensure we always close open worksheets tags */
	context->openWorksheets = 0;

	/* Creating first worksheet and adding first rows */

	/* Write results Worksheet */
	profileManager_writeResultsWorksheet(element, 0, 0, handler->numRunMax,  1, 1);

	/* Create worksheet label */
	/* Write Worksheet */
	profileManager_writeWorksheetHead(element, NULL);

	/* Write runCount */
	profileManager_writeNumRun(element, handler->curNumRun);
}

/**
 * ProfileManager_closeProfileFile function
 */
void profileManager_closeProfileFile(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	/* Close profile file */
	if (context->profileFile != NULL) {

		/* Ensure we close all tags */
		if (context->openWorksheets) {
			context->openWorksheets = 0;
			profileManager_writeWorksheetTail(element);
		}

		/* Add workbook closure tag */
		fprintf(context->profileFile, "</Workbook>\n");

		fclose(context->profileFile);
		context->profileFile = NULL;
	}
}

/**
 * ProfileManager_writeWorksheetHead function
 */
void profileManager_writeWorksheetHead(const DSPEElement *element, const char *name) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	char buffer[31];
	size_t len;

	/* Increase open worksheets var */
	context->openWorksheets++;

	if (name == NULL) {
		fprintf(context->profileFile, "<Worksheet ss:Name=\"Sequential\">\n\t<Table>\n");
		return;
	}

	len = strlen(name);
	buffer[0] = '\0';
	if (len > 30) {
		// Truncate! WorkSheet name limit is 31
		sprintf(buffer, "%.*s", 30, &name[0]);
		fprintf(context->profileFile, "<Worksheet ss:Name=\"%s\">\n\t<Table>\n", buffer);
	} else
		fprintf(context->profileFile, "<Worksheet ss:Name=\"%s\">\n\t<Table>\n", name);
}

/**
 * ProfileManager_writeWorksheetTail function
 */
void profileManager_writeWorksheetTail(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;


	fprintf(context->profileFile, "\t</Table>\n</Worksheet>\n");

	/* Decrease open worksheets var */
	context->openWorksheets--;
	}

/**
 * ProfileManager_writeProfileInfoHeader function
 */
void profileManager_writeProfileInfoHeader(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	FILE *file = context->profileFile;

	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Profile ID</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">min [ms]</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">mean [ms]</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">max [ms]</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">measures</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">total unit time [ms]</Data></Cell>\n");
	fprintf(file, "\t</Row>\n");
}

/**
 * ProfileManager_writeProfileInfo function
 */
void profileManager_writeProfileInfo(const DSPEElement *element, profileID id) {
	const char *applID;
	profile *profileData = NULL;
	profileNode *node = NULL;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	FILE *file = context->profileFile;

	if (id == MatrixMicroBench_ID) {
		/* Application */
		profileData = context->profileData;
		applID = profileSupport_getProfileString(id);
		
		/* Elapsed time */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Total elapsed time</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getElapsedTime(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">s</Data></Cell>\n");
		fprintf(file, "\t</Row>\n");
		
		/* Total unit process time */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Total unit process time</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getTotalUnitProcessTime(element) / 1000);
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">s</Data></Cell>\n");
		fprintf(file, "\t</Row>\n");

		/* mean sample process time */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Mean process time for sample</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMeanProcessTime(element, MatrixMicroBench_ID));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">ms</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileData->processCount);
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">measures</Data></Cell>\n");
		fprintf(file, "\t</Row>\n");

		/* Throughput */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Throughput</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getThroughput(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">samples / second</Data></Cell>\n");
		fprintf(file, "\t</Row>\n");

		/* Lag / Latency Header */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\"></Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">min</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">mean</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">max</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">measures</Data></Cell>\n");
		fprintf(file, "\t</Row>\n");

		/* Lag */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Lag [samples]</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileManager_getMinLag(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileManager_getMeanLag(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileManager_getMaxLag(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileData->lagCount);
		fprintf(file, "\t</Row>\n");

		/* Latency */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Latency [ms]</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMinLatency(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMeanLatency(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMaxLatency(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileData->latencyCount);
		fprintf(file, "\t</Row>\n");

		/* ResponseTime */
		fprintf(file, "\t<Row>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">ResponseTime [ms]</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMinResponseTime(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMeanResponseTime(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMaxResponseTime(element));
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", profileData->responseCount);
		fprintf(file, "\t</Row>\n");

		return;
	}
	/* Unit - Find node */
	node = getProfileNode(element, id);
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", profileSupport_getProfileString(id));
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", (node->count == 0) ? 0 : DSPEProfileTime_getMilliseconds(node->minTicks));
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", profileManager_getMeanProcessTime(element, id));
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", DSPEProfileTime_getMilliseconds(node->maxTicks));
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", node->count);
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%.6f</Data></Cell>\n", DSPEProfileTime_getMilliseconds(node->totalTicks));
	fprintf(file, "\t</Row>\n");
}

/**
 * ProfileManager_writeNumRun function
 */
void profileManager_writeNumRun(const DSPEElement *element, size_t curNumRun) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	FILE *file = context->profileFile;

	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Run number</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", 1 + curNumRun);
	fprintf(file, "\t</Row>\n");
}

/**
 * ProfileManager_writeBlockSize function
 */
void profileManager_writeBlockSize(const DSPEElement *element, size_t blockSize) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	FILE *file = context->profileFile;

	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">BlockSize</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"Number\">%u</Data></Cell>\n", blockSize);
	fprintf(file, "\t</Row>\n");
}

/**
 * ProfileManager_writeAverages function
 */
void profileManager_writeAverages(const DSPEElement *element, size_t numRuns) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	FILE *file = context->profileFile;
	size_t i, j;
	size_t offset = 0;
	char buffer[1024];
	char tmp[64];

	/* offset calculation */
	offset += profileIDCount; /* profiles row */
	offset += 4; /* header Lag Latency Throughput rows */;
	offset += 1; /* ResponseTime row */;
	offset += 1; /* mean sample processing time row*/
	offset += 1; /* units process time row */
	offset += 2; /* headers */

	/* Averages separation row */
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2,&quot;Best values&quot;,&quot;Average values&quot;)\"><Data ss:Type=\"String\"></Data></Cell>\n");
	fprintf(file, "\t</Row>\n");

	/* Relative row offsets to cells to average */
	buffer[0] = '\0';
	for (j = 0; j < numRuns - 1; j++) {
		sprintf(tmp, "R[-%u]C,", offset + (j * offset));
		strcat(buffer, tmp);
	}
	/* Omit tailing comma from last one! */
	sprintf(tmp, "R[-%u]C", offset + (j * offset));
	strcat(buffer, tmp);
	/* Elapsed time */
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Total elapsed time</Data></Cell>\n");
	fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">seconds</Data></Cell>\n");
	fprintf(file, "\t</Row>\n");
	
	/* Unit process time */
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Total units process time</Data></Cell>\n");
	fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">seconds</Data></Cell>\n");
	fprintf(file, "\t</Row>\n");

	/* mean sample process time */
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Mean process time for sample</Data></Cell>\n");
	fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">ms</Data></Cell>\n");
	fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">measures</Data></Cell>\n");
	fprintf(file, "\t</Row>\n");

	/* Application: Throughput */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">throughput</Data></Cell>\n");
	fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	fprintf(file, "\t</Row>\n");

	/* Lag / Latency Header */
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\"></Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">min</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">mean</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">max</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">measures</Data></Cell>\n");
	fprintf(file, "\t</Row>\n");

	/* Application: Lag */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">lag</Data></Cell>\n");
	for (j = 0; j < 4; j++) {
		//4: Average min avg max cnt
		fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	}
	fprintf(file, "\t</Row>\n");

	/* Application: Latency */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">latency</Data></Cell>\n");
	for (j = 0; j < 4; j++) {
		//4: Average min avg max cnt
		fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	}
	fprintf(file, "\t</Row>\n");

	/* Application: ResponseTime */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">response time</Data></Cell>\n");
	for (j = 0; j < 4; j++) {
		//4: Average min avg max cnt
		fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
	}
	fprintf(file, "\t</Row>\n");

	/* Profiles Header */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">Profile ID</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">min [ms]</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">mean [ms]</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">max [ms]</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">measures</Data></Cell>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">total</Data></Cell>\n");
	fprintf(file, "\t</Row>\n");

	for (i = 0; i < profileIDCount; i++) {
		/* Skip runner */
		if (i == MatrixMicroBench_ID)
			continue;

		fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", profileSupport_getProfileString((profileID) i));
		for (j = 0; j < 5; j++) {
			//4: Average min avg max cnt tot
			fprintf(file, "\t\t<Cell ss:Formula=\"=IF('Results'!R3C2, MIN(%s), AVERAGE(%s))\">\n\t\t\t<Data ss:Type=\"Number\"></Data>\n\t\t</Cell>\n", buffer, buffer);
		}
		fprintf(file, "\t</Row>\n");
	}
}

/**
 * appendSeparationHeader function.
 */
static INLINE void appendSeparationHeader(FILE *file, const size_t minBlockSize, const size_t maxBlockSize, const char *title) {
	size_t i;

	/* Empty row separator */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\"></Data></Cell>\n\t</Row>\n");

	/* Title */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", title);

	/* blockSize header */
	for (i = minBlockSize; i <= maxBlockSize; i *= 2) {
		fprintf(file,"\t\t<Cell><Data ss:Type=\"String\">%u</Data></Cell>\n", i);
	}
	fprintf(file, "\t</Row>\n");
}

/**
 * appendMeasureRows function.
 */
static INLINE void appendMeasureRows(FILE *file, const size_t minBlockSize, const size_t maxBlockSize, const size_t minEngine, const size_t numEngines, const size_t startLine, const size_t nextBenchmark_offset) {
	size_t i;
	size_t cur_offset = startLine;

	/* Create result references for sequential version */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">Sequential</Data></Cell>\n");
	for (i = minBlockSize; i <= maxBlockSize; i *= 2) {
		fprintf(file,"\t\t<Cell ss:Formula=\"='Sequential'!R%uC2\"><Data ss:Type=\"Number\"></Data></Cell>\n", cur_offset);
		cur_offset += nextBenchmark_offset;
	}
	fprintf(file, "\t</Row>\n");
}

/**
 * appendMultiMeasureRows function.
 */
static INLINE void appendMultiMeasureRows(FILE *file, const size_t minBlockSize, const size_t maxBlockSize, const size_t minEngine, const size_t numEngines, const size_t startLine, const size_t nextBenchmark_offset, measures_e type) {
	size_t i;
	size_t cur_offset = startLine;

	/* Create result references for sequential version */
	fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">%s_Sequential</Data></Cell>\n", getMeasures_typeText(type));
	for (i = minBlockSize; i <= maxBlockSize; i *= 2) {
		fprintf(file, "\t\t<Cell ss:Formula=\"='Sequential'!R%uC%u\"><Data ss:Type=\"Number\"></Data></Cell>\n", cur_offset, getMeasures_columnIndex(type));
		cur_offset += nextBenchmark_offset;
	}
	fprintf(file, "\t</Row>\n");
}

/**
 * ProfileManager_writeResultsWorksheet function
 */
void profileManager_writeResultsWorksheet(const DSPEElement *element, size_t minEngines, size_t maxEngines, size_t numRuns, size_t minBlockSize, size_t maxBlockSize) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	FILE *file = context->profileFile;
	size_t nextBenchmark_offset = 0;
	size_t throughput_start;
	size_t numEngines = 1 + maxEngines - minEngines;
	size_t sequentialRow = 5;
	time_t currentTime;
	struct tm *tm;

	/* Set startline (elapsed time row number) */
	size_t startLine = 1;	/* start from index 1 */

	nextBenchmark_offset = 1; /* step next row */
	nextBenchmark_offset += profileIDCount; /* profiles row + header */
	nextBenchmark_offset += 1; /* blocksize row */
	nextBenchmark_offset += 4; /* header Lag Latency Throughput rows */
	nextBenchmark_offset += 1; /* responseTime row */
	nextBenchmark_offset += 1; /* mean sample processing time row*/
	nextBenchmark_offset += 1; /* total unit process time */

	/* multiRun */
	if (numRuns > 0) {
		startLine += 1; /* run number row */
		startLine += (numRuns * nextBenchmark_offset);

		nextBenchmark_offset *= (numRuns + 1); /* offset happens numRuns + 1 for averages! */
		nextBenchmark_offset += 1;

		if (numRuns > 1)
			sequentialRow++;
	}

	/* Throughput start line */
	throughput_start = startLine + 1;	/* Step to next row starting from startLine */
	throughput_start += 1;	/* mean processTime for sample */
	throughput_start += 1;  /* total unit process time */

	profileManager_writeWorksheetHead(element, "Results");

	// REMARK
	// Write application name on first row / cell. Used for estimation purposes
	// Do not cancel
	currentTime = time(NULL);
	tm = localtime(&currentTime);
	fprintf(file, "\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Application name</Data></Cell>\n\t\t<Cell><Data ss:Type=\"String\">MatrixMicroBench</Data></Cell>\n");
	fprintf(file, "\t</Row>\n\t<Row>\n");
	fprintf(file, "\t\t<Cell><Data ss:Type=\"String\">Executed on</Data></Cell>\n\t\t<Cell><Data ss:Type=\"String\">%02d.%02d.%d %02d:%02d:%02d</Data></Cell>\n", 
		tm->tm_mday,
		1 + tm->tm_mon,
		1900 + tm->tm_year,
		tm->tm_hour,
		tm->tm_min,
		tm->tm_sec);
	fprintf(file, "\t</Row>\n");

	/* If multiruns enabled switch between Average values and bestResults */
	if (numRuns > 1) {
		fprintf(file, "\t<Row>\n\t\t<Cell><Data ss:Type=\"String\">BestResult</Data></Cell>\n");
		fprintf(file, "\t\t<Cell><Data ss:Type=\"Boolean\">0</Data></Cell>\n\t</Row>\n");
	}

	/* Append Elapsed times rows */
	appendSeparationHeader(file, minBlockSize, maxBlockSize, "Elapsed times");
	appendMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, startLine, nextBenchmark_offset);

	/* Append total unit process times rows */
	appendSeparationHeader(file, minBlockSize, maxBlockSize, "Total unit process time");
	appendMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, startLine + 1, nextBenchmark_offset);

	/* Append throughput rows */
	appendSeparationHeader(file, minBlockSize, maxBlockSize, "Throughput");
	appendMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start, nextBenchmark_offset);

	/* Append latency rows */
	appendSeparationHeader(file, minBlockSize, maxBlockSize, "Latency");
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 3, nextBenchmark_offset, MEASURES_MIN);
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 3, nextBenchmark_offset, MEASURES_MEAN);
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 3, nextBenchmark_offset, MEASURES_MAX);

	/* Append lag rows */
	appendSeparationHeader(file, minBlockSize, maxBlockSize, "Lag");
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 2, nextBenchmark_offset, MEASURES_MIN);
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 2, nextBenchmark_offset, MEASURES_MEAN);
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 2, nextBenchmark_offset, MEASURES_MAX);

	/* ResponseTime rows */
	appendSeparationHeader(file, minBlockSize, maxBlockSize, "ResponseTime");
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 4, nextBenchmark_offset, MEASURES_MIN);
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 4, nextBenchmark_offset, MEASURES_MEAN);
	appendMultiMeasureRows(file, minBlockSize, maxBlockSize, minEngines, numEngines, throughput_start + 4, nextBenchmark_offset, MEASURES_MAX);

	profileManager_writeWorksheetTail(element);
}

