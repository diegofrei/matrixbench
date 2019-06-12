/**
 * File: MicroBenchFlag_StandardGate.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#ifndef MicroBenchFlag_StandardGate_h
#define MicroBenchFlag_StandardGate_h

#include "DSPEElements.h"

#define MICROBENCHFLAG_STANDARDGATE_TYPECATEGORY "Standard"
#define MICROBENCHFLAG_STANDARDGATE_DEFAULTVALUE 0
#define MICROBENCHFLAG_STANDARDGATE_POSSIBLEVALUE0 0
#define MICROBENCHFLAG_STANDARDGATE_POSSIBLEVALUE1 1
typedef int MicroBenchFlag_StandardGate;

/* StandardGate node type definition */
typedef struct MicroBenchFlag_StandardGate_node MicroBenchFlag_StandardGate_node; 

/* StandardGate node definition */ 
struct MicroBenchFlag_StandardGate_node {
	DSPEGateNode node;
	
	MicroBenchFlag_StandardGate *gate;
	MicroBenchFlag_StandardGate *localVar;
	MicroBenchFlag_StandardGate value;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MicroBenchFlag_StandardGate* MicroBenchFlag_StandardGate_allocate(DSPEElement *context);

/* Initialise function */
void MicroBenchFlag_StandardGate_initialize(DSPEElement *context, MicroBenchFlag_StandardGate *place);

/* SetOverride function */
void MicroBenchFlag_StandardGate_setOverride(DSPEElement *context, MicroBenchFlag_StandardGate *place, MicroBenchFlag_StandardGate value);

/* Set function */
void MicroBenchFlag_StandardGate_set(DSPEElement *context, MicroBenchFlag_StandardGate *place, MicroBenchFlag_StandardGate *value);

/* Dispose function */
void MicroBenchFlag_StandardGate_dispose(DSPEElement *context, MicroBenchFlag_StandardGate *place);

/* AllocateGroup function */
void MicroBenchFlag_StandardGate_allocateGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size);

/* InitialiseGroup function */
void MicroBenchFlag_StandardGate_initializeGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size);

/* SetOverrideGroup function */
void MicroBenchFlag_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size, MicroBenchFlag_StandardGate value);

/* SetGroup function */
void MicroBenchFlag_StandardGate_setGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size, MicroBenchFlag_StandardGate **value);

/* DisposeGroup function */
void MicroBenchFlag_StandardGate_disposeGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size);

/* CreateNode function */
MicroBenchFlag_StandardGate_node* MicroBenchFlag_StandardGate_createNode(DSPEElement *context, MicroBenchFlag_StandardGate *gate, MicroBenchFlag_StandardGate *localVar);

/* DisposeNode function */
void MicroBenchFlag_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MicroBenchFlag_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchFlag_StandardGate* MicroBenchFlag_StandardGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MicroBenchFlag_StandardGate_initializeBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place, size_t size);

/* SetOverrideBlock function */
void MicroBenchFlag_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place, size_t size, MicroBenchFlag_StandardGate value);

/* SetBlock function */
void MicroBenchFlag_StandardGate_setBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place, size_t size, MicroBenchFlag_StandardGate *value);

/* Dispose function */
void MicroBenchFlag_StandardGate_disposeBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place);

/* AllocateGroup function */
void MicroBenchFlag_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MicroBenchFlag_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MicroBenchFlag_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchFlag_StandardGate value);

/* SetGroupBlock function */
void MicroBenchFlag_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchFlag_StandardGate **value);

/* DisposeGroup function */
void MicroBenchFlag_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
