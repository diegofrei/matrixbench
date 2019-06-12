/**
 * File: DSPEObjects.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#ifndef DSPEObjects_h
#define DSPEObjects_h

#include "DSPEElements.h"

#ifdef __cplusplus

// BASE OBJECTS

class DSPEObject : public DSPEElement {
public:
	DSPEObject() {};
	virtual ~DSPEObject() {};
};

class DSPEImplementationObject : public DSPEObject {
public:
	DSPEImplementationObject() {};
	virtual ~DSPEImplementationObject() {};
	
	// phases
	virtual void preProcess() = 0;
	virtual void process() = 0;
	virtual void postProcess() = 0;
};

class DSPERunnerBehaviourObject : public DSPEObject {
public:
	DSPERunnerBehaviourObject() {};
	virtual ~DSPERunnerBehaviourObject() {};
};

#endif /* __cplusplus */
#endif
