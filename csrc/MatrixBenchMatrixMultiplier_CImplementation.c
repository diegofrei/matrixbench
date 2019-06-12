/**
 * File: MatrixBenchMatrixMultiplier_CImplementation.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "InfoManager.h"
#include "MatrixBenchMatrixMultiplier_CImplementation.h"
#include "MatrixBenchMatrix_Requirement.h"

#include "MemoryManager.h"

/**
 * Convenience defines to access unit state variables.
 */
/* Input DataGates Shortcuts */
#define dIn_In (*context->dataIn_In)

/* Output DataGates Shortcuts */
#define dOut_Out (*context->dataOut_Out)

/* numLinks shortcuts */
#define dIn_In_numLinks context->dataIn_In_numLinks
#define dOut_Out_numLinks context->dataOut_Out_numLinks

/* Common event shortcuts */
/* InfoManager function shortcuts */
#if defined(INFOMANAGER_BYPASS_CONSOLE) && (INFOMANAGER_BYPASS_CONSOLE == 1)
#define info_writeInfo(info, ...)
#define info_collectAndWriteInfo(id)
#define info_nCollectAndWriteInfo(id, increment)
#else
#define info_writeInfo(info, ...) infoManager_writeInfo((DSPEElement*) context, info , ##__VA_ARGS__)
#define info_collectAndWriteInfo(id) infoManager_collectAndWriteInfo((DSPEElement*) context, id, 1)
#define info_nCollectAndWriteInfo(id, increment) infoManager_collectAndWriteInfo((DSPEElement*) context, id, increment)
#endif
#if defined(INFOMANAGER_BYPASS_LOG) && (INFOMANAGER_BYPASS_LOG == 1)
#define info_logInfo(info, ...)
#define info_collectAndLogInfo(id)
#define info_nCollectAndLogInfo(id, increment)
#else
#define info_logInfo(info, ...) infoManager_logInfo((DSPEElement*) context, info , ##__VA_ARGS__)
#define info_collectAndLogInfo(id) infoManager_collectAndLogInfo((DSPEElement*) context, id, 1)
#define info_nCollectAndLogInfo(id, increment) infoManager_collectAndLogInfo((DSPEElement*) context, id, increment)
#endif

/* Allocate function */
MatrixBenchMatrixMultiplier_CImplementation* MatrixBenchMatrixMultiplier_CImplementation_allocate(DSPEElement *context) {
	/* Allocating functional structure but returning parent struct pointer */
	return (MatrixBenchMatrixMultiplier_CImplementation*) memoryManager_allocate(context, sizeof(MatrixBenchMatrixMultiplier_CImplementation_func));
}

/* Dispose function */
void MatrixBenchMatrixMultiplier_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixMultiplier_CImplementation *context) {
	memorySupport_dispose(context);
}

/**
 * Process algorithm. What the unit really does should take place here.
 * This function will be called at each process cycle.
 */
void MatrixBenchMatrixMultiplier_CImplementation_process(MatrixBenchMatrixMultiplier_CImplementation *context) {
//Place implementation after this line -- SYD-PROCESS-START
	int i = 0;
	int j = 0;
	int k = 0;

	// Matrix multiplication
	for(i = 0; i < MATRIX_SIZE; i++)
		for( j = 0; j < MATRIX_SIZE; j++) {
			dOut_Out[i * MATRIX_SIZE + j] = 0.0;
			for( k = 0; k < MATRIX_SIZE; k++)
				dOut_Out[i * MATRIX_SIZE + j] +=  dIn_In[i * MATRIX_SIZE + k] * dIn_In[k * MATRIX_SIZE + j];
		}

	// Copy matrix ID
	dOut_Out[MATRIX_SIZE * MATRIX_SIZE] = dIn_In[MATRIX_SIZE * MATRIX_SIZE];
	// Copy signal flag
	dOut_Out[MATRIX_SIZE * MATRIX_SIZE + 1] = dIn_In[MATRIX_SIZE * MATRIX_SIZE + 1];
//SYD-PROCESS-END -- Place implementation before this line 
}

/* Input DataGates Shortcuts */
#undef dIn_In

/* Output DataGates Shortcuts */
#undef dOut_Out

/* numLinks shortcuts */
#undef dIn_In_numLinks
#undef dOut_Out_numLinks

/* InfoManager function shortcuts */
#undef info_writeInfo
#undef info_collectAndWriteInfo
#undef info_nCollectAndWriteInfo
#undef info_logInfo
#undef info_collectAndLogInfo
#undef info_nCollectAndLogInfo

