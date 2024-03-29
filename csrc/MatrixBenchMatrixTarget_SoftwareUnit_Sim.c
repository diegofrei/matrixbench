/**
 * File: MatrixBenchMatrixTarget_SoftwareUnit.c
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

#include "MatrixBenchMatrixTarget_SoftwareUnit_Sim.h"

/* getID function */
char* MatrixBenchMatrixTarget_SoftwareUnit_getIDSim(const DSPEElement *element) {
	return ((const MatrixBenchMatrixTarget_SoftwareUnit*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValues(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {

	/* Parameter Output gates initialization */
	MicroBenchSignalsCount_StandardGate_initialize((DSPEElement*) context, context->paramOut_ReceivedSignals_place);
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramOut_OutOfSynchSamples_place);

	/* Data output places initialization */
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->dataOut_Stop_place);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {
	MatrixBenchMatrixTarget_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixTarget_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixTarget_SoftwareUnit_getIDSim;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixTarget_SoftwareUnit_preProcessSim;
	((DSPEComponent*) context)->process = MatrixBenchMatrixTarget_SoftwareUnit_processSim;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixTarget_SoftwareUnit_postProcessSim;

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixTarget_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixTarget_CImplementation_func*) implState)->matrixCounter = 0;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {

	/* Output parameters places allocation */
	context->paramOut_ReceivedSignals_place = MicroBenchSignalsCount_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_OutOfSynchSamples_place = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);


	/* Output data places allocation */
	context->dataOut_Stop_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
}

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_CImplementation *implState = context->implState;

	/* Implementation output parameters gates initialization */
	implState->paramOut_ReceivedSignals = context->paramOut_ReceivedSignals_place;
	implState->paramOut_OutOfSynchSamples = context->paramOut_OutOfSynchSamples_place;

	/* Gates numLinks initialization */
	context->dataIn_In_numLinks = 0;
	context->dataOut_Stop_numLinks = 0;
	context->paramIn_SignalSource_numLinks = 0;
	context->paramIn_ShowInfo_numLinks = 0;
	context->paramOut_ReceivedSignals_numLinks = 0;
	context->paramOut_OutOfSynchSamples_numLinks = 0;

	/* Output parameters gates initialization */
	context->paramOut_ReceivedSignals = context->paramOut_ReceivedSignals_place;
	context->paramOut_OutOfSynchSamples = context->paramOut_OutOfSynchSamples_place;

	/* Output data gates initialization */
	context->dataOut_Stop = context->dataOut_Stop_place;
}

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_CImplementation *implState = context->implState;

	/* Implementation input parameters gates initialization */
	implState->paramIn_SignalSource = context->paramIn_SignalSource;
	implState->paramIn_ShowInfo = context->paramIn_ShowInfo;

	/* Implementation data gates initialization */
	implState->dataIn_In = context->dataIn_In;
	implState->dataOut_Stop = context->dataOut_Stop;

	/* Implementation gates numLinks initialization */
	implState->dataIn_In_numLinks = context->dataIn_In_numLinks;
	implState->dataOut_Stop_numLinks = context->dataOut_Stop_numLinks;
	implState->paramIn_SignalSource_numLinks = context->paramIn_SignalSource_numLinks;
	implState->paramIn_ShowInfo_numLinks = context->paramIn_ShowInfo_numLinks;
	implState->paramOut_ReceivedSignals_numLinks = context->paramOut_ReceivedSignals_numLinks;
	implState->paramOut_OutOfSynchSamples_numLinks = context->paramOut_OutOfSynchSamples_numLinks;
}

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {

	/* Initialize gate values */
	initValues(context);
}

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnitSim *context = (MatrixBenchMatrixTarget_SoftwareUnitSim*) component;

	/* Implementation preprocess() call */
	MatrixBenchMatrixTarget_CImplementation_preProcess(context->implState);
}

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnitSim *context = (MatrixBenchMatrixTarget_SoftwareUnitSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixTarget_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Increment application process count */
	if (profileManager_isProfileUnit((DSPEElement*) context, (profileID) context->unitProfileID))
		profileManager_incrementSamplesCount((DSPEElement*) context, 1);

}

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnitSim *context = (MatrixBenchMatrixTarget_SoftwareUnitSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixTarget_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Increment application process count */
	if (profileManager_isProfileUnit((DSPEElement*) context, (profileID) context->unitProfileID))
		profileManager_incrementSamplesCount((DSPEElement*) context, 1);

}

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnitSim *context = (MatrixBenchMatrixTarget_SoftwareUnitSim*) component;
}

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {
	MatrixBenchMatrixTarget_CImplementation *implState = context->implState;

	/* Initialize gate values */
	initValues(context);

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixTarget_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixTarget_CImplementation_func*) implState)->matrixCounter = 0;
}

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context) {

	/* Output parameters places dispose */
	MicroBenchSignalsCount_StandardGate_dispose((DSPEElement*) context, context->paramOut_ReceivedSignals_place);
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramOut_OutOfSynchSamples_place);

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->dataOut_Stop_place);

	/* Dispose implementation */
	MatrixBenchMatrixTarget_CImplementation_dispose((DSPEElement*) context, context->implState);
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* getID function */
char* MatrixBenchMatrixTarget_SoftwareUnit_getIDBlockSim(const DSPEElement *element) {
	return ((const MatrixBenchMatrixTarget_SoftwareUnit_block*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValuesBlock(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {

	/* Parameter Output gates initialization */
	MicroBenchSignalsCount_StandardGate_initialize((DSPEElement*) context, context->paramOut_ReceivedSignals_place);
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramOut_OutOfSynchSamples_place);

	/* Data output places initialization */
	MicroBenchFlag_StandardGate_initializeBlock((DSPEElement*) context, context->dataOut_Stop_place, context->dataOut_Stop_size);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {
	MatrixBenchMatrixTarget_Block_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixTarget_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixTarget_SoftwareUnit_getIDBlockSim;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixTarget_SoftwareUnit_preProcessBlockSim;
	((DSPEComponent*) context)->process = MatrixBenchMatrixTarget_SoftwareUnit_processBlockSim;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixTarget_SoftwareUnit_postProcessBlockSim;

	/* Data gates size initialization */
	context->dataIn_In_size = context->blockSize;
	context->dataOut_Stop_size = context->blockSize;

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixTarget_Block_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixTarget_Block_CImplementation_func*) implState)->matrixCounter = 0;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {

	/* Output parameters places allocation */
	context->paramOut_ReceivedSignals_place = MicroBenchSignalsCount_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_OutOfSynchSamples_place = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);


	/* Data output gates factor and counter initialization */
	context->dataOut_Stop_factor = context->dataOut_Stop_size / context->blockSize;

	/* Data output gates factor and counter initialization */
	context->dataOut_Stop_counter = context->dataOut_Stop_factor;

	/* Output data places memory allocation */
	context->dataOut_Stop_place = MicroBenchFlag_StandardGate_allocateBlock((DSPEElement*) context, context->dataOut_Stop_size);
}

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_Block_CImplementation *implState = context->implState;

	/* Implementation output parameters gates initialization */
	implState->paramOut_ReceivedSignals = context->paramOut_ReceivedSignals_place;
	implState->paramOut_OutOfSynchSamples = context->paramOut_OutOfSynchSamples_place;

	/* Gates numLinks initialization */
	context->dataIn_In_numLinks = 0;
	context->dataOut_Stop_numLinks = 0;
	context->paramIn_SignalSource_numLinks = 0;
	context->paramIn_ShowInfo_numLinks = 0;
	context->paramOut_ReceivedSignals_numLinks = 0;
	context->paramOut_OutOfSynchSamples_numLinks = 0;

	/* Output parameters gates initialization */
	context->paramOut_ReceivedSignals = context->paramOut_ReceivedSignals_place;
	context->paramOut_OutOfSynchSamples = context->paramOut_OutOfSynchSamples_place;

	/* Input data gates factor and counter initialization */
	context->dataIn_In_factor = context->dataIn_In_size / context->blockSize;

	/* Input data gates factor and counter initialization */
	context->dataIn_In_counter = context->dataIn_In_factor;

	/* Output data gates initialization */
	context->dataOut_Stop = context->dataOut_Stop_place;
}

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_Block_CImplementation *implState = context->implState;

	/* Implementation input parameters gates initialization */
	implState->paramIn_SignalSource = context->paramIn_SignalSource;
	implState->paramIn_ShowInfo = context->paramIn_ShowInfo;

	/* Implementation blocksize initialization */
	implState->blockSize = context->blockSize;

	/* Implementation data gates initialization */
	implState->dataIn_In = context->dataIn_In;
	implState->dataOut_Stop = context->dataOut_Stop;

	/* Implementation gates numLinks initialization */
	implState->dataIn_In_numLinks = context->dataIn_In_numLinks;
	implState->dataOut_Stop_numLinks = context->dataOut_Stop_numLinks;
	implState->paramIn_SignalSource_numLinks = context->paramIn_SignalSource_numLinks;
	implState->paramIn_ShowInfo_numLinks = context->paramIn_ShowInfo_numLinks;
	implState->paramOut_ReceivedSignals_numLinks = context->paramOut_ReceivedSignals_numLinks;
	implState->paramOut_OutOfSynchSamples_numLinks = context->paramOut_OutOfSynchSamples_numLinks;
}

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context = (MatrixBenchMatrixTarget_SoftwareUnit_blockSim*) component;
	MatrixBenchMatrixTarget_Block_CImplementation *implState = context->implState;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Implementation preprocess() call */
	MatrixBenchMatrixTarget_Block_CImplementation_preProcess(context->implState);
}

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context = (MatrixBenchMatrixTarget_SoftwareUnit_blockSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MatrixBenchMatrix_PointerGate *dataIn_In_anchor;
	MicroBenchFlag_StandardGate *dataOut_Stop_anchor;

	/* Implementation data gates and counters update */
	if (context->dataIn_In_counter == context->dataIn_In_factor) {
		implState->dataIn_In = context->dataIn_In;
		context->dataIn_In_counter = 0;
	} else {
		implState->dataIn_In += context->blockSize;
	}
	if (context->dataOut_Stop_counter == context->dataOut_Stop_factor) {
		implState->dataOut_Stop = context->dataOut_Stop;
		context->dataOut_Stop_counter = 0;
	} else {
		implState->dataOut_Stop += context->blockSize;
	}

	/* Saves optimization data block */
	dataIn_In_anchor = implState->dataIn_In;
	dataOut_Stop_anchor = implState->dataOut_Stop;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixTarget_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Increment application process count */
	if (profileManager_isProfileUnit((DSPEElement*) context, (profileID) context->unitProfileID))
		profileManager_incrementSamplesCount((DSPEElement*) context, (unsigned int)context->samplesToProcess);

	/* Restores optimization data block */
	implState->dataIn_In = dataIn_In_anchor;
	implState->dataOut_Stop = dataOut_Stop_anchor;

	/* Block counters increment */
	context->dataIn_In_counter++;
	context->dataOut_Stop_counter++;

}

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context = (MatrixBenchMatrixTarget_SoftwareUnit_blockSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixTarget_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MatrixBenchMatrix_PointerGate *dataIn_In_anchor;
	MicroBenchFlag_StandardGate *dataOut_Stop_anchor;

	/* Implementation data gates and counters update */
	if (context->dataIn_In_counter == context->dataIn_In_factor) {
		implState->dataIn_In = context->dataIn_In;
		context->dataIn_In_counter = 0;
	} else {
		implState->dataIn_In += context->blockSize;
	}
	if (context->dataOut_Stop_counter == context->dataOut_Stop_factor) {
		implState->dataOut_Stop = context->dataOut_Stop;
		context->dataOut_Stop_counter = 0;
	} else {
		implState->dataOut_Stop += context->blockSize;
	}

	/* Saves optimization data block */
	dataIn_In_anchor = implState->dataIn_In;
	dataOut_Stop_anchor = implState->dataOut_Stop;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixTarget_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Increment application process count */
	if (profileManager_isProfileUnit((DSPEElement*) context, (profileID) context->unitProfileID))
		profileManager_incrementSamplesCount((DSPEElement*) context, (unsigned int)context->samplesToProcess);

	/* Restores optimization data block */
	implState->dataIn_In = dataIn_In_anchor;
	implState->dataOut_Stop = dataOut_Stop_anchor;

	/* Block counters increment */
	context->dataIn_In_counter++;
	context->dataOut_Stop_counter++;

}

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context = (MatrixBenchMatrixTarget_SoftwareUnit_blockSim*) component;
}

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {
	MatrixBenchMatrixTarget_Block_CImplementation *implState = context->implState;

	/* Initialize gate values */
	initValuesBlock(context);

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixTarget_Block_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixTarget_Block_CImplementation_func*) implState)->matrixCounter = 0;
}

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context) {

	/* Output parameters places dispose */
	MicroBenchSignalsCount_StandardGate_dispose((DSPEElement*) context, context->paramOut_ReceivedSignals_place);
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramOut_OutOfSynchSamples_place);

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MicroBenchFlag_StandardGate_disposeBlock((DSPEElement*) context, context->dataOut_Stop_place);

	/* Dispose implementation */
	MatrixBenchMatrixTarget_Block_CImplementation_dispose((DSPEElement*) context, context->implState);
}

