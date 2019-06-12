/**
 * File: CRunner.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#include "ErrorManager.h"
#include "MemoryManager.h"
#include "EngineManager.h"
#include "InfoManager.h"
#include "ProfileManager.h"
#include "InfoManager.h"

#include "RunnerGround.h"
#include "RunnerSupport.h"
#include "TextualRepresentation.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

MatrixBenchMatrixMicroBench_Application_cmd *context;

/**
 * StopEngine function.
 * Called when Ctrl-C is pressed.
 */
void stopEngine(int signal) {
	engineManager_stop((DSPEElement*) context);
}

/**
 * QuitEngine function.
 * Called when TERM signal is set to process.
 */
void quitEngine(int signal) {
	engineManager_quit((DSPEElement*) context);
}

/**
 * Main function
 */
int main(int argc, char *argv[]) {
	int currArg = 1;
	int lastOpt = 0;
	int err = 0;
	long int iter = 0;
	char *opt = NULL;

	/* Execution announcement */
	printf("\nApplication in execution.\n");
	printf("Application name: ...... MatrixMicroBench\n");
	printf("System name: ........... MatrixBench\n");
	printf("Runtime mode: .......... CommandLine\n");
	fflush(stdout);

	if (argc > 1) {
		if (handleOptionsWithoutValue(argv[currArg]))
			return 0;
	}

	/* CTRL+C signal handler initialization */
	signal(SIGINT, stopEngine);

	/* TERM signal handler initialization */
	signal(SIGTERM, quitEngine);

	/* Initialize runner */
	context = initializeRunner();
	if (context == NULL)
		return 1;

	/* Handle options */
	for (currArg = 1; currArg < argc; currArg++) {

		opt = argv[currArg];
		if (currArg + 1 >= argc) lastOpt = 1;

		if (handleOptions(context, opt, argv[++currArg], &err, &iter, lastOpt) || err)
			return 1;
  	}

	/* Start runner */
	engineManager_run((DSPEElement*) context);

	/* Benchmark run - while benchmark has not completed */
	while (!engineManager_isStopped((DSPEElement*) context)) {
		/* start runner processing */
		run(context, iter);
	}
	/* Destroy runner */
	destroyRunner(context);

	return 0;
}

