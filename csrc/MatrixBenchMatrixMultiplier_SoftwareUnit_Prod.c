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

#include "MatrixBenchMatrixMultiplier_SoftwareUnit_Prod.h"

/* getID function */
char* MatrixBenchMatrixMultiplier_SoftwareUnit_getIDProd(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMultiplier_SoftwareUnit*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValues(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {

	/* Data output places initialization */
	MatrixBenchMatrix_PointerGate_initManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);
	MatrixBenchMatrix_PointerGate_set((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_placeAnchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixMultiplier_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixMultiplier_SoftwareUnit_getIDProd;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessProd;
	((DSPEComponent*) context)->process = MatrixBenchMatrixMultiplier_SoftwareUnit_processProd;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessProd;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {


	/* Output data places allocation */
	context->dataOut_Out_place = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	context->dataOut_Out_placeAnchor = MatrixBenchMatrix_PointerGate_allocate((DSPEElement*) context);

	/* Places anchors allocation */
	MatrixBenchMatrix_PointerGate_allocateManaged((DSPEElement*) context, context->dataOut_Out_placeAnchor);
}

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {

	/* Gates numLinks initialization */
	context->dataIn_In_numLinks = 0;
	context->dataOut_Out_numLinks = 0;

	/* Output data gates initialization */
	context->dataOut_Out = context->dataOut_Out_place;
}

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {

	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = context->implState;

	/* Implementation data gates initialization */
	implState->dataIn_In = context->dataIn_In;
	implState->dataOut_Out = context->dataOut_Out;

	/* Implementation gates numLinks initialization */
	implState->dataIn_In_numLinks = context->dataIn_In_numLinks;
	implState->dataOut_Out_numLinks = context->dataOut_Out_numLinks;

	/* Implementation blockSize initialization */
	implState->blockSize = 1;
}

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {

	/* Initialize gate values */
	initValues(context);
}

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessProd(DSPEComponent *component) {
}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processProd(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnitProd *context = (MatrixBenchMatrixMultiplier_SoftwareUnitProd*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixMultiplier_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullProd(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnitProd *context = (MatrixBenchMatrixMultiplier_SoftwareUnitProd*) component;
	/* Implementation state local variable initialization */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = context->implState;


	/* Capture unit process start time */
	profileManager_captureStartTime((DSPEElement*) context, (profileID) context->unitProfileID);


	/* Implementation process() call */
	MatrixBenchMatrixMultiplier_Block_CImplementation_process(implState);

	/* Capture unit process end time */
	profileManager_captureEndTime((DSPEElement*) context, (profileID) context->unitProfileID);

}

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessProd(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnitProd *context = (MatrixBenchMatrixMultiplier_SoftwareUnitProd*) component;
}

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {

	/* Initialize gate values */
	initValues(context);
}

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context) {

	/* UnitID dispose */
	memorySupport_dispose(context->ID);

	/* Output data places dispose */
	MatrixBenchMatrix_PointerGate_dispose((DSPEElement*) context, context->dataOut_Out_place);

	/* Places anchors memory dispose */
	MatrixBenchMatrix_PointerGate_disposeManaged((DSPEElement*) context, *context->dataOut_Out_placeAnchor);

	/* Places anchors memory dispose */
	MatrixBenchMatrix_PointerGate_dispose((DSPEElement*) context, context->dataOut_Out_placeAnchor);

	/* Dispose implementation */
	MatrixBenchMatrixMultiplier_Block_CImplementation_dispose((DSPEElement*) context, context->implState);
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* getID function */
char* MatrixBenchMatrixMultiplier_SoftwareUnit_getIDBlockProd(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMultiplier_SoftwareUnit_block*) element)->ID;
}


/******************************************************************************
 * GATE AUTOMATION SUPPORT FUNCTIONS
 ******************************************************************************/

/* Initialize gate values */
static INLINE void initValuesBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {

	/* Data output places initialization */
	MatrixBenchMatrix_PointerGate_initBlockManaged((DSPEElement*) context, context->dataOut_Out_anchor, context->dataOut_Out_size);
	MatrixBenchMatrix_PointerGate_setBlock((DSPEElement*) context, context->dataOut_Out_place, context->dataOut_Out_size, context->dataOut_Out_anchor);
}

/******************************************************************************
 * COMMON UNIT FUNCTIONS
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState = NULL;
	context->implState = MatrixBenchMatrixMultiplier_Block_CImplementation_allocate((DSPEElement*) context);
	implState = context->implState;
	initDSPEElement((DSPEElement*) implState, (DSPEElement*) context);
	initDSPEComponent((DSPEComponent*) context);
	((DSPEElement*) context)->getID = MatrixBenchMatrixMultiplier_SoftwareUnit_getIDBlockProd;
	((DSPEComponent*) context)->preprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlockProd;
	((DSPEComponent*) context)->process = MatrixBenchMatrixMultiplier_SoftwareUnit_processBlockProd;
	((DSPEComponent*) context)->postprocess = MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlockProd;

	/* Data gates size initialization */
	context->dataIn_In_size = context->blockSize;
	context->dataOut_Out_size = context->blockSize;

	/* Unit profile ID initialization */
	context->unitProfileID = (int) profileSupport_getProfileID(context->ID, NULL);
}

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {


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
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {

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
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {

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
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlockProd(DSPEComponent *component) {
}

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processBlockProd(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd*) component;
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullBlockProd(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd*) component;
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlockProd(DSPEComponent *component) {
	MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context = (MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd*) component;
}

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {

	/* Initialize gate values */
	initValuesBlock(context);
}

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context) {

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

