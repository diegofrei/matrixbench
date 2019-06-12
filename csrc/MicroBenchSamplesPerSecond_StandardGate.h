/**
 * File: MicroBenchSamplesPerSecond_StandardGate.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MicroBenchSamplesPerSecond_StandardGate_h
#define MicroBenchSamplesPerSecond_StandardGate_h

#include "DSPEElements.h"

#define MICROBENCHSAMPLESPERSECOND_STANDARDGATE_TYPECATEGORY "Standard"
#define MICROBENCHSAMPLESPERSECOND_STANDARDGATE_DEFAULTVALUE 0.0
#define MICROBENCHSAMPLESPERSECOND_STANDARDGATE_QUALIFIER "SamplesPerSecond"
typedef double MicroBenchSamplesPerSecond_StandardGate;

/* StandardGate node type definition */
typedef struct MicroBenchSamplesPerSecond_StandardGate_node MicroBenchSamplesPerSecond_StandardGate_node; 

/* StandardGate node definition */ 
struct MicroBenchSamplesPerSecond_StandardGate_node {
	DSPEGateNode node;
	
	MicroBenchSamplesPerSecond_StandardGate *gate;
	MicroBenchSamplesPerSecond_StandardGate *localVar;
	MicroBenchSamplesPerSecond_StandardGate value;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MicroBenchSamplesPerSecond_StandardGate* MicroBenchSamplesPerSecond_StandardGate_allocate(DSPEElement *context);

/* Initialise function */
void MicroBenchSamplesPerSecond_StandardGate_initialize(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place);

/* SetOverride function */
void MicroBenchSamplesPerSecond_StandardGate_setOverride(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, MicroBenchSamplesPerSecond_StandardGate value);

/* Set function */
void MicroBenchSamplesPerSecond_StandardGate_set(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, MicroBenchSamplesPerSecond_StandardGate *value);

/* Dispose function */
void MicroBenchSamplesPerSecond_StandardGate_dispose(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place);

/* AllocateGroup function */
void MicroBenchSamplesPerSecond_StandardGate_allocateGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size);

/* InitialiseGroup function */
void MicroBenchSamplesPerSecond_StandardGate_initializeGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size);

/* SetOverrideGroup function */
void MicroBenchSamplesPerSecond_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size, MicroBenchSamplesPerSecond_StandardGate value);

/* SetGroup function */
void MicroBenchSamplesPerSecond_StandardGate_setGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size, MicroBenchSamplesPerSecond_StandardGate **value);

/* DisposeGroup function */
void MicroBenchSamplesPerSecond_StandardGate_disposeGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size);

/* CreateNode function */
MicroBenchSamplesPerSecond_StandardGate_node* MicroBenchSamplesPerSecond_StandardGate_createNode(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *gate, MicroBenchSamplesPerSecond_StandardGate *localVar);

/* DisposeNode function */
void MicroBenchSamplesPerSecond_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MicroBenchSamplesPerSecond_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchSamplesPerSecond_StandardGate* MicroBenchSamplesPerSecond_StandardGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MicroBenchSamplesPerSecond_StandardGate_initializeBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, size_t size);

/* SetOverrideBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, size_t size, MicroBenchSamplesPerSecond_StandardGate value);

/* SetBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, size_t size, MicroBenchSamplesPerSecond_StandardGate *value);

/* Dispose function */
void MicroBenchSamplesPerSecond_StandardGate_disposeBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place);

/* AllocateGroup function */
void MicroBenchSamplesPerSecond_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MicroBenchSamplesPerSecond_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSamplesPerSecond_StandardGate value);

/* SetGroupBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSamplesPerSecond_StandardGate **value);

/* DisposeGroup function */
void MicroBenchSamplesPerSecond_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
