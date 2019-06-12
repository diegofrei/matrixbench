/**
 * File: ThreadManager.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#ifndef ThreadManager_h
#define ThreadManager_h

#include "DSPEElements.h"

/* Minimum number of threads (Master Thread, RunnerDelegate Thread) */
#define MIN_NUM_THREADS 2

/* Maximum number of threads (Runner, GUI + maxNumEngines) */
#define MAX_NUM_THREADS (MIN_NUM_THREADS + 0)

#define THREAD_ROUTINE_LPART void*
#define THREAD_ROUTINE_ARGS void *args
#define THREAD_ROUTINE_RETURN return NULL;
#define CREATE_THREAD_ROUTINE void* (*threadRoutine) (void*)

typedef struct DSPEThreadHandler DSPEThreadHandler;

struct DSPEThreadHandler {
	DSPEHandler handler;

	/* Actual number of threads */
	size_t numThreads;

	/* Processor affinity counter */
	size_t affinityCounter;
};

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * HANDLER SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_initThreadHandler function
 */
void threadManager_initThreadHandler(DSPEOwner *ownerExt);

/******************************************************************************
 * THREAD SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_getNumProcessors function
 * Return the number of Processors on system
 */
unsigned int threadManager_getNumProcessors(const DSPEElement *context);

/**
 * ThreadManager_createThread function
 * Create and start a thread
 */
void* threadManager_createThread(const DSPEElement *element, CREATE_THREAD_ROUTINE, THREAD_ROUTINE_ARGS);

/**
 * ThreadManager_waitThread function
 * The calling thread is suspended until the thread passed as
 * argument is terminated.
 */
void threadManager_waitThread(const DSPEElement *element, void *thread);

/**
 * ThreadManager_destroyThread function
 */
void threadManager_destroyThread(const DSPEElement *element, void *thread);

/******************************************************************************
 * MUTEX SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_createMutex function
 */
void* threadManager_createMutex(const DSPEElement *element);

/**
 * ThreadManager_lockMutex function
 */
void threadManager_lockMutex(const DSPEElement *element, void *mutex);

/**
 * ThreadManager_tryLockMutex function
 */
int threadManager_tryLockMutex(const DSPEElement *element, void *mutex);

/**
 * ThreadManager_unlockMutex function
 */
void threadManager_unlockMutex(const DSPEElement *element, void *mutex);

/**
 * ThreadManager_deleteMutex function
 */
void threadManager_deleteMutex(const DSPEElement *element, void *mutex);

/******************************************************************************
 * SPINLOCK SUPPORT
 ******************************************************************************/

/**
 * Creates a spinning lock
 */
void* threadManager_createSpin(const DSPEElement *element);

/**
 * Lock a spinning lock
 */
void threadManager_lockSpin(const DSPEElement *element, void *spin);

/**
 * Tries to lock a spinning lock
 */
int threadManager_tryLockSpin(const DSPEElement *element, void *spin);

/**
 * Unlock a spinning lock
 */
void threadManager_unlockSpin(const DSPEElement *element, void *spin);

/**
 * Deletes a spinning lock
 */
void threadManager_deleteSpin(const DSPEElement *element, void *spin);

/******************************************************************************
 * CONDITION SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_createCondition function
 * Create and initialise condition variable
 */
void* threadManager_createCondition(const DSPEElement *element);

/**
 * ThreadManager_waitCondition function
 */
void threadManager_waitCondition(const DSPEElement *element, void *condition, void *mutex);

/**
 * Function to wake a thread waiting at a conditional variable
 */
void threadManager_wakeCondition(const DSPEElement *element, void *condition);

/**
 * threadManager_wakeAllCondition function
 */
void threadManager_wakeAllCondition(const DSPEElement *element, void *condition);

/**
 * ThreadManager_destroyCondition function
 */
void threadManager_destroyCondition(const DSPEElement *element, void *condition);

/******************************************************************************
 * GENERIC SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_delay function
 * The calling thread is suspended for seconds (argument 'sec')
 * and nano seconds (argument 'nsec').
 */
void threadManager_delay(const DSPEElement *element, long int sec, long int nsec);

/**
 * ThreadManager_setAffinity function
 */
void threadManager_setAffinity(const DSPEElement *element, void *thread);

/**
 * ThreadManager_getNumThreads function
 * Return the number of active threads
 */
size_t threadManager_getNumThreads(const DSPEElement *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
