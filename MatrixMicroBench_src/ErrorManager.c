/**
 * File: ErrorManager.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#include "ErrorManager.h"

#include "InfoManager.h"

#include "RunnerGround.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

/**
 * ClearErrorQueue function
 */
static INLINE void clearErrorQueue(const DSPEElement *element, DSPEErrorQueue *errorQueue) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (errorQueue == NULL || errorQueue->queueNumElements == 0) {
		return;
	}
	// Add error nodes to pool
	if (context->errorPoolNodesNum == 0) {
		context->errorPoolHead = errorQueue->queueHead;
		context->errorPoolTail = errorQueue->queueTail;
		context->errorPoolNodesNum = errorQueue->queueNumElements;
	} else {
		context->errorPoolTail->next = errorQueue->queueHead;
		context->errorPoolTail = errorQueue->queueTail;
		context->errorPoolNodesNum += errorQueue->queueNumElements;
	}
	errorQueue->queueHead = NULL;
	errorQueue->queueTail = NULL;
	errorQueue->queueNumElements = 0;
}

/**
 * InitializeErrorQueue function
 */
static INLINE DSPEErrorQueue* initializeErrorQueue(const DSPEElement *element) {
	DSPEErrorQueue *errorQueue = (DSPEErrorQueue*) allocateMemory(element, sizeof(DSPEErrorQueue));
	errorQueue->queueHead = NULL;
	errorQueue->queueTail = NULL;
	errorQueue->queueNumElements = 0;
	return errorQueue;
}

/**
 * DisposeErrorQueue function
 */
static INLINE void disposeErrorQueue(const DSPEElement *element, DSPEErrorQueue *errorQueue) {
	clearErrorQueue(element, errorQueue);
	disposeMemory(errorQueue);
}

/**
 * GetErrorQueue function
 */
static INLINE DSPEErrorQueue* getErrorQueue(const DSPEElement *element, errorType type) {
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (type >= errorTypeCnt)
		return NULL;
	return context->errorQueues[type];
}

/**
 * GetErrorTypeString function
 */
static INLINE char* getErrorTypeString(errorType type) {
 	switch (type) {
 	case FATAL_ERROR:
 		return "Fatal error";
 	case SEVERE_ERROR:
 		return "Severe error";
 	case MAJOR_ERROR:
 		return "Major error";
 	case MINOR_ERROR:
 		return "Minor error";
 	case errorTypeCnt:
 	default:
 	 	return "Undefined error";
 	}
}

/**
 * Adds the given errorMsg to the error queue.
 * Returns the newly added errorNode for convenience.
 */
static INLINE DSPEErrorNode* addErrorNode(const DSPEElement *element, errorType type, const char *errorMsg, va_list args) {
	DSPEErrorQueue *errorQueue = getErrorQueue(element, type);
	DSPEErrorNode *node;
	size_t errorMsgLength;
	va_list copy;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	if (errorQueue == NULL)
		return NULL;
	if (errorQueue->queueNumElements >= ERROR_MAX_SIZE) {
		// Error queue is full, overwrite oldest error
		node = errorQueue->queueHead;
		errorQueue->queueHead = node->next;
		errorQueue->queueNumElements--;
		node->next = NULL;
	} else {
		// Retrieve node from pool (if any)
		switch (context->errorPoolNodesNum) {
		case 0:
			node = (DSPEErrorNode*) allocateMemory(element, sizeof(DSPEErrorNode));
			node->elementID = NULL;
			node->errorMsg = NULL;
			node->errorMsgLength = 0;
			node->next = NULL;
			break;
		case 1:
			node = context->errorPoolHead;
			context->errorPoolHead = NULL;
			context->errorPoolTail = NULL;
			context->errorPoolNodesNum = 0;
			node->next = NULL;
			break;
		default:
			node = context->errorPoolHead;
			context->errorPoolHead = node->next;
			context->errorPoolNodesNum--;
			node->next = NULL;
			break;
		}
	}

	// REMARK: cannot reuse the same va_list, need a copy!
	va_copy(copy, args);
	errorMsgLength = (size_t) (vsnprintf(NULL, 0, errorMsg, copy) + 1);
	va_end(copy);
	if (node->errorMsgLength == 0) {
		node->errorMsg = (char*) allocateMemory(element, errorMsgLength);
		node->errorMsgLength = errorMsgLength;
	} else if (errorMsgLength > node->errorMsgLength) {
		node->errorMsg = (char*) reallocateMemory(node->errorMsg, errorMsgLength);
		node->errorMsgLength = errorMsgLength;
	}
	vsnprintf(node->errorMsg, node->errorMsgLength, errorMsg, args);

	if (element->getID == NULL)
		node->elementID = NULL;
	else
		node->elementID = element->getID(element);

	// Add error node to queue
	if (errorQueue->queueNumElements == 0) {
		errorQueue->queueHead = node;
		errorQueue->queueTail = node;
		errorQueue->queueNumElements = 1;
	} else {
		errorQueue->queueTail->next = node;
		errorQueue->queueTail = node;
		errorQueue->queueNumElements++;
	}
	if ((type == FATAL_ERROR || type == SEVERE_ERROR || type == MAJOR_ERROR) && !context->errorForceApplicationStop)
		context->errorForceApplicationStop = 1;

	return node;
}

/**
 * Displays the given error message to the screen.
 */
static INLINE void showError(const DSPEElement *element, errorType type, DSPEErrorNode *node) {
	char *errorTypeStr = getErrorTypeString(type);
	if (node == NULL)
		return;

	if (node->elementID != NULL)
		infoManager_writeInfo(element, "%s - %s: %s", errorTypeStr, node->elementID, node->errorMsg);
	else
		infoManager_writeInfo(element, "%s - %s", errorTypeStr, node->errorMsg);
}

/**
 * ErrorManager_initialize function
 */
void errorManager_initialize(const DSPEElement *element) {
	register size_t i;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	// Always collect is set since info manager is not available
	context->errorAlwaysCollect = 1;

	context->errorPoolNodesNum = 0;
	context->errorPoolHead = NULL;
	context->errorPoolTail = NULL;

	context->errorQueues = (DSPEErrorQueue**) allocateMemory(element, errorTypeCnt * sizeof(DSPEErrorQueue*));
	for (i = 0; i < errorTypeCnt; i++)
		context->errorQueues[i] = initializeErrorQueue(element);
	context->errorForceApplicationStop = 0;
}

/**
 * ErrorManager_dispose function
 */
void errorManager_dispose(const DSPEElement *element) {
	register size_t i;
	DSPEErrorNode *node;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	for (i = 0; i < errorTypeCnt; i++)
		disposeErrorQueue(element, context->errorQueues[i]);
	disposeMemory(context->errorQueues);

	while (context->errorPoolNodesNum > 0) {
		node = context->errorPoolHead;
		context->errorPoolHead = node->next;
		context->errorPoolNodesNum--;
		disposeMemory(node->errorMsg);
		node->next = NULL;
		disposeMemory(node);
	}
}

/**
 * ErrorManager_appendError function
 * Error is added to errorQueue and an error message is displayed.
 */
void errorManager_appendError(const DSPEElement *element, errorType type, const char *errorMsg, ...) {
	va_list args;
	DSPEErrorNode *node;
	MatrixBenchMatrixMicroBench_Application_cmd *context = (MatrixBenchMatrixMicroBench_Application_cmd*) element->application;

	va_start(args, errorMsg);
	node = addErrorNode(element, type, errorMsg, args);
	va_end(args);
	if (!context->errorAlwaysCollect)
		showError(element, type, node);
}

/**
 * ErrorManager_appendStandardError function
 * Error is added to errorQueue and an error message is displayed.
 */
void errorManager_appendStandardError(const DSPEElement *element, errorType type, int errorCode) {
	errorManager_appendError(element, type, strerror(errorCode));
}

/**
 * ErrorManager_collectError function.
 * Error is added to errorQueue but no error message is displayed.
 */
void errorManager_collectError(const DSPEElement *element, errorType type, const char *errorMsg, ...) {
	va_list args;

	va_start(args, errorMsg);
	addErrorNode(element, type, errorMsg, args);
	va_end(args);
}

/**
 * ErrorManager_collectStandardError function
 * Error is added to errorQueue but no error message is displayed.
 */
void errorManager_collectStandardError(const DSPEElement *element, errorType type, int errorCode) {
	errorManager_collectError(element, type, strerror(errorCode));
}

/**
 * ErrorManager_clearErrors function
 */
void errorManager_clearErrors(const DSPEElement *element, errorType type) {
	clearErrorQueue(element, getErrorQueue(element, type));
}

/**
 * ErrorManager_hasErrorOccurred function
 */
int errorManager_hasErrorOccurred(const DSPEElement *element, errorType type) {
	DSPEErrorQueue* errorQueue = getErrorQueue(element, type);
	if (errorQueue == NULL)
		return 0;

	return errorQueue->queueNumElements != 0;
}

/**
 * ErrorManager_showErrors function
 */
void errorManager_showErrors(const DSPEElement *element, errorType type, const char *message) {
	DSPEErrorNode *node;
	DSPEErrorQueue *errorQueue = getErrorQueue(element, type);
	if (errorQueue == NULL || errorQueue->queueNumElements == 0) {
		return;
	}

	if (message != NULL)
		infoManager_writeInfo(element, message);
	node = errorQueue->queueHead;
	while (node != NULL) {
		showError(element, type, node);
		node = node->next;
	}
}

