/**
 * File: ProfileManager.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "ProfileManager.h"

#include "StringManager.h"
#include "InfoManager.h"
#include "RunnerGround.h"

#include <limits.h>

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
	// Profile unit support disabled.
	return 0;
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

		infoManager_writeInfo(element, "\n%s elapsed time:\t%.3f\ts", applID, profileManager_getElapsedTime(element));
		infoManager_writeInfo(element, "%s total process time of units:\t%.3f\ts", applID, profileManager_getTotalUnitProcessTime(element) / 1000);
		infoManager_writeInfo(element, "%s mean process time for sample (average of %u measures):\t%.3f\tms", applID, profileData->processCount, profileManager_getMeanProcessTime(element, MatrixMicroBench_ID));
		if (profileData->samplesCount > 0)
			infoManager_writeInfo(element, "%s throughput:\t%.3f\tsamples/second", applID, profileManager_getThroughput(element));
		if (profileData->lagCount > 0)
			infoManager_writeInfo(element, "%s lag (average of %u measures, min mean max):\t%u\t%u\t%u\tsamples", applID, profileData->lagCount, profileManager_getMinLag(element), profileManager_getMeanLag(element), profileManager_getMaxLag(element));
		if (profileData->latencyCount > 0)
			infoManager_writeInfo(element, "%s latency (average of %u measures, min mean max):\t%.3f\t%.3f\t%.3f\tms", applID, profileData->latencyCount, profileManager_getMinLatency(element), profileManager_getMeanLatency(element), profileManager_getMaxLatency(element));
		if (profileData->responseCount > 0)
			infoManager_writeInfo(element, "%s response (average of %u measures, min mean max):\t%.3f\t%.3f\t%.3f\tms", applID, profileData->responseCount, profileManager_getMinResponseTime(element), profileManager_getMeanResponseTime(element), profileManager_getMaxResponseTime(element));
		infoManager_writeInfo(element, "");
		return;
	}
	// Unit - Find node
	node = getProfileNode(element, id);
	if (node->count > 0)
		infoManager_writeInfo(element, "%s process time:\t%.3f\t%.3f\t%.3f\t%u\t%.3f", profileSupport_getProfileString(id), DSPEProfileTime_getMilliseconds(node->minTicks), profileManager_getMeanProcessTime(element, id), DSPEProfileTime_getMilliseconds(node->maxTicks), node->count, DSPEProfileTime_getMilliseconds(node->totalTicks));
}

