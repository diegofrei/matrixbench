/**
 * File: MatrixBenchMatrixTarget_SoftwareUnit.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixTarget_SoftwareUnit_h
#define MatrixBenchMatrixTarget_SoftwareUnit_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"

#include "MatrixBenchMatrixTarget_CImplementation.h"
#include "MatrixBenchMatrixTarget_Block_CImplementation.h"
#include "MatrixBenchMatrix_PointerGate.h"
#include "MicroBenchFlag_StandardGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixTarget_SoftwareUnit MatrixBenchMatrixTarget_SoftwareUnit;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixTarget_SoftwareUnit {
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
	MatrixBenchMatrixTarget_CImplementation *implState;
	

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
typedef struct MatrixBenchMatrixTarget_SoftwareUnit_block MatrixBenchMatrixTarget_SoftwareUnit_block;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixTarget_SoftwareUnit_block {
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
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAlloc(MatrixBenchMatrixTarget_SoftwareUnit *context);

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_alloc(MatrixBenchMatrixTarget_SoftwareUnit *context);

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnect(MatrixBenchMatrixTarget_SoftwareUnit *context);

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connect(MatrixBenchMatrixTarget_SoftwareUnit *context);

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startup(MatrixBenchMatrixTarget_SoftwareUnit *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcess(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_process(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPull(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcess(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_reset(MatrixBenchMatrixTarget_SoftwareUnit *context);

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdown(MatrixBenchMatrixTarget_SoftwareUnit *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessBlock(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processBlock(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullBlock(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessBlock(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownBlock(MatrixBenchMatrixTarget_SoftwareUnit_block *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
