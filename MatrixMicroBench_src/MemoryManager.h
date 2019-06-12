/**
 * File: MemoryManager.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#ifndef MemoryManager_h
#define MemoryManager_h

#include "DSPEElements.h"
#include "MemoryGround.h"

/* MemoryManager Handler defines */
#define MAX_NUM_HANDLERS 6
#define HANDLER_INDEX_EVENTPOOL 0
#define HANDLER_INDEX_COPROC 1
#define HANDLER_INDEX_THREAD 2
#define HANDLER_INDEX_BENCHMARK 3
#define HANDLER_INDEX_DISTRIBUTION 4
#define HANDLER_INDEX_SNAPSHOT 5

#ifdef __cplusplus
extern "C" {
#endif

/**
 * MemorySupport_allocate function
 */
void* memorySupport_allocate(size_t size);

/**
 * MemorySupport_allocateAndInit function
 */
void* memorySupport_allocateAndInit(size_t blockSize, size_t size);

/**
 * MemorySupport_realloc function
 */
void* memorySupport_realloc(void *pointer, size_t newSize);

/**
 * MemorySupport_dispose function
 */
void memorySupport_dispose(void *pointer);

/**
 * MemorySupport_copyBlock function
 */
void memorySupport_copyBlock(void *destination, const void *source, size_t size);

/**
 * MemorySupport_resetBlock function
 */
void memorySupport_resetBlock(void *destination, size_t size);

/**
 * MemoryManager_allocate function
 */
void* memoryManager_allocate(const DSPEElement *element, size_t size);

/**
 * MemoryManager_allocateAndInit function
 */
void* memoryManager_allocateAndInit(const DSPEElement *element, size_t blockSize, size_t size);

/**
 * MemoryManager_realloc function
 */
void* memoryManager_realloc(const DSPEElement *element, void *pointer, size_t newSize);

/**
 * MemoryManager_allocateHandlerPool function
 */
void memoryManager_allocateHandlerPool(const DSPEElement *element, DSPEOwner *ownerExt);

/**
 * MemoryManager_resetHandlerPool function
 */
void memoryManager_resetHandlerPool(const DSPEElement *element, DSPEOwner *ownerExt);

/**
 * MemoryManager_disposeHandlerPool function
 */
void memoryManager_disposeHandlerPool(const DSPEElement *element, DSPEOwner *ownerExt);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
