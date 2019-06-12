/**
 * File: MatrixBenchMatrix_PointerGate.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "MemoryManager.h"

#include "MatrixBenchMatrix_PointerGate.h"

#include "MatrixBenchMatrix_Requirement.h"

/* MemoryManager function shortcuts */
#define memory_allocate(size) memorySupport_allocate(size)
#define memory_allocateAndInit(blockSize, size) memorySupport_allocateAndInit(blockSize, size)
#define memory_realloc(pointer, newSize) memorySupport_realloc(pointer, newSize)
#define memory_dispose(pointer) memorySupport_dispose(pointer)
#define memory_copyBlock(destination, source, size) memorySupport_copyBlock(destination, source, size)
#define memory_resetBlock(destination, size) memorySupport_resetBlock(destination, size)

/**
 * Allocate. This function will be used to allocate memory to the gate.
 */
MatrixBenchMatrix_PointerGate MatrixBenchMatrix_PointerGate_allocateValue(DSPEElement *context) {
//Place implementation after this line -- SYD-ALLOCATEVALUE-START
	// [0 .. MATRIX_SIZE * MATRIX_SIZE - 1]: Matrix data
	// [MATRIX_SIZE * MATRIX_SIZE]: Matrix ID
	// [MATRIX_SIZE * MATRIX_SIZE + 1]: Signal flag
	return (MatrixBenchMatrix_PointerGate) memorySupport_allocate((MATRIX_SIZE * MATRIX_SIZE + ADDITIONAL_FIELDS) * sizeof(float));
//SYD-ALLOCATEVALUE-END -- Place implementation before this line
}

/**
 * Initialise. This function will be used to initialise the given gate.
 */
void MatrixBenchMatrix_PointerGate_initValue(DSPEElement *context, MatrixBenchMatrix_PointerGate data) {
//Place implementation after this line -- SYD-INITVALUE-START
	int i;
	for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE + ADDITIONAL_FIELDS; ++i)
		data[i] = 0.0;
//SYD-INITVALUE-END -- Place implementation before this line
}

/**
 * Copy. This function will be used to copy data between the given source and destination gates.
 */
void MatrixBenchMatrix_PointerGate_copyValue(DSPEElement *context, MatrixBenchMatrix_PointerGate destination, MatrixBenchMatrix_PointerGate source) {
//Place implementation after this line -- SYD-COPYVALUE-START
	memory_copyBlock(destination, source, (MATRIX_SIZE * MATRIX_SIZE + ADDITIONAL_FIELDS) * sizeof(float));
//SYD-COPYVALUE-END -- Place implementation before this line
}

/**
 * Compare. This function will be used to compare data between the given first and second gate.
 */
int MatrixBenchMatrix_PointerGate_compareValue(DSPEElement *context, MatrixBenchMatrix_PointerGate first, MatrixBenchMatrix_PointerGate second) {
//Place implementation after this line -- SYD-COMPAREVALUE-START
	int i;
	for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE + ADDITIONAL_FIELDS; ++i) {
		if (first[i] == second[i])
			continue;
		else if (first[i] > second[i])
			return 1;
		else
			return -1;
	}
	return 0;
//SYD-COMPAREVALUE-END -- Place implementation before this line
}

/**
 * Dispose. This function will be used to free the given gate memory.
 */
void MatrixBenchMatrix_PointerGate_disposeValue(DSPEElement *context, MatrixBenchMatrix_PointerGate data) {
//Place implementation after this line -- SYD-DISPOSEVALUE-START
	memorySupport_dispose(data);
//SYD-DISPOSEVALUE-END -- Place implementation before this line
}

/******************************************************************************
 * FOLLOWING CODE IS NOT INTENDED TO BE MODIFIED BY USERS                     *
 ******************************************************************************/

/* AllocateManaged function */
void MatrixBenchMatrix_PointerGate_allocateManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor) {
	*anchor = MatrixBenchMatrix_PointerGate_allocateValue(context);
}
/* InitManaged function */
void MatrixBenchMatrix_PointerGate_initManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate anchor) {
	MatrixBenchMatrix_PointerGate_initValue(context, anchor);
}

/* DisposeManaged function */
void MatrixBenchMatrix_PointerGate_disposeManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate anchor) {
	MatrixBenchMatrix_PointerGate_disposeValue(context, anchor);
}

/* AllocateGroupManaged function */
void MatrixBenchMatrix_PointerGate_allocateGroupManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_allocateManaged(context, anchor[i]);
	}
}
/* InitGroupManaged function */
void MatrixBenchMatrix_PointerGate_initGroupManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_initValue(context, *anchor[i]);
	}
}

/* DisposeGroupManaged function */
void MatrixBenchMatrix_PointerGate_disposeGroupManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_disposeValue(context, *anchor[i]);
	}
}

/* Allocate function */
MatrixBenchMatrix_PointerGate* MatrixBenchMatrix_PointerGate_allocate(DSPEElement *context) {
	return (MatrixBenchMatrix_PointerGate*) memoryManager_allocate(context, sizeof(MatrixBenchMatrix_PointerGate));
}

/* Initialise function */
void MatrixBenchMatrix_PointerGate_initialize(DSPEElement *context, MatrixBenchMatrix_PointerGate *place) {
	*place = MATRIXBENCHMATRIX_POINTERGATE_DEFAULTVALUE;
}

/* SetOverride function */
void MatrixBenchMatrix_PointerGate_setOverride(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, MatrixBenchMatrix_PointerGate value) {
	MatrixBenchMatrix_PointerGate_copyValue(context, *place, value);
}

/* Set function */
void MatrixBenchMatrix_PointerGate_set(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, MatrixBenchMatrix_PointerGate *value) {
	*place = *value;
}

/* Compare function */
int MatrixBenchMatrix_PointerGate_compare(DSPEElement *context, MatrixBenchMatrix_PointerGate first, MatrixBenchMatrix_PointerGate second) {
	return MatrixBenchMatrix_PointerGate_compareValue(context, first, second);
}

/* Dispose function */
void MatrixBenchMatrix_PointerGate_dispose(DSPEElement *context, MatrixBenchMatrix_PointerGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MatrixBenchMatrix_PointerGate_allocateGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	place[i] = MatrixBenchMatrix_PointerGate_allocate(context);
	}
}

/* InitialiseGroup function */
void MatrixBenchMatrix_PointerGate_initializeGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
	 	MatrixBenchMatrix_PointerGate_initialize(context, place[i]);
	}
}

/* SetOverrideGroup function */
void MatrixBenchMatrix_PointerGate_setOverrideGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size, MatrixBenchMatrix_PointerGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_setOverride(context, place[i], value);
	}
}

/* SetGroup function */
void MatrixBenchMatrix_PointerGate_setGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size, MatrixBenchMatrix_PointerGate **value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_set(context, place[i], value[i]);
	}
}

/* DisposeGroup function */
void MatrixBenchMatrix_PointerGate_disposeGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

/* CreateNode function */
MatrixBenchMatrix_PointerGate_node* MatrixBenchMatrix_PointerGate_createNode(DSPEElement *context, MatrixBenchMatrix_PointerGate *gate, MatrixBenchMatrix_PointerGate *localVar) {
	MatrixBenchMatrix_PointerGate_node *node = (MatrixBenchMatrix_PointerGate_node*) memoryManager_allocate(context, sizeof(MatrixBenchMatrix_PointerGate_node));
	initDSPEGateNode((DSPEGateNode*) node);
	node->gate = gate;
	if (gate != 0)
		node->gateAnchor = *node->gate;
	else
		node->gateAnchor = 0;
	node->localVar = localVar;
	if (localVar != 0)
		node->localVarAnchor = *node->localVar;
	else
		node->localVarAnchor = 0;
	node->value = MatrixBenchMatrix_PointerGate_allocate(context);
	MatrixBenchMatrix_PointerGate_allocateManaged(context, node->value);
	MatrixBenchMatrix_PointerGate_initManaged(context, *node->value);
	node->valueAnchor = *node->value;
	((DSPEGateNode*) node)->setValue = MatrixBenchMatrix_PointerGate_setValue;
	((DSPEGateNode*) node)->disposeNode = MatrixBenchMatrix_PointerGate_disposeNode;
	return node;
}

/* DisposeNode function */
void MatrixBenchMatrix_PointerGate_disposeNode(DSPEElement *context, DSPEGateNode *node) {
	MatrixBenchMatrix_PointerGate_node *tmpNode = (MatrixBenchMatrix_PointerGate_node*) node;
	node->next = NULL;
	MatrixBenchMatrix_PointerGate_disposeManaged(context, tmpNode->valueAnchor);
	MatrixBenchMatrix_PointerGate_dispose(context, tmpNode->value);
	memorySupport_dispose(tmpNode);
}

/* SetValue function */
void MatrixBenchMatrix_PointerGate_setValue(DSPEElement *context, DSPEGateNode *node) {
MatrixBenchMatrix_PointerGate_node *tmpNode = (MatrixBenchMatrix_PointerGate_node*) node;
	if (tmpNode->gate != 0) {
		if (*tmpNode->value != 0) {
			*tmpNode->gate = tmpNode->gateAnchor;
			MatrixBenchMatrix_PointerGate_copyValue(context, *tmpNode->gate, *tmpNode->value);
		} else
			*tmpNode->gate = 0;
	}
	if (tmpNode->localVar != 0) {
		if (*tmpNode->value != 0) {
			*tmpNode->localVar = tmpNode->localVarAnchor;
			MatrixBenchMatrix_PointerGate_copyValue(context, *tmpNode->localVar, *tmpNode->value);
		} else
			*tmpNode->localVar = 0;
	}
}

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* AllocateBlockManaged function */
void MatrixBenchMatrix_PointerGate_allocateBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		anchor[i] = MatrixBenchMatrix_PointerGate_allocateValue(context);
	}
}

/* InitBlockManaged function */
void MatrixBenchMatrix_PointerGate_initBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_initManaged(context, anchor[i]);
	}
}

/* DisposeBlockManaged function */
void MatrixBenchMatrix_PointerGate_disposeBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_disposeManaged(context, anchor[i]);
	}
}

/* AllocateGroupBlockManaged function */
void MatrixBenchMatrix_PointerGate_allocateGroupBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_allocateBlockManaged(context, anchor[i], gateSize[i]);
	}
}

/* InitGroupBlockManaged function */
void MatrixBenchMatrix_PointerGate_initGroupBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_initBlockManaged(context, anchor[i], gateSize[i]);
	}
}

/* DisposeGroupBlockManaged function */
void MatrixBenchMatrix_PointerGate_disposeGroupBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_disposeBlockManaged(context, anchor[i], gateSize[i]);
	}
}

/* Allocate function */
MatrixBenchMatrix_PointerGate* MatrixBenchMatrix_PointerGate_allocateBlock(DSPEElement *context, size_t size) {
	return (MatrixBenchMatrix_PointerGate*) memoryManager_allocate(context, size * sizeof(MatrixBenchMatrix_PointerGate));
}

/* Initialise function */
void MatrixBenchMatrix_PointerGate_initializeBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, size_t size) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_initialize(context, &place[i]);
	}
}

/* SetOverrideBlock function */
void MatrixBenchMatrix_PointerGate_setOverrideBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, size_t size, MatrixBenchMatrix_PointerGate value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		MatrixBenchMatrix_PointerGate_setOverride(context, &place[i], value);
	}
}

/* Set function */
void MatrixBenchMatrix_PointerGate_setBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, size_t size, MatrixBenchMatrix_PointerGate *value) {
	register size_t i;
	for (i = 0; i < size; i++) {
		place[i] = value[i]; 
	}
}

/* Dispose function */
void MatrixBenchMatrix_PointerGate_disposeBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place) {
	memorySupport_dispose(place);
}

/* AllocateGroup function */
void MatrixBenchMatrix_PointerGate_allocateGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;	
	for (i = 0; i < groupSize; i++) {
	 	place[i] = MatrixBenchMatrix_PointerGate_allocateBlock(context, gateSize[i]);	
	}
}

/* InitialiseGroup function */
void MatrixBenchMatrix_PointerGate_initializeGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MatrixBenchMatrix_PointerGate_initializeBlock(context, place[i], gateSize[i]);
	}
}

/* SetOverrideGroupBlock function */
void MatrixBenchMatrix_PointerGate_setOverrideGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize, MatrixBenchMatrix_PointerGate value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MatrixBenchMatrix_PointerGate_setOverrideBlock(context, place[i], gateSize[i], value);
	}
}

/* SetGroupBlock function */
void MatrixBenchMatrix_PointerGate_setGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize, MatrixBenchMatrix_PointerGate **value) {
	register size_t i;
	for (i = 0; i < groupSize; i++) {
		MatrixBenchMatrix_PointerGate_setBlock(context, place[i], gateSize[i], value[i]);
	}
}

/* DisposeGroup function */
void MatrixBenchMatrix_PointerGate_disposeGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size) {
	register size_t i;	
	for (i = 0; i < size; i++) {
	 	memorySupport_dispose(place[i]);
	}
}

