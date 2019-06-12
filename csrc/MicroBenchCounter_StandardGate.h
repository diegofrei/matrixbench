/**
 * File: MicroBenchCounter_StandardGate.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MicroBenchCounter_StandardGate_h
#define MicroBenchCounter_StandardGate_h

#include "DSPEElements.h"

#define MICROBENCHCOUNTER_STANDARDGATE_TYPECATEGORY "Standard"
#define MICROBENCHCOUNTER_STANDARDGATE_DEFAULTVALUE 0L
#define MICROBENCHCOUNTER_STANDARDGATE_QUALIFIER "Samples"
typedef long int MicroBenchCounter_StandardGate;

/* StandardGate node type definition */
typedef struct MicroBenchCounter_StandardGate_node MicroBenchCounter_StandardGate_node; 

/* StandardGate node definition */ 
struct MicroBenchCounter_StandardGate_node {
	DSPEGateNode node;
	
	MicroBenchCounter_StandardGate *gate;
	MicroBenchCounter_StandardGate *localVar;
	MicroBenchCounter_StandardGate value;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MicroBenchCounter_StandardGate* MicroBenchCounter_StandardGate_allocate(DSPEElement *context);

/* Initialise function */
void MicroBenchCounter_StandardGate_initialize(DSPEElement *context, MicroBenchCounter_StandardGate *place);

/* SetOverride function */
void MicroBenchCounter_StandardGate_setOverride(DSPEElement *context, MicroBenchCounter_StandardGate *place, MicroBenchCounter_StandardGate value);

/* Set function */
void MicroBenchCounter_StandardGate_set(DSPEElement *context, MicroBenchCounter_StandardGate *place, MicroBenchCounter_StandardGate *value);

/* Dispose function */
void MicroBenchCounter_StandardGate_dispose(DSPEElement *context, MicroBenchCounter_StandardGate *place);

/* AllocateGroup function */
void MicroBenchCounter_StandardGate_allocateGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size);

/* InitialiseGroup function */
void MicroBenchCounter_StandardGate_initializeGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size);

/* SetOverrideGroup function */
void MicroBenchCounter_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size, MicroBenchCounter_StandardGate value);

/* SetGroup function */
void MicroBenchCounter_StandardGate_setGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size, MicroBenchCounter_StandardGate **value);

/* DisposeGroup function */
void MicroBenchCounter_StandardGate_disposeGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size);

/* CreateNode function */
MicroBenchCounter_StandardGate_node* MicroBenchCounter_StandardGate_createNode(DSPEElement *context, MicroBenchCounter_StandardGate *gate, MicroBenchCounter_StandardGate *localVar);

/* DisposeNode function */
void MicroBenchCounter_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MicroBenchCounter_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchCounter_StandardGate* MicroBenchCounter_StandardGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MicroBenchCounter_StandardGate_initializeBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place, size_t size);

/* SetOverrideBlock function */
void MicroBenchCounter_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place, size_t size, MicroBenchCounter_StandardGate value);

/* SetBlock function */
void MicroBenchCounter_StandardGate_setBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place, size_t size, MicroBenchCounter_StandardGate *value);

/* Dispose function */
void MicroBenchCounter_StandardGate_disposeBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place);

/* AllocateGroup function */
void MicroBenchCounter_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MicroBenchCounter_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MicroBenchCounter_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchCounter_StandardGate value);

/* SetGroupBlock function */
void MicroBenchCounter_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchCounter_StandardGate **value);

/* DisposeGroup function */
void MicroBenchCounter_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
