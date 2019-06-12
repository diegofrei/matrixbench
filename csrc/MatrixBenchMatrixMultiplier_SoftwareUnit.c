/**
 * File: MatrixBenchMatrixMultiplier_SoftwareUnit.c
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

#include "MatrixBenchMatrixMultiplier_SoftwareUnit.h"

/* getID function */
char* MatrixBenchMatrixMultiplier_SoftwareUnit_getID(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMultiplier_SoftwareUnit*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValues(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {

	/* Data output places initialization */
	MatrixBenchMatrix_PointerGate_initManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);
	MatrixBenchMatrix_PointerGate_set((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_placeAnchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAlloc(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {
	MatrixBenchMatrixMultiplier_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixMultiplier_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixMultiplier_SoftwareUnit_getID;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_preProcess;
	((DSPEComponent*) context)->process = MatrixBenchMatrixMultiplier_SoftwareUnit_process;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_postProcess;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_alloc(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {


	/* Output data places allocation */
	context->dataOut_Out_place = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	context->dataOut_Out_placeAnchor = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	MatrixBenchMatrix_PointerGate_allocateManaged((DSPEElement*) context, context->dataOut_Out_placeAnchor);
}

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnect(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {

	/* Gates numLinks initialization */
	context->dataIn_In_numLinks = 0;
	context->dataOut_Out_numLinks = 0;

	/* Output data gates initialization */
	context->dataOut_Out = context->dataOut_Out_place;
}

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connect(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {

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
void MatrixBenchMatrixMultiplier_SoftwareUnit_startup(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {

	/* Initialize gate values */
	initValues(context);
}

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcess(DSPEComponent *component) {
}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_process(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit *context = (MatrixBenchMatrixMultiplier_SoftwareUnit*) component;
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPull(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit *context = (MatrixBenchMatrixMultiplier_SoftwareUnit*) component;
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcess(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit *context = (MatrixBenchMatrixMultiplier_SoftwareUnit*) component;
}

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_reset(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {

	/* Initialize gate values */
	initValues(context);
}

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdown(MatrixBenchMatrixMultiplier_SoftwareUnit *context) {

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
char* MatrixBenchMatrixMultiplier_SoftwareUnit_getIDBlock(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMultiplier_SoftwareUnit_block*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValuesBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {

	/* Data output places initialization */
	MatrixBenchMatrix_PointerGate_initBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);
	MatrixBenchMatrix_PointerGate_setBlock((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_size, context->dataOut_Out_anchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixMultiplier_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixMultiplier_SoftwareUnit_getIDBlock;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlock;
	((DSPEComponent*) context)->process = MatrixBenchMatrixMultiplier_SoftwareUnit_processBlock;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlock;

	/* Data gates size initialization */
	context->dataIn_In_size = context->blockSize;
	context->dataOut_Out_size = context->blockSize;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {


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
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {

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
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {

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
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlock(DSPEComponent *component) {
}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processBlock(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_block *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_block*) component;
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullBlock(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_block *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_block*) component;
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlock(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_block *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_block*) component;
}

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context) {

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

