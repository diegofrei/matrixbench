/**
 * File: MatrixBenchMatrixMicroBench_Application.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:25 CEST 2019
 */
#include "PlatformManager.h"
#include "StringManager.h"
#include "MemoryManager.h"
#include "InfoManager.h"

#include "MatrixBenchMatrixMicroBench_Application.h"

#define MatrixMicroBench_ID "MatrixMicroBench"


/* getID function */
char* MatrixBenchMatrixMicroBench_Application_getID(const DSPEElement *element) {
	return ((const MatrixBenchMatrixMicroBench_Application*) element)->ID;
}

/* Initialize gate values */
static INLINE void initValues(MatrixBenchMatrixMicroBench_Application *context) {

	/* Application input parameters places initialization */
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramIn_SignalDelay_place);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramIn_AutomaticStop_place);
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramIn_SamplesToProcess_place);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramIn_ShowInfo_place);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramIn_SignalSource_place);

}

/* EarlyAlloc function */
void MatrixBenchMatrixMicroBench_Application_earlyAlloc(MatrixBenchMatrixMicroBench_Application *context) {

	initDSPEElement((DSPEElement*) &context->structure, (DSPEElement*) context);
	/* Initializing process function pointer */
	((DSPEComponent*) context)->process = MatrixBenchMatrixMicroBench_Application_process;

	/* Application ID init */
	((DSPEElement*) context)->getID = MatrixBenchMatrixMicroBench_Application_getID;
	context->ID = stringSupport_generateID(0, MatrixMicroBench_ID);
	/* Root configuration namePrefix init */
	context->structure.namePrefix = context->ID;


	/* Configuration earlyalloc() function call */
	MatrixBenchMatrixMicroBench_Configuration_earlyAlloc(&context->structure);
}

/* Alloc function */
void MatrixBenchMatrixMicroBench_Application_alloc(MatrixBenchMatrixMicroBench_Application *context) {

	/* Application input parameters places allocation */
	context->paramIn_SignalDelay_place = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_AutomaticStop_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_SamplesToProcess_place = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_ShowInfo_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_SignalSource_place = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);


	/* Configuration alloc() function call */
	MatrixBenchMatrixMicroBench_Configuration_alloc(&context->structure);

}

/* EarlyConnect function */
void MatrixBenchMatrixMicroBench_Application_earlyConnect(MatrixBenchMatrixMicroBench_Application *context) {
	/* Contained configuration local variable */
	MatrixBenchMatrixMicroBench_Configuration *structure = &context->structure;


	/* Application input parameters gates initialization */
	context->paramIn_SignalDelay = context->paramIn_SignalDelay_place;
	context->paramIn_AutomaticStop = context->paramIn_AutomaticStop_place;
	context->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess_place;
	context->paramIn_ShowInfo = context->paramIn_ShowInfo_place;
	context->paramIn_SignalSource = context->paramIn_SignalSource_place;


	/* Configuration earlyconnect() function call */
	MatrixBenchMatrixMicroBench_Configuration_earlyConnect(&context->structure);


	/* Configuration container parameter output gates initialization */
	context->paramOut_Throughput = structure->Evaluator->paramOut_Throughput;
	context->paramOut_Min_L = structure->Evaluator->paramOut_Min_L;
	context->paramOut_Max_L = structure->Evaluator->paramOut_Max_L;
	context->paramOut_SamplesCount = structure->Evaluator->paramOut_SamplesCount;
	context->paramOut_Min_Lag = structure->Evaluator->paramOut_Min_Lag;
	context->paramOut_Max_Lag = structure->Evaluator->paramOut_Max_Lag;
	context->paramOut_SentSignals = structure->MatrixSource->paramOut_SentSignals;
	context->paramOut_ReceivedSignals = structure->MatrixTarget->paramOut_ReceivedSignals;
	context->paramOut_Mean_L = structure->Evaluator->paramOut_Mean_L;
	context->paramOut_Mean_Lag = structure->Evaluator->paramOut_Mean_Lag;
	context->paramOut_ElapsedTime = structure->Evaluator->paramOut_ElapsedTime;
	context->paramOut_OutOfSynchSamples = structure->MatrixTarget->paramOut_OutOfSynchSamples;

}

/* Connect function */
void MatrixBenchMatrixMicroBench_Application_connect(MatrixBenchMatrixMicroBench_Application *context) {
	/* Contained configuration local variable */
	MatrixBenchMatrixMicroBench_Configuration *structure = &context->structure;


	/* Configuration container parameter input gates initialization */
	structure->Evaluator->paramIn_SignalDelay = context->paramIn_SignalDelay;
	structure->MatrixSource->paramIn_ShowInfo = context->paramIn_ShowInfo;
	structure->MatrixTarget->paramIn_ShowInfo = context->paramIn_ShowInfo;
	structure->Evaluator->paramIn_AutomaticStop = context->paramIn_AutomaticStop;
	structure->Evaluator->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess;
	structure->MatrixSource->paramIn_SignalSource = context->paramIn_SignalSource;
	structure->MatrixTarget->paramIn_SignalSource = context->paramIn_SignalSource;
	structure->MatrixSource->paramIn_AutomaticStop = context->paramIn_AutomaticStop;
	structure->MatrixSource->paramIn_SamplesToProcess = context->paramIn_SamplesToProcess;

	/* StructureContainer numLinks initialization */
	structure->Evaluator->paramIn_AutomaticStop_numLinks = 1;
	structure->Evaluator->paramIn_SamplesToProcess_numLinks = 1;
	structure->Evaluator->paramIn_SignalDelay_numLinks = 1;
	structure->MatrixSource->paramIn_AutomaticStop_numLinks = 1;
	structure->MatrixSource->paramIn_SamplesToProcess_numLinks = 1;
	structure->MatrixSource->paramIn_ShowInfo_numLinks = 1;
	structure->MatrixSource->paramIn_SignalSource_numLinks = 1;
	structure->MatrixTarget->paramIn_ShowInfo_numLinks = 1;
	structure->MatrixTarget->paramIn_SignalSource_numLinks = 1;

	/* StructureContainer numLinks initialization */
	structure->Evaluator->paramOut_ElapsedTime_numLinks = 1;
	structure->Evaluator->paramOut_Max_L_numLinks = 1;
	structure->Evaluator->paramOut_Max_Lag_numLinks = 1;
	structure->Evaluator->paramOut_Mean_L_numLinks = 1;
	structure->Evaluator->paramOut_Mean_Lag_numLinks = 1;
	structure->Evaluator->paramOut_Min_L_numLinks = 1;
	structure->Evaluator->paramOut_Min_Lag_numLinks = 1;
	structure->Evaluator->paramOut_SamplesCount_numLinks = 1;
	structure->Evaluator->paramOut_Throughput_numLinks = 1;
	structure->MatrixSource->paramOut_SentSignals_numLinks = 1;
	structure->MatrixTarget->paramOut_OutOfSynchSamples_numLinks = 1;
	structure->MatrixTarget->paramOut_ReceivedSignals_numLinks = 1;

	/* Configuration connect() function call */
	MatrixBenchMatrixMicroBench_Configuration_connect(&context->structure);
}

/* Startup function */
void MatrixBenchMatrixMicroBench_Application_startup(DSPEApplication *application) {
	MatrixBenchMatrixMicroBench_Application *context = (MatrixBenchMatrixMicroBench_Application*) application;
	/* Base earlyalloc() function call */
	MatrixBenchMatrixMicroBench_Application_earlyAlloc(context);

	/* Base alloc() function call */
	MatrixBenchMatrixMicroBench_Application_alloc(context);


	/* Initialize gate values */
	initValues(context);

	/* Base earlyconnect() function call */
	MatrixBenchMatrixMicroBench_Application_earlyConnect(context);

	/* Base connect() function call */
	MatrixBenchMatrixMicroBench_Application_connect(context);

	infoManager_writeInfo((DSPEElement*) context, "RUNTIME SETTINGS");
	infoManager_writeInfo((DSPEElement*) context, " - Multirun  benchmark : disabled");
	infoManager_writeInfo((DSPEElement*) context, " - Blocksize benchmark : disabled");
	/* Runner settings overview */
	infoManager_writeInfo((DSPEElement*) context, "THREADING SETTINGS");
	infoManager_writeInfo((DSPEElement*) context, " - ThreadingSystem : PThreads");
	infoManager_writeInfo((DSPEElement*) context, " - SpinLocks : enabled");
	infoManager_writeInfo((DSPEElement*) context, " - SpecificThreadCreation : disabled");
	infoManager_writeInfo((DSPEElement*) context, " - AutomaticallyAssignAffinity : None");
	infoManager_writeInfo((DSPEElement*) context, "(PROTO) ProfileQueue on owner");

	/* Configuration startup() function call */
	MatrixBenchMatrixMicroBench_Configuration_startup(&context->structure);

	infoManager_writeInfo((DSPEElement*) context, "--------------------------------------------------------------------------------\n");

}

/* PreProcess function */
void MatrixBenchMatrixMicroBench_Application_preProcess(DSPEComponent *component) {
	MatrixBenchMatrixMicroBench_Application *context = (MatrixBenchMatrixMicroBench_Application*) component;

	/* Configuration preprocess() function call */
	MatrixBenchMatrixMicroBench_Configuration_preProcess(&context->structure);

}

/* Process function */
void MatrixBenchMatrixMicroBench_Application_process(DSPEComponent *component) {
	MatrixBenchMatrixMicroBench_Application *context = (MatrixBenchMatrixMicroBench_Application*) component;

	/* Configuration process() function call */
	MatrixBenchMatrixMicroBench_Configuration_process(&context->structure);

}

/* PostProcess function */
void MatrixBenchMatrixMicroBench_Application_postProcess(DSPEComponent *component) {
	MatrixBenchMatrixMicroBench_Application *context = (MatrixBenchMatrixMicroBench_Application*) component;

	/* Configuration postprocess() function call */
	MatrixBenchMatrixMicroBench_Configuration_postProcess(&context->structure);

}

/* Reset function */
void MatrixBenchMatrixMicroBench_Application_reset(DSPEComponent *component) {
	MatrixBenchMatrixMicroBench_Application *context = (MatrixBenchMatrixMicroBench_Application*) component;

	/* Configuration reset() function call */
	MatrixBenchMatrixMicroBench_Configuration_reset(&context->structure);

	/* Initialize gate values */
	initValues(context);

}

/* Shutdown function */
void MatrixBenchMatrixMicroBench_Application_shutdown(DSPEApplication *application) {
	MatrixBenchMatrixMicroBench_Application *context = (MatrixBenchMatrixMicroBench_Application*) application;

	/* Configuration shutdown() function call */
	MatrixBenchMatrixMicroBench_Configuration_shutdown(&context->structure);

	/* Application input parameters places dispose */
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramIn_SignalDelay_place);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramIn_AutomaticStop_place);
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramIn_SamplesToProcess_place);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramIn_ShowInfo_place);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramIn_SignalSource_place);

	/* Dispose application ID */
	memorySupport_dispose(context->ID);

}

