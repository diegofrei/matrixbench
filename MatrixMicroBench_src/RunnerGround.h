/**
 * File: RunnerGround.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef RunnerGround_h
#define RunnerGround_h

#include "DSPEElements.h"

#include "MatrixBenchMatrixMicroBench_Application.h"

#include <stdio.h>

/* DSPESetting definition */
typedef struct DSPESettings DSPESettings;

struct DSPESettings {
	int changed;

	/* Multirun support */
	int numMultiRuns;
};

/* Error node definition */
typedef struct DSPEErrorNode DSPEErrorNode;

struct DSPEErrorNode {
	DSPEErrorNode *next;

	char *errorMsg;
	size_t errorMsgLength;
	char *elementID;
};

/* Error queue definition */
typedef struct DSPEErrorQueue DSPEErrorQueue;

struct DSPEErrorQueue {
	DSPEErrorNode *queueHead;
	DSPEErrorNode *queueTail;
	size_t queueNumElements;
};

/* Profile node definition */
typedef struct profileNode profileNode;

struct profileNode {
	DSPEProfileNode node;

	DSPEProfileTime startTime;
	DSPEProfileTime totalTicks;
	DSPEProfileTime minTicks;
	DSPEProfileTime maxTicks;
	unsigned int count;
};

/* Profile definition */
typedef struct profile profile;

struct profile {
	// Time and counters
	DSPEProfileTime startTime;
	DSPEProfileTime endTime;
	DSPEProfileTime ticks;

	unsigned int samplesCount;
	unsigned int processCount;

	// Lag support
	int lagCountEnabled;
	unsigned int lag;
	unsigned int totalLag;
	unsigned int minLag;
	unsigned int maxLag;
	unsigned int lagCount;

	// Latency support
	DSPEProfileTime startLatency;
	DSPEProfileTime totalLatency;
	DSPEProfileTime minLatency;
	DSPEProfileTime maxLatency;
	unsigned int latencyCount;

	// ResponseTime support
	DSPEProfileTime startResponse;
	DSPEProfileTime totalResponse;
	DSPEProfileTime minResponse;
	DSPEProfileTime maxResponse;
	unsigned int responseCount;	

	// Profile unit
	int profileUnit;
};

/* Application's inputParameters struct */
typedef struct DSPEInputParameters DSPEInputParameters;
typedef struct DSPEInputParameterValue DSPEInputParameterValue;

struct DSPEInputParameters {
	DSPEInputParameters *next;

	/* List of values */
	DSPEInputParameterValue *headParam;
	DSPEInputParameterValue *tailParam;
	size_t numParams;
};

struct DSPEInputParameterValue {
	char *gateName;
	char *optionPnString;
	char *value;

	DSPEInputParameterValue *nextValue;
};
/* Application type definition */
typedef struct MatrixBenchMatrixMicroBench_Application_cmd MatrixBenchMatrixMicroBench_Application_cmd;

/* Application definition */
struct MatrixBenchMatrixMicroBench_Application_cmd {

	/* Application */
	MatrixBenchMatrixMicroBench_Application application;

	/* Settings support */
	DSPESettings settings;

	/* Input parameters support */ 
	size_t inputParametersNumElements;
	DSPEInputParameters *inputParametersCurr;
	DSPEInputParameters *inputParametersHead;
	DSPEInputParameters *inputParametersTail;
	/* GUI current values */
	MicroBenchCounter_StandardGate *paramIn_SignalDelay_curValue;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop_curValue;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess_curValue;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo_curValue;
	MicroBenchFlag_StandardGate *paramIn_SignalSource_curValue;
	MicroBenchCounter_StandardGate *paramOut_SamplesCount_curValue;
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals_curValue;
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals_curValue;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples_curValue;
	MicroBenchTime_StandardGate *paramOut_ElapsedTime_curValue;
	MicroBenchSamplesPerSecond_StandardGate *paramOut_Throughput_curValue;
	MicroBenchTime_StandardGate *paramOut_Min_L_curValue;
	MicroBenchTime_StandardGate *paramOut_Mean_L_curValue;
	MicroBenchTime_StandardGate *paramOut_Max_L_curValue;
	MicroBenchNumSamples_StandardGate *paramOut_Min_Lag_curValue;
	MicroBenchNumSamples_StandardGate *paramOut_Mean_Lag_curValue;
	MicroBenchNumSamples_StandardGate *paramOut_Max_Lag_curValue;

	/* EngineManager variables */
	int stopped;
	long int skipCycles;

	void *updateDisplayThread;

	/* ErrorManager variables */
	unsigned int errorPoolNodesNum;
	DSPEErrorNode *errorPoolHead;
	DSPEErrorNode *errorPoolTail;

	// REMARK: Cannot use a static array since the enum is defined
	// within ErrorManager.h file that cannot be included!
	DSPEErrorQueue **errorQueues;

	int errorForceApplicationStop;
	int errorAlwaysCollect;

	/* InfoManager collect support variables */
	unsigned int *collectedInfo;
	unsigned int *collectedLog;

	/* Profile variable */
	profile *profileData;

	/* Log file variable */
	FILE *logFile;

	/* Profile file variable */
	FILE *profileFile;
	/* Open worksheets */
	int openWorksheets;

};

#ifdef __cplusplus
extern "C" {
#endif

/* LOG FILE SUPPORT */

void openLogFile(MatrixBenchMatrixMicroBench_Application_cmd *context, int logCurrentTime);

void closeLogFile(MatrixBenchMatrixMicroBench_Application_cmd *context);

/* 
 * REMARK: Managers using these functions cannot directly include the
 * corresponding manager header file (MemoryManager or ThreadManager)
 * to avoid circular inclusions when inline support is active.
 */

/* MEMORY SUPPORT */

void* allocateMemory(const DSPEElement *element, size_t size);

void* allocateAndInitMemory(const DSPEElement *element, size_t blockSize, unsigned int size);

void* reallocateMemory(void *pointer, size_t newSize);

void disposeMemory(void *pointer);

/* DSPEInputParameters SUPPORT */

DSPEInputParameters* DSPEInputParameters_create(DSPEApplication *application);

void DSPEInputParameters_dispose(DSPEApplication *application, DSPEInputParameters *params);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
