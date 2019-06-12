/**
 * File: MatrixBenchMatrix_PointerGate.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef MatrixBenchMatrix_PointerGate_h
#define MatrixBenchMatrix_PointerGate_h

#include "DSPEXTElements.h"

#define MATRIXBENCHMATRIX_POINTERGATE_TYPECATEGORY "Pointer"
#define MATRIXBENCHMATRIX_POINTERGATE_DEFAULTVALUE 0

typedef float* MatrixBenchMatrix_PointerGate;

/* PointerGate node type definition */
typedef struct MatrixBenchMatrix_PointerGate_node MatrixBenchMatrix_PointerGate_node; 

/* PointerGate node definition */ 
struct MatrixBenchMatrix_PointerGate_node {
	DSPEGateNode node;
	
	MatrixBenchMatrix_PointerGate *gate;
	MatrixBenchMatrix_PointerGate gateAnchor;
	MatrixBenchMatrix_PointerGate *localVar;
	MatrixBenchMatrix_PointerGate localVarAnchor;
	MatrixBenchMatrix_PointerGate *value;
	MatrixBenchMatrix_PointerGate valueAnchor;
};

#ifdef __cplusplus
extern "C" {
#endif

/* Allocate function */
MatrixBenchMatrix_PointerGate MatrixBenchMatrix_PointerGate_allocateValue(DSPEElement *context);

/* Initialise function */
void MatrixBenchMatrix_PointerGate_initValue(DSPEElement *context, MatrixBenchMatrix_PointerGate data);

/* Copy function */
void MatrixBenchMatrix_PointerGate_copyValue(DSPEElement *context, MatrixBenchMatrix_PointerGate destination, MatrixBenchMatrix_PointerGate source);

/* Compare. This function will be used to compare data between the given first and second gate. */
int MatrixBenchMatrix_PointerGate_compareValue(DSPEElement *context, MatrixBenchMatrix_PointerGate first, MatrixBenchMatrix_PointerGate second);

/* Dispose function */
void MatrixBenchMatrix_PointerGate_disposeValue(DSPEElement *context, MatrixBenchMatrix_PointerGate data);

/* AllocateManaged function */
void MatrixBenchMatrix_PointerGate_allocateManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor);
/* InitManaged function */
void MatrixBenchMatrix_PointerGate_initManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate anchor);

/* DisposeManaged function */
void MatrixBenchMatrix_PointerGate_disposeManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate anchor);

/* AllocateGroupManaged function */
void MatrixBenchMatrix_PointerGate_allocateGroupManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size);
/* InitGroupManaged function */
void MatrixBenchMatrix_PointerGate_initGroupManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size);

/* DisposeGroupManaged function */
void MatrixBenchMatrix_PointerGate_disposeGroupManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size);

/* Allocate function */
MatrixBenchMatrix_PointerGate* MatrixBenchMatrix_PointerGate_allocate(DSPEElement *context);

/* Initialise function */
void MatrixBenchMatrix_PointerGate_initialize(DSPEElement *context, MatrixBenchMatrix_PointerGate *place);

/* SetOverride function */
void MatrixBenchMatrix_PointerGate_setOverride(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, MatrixBenchMatrix_PointerGate value);

/* Set function */
void MatrixBenchMatrix_PointerGate_set(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, MatrixBenchMatrix_PointerGate *value);

/* Compare function */
int MatrixBenchMatrix_PointerGate_compare(DSPEElement *context, MatrixBenchMatrix_PointerGate first, MatrixBenchMatrix_PointerGate second);

/* Dispose function */
void MatrixBenchMatrix_PointerGate_dispose(DSPEElement *context, MatrixBenchMatrix_PointerGate *place);

/* AllocateGroup function */
void MatrixBenchMatrix_PointerGate_allocateGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size);

/* InitialiseGroup function */
void MatrixBenchMatrix_PointerGate_initializeGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size);

/* SetOverrideGroup function */
void MatrixBenchMatrix_PointerGate_setOverrideGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size, MatrixBenchMatrix_PointerGate value);

/* SetGroup function */
void MatrixBenchMatrix_PointerGate_setGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size, MatrixBenchMatrix_PointerGate **value);

/* DisposeGroup function */
void MatrixBenchMatrix_PointerGate_disposeGroup(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size);

/* CreateNode function */
MatrixBenchMatrix_PointerGate_node* MatrixBenchMatrix_PointerGate_createNode(DSPEElement *context, MatrixBenchMatrix_PointerGate *gate, MatrixBenchMatrix_PointerGate *localVar);

/* DisposeNode function */
void MatrixBenchMatrix_PointerGate_disposeNode(DSPEElement *context, DSPEGateNode *node);

/* SetValue function */
void MatrixBenchMatrix_PointerGate_setValue(DSPEElement *context, DSPEGateNode *node);

/******************************************************************************
 * BLOCK FUNCTIONS
 ******************************************************************************/

/* AllocateBlockManaged function */
void MatrixBenchMatrix_PointerGate_allocateBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor, size_t size);

/* InitBlockManaged function */
void MatrixBenchMatrix_PointerGate_initBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor, size_t size);

/* DisposeBlockManaged function */
void MatrixBenchMatrix_PointerGate_disposeBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate *anchor, size_t size);

/* AllocateGroupBlockManaged function */
void MatrixBenchMatrix_PointerGate_allocateGroupBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size, size_t *gateSize);

/* InitGroupBlockManaged function */
void MatrixBenchMatrix_PointerGate_initGroupBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size, size_t *gateSize);

/* DisposeGroupBlockManaged function */
void MatrixBenchMatrix_PointerGate_disposeGroupBlockManaged(DSPEElement *context, MatrixBenchMatrix_PointerGate **anchor, size_t size, size_t *gateSize);

/* Allocate function */
MatrixBenchMatrix_PointerGate* MatrixBenchMatrix_PointerGate_allocateBlock(DSPEElement *context, size_t size);

/* Initialise function */
void MatrixBenchMatrix_PointerGate_initializeBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, size_t size);

/* SetOverrideBlock function */
void MatrixBenchMatrix_PointerGate_setOverrideBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, size_t size, MatrixBenchMatrix_PointerGate value);

/* Set function */
void MatrixBenchMatrix_PointerGate_setBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place, size_t size, MatrixBenchMatrix_PointerGate *value);

/* Dispose function */
void MatrixBenchMatrix_PointerGate_disposeBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate *place);

/* AllocateGroup function */
void MatrixBenchMatrix_PointerGate_allocateGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize);

/* InitialiseGroup function */
void MatrixBenchMatrix_PointerGate_initializeGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize);

/* SetOverrideGroupBlock function */
void MatrixBenchMatrix_PointerGate_setOverrideGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize, MatrixBenchMatrix_PointerGate value);

/* SetGroupBlock function */
void MatrixBenchMatrix_PointerGate_setGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t groupSize, size_t *gateSize, MatrixBenchMatrix_PointerGate **value);

/* DisposeGroup function */
void MatrixBenchMatrix_PointerGate_disposeGroupBlock(DSPEElement *context, MatrixBenchMatrix_PointerGate **place, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
