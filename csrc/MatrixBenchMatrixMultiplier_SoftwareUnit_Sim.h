/**
 * File: MatrixBenchMatrixMultiplier_SoftwareUnit.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MatrixBenchMatrixMultiplier_SoftwareUnit_Sim_h
#define MatrixBenchMatrixMultiplier_SoftwareUnit_Sim_h

#include "DSPEElements.h"


#include "MatrixBenchMatrixMultiplier_CImplementation.h"
#include "MatrixBenchMatrixMultiplier_Block_CImplementation.h"
#include "MatrixBenchMatrix_PointerGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixMultiplier_SoftwareUnitSim MatrixBenchMatrixMultiplier_SoftwareUnitSim;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixMultiplier_SoftwareUnitSim {
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
typedef struct MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim {
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
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullSim(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessSim(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownSim(MatrixBenchMatrixMultiplier_SoftwareUnitSim *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAllocBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

/* Alloc function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_allocBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

/* EarlyConnect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnectBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

/* Connect function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_connectBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

/* Startup function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_startupBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

/* PreProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_preProcessBlockSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processBlockSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_processAutoPullBlockSim(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_postProcessBlockSim(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_resetBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

/* Shutdown function */
void MatrixBenchMatrixMultiplier_SoftwareUnit_shutdownBlockSim(MatrixBenchMatrixMultiplier_SoftwareUnit_blockSim *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
