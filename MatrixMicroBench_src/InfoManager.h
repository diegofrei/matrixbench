/**
 * File: InfoManager.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#ifndef InfoManager_h
#define InfoManager_h

#include "DSPEElements.h"

/* Bypass console */
#define INFOMANAGER_BYPASS_CONSOLE 0
/* Bypass log */
#define INFOMANAGER_BYPASS_LOG 0

/* Collected info ids */
typedef enum infoID {

	infoIDCount
} infoID;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * InfoManager_writeInfo function
 */
void infoManager_writeInfo(const DSPEElement *element, const char *info, ...);

/**
 * InfoManager_logInfo function
 */
void infoManager_logInfo(const DSPEElement *element, const char *info, ...);

/**
 * InfoSupport_getCollectedInfoString function.
 */
const char* infoSupport_getCollectedInfoString(const infoID id);

/**
 * InfoManager_collectAndWriteInfo function
 */
void infoManager_collectAndWriteInfo(const DSPEElement *element, const infoID id, const unsigned int increment);

/**
 * InfoManager_collectAndLogInfo function
 */
void infoManager_collectAndLogInfo(const DSPEElement *element, const infoID id, const unsigned int increment);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
