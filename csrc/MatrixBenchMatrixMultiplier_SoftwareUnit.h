/**
 * File: MatrixBenchMatrixMultiplier_SoftwareUnit.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MatrixBenchMatrixMultiplier_SoftwareUnit_h
#define MatrixBenchMatrixMultiplier_SoftwareUnit_h

#include "DSPEElements.h"


#include "MatrixBenchMatrixMultiplier_CImplementation.h"
#include "MatrixBenchMatrixMultiplier_Block_CImplementation.h"
#include "MatrixBenchMatrix_PointerGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixMultiplier_SoftwareUnit MatrixBenchMatrixMultiplier_SoftwareUnit;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixMultiplier_SoftwareUnit {
	DSPEUnit unit;
	

	/* Gates numLinks */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Out_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixMultiplier_CImplementation *implState;
	

	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MatrixBenchMatrix_PointerGate *dataOut_Out;


	/* Output data places */
	MatrixBenchMatrix_PointerGate *dataOut_Out_place;


	/* Output data places anchors */
	MatrixBenchMatrix_PointerGate *dataOut_Out_placeAnchor;
	/* Unit profile ID */
	int unitProfileID;
};

// BLOCK UNIT
/* Block SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixMultiplier_SoftwareUnit_block MatrixBenchMatrixMultiplier_SoftwareUnit_block;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixMultiplier_SoftwareUnit_block {
	DSPEUnit unit;
	

	/* Gates numLinks */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Out_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState;
	
	/* Block size */
	size_t blockSize;

	/* Samples to process */
	size_t samplesToProcess;


	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MatrixBenchMatrix_PointerGate *dataOut_Out;


	/* Data gates sizes */
	size_t dataIn_In_size;
	size_t dataOut_Out_size;


	/* Data gates factors */
	size_t dataIn_In_factor;
	size_t dataOut_Out_factor;


	/* Data gates counters */
	size_t dataIn_In_counter;
	size_t dataOut_Out_counter;


	/* Output data places */
	MatrixBenchMatrix_PointerGate *dataOut_Out_place;


	/* Output data places anchors */
	MatrixBenchMatrix_PointerGate *dataOut_Out_anchor;
	/* Unit profile ID */
	int unitProfileID;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAlloc(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_alloc(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnect(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connect(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startup(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcess(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_process(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPull(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcess(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_reset(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdown(MatrixBenchMatrixMultiplier_SoftwareUnit *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlock(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processBlock(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullBlock(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlock(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownBlock(MatrixBenchMatrixMultiplier_SoftwareUnit_block *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
