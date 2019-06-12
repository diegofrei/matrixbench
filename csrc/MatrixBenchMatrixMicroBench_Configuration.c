/**
 * File: MatrixBenchMatrixMicroBench_Configuration.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "StringManager.h"
#include "MemoryManager.h"
#include "EngineManager.h"
#include "InfoManager.h"

#include "MatrixBenchMatrixMicroBench_Configuration.h"


/* Unit declaration id defines */
#define MatrixSource_ID "MatrixSource"
#define MatrixMultiplier_ID "MatrixMultiplier"
#define MatrixTarget_ID "MatrixTarget"
#define Evaluator_ID "Evaluator"

/* EarlyAlloc function */
void MatrixBenchMatrixMicroBench_Configuration_earlyAlloc(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained unit allocation */
	context->MatrixSource = (MatrixBenchMatrixSource_SoftwareUnit*) memoryManager_allocate((DSPEElement*) context, sizeof(MatrixBenchMatrixSource_SoftwareUnit));
	context->MatrixMultiplier = (MatrixBenchMatrixMultiplier_SoftwareUnit*) memoryManager_allocate((DSPEElement*) context, sizeof(MatrixBenchMatrixMultiplier_SoftwareUnit));
	context->MatrixTarget = (MatrixBenchMatrixTarget_SoftwareUnit*) memoryManager_allocate((DSPEElement*) context, sizeof(MatrixBenchMatrixTarget_SoftwareUnit));
	context->Evaluator = (MicroBenchEvaluator_SoftwareUnit*) memoryManager_allocate((DSPEElement*) context, sizeof(MicroBenchEvaluator_SoftwareUnit));

	/* Contained unit initialization */
	initDSPEElement((DSPEElement*) context->MatrixSource, (DSPEElement*) context);
	initDSPEElement((DSPEElement*) context->MatrixMultiplier, (DSPEElement*) context);
	initDSPEElement((DSPEElement*) context->MatrixTarget, (DSPEElement*) context);
	initDSPEElement((DSPEElement*) context->Evaluator, (DSPEElement*) context);

	/* Unit IDs initilization */
	context->MatrixSource->ID = stringSupport_generateID(context->namePrefix, MatrixSource_ID);
	context->MatrixMultiplier->ID = stringSupport_generateID(context->namePrefix, MatrixMultiplier_ID);
	context->MatrixTarget->ID = stringSupport_generateID(context->namePrefix, MatrixTarget_ID);
	context->Evaluator->ID = stringSupport_generateID(context->namePrefix, Evaluator_ID);

	/* Contained units earlyalloc() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_earlyAlloc(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_earlyAlloc(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_earlyAlloc(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_earlyAlloc(context->Evaluator);
}

/* Alloc function */
void MatrixBenchMatrixMicroBench_Configuration_alloc(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units alloc() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_alloc(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_alloc(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_alloc(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_alloc(context->Evaluator);
}

/* EarlyConnect function */
void MatrixBenchMatrixMicroBench_Configuration_earlyConnect(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units earlyConnect() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_earlyConnect(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_earlyConnect(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_earlyConnect(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_earlyConnect(context->Evaluator);
}

/* Connect function */
void MatrixBenchMatrixMicroBench_Configuration_connect(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units data gates connection */
	context->MatrixMultiplier->dataIn_In = context->MatrixSource->dataOut_Out;
	context->MatrixTarget->dataIn_In = context->MatrixMultiplier->dataOut_Out;
	context->Evaluator->dataIn_Start = context->MatrixSource->dataOut_Start;
	context->Evaluator->dataIn_Stop = context->MatrixTarget->dataOut_Stop;

	/* Contained units parameter gates connection */
	context->MatrixSource->paramIn_Trigger = context->Evaluator->paramOut_Trigger;

	/* Initialize numLinks state vars */
	context->Evaluator->dataIn_Start_numLinks += 1;
	context->Evaluator->dataIn_Stop_numLinks += 1;
	context->MatrixMultiplier->dataIn_In_numLinks += 1;
	context->MatrixSource->paramIn_Trigger_numLinks += 1;
	context->MatrixTarget->dataIn_In_numLinks += 1;

	/* Initialize numLinks state vars */
	context->Evaluator->paramOut_Trigger_numLinks += 1;
	context->MatrixMultiplier->dataOut_Out_numLinks += 1;
	context->MatrixSource->dataOut_Out_numLinks += 1;
	context->MatrixSource->dataOut_Start_numLinks += 1;
	context->MatrixTarget->dataOut_Stop_numLinks += 1;

	/* Contained units connect() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_connect(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_connect(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_connect(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_connect(context->Evaluator);
}

/* Startup function */
void MatrixBenchMatrixMicroBench_Configuration_startup(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Config settings */
	infoManager_writeInfo((DSPEElement*) context, "%s SETTINGS", context->namePrefix);
	infoManager_writeInfo((DSPEElement*) context, " - blockProcessing: disabled");

	/* Contained units startup() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_startup(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_startup(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_startup(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_startup(context->Evaluator);
}

/* PreProcess function */
void MatrixBenchMatrixMicroBench_Configuration_preProcess(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units preprocess() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_preProcess((DSPEComponent*) context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_preProcess((DSPEComponent*) context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_preProcess((DSPEComponent*) context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_preProcess((DSPEComponent*) context->Evaluator);
}

/* Process function */
void MatrixBenchMatrixMicroBench_Configuration_process(MatrixBenchMatrixMicroBench_Configuration *context) {
	DSPEApplication *application = ((DSPEElement*) context)->application;
	DSPEComponent *component;

	/* Contained units process() calls sequence */
	component = (DSPEComponent*) context->MatrixSource;
	component->process(component);
	component = (DSPEComponent*) context->MatrixMultiplier;
	component->process(component);
	component = (DSPEComponent*) context->MatrixTarget;
	component->process(component);
	component = (DSPEComponent*) context->Evaluator;
	component->process(component);

	engineManager_forceCriticalSection((DSPEElement*) application);
}

/* PostProcess function */
void MatrixBenchMatrixMicroBench_Configuration_postProcess(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units postProcess() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_postProcess((DSPEComponent*) context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_postProcess((DSPEComponent*) context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_postProcess((DSPEComponent*) context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_postProcess((DSPEComponent*) context->Evaluator);
}

/* Reset function */
void MatrixBenchMatrixMicroBench_Configuration_reset(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units reset() call sequence */
	MatrixBenchMatrixSource_SoftwareUnit_reset(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_reset(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_reset(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_reset(context->Evaluator);
}

/* Shutdown function */
void MatrixBenchMatrixMicroBench_Configuration_shutdown(MatrixBenchMatrixMicroBench_Configuration *context) {

	/* Contained units shutdown() calls sequence */
	MatrixBenchMatrixSource_SoftwareUnit_shutdown(context->MatrixSource);
	MatrixBenchMatrixMultiplier_SoftwareUnit_shutdown(context->MatrixMultiplier);
	MatrixBenchMatrixTarget_SoftwareUnit_shutdown(context->MatrixTarget);
	MicroBenchEvaluator_SoftwareUnit_shutdown(context->Evaluator);

	/* Contained unit dispose */
	memorySupport_dispose(context->MatrixSource);
	memorySupport_dispose(context->MatrixMultiplier);
	memorySupport_dispose(context->MatrixTarget);
	memorySupport_dispose(context->Evaluator);
}

