/**
 * File: MatrixBenchMatrixSource_CImplementation.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixSource_CImplementation_h
#define MatrixBenchMatrixSource_CImplementation_h

#include "DSPEElements.h"

#include "MicroBenchFlag_StandardGate.h"
#include "MatrixBenchMatrix_PointerGate.h"
#include "MicroBenchCounter_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"

/* State type definition */
typedef struct MatrixBenchMatrixSource_CImplementation MatrixBenchMatrixSource_CImplementation;

/* State definition */ 
struct MatrixBenchMatrixSource_CImplementation {

	DSPEImplementation implementation;
	

	/* Data gates */
	MicroBenchFlag_StandardGate *dataOut_Start;
	MatrixBenchMatrix_PointerGate *dataOut_Out;

	/* Parameter gates */
	MicroBenchFlag_StandardGate *paramIn_Trigger;
	MicroBenchFlag_StandardGate *paramIn_AutomaticStop;
	MicroBenchCounter_StandardGate *paramIn_SamplesToProcess;
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchSignalsCount_StandardGate *paramOut_SentSignals;


	/* numLinks flags */
	unsigned int dataOut_Start_numLinks;
	unsigned int dataOut_Out_numLinks;
	unsigned int paramIn_Trigger_numLinks;
	unsigned int paramIn_AutomaticStop_numLinks;
	unsigned int paramIn_SamplesToProcess_numLinks;
	unsigned int paramIn_SignalSource_numLinks;
	unsigned int paramIn_ShowInfo_numLinks;
	unsigned int paramOut_SentSignals_numLinks;
};

/* Functional implementation state type definition */
typedef struct MatrixBenchMatrixSource_CImplementation_func MatrixBenchMatrixSource_CImplementation_func;

/* This struct may contain user defined additional state variables for the unit */
struct MatrixBenchMatrixSource_CImplementation_func {
	MatrixBenchMatrixSource_CImplementation parent;
	//Place additional state variables after this line -- SYD-ADDITIONAL-STATE-START
	int trigger;
	int show;
	unsigned long matrixID;
	unsigned long matrixCnt;
	//SYD-ADDITIONAL-STATE-END  -- Place additional state variables before this line

};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* Allocate function */
MatrixBenchMatrixSource_CImplementation* MatrixBenchMatrixSource_CImplementation_allocate(DSPEElement *context);

/* Dispose function */
void MatrixBenchMatrixSource_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixSource_CImplementation *context);

/* Startup function */
void MatrixBenchMatrixSource_CImplementation_startup(MatrixBenchMatrixSource_CImplementation *context);

/* PreProcess function */
void MatrixBenchMatrixSource_CImplementation_preProcess(MatrixBenchMatrixSource_CImplementation *context);


/* Prepare params function */
void MatrixBenchMatrixSource_CImplementation_prepareParams(MatrixBenchMatrixSource_CImplementation *context);

/* Process function */
void MatrixBenchMatrixSource_CImplementation_process(MatrixBenchMatrixSource_CImplementation *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
