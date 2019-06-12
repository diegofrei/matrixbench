/**
 * File: MicroBenchTime_StandardGate.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MicroBenchTime_StandardGate_h
#define MicroBenchTime_StandardGate_h

#include "DSPEElements.h"

#define MICROBENCHTIME_STANDARDGATE_TYPECATEGORY "Standard"
#define MICROBENCHTIME_STANDARDGATE_DEFAULTVALUE 0.0
#define MICROBENCHTIME_STANDARDGATE_QUALIFIER "Seconds"
typedef double MicroBenchTime_StandardGate;

/* StandardGate node type definition */
typedef struct MicroBenchTime_StandardGate_node MicroBenchTime_StandardGate_node; 

/* StandardGate node definition */ 
struct MicroBenchTime_StandardGate_node {
	DSPEGateNode node;
	
	MicroBenchTime_StandardGate *gate;
	MicroBenchTime_StandardGate *localVar;
	MicroBenchTime_StandardGate value;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MicroBenchTime_StandardGate* MicroBenchTime_StandardGate_allocate(DSPEElement *context);

/* Initialise function */
void MicroBenchTime_StandardGate_initialize(DSPEElement *context, MicroBenchTime_StandardGate *place);

/* SetOverride function */
void MicroBenchTime_StandardGate_setOverride(DSPEElement *context, MicroBenchTime_StandardGate *place, MicroBenchTime_StandardGate value);

/* Set function */
void MicroBenchTime_StandardGate_set(DSPEElement *context, MicroBenchTime_StandardGate *place, MicroBenchTime_StandardGate *value);

/* Dispose function */
void MicroBenchTime_StandardGate_dispose(DSPEElement *context, MicroBenchTime_StandardGate *place);

/* AllocateGroup function */
void MicroBenchTime_StandardGate_allocateGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size);

/* InitialiseGroup function */
void MicroBenchTime_StandardGate_initializeGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size);

/* SetOverrideGroup function */
void MicroBenchTime_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size, MicroBenchTime_StandardGate value);

/* SetGroup function */
void MicroBenchTime_StandardGate_setGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size, MicroBenchTime_StandardGate **value);

/* DisposeGroup function */
void MicroBenchTime_StandardGate_disposeGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size);

/* CreateNode function */
MicroBenchTime_StandardGate_node* MicroBenchTime_StandardGate_createNode(DSPEElement *context, MicroBenchTime_StandardGate *gate, MicroBenchTime_StandardGate *localVar);

/* DisposeNode function */
void MicroBenchTime_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MicroBenchTime_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchTime_StandardGate* MicroBenchTime_StandardGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MicroBenchTime_StandardGate_initializeBlock(DSPEElement *context, MicroBenchTime_StandardGate *place, size_t size);

/* SetOverrideBlock function */
void MicroBenchTime_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchTime_StandardGate *place, size_t size, MicroBenchTime_StandardGate value);

/* SetBlock function */
void MicroBenchTime_StandardGate_setBlock(DSPEElement *context, MicroBenchTime_StandardGate *place, size_t size, MicroBenchTime_StandardGate *value);

/* Dispose function */
void MicroBenchTime_StandardGate_disposeBlock(DSPEElement *context, MicroBenchTime_StandardGate *place);

/* AllocateGroup function */
void MicroBenchTime_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MicroBenchTime_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MicroBenchTime_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchTime_StandardGate value);

/* SetGroupBlock function */
void MicroBenchTime_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchTime_StandardGate **value);

/* DisposeGroup function */
void MicroBenchTime_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
