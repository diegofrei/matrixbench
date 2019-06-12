/**
 * File: EngineManager.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "EngineManager.h"

#include "ErrorManager.h"

#include "RunnerGround.h"

/**
 * EngineManager_initialize function
 */
void engineManager_initialize(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	context->stopped = 1;
	context->skipCycles = 0;
}

/**
 * EngineManager_isExecuting function
 */
int engineManager_isExecuting(const DSPEElement *element) {
	return !((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_isStopping function
 */
int engineManager_isStopping(const DSPEElement *element) {
	return ((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_isStopped function
 */
int engineManager_isStopped(const DSPEElement *element) {
	return ((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_isRunning function
 */
int engineManager_isRunning(const DSPEElement *element) {
	return !((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_isPaused function
 */
int engineManager_isPaused(const DSPEElement *element) {
	return ((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_isSkipping function
 */
int engineManager_isSkipping(const DSPEElement *element) {
	return ((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->skipCycles != 0;
}

/**
 * EngineManager_isExiting function
 */
int engineManager_isExiting(const DSPEElement *element) {
	return ((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_isSuspended function
 */
int engineManager_isSuspended(const DSPEElement *element) {
	return ((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped;
}

/**
 * EngineManager_run function
 */
void engineManager_run(const DSPEElement *element) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped = 0;
}

/**
 * EngineManager_stop function
 */
void engineManager_stop(const DSPEElement *element) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped = 1;
}

/**
 * EngineManager_pause function
 */
void engineManager_pause(const DSPEElement *element) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped = 1;
}

/**
 * EngineManager_skip function
 */
void engineManager_skip(const DSPEElement *element, long int cycles) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->skipCycles = cycles + 1;
}

/**
 * EngineManager_quit function
 */
void engineManager_quit(const DSPEElement *element) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped = 1;
}

/**
 * EngineManager_suspend function
 */
void engineManager_suspend(const DSPEElement *element) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped = 1;
}

/**
 * EngineManager_freeze function
 */
int engineManager_freeze(const DSPEElement *element) {
	((MatrixBenchMatrixMicroBench_Application_cmd*) element->application)->stopped = 1;
	return 0;
}

/**
 * EngineManager_resume function
 */
void engineManager_resume(const DSPEElement *element) {
}

/**
 * EngineManager_performIdleTime function
 */
void engineManager_performIdleTime(const DSPEElement *element) {
}

/**
 * EngineManager_forceUpdateEngineStateFeedback function.
 */
void engineManager_forceUpdateEngineStateFeedback(const DSPEElement *element) {
	// REMARK not supported for commandLine!
}

/**
 * EngineManager_forceCriticalSection function.
 * Returns engineManager stopped state.
 */
int engineManager_forceCriticalSection(const DSPEElement *element) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;


	if (context->errorForceApplicationStop) {
		engineManager_stop(element);
		return engineManager_isStopped(element) || engineManager_isStopping(element);
	}

	return engineManager_isStopped(element) || engineManager_isStopping(element);
}

