/**
 * File: MicroBenchEvaluator_Block_CImplementation.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "InfoManager.h"
#include "EngineManager.h"
#include "ProfileManager.h"
#include "MicroBenchEvaluator_Block_CImplementation.h"
#include "MemoryManager.h"
/**
 * Convenience defines to access unit state variables.
 */
#define blockSize context->blockSize

#define LOOPVAR_TYPE size_t

/* Input ParameterGates Shortcuts */
#define pIn_SignalDelay (*context->paramIn_SignalDelay)
#define pIn_AutomaticStop (*context->paramIn_AutomaticStop)
#define pIn_SamplesToProcess (*context->paramIn_SamplesToProcess)

/* Output ParameterGates Shortcuts */
#define pOut_SamplesCount (*context->paramOut_SamplesCount)
#define pOut_ElapsedTime (*context->paramOut_ElapsedTime)
#define pOut_Throughput (*context->paramOut_Throughput)
#define pOut_Min_L (*context->paramOut_Min_L)
#define pOut_Mean_L (*context->paramOut_Mean_L)
#define pOut_Max_L (*context->paramOut_Max_L)
#define pOut_Min_Lag (*context->paramOut_Min_Lag)
#define pOut_Mean_Lag (*context->paramOut_Mean_Lag)
#define pOut_Max_Lag (*context->paramOut_Max_Lag)
#define pOut_Trigger (*context->paramOut_Trigger)

/* Input DataGates Shortcuts */
#define dIn_Start (*context->dataIn_Start)
#define dIn_Start_block (context->dataIn_Start)
#define dIn_Stop (*context->dataIn_Stop)
#define dIn_Stop_block (context->dataIn_Stop)

/* numLinks shortcuts */
#define dIn_Start_numLinks context->dataIn_Start_numLinks
#define dIn_Stop_numLinks context->dataIn_Stop_numLinks
#define pIn_SignalDelay_numLinks context->paramIn_SignalDelay_numLinks
#define pIn_AutomaticStop_numLinks context->paramIn_AutomaticStop_numLinks
#define pIn_SamplesToProcess_numLinks context->paramIn_SamplesToProcess_numLinks
#define pOut_SamplesCount_numLinks context->paramOut_SamplesCount_numLinks
#define pOut_ElapsedTime_numLinks context->paramOut_ElapsedTime_numLinks
#define pOut_Throughput_numLinks context->paramOut_Throughput_numLinks
#define pOut_Min_L_numLinks context->paramOut_Min_L_numLinks
#define pOut_Mean_L_numLinks context->paramOut_Mean_L_numLinks
#define pOut_Max_L_numLinks context->paramOut_Max_L_numLinks
#define pOut_Min_Lag_numLinks context->paramOut_Min_Lag_numLinks
#define pOut_Mean_Lag_numLinks context->paramOut_Mean_Lag_numLinks
#define pOut_Max_Lag_numLinks context->paramOut_Max_Lag_numLinks
#define pOut_Trigger_numLinks context->paramOut_Trigger_numLinks

/* AdditionalStateVariables shortcuts */
#define addS_SCEnabled ((MicroBenchEvaluator_Block_CImplementation_func*) context)->SCEnabled
#define addS_samplesCounter ((MicroBenchEvaluator_Block_CImplementation_func*) context)->samplesCounter
#define addS_signalCounter ((MicroBenchEvaluator_Block_CImplementation_func*) context)->signalCounter

/* AdditionalStateVariables default values */
#define ADDS_SCENABLED_DEFAULTVALUE 0
#define ADDS_SAMPLESCOUNTER_DEFAULTVALUE 0
#define ADDS_SIGNALCOUNTER_DEFAULTVALUE 0

/* Common event shortcuts */
/* EngineManager function shortcuts */
#define engine_run() engineManager_run((DSPEElement*) context)
#define engine_stop() engineManager_stop((DSPEElement*) context)
#define engine_pause() engineManager_pause((DSPEElement*) context)
#define engine_skip(cycles) engineManager_skip((DSPEElement*) context, cycles)
#define engine_quit() engineManager_quit((DSPEElement*) context)
#define engine_suspend() engineManager_suspend((DSPEElement*) context)
#define engine_freeze() engineManager_freeze((DSPEElement*) context)
#define engine_resume() engineManager_resume((DSPEElement*) context)

#define engine_isExecuting() engineManager_isExecuting((DSPEElement*) context)
#define engine_isStopping() engineManager_isStopping((DSPEElement*) context)
#define engine_isStopped() engineManager_isStopped((DSPEElement*) context)
#define engine_isPaused() engineManager_isPaused((DSPEElement*) context)
#define engine_isSkipping() engineManager_isSkipping((DSPEElement*) context)
#define engine_isExiting() engineManager_isExiting((DSPEElement*) context)
#define engine_isSuspended() engineManager_isSuspended((DSPEElement*) context)

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
MicroBenchEvaluator_Block_CImplementation* MicroBenchEvaluator_Block_CImplementation_allocate(DSPEElement *context) {
	/* Allocating functional structure but returning parent struct pointer */
	return (MicroBenchEvaluator_Block_CImplementation*) memoryManager_allocate(context, sizeof(MicroBenchEvaluator_Block_CImplementation_func));
}

/* Dispose function */
void MicroBenchEvaluator_Block_CImplementation_dispose(DSPEElement *element, MicroBenchEvaluator_Block_CImplementation *context) {
	memorySupport_dispose(context);
}

/**
 * Process algorithm. What the unit really does should take place here.
 * This function will be called at each process cycle.
 */
void MicroBenchEvaluator_Block_CImplementation_process(MicroBenchEvaluator_Block_CImplementation *context) {
//Place implementation after this line -- SYD-PROCESS-START
	LOOPVAR_TYPE l;

	pOut_Trigger = 0;

	for (l = 0; l < blockSize; l++) {
		//TODO valutare l'utilizzo di signals invece che semplici parametri per diverse gates
		if (dIn_Start_block[l])
			addS_SCEnabled = 1;
		if (dIn_Stop_block[l])
			addS_SCEnabled = 0;

		if (!addS_SCEnabled) {
			addS_signalCounter++;
			if (addS_signalCounter >= pIn_SignalDelay) {
				addS_signalCounter = 0;
				pOut_Trigger = 1;
			}
		}
	}

	addS_samplesCounter += blockSize;
	pOut_SamplesCount = addS_samplesCounter;
	if (pIn_AutomaticStop && addS_samplesCounter >= pIn_SamplesToProcess)
		engine_stop();
//SYD-PROCESS-END -- Place implementation before this line 
}

/**
 * PostProcess algorithm. Process phase cleanup should take place here.
 * This function will be called ONCE after the process phase.
 */
void MicroBenchEvaluator_Block_CImplementation_postProcess(MicroBenchEvaluator_Block_CImplementation *context) {
//Place implementation after this line -- SYD-POSTPROCESS-START
	pOut_ElapsedTime = profile_getElapsedTime();

	pOut_Throughput = profile_getThroughput();

	pOut_Min_Lag = profile_getMinLag();
	pOut_Mean_Lag = profile_getMeanLag();
	pOut_Max_Lag = profile_getMaxLag();

	pOut_Min_L = profile_getMinLatency() / 1000;
	pOut_Mean_L = profile_getMeanLatency() / 1000;
	pOut_Max_L = profile_getMaxLatency() / 1000;
//SYD-POSTPROCESS-END -- Place implementation before this line 
}

#undef blockSize

#undef LOOPVAR_TYPE

/* Input ParameterGates Shortcuts */
#undef pIn_SignalDelay
#undef pIn_AutomaticStop
#undef pIn_SamplesToProcess

/* Output ParameterGates Shortcuts */
#undef pOut_SamplesCount
#undef pOut_ElapsedTime
#undef pOut_Throughput
#undef pOut_Min_L
#undef pOut_Mean_L
#undef pOut_Max_L
#undef pOut_Min_Lag
#undef pOut_Mean_Lag
#undef pOut_Max_Lag
#undef pOut_Trigger

/* Input DataGates Shortcuts */
#undef dIn_Start
#undef dIn_Start_block
#undef dIn_Stop
#undef dIn_Stop_block

/* numLinks shortcuts */
#undef dIn_Start_numLinks
#undef dIn_Stop_numLinks
#undef pIn_SignalDelay_numLinks
#undef pIn_AutomaticStop_numLinks
#undef pIn_SamplesToProcess_numLinks
#undef pOut_SamplesCount_numLinks
#undef pOut_ElapsedTime_numLinks
#undef pOut_Throughput_numLinks
#undef pOut_Min_L_numLinks
#undef pOut_Mean_L_numLinks
#undef pOut_Max_L_numLinks
#undef pOut_Min_Lag_numLinks
#undef pOut_Mean_Lag_numLinks
#undef pOut_Max_Lag_numLinks
#undef pOut_Trigger_numLinks

/* AdditionalStateVariables shortcuts */
#undef addS_SCEnabled
#undef addS_samplesCounter
#undef addS_signalCounter

#undef ADDS_SCENABLED_DEFAULTVALUE
#undef ADDS_SAMPLESCOUNTER_DEFAULTVALUE
#undef ADDS_SIGNALCOUNTER_DEFAULTVALUE

/* EngineManager function shortcuts */
#undef engine_run
#undef engine_stop
#undef engine_pause
#undef engine_skip
#undef engine_quit
#undef engine_suspend
#undef engine_freeze
#undef engine_resume

#undef engine_isExecuting
#undef engine_isStopping
#undef engine_isStopped
#undef engine_isPaused
#undef engine_isSkipping
#undef engine_isExiting
#undef engine_isSuspended

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

