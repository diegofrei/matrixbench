/**
 * File: MatrixBenchMatrixSource_SoftwareUnit.c
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

#include "MatrixBenchMatrixSource_SoftwareUnit_Sim.h"

/* getID function */
char* MatrixBenchMatrixSource_SoftwareUnit_getIDSim(const DSPEElement *element) {
	return ((const MatrixBenchMatrixSource_SoftwareUnit*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValues(MatrixBenchMatrixSource_SoftwareUnitSim *context) {

	/* Parameter Output gates initialization */
	MicroBenchSignalsCount_StandardGate_initialize((DSPEElement*) context, context->paramOut_SentSignals_place);

	/* Data output places initialization */
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->dataOut_Start_place);
	MatrixBenchMatrix_PointerGate_initManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);
	MatrixBenchMatrix_PointerGate_set((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_placeAnchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {
	MatrixBenchMatrixSource_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixSource_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixSource_SoftwareUnit_getIDSim;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixSource_SoftwareUnit_preProcessSim;
	((DSPEComponent*) context)->process = MatrixBenchMatrixSource_SoftwareUnit_processSim;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixSource_SoftwareUnit_postProcessSim;

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->trigger = 0;
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->matrixID = 0;
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->matrixCnt = 0;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {

	/* Output parameters places allocation */
	context->paramOut_SentSignals_place = MicroBenchSignalsCount_StandardGate_allocate((DSPEElement*) context);


	/* Output data places allocation */
	context->dataOut_Start_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
	context->dataOut_Out_place = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	context->dataOut_Out_placeAnchor = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	MatrixBenchMatrix_PointerGate_allocateManaged((DSPEElement*) context, context->dataOut_Out_placeAnchor);
}

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_CImplementation *implState = context->implState;

	/* Implementation output parameters gates initialization */
	implState->paramOut_SentSignals = context->paramOut_SentSignals_place;

	/* Gates numLinks initialization */
	context->dataOut_Start_numLinks = 0;
	context->dataOut_Out_numLinks = 0;
	context->paramIn_Trigger_numLinks = 0;
	context->paramIn_AutomaticStop_numLinks = 0;
	context->paramIn_SamplesToProcess_numLinks = 0;
	context->paramIn_SignalSource_numLinks = 0;
	context->paramIn_ShowInfo_numLinks = 0;
	context->paramOut_SentSignals_numLinks = 0;

	/* Output parameters gates initialization */
	context->paramOut_SentSignals = context->paramOut_SentSignals_place;

	/* Output data gates initialization */
	context->dataOut_Start = context->dataOut_Start_place;
	context->dataOut_Out = context->dataOut_Out_place;
}

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_CImplementation *implState = context->implState;

	/* Implementation input parameters gates initialization */
	implState->paramIn_Trigger = context->paramIn_Trigger;
	implState->paramIn_AutomaticStop = context->paramIn_AutomaticStop;
	implState->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess;
	implState->paramIn_SignalSource = context->paramIn_SignalSource;
	implState->paramIn_ShowInfo = context->paramIn_ShowInfo;

	/* Implementation data gates initialization */
	implState->dataOut_Start = context->dataOut_Start;
	implState->dataOut_Out = context->dataOut_Out;

	/* Implementation gates numLinks initialization */
	implState->dataOut_Start_numLinks = context->dataOut_Start_numLinks;
	implState->dataOut_Out_numLinks = context->dataOut_Out_numLinks;
	implState->paramIn_Trigger_numLinks = context->paramIn_Trigger_numLinks;
	implState->paramIn_AutomaticStop_numLinks = context->paramIn_AutomaticStop_numLinks;
	implState->paramIn_SamplesToProcess_numLinks = context->paramIn_SamplesToProcess_numLinks;
	implState->paramIn_SignalSource_numLinks = context->paramIn_SignalSource_numLinks;
	implState->paramIn_ShowInfo_numLinks = context->paramIn_ShowInfo_numLinks;
	implState->paramOut_SentSignals_numLinks = context->paramOut_SentSignals_numLinks;
}

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {

	/* Initialize gate values */
	initValues(context);

	/* Implementation startup() call */
	MatrixBenchMatrixSource_CImplementation_startup(context->implState);
}

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnitSim *context = (MatrixBenchMatrixSource_SoftwareUnitSim*) component;

	/* Implementation preprocess() call */
	MatrixBenchMatrixSource_CImplementation_preProcess(context->implState);
}

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnitSim *context = (MatrixBenchMatrixSource_SoftwareUnitSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation prepareparams() call */
	MatrixBenchMatrixSource_CImplementation_prepareParams(implState);

	/* Implementation process() call */
	MatrixBenchMatrixSource_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnitSim *context = (MatrixBenchMatrixSource_SoftwareUnitSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation prepareparams() call */
	MatrixBenchMatrixSource_CImplementation_prepareParams(implState);

	/* Implementation process() call */
	MatrixBenchMatrixSource_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnitSim *context = (MatrixBenchMatrixSource_SoftwareUnitSim*) component;
}

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {
	MatrixBenchMatrixSource_CImplementation *implState = context->implState;

	/* Initialize gate values */
	initValues(context);

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->trigger = 0;
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->matrixID = 0;
	((MatrixBenchMatrixSource_CImplementation_func*) implState)->matrixCnt = 0;
}

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownSim(MatrixBenchMatrixSource_SoftwareUnitSim *context) {

	/* Output parameters places dispose */
	MicroBenchSignalsCount_StandardGate_dispose((DSPEElement*) context, context->paramOut_SentSignals_place);

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->dataOut_Start_place);
	MatrixBenchMatrix_PointerGate_dispose((DSPEElement*) context, context->dataOut_Out_place);

	/* Places anchors memory dispose */
	MatrixBenchMatrix_PointerGate_disposeManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);

	/* Places anchors memory dispose */
	MatrixBenchMatrix_PointerGate_dispose((DSPEElement*) context, context->dataOut_Out_placeAnchor);

	/* Dispose implementation */
	MatrixBenchMatrixSource_CImplementation_dispose((DSPEElement*) context, context->implState);
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* getID function */
char* MatrixBenchMatrixSource_SoftwareUnit_getIDBlockSim(const DSPEElement *element) {
	return ((const MatrixBenchMatrixSource_SoftwareUnit_block*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValuesBlock(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {

	/* Parameter Output gates initialization */
	MicroBenchSignalsCount_StandardGate_initialize((DSPEElement*) context, context->paramOut_SentSignals_place);

	/* Data output places initialization */
	MicroBenchFlag_StandardGate_initializeBlock((DSPEElement*) context, context->dataOut_Start_place, context->dataOut_Start_size);
	MatrixBenchMatrix_PointerGate_initBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);
	MatrixBenchMatrix_PointerGate_setBlock((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_size, context->dataOut_Out_anchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {
	MatrixBenchMatrixSource_Block_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixSource_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixSource_SoftwareUnit_getIDBlockSim;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixSource_SoftwareUnit_preProcessBlockSim;
	((DSPEComponent*) context)->process = MatrixBenchMatrixSource_SoftwareUnit_processBlockSim;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixSource_SoftwareUnit_postProcessBlockSim;

	/* Data gates size initialization */
	context->dataOut_Start_size = context->blockSize;
	context->dataOut_Out_size = context->blockSize;

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->trigger = 0;
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->matrixID = 0;
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->matrixCnt = 0;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {

	/* Output parameters places allocation */
	context->paramOut_SentSignals_place = MicroBenchSignalsCount_StandardGate_allocate((DSPEElement*) context);


	/* Data output gates factor and counter initialization */
	context->dataOut_Start_factor = context->dataOut_Start_size / context->blockSize;
	context->dataOut_Out_factor = context->dataOut_Out_size / context->blockSize;

	/* Data output gates factor and counter initialization */
	context->dataOut_Start_counter = context->dataOut_Start_factor;
	context->dataOut_Out_counter = context->dataOut_Out_factor;

	/* Output data places memory allocation */
	context->dataOut_Start_place = MicroBenchFlag_StandardGate_allocateBlock((DSPEElement*) context, context->dataOut_Start_size);
	context->dataOut_Out_place = MatrixBenchMatrix_PointerGate_allocateBlock((DSPEElement*) context, context->dataOut_Out_size);

	/* Places anchors allocation */
	context->dataOut_Out_anchor = MatrixBenchMatrix_PointerGate_allocateBlock((DSPEElement*) context, context->dataOut_Out_size);

	/* Places anchors allocation */
	MatrixBenchMatrix_PointerGate_allocateBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);
}

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_Block_CImplementation *implState = context->implState;

	/* Implementation output parameters gates initialization */
	implState->paramOut_SentSignals = context->paramOut_SentSignals_place;

	/* Gates numLinks initialization */
	context->dataOut_Start_numLinks = 0;
	context->dataOut_Out_numLinks = 0;
	context->paramIn_Trigger_numLinks = 0;
	context->paramIn_AutomaticStop_numLinks = 0;
	context->paramIn_SamplesToProcess_numLinks = 0;
	context->paramIn_SignalSource_numLinks = 0;
	context->paramIn_ShowInfo_numLinks = 0;
	context->paramOut_SentSignals_numLinks = 0;

	/* Output parameters gates initialization */
	context->paramOut_SentSignals = context->paramOut_SentSignals_place;

	/* Output data gates initialization */
	context->dataOut_Start = context->dataOut_Start_place;
	context->dataOut_Out = context->dataOut_Out_place;
}

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_Block_CImplementation *implState = context->implState;

	/* Implementation input parameters gates initialization */
	implState->paramIn_Trigger = context->paramIn_Trigger;
	implState->paramIn_AutomaticStop = context->paramIn_AutomaticStop;
	implState->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess;
	implState->paramIn_SignalSource = context->paramIn_SignalSource;
	implState->paramIn_ShowInfo = context->paramIn_ShowInfo;

	/* Implementation blocksize initialization */
	implState->blockSize = context->blockSize;

	/* Implementation data gates initialization */
	implState->dataOut_Start = context->dataOut_Start;
	implState->dataOut_Out = context->dataOut_Out;

	/* Implementation gates numLinks initialization */
	implState->dataOut_Start_numLinks = context->dataOut_Start_numLinks;
	implState->dataOut_Out_numLinks = context->dataOut_Out_numLinks;
	implState->paramIn_Trigger_numLinks = context->paramIn_Trigger_numLinks;
	implState->paramIn_AutomaticStop_numLinks = context->paramIn_AutomaticStop_numLinks;
	implState->paramIn_SamplesToProcess_numLinks = context->paramIn_SamplesToProcess_numLinks;
	implState->paramIn_SignalSource_numLinks = context->paramIn_SignalSource_numLinks;
	implState->paramIn_ShowInfo_numLinks = context->paramIn_ShowInfo_numLinks;
	implState->paramOut_SentSignals_numLinks = context->paramOut_SentSignals_numLinks;
}

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {

	/* Initialize gate values */
	initValuesBlock(context);

	/* Implementation startup() call */
	MatrixBenchMatrixSource_Block_CImplementation_startup(context->implState);
}

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnit_blockSim *context = (MatrixBenchMatrixSource_SoftwareUnit_blockSim*) component;
	MatrixBenchMatrixSource_Block_CImplementation *implState = context->implState;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Implementation preprocess() call */
	MatrixBenchMatrixSource_Block_CImplementation_preProcess(context->implState);
}

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnit_blockSim *context = (MatrixBenchMatrixSource_SoftwareUnit_blockSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MicroBenchFlag_StandardGate *dataOut_Start_anchor;
	MatrixBenchMatrix_PointerGate *dataOut_Out_anchor;

	/* Implementation data gates and counters update */
	if (context->dataOut_Start_counter == context->dataOut_Start_factor) {
		implState->dataOut_Start = context->dataOut_Start;
		context->dataOut_Start_counter = 0;
	} else {
		implState->dataOut_Start += context->blockSize;
	}
	if (context->dataOut_Out_counter == context->dataOut_Out_factor) {
		implState->dataOut_Out = context->dataOut_Out;
		context->dataOut_Out_counter = 0;
	} else {
		implState->dataOut_Out += context->blockSize;
	}

	/* Saves optimization data block */
	dataOut_Start_anchor = implState->dataOut_Start;
	dataOut_Out_anchor = implState->dataOut_Out;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixSource_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

	/* Restores optimization data block */
	implState->dataOut_Start = dataOut_Start_anchor;
	implState->dataOut_Out = dataOut_Out_anchor;

	/* Block counters increment */
	context->dataOut_Start_counter++;
	context->dataOut_Out_counter++;

}

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnit_blockSim *context = (MatrixBenchMatrixSource_SoftwareUnit_blockSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixSource_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MicroBenchFlag_StandardGate *dataOut_Start_anchor;
	MatrixBenchMatrix_PointerGate *dataOut_Out_anchor;

	/* Implementation data gates and counters update */
	if (context->dataOut_Start_counter == context->dataOut_Start_factor) {
		implState->dataOut_Start = context->dataOut_Start;
		context->dataOut_Start_counter = 0;
	} else {
		implState->dataOut_Start += context->blockSize;
	}
	if (context->dataOut_Out_counter == context->dataOut_Out_factor) {
		implState->dataOut_Out = context->dataOut_Out;
		context->dataOut_Out_counter = 0;
	} else {
		implState->dataOut_Out += context->blockSize;
	}

	/* Saves optimization data block */
	dataOut_Start_anchor = implState->dataOut_Start;
	dataOut_Out_anchor = implState->dataOut_Out;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixSource_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

	/* Restores optimization data block */
	implState->dataOut_Start = dataOut_Start_anchor;
	implState->dataOut_Out = dataOut_Out_anchor;

	/* Block counters increment */
	context->dataOut_Start_counter++;
	context->dataOut_Out_counter++;

}

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixSource_SoftwareUnit_blockSim *context = (MatrixBenchMatrixSource_SoftwareUnit_blockSim*) component;
}

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {
	MatrixBenchMatrixSource_Block_CImplementation *implState = context->implState;

	/* Initialize gate values */
	initValuesBlock(context);

	/* Implementation AdditionalStateVariables initialization */
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->trigger = 0;
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->show = 0;
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->matrixID = 0;
	((MatrixBenchMatrixSource_Block_CImplementation_func*) implState)->matrixCnt = 0;
}

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context) {

	/* Output parameters places dispose */
	MicroBenchSignalsCount_StandardGate_dispose((DSPEElement*) context, context->paramOut_SentSignals_place);

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MicroBenchFlag_StandardGate_disposeBlock((DSPEElement*) context, context->dataOut_Start_place);
	MatrixBenchMatrix_PointerGate_disposeBlock((DSPEElement*) context, context->dataOut_Out_place);

	/* Places memory dispose */
	MatrixBenchMatrix_PointerGate_disposeBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);

	/* Places memory dispose */
	MatrixBenchMatrix_PointerGate_disposeBlock((DSPEElement*) context, context->dataOut_Out_anchor);

	/* Dispose implementation */
	MatrixBenchMatrixSource_Block_CImplementation_dispose((DSPEElement*) context, context->implState);
}

