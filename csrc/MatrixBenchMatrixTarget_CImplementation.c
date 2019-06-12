/**
 * File: MatrixBenchMatrixTarget_CImplementation.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "InfoManager.h"
#include "ProfileManager.h"
#include "MatrixBenchMatrixTarget_CImplementation.h"
#include "MatrixBenchMatrix_Requirement.h"

#include "MemoryManager.h"

/**
 * Convenience defines to access unit state variables.
 */
/* Input ParameterGates Shortcuts */
#define pIn_SignalSource (*context->paramIn_SignalSource)
#define pIn_ShowInfo (*context->paramIn_ShowInfo)

/* Output ParameterGates Shortcuts */
#define pOut_ReceivedSignals (*context->paramOut_ReceivedSignals)
#define pOut_OutOfSynchSamples (*context->paramOut_OutOfSynchSamples)

/* Input DataGates Shortcuts */
#define dIn_In (*context->dataIn_In)

/* Output DataGates Shortcuts */
#define dOut_Stop (*context->dataOut_Stop)

/* numLinks shortcuts */
#define dIn_In_numLinks context->dataIn_In_numLinks
#define dOut_Stop_numLinks context->dataOut_Stop_numLinks
#define pIn_SignalSource_numLinks context->paramIn_SignalSource_numLinks
#define pIn_ShowInfo_numLinks context->paramIn_ShowInfo_numLinks
#define pOut_ReceivedSignals_numLinks context->paramOut_ReceivedSignals_numLinks
#define pOut_OutOfSynchSamples_numLinks context->paramOut_OutOfSynchSamples_numLinks

/* AdditionalStateVariables shortcuts */
#define addS_show ((MatrixBenchMatrixTarget_CImplementation_func*) context)->show
#define addS_matrixCounter ((MatrixBenchMatrixTarget_CImplementation_func*) context)->matrixCounter

/* AdditionalStateVariables default values */
#define ADDS_SHOW_DEFAULTVALUE 0
#define ADDS_MATRIXCOUNTER_DEFAULTVALUE 0

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

/* ProfileManager function shortcuts */
#define profile_showProfileInfo(id) profileManager_showProfileInfo((DSPEElement*) context, id)

#define profile_incrementSamplesCount(increment) profileManager_incrementSamplesCount((DSPEElement*) context, increment)
#define profile_getSamplesCount() profileManager_getSamplesCount((DSPEElement*) context)
#define profile_getElapsedTime() profileManager_getElapsedTime((DSPEElement*) context)
#define profile_getThroughput() profileManager_getThroughput((DSPEElement*) context)

#define profile_captureStartTime(id) profileManager_captureStartTime((DSPEElement*) context, id)
#define profile_captureEndTime(id) profileManager_captureEndTime((DSPEElement*) context, id)
#define profile_getMeanProcessTime(id) profileManager_getMeanProcessTime((DSPEElement*) context, id)
#define profile_getMinProcessTime(id) profileManager_getMinProcessTime((DSPEElement*) context, id)
#define profile_getMaxProcessTime(id) profileManager_getMaxProcessTime((DSPEElement*) context, id)
#define profile_getTotalProcessTime(id) profileManager_getTotalProcessTime((DSPEElement*) context, id)

#define profile_sendSignal() profileManager_sendSignal((DSPEElement*) context)
#define profile_receiveSignal() profileManager_receiveSignal((DSPEElement*) context)
#define profile_isSignalSent() profileManager_isSignalSent((DSPEElement*) context)
#define profile_incrementLag(increment) profileManager_incrementLag((DSPEElement*) context, increment)
#define profile_getMeanLag() profileManager_getMeanLag((DSPEElement*) context)
#define profile_getMinLag() profileManager_getMinLag((DSPEElement*) context)
#define profile_getMaxLag() profileManager_getMaxLag((DSPEElement*) context)
#define profile_getMeanLatency() profileManager_getMeanLatency((DSPEElement*) context)
#define profile_getMinLatency() profileManager_getMinLatency((DSPEElement*) context)
#define profile_getMaxLatency() profileManager_getMaxLatency((DSPEElement*) context)

#define profile_receiveData() profileManager_receiveData((DSPEElement*) context)

/* Allocate function */
MatrixBenchMatrixTarget_CImplementation* MatrixBenchMatrixTarget_CImplementation_allocate(DSPEElement *context) {
	/* Allocating functional structure but returning parent struct pointer */
	return (MatrixBenchMatrixTarget_CImplementation*) memoryManager_allocate(context, sizeof(MatrixBenchMatrixTarget_CImplementation_func));
}

/* Dispose function */
void MatrixBenchMatrixTarget_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixTarget_CImplementation *context) {
	memorySupport_dispose(context);
}

/**
 * PreProcess algorithm. Process phase initialization should take place here.
 * This function will be called ONCE before the process phase.
 */
void MatrixBenchMatrixTarget_CImplementation_preProcess(MatrixBenchMatrixTarget_CImplementation *context) {
//Place implementation after this line -- SYD-PREPROCESS-START
	pOut_ReceivedSignals = 0;
	pOut_OutOfSynchSamples = 0;
//SYD-PREPROCESS-END -- Place implementation before this line
}

/**
 * Process algorithm. What the unit really does should take place here.
 * This function will be called at each process cycle.
 */
void MatrixBenchMatrixTarget_CImplementation_process(MatrixBenchMatrixTarget_CImplementation *context) {
//Place implementation after this line -- SYD-PROCESS-START
	int i;
	double determinant = 1.0;

	if (pIn_SignalSource && profile_isSignalSent())
		// Increment lag counter
		profile_incrementLag(1);

	if (dIn_In[MATRIX_SIZE * MATRIX_SIZE + 1]) {
		// Signal matrix, compute lag and latency
		dOut_Stop = 1;
		profile_receiveSignal();
		pOut_ReceivedSignals++;
		if (pIn_ShowInfo)
			addS_show = 1;
	} else
		dOut_Stop = 0;

	// Show matrix determinant if required
	if (addS_show) {
		// Determinant
		for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i += MATRIX_SIZE + 1) {
			if (dIn_In[i] == 0) {
				determinant = 0.0;
				info_writeInfo("TARGET ERROR: matrix diagonal element equals to 0 at position (%d, %d)", i / MATRIX_SIZE, i / MATRIX_SIZE);
				break;
			}
			determinant *= dIn_In[i];
		}
		info_writeInfo("TARGET:\t%.12e", determinant);
		addS_show = 0;
	}

	// Check if matrix is out of synch
	addS_matrixCounter++;
	if (addS_matrixCounter > MAX_MATRIX_ID)
		addS_matrixCounter = 0;
	if (dIn_In[MATRIX_SIZE * MATRIX_SIZE] != addS_matrixCounter)
		pOut_OutOfSynchSamples++;
//SYD-PROCESS-END -- Place implementation before this line 
}

/* Input ParameterGates Shortcuts */
#undef pIn_SignalSource
#undef pIn_ShowInfo

/* Output ParameterGates Shortcuts */
#undef pOut_ReceivedSignals
#undef pOut_OutOfSynchSamples

/* Input DataGates Shortcuts */
#undef dIn_In

/* Output DataGates Shortcuts */
#undef dOut_Stop

/* numLinks shortcuts */
#undef dIn_In_numLinks
#undef dOut_Stop_numLinks
#undef pIn_SignalSource_numLinks
#undef pIn_ShowInfo_numLinks
#undef pOut_ReceivedSignals_numLinks
#undef pOut_OutOfSynchSamples_numLinks

/* AdditionalStateVariables shortcuts */
#undef addS_show
#undef addS_matrixCounter

#undef ADDS_SHOW_DEFAULTVALUE
#undef ADDS_MATRIXCOUNTER_DEFAULTVALUE

/* InfoManager function shortcuts */
#undef info_writeInfo
#undef info_collectAndWriteInfo
#undef info_nCollectAndWriteInfo
#undef info_logInfo
#undef info_collectAndLogInfo
#undef info_nCollectAndLogInfo

/* ProfileManager function shortcuts */
#undef profile_showProfileInfo

#undef profile_incrementSamplesCount
#undef profile_getSamplesCount
#undef profile_getElapsedTime
#undef profile_getThroughput

#undef profile_captureStartTime
#undef profile_captureEndTime
#undef profile_getMeanProcessTime
#undef profile_getMinProcessTime
#undef profile_getMaxProcessTime
#undef profile_getTotalProcessTime

#undef profile_sendSignal
#undef profile_receiveSignal
#undef profile_isSignalSent
#undef profile_incrementLag
#undef profile_getMeanLag
#undef profile_getMinLag
#undef profile_getMaxLag
#undef profile_getMeanLatency
#undef profile_getMinLatency
#undef profile_getMaxLatency

