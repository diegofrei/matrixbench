/**
 * File: MatrixBenchMatrixMultiplier_SoftwareUnit.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixMultiplier_SoftwareUnit_Prod_h
#define MatrixBenchMatrixMultiplier_SoftwareUnit_Prod_h

#include "DSPEElements.h"


#include "MatrixBenchMatrixMultiplier_Block_CImplementation.h"
#include "MatrixBenchMatrixMultiplier_Block_CImplementation.h"
#include "MatrixBenchMatrix_PointerGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixMultiplier_SoftwareUnitProd MatrixBenchMatrixMultiplier_SoftwareUnitProd;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixMultiplier_SoftwareUnitProd {
	DSPEUnit unit;
	

	/* Gates numLinks */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Out_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixMultiplier_Block_CImplementation *implState;
	

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
typedef struct MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd {
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullProd(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessProd(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownProd(MatrixBenchMatrixMultiplier_SoftwareUnitProd *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlockProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processBlockProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullBlockProd(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlockProd(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownBlockProd(MatrixBenchMatrixMultiplier_SoftwareUnit_blockProd *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
