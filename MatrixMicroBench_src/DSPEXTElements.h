/**
 * File: DSPEXTElements.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef DSPEXTElements_h
#define DSPEXTElements_h

#include "DSPEElements.h"

#ifdef __cplusplus
extern "C" {
#endif

// DSPE XT

#define NON_EXCLUSIVE_QUEUE 0
#define EXCLUSIVE_QUEUE 1

typedef struct DSPEComposite DSPEComposite;

typedef struct DSPEWrapImplementation DSPEWrapImplementation;


// EVENTS SUPPORT

typedef struct DSPEScheduler DSPEScheduler;

typedef struct DSPEEventsComposite DSPEEventsComposite;

typedef struct DSPEStateImplementation DSPEStateImplementation;


// OP SUPPORT

typedef struct DSPEOp DSPEOp;

typedef struct DSPEOpPool DSPEOpPool;

typedef struct DSPEOpInQueue DSPEOpInQueue;

typedef struct DSPEOpOutQueue DSPEOpOutQueue;

// COPROC SUPPORT

typedef struct DSPECoprocEvent DSPECoprocEvent;

typedef struct DSPECoprocUnit DSPECoprocUnit;

typedef struct DSPECoprocConfig DSPECoprocConfig;

typedef struct DSPECoprocScheduler DSPECoprocScheduler;

typedef struct DSPECoprocImplementation DSPECoprocImplementation;


// DSPE XT

struct DSPEComposite {
	DSPEUnit unit;
	OWNER_EXT;
};

struct DSPEWrapImplementation {
	DSPEElement element;
};

// EVENTS SUPPORT

struct DSPEScheduler {
	DSPEStructure structure;
};

struct DSPEEventsComposite {
	DSPEEventsUnit eventsUnit;
};

struct DSPEStateImplementation {
	DSPEElement element;
};

// OP SUPPORT

struct DSPEOp {
	DSPEElement element;
	
	void (*execute) (DSPEOp *op);
	void (*dispose) (DSPEOp *op);
	
	DSPEOpOutQueue *outQueue;
};

struct DSPEOpPool {
	DSPEElement element;

	DSPEOp* (*createOp) (DSPEOpPool *pool);
	void (*resetOp) (DSPEOpPool *pool, DSPEOp *op);
	void (*destroyOp) (DSPEOpPool *pool, DSPEOp *op);
	
	size_t (*getOpsBusy) (DSPEOpPool *pool);
};

struct DSPEOpInQueue {
	DSPEElement element;

	void (*reset) (DSPEOpInQueue *queue);
	void (*dispose) (DSPEOpInQueue *queue);
};

struct DSPEOpOutQueue {
	DSPEElement element;

	void (*reset) (DSPEOpOutQueue *outQueue);
	void (*dispose) (DSPEOpOutQueue *outQueue);
};

// COPROC SUPPORT

struct DSPECoprocEvent {	
	DSPEEvent event;
	DSPEOp *op;
};

struct DSPECoprocUnit {
	DSPEQueueUnit queueUnit;

	DSPEOpInQueue* (*getCoprocQueue) (DSPECoprocUnit *unit);
	void (*queueOp) (DSPECoprocUnit *unit, DSPEOp *op);
	int (*isCoprocFull) (DSPECoprocUnit *unit);
	void (*initOp) (DSPECoprocUnit *unit, DSPEOp *op);
	DSPEOp* (*getOpPoolHead) (DSPECoprocUnit *unit);
	DSPEOp* (*getOpFromPool) (DSPECoprocUnit *unit);
	void (*addOpToPool) (DSPECoprocUnit *unit, DSPEOp *op);
	DSPEOp* (*getEmptyOp) (DSPECoprocUnit *unit);
	DSPEOp* (*getBufferedOp) (DSPECoprocUnit *unit);
	DSPEOp* (*getNextOp) (DSPECoprocUnit *unit);
	void (*releaseOp) (DSPECoprocUnit *unit, DSPEOp *op);
};

struct DSPECoprocConfig {
	DSPEConfiguration config;
};

struct DSPECoprocScheduler {
	DSPEScheduler scheduler;
	
	void (*addQueueToPool) (const DSPEElement *element, DSPECoprocScheduler *scheduler, DSPEOpOutQueue *queue);
};

struct DSPECoprocImplementation {
	DSPEElement element;
};


// INITIALIZATION FUNCTIONS

static INLINE void initDSPECoprocUnit(DSPECoprocUnit *unit) {
	initDSPEQueueUnit((DSPEQueueUnit*) unit);
	unit->getCoprocQueue = NULL;
	unit->queueOp = NULL;
	unit->isCoprocFull = NULL;
	unit->initOp = NULL;
	// OpPool support
	unit->getOpPoolHead = NULL;
	unit->getOpFromPool = NULL;
	unit->addOpToPool = NULL;
	// OpBuffer support
	unit->getEmptyOp = NULL;
	unit->getBufferedOp = NULL;
	unit->getNextOp = NULL;
	unit->releaseOp = NULL;
}

static INLINE void initDSPECoprocScheduler(DSPECoprocScheduler *scheduler) {
	scheduler->addQueueToPool = NULL;
}

static INLINE void initDSPECoprocConfig(DSPECoprocConfig *config) {
}
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
