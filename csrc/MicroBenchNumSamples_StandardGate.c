/**
 * File: MicroBenchNumSamples_StandardGate.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "MemoryManager.h"

#include "MicroBenchNumSamples_StandardGate.h"

/* Allocate function */
MicroBenchNumSamples_StandardGate* MicroBenchNumSamples_StandardGate_allocate(DSPEElement *context) {
	return (MicroBenchNumSamples_StandardGate*) memoryManager_allocate(context, sizeof(MicroBenchNumSamples_StandardGate));
}

/* Initialise function */
void MicroBenchNumSamples_StandardGate_initialize(DSPEElement *context, MicroBenchNumSamples_StandardGate *place) {
	*place = MICROBENCHNUMSAMPLES_STANDARDGATE_DEFAULTVALUE;
}

/* Set function */
void MicroBenchNumSamples_StandardGate_setOverride(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, MicroBenchNumSamples_StandardGate value) {
	*place = value;
}

/* Set function */
void MicroBenchNumSamples_StandardGate_set(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, MicroBenchNumSamples_StandardGate *value) {
	*place = *value;
}

/* Dispose function */
void MicroBenchNumSamples_StandardGate_dispose(DSPEElement *context, MicroBenchNumSamples_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchNumSamples_StandardGate_allocateGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MicroBenchNumSamples_StandardGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MicroBenchNumSamples_StandardGate_initializeGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MicroBenchNumSamples_StandardGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MicroBenchNumSamples_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size, MicroBenchNumSamples_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchNumSamples_StandardGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MicroBenchNumSamples_StandardGate_setGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size, MicroBenchNumSamples_StandardGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchNumSamples_StandardGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchNumSamples_StandardGate_disposeGroup(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MicroBenchNumSamples_StandardGate_node* MicroBenchNumSamples_StandardGate_createNode(DSPEElement *context, MicroBenchNumSamples_StandardGate *gate, MicroBenchNumSamples_StandardGate *localVar) {
	MicroBenchNumSamples_StandardGate_node *node = (MicroBenchNumSamples_StandardGate_node*) memoryManager_allocate(context, sizeof(MicroBenchNumSamples_StandardGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	node->localVar = localVar;
	((DSPEGateNode*) node)->setValue = MicroBenchNumSamples_StandardGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MicroBenchNumSamples_StandardGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MicroBenchNumSamples_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	node->next = NULL;
	memorySupport_dispose(node);
}

/* SetValue function */
void MicroBenchNumSamples_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node) {
	MicroBenchNumSamples_StandardGate_node *tmpNode = (MicroBenchNumSamples_StandardGate_node*) node;
	if (tmpNode->gate != 0)
		*tmpNode->gate = tmpNode->value;
	if (tmpNode->localVar != 0)
		*tmpNode->localVar = tmpNode->value;
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchNumSamples_StandardGate* MicroBenchNumSamples_StandardGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MicroBenchNumSamples_StandardGate*) memoryManager_allocate(context, size * sizeof(MicroBenchNumSamples_StandardGate));
}

/* Initialise function */
void MicroBenchNumSamples_StandardGate_initializeBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchNumSamples_StandardGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MicroBenchNumSamples_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, size_t size, MicroBenchNumSamples_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchNumSamples_StandardGate_setOverride(context, &place[i], value);
	}
}

/* SetBlock function */
void MicroBenchNumSamples_StandardGate_setBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place, size_t size, MicroBenchNumSamples_StandardGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MicroBenchNumSamples_StandardGate_disposeBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchNumSamples_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MicroBenchNumSamples_StandardGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MicroBenchNumSamples_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchNumSamples_StandardGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MicroBenchNumSamples_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchNumSamples_StandardGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchNumSamples_StandardGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MicroBenchNumSamples_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchNumSamples_StandardGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchNumSamples_StandardGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchNumSamples_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchNumSamples_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

