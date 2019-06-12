/**
 * File: MicroBenchCounter_StandardGate.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "MemoryManager.h"

#include "MicroBenchCounter_StandardGate.h"

/* Allocate function */
MicroBenchCounter_StandardGate* MicroBenchCounter_StandardGate_allocate(DSPEElement *context) {
	return (MicroBenchCounter_StandardGate*) memoryManager_allocate(context, sizeof(MicroBenchCounter_StandardGate));
}

/* Initialise function */
void MicroBenchCounter_StandardGate_initialize(DSPEElement *context, MicroBenchCounter_StandardGate *place) {
	*place = MICROBENCHCOUNTER_STANDARDGATE_DEFAULTVALUE;
}

/* Set function */
void MicroBenchCounter_StandardGate_setOverride(DSPEElement *context, MicroBenchCounter_StandardGate *place, MicroBenchCounter_StandardGate value) {
	*place = value;
}

/* Set function */
void MicroBenchCounter_StandardGate_set(DSPEElement *context, MicroBenchCounter_StandardGate *place, MicroBenchCounter_StandardGate *value) {
	*place = *value;
}

/* Dispose function */
void MicroBenchCounter_StandardGate_dispose(DSPEElement *context, MicroBenchCounter_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchCounter_StandardGate_allocateGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MicroBenchCounter_StandardGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MicroBenchCounter_StandardGate_initializeGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MicroBenchCounter_StandardGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MicroBenchCounter_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size, MicroBenchCounter_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchCounter_StandardGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MicroBenchCounter_StandardGate_setGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size, MicroBenchCounter_StandardGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchCounter_StandardGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchCounter_StandardGate_disposeGroup(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MicroBenchCounter_StandardGate_node* MicroBenchCounter_StandardGate_createNode(DSPEElement *context, MicroBenchCounter_StandardGate *gate, MicroBenchCounter_StandardGate *localVar) {
	MicroBenchCounter_StandardGate_node *node = (MicroBenchCounter_StandardGate_node*) memoryManager_allocate(context, sizeof(MicroBenchCounter_StandardGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	node->localVar = localVar;
	((DSPEGateNode*) node)->setValue = MicroBenchCounter_StandardGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MicroBenchCounter_StandardGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MicroBenchCounter_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	node->next = NULL;
	memorySupport_dispose(node);
}

/* SetValue function */
void MicroBenchCounter_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node) {
	MicroBenchCounter_StandardGate_node *tmpNode = (MicroBenchCounter_StandardGate_node*) node;
	if (tmpNode->gate != 0)
		*tmpNode->gate = tmpNode->value;
	if (tmpNode->localVar != 0)
		*tmpNode->localVar = tmpNode->value;
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchCounter_StandardGate* MicroBenchCounter_StandardGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MicroBenchCounter_StandardGate*) memoryManager_allocate(context, size * sizeof(MicroBenchCounter_StandardGate));
}

/* Initialise function */
void MicroBenchCounter_StandardGate_initializeBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchCounter_StandardGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MicroBenchCounter_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place, size_t size, MicroBenchCounter_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchCounter_StandardGate_setOverride(context, &place[i], value);
	}
}

/* SetBlock function */
void MicroBenchCounter_StandardGate_setBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place, size_t size, MicroBenchCounter_StandardGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MicroBenchCounter_StandardGate_disposeBlock(DSPEElement *context, MicroBenchCounter_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchCounter_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MicroBenchCounter_StandardGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MicroBenchCounter_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchCounter_StandardGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MicroBenchCounter_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchCounter_StandardGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchCounter_StandardGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MicroBenchCounter_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchCounter_StandardGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchCounter_StandardGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchCounter_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchCounter_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

