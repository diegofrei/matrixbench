/**
 * File: ThreadManager.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "ThreadManager.h"

#include "ErrorManager.h"
#include "MemoryManager.h"

#include <errno.h>
#include <pthread.h>
#if defined(LINUX) || defined(MAC_OSX)
#include <unistd.h>
#endif
#if defined(LINUX)
#include <sched.h>
#endif

// REMARK
// Found pthread_splinlock implmementation due to OSX's missing implmenetation.
// Source: https://github.com/majek/dump/blob/master/msqueue/pthread_spin_lock_shim.h
#if defined(MAC_OSX)

typedef int pthread_spinlock_t;

#ifndef PTHREAD_PROCESS_SHARED
# define PTHREAD_PROCESS_SHARED 1
#endif /* PTHREAD_PROCESS_SHARED */

#ifndef PTHREAD_PROCESS_PRIVATE
# define PTHREAD_PROCESS_PRIVATE 2
#endif /* PTHREAD_PROCESS_PRIVATE */

static inline int pthread_spin_init(pthread_spinlock_t *lock, int pshared) {
	__asm__ __volatile__ ("" ::: "memory");
	*lock = 0;
	return 0;
}

static inline int pthread_spin_destroy(pthread_spinlock_t *lock) {
	return 0;
}

static inline int pthread_spin_lock(pthread_spinlock_t *lock) {
	while (1) {
		int i;
		for (i=0; i < 10000; i++) {
			if (__sync_bool_compare_and_swap(lock, 0, 1)) {
				return 0;
			}
		}
		sched_yield();
	}
}

static inline int pthread_spin_trylock(pthread_spinlock_t *lock) {
	if (__sync_bool_compare_and_swap(lock, 0, 1)) {
		return 0;
	}
	return EBUSY;
}

static inline int pthread_spin_unlock(pthread_spinlock_t *lock) {
	__asm__ __volatile__ ("" ::: "memory");
	*lock = 0;
	return 0;
}

#endif /* MAC_OSX */
/******************************************************************************
 * HANDLER SUPPORT
 ******************************************************************************/

/**
 * getThreadHandler function
 */
static INLINE DSPEThreadHandler* getThreadHandler(const DSPEElement *context) {
	// REMARK on disposal applicationHandlers might have already disposed before runnerDelegate!
	if (context->owner->handlers == NULL)
		return NULL;
	return (DSPEThreadHandler*) context->owner->handlers[HANDLER_INDEX_THREAD];
}

/**
 * resetThreadHandler function
 */
static void resetThreadHandler(DSPEHandler *handler) {
	// Reset handler body
}

/**
 * disposeThreadHandler function
 */
static void disposeThreadHandler(DSPEHandler *handler) {
	
	/* Dispose handler */
	memorySupport_dispose(handler);
}

/**
 * initGlobalThreadHandler function
 */
static INLINE void initGlobalThreadHandler(const DSPEElement *element) {
	DSPEOwner *ownerExt = CAST_TO_OWNER(element->application);
	DSPEHandler **handlers = ownerExt->handlers;
	DSPEThreadHandler *handler = NULL;

	/* Lazy initialization of handlers array */
	if (handlers == NULL) {
		memoryManager_allocateHandlerPool(element, ownerExt);
		handlers = ownerExt->handlers;
	}

	handler = (DSPEThreadHandler*) memoryManager_allocate(element, sizeof(DSPEThreadHandler));
	initDSPEElement((DSPEElement*) handler, element);
	initDSPEHandler((DSPEHandler*) handler, element);

	((DSPEHandler*) handler)->reset = resetThreadHandler;
	((DSPEHandler*) handler)->dispose = disposeThreadHandler;

	/* Add ThreadHandler to handlers */
	handlers[HANDLER_INDEX_THREAD] = (DSPEHandler*) handler;

	
	/* init processor affinity counter */
	handler->affinityCounter = 0;

	/* init numThreads */
	handler->numThreads = MAX_NUM_THREADS;
}

/**
 * ThreadManager_initThreadHandler function
 */
void threadManager_initThreadHandler(DSPEOwner *ownerExt) {
	DSPEThreadHandler *handler = NULL;
	const DSPEElement *element = CAST_TO_ELEMENT(ownerExt);
	DSPEThreadHandler *applicationHandler = getThreadHandler((DSPEElement*) element->application);
	DSPEHandler **handlers = ownerExt->handlers;

	/* Lazy initialization of global threadHandler */
	if (applicationHandler == NULL) {
		initGlobalThreadHandler(element);
		applicationHandler = getThreadHandler((DSPEElement*) element->application);
	}

	if (element == (DSPEElement*) element->application) {
		// global ThreadHandler already initialized!
		return;
	}

	/* Lazy initialization of handlers array */
	if (handlers == NULL) {
		memoryManager_allocateHandlerPool(element, ownerExt);
		handlers = ownerExt->handlers;
	}

	handler = (DSPEThreadHandler*) memoryManager_allocate(element, sizeof(DSPEThreadHandler));
	initDSPEElement((DSPEElement*) handler, element);
	initDSPEHandler((DSPEHandler*) handler, element);

	((DSPEHandler*) handler)->reset = resetThreadHandler;
	((DSPEHandler*) handler)->dispose = disposeThreadHandler;

	applicationHandler = getThreadHandler((DSPEElement*) element->application);

	/* Add ThreadHandler to handlers */
	handlers[HANDLER_INDEX_THREAD] = (DSPEHandler*) handler;

	
	/* init processor affinity counter */
	handler->affinityCounter = 0;

	/* init numThreads */
	handler->numThreads = MAX_NUM_THREADS;
}

/******************************************************************************
 * THREAD SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_getNumProcessors function
 * Return the number of Processors on system
 */
unsigned int threadManager_getNumProcessors(const DSPEElement *context) {
	threadNumProcessors();
}

/**
 * ThreadManager_createThread function
 * Create and start a thread
 */
void* threadManager_createThread(const DSPEElement *element, CREATE_THREAD_ROUTINE, THREAD_ROUTINE_ARGS) {
	register int error = 0;
	pthread_attr_t attributes;
	pthread_t *thread = NULL;
	error = pthread_attr_init(&attributes);
	if (error) {
		errorManager_appendStandardError(element, FATAL_ERROR, error);
		return NULL;
	}
	// TODO parte condizionale
	error = pthread_attr_setscope(&attributes, PTHREAD_SCOPE_SYSTEM);
	if (error) {
		errorManager_appendStandardError(element, FATAL_ERROR, error);
		return NULL;
	}
	// TODO risolvere problema DSPECGeneConstants allocate!
	thread = (pthread_t*) memoryManager_allocate(element, sizeof(pthread_t));
	error = pthread_create(thread, &attributes, threadRoutine, args);
	// error = pthread_create(thread, NULL, threadRoutine, args);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	
	return (void*) thread;
}

/**
 * ThreadManager_waitThread function
 * The calling thread is suspended until the thread passed as
 * argument is terminated.
 */
void threadManager_waitThread(const DSPEElement *element, void *thread) {
	register int error = 0;
	error = pthread_join(*((pthread_t*) thread), NULL);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * ThreadManager_destroyThread function
 */
void threadManager_destroyThread(const DSPEElement *element, void *thread) {
	memorySupport_dispose(thread);
}

/******************************************************************************
 * MUTEX SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_createMutex function
 */
void* threadManager_createMutex(const DSPEElement *element) {
	register int error = 0;
	pthread_mutex_t *mutex = (pthread_mutex_t*) memoryManager_allocate(element, sizeof(pthread_mutex_t));
	error = pthread_mutex_init(mutex, NULL);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	return (void*) mutex;
}

/**
 * ThreadManager_lockMutex function
 */
void threadManager_lockMutex(const DSPEElement *element, void *mutex) {
	register int error = 0;
	error = pthread_mutex_lock((pthread_mutex_t*) mutex);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * ThreadManager_tryLockMutex function
 */
int threadManager_tryLockMutex(const DSPEElement *element, void *mutex) {
	int error = 0;
	error = pthread_mutex_trylock((pthread_mutex_t*) mutex);
	if (!error)
		return 1;
	if (error == EBUSY)
		return 0;
	else {
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
		return 0;
	}
}

/**
 * ThreadManager_unlockMutex function
 */
void threadManager_unlockMutex(const DSPEElement *element, void *mutex) {
	register int error = 0;
	error = pthread_mutex_unlock((pthread_mutex_t*) mutex);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * ThreadManager_deleteMutex function
 */
void threadManager_deleteMutex(const DSPEElement *element, void *mutex) {
	register int error = 0;
	error = pthread_mutex_destroy((pthread_mutex_t*) mutex);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	memorySupport_dispose(mutex);
}

/******************************************************************************
 * SPINLOCK SUPPORT
 ******************************************************************************/

/**
 * Creates a spinning lock
 */
void* threadManager_createSpin(const DSPEElement *element) {
	register int error = 0;
	pthread_spinlock_t *spin = (pthread_spinlock_t*) memoryManager_allocate(element, sizeof(pthread_spinlock_t));
	error = pthread_spin_init(spin, PTHREAD_PROCESS_PRIVATE);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	return (void*) spin;
}

/**
 * Lock a spinning lock
 */
void threadManager_lockSpin(const DSPEElement *element, void *spin) {
	register int error = 0;
	error = pthread_spin_lock((pthread_spinlock_t*) spin);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * Tries to lock a spinning lock
 */
int threadManager_tryLockSpin(const DSPEElement *element, void *spin) {
	int error = 0;
	error = pthread_spin_trylock((pthread_spinlock_t*) spin);
	if (!error)
		return 1;
	if (error == EBUSY)
		return 0;
	else {
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
		return 0;
	}
}

/**
 * Unlock a spinning lock
 */
void threadManager_unlockSpin(const DSPEElement *element, void *spin) {
	register int error = 0;
	error = pthread_spin_unlock((pthread_spinlock_t*) spin);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * Deletes a spinning lock
 */
void threadManager_deleteSpin(const DSPEElement *element, void *spin) {
	register int error = 0;
	error = pthread_spin_destroy((pthread_spinlock_t*) spin);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	memorySupport_dispose(spin);
}

/******************************************************************************
 * CONDITION SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_createCondition function
 * Create and initialise condition variable
 */
void* threadManager_createCondition(const DSPEElement *element) {
	register int error = 0;
	pthread_cond_t *condition = (pthread_cond_t*) memoryManager_allocate(element, sizeof(pthread_cond_t));
	error = pthread_cond_init(condition, NULL);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	return (void*) condition;
}

/**
 * ThreadManager_waitCondition function
 */
void threadManager_waitCondition(const DSPEElement *element, void *condition, void *mutex) {
	register int error = 0;
	error = pthread_cond_wait((pthread_cond_t*) condition, (pthread_mutex_t*) mutex);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * Function to wake a thread waiting at a conditional variable
 */
void threadManager_wakeCondition(const DSPEElement *element, void *condition) {
	register int error = 0;
	error = pthread_cond_signal((pthread_cond_t*) condition);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * threadManager_wakeAllCondition function
 */
void threadManager_wakeAllCondition(const DSPEElement *element, void *condition) {
	register int error = 0;
	error = pthread_cond_broadcast((pthread_cond_t*) condition);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * ThreadManager_destroyCondition function
 */
void threadManager_destroyCondition(const DSPEElement *element, void *condition) {
	register int error = 0;
	error = pthread_cond_destroy((pthread_cond_t*) condition);
	if (error)
		errorManager_appendStandardError(element, FATAL_ERROR, error);
	memorySupport_dispose(condition);
}

/******************************************************************************
 * GENERIC SUPPORT
 ******************************************************************************/

/**
 * ThreadManager_delay function
 * The calling thread is suspended for seconds (argument 'sec')
 * and nano seconds (argument 'nsec').
 */
void threadManager_delay(const DSPEElement *element, long int sec, long int nsec) {
	register int error = 0;
	struct timespec time = {sec, nsec};
	error = threadDelay(time);
	if (error)
		errorManager_appendStandardError(element, SEVERE_ERROR, error);
}

/**
 * ThreadManager_setAffinity function
 */
void threadManager_setAffinity(const DSPEElement *element, void *thread) {
// REMARK pthread affinity available only on linux platforms!
#if defined(LINUX) && defined(_GNU_SOURCE)
	DSPEThreadHandler* handler = NULL;
	pthread_t *ptThread = (pthread_t*) thread;
	cpu_set_t set;
	register unsigned int numProcessors;
	register unsigned int processorID;
	unsigned int error;

	/* Find out how many cpus we have */
	numProcessors = threadManager_getNumProcessors(element);

	/* Increase affinity counter */
	handler = getThreadHandler(element);

	/* Find out on which processor the created thread has to be paced */	
#if defined(AFFINITY_STEP)
	processorID = handler->affinityCounter * AFFINITY_STEP;
#else
	processorID = handler->affinityCounter;
#endif
	if (processorID >= numProcessors) {
		processorID = (processorID % numProcessors);
		processorID = processorID + 1;
	}
	
	handler->affinityCounter++;

	//FIXME Linux only functions
	CPU_ZERO(&set);
	CPU_SET(processorID, &set);

	//FIXME Non portable (NP), it works only on linux machine because
	//it's based on the system function sched_setaffinity
	error = pthread_setaffinity_np(*ptThread, sizeof(cpu_set_t), &set);

	if (error)
		errorManager_appendError(element, SEVERE_ERROR, "Failed to set thread affinity on processing thread");
#endif
}

/**
 * ThreadManager_getNumThreads function
 * Return the number of active threads
 */
size_t threadManager_getNumThreads(const DSPEElement *context) {
	DSPEThreadHandler *handler = getThreadHandler(context);
	return handler->numThreads;
}

