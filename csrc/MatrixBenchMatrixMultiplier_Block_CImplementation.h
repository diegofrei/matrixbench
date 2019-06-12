/**
 * File: MatrixBenchMatrixMultiplier_Block_CImplementation.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrixMultiplier_Block_CImplementation_h
#define MatrixBenchMatrixMultiplier_Block_CImplementation_h

#include "DSPEElements.h"

#include "MatrixBenchMatrix_PointerGate.h"

/* BlockOptimization state type definition */
typedef struct MatrixBenchMatrixMultiplier_Block_CImplementation MatrixBenchMatrixMultiplier_Block_CImplementation;

/* State definition */ 
struct MatrixBenchMatrixMultiplier_Block_CImplementation {

	DSPEImplementation implementation;
	
	/* Block size */
	size_t blockSize;


	/* Data gates */
	MatrixBenchMatrix_PointerGate *dataIn_In;
	MatrixBenchMatrix_PointerGate *dataOut_Out;


	/* numLinks flags */
	unsigned int dataIn_In_numLinks;
	unsigned int dataOut_Out_numLinks;
};

/* Functional implementation state type definition */
typedef struct MatrixBenchMatrixMultiplier_Block_CImplementation_func MatrixBenchMatrixMultiplier_Block_CImplementation_func;

/* This struct may contain user defined additional state variables for the unit */
struct MatrixBenchMatrixMultiplier_Block_CImplementation_func {
	MatrixBenchMatrixMultiplier_Block_CImplementation parent;
	//Place additional state variables after this line -- SYD-ADDITIONAL-STATE-START
	//SYD-ADDITIONAL-STATE-END  -- Place additional state variables before this line

};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/* Allocate function */
MatrixBenchMatrixMultiplier_Block_CImplementation* MatrixBenchMatrixMultiplier_Block_CImplementation_allocate(DSPEElement *context);

/* Dispose function */
void MatrixBenchMatrixMultiplier_Block_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixMultiplier_Block_CImplementation *context);

/* Process function */
void MatrixBenchMatrixMultiplier_Block_CImplementation_process(MatrixBenchMatrixMultiplier_Block_CImplementation *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
