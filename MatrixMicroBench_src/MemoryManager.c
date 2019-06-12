/**
 * File: MemoryManager.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#include "MemoryManager.h"

#include "ErrorManager.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * MemorySupport_allocate function
 */
void* memorySupport_allocate(size_t size) {
	return malloc(size);
}

/**
 * MemorySupport_allocateAndInit function
 */
void* memorySupport_allocateAndInit(size_t blockSize, size_t size) {
	return calloc(blockSize, size);
}

/**
 * MemorySupport_realloc function
 */
void* memorySupport_realloc(void *pointer, size_t newSize) {
	void *tmp;
	tmp = realloc(pointer, newSize);
	if (tmp == NULL)
		return pointer;
	return tmp;
}

/**
 * MemorySupport_dispose function
 */
void memorySupport_dispose(void *pointer) {
	free(pointer);
}

/**
 * MemorySupport_copyBlock function
 */
void memorySupport_copyBlock(void *destination, const void *source, size_t size) {
	memcpy(destination, source, size);
}

/**
 * MemorySupport_resetBlock function
 */
void memorySupport_resetBlock(void *destination, size_t size) {
	memset(destination, 0, size);
}

/**
 * MemoryManager_allocate function
 */
void* memoryManager_allocate(const DSPEElement *element, size_t size) {
	void *allocated;
	errno = 0;
	allocated = malloc(size);
	if (errno)
		errorManager_appendStandardError(element, FATAL_ERROR, errno);
	if (!errno && allocated == NULL)
		errorManager_appendError(element, FATAL_ERROR, "Unable to allocate the requested memory");
	return allocated;
}

/**
 * MemoryManager_allocateAndInit function
 */
void* memoryManager_allocateAndInit(const DSPEElement *element, size_t blockSize, size_t size) {
	void *allocated;
	errno = 0;
	allocated = calloc(blockSize, size);
	if (errno)
		errorManager_appendStandardError(element, FATAL_ERROR, errno);
	if (!errno && allocated == NULL)
		errorManager_appendError(element, FATAL_ERROR, "Unable to allocate the requested memory");
	return allocated;
}

/**
 * MemoryManager_realloc function
 */
void* memoryManager_realloc(const DSPEElement *element, void *pointer, size_t newSize) {
	void *tmp;
	tmp = realloc(pointer, newSize);
	if (tmp == NULL) {
		errorManager_appendError(element, FATAL_ERROR, "Unable to re-allocate the requested memory");
		return pointer;
	}
	return tmp;
}

/**
 * MemoryManager_allocateHandlerPool function
 */
void memoryManager_allocateHandlerPool(const DSPEElement *element, DSPEOwner *ownerExt) {
	register size_t i;
	ownerExt->handlers = (DSPEHandler**) memoryManager_allocate(element, MAX_NUM_HANDLERS * sizeof(DSPEHandler*));

	for (i = 0; i < MAX_NUM_HANDLERS; i++) {
		ownerExt->handlers[i] = NULL;
	}
}

/**
 * MemoryManager_resetHandlerPool function
 */
void memoryManager_resetHandlerPool(const DSPEElement *element, DSPEOwner *ownerExt) {
	register size_t i;
	DSPEHandler *handler = NULL;

	if (ownerExt->handlers == NULL)
		return;

	for (i = 0; i < MAX_NUM_HANDLERS; i++) {
		handler = ownerExt->handlers[i];
		if (handler != NULL)
			handler->reset(handler);
	}
}

/**
 * MemoryManager_disposeHandlerPool function
 */
void memoryManager_disposeHandlerPool(const DSPEElement *element, DSPEOwner *ownerExt) {
	register size_t i;
	DSPEHandler *handler = NULL;

	if (ownerExt->handlers == NULL)
		return;

	for (i = 0; i < MAX_NUM_HANDLERS; i++) {
		handler = ownerExt->handlers[i];
		/* Not all handlers might have been created! */
		if (handler != NULL)
			handler->dispose(handler);
	}
	/* Dispose allocated handlers array */
	memorySupport_dispose(ownerExt->handlers);
	
	// REMARK needed when disposing threadHandler on runnerDelegates, because application
	// handlers are disposed before runnerDelegate handlers!
	ownerExt->handlers = NULL;
}

