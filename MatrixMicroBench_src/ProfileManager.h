/**
 * File: ProfileManager.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#ifndef ProfileManager_h
#define ProfileManager_h

#include "DSPEElements.h"

// Profiling with benchmarking support
#define PROFILE_BENCHMARKING
/* Profile ids */
typedef enum profileID {
	MatrixMicroBench_MatrixSource_ID,
	MatrixMicroBench_MatrixMultiplier_ID,
	MatrixMicroBench_MatrixTarget_ID,
	MatrixMicroBench_Evaluator_ID,
	MatrixMicroBench_ID,
	profileIDCount
} profileID;

/* BenchmarkHandler support */
typedef struct DSPEBenchmarkHandler DSPEBenchmarkHandler;

struct DSPEBenchmarkHandler {
	DSPEHandler handler;

	/* Multirun benchmarking */
	size_t curNumRun;
	size_t numRunMin;
	size_t numRunMax;
};
#ifdef __cplusplus
extern "C" {
#endif

/* PROFILE SUPPORT */

/**
 * ProfileManager_initProfileQueue function
 */
DSPEProfileNode** profileManager_initProfileQueue(const DSPEElement *element);

/**
 * ProfileManager_disposeProfileQueue function
 */
void profileManager_disposeProfileQueue(const DSPEElement *element, DSPEProfileNode **profileQueue);

/**
 * ProfileManager_initialize function
 */
void profileManager_initialize(const DSPEElement *element);

/**
 * ProfileManager_dispose function
 */
void profileManager_dispose(const DSPEElement *element);

/**
 * ProfileSupport_getProfileString function
 */
const char* profileSupport_getProfileString(const profileID id);

/**
 * ProfileSupport_getProfileID function
 */
profileID profileSupport_getProfileID(char *unitID, char *typeID);

/**
 * ProfileManager_captureStartTime function
 */
void profileManager_captureStartTime(const DSPEElement *element, profileID id);

/**
 * ProfileManager_captureEndTime function
 */
void profileManager_captureEndTime(const DSPEElement *element, profileID id);

/**
 * ProfileManager_incrementSamplesCount function
 */
void profileManager_incrementSamplesCount(const DSPEElement *element, const unsigned int increment);

/**
 * ProfileManager_getSamplesCount function
 */
unsigned int profileManager_getSamplesCount(const DSPEElement *element);

/**
 * ProfileManager_getElapsedTime function
 * Returns the elapsed time in seconds
 */
double profileManager_getElapsedTime(const DSPEElement *element);

/**
 * ProfileManager_getMeanProcessTime function
 * Returns the mean process time in milliseconds
 */
double profileManager_getMeanProcessTime(const DSPEElement *element, profileID id);

/**
 * ProfileManager_getMinProcessTime function
 * Returns the min process time in milliseconds
 */
double profileManager_getMinProcessTime(const DSPEElement *element, profileID id);

/**
 * ProfileManager_getMaxProcessTime function
 * Returns the max process time in milliseconds
 */
double profileManager_getMaxProcessTime(const DSPEElement *element, profileID id);

/**
 * ProfileManager_getTotalProcessTime function
 * Returns the total process time in milliseconds
 */
double profileManager_getTotalProcessTime(const DSPEElement *element, profileID id);

/**
 * ProfileManager_getThroughput function
 */
double profileManager_getThroughput(const DSPEElement *element);

/**
 * ProfileManager_isProfileUnit function
 */
int profileManager_isProfileUnit(const DSPEElement *element, profileID id);

/* LAG AND LATENCY SUPPORT */

/**
 * ProfileManager_sendSignal function
 */
void profileManager_sendSignal(const DSPEElement *element);

/**
 * ProfileManager_receiveSignal function
 */
void profileManager_receiveSignal(const DSPEElement *element);

/**
 * ProfileManager_isSignalSent function
 */
int profileManager_isSignalSent(const DSPEElement *element);

/**
 * ProfileManager_incrementLag function
 */
void profileManager_incrementLag(const DSPEElement *element, const unsigned int increment);

/**
 * ProfileManager_getMeanLag function
 */
unsigned int profileManager_getMeanLag(const DSPEElement *element);

/**
 * ProfileManager_getMinLag function
 */
unsigned int profileManager_getMinLag(const DSPEElement *element);

/**
 * ProfileManager_getMaxLag function
 */
unsigned int profileManager_getMaxLag(const DSPEElement *element);

/**
 * ProfileManager_getMeanLatency function
 * Returns the mean latency in milliseconds
 */
double profileManager_getMeanLatency(const DSPEElement *element);

/**
 * ProfileManager_getMinLatency function
 * Returns the min latency in milliseconds
 */
double profileManager_getMinLatency(const DSPEElement *element);

/**
 * ProfileManager_getMaxLatency function
 * Returns the max latency in milliseconds
 */
double profileManager_getMaxLatency(const DSPEElement *element);

/**
 * ProfileManager_receiveData function
 */
void profileManager_receiveData(const DSPEElement *element);

/**
 * ProfileManager_getMeanResponseTime function
 * Returns the mean responseTime in milliseconds
 */
double profileManager_getMeanResponseTime(const DSPEElement *element);

/**
 * ProfileManager_getMinResponseTime function
 * Returns the min responseTime in milliseconds
 */
double profileManager_getMinResponseTime(const DSPEElement *element);

/**
 * ProfileManager_getMaxResponse function
 * Returns the max response time in milliseconds
 */
double profileManager_getMaxResponseTime(const DSPEElement *element);

/**
 * ProfileManager_getTotalUnitProcessTime function
 */
double profileManager_getTotalUnitProcessTime(const DSPEElement *element);

/**
 * ProfileManager_showProfileInfo function
 */
void profileManager_showProfileInfo(const DSPEElement *element, profileID id);


/******************************************************************************
 * BENCHMARKING SUPPORT
 ******************************************************************************/

/**
 * ProfileManager_initBenchmarkHandler function
 */
void profileManager_initBenchmarkHandler(DSPEApplication *application);

/**
 * ProfileManager_updateBenchmarking function
 */
int profileManager_updateBenchmarking(const DSPEElement *element);

/**
 * ProfileManager_initBenchmarking function
 */
void profileManager_initBenchmarking(const DSPEElement *element);

/**
 * ProfileManager_isBenchmarkingDone function
 */
int profileManager_isBenchmarkingDone(const DSPEElement *element);

/**
 * profileManager_resetBenchmarkHandler function
 */
void profileManager_resetBenchmarkHandler(const DSPEElement *element);

/**
 * profileManager_getBenchmarkMaxNumRuns function
 */
size_t profileManager_getBenchmarkMaxNumRuns(DSPEElement *element);

/**
 * profileManager_getBenchmarkCurNumRuns function
 */
size_t profileManager_getBenchmarkCurNumRuns(DSPEElement *element);

/**
 * profileManager_getBenchmarkMinBlocksize function
 */
size_t profileManager_getBenchmarkMinBlocksize(DSPEElement *element);

/**
 * profileManager_getBenchmarkMaxBlocksize function
 */
size_t profileManager_getBenchmarkMaxBlocksize(DSPEElement *element);

/**
 * profileManager_getBenchmarkCurBlocksize function
 */
size_t profileManager_getBenchmarkCurBlocksize(DSPEElement *element);

/**
 * profileManager_getBenchmarkMaxEngines function
 */
size_t profileManager_getBenchmarkMaxEngines(DSPEElement *element);

/**
 * profileManager_getBenchmarkCurNumEngines function
 */
size_t profileManager_getBenchmarkCurNumEngines(DSPEElement *element);

/******************************************************************************
 * PROFILING FILE SUPPORT
 ******************************************************************************/


/**
 * ProfileManager_openProfileFile function
 */
void profileManager_openProfileFile(const DSPEElement *element);

/**
 * ProfileManager_closeProfileFile function
 */
void profileManager_closeProfileFile(const DSPEElement *element);

/**
 * ProfileManager_writeWorksheetHead function
 */
void profileManager_writeWorksheetHead(const DSPEElement *element, const char *name);

/**
 * ProfileManager_writeWorksheetTail function
 */
void profileManager_writeWorksheetTail(const DSPEElement *element);

/**
 * ProfileManager_writeProfileInfoHeader function
 */
void profileManager_writeProfileInfoHeader(const DSPEElement *element);

/**
 * ProfileManager_writeProfileInfo function
 */
void profileManager_writeProfileInfo(const DSPEElement *element, profileID id);

/**
 * ProfileManager_writeNumRun function
 */
void profileManager_writeNumRun(const DSPEElement *element, size_t curNumRun);

/**
 * ProfileManager_writeBlockSize function
 */
void profileManager_writeBlockSize(const DSPEElement *element, size_t blockSize);

/**
 * ProfileManager_writeAverages function
 */
void profileManager_writeAverages(const DSPEElement *element, size_t numRuns);

/**
 * ProfileManager_writeResultsWorksheet function
 */
void profileManager_writeResultsWorksheet(const DSPEElement *element, size_t minEngines, size_t maxEngines, size_t numRuns, size_t minBlockSize, size_t maxBlockSize);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
