/**
 * File: MicroBenchSignalsCount_StandardGate.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "MemoryManager.h"

#include "MicroBenchSignalsCount_StandardGate.h"

/* Allocate function */
MicroBenchSignalsCount_StandardGate* MicroBenchSignalsCount_StandardGate_allocate(DSPEElement *context) {
	return (MicroBenchSignalsCount_StandardGate*) memoryManager_allocate(context, sizeof(MicroBenchSignalsCount_StandardGate));
}

/* Initialise function */
void MicroBenchSignalsCount_StandardGate_initialize(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place) {
	*place = MICROBENCHSIGNALSCOUNT_STANDARDGATE_DEFAULTVALUE;
}

/* Set function */
void MicroBenchSignalsCount_StandardGate_setOverride(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, MicroBenchSignalsCount_StandardGate value) {
	*place = value;
}

/* Set function */
void MicroBenchSignalsCount_StandardGate_set(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, MicroBenchSignalsCount_StandardGate *value) {
	*place = *value;
}

/* Dispose function */
void MicroBenchSignalsCount_StandardGate_dispose(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchSignalsCount_StandardGate_allocateGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MicroBenchSignalsCount_StandardGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MicroBenchSignalsCount_StandardGate_initializeGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MicroBenchSignalsCount_StandardGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MicroBenchSignalsCount_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size, MicroBenchSignalsCount_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSignalsCount_StandardGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MicroBenchSignalsCount_StandardGate_setGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size, MicroBenchSignalsCount_StandardGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSignalsCount_StandardGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchSignalsCount_StandardGate_disposeGroup(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MicroBenchSignalsCount_StandardGate_node* MicroBenchSignalsCount_StandardGate_createNode(DSPEElement *context, MicroBenchSignalsCount_StandardGate *gate, MicroBenchSignalsCount_StandardGate *localVar) {
	MicroBenchSignalsCount_StandardGate_node *node = (MicroBenchSignalsCount_StandardGate_node*) memoryManager_allocate(context, sizeof(MicroBenchSignalsCount_StandardGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	node->localVar = localVar;
	((DSPEGateNode*) node)->setValue = MicroBenchSignalsCount_StandardGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MicroBenchSignalsCount_StandardGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MicroBenchSignalsCount_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	node->next = NULL;
	memorySupport_dispose(node);
}

/* SetValue function */
void MicroBenchSignalsCount_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node) {
	MicroBenchSignalsCount_StandardGate_node *tmpNode = (MicroBenchSignalsCount_StandardGate_node*) node;
	if (tmpNode->gate != 0)
		*tmpNode->gate = tmpNode->value;
	if (tmpNode->localVar != 0)
		*tmpNode->localVar = tmpNode->value;
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchSignalsCount_StandardGate* MicroBenchSignalsCount_StandardGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MicroBenchSignalsCount_StandardGate*) memoryManager_allocate(context, size * sizeof(MicroBenchSignalsCount_StandardGate));
}

/* Initialise function */
void MicroBenchSignalsCount_StandardGate_initializeBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSignalsCount_StandardGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MicroBenchSignalsCount_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, size_t size, MicroBenchSignalsCount_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSignalsCount_StandardGate_setOverride(context, &place[i], value);
	}
}

/* SetBlock function */
void MicroBenchSignalsCount_StandardGate_setBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place, size_t size, MicroBenchSignalsCount_StandardGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MicroBenchSignalsCount_StandardGate_disposeBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchSignalsCount_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MicroBenchSignalsCount_StandardGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MicroBenchSignalsCount_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchSignalsCount_StandardGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MicroBenchSignalsCount_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSignalsCount_StandardGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchSignalsCount_StandardGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MicroBenchSignalsCount_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSignalsCount_StandardGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchSignalsCount_StandardGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchSignalsCount_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchSignalsCount_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

