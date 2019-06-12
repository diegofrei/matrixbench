/**
 * File: TextualRepresentation.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#ifndef TextualRepresentation_h
#define TextualRepresentation_h

#include "RunnerGround.h"

#ifdef __cplusplus
extern "C" {
#endif

void initializeCurValues(MatrixBenchMatrixMicroBench_Application_cmd *context);

void disposeCurValues(MatrixBenchMatrixMicroBench_Application_cmd *context);

int handleOptionsWithoutValue(char *opt);

int handleOptions(MatrixBenchMatrixMicroBench_Application_cmd *context, char *opt, char *value, int *err, long int *iter, int lastOpt);

void optionPn(MatrixBenchMatrixMicroBench_Application_cmd *context, char *opt, char *value, int *err);

void loadInputParameters(MatrixBenchMatrixMicroBench_Application_cmd *context, char *filePath);

void displayOutput(MatrixBenchMatrixMicroBench_Application_cmd *context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
