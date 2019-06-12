/**
 * File: EngineManager.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#ifndef EngineManager_h
#define EngineManager_h

#include "DSPEElements.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * EngineManager_initialize function
 */
void engineManager_initialize(const DSPEElement *element);

/**
 * EngineManager_isExecuting function
 */
int engineManager_isExecuting(const DSPEElement *element);

/**
 * EngineManager_isStopping function
 */
int engineManager_isStopping(const DSPEElement *element);

/**
 * EngineManager_isStopped function
 */
int engineManager_isStopped(const DSPEElement *element);

/**
 * EngineManager_isRunning function
 */
int engineManager_isRunning(const DSPEElement *element);

/**
 * EngineManager_isPaused function
 */
int engineManager_isPaused(const DSPEElement *element);

/**
 * EngineManager_isSkipping function
 */
int engineManager_isSkipping(const DSPEElement *element);

/**
 * EngineManager_isExiting function
 */
int engineManager_isExiting(const DSPEElement *element);

/**
 * EngineManager_isSuspended function
 */
int engineManager_isSuspended(const DSPEElement *element);

/**
 * EngineManager_run function
 */
void engineManager_run(const DSPEElement *element);

/**
 * EngineManager_stop function
 */
void engineManager_stop(const DSPEElement *element);

/**
 * EngineManager_pause function
 */
void engineManager_pause(const DSPEElement *element);

/**
 * EngineManager_skip function
 */
void engineManager_skip(const DSPEElement *element, long int cycles);

/**
 * EngineManager_quit function
 */
void engineManager_quit(const DSPEElement *element);

/**
 * EngineManager_suspend function
 */
void engineManager_suspend(const DSPEElement *element);

/**
 * EngineManager_freeze function
 */
int engineManager_freeze(const DSPEElement *element);

/**
 * EngineManager_resume function
 */
void engineManager_resume(const DSPEElement *element);

/**
 * EngineManager_performIdleTime function
 */
void engineManager_performIdleTime(const DSPEElement *element);

/**
 * EngineManager_forceUpdateEngineStateFeedback function.
 */
void engineManager_forceUpdateEngineStateFeedback(const DSPEElement *element);

/**
 * EngineManager_forceCriticalSection function.
 * Returns engineManager stopped state.
 */
int engineManager_forceCriticalSection(const DSPEElement *element);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
