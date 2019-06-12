/**
 * File: MatrixBenchMatrixTarget_SoftwareUnit.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MatrixBenchMatrixTarget_SoftwareUnit_Sim_h
#define MatrixBenchMatrixTarget_SoftwareUnit_Sim_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"

#include "MatrixBenchMatrixTarget_CImplementation.h"
#include "MatrixBenchMatrixTarget_Block_CImplementation.h"
#include "MatrixBenchMatrix_PointerGate.h"
#include "MicroBenchFlag_StandardGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixTarget_SoftwareUnitSim MatrixBenchMatrixTarget_SoftwareUnitSim;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixTarget_SoftwareUnitSim {
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
typedef struct MatrixBenchMatrixTarget_SoftwareUnit_blockSim MatrixBenchMatrixTarget_SoftwareUnit_blockSim;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixTarget_SoftwareUnit_blockSim {
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
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullSim(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessSim(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownSim(MatrixBenchMatrixTarget_SoftwareUnitSim *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyAllocBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

/* Alloc function */
void MatrixBenchMatrixTarget_SoftwareUnit_allocBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

/* EarlyConnect function */
void MatrixBenchMatrixTarget_SoftwareUnit_earlyConnectBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

/* Connect function */
void MatrixBenchMatrixTarget_SoftwareUnit_connectBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

/* Startup function */
void MatrixBenchMatrixTarget_SoftwareUnit_startupBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_preProcessBlockSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processBlockSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixTarget_SoftwareUnit_processAutoPullBlockSim(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixTarget_SoftwareUnit_postProcessBlockSim(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixTarget_SoftwareUnit_resetBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

/* Shutdown function */
void MatrixBenchMatrixTarget_SoftwareUnit_shutdownBlockSim(MatrixBenchMatrixTarget_SoftwareUnit_blockSim *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
