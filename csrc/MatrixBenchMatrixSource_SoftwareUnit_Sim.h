/**
 * File: MatrixBenchMatrixSource_SoftwareUnit.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixSource_SoftwareUnit_Sim_h
#define MatrixBenchMatrixSource_SoftwareUnit_Sim_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"

#include "MatrixBenchMatrixSource_CImplementation.h"
#include "MatrixBenchMatrixSource_Block_CImplementation.h"
#include "MicroBenchFlag_StandardGate.h"
#include "MatrixBenchMatrix_PointerGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixSource_SoftwareUnitSim MatrixBenchMatrixSource_SoftwareUnitSim;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixSource_SoftwareUnitSim {
	DSPEUnit unit;
	

	/* Parameter gates */
	MicroBenchFlag_StandardGate *paramIn_Trigger;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess;
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals;

	/* Output parameters places */
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals_place;

	/* Gates numLinks */
	unsigned int dataOut_Start_numLinks;
	unsigned int dataOut_Out_numLinks;
	unsigned int paramIn_Trigger_numLinks;
	unsigned int paramIn_AutomaticStop_numLinks;
	unsigned int paramIn_SamplesToProcess_numLinks;
	unsigned int paramIn_SignalSource_numLinks;
	unsigned int paramIn_ShowInfo_numLinks;
	unsigned int paramOut_SentSignals_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixSource_CImplementation *implState;
	

	/* Data gates */
	MicroBenchFlag_StandardGate *dataOut_Start;
	MatrixBenchMatrix_PointerGate *dataOut_Out;


	/* Output data places */
	MicroBenchFlag_StandardGate *dataOut_Start_place;
	MatrixBenchMatrix_PointerGate *dataOut_Out_place;


	/* Output data places anchors */
	MatrixBenchMatrix_PointerGate *dataOut_Out_placeAnchor;
	/* Unit profile ID */
	int unitProfileID;
};

// BLOCK UNIT
/* Block SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixSource_SoftwareUnit_blockSim MatrixBenchMatrixSource_SoftwareUnit_blockSim;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixSource_SoftwareUnit_blockSim {
	DSPEUnit unit;
	

	/* Parameter gates */
	MicroBenchFlag_StandardGate *paramIn_Trigger;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess;
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals;

	/* Output parameters places */
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals_place;

	/* Gates numLinks */
	unsigned int dataOut_Start_numLinks;
	unsigned int dataOut_Out_numLinks;
	unsigned int paramIn_Trigger_numLinks;
	unsigned int paramIn_AutomaticStop_numLinks;
	unsigned int paramIn_SamplesToProcess_numLinks;
	unsigned int paramIn_SignalSource_numLinks;
	unsigned int paramIn_ShowInfo_numLinks;
	unsigned int paramOut_SentSignals_numLinks;
	/* unit ID */
	char *ID;
	/* Base implementation state */
	MatrixBenchMatrixSource_Block_CImplementation *implState;
	
	/* Block size */
	size_t blockSize;

	/* Samples to process */
	size_t samplesToProcess;


	/* Data gates */
	MicroBenchFlag_StandardGate *dataOut_Start;
	MatrixBenchMatrix_PointerGate *dataOut_Out;


	/* Data gates sizes */
	size_t dataOut_Start_size;
	size_t dataOut_Out_size;


	/* Data gates factors */
	size_t dataOut_Start_factor;
	size_t dataOut_Out_factor;


	/* Data gates counters */
	size_t dataOut_Start_counter;
	size_t dataOut_Out_counter;


	/* Output data places */
	MicroBenchFlag_StandardGate *dataOut_Start_place;
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
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullSim(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessSim(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownSim(MatrixBenchMatrixSource_SoftwareUnitSim *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessBlockSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processBlockSim(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullBlockSim(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessBlockSim(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownBlockSim(MatrixBenchMatrixSource_SoftwareUnit_blockSim *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
