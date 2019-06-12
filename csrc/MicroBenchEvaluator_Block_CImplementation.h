/**
 * File: MicroBenchEvaluator_Block_CImplementation.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MicroBenchEvaluator_Block_CImplementation_h
#define MicroBenchEvaluator_Block_CImplementation_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchTime_StandardGate.h"
#include "MicroBenchSamplesPerSecond_StandardGate.h"
#include "MicroBenchNumSamples_StandardGate.h"

/* BlockOptimization state type definition */
typedef struct MicroBenchEvaluator_Block_CImplementation MicroBenchEvaluator_Block_CImplementation;

/* State definition */ 
struct MicroBenchEvaluator_Block_CImplementation {

	DSPEImplementation implementation;
	
	/* Block size */
	size_t blockSize;


	/* Data gates */
	MicroBenchFlag_StandardGate *dataIn_Start;
	MicroBenchFlag_StandardGate *dataIn_Stop;

	/* Parameter gates */
	MicroBenchCounter_StandardGate *paramIn_SignalDelay;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess;
	MicroBenchCounter_StandardGate *paramOut_SamplesCount;
	MicroBenchTime_StandardGate *paramOut_ElapsedTime;
	MicroBenchSamplesPerSecond_StandardGate *paramOut_Throughput;
	MicroBenchTime_StandardGate *paramOut_Min_L;
	MicroBenchTime_StandardGate *paramOut_Mean_L;
	MicroBenchTime_StandardGate *paramOut_Max_L;
	MicroBenchNumSamples_StandardGate *paramOut_Min_Lag;
	MicroBenchNumSamples_StandardGate *paramOut_Mean_Lag;
	MicroBenchNumSamples_StandardGate *paramOut_Max_Lag;
	MicroBenchFlag_StandardGate *paramOut_Trigger;


	/* numLinks flags */
	unsigned int dataIn_Start_numLinks;
	unsigned int dataIn_Stop_numLinks;
	unsigned int paramIn_SignalDelay_numLinks;
	unsigned int paramIn_AutomaticStop_numLinks;
	unsigned int paramIn_SamplesToProcess_numLinks;
	unsigned int paramOut_SamplesCount_numLinks;
	unsigned int paramOut_ElapsedTime_numLinks;
	unsigned int paramOut_Throughput_numLinks;
	unsigned int paramOut_Min_L_numLinks;
	unsigned int paramOut_Mean_L_numLinks;
	unsigned int paramOut_Max_L_numLinks;
	unsigned int paramOut_Min_Lag_numLinks;
	unsigned int paramOut_Mean_Lag_numLinks;
	unsigned int paramOut_Max_Lag_numLinks;
	unsigned int paramOut_Trigger_numLinks;
};

/* Functional implementation state type definition */
typedef struct MicroBenchEvaluator_Block_CImplementation_func MicroBenchEvaluator_Block_CImplementation_func;

/* This struct may contain user defined additional state variables for the unit */
struct MicroBenchEvaluator_Block_CImplementation_func {
	MicroBenchEvaluator_Block_CImplementation parent;
	//Place additional state variables after this line -- SYD-ADDITIONAL-STATE-START
	int SCEnabled;
	size_t samplesCounter;
	unsigned int signalCounter;
	//SYD-ADDITIONAL-STATE-END  -- Place additional state variables before this line

};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* Allocate function */
MicroBenchEvaluator_Block_CImplementation* MicroBenchEvaluator_Block_CImplementation_allocate(DSPEElement *context);

/* Dispose function */
void MicroBenchEvaluator_Block_CImplementation_dispose(DSPEElement *element, MicroBenchEvaluator_Block_CImplementation *context);

/* Process function */
void MicroBenchEvaluator_Block_CImplementation_process(MicroBenchEvaluator_Block_CImplementation *context);

/* PostProcess function */
void MicroBenchEvaluator_Block_CImplementation_postProcess(MicroBenchEvaluator_Block_CImplementation *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
