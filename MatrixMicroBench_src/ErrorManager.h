/**
 * File: ErrorManager.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#ifndef ErrorManager_h
#define ErrorManager_h

#include "DSPEElements.h"

#define ERROR_MAX_SIZE 10

typedef enum errorType {
	FATAL_ERROR,
	SEVERE_ERROR,
	MAJOR_ERROR,
	MINOR_ERROR,
	errorTypeCnt
} errorType;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * ErrorManager_initialize function
 */
void errorManager_initialize(const DSPEElement *element);

/**
 * ErrorManager_dispose function
 */
void errorManager_dispose(const DSPEElement *element);

/**
 * ErrorManager_appendError function
 * Error is added to errorQueue and an error message is displayed.
 */
void errorManager_appendError(const DSPEElement *element, errorType type, const char *errorMsg, ...);

/**
 * ErrorManager_appendStandardError function
 * Error is added to errorQueue and an error message is displayed.
 */
void errorManager_appendStandardError(const DSPEElement *element, errorType type, int errorCode);

/**
 * ErrorManager_collectError function.
 * Error is added to errorQueue but no error message is displayed.
 */
void errorManager_collectError(const DSPEElement *element, errorType type, const char *errorMsg, ...);

/**
 * ErrorManager_collectStandardError function
 * Error is added to errorQueue but no error message is displayed.
 */
void errorManager_collectStandardError(const DSPEElement *element, errorType type, int errorCode);

/**
 * ErrorManager_clearErrors function
 */
void errorManager_clearErrors(const DSPEElement *element, errorType type);

/**
 * ErrorManager_hasErrorOccurred function
 */
int errorManager_hasErrorOccurred(const DSPEElement *element, errorType type);

/**
 * ErrorManager_showErrors function
 */
void errorManager_showErrors(const DSPEElement *element, errorType type, const char *message);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
