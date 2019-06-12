/**
 * File: MatrixBenchMatrixSource_SoftwareUnit.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixSource_SoftwareUnit_Prod_h
#define MatrixBenchMatrixSource_SoftwareUnit_Prod_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"

#include "MatrixBenchMatrixSource_Block_CImplementation.h"
#include "MatrixBenchMatrixSource_Block_CImplementation.h"
#include "MicroBenchFlag_StandardGate.h"
#include "MatrixBenchMatrix_PointerGate.h"

/* Real SoftwareUnit state type definition */
typedef struct MatrixBenchMatrixSource_SoftwareUnitProd MatrixBenchMatrixSource_SoftwareUnitProd;

/* Real SoftwareUnit state definition */
struct MatrixBenchMatrixSource_SoftwareUnitProd {
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
typedef struct MatrixBenchMatrixSource_SoftwareUnit_blockProd MatrixBenchMatrixSource_SoftwareUnit_blockProd;

/* Block SoftwareUnit state definition */
struct MatrixBenchMatrixSource_SoftwareUnit_blockProd {
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
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullProd(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessProd(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownProd(MatrixBenchMatrixSource_SoftwareUnitProd *context);

/******************************************************************************
 * BLOCK functions
 ******************************************************************************/

/* EarlyAlloc function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyAllocBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

/* Alloc function */
void MatrixBenchMatrixSource_SoftwareUnit_allocBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

/* EarlyConnect function */
void MatrixBenchMatrixSource_SoftwareUnit_earlyConnectBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

/* Connect function */
void MatrixBenchMatrixSource_SoftwareUnit_connectBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

/* Startup function */
void MatrixBenchMatrixSource_SoftwareUnit_startupBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

/* PreProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_preProcessBlockProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processBlockProd(DSPEComponent *component);

/* Process function */
void MatrixBenchMatrixSource_SoftwareUnit_processAutoPullBlockProd(DSPEComponent *component);

/* PostProcess function */
void MatrixBenchMatrixSource_SoftwareUnit_postProcessBlockProd(DSPEComponent *component);

/* Reset function */
void MatrixBenchMatrixSource_SoftwareUnit_resetBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

/* Shutdown function */
void MatrixBenchMatrixSource_SoftwareUnit_shutdownBlockProd(MatrixBenchMatrixSource_SoftwareUnit_blockProd *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
