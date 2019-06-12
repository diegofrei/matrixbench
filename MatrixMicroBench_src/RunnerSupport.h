/**
 * File: RunnerSupport.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#ifndef RunnerSupport_h
#define RunnerSupport_h

#include "RunnerGround.h"

#ifdef __cplusplus
extern "C" {
#endif

/* InitializeRunner function */
MatrixBenchMatrixMicroBench_Application_cmd* initializeRunner();

/* DestroyRunner function */
void destroyRunner(MatrixBenchMatrixMicroBench_Application_cmd *context);

/* RunnerPreProcess function */
void MatrixBenchMatrixMicroBench_Application_runnerPreProcess(DSPEComponent *component);

/* RunnerPostProcess function */
void MatrixBenchMatrixMicroBench_Application_runnerPostProcess(DSPEComponent *component);

/* Run function */
void run(MatrixBenchMatrixMicroBench_Application_cmd *context, long int iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
