/**
 * File: MatrixBenchMatrixSource_CImplementation.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "InfoManager.h"
#include "ProfileManager.h"
#include "MatrixBenchMatrixSource_CImplementation.h"
#include "MatrixBenchMatrix_Requirement.h"

#include "MemoryManager.h"

/**
 * Convenience defines to access unit state variables.
 */
/* Input ParameterGates Shortcuts */
#define pIn_Trigger (*context->paramIn_Trigger)
#define pIn_AutomaticStop (*context->paramIn_AutomaticStop)
#define pIn_SamplesToProcess (*context->paramIn_SamplesToProcess)
#define pIn_SignalSource (*context->paramIn_SignalSource)
#define pIn_ShowInfo (*context->paramIn_ShowInfo)

/* Output ParameterGates Shortcuts */
#define pOut_SentSignals (*context->paramOut_SentSignals)

/* Output DataGates Shortcuts */
#define dOut_Start (*context->dataOut_Start)
#define dOut_Out (*context->dataOut_Out)

/* numLinks shortcuts */
#define dOut_Start_numLinks context->dataOut_Start_numLinks
#define dOut_Out_numLinks context->dataOut_Out_numLinks
#define pIn_Trigger_numLinks context->paramIn_Trigger_numLinks
#define pIn_AutomaticStop_numLinks context->paramIn_AutomaticStop_numLinks
#define pIn_SamplesToProcess_numLinks context->paramIn_SamplesToProcess_numLinks
#define pIn_SignalSource_numLinks context->paramIn_SignalSource_numLinks
#define pIn_ShowInfo_numLinks context->paramIn_ShowInfo_numLinks
#define pOut_SentSignals_numLinks context->paramOut_SentSignals_numLinks

/* AdditionalStateVariables shortcuts */
#define addS_trigger ((MatrixBenchMatrixSource_CImplementation_func*) context)->trigger
#define addS_show ((MatrixBenchMatrixSource_CImplementation_func*) context)->show
#define addS_matrixID ((MatrixBenchMatrixSource_CImplementation_func*) context)->matrixID
#define addS_matrixCnt ((MatrixBenchMatrixSource_CImplementation_func*) context)->matrixCnt

/* AdditionalStateVariables default values */
#define ADDS_TRIGGER_DEFAULTVALUE 0
#define ADDS_SHOW_DEFAULTVALUE 0
#define ADDS_MATRIXID_DEFAULTVALUE 0
#define ADDS_MATRIXCNT_DEFAULTVALUE 0

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
MatrixBenchMatrixSource_CImplementation* MatrixBenchMatrixSource_CImplementation_allocate(DSPEElement *context) {
	/* Allocating functional structure but returning parent struct pointer */
	return (MatrixBenchMatrixSource_CImplementation*) memoryManager_allocate(context, sizeof(MatrixBenchMatrixSource_CImplementation_func));
}

/* Dispose function */
void MatrixBenchMatrixSource_CImplementation_dispose(DSPEElement *element, MatrixBenchMatrixSource_CImplementation *context) {
	memorySupport_dispose(context);
}

/**
 * Startup algorithm. Unit initialization should take place here.
 * This function will be called ONCE at application startup.
 */
void MatrixBenchMatrixSource_CImplementation_startup(MatrixBenchMatrixSource_CImplementation *context) {
//Place implementation after this line -- SYD-STARTUP-START
	srand(time(NULL));
	info_writeInfo("MatrixSize : %d", MATRIX_SIZE);
//SYD-STARTUP-END -- Place implementation before this line
}

/**
 * PreProcess algorithm. Process phase initialization should take place here.
 * This function will be called ONCE before the process phase.
 */
void MatrixBenchMatrixSource_CImplementation_preProcess(MatrixBenchMatrixSource_CImplementation *context) {
//Place implementation after this line -- SYD-PREPROCESS-START
	addS_trigger = pIn_SignalSource;
	pOut_SentSignals = 0;
//SYD-PREPROCESS-END -- Place implementation before this line
}

/**
 * PrepareParams algorithm. Calculations for parameters should take place here.
 * This function will be called before each process cycle.
 */
void MatrixBenchMatrixSource_CImplementation_prepareParams(MatrixBenchMatrixSource_CImplementation *context) {
//Place implementation after this line -- SYD-PREPAREPARAMS-START
	if (pIn_SignalSource && pIn_Trigger)
		addS_trigger = 1;
//SYD-PREPAREPARAMS-END -- Place implementation before this line 
}

/**
 * Process algorithm. What the unit really does should take place here.
 * This function will be called at each process cycle.
 */
void MatrixBenchMatrixSource_CImplementation_process(MatrixBenchMatrixSource_CImplementation *context) {
//Place implementation after this line -- SYD-PROCESS-START
	int i;
	int j;
	double determinant = 1.0;

	if (pIn_AutomaticStop && addS_matrixCnt >= pIn_SamplesToProcess)
		// This should never happen!
		return;
	addS_matrixCnt++;

	if (addS_trigger && !profile_isSignalSent()) {
		// Used to compute samples latency between source and destination
		dOut_Start = 1;
		if (!profile_isSignalSent())
			profile_sendSignal();
		pOut_SentSignals++;
		addS_trigger = 0;

		if (pIn_ShowInfo)
			addS_show = 1;

		// Set signal flag
		dOut_Out[MATRIX_SIZE * MATRIX_SIZE + 1] = 1.0;
	} else {
		dOut_Start = 0;
		// Unset signal flag
		dOut_Out[MATRIX_SIZE * MATRIX_SIZE + 1] = 0.0;
	}

	// Generate matrix values (triangular matrix)
	for (i = 0; i < MATRIX_SIZE; i++)
		for (j = 0; j < MATRIX_SIZE; j++)
			dOut_Out[i * MATRIX_SIZE + j] = j > i ? 0.0 : ((double) rand() / ((double) RAND_MAX + (double) 1));

	// Add matrix ID
	addS_matrixID++;
	if (addS_matrixID > MAX_MATRIX_ID)
		addS_matrixID = 0;
	dOut_Out[MATRIX_SIZE * MATRIX_SIZE] = addS_matrixID;

	// Show matrix determinant if required
	if (addS_show) {
		// Determinant
		for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i += MATRIX_SIZE + 1) {
			if (dOut_Out[i] == 0) {
				determinant = 0.0;
				info_writeInfo("SOURCE ERROR: matrix diagonal element equals to 0 at position (%d, %d)", i / MATRIX_SIZE, i / MATRIX_SIZE);
				break;
			}
			determinant *= dOut_Out[i];
		}
		info_writeInfo("SOURCE:\t%.12e", determinant);
		addS_show = 0;
	}
//SYD-PROCESS-END -- Place implementation before this line 
}

/* Input ParameterGates Shortcuts */
#undef pIn_Trigger
#undef pIn_AutomaticStop
#undef pIn_SamplesToProcess
#undef pIn_SignalSource
#undef pIn_ShowInfo

/* Output ParameterGates Shortcuts */
#undef pOut_SentSignals

/* Output DataGates Shortcuts */
#undef dOut_Start
#undef dOut_Out

/* numLinks shortcuts */
#undef dOut_Start_numLinks
#undef dOut_Out_numLinks
#undef pIn_Trigger_numLinks
#undef pIn_AutomaticStop_numLinks
#undef pIn_SamplesToProcess_numLinks
#undef pIn_SignalSource_numLinks
#undef pIn_ShowInfo_numLinks
#undef pOut_SentSignals_numLinks

/* AdditionalStateVariables shortcuts */
#undef addS_trigger
#undef addS_show
#undef addS_matrixID
#undef addS_matrixCnt

#undef ADDS_TRIGGER_DEFAULTVALUE
#undef ADDS_SHOW_DEFAULTVALUE
#undef ADDS_MATRIXID_DEFAULTVALUE
#undef ADDS_MATRIXCNT_DEFAULTVALUE

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

