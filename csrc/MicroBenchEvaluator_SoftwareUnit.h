/**
 * File: MicroBenchEvaluator_SoftwareUnit.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MicroBenchEvaluator_SoftwareUnit_h
#define MicroBenchEvaluator_SoftwareUnit_h

#include "DSPEElements.h"

#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchTime_StandardGate.h"
#include "MicroBenchSamplesPerSecond_StandardGate.h"
#include "MicroBenchNumSamples_StandardGate.h"

#include "MicroBenchEvaluator_CImplementation.h"
#include "MicroBenchEvaluator_Block_CImplementation.h"
#include "MicroBenchFlag_StandardGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MicroBenchEvaluator_SoftwareUnit MicroBenchEvaluator_SoftwareUnit;

/* Real SoftwareUnit state definition */
struct MicroBenchEvaluator_SoftwareUnit {
	DSPEUnit unit;
	

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

	/* Output parameters places */
	MicroBenchCounter_StandardGate *paramOut_SamplesCount_place;
	MicroBenchTime_StandardGate *paramOut_ElapsedTime_place;
	MicroBenchSamplesPerSecond_StandardGate *paramOut_Throughput_place;
	MicroBenchTime_StandardGate *paramOut_Min_L_place;
	MicroBenchTime_StandardGate *paramOut_Mean_L_place;
	MicroBenchTime_StandardGate *paramOut_Max_L_place;
	MicroBenchNumSamples_StandardGate *paramOut_Min_Lag_place;
	MicroBenchNumSamples_StandardGate *paramOut_Mean_Lag_place;
	MicroBenchNumSamples_StandardGate *paramOut_Max_Lag_place;
	MicroBenchFlag_StandardGate *paramOut_Trigger_place;

	/* Gates numLinks */
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
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MicroBenchEvaluator_CImplementation *implState;
	

	/* Data gates */
	MicroBenchFlag_StandardGate *dataIn_Start;
	MicroBenchFlag_StandardGate *dataIn_Stop;

	/* Unit profile ID */
	int unitProfileID;
};

// BLOCK UNIT
/* Block SoftwareUnit state type definition */
typedef struct MicroBenchEvaluator_SoftwareUnit_block MicroBenchEvaluator_SoftwareUnit_block;

/* Block SoftwareUnit state definition */
struct MicroBenchEvaluator_SoftwareUnit_block {
	DSPEUnit unit;
	

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

	/* Output parameters places */
	MicroBenchCounter_StandardGate *paramOut_SamplesCount_place;
	MicroBenchTime_StandardGate *paramOut_ElapsedTime_place;
	MicroBenchSamplesPerSecond_StandardGate *paramOut_Throughput_place;
	MicroBenchTime_StandardGate *paramOut_Min_L_place;
	MicroBenchTime_StandardGate *paramOut_Mean_L_place;
	MicroBenchTime_StandardGate *paramOut_Max_L_place;
	MicroBenchNumSamples_StandardGate *paramOut_Min_Lag_place;
	MicroBenchNumSamples_StandardGate *paramOut_Mean_Lag_place;
	MicroBenchNumSamples_StandardGate *paramOut_Max_Lag_place;
	MicroBenchFlag_StandardGate *paramOut_Trigger_place;

	/* Gates numLinks */
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
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MicroBenchEvaluator_Block_CImplementation *implState;
	
	/* Block size */
	size_t blockSize;

	/* Samples to process */
	size_t samplesToProcess;


	/* Data gates */
	MicroBenchFlag_StandardGate *dataIn_Start;
	MicroBenchFlag_StandardGate *dataIn_Stop;


	/* Data gates sizes */
	size_t dataIn_Start_size;
	size_t dataIn_Stop_size;


	/* Data gates factors */
	size_t dataIn_Start_factor;
	size_t dataIn_Stop_factor;


	/* Data gates counters */
	size_t dataIn_Start_counter;
	size_t dataIn_Stop_counter;

	/* Unit profile ID */
	int unitProfileID;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* EarlyAlloc function */
void MicroBenchEvaluator_SoftwareUnit_earlyAlloc(MicroBenchEvaluator_SoftwareUnit *context);

/* Alloc function */
void MicroBenchEvaluator_SoftwareUnit_alloc(MicroBenchEvaluator_SoftwareUnit *context);

/* EarlyConnect function */
void MicroBenchEvaluator_SoftwareUnit_earlyConnect(MicroBenchEvaluator_SoftwareUnit *context);

/* Connect function */
void MicroBenchEvaluator_SoftwareUnit_connect(MicroBenchEvaluator_SoftwareUnit *context);

/* Startup function */
void MicroBenchEvaluator_SoftwareUnit_startup(MicroBenchEvaluator_SoftwareUnit *context);

/* PreProcess function */
void MicroBenchEvaluator_SoftwareUnit_preProcess(DSPEComponent *component);

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_process(DSPEComponent *component);

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_processAutoPull(DSPEComponent *component);

/* PostProcess function */
void MicroBenchEvaluator_SoftwareUnit_postProcess(DSPEComponent *component);

/* Reset function */
void MicroBenchEvaluator_SoftwareUnit_reset(MicroBenchEvaluator_SoftwareUnit *context);

/* Shutdown function */
void MicroBenchEvaluator_SoftwareUnit_shutdown(MicroBenchEvaluator_SoftwareUnit *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MicroBenchEvaluator_SoftwareUnit_earlyAllocBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

/* Alloc function */
void MicroBenchEvaluator_SoftwareUnit_allocBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

/* EarlyConnect function */
void MicroBenchEvaluator_SoftwareUnit_earlyConnectBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

/* Connect function */
void MicroBenchEvaluator_SoftwareUnit_connectBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

/* Startup function */
void MicroBenchEvaluator_SoftwareUnit_startupBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

/* PreProcess function */
void MicroBenchEvaluator_SoftwareUnit_preProcessBlock(DSPEComponent *component);

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_processBlock(DSPEComponent *component);

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_processAutoPullBlock(DSPEComponent *component);

/* PostProcess function */
void MicroBenchEvaluator_SoftwareUnit_postProcessBlock(DSPEComponent *component);

/* Reset function */
void MicroBenchEvaluator_SoftwareUnit_resetBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

/* Shutdown function */
void MicroBenchEvaluator_SoftwareUnit_shutdownBlock(MicroBenchEvaluator_SoftwareUnit_block *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
