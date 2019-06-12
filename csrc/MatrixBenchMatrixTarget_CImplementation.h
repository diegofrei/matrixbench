/**
 * File: MatrixBenchMatrixTarget_CImplementation.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MatrixBenchMatrixTarget_CImplementation_h
#define MatrixBenchMatrixTarget_CImplementation_h

#include "DSPEElements.h"

#include "MatrixBenchMatrix_PointerGate.h"
#include "MicroBenchFlag_StandardGate.h"
#include "MicroBenchSignalsCount_StandardGate.h"
#include "MicroBenchCounter_StandardGate.h"

/* State type definition */
typedef struct MatrixBenchMatrixTarget_CImplementation MatrixBenchMatrixTarget_CImplementation;

/* State definition */ 
struct MatrixBenchMatrixTarget_CImplementation {

	DSPEImplementation implementation;
	

	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MicroBenchFlag_StandardGate *dataOut_Stop;

	/* Parameter gates */
	MicroBenchFlag_StandardGate *paramIn_SignalSource;
	MicroBenchFlag_StandardGate *paramIn_ShowInfo;
	MicroBenchSignalsCount_StandardGate *paramOut_ReceivedSignals;
	MicroBenchCounter_StandardGate *paramOut_OutOfSynchSamples;


	/* numLinks flags */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Stop_numLinks;
	unsigned int paramIn_SignalSource_numLinks;
	unsigned int paramIn_ShowInfo_numLinks;
	unsigned int paramOut_ReceivedSignals_numLinks;
	unsigned int paramOut_OutOfSynchSamples_numLinks;
};

/* Functional implementation state type definition */
typedef struct MatrixBenchMatrixTarget_CImplementation_func MatrixBenchMatrixTarget_CImplementation_func;

/* This struct may contain user defined additional state variables for the unit */
struct MatrixBenchMatrixTarget_CImplementation_func {
	MatrixBenchMatrixTarget_CImplementation parent;
	//Place additional state variables after this line -- SYD-ADDITIONAL-STATE-START
	int show;
	unsigned long matrixCounter;
	//SYD-ADDITIONAL-STATE-END  -- Place additional state variables before this line

};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* Allocate function */
MatrixBenchMatrixTarget_CImplementation* MatrixBenchMatrixTarget_CImplementation_allocate(DSPEElement *context);

/* Dispose function */
void MatrixBenchMatrixTarget_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixTarget_CImplementation *context);

/* PreProcess function */
void MatrixBenchMatrixTarget_CImplementation_preProcess(MatrixBenchMatrixTarget_CImplementation *context);

/* Process function */
void MatrixBenchMatrixTarget_CImplementation_process(MatrixBenchMatrixTarget_CImplementation *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
