/**
 * File: MicroBenchNumSamples_StandardGate.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MicroBenchNumSamples_StandardGate_h
#define MicroBenchNumSamples_StandardGate_h

#include "DSPEElements.h"

#define MICROBENCHNUMSAMPLES_STANDARDGATE_TYPECATEGORY "Standard"
#define MICROBENCHNUMSAMPLES_STANDARDGATE_DEFAULTVALUE 0L
#define MICROBENCHNUMSAMPLES_STANDARDGATE_QUALIFIER "Samples"
typedef long int MicroBenchNumSamples_StandardGate;

/* StandardGate node type definition */
typedef struct MicroBenchNumSamples_StandardGate_node MicroBenchNumSamples_StandardGate_node; 

/* StandardGate node definition */ 
struct MicroBenchNumSamples_StandardGate_node {
	DSPEGateNode node;
	
	MicroBenchNumSamples_StandardGate *gate;
	MicroBenchNumSamples_StandardGate *localVar;
	MicroBenchNumSamples_StandardGate value;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MicroBenchNumSamples_StandardGate* MicroBenchNumSamples_StandardGate_allocate(DSPEElement *context);

/* Initialise function */
void MicroBenchNumSamples_StandardGate_initialize(DSPEElement *context, MicroBenchNumSamples_StandardGate *place);

/* SetOverride function */
void MicroBenchNumSamples_StandardGate_setOverride(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, MicroBenchNumSamples_StandardGate value);

/* Set function */
void MicroBenchNumSamples_StandardGate_set(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, MicroBenchNumSamples_StandardGate *value);

/* Dispose function */
void MicroBenchNumSamples_StandardGate_dispose(DSPEElement *context, MicroBenchNumSamples_StandardGate *place);

/* AllocateGroup function */
void MicroBenchNumSamples_StandardGate_allocateGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size);

/* InitialiseGroup function */
void MicroBenchNumSamples_StandardGate_initializeGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size);

/* SetOverrideGroup function */
void MicroBenchNumSamples_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size, MicroBenchNumSamples_StandardGate value);

/* SetGroup function */
void MicroBenchNumSamples_StandardGate_setGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size, MicroBenchNumSamples_StandardGate **value);

/* DisposeGroup function */
void MicroBenchNumSamples_StandardGate_disposeGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size);

/* CreateNode function */
MicroBenchNumSamples_StandardGate_node* MicroBenchNumSamples_StandardGate_createNode(DSPEElement *context, MicroBenchNumSamples_StandardGate *gate, MicroBenchNumSamples_StandardGate *localVar);

/* DisposeNode function */
void MicroBenchNumSamples_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MicroBenchNumSamples_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchNumSamples_StandardGate* MicroBenchNumSamples_StandardGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MicroBenchNumSamples_StandardGate_initializeBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, size_t size);

/* SetOverrideBlock function */
void MicroBenchNumSamples_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, size_t size, MicroBenchNumSamples_StandardGate value);

/* SetBlock function */
void MicroBenchNumSamples_StandardGate_setBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, size_t size, MicroBenchNumSamples_StandardGate *value);

/* Dispose function */
void MicroBenchNumSamples_StandardGate_disposeBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place);

/* AllocateGroup function */
void MicroBenchNumSamples_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MicroBenchNumSamples_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MicroBenchNumSamples_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchNumSamples_StandardGate value);

/* SetGroupBlock function */
void MicroBenchNumSamples_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchNumSamples_StandardGate **value);

/* DisposeGroup function */
void MicroBenchNumSamples_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
