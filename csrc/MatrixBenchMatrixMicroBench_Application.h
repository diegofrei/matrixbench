/**
 * File: MatrixBenchMatrixMicroBench_Application.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixMicroBench_Application_h
#define MatrixBenchMatrixMicroBench_Application_h

#include "DSPEElements.h"

#include "MatrixBenchMatrixMicroBench_Configuration.h"
#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"
#include "MicroBenchTime_StandardGate.h"
#include "MicroBenchSamplesPerSecond_StandardGate.h"
#include "MicroBenchNumSamples_StandardGate.h"

/* Parameter rates */
#define MATRIXBENCHMATRIXMICROBENCH_APPLICATION_PARAMETERSINPUTRATE 1
#define MATRIXBENCHMATRIXMICROBENCH_APPLICATION_PARAMETERSOUTPUTRATE 1

/* Update rate */
#define MATRIXBENCHMATRIXMICROBENCH_APPLICATION_UPDATERATE 1

/* State type definition */
typedef struct MatrixBenchMatrixMicroBench_Application MatrixBenchMatrixMicroBench_Application;

/* State definition */ 
struct MatrixBenchMatrixMicroBench_Application {

	DSPEApplication application;

	/* Contained configuration */
	MatrixBenchMatrixMicroBench_Configuration structure;

	/* Parameter gates */
	MicroBenchCounter_StandardGate *paramIn_SignalDelay;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchCounter_StandardGate *paramOut_SamplesCount;
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals;
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples;
	MicroBenchTime_StandardGate *paramOut_ElapsedTime;
	MicroBenchSamplesPerSecond_StandardGate *paramOut_Throughput;
	MicroBenchTime_StandardGate *paramOut_Min_L;
	MicroBenchTime_StandardGate *paramOut_Mean_L;
	MicroBenchTime_StandardGate *paramOut_Max_L;
	MicroBenchNumSamples_StandardGate *paramOut_Min_Lag;
	MicroBenchNumSamples_StandardGate *paramOut_Mean_Lag;
	MicroBenchNumSamples_StandardGate *paramOut_Max_Lag;


	/* Application input parameter gates places */
	MicroBenchCounter_StandardGate *paramIn_SignalDelay_place;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop_place;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess_place;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo_place;
	MicroBenchFlag_StandardGate *paramIn_SignalSource_place;

	/* unit ID */
	char *ID;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* getID function */
char* MatrixBenchMatrixMicroBench_Application_getID(const DSPEElement *element);

/* EarlyAlloc function */
void MatrixBenchMatrixMicroBench_Application_earlyAlloc(MatrixBenchMatrixMicroBench_Application *context);

/* Alloc function */
void MatrixBenchMatrixMicroBench_Application_alloc(MatrixBenchMatrixMicroBench_Application *context);

/* EarlyConnect function */
void MatrixBenchMatrixMicroBench_Application_earlyConnect(MatrixBenchMatrixMicroBench_Application *context);

/* Connect function */
void MatrixBenchMatrixMicroBench_Application_connect(MatrixBenchMatrixMicroBench_Application *context);

/* Startup function */
void MatrixBenchMatrixMicroBench_Application_startup(DSPEApplication *application);

/* PreProcess function */
void MatrixBenchMatrixMicroBench_Application_preProcess(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMicroBench_Application_process(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMicroBench_Application_postProcess(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMicroBench_Application_reset(DSPEComponent *component);

/* Shutdown function */
void MatrixBenchMatrixMicroBench_Application_shutdown(DSPEApplication *application);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
