/**
 * File: MicroBenchSamplesPerSecond_StandardGate.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "MemoryManager.h"

#include "MicroBenchSamplesPerSecond_StandardGate.h"

/* Allocate function */
MicroBenchSamplesPerSecond_StandardGate* MicroBenchSamplesPerSecond_StandardGate_allocate(DSPEElement *context) {
	return (MicroBenchSamplesPerSecond_StandardGate*) memoryManager_allocate(context, sizeof(MicroBenchSamplesPerSecond_StandardGate));
}

/* Initialise function */
void MicroBenchSamplesPerSecond_StandardGate_initialize(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place) {
	*place = MICROBENCHSAMPLESPERSECOND_STANDARDGATE_DEFAULTVALUE;
}

/* Set function */
void MicroBenchSamplesPerSecond_StandardGate_setOverride(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, MicroBenchSamplesPerSecond_StandardGate value) {
	*place = value;
}

/* Set function */
void MicroBenchSamplesPerSecond_StandardGate_set(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, MicroBenchSamplesPerSecond_StandardGate *value) {
	*place = *value;
}

/* Dispose function */
void MicroBenchSamplesPerSecond_StandardGate_dispose(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchSamplesPerSecond_StandardGate_allocateGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MicroBenchSamplesPerSecond_StandardGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MicroBenchSamplesPerSecond_StandardGate_initializeGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MicroBenchSamplesPerSecond_StandardGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MicroBenchSamplesPerSecond_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size, MicroBenchSamplesPerSecond_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSamplesPerSecond_StandardGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MicroBenchSamplesPerSecond_StandardGate_setGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size, MicroBenchSamplesPerSecond_StandardGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSamplesPerSecond_StandardGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchSamplesPerSecond_StandardGate_disposeGroup(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MicroBenchSamplesPerSecond_StandardGate_node* MicroBenchSamplesPerSecond_StandardGate_createNode(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *gate, MicroBenchSamplesPerSecond_StandardGate *localVar) {
	MicroBenchSamplesPerSecond_StandardGate_node *node = (MicroBenchSamplesPerSecond_StandardGate_node*) memoryManager_allocate(context, sizeof(MicroBenchSamplesPerSecond_StandardGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	node->localVar = localVar;
	((DSPEGateNode*) node)->setValue = MicroBenchSamplesPerSecond_StandardGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MicroBenchSamplesPerSecond_StandardGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MicroBenchSamplesPerSecond_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	node->next = NULL;
	memorySupport_dispose(node);
}

/* SetValue function */
void MicroBenchSamplesPerSecond_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node) {
	MicroBenchSamplesPerSecond_StandardGate_node *tmpNode = (MicroBenchSamplesPerSecond_StandardGate_node*) node;
	if (tmpNode->gate != 0)
		*tmpNode->gate = tmpNode->value;
	if (tmpNode->localVar != 0)
		*tmpNode->localVar = tmpNode->value;
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchSamplesPerSecond_StandardGate* MicroBenchSamplesPerSecond_StandardGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MicroBenchSamplesPerSecond_StandardGate*) memoryManager_allocate(context, size * sizeof(MicroBenchSamplesPerSecond_StandardGate));
}

/* Initialise function */
void MicroBenchSamplesPerSecond_StandardGate_initializeBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSamplesPerSecond_StandardGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, size_t size, MicroBenchSamplesPerSecond_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchSamplesPerSecond_StandardGate_setOverride(context, &place[i], value);
	}
}

/* SetBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place, size_t size, MicroBenchSamplesPerSecond_StandardGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MicroBenchSamplesPerSecond_StandardGate_disposeBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchSamplesPerSecond_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MicroBenchSamplesPerSecond_StandardGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MicroBenchSamplesPerSecond_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchSamplesPerSecond_StandardGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSamplesPerSecond_StandardGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchSamplesPerSecond_StandardGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MicroBenchSamplesPerSecond_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchSamplesPerSecond_StandardGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchSamplesPerSecond_StandardGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchSamplesPerSecond_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchSamplesPerSecond_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

