/**
 * File: MicroBenchEvaluator_SoftwareUnit.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "PlatformManager.h"
#include "StringManager.h"
#include "MemoryManager.h"
#include "EngineManager.h"
#include "ProfileManager.h"
#include "ErrorManager.h"

#include "MicroBenchEvaluator_SoftwareUnit.h"

/* getID function */
char* MicroBenchEvaluator_SoftwareUnit_getID(const DSPEElement *element) {
	return ((const MicroBenchEvaluator_SoftwareUnit*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValues(MicroBenchEvaluator_SoftwareUnit *context) {

	/* Parameter Output gates initialization */
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramOut_SamplesCount_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_ElapsedTime_place);
	MicroBenchSamplesPerSecond_StandardGate_initialize((DSPEElement*) context, context->paramOut_Throughput_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Min_L_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Mean_L_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Max_L_place);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Min_Lag_place);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Mean_Lag_place);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Max_Lag_place);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramOut_Trigger_place);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MicroBenchEvaluator_SoftwareUnit_earlyAlloc(MicroBenchEvaluator_SoftwareUnit *context) {
	MicroBenchEvaluator_CImplementation *implState = NULL;
	context->implState = MicroBenchEvaluator_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MicroBenchEvaluator_SoftwareUnit_getID;
	((DSPEComponent*) context)->preprocess = MicroBenchEvaluator_SoftwareUnit_preProcess;
	((DSPEComponent*) context)->process = MicroBenchEvaluator_SoftwareUnit_process;
	((DSPEComponent*) context)->postprocess = MicroBenchEvaluator_SoftwareUnit_postProcess;

	/* Implementation AdditionalStateVariables initialization */
	((MicroBenchEvaluator_CImplementation_func*) implState)->SCEnabled = 0;
	((MicroBenchEvaluator_CImplementation_func*) implState)->samplesCounter = 0;
	((MicroBenchEvaluator_CImplementation_func*) implState)->signalCounter = 0;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MicroBenchEvaluator_SoftwareUnit_alloc(MicroBenchEvaluator_SoftwareUnit *context) {

	/* Output parameters places allocation */
	context->paramOut_SamplesCount_place = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_ElapsedTime_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Throughput_place = MicroBenchSamplesPerSecond_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Min_L_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Mean_L_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Max_L_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Min_Lag_place = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Mean_Lag_place = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Max_Lag_place = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Trigger_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);

}

/* EarlyConnect function */
void MicroBenchEvaluator_SoftwareUnit_earlyConnect(MicroBenchEvaluator_SoftwareUnit *context) {

	/* Implementation state local variable initialization */
	MicroBenchEvaluator_CImplementation *implState = context->implState;

	/* Implementation output parameters gates initialization */
	implState->paramOut_SamplesCount = context->paramOut_SamplesCount_place;
	implState->paramOut_ElapsedTime = context->paramOut_ElapsedTime_place;
	implState->paramOut_Throughput = context->paramOut_Throughput_place;
	implState->paramOut_Min_L = context->paramOut_Min_L_place;
	implState->paramOut_Mean_L = context->paramOut_Mean_L_place;
	implState->paramOut_Max_L = context->paramOut_Max_L_place;
	implState->paramOut_Min_Lag = context->paramOut_Min_Lag_place;
	implState->paramOut_Mean_Lag = context->paramOut_Mean_Lag_place;
	implState->paramOut_Max_Lag = context->paramOut_Max_Lag_place;
	implState->paramOut_Trigger = context->paramOut_Trigger_place;

	/* Gates numLinks initialization */
	context->dataIn_Start_numLinks = 0;
	context->dataIn_Stop_numLinks = 0;
	context->paramIn_SignalDelay_numLinks = 0;
	context->paramIn_AutomaticStop_numLinks = 0;
	context->paramIn_SamplesToProcess_numLinks = 0;
	context->paramOut_SamplesCount_numLinks = 0;
	context->paramOut_ElapsedTime_numLinks = 0;
	context->paramOut_Throughput_numLinks = 0;
	context->paramOut_Min_L_numLinks = 0;
	context->paramOut_Mean_L_numLinks = 0;
	context->paramOut_Max_L_numLinks = 0;
	context->paramOut_Min_Lag_numLinks = 0;
	context->paramOut_Mean_Lag_numLinks = 0;
	context->paramOut_Max_Lag_numLinks = 0;
	context->paramOut_Trigger_numLinks = 0;

	/* Output parameters gates initialization */
	context->paramOut_SamplesCount = context->paramOut_SamplesCount_place;
	context->paramOut_ElapsedTime = context->paramOut_ElapsedTime_place;
	context->paramOut_Throughput = context->paramOut_Throughput_place;
	context->paramOut_Min_L = context->paramOut_Min_L_place;
	context->paramOut_Mean_L = context->paramOut_Mean_L_place;
	context->paramOut_Max_L = context->paramOut_Max_L_place;
	context->paramOut_Min_Lag = context->paramOut_Min_Lag_place;
	context->paramOut_Mean_Lag = context->paramOut_Mean_Lag_place;
	context->paramOut_Max_Lag = context->paramOut_Max_Lag_place;
	context->paramOut_Trigger = context->paramOut_Trigger_place;
}

/* Connect function */
void MicroBenchEvaluator_SoftwareUnit_connect(MicroBenchEvaluator_SoftwareUnit *context) {

	/* Implementation state local variable initialization */
	MicroBenchEvaluator_CImplementation *implState = context->implState;

	/* Implementation input parameters gates initialization */
	implState->paramIn_SignalDelay = context->paramIn_SignalDelay;
	implState->paramIn_AutomaticStop = context->paramIn_AutomaticStop;
	implState->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess;

	/* Implementation data gates initialization */
	implState->dataIn_Start = context->dataIn_Start;
	implState->dataIn_Stop = context->dataIn_Stop;

	/* Implementation gates numLinks initialization */
	implState->dataIn_Start_numLinks = context->dataIn_Start_numLinks;
	implState->dataIn_Stop_numLinks = context->dataIn_Stop_numLinks;
	implState->paramIn_SignalDelay_numLinks = context->paramIn_SignalDelay_numLinks;
	implState->paramIn_AutomaticStop_numLinks = context->paramIn_AutomaticStop_numLinks;
	implState->paramIn_SamplesToProcess_numLinks = context->paramIn_SamplesToProcess_numLinks;
	implState->paramOut_SamplesCount_numLinks = context->paramOut_SamplesCount_numLinks;
	implState->paramOut_ElapsedTime_numLinks = context->paramOut_ElapsedTime_numLinks;
	implState->paramOut_Throughput_numLinks = context->paramOut_Throughput_numLinks;
	implState->paramOut_Min_L_numLinks = context->paramOut_Min_L_numLinks;
	implState->paramOut_Mean_L_numLinks = context->paramOut_Mean_L_numLinks;
	implState->paramOut_Max_L_numLinks = context->paramOut_Max_L_numLinks;
	implState->paramOut_Min_Lag_numLinks = context->paramOut_Min_Lag_numLinks;
	implState->paramOut_Mean_Lag_numLinks = context->paramOut_Mean_Lag_numLinks;
	implState->paramOut_Max_Lag_numLinks = context->paramOut_Max_Lag_numLinks;
	implState->paramOut_Trigger_numLinks = context->paramOut_Trigger_numLinks;
}

/* Startup function */
void MicroBenchEvaluator_SoftwareUnit_startup(MicroBenchEvaluator_SoftwareUnit *context) {

	/* Initialize gate values */
	initValues(context);
}

/* PreProcess function */
void MicroBenchEvaluator_SoftwareUnit_preProcess(DSPEComponent *component) {
}

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_process(DSPEComponent *component) {
	MicroBenchEvaluator_SoftwareUnit *context = (MicroBenchEvaluator_SoftwareUnit*) component;
	/* Implementation state local variable initialization */
	MicroBenchEvaluator_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation prepareparams() call */
	MicroBenchEvaluator_CImplementation_prepareParams(implState);

	/* Implementation process() call */
	MicroBenchEvaluator_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_processAutoPull(DSPEComponent *component) {
	MicroBenchEvaluator_SoftwareUnit *context = (MicroBenchEvaluator_SoftwareUnit*) component;
	/* Implementation state local variable initialization */
	MicroBenchEvaluator_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation prepareparams() call */
	MicroBenchEvaluator_CImplementation_prepareParams(implState);

	/* Implementation process() call */
	MicroBenchEvaluator_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* PostProcess function */
void MicroBenchEvaluator_SoftwareUnit_postProcess(DSPEComponent *component) {
	MicroBenchEvaluator_SoftwareUnit *context = (MicroBenchEvaluator_SoftwareUnit*) component;

	/* Implementation postprocess() call */
	MicroBenchEvaluator_CImplementation_postProcess(context->implState);
}

/* Reset function */
void MicroBenchEvaluator_SoftwareUnit_reset(MicroBenchEvaluator_SoftwareUnit *context) {
	MicroBenchEvaluator_CImplementation *implState = context->implState;

	/* Initialize gate values */
	initValues(context);

	/* Implementation AdditionalStateVariables initialization */
	((MicroBenchEvaluator_CImplementation_func*) implState)->SCEnabled = 0;
	((MicroBenchEvaluator_CImplementation_func*) implState)->samplesCounter = 0;
	((MicroBenchEvaluator_CImplementation_func*) implState)->signalCounter = 0;
}

/* Shutdown function */
void MicroBenchEvaluator_SoftwareUnit_shutdown(MicroBenchEvaluator_SoftwareUnit *context) {

	/* Output parameters places dispose */
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramOut_SamplesCount_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_ElapsedTime_place);
	MicroBenchSamplesPerSecond_StandardGate_dispose((DSPEElement*) context, context->paramOut_Throughput_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Min_L_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Mean_L_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Max_L_place);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Min_Lag_place);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Mean_Lag_place);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Max_Lag_place);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramOut_Trigger_place);

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Dispose implementation */
	MicroBenchEvaluator_CImplementation_dispose((DSPEElement*) context, context->implState);
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* getID function */
char* MicroBenchEvaluator_SoftwareUnit_getIDBlock(const DSPEElement *element) {
	return ((const MicroBenchEvaluator_SoftwareUnit_block*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValuesBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {

	/* Parameter Output gates initialization */
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramOut_SamplesCount_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_ElapsedTime_place);
	MicroBenchSamplesPerSecond_StandardGate_initialize((DSPEElement*) context, context->paramOut_Throughput_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Min_L_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Mean_L_place);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Max_L_place);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Min_Lag_place);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Mean_Lag_place);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Max_Lag_place);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramOut_Trigger_place);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MicroBenchEvaluator_SoftwareUnit_earlyAllocBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {
	MicroBenchEvaluator_Block_CImplementation *implState = NULL;
	context->implState = MicroBenchEvaluator_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MicroBenchEvaluator_SoftwareUnit_getIDBlock;
	((DSPEComponent*) context)->preprocess = MicroBenchEvaluator_SoftwareUnit_preProcessBlock;
	((DSPEComponent*) context)->process = MicroBenchEvaluator_SoftwareUnit_processBlock;
	((DSPEComponent*) context)->postprocess = MicroBenchEvaluator_SoftwareUnit_postProcessBlock;

	/* Data gates size initialization */
	context->dataIn_Start_size = context->blockSize;
	context->dataIn_Stop_size = context->blockSize;

	/* Implementation AdditionalStateVariables initialization */
	((MicroBenchEvaluator_Block_CImplementation_func*) implState)->SCEnabled = 0;
	((MicroBenchEvaluator_Block_CImplementation_func*) implState)->samplesCounter = 0;
	((MicroBenchEvaluator_Block_CImplementation_func*) implState)->signalCounter = 0;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MicroBenchEvaluator_SoftwareUnit_allocBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {

	/* Output parameters places allocation */
	context->paramOut_SamplesCount_place = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_ElapsedTime_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Throughput_place = MicroBenchSamplesPerSecond_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Min_L_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Mean_L_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Max_L_place = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Min_Lag_place = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Mean_Lag_place = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Max_Lag_place = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Trigger_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);

}

/* EarlyConnect function */
void MicroBenchEvaluator_SoftwareUnit_earlyConnectBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {

	/* Implementation state local variable initialization */
	MicroBenchEvaluator_Block_CImplementation *implState = context->implState;

	/* Implementation output parameters gates initialization */
	implState->paramOut_SamplesCount = context->paramOut_SamplesCount_place;
	implState->paramOut_ElapsedTime = context->paramOut_ElapsedTime_place;
	implState->paramOut_Throughput = context->paramOut_Throughput_place;
	implState->paramOut_Min_L = context->paramOut_Min_L_place;
	implState->paramOut_Mean_L = context->paramOut_Mean_L_place;
	implState->paramOut_Max_L = context->paramOut_Max_L_place;
	implState->paramOut_Min_Lag = context->paramOut_Min_Lag_place;
	implState->paramOut_Mean_Lag = context->paramOut_Mean_Lag_place;
	implState->paramOut_Max_Lag = context->paramOut_Max_Lag_place;
	implState->paramOut_Trigger = context->paramOut_Trigger_place;

	/* Gates numLinks initialization */
	context->dataIn_Start_numLinks = 0;
	context->dataIn_Stop_numLinks = 0;
	context->paramIn_SignalDelay_numLinks = 0;
	context->paramIn_AutomaticStop_numLinks = 0;
	context->paramIn_SamplesToProcess_numLinks = 0;
	context->paramOut_SamplesCount_numLinks = 0;
	context->paramOut_ElapsedTime_numLinks = 0;
	context->paramOut_Throughput_numLinks = 0;
	context->paramOut_Min_L_numLinks = 0;
	context->paramOut_Mean_L_numLinks = 0;
	context->paramOut_Max_L_numLinks = 0;
	context->paramOut_Min_Lag_numLinks = 0;
	context->paramOut_Mean_Lag_numLinks = 0;
	context->paramOut_Max_Lag_numLinks = 0;
	context->paramOut_Trigger_numLinks = 0;

	/* Output parameters gates initialization */
	context->paramOut_SamplesCount = context->paramOut_SamplesCount_place;
	context->paramOut_ElapsedTime = context->paramOut_ElapsedTime_place;
	context->paramOut_Throughput = context->paramOut_Throughput_place;
	context->paramOut_Min_L = context->paramOut_Min_L_place;
	context->paramOut_Mean_L = context->paramOut_Mean_L_place;
	context->paramOut_Max_L = context->paramOut_Max_L_place;
	context->paramOut_Min_Lag = context->paramOut_Min_Lag_place;
	context->paramOut_Mean_Lag = context->paramOut_Mean_Lag_place;
	context->paramOut_Max_Lag = context->paramOut_Max_Lag_place;
	context->paramOut_Trigger = context->paramOut_Trigger_place;

	/* Input data gates factor and counter initialization */
	context->dataIn_Start_factor = context->dataIn_Start_size / context->blockSize;
	context->dataIn_Stop_factor = context->dataIn_Stop_size / context->blockSize;

	/* Input data gates factor and counter initialization */
	context->dataIn_Start_counter = context->dataIn_Start_factor;
	context->dataIn_Stop_counter = context->dataIn_Stop_factor;
}

/* Connect function */
void MicroBenchEvaluator_SoftwareUnit_connectBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {

	/* Implementation state local variable initialization */
	MicroBenchEvaluator_Block_CImplementation *implState = context->implState;

	/* Implementation input parameters gates initialization */
	implState->paramIn_SignalDelay = context->paramIn_SignalDelay;
	implState->paramIn_AutomaticStop = context->paramIn_AutomaticStop;
	implState->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess;

	/* Implementation blocksize initialization */
	implState->blockSize = context->blockSize;

	/* Implementation data gates initialization */
	implState->dataIn_Start = context->dataIn_Start;
	implState->dataIn_Stop = context->dataIn_Stop;

	/* Implementation gates numLinks initialization */
	implState->dataIn_Start_numLinks = context->dataIn_Start_numLinks;
	implState->dataIn_Stop_numLinks = context->dataIn_Stop_numLinks;
	implState->paramIn_SignalDelay_numLinks = context->paramIn_SignalDelay_numLinks;
	implState->paramIn_AutomaticStop_numLinks = context->paramIn_AutomaticStop_numLinks;
	implState->paramIn_SamplesToProcess_numLinks = context->paramIn_SamplesToProcess_numLinks;
	implState->paramOut_SamplesCount_numLinks = context->paramOut_SamplesCount_numLinks;
	implState->paramOut_ElapsedTime_numLinks = context->paramOut_ElapsedTime_numLinks;
	implState->paramOut_Throughput_numLinks = context->paramOut_Throughput_numLinks;
	implState->paramOut_Min_L_numLinks = context->paramOut_Min_L_numLinks;
	implState->paramOut_Mean_L_numLinks = context->paramOut_Mean_L_numLinks;
	implState->paramOut_Max_L_numLinks = context->paramOut_Max_L_numLinks;
	implState->paramOut_Min_Lag_numLinks = context->paramOut_Min_Lag_numLinks;
	implState->paramOut_Mean_Lag_numLinks = context->paramOut_Mean_Lag_numLinks;
	implState->paramOut_Max_Lag_numLinks = context->paramOut_Max_Lag_numLinks;
	implState->paramOut_Trigger_numLinks = context->paramOut_Trigger_numLinks;
}

/* Startup function */
void MicroBenchEvaluator_SoftwareUnit_startupBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* PreProcess function */
void MicroBenchEvaluator_SoftwareUnit_preProcessBlock(DSPEComponent *component) {
}

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_processBlock(DSPEComponent *component) {
	MicroBenchEvaluator_SoftwareUnit_block *context = (MicroBenchEvaluator_SoftwareUnit_block*) component;
	/* Implementation state local variable initialization */
	MicroBenchEvaluator_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MicroBenchFlag_StandardGate *dataIn_Start_anchor;
	MicroBenchFlag_StandardGate *dataIn_Stop_anchor;

	/* Implementation data gates and counters update */
	if (context->dataIn_Start_counter == context->dataIn_Start_factor) {
		implState->dataIn_Start = context->dataIn_Start;
		context->dataIn_Start_counter = 0;
	} else {
		implState->dataIn_Start += context->blockSize;
	}
	if (context->dataIn_Stop_counter == context->dataIn_Stop_factor) {
		implState->dataIn_Stop = context->dataIn_Stop;
		context->dataIn_Stop_counter = 0;
	} else {
		implState->dataIn_Stop += context->blockSize;
	}

	/* Saves optimization data block */
	dataIn_Start_anchor = implState->dataIn_Start;
	dataIn_Stop_anchor = implState->dataIn_Stop;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MicroBenchEvaluator_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

	/* Restores optimization data block */
	implState->dataIn_Start = dataIn_Start_anchor;
	implState->dataIn_Stop = dataIn_Stop_anchor;

	/* Block counters increment */
	context->dataIn_Start_counter++;
	context->dataIn_Stop_counter++;

}

/* Process function */
void MicroBenchEvaluator_SoftwareUnit_processAutoPullBlock(DSPEComponent *component) {
	MicroBenchEvaluator_SoftwareUnit_block *context = (MicroBenchEvaluator_SoftwareUnit_block*) component;
	/* Implementation state local variable initialization */
	MicroBenchEvaluator_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MicroBenchFlag_StandardGate *dataIn_Start_anchor;
	MicroBenchFlag_StandardGate *dataIn_Stop_anchor;

	/* Implementation data gates and counters update */
	if (context->dataIn_Start_counter == context->dataIn_Start_factor) {
		implState->dataIn_Start = context->dataIn_Start;
		context->dataIn_Start_counter = 0;
	} else {
		implState->dataIn_Start += context->blockSize;
	}
	if (context->dataIn_Stop_counter == context->dataIn_Stop_factor) {
		implState->dataIn_Stop = context->dataIn_Stop;
		context->dataIn_Stop_counter = 0;
	} else {
		implState->dataIn_Stop += context->blockSize;
	}

	/* Saves optimization data block */
	dataIn_Start_anchor = implState->dataIn_Start;
	dataIn_Stop_anchor = implState->dataIn_Stop;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MicroBenchEvaluator_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

	/* Restores optimization data block */
	implState->dataIn_Start = dataIn_Start_anchor;
	implState->dataIn_Stop = dataIn_Stop_anchor;

	/* Block counters increment */
	context->dataIn_Start_counter++;
	context->dataIn_Stop_counter++;

}

/* PostProcess function */
void MicroBenchEvaluator_SoftwareUnit_postProcessBlock(DSPEComponent *component) {
	MicroBenchEvaluator_SoftwareUnit_block *context = (MicroBenchEvaluator_SoftwareUnit_block*) component;

	/* Implementation postprocess() call */
	MicroBenchEvaluator_Block_CImplementation_postProcess(context->implState);
}

/* Reset function */
void MicroBenchEvaluator_SoftwareUnit_resetBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {
	MicroBenchEvaluator_Block_CImplementation *implState = context->implState;

	/* Initialize gate values */
	initValuesBlock(context);

	/* Implementation AdditionalStateVariables initialization */
	((MicroBenchEvaluator_Block_CImplementation_func*) implState)->SCEnabled = 0;
	((MicroBenchEvaluator_Block_CImplementation_func*) implState)->samplesCounter = 0;
	((MicroBenchEvaluator_Block_CImplementation_func*) implState)->signalCounter = 0;
}

/* Shutdown function */
void MicroBenchEvaluator_SoftwareUnit_shutdownBlock(MicroBenchEvaluator_SoftwareUnit_block *context) {

	/* Output parameters places dispose */
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramOut_SamplesCount_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_ElapsedTime_place);
	MicroBenchSamplesPerSecond_StandardGate_dispose((DSPEElement*) context, context->paramOut_Throughput_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Min_L_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Mean_L_place);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Max_L_place);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Min_Lag_place);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Mean_Lag_place);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Max_Lag_place);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramOut_Trigger_place);

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Dispose implementation */
	MicroBenchEvaluator_Block_CImplementation_dispose((DSPEElement*) context, context->implState);
}

