/**
 * File: MatrixBenchMatrixSource_SoftwareUnit.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixSource_SoftwareUnit_h
#define MatrixBenchMatrixSource_SoftwareUnit_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"

#include "MatrixBenchMatrixSource_CImplementation.h"
#include "MatrixBenchMatrixSource_Block_CImplementation.h"
#include "MicroBenchFlag_StandardGate.h"
#include "MatrixBenchMatrix_PointerGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixSource_SoftwareUnit MatrixBenchMatrixSource_SoftwareUnit;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixSource_SoftwareUnit {
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
typedef struct MatrixBenchMatrixSource_SoftwareUnit_block MatrixBenchMatrixSource_SoftwareUnit_block;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixSource_SoftwareUnit_block {
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
void MatrixBenchMatrixSource_SoftwareUnit_earlyAlloc(MatrixBenchMatrixSource_SoftwareUnit *context);

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_alloc(MatrixBenchMatrixSource_SoftwareUnit *context);

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnect(MatrixBenchMatrixSource_SoftwareUnit *context);

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connect(MatrixBenchMatrixSource_SoftwareUnit *context);

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startup(MatrixBenchMatrixSource_SoftwareUnit *context);

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcess(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_process(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPull(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcess(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_reset(MatrixBenchMatrixSource_SoftwareUnit *context);

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdown(MatrixBenchMatrixSource_SoftwareUnit *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessBlock(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processBlock(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullBlock(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessBlock(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownBlock(MatrixBenchMatrixSource_SoftwareUnit_block *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
