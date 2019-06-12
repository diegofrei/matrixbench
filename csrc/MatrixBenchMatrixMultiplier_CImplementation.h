/**
 * File: MatrixBenchMatrixMultiplier_CImplementation.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MatrixBenchMatrixMultiplier_CImplementation_h
#define MatrixBenchMatrixMultiplier_CImplementation_h

#include "DSPEElements.h"

#include "MatrixBenchMatrix_PointerGate.h"

/* State type definition */
typedef struct MatrixBenchMatrixMultiplier_CImplementation MatrixBenchMatrixMultiplier_CImplementation;

/* State definition */ 
struct MatrixBenchMatrixMultiplier_CImplementation {

	DSPEImplementation implementation;
	

	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MatrixBenchMatrix_PointerGate *dataOut_Out;


	/* numLinks flags */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Out_numLinks;
};

/* Functional implementation state type definition */
typedef struct MatrixBenchMatrixMultiplier_CImplementation_func MatrixBenchMatrixMultiplier_CImplementation_func;

/* This struct may contain user defined additional state variables for the unit */
struct MatrixBenchMatrixMultiplier_CImplementation_func {
	MatrixBenchMatrixMultiplier_CImplementation parent;
	//Place additional state variables after this line -- SYD-ADDITIONAL-STATE-START
	//SYD-ADDITIONAL-STATE-END  -- Place additional state variables before this line

};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* Allocate function */
MatrixBenchMatrixMultiplier_CImplementation* MatrixBenchMatrixMultiplier_CImplementation_allocate(DSPEElement *context);

/* Dispose function */
void MatrixBenchMatrixMultiplier_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixMultiplier_CImplementation *context);

/* Process function */
void MatrixBenchMatrixMultiplier_CImplementation_process(MatrixBenchMatrixMultiplier_CImplementation *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
