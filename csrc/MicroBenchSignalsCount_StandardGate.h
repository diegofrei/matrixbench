/**
 * File: MicroBenchSignalsCount_StandardGate.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MicroBenchSignalsCount_StandardGate_h
#define MicroBenchSignalsCount_StandardGate_h

#include "DSPEElements.h"

#define MICROBENCHSIGNALSCOUNT_STANDARDGATE_TYPECATEGORY "Standard"
#define MICROBENCHSIGNALSCOUNT_STANDARDGATE_DEFAULTVALUE 0L
#define MICROBENCHSIGNALSCOUNT_STANDARDGATE_QUALIFIER "Signals"
typedef unsigned long int MicroBenchSignalsCount_StandardGate;

/* StandardGate node type definition */
typedef struct MicroBenchSignalsCount_StandardGate_node MicroBenchSignalsCount_StandardGate_node; 

/* StandardGate node definition */ 
struct MicroBenchSignalsCount_StandardGate_node {
	DSPEGateNode node;
	
	MicroBenchSignalsCount_StandardGate *gate;
	MicroBenchSignalsCount_StandardGate *localVar;
	MicroBenchSignalsCount_StandardGate value;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MicroBenchSignalsCount_StandardGate* MicroBenchSignalsCount_StandardGate_allocate(DSPEElement *context);

/* Initialise function */
void MicroBenchSignalsCount_StandardGate_initialize(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place);

/* SetOverride function */
void MicroBenchSignalsCount_StandardGate_setOverride(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, MicroBenchSignalsCount_StandardGate value);

/* Set function */
void MicroBenchSignalsCount_StandardGate_set(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, MicroBenchSignalsCount_StandardGate *value);

/* Dispose function */
void MicroBenchSignalsCount_StandardGate_dispose(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place);

/* AllocateGroup function */
void MicroBenchSignalsCount_StandardGate_allocateGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size);

/* InitialiseGroup function */
void MicroBenchSignalsCount_StandardGate_initializeGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size);

/* SetOverrideGroup function */
void MicroBenchSignalsCount_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size, MicroBenchSignalsCount_StandardGate value);

/* SetGroup function */
void MicroBenchSignalsCount_StandardGate_setGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size, MicroBenchSignalsCount_StandardGate **value);

/* DisposeGroup function */
void MicroBenchSignalsCount_StandardGate_disposeGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size);

/* CreateNode function */
MicroBenchSignalsCount_StandardGate_node* MicroBenchSignalsCount_StandardGate_createNode(DSPEElement *context, MicroBenchSignalsCount_StandardGate *gate, MicroBenchSignalsCount_StandardGate *localVar);

/* DisposeNode function */
void MicroBenchSignalsCount_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MicroBenchSignalsCount_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchSignalsCount_StandardGate* MicroBenchSignalsCount_StandardGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MicroBenchSignalsCount_StandardGate_initializeBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, size_t size);

/* SetOverrideBlock function */
void MicroBenchSignalsCount_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, size_t size, MicroBenchSignalsCount_StandardGate value);

/* SetBlock function */
void MicroBenchSignalsCount_StandardGate_setBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, size_t size, MicroBenchSignalsCount_StandardGate *value);

/* Dispose function */
void MicroBenchSignalsCount_StandardGate_disposeBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place);

/* AllocateGroup function */
void MicroBenchSignalsCount_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MicroBenchSignalsCount_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MicroBenchSignalsCount_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSignalsCount_StandardGate value);

/* SetGroupBlock function */
void MicroBenchSignalsCount_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSignalsCount_StandardGate **value);

/* DisposeGroup function */
void MicroBenchSignalsCount_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
