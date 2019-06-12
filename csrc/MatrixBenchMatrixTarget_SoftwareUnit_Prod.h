/**
 * File: MatrixBenchMatrixTarget_SoftwareUnit.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixTarget_SoftwareUnit_Prod_h
#define MatrixBenchMatrixTarget_SoftwareUnit_Prod_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"

#include "MatrixBenchMatrixTarget_Block_CImplementation.h"
#include "MatrixBenchMatrixTarget_Block_CImplementation.h"
#include "MatrixBenchMatrix_PointerGate.h"
#include "MicroBenchFlag_StandardGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixTarget_SoftwareUnitProd MatrixBenchMatrixTarget_SoftwareUnitProd;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixTarget_SoftwareUnitProd {
	DSPEUnit unit;
	

	/* Parameter gates */
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples;

	/* Output parameters places */
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals_place;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples_place;

	/* Gates numLinks */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Stop_numLinks;
	unsigned int paramIn_SignalSource_numLinks;
	unsigned int paramIn_ShowInfo_numLinks;
	unsigned int paramOut_ReceivedSignals_numLinks;
	unsigned int paramOut_OutOfSynchSamples_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixTarget_Block_CImplementation *implState;
	

	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MicroBenchFlag_StandardGate *dataOut_Stop;


	/* Output data places */
	MicroBenchFlag_StandardGate *dataOut_Stop_place;

	/* Unit profile ID */
	int unitProfileID;
};

// BLOCK UNIT
/* Block SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixTarget_SoftwareUnit_blockProd MatrixBenchMatrixTarget_SoftwareUnit_blockProd;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixTarget_SoftwareUnit_blockProd {
	DSPEUnit unit;
	

	/* Parameter gates */
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples;

	/* Output parameters places */
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals_place;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples_place;

	/* Gates numLinks */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Stop_numLinks;
	unsigned int paramIn_SignalSource_numLinks;
	unsigned int paramIn_ShowInfo_numLinks;
	unsigned int paramOut_ReceivedSignals_numLinks;
	unsigned int paramOut_OutOfSynchSamples_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixTarget_Block_CImplementation *implState;
	
	/* Block size */
	size_t blockSize;

	/* Samples to process */
	size_t samplesToProcess;


	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MicroBenchFlag_StandardGate *dataOut_Stop;


	/* Data gates sizes */
	size_t dataIn_In_size;
	size_t dataOut_Stop_size;


	/* Data gates factors */
	size_t dataIn_In_factor;
	size_t dataOut_Stop_factor;


	/* Data gates counters */
	size_t dataIn_In_counter;
	size_t dataOut_Stop_counter;


	/* Output data places */
	MicroBenchFlag_StandardGate *dataOut_Stop_place;

	/* Unit profile ID */
	int unitProfileID;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* EarlyAlloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullProd(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessProd(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownProd(MatrixBenchMatrixTarget_SoftwareUnitProd *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessBlockProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processBlockProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullBlockProd(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessBlockProd(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownBlockProd(MatrixBenchMatrixTarget_SoftwareUnit_blockProd *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
