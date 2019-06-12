/**
 * File: MicroBenchFlag_StandardGate.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "MemoryManager.h"

#include "MicroBenchFlag_StandardGate.h"

/* Allocate function */
MicroBenchFlag_StandardGate* MicroBenchFlag_StandardGate_allocate(DSPEElement *context) {
	return (MicroBenchFlag_StandardGate*) memoryManager_allocate(context, sizeof(MicroBenchFlag_StandardGate));
}

/* Initialise function */
void MicroBenchFlag_StandardGate_initialize(DSPEElement *context, MicroBenchFlag_StandardGate *place) {
	*place = MICROBENCHFLAG_STANDARDGATE_DEFAULTVALUE;
}

/* Set function */
void MicroBenchFlag_StandardGate_setOverride(DSPEElement *context, MicroBenchFlag_StandardGate *place, MicroBenchFlag_StandardGate value) {
	*place = value;
}

/* Set function */
void MicroBenchFlag_StandardGate_set(DSPEElement *context, MicroBenchFlag_StandardGate *place, MicroBenchFlag_StandardGate *value) {
	*place = *value;
}

/* Dispose function */
void MicroBenchFlag_StandardGate_dispose(DSPEElement *context, MicroBenchFlag_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchFlag_StandardGate_allocateGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MicroBenchFlag_StandardGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MicroBenchFlag_StandardGate_initializeGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MicroBenchFlag_StandardGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MicroBenchFlag_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size, MicroBenchFlag_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchFlag_StandardGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MicroBenchFlag_StandardGate_setGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size, MicroBenchFlag_StandardGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchFlag_StandardGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchFlag_StandardGate_disposeGroup(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MicroBenchFlag_StandardGate_node* MicroBenchFlag_StandardGate_createNode(DSPEElement *context, MicroBenchFlag_StandardGate *gate, MicroBenchFlag_StandardGate *localVar) {
	MicroBenchFlag_StandardGate_node *node = (MicroBenchFlag_StandardGate_node*) memoryManager_allocate(context, sizeof(MicroBenchFlag_StandardGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	node->localVar = localVar;
	((DSPEGateNode*) node)->setValue = MicroBenchFlag_StandardGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MicroBenchFlag_StandardGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MicroBenchFlag_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	node->next = NULL;
	memorySupport_dispose(node);
}

/* SetValue function */
void MicroBenchFlag_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node) {
	MicroBenchFlag_StandardGate_node *tmpNode = (MicroBenchFlag_StandardGate_node*) node;
	if (tmpNode->gate != 0)
		*tmpNode->gate = tmpNode->value;
	if (tmpNode->localVar != 0)
		*tmpNode->localVar = tmpNode->value;
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchFlag_StandardGate* MicroBenchFlag_StandardGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MicroBenchFlag_StandardGate*) memoryManager_allocate(context, size * sizeof(MicroBenchFlag_StandardGate));
}

/* Initialise function */
void MicroBenchFlag_StandardGate_initializeBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchFlag_StandardGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MicroBenchFlag_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place, size_t size, MicroBenchFlag_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchFlag_StandardGate_setOverride(context, &place[i], value);
	}
}

/* SetBlock function */
void MicroBenchFlag_StandardGate_setBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place, size_t size, MicroBenchFlag_StandardGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MicroBenchFlag_StandardGate_disposeBlock(DSPEElement *context, MicroBenchFlag_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchFlag_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MicroBenchFlag_StandardGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MicroBenchFlag_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchFlag_StandardGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MicroBenchFlag_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchFlag_StandardGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchFlag_StandardGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MicroBenchFlag_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchFlag_StandardGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchFlag_StandardGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchFlag_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchFlag_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

