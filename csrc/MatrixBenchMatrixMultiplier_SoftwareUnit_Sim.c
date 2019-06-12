/**
 * File: MatrixBenchMatrixMultiplier_SoftwareUnit.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "PlatformManager.h"
#include "StringManager.h"
#include "MemoryManager.h"
#include "EngineManager.h"
#include "ProfileManager.h"
#include "ErrorManager.h"

#include "MatrixBenchMatrixMultiplier_SoftwareUnit_Sim.h"

/* getID function */
char* MatrixBenchMatrixMultiplier_SoftwareUnit_getIDSim(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMultiplier_SoftwareUnit*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValues(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {

	/* Data output places initialization */
	MatrixBenchMatrix_PointerGate_initManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);
	MatrixBenchMatrix_PointerGate_set((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_placeAnchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {
	MatrixBenchMatrixMultiplier_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixMultiplier_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixMultiplier_SoftwareUnit_getIDSim;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessSim;
	((DSPEComponent*) context)->process = MatrixBenchMatrixMultiplier_SoftwareUnit_processSim;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessSim;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {


	/* Output data places allocation */
	context->dataOut_Out_place = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	context->dataOut_Out_placeAnchor = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	MatrixBenchMatrix_PointerGate_allocateManaged((DSPEElement*) context, context->dataOut_Out_placeAnchor);
}

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {

	/* Gates numLinks initialization */
	context->dataIn_In_numLinks = 0;
	context->dataOut_Out_numLinks = 0;

	/* Output data gates initialization */
	context->dataOut_Out = context->dataOut_Out_place;
}

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_CImplementation *implState = context->implState;

	/* Implementation data gates initialization */
	implState->dataIn_In = context->dataIn_In;
	implState->dataOut_Out = context->dataOut_Out;

	/* Implementation gates numLinks initialization */
	implState->dataIn_In_numLinks = context->dataIn_In_numLinks;
	implState->dataOut_Out_numLinks = context->dataOut_Out_numLinks;
}

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {

	/* Initialize gate values */
	initValues(context);
}

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessSim(DSPEComponent *component) {
}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processSim(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnitSim *context = (MatrixBenchMatrixMultiplier_SoftwareUnitSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixMultiplier_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullSim(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnitSim *context = (MatrixBenchMatrixMultiplier_SoftwareUnitSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixMultiplier_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessSim(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnitSim *context = (MatrixBenchMatrixMultiplier_SoftwareUnitSim*) component;
}

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {

	/* Initialize gate values */
	initValues(context);
}

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context) {

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MatrixBenchMatrix_PointerGate_dispose((DSPEElement*) context, context->dataOut_Out_place);

	/* Places anchors memory dispose */
	MatrixBenchMatrix_PointerGate_disposeManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);

	/* Places anchors memory dispose */
	MatrixBenchMatrix_PointerGate_dispose((DSPEElement*) context, context->dataOut_Out_placeAnchor);

	/* Dispose implementation */
	MatrixBenchMatrixMultiplier_CImplementation_dispose((DSPEElement*) context, context->implState);
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* getID function */
char* MatrixBenchMatrixMultiplier_SoftwareUnit_getIDBlockSim(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMultiplier_SoftwareUnit_block*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValuesBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {

	/* Data output places initialization */
	MatrixBenchMatrix_PointerGate_initBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);
	MatrixBenchMatrix_PointerGate_setBlock((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_size, context->dataOut_Out_anchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixMultiplier_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixMultiplier_SoftwareUnit_getIDBlockSim;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlockSim;
	((DSPEComponent*) context)->process = MatrixBenchMatrixMultiplier_SoftwareUnit_processBlockSim;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlockSim;

	/* Data gates size initialization */
	context->dataIn_In_size = context->blockSize;
	context->dataOut_Out_size = context->blockSize;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {


	/* Data output gates factor and counter initialization */
	context->dataOut_Out_factor = context->dataOut_Out_size / context->blockSize;

	/* Data output gates factor and counter initialization */
	context->dataOut_Out_counter = context->dataOut_Out_factor;

	/* Output data places memory allocation */
	context->dataOut_Out_place = MatrixBenchMatrix_PointerGate_allocateBlock((DSPEElement*) context, context->dataOut_Out_size);

	/* Places anchors allocation */
	context->dataOut_Out_anchor = MatrixBenchMatrix_PointerGate_allocateBlock((DSPEElement*) context, context->dataOut_Out_size);

	/* Places anchors allocation */
	MatrixBenchMatrix_PointerGate_allocateBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);
}

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {

	/* Gates numLinks initialization */
	context->dataIn_In_numLinks = 0;
	context->dataOut_Out_numLinks = 0;

	/* Input data gates factor and counter initialization */
	context->dataIn_In_factor = context->dataIn_In_size / context->blockSize;

	/* Input data gates factor and counter initialization */
	context->dataIn_In_counter = context->dataIn_In_factor;

	/* Output data gates initialization */
	context->dataOut_Out = context->dataOut_Out_place;
}

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = context->implState;

	/* Implementation blocksize initialization */
	implState->blockSize = context->blockSize;

	/* Implementation data gates initialization */
	implState->dataIn_In = context->dataIn_In;
	implState->dataOut_Out = context->dataOut_Out;

	/* Implementation gates numLinks initialization */
	implState->dataIn_In_numLinks = context->dataIn_In_numLinks;
	implState->dataOut_Out_numLinks = context->dataOut_Out_numLinks;
}

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlockSim(DSPEComponent *component) {
}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MatrixBenchMatrix_PointerGate *dataIn_In_anchor;
	MatrixBenchMatrix_PointerGate *dataOut_Out_anchor;

	/* Implementation data gates and counters update */
	if (context->dataIn_In_counter == context->dataIn_In_factor) {
		implState->dataIn_In = context->dataIn_In;
		context->dataIn_In_counter = 0;
	} else {
		implState->dataIn_In += context->blockSize;
	}
	if (context->dataOut_Out_counter == context->dataOut_Out_factor) {
		implState->dataOut_Out = context->dataOut_Out;
		context->dataOut_Out_counter = 0;
	} else {
		implState->dataOut_Out += context->blockSize;
	}

	/* Saves optimization data block */
	dataIn_In_anchor = implState->dataIn_In;
	dataOut_Out_anchor = implState->dataOut_Out;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixMultiplier_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

	/* Restores optimization data block */
	implState->dataIn_In = dataIn_In_anchor;
	implState->dataOut_Out = dataOut_Out_anchor;

	/* Block counters increment */
	context->dataIn_In_counter++;
	context->dataOut_Out_counter++;

}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = context->implState;

	/* Block optimization data block anchors */
	MatrixBenchMatrix_PointerGate *dataIn_In_anchor;
	MatrixBenchMatrix_PointerGate *dataOut_Out_anchor;

	/* Implementation data gates and counters update */
	if (context->dataIn_In_counter == context->dataIn_In_factor) {
		implState->dataIn_In = context->dataIn_In;
		context->dataIn_In_counter = 0;
	} else {
		implState->dataIn_In += context->blockSize;
	}
	if (context->dataOut_Out_counter == context->dataOut_Out_factor) {
		implState->dataOut_Out = context->dataOut_Out;
		context->dataOut_Out_counter = 0;
	} else {
		implState->dataOut_Out += context->blockSize;
	}

	/* Saves optimization data block */
	dataIn_In_anchor = implState->dataIn_In;
	dataOut_Out_anchor = implState->dataOut_Out;

	/* Implementation blockSize assignment */
	implState->blockSize = context->samplesToProcess;

	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixMultiplier_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

	/* Restores optimization data block */
	implState->dataIn_In = dataIn_In_anchor;
	implState->dataOut_Out = dataOut_Out_anchor;

	/* Block counters increment */
	context->dataIn_In_counter++;
	context->dataOut_Out_counter++;

}

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlockSim(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim*) component;
}

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context) {

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MatrixBenchMatrix_PointerGate_disposeBlock((DSPEElement*) context, context->dataOut_Out_place);

	/* Places memory dispose */
	MatrixBenchMatrix_PointerGate_disposeBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);

	/* Places memory dispose */
	MatrixBenchMatrix_PointerGate_disposeBlock((DSPEElement*) context, context->dataOut_Out_anchor);

	/* Dispose implementation */
	MatrixBenchMatrixMultiplier_Block_CImplementation_dispose((DSPEElement*) context, context->implState);
}

