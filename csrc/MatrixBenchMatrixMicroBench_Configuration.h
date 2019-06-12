/**
 * File: MatrixBenchMatrixMicroBench_Configuration.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:25 CEST 2019
 */
#ifndef MatrixBenchMatrixMicroBench_Configuration_h
#define MatrixBenchMatrixMicroBench_Configuration_h

#include "DSPEElements.h"

#include "MatrixBenchMatrixSource_SoftwareUnit.h"
#include "MatrixBenchMatrixMultiplier_SoftwareUnit.h"
#include "MatrixBenchMatrixTarget_SoftwareUnit.h"
#include "MicroBenchEvaluator_SoftwareUnit.h"

/* Configuration state type definition */
typedef struct MatrixBenchMatrixMicroBench_Configuration MatrixBenchMatrixMicroBench_Configuration;

/* Configuration state definition */
struct MatrixBenchMatrixMicroBench_Configuration {

	DSPEConfiguration structure;
	
	/* Units */
	MatrixBenchMatrixSource_SoftwareUnit *MatrixSource;
	MatrixBenchMatrixMultiplier_SoftwareUnit *MatrixMultiplier;
	MatrixBenchMatrixTarget_SoftwareUnit *MatrixTarget;
	MicroBenchEvaluator_SoftwareUnit *Evaluator;

	/* NamePrefix for Bypass Units */
	char *namePrefix;

};

#ifdef __cplusplus
extern "C" {
#endif

/* Exported local functions */

/**
 * Snapshot function
 */
void MatrixBenchMatrixMicroBench_Configuration_snapshot(DSPEElement *element, DSPESnapshot *snapshot);

/* EarlyAlloc function */
void MatrixBenchMatrixMicroBench_Configuration_earlyAlloc(MatrixBenchMatrixMicroBench_Configuration *context);

/* Alloc function */
void MatrixBenchMatrixMicroBench_Configuration_alloc(MatrixBenchMatrixMicroBench_Configuration *context);

/* EarlyConnect function */
void MatrixBenchMatrixMicroBench_Configuration_earlyConnect(MatrixBenchMatrixMicroBench_Configuration *context);

/* Connect function */
void MatrixBenchMatrixMicroBench_Configuration_connect(MatrixBenchMatrixMicroBench_Configuration *context);

/* Startup function */
void MatrixBenchMatrixMicroBench_Configuration_startup(MatrixBenchMatrixMicroBench_Configuration *context);

/* PreProcess function */
void MatrixBenchMatrixMicroBench_Configuration_preProcess(MatrixBenchMatrixMicroBench_Configuration *context);

/* Process function */
void MatrixBenchMatrixMicroBench_Configuration_process(MatrixBenchMatrixMicroBench_Configuration *context);

/* PostProcess function */
void MatrixBenchMatrixMicroBench_Configuration_postProcess(MatrixBenchMatrixMicroBench_Configuration *context);

/* Reset function */
void MatrixBenchMatrixMicroBench_Configuration_reset(MatrixBenchMatrixMicroBench_Configuration *context);

/* Shutdown function */
void MatrixBenchMatrixMicroBench_Configuration_shutdown(MatrixBenchMatrixMicroBench_Configuration *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
