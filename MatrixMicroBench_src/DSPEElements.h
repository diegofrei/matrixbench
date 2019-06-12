/**
 * File: DSPEElements.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef DSPEElements_h
#define DSPEElements_h

#include "PlatformManager.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Conversion defines */
#define CAST_TO_EXTENSION(element, extension) &element->extension
#define CAST_TO_ELEMENT(extension) ((DSPEExtension*) extension)->root

// BASE

typedef struct DSPEElement DSPEElement;

typedef struct DSPEExtension DSPEExtension;

typedef struct DSPEOwner DSPEOwner;

typedef struct DSPEComponent DSPEComponent;

// DSPE

typedef struct DSPEUnit DSPEUnit;

typedef struct DSPEStructure DSPEStructure;

typedef struct DSPEConfiguration DSPEConfiguration;

typedef struct DSPERunnerDelegate DSPERunnerDelegate;

typedef struct DSPEApplication DSPEApplication;

typedef struct DSPEImplementation DSPEImplementation;

typedef struct DSPERunnerBehaviour DSPERunnerBehaviour;

// CRITICAL SECTION SUPPORT

typedef struct DSPEGateNode DSPEGateNode;

// EVENTS SUPPORT

typedef struct DSPEEvent DSPEEvent;

typedef struct DSPEGroupEvent DSPEGroupEvent;

typedef struct DSPEEventsUnit DSPEEventsUnit;

typedef struct DSPEQueueUnit DSPEQueueUnit;

typedef struct DSPEEventsApplication DSPEEventsApplication;

// HANDLER SUPPORT

typedef struct DSPEHandler DSPEHandler;

// EVENTS POOL SUPPORT

typedef struct DSPEEventsPool DSPEEventsPool;

// PROFILE SUPPORT

typedef struct DSPEProfileNode DSPEProfileNode;

// SNAPSHOT SUPPORT

typedef struct DSPESnapshot DSPESnapshot;

// BASE

/* Common struct for all DSPE elements */
struct DSPEElement {
	const DSPEElement *container;
	DSPEApplication *application;
	const DSPEOwner *owner;

	char* (*getID) (const DSPEElement *element);
	void (*snapshot) (DSPEElement *element, DSPESnapshot *snapshot);
};

struct DSPEExtension {
	const DSPEElement *root;
};

/* Conversion support defines */ 
#define OWNER_EXT DSPEOwner ownerExt
#define CAST_TO_OWNER(element) &(element)->ownerExt

struct DSPEOwner {
	DSPEExtension extension;

	DSPEHandler **handlers;
	DSPEProfileNode **profileQueue;
};

/* Common struct for elements like Unit, Composite or Application, that may e.g. be scheduled */
struct DSPEComponent {
	DSPEElement element;

	void (*preprocess) (DSPEComponent *component);
	int (*canExecute) (DSPEComponent *component);
	void (*process) (DSPEComponent *component);
	void (*postprocess) (DSPEComponent *component);
	void (*setBypass) (DSPEComponent *component, int bypass);
};

// DSPE

struct DSPEUnit {
	DSPEComponent component;
};

struct DSPEStructure {
	DSPEElement element;
};

struct DSPEConfiguration {
	DSPEStructure structure;
};

struct DSPERunnerDelegate {
	DSPEElement element;
	OWNER_EXT;
};

struct DSPEApplication {
	DSPEComponent component;
	OWNER_EXT;

	void (*startup) (DSPEApplication *application);
	void (*shutdown) (DSPEApplication *application);
};

struct DSPEImplementation {
	DSPEElement element;
};

struct DSPERunnerBehaviour {
	DSPEElement element;
};

// CRITICAL SECTION SUPPORT

struct DSPEGateNode {
	DSPEGateNode *next;

	int isInQueue;

	void (*setValue) (DSPEElement *context, DSPEGateNode *node);
	void (*disposeNode) (DSPEElement *context, DSPEGateNode *node);
	void (*updateRep) (DSPEElement *element);
};

// EVENTS SUPPORT

struct DSPEEvent {
	unsigned int refCount;

	size_t blockSize;
	
	DSPEEvent *next;
	DSPEEventsPool *pool;

	DSPEEvent* (*clone) (DSPEEvent *event);
	void (*dispose) (DSPEEvent *event);
};

struct DSPEGroupEvent {
	DSPEEvent event;

	size_t groupSize;
};

struct DSPEEventsUnit {
	DSPEUnit unit;

	void (*queueEvent) (DSPEEventsUnit *unit, DSPEEvent *event, unsigned int ID);
	void (*sendEvent) (DSPEEventsUnit *unit, DSPEEvent *event, unsigned int ID);
	void (*armEvent) (DSPEEventsUnit *unit, unsigned int ID);
	void (*postEvent) (DSPEEventsUnit *unit, unsigned int ID);

	DSPEEvent* (*getConsumeEvent) (DSPEEventsUnit *unit);
	void (*processConsume) (DSPEEventsUnit *unit);
};

struct DSPEQueueUnit {
	DSPEEventsUnit eventsUnit;

	int (*isEventAvailable) (const DSPEQueueUnit *unit);
	unsigned int (*getEventID) (const DSPEQueueUnit *unit);
	DSPEEvent* (*getEvent) (const DSPEQueueUnit *unit);
	void (*transitEvent) (DSPEQueueUnit *unit);
	size_t (*getTransitNumElements) (DSPEQueueUnit *unit, unsigned int ID);
	void (*getFirstTransitEvent) (DSPEQueueUnit *unit, unsigned int ID);
	size_t (*getCurrentNumElements) (DSPEQueueUnit *unit, unsigned int ID);
	void (*getCurrentTransitEvent) (DSPEQueueUnit *unit, unsigned int ID);
	void (*dismissEvent) (DSPEQueueUnit *unit, unsigned int ID);
};

struct DSPEEventsApplication {
	DSPEApplication application;

	void (*queueEvent) (DSPEEventsApplication *application, DSPEEvent *event, unsigned int ID);
	void (*sendEvent) (DSPEEventsApplication *application, DSPEEvent *event, unsigned int ID);
};

// HANDLER SUPPORT

struct DSPEHandler {
	DSPEElement element;
	
	void (*reset) (DSPEHandler *handler);
	void (*dispose) (DSPEHandler *handler);
};

// EVENTS POOL SUPPORT (Concrete structs moved to MemoryManager)

struct DSPEEventsPool {
	DSPEElement element;

	void *gateDefID;
	DSPEEventsPool *next;
	
	void (*preAlloc) (DSPEEventsPool *pool, size_t size);
	void (*reset) (DSPEEventsPool *pool);
	void (*dispose) (DSPEEventsPool *event);
};

// PROFILE SUPPORT

struct DSPEProfileNode {
	size_t id;
};

// SNAPSHOT SUPPORT

struct DSPESnapshot {
	DSPESnapshot *header;
	DSPESnapshot *next;

	void (*addRunnerTAG) (DSPESnapshot *snap);
	void (*addStructTAG) (DSPESnapshot *snap);
	void (*addUnitTAG) (DSPESnapshot *snap);
	void (*addImplementationTAG) (DSPESnapshot *snap);

	// Function pointers for dumping data to snapshot
	void (*addPointer) (DSPESnapshot *snap, void *ptr);
	void (*addString) (DSPESnapshot *snap, char *string);

	void (*addUChar) (DSPESnapshot *snap, unsigned char value);
	void (*addUCharArray) (DSPESnapshot *snap, unsigned char *array, size_t size);

	void (*addChar) (DSPESnapshot *snap, char value);
	void (*addCharArray) (DSPESnapshot *snap, char *array, size_t size);

	void (*addUInt) (DSPESnapshot *snap, unsigned int value);
	void (*addUIntArray) (DSPESnapshot *snap, unsigned int *array, size_t size);

	void (*addShort) (DSPESnapshot *snap, short value);
	void (*addShortArray) (DSPESnapshot *snap, short *array, size_t size);

	void (*addUShort) (DSPESnapshot *snap, unsigned short value);
	void (*addUShortArray) (DSPESnapshot *snap, unsigned short *array, size_t size);

	void (*addInt) (DSPESnapshot *snap, int value);
	void (*addIntArray) (DSPESnapshot *snap, int *array, size_t size);

	void (*addLong) (DSPESnapshot *snap, long value);
	void (*addLongArray) (DSPESnapshot *snap, long *array, size_t size);

	void (*addULong) (DSPESnapshot *snap, unsigned long value);
	void (*addULongArray) (DSPESnapshot *snap, unsigned long *array, size_t size);

	void (*addLongLong) (DSPESnapshot *snap, long long value);
	void (*addLongLongArray) (DSPESnapshot *snap, long long *array, size_t size);

	void (*addULongLong) (DSPESnapshot *snap, unsigned long long value);
	void (*addULongLongArray) (DSPESnapshot *snap, unsigned long long *array, size_t size);

	void (*addFloat) (DSPESnapshot *snap, float value);
	void (*addFloatArray) (DSPESnapshot *snap, float *array, size_t size);

	void (*addDouble) (DSPESnapshot *snap, double value);
	void (*addDoubleArray) (DSPESnapshot *snap, double *array, size_t size);

	void (*addLongDouble) (DSPESnapshot *snap, long double value);
	void (*addLongDoubleArray) (DSPESnapshot *snap, long double *array, size_t size);
	
	void (*dispose) (DSPESnapshot *snap);
};

// INITIALIZATION FUNCTIONS

static char* getID(const DSPEElement *element) {
	return element->container->getID(element->container);
}

static INLINE void initDSPEElement(DSPEElement *element, const DSPEElement *container) {
	element->container = container;
	element->application = container->application;
	element->owner = container->owner;
	element->getID = getID;
	element->snapshot = NULL;
}


static INLINE void initDSPEExtension(DSPEExtension *extension, DSPEElement *root) {
	extension->root = root;
}

static INLINE void initDSPEOwner(DSPEOwner *ownerExt, DSPEElement *root) {
	initDSPEExtension((DSPEExtension*) ownerExt, root);
	ownerExt->handlers = NULL;
	ownerExt->profileQueue = NULL;
}

static INLINE void initDSPERunnerDelegate(DSPERunnerDelegate *delegate, DSPEApplication *application) {
	((DSPEElement*) delegate)->container = NULL;
	((DSPEElement*) delegate)->application = application;
	((DSPEElement*) delegate)->owner = CAST_TO_OWNER(delegate);
	((DSPEElement*) delegate)->getID = NULL;
	initDSPEOwner(CAST_TO_OWNER(delegate), (DSPEElement*) delegate);
}

// Default implementation
static int canExecute(DSPEComponent *component) {
	return 1;
}

static INLINE void initDSPEComponent(DSPEComponent *component) {
	component->preprocess = NULL;
	component->canExecute = canExecute;
	component->process = NULL;
	component->postprocess = NULL;
	component->setBypass = NULL;
}

static INLINE void initDSPEHandler(DSPEHandler *handler, const DSPEElement *container) {
	initDSPEElement((DSPEElement*) handler, container);
	handler->reset = NULL;
	handler->dispose = NULL;
}

static INLINE void initDSPEEventsUnit(DSPEEventsUnit *unit) {
	initDSPEComponent((DSPEComponent*) unit);
	unit->queueEvent = NULL;
	unit->sendEvent = NULL;
	unit->armEvent = NULL;
	unit->postEvent = NULL;
	unit->getConsumeEvent = NULL;
	unit->processConsume = NULL;
}

static INLINE void initDSPEQueueUnit(DSPEQueueUnit *unit) {
	initDSPEEventsUnit((DSPEEventsUnit*) unit);
	unit->isEventAvailable = NULL;
	unit->getEventID = NULL;
	unit->getEvent = NULL;
	unit->transitEvent = NULL;
	unit->getTransitNumElements = NULL;
	unit->getFirstTransitEvent = NULL;
	unit->getCurrentNumElements = NULL;
	unit->getCurrentTransitEvent = NULL;
	unit->dismissEvent = NULL;
}

static INLINE void initDSPEApplication(DSPEApplication *application) {
	((DSPEElement*) application)->container = NULL;
	((DSPEElement*) application)->application = application;
	((DSPEElement*) application)->owner = &application->ownerExt;
	((DSPEElement*) application)->getID = NULL;
	((DSPEApplication*) application)->startup = NULL;
	((DSPEApplication*) application)->shutdown = NULL;

	initDSPEComponent((DSPEComponent*) application);
	initDSPEOwner(&application->ownerExt, (DSPEElement*) application);
}

static INLINE void initDSPEEventsApplication(DSPEEventsApplication *application) {
	initDSPEApplication((DSPEApplication*) application);
	application->queueEvent = NULL;
	application->sendEvent = NULL;
}

static INLINE void initDSPEEvent(DSPEEvent *event) {
	event->refCount = 0;
	event->blockSize = 1;
	event->next = NULL;
	event->pool = NULL;
	event->clone = NULL;
	event->dispose = NULL;
}

static INLINE void initDSPEGroupEvent(DSPEGroupEvent *event) {
 	initDSPEEvent((DSPEEvent*) event);
 	event->groupSize = 0;
}

static INLINE void initDSPEEventsPool(DSPEEventsPool *pool) {
	pool->gateDefID = NULL;
	pool->next = NULL;
	pool->preAlloc = NULL;
	pool->reset = NULL;
	pool->dispose = NULL;
}

static INLINE void initDSPEGateNode(DSPEGateNode *node) {
	node->next = NULL;
	node->isInQueue = 0;
	node->setValue = NULL;
	node->disposeNode = NULL;
	node->updateRep = NULL;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
