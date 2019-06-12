/**
 * File: MicroBenchTime_StandardGate.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:26 CEST 2019
 */
#include "MemoryManager.h"

#include "MicroBenchTime_StandardGate.h"

/* Allocate function */
MicroBenchTime_StandardGate* MicroBenchTime_StandardGate_allocate(DSPEElement *context) {
	return (MicroBenchTime_StandardGate*) memoryManager_allocate(context, sizeof(MicroBenchTime_StandardGate));
}

/* Initialise function */
void MicroBenchTime_StandardGate_initialize(DSPEElement *context, MicroBenchTime_StandardGate *place) {
	*place = MICROBENCHTIME_STANDARDGATE_DEFAULTVALUE;
}

/* Set function */
void MicroBenchTime_StandardGate_setOverride(DSPEElement *context, MicroBenchTime_StandardGate *place, MicroBenchTime_StandardGate value) {
	*place = value;
}

/* Set function */
void MicroBenchTime_StandardGate_set(DSPEElement *context, MicroBenchTime_StandardGate *place, MicroBenchTime_StandardGate *value) {
	*place = *value;
}

/* Dispose function */
void MicroBenchTime_StandardGate_dispose(DSPEElement *context, MicroBenchTime_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchTime_StandardGate_allocateGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MicroBenchTime_StandardGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MicroBenchTime_StandardGate_initializeGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MicroBenchTime_StandardGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MicroBenchTime_StandardGate_setOverrideGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size, MicroBenchTime_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchTime_StandardGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MicroBenchTime_StandardGate_setGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size, MicroBenchTime_StandardGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchTime_StandardGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchTime_StandardGate_disposeGroup(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MicroBenchTime_StandardGate_node* MicroBenchTime_StandardGate_createNode(DSPEElement *context, MicroBenchTime_StandardGate *gate, MicroBenchTime_StandardGate *localVar) {
	MicroBenchTime_StandardGate_node *node = (MicroBenchTime_StandardGate_node*) memoryManager_allocate(context, sizeof(MicroBenchTime_StandardGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	node->localVar = localVar;
	((DSPEGateNode*) node)->setValue = MicroBenchTime_StandardGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MicroBenchTime_StandardGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MicroBenchTime_StandardGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	node->next = NULL;
	memorySupport_dispose(node);
}

/* SetValue function */
void MicroBenchTime_StandardGate_setValue(DSPEElement *context, DSPEGateNode *node) {
	MicroBenchTime_StandardGate_node *tmpNode = (MicroBenchTime_StandardGate_node*) node;
	if (tmpNode->gate != 0)
		*tmpNode->gate = tmpNode->value;
	if (tmpNode->localVar != 0)
		*tmpNode->localVar = tmpNode->value;
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* Allocate function */
MicroBenchTime_StandardGate* MicroBenchTime_StandardGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MicroBenchTime_StandardGate*) memoryManager_allocate(context, size * sizeof(MicroBenchTime_StandardGate));
}

/* Initialise function */
void MicroBenchTime_StandardGate_initializeBlock(DSPEElement *context, MicroBenchTime_StandardGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchTime_StandardGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MicroBenchTime_StandardGate_setOverrideBlock(DSPEElement *context, MicroBenchTime_StandardGate *place, size_t size, MicroBenchTime_StandardGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MicroBenchTime_StandardGate_setOverride(context, &place[i], value);
	}
}

/* SetBlock function */
void MicroBenchTime_StandardGate_setBlock(DSPEElement *context, MicroBenchTime_StandardGate *place, size_t size, MicroBenchTime_StandardGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MicroBenchTime_StandardGate_disposeBlock(DSPEElement *context, MicroBenchTime_StandardGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MicroBenchTime_StandardGate_allocateGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MicroBenchTime_StandardGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MicroBenchTime_StandardGate_initializeGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchTime_StandardGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MicroBenchTime_StandardGate_setOverrideGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchTime_StandardGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchTime_StandardGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MicroBenchTime_StandardGate_setGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t groupSize, size_t *gateSize, MicroBenchTime_StandardGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MicroBenchTime_StandardGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MicroBenchTime_StandardGate_disposeGroupBlock(DSPEElement *context, MicroBenchTime_StandardGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

