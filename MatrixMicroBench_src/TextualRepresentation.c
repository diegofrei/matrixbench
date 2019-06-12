/**
 * File: TextualRepresentation.c
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#include "StringManager.h"
#include "MemoryManager.h"
#include "InfoManager.h"

#include "TextualRepresentation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * InitializeCurValues function.
 */
void initializeCurValues(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	/* GUI current values allocation */
	context->paramIn_SignalDelay_curValue = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_AutomaticStop_curValue = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_SamplesToProcess_curValue = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_ShowInfo_curValue = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
	context->paramIn_SignalSource_curValue = MicroBenchFlag_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_SamplesCount_curValue = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_SentSignals_curValue = MicroBenchSignalsCount_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_ReceivedSignals_curValue = MicroBenchSignalsCount_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_OutOfSynchSamples_curValue = MicroBenchCounter_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_ElapsedTime_curValue = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Throughput_curValue = MicroBenchSamplesPerSecond_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Min_L_curValue = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Mean_L_curValue = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Max_L_curValue = MicroBenchTime_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Min_Lag_curValue = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Mean_Lag_curValue = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);
	context->paramOut_Max_Lag_curValue = MicroBenchNumSamples_StandardGate_allocate((DSPEElement*) context);

	/* GUI current values initialization */
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramIn_SignalDelay_curValue);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramIn_AutomaticStop_curValue);
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramIn_SamplesToProcess_curValue);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramIn_ShowInfo_curValue);
	MicroBenchFlag_StandardGate_initialize((DSPEElement*) context, context->paramIn_SignalSource_curValue);
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramOut_SamplesCount_curValue);
	MicroBenchSignalsCount_StandardGate_initialize((DSPEElement*) context, context->paramOut_SentSignals_curValue);
	MicroBenchSignalsCount_StandardGate_initialize((DSPEElement*) context, context->paramOut_ReceivedSignals_curValue);
	MicroBenchCounter_StandardGate_initialize((DSPEElement*) context, context->paramOut_OutOfSynchSamples_curValue);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_ElapsedTime_curValue);
	MicroBenchSamplesPerSecond_StandardGate_initialize((DSPEElement*) context, context->paramOut_Throughput_curValue);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Min_L_curValue);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Mean_L_curValue);
	MicroBenchTime_StandardGate_initialize((DSPEElement*) context, context->paramOut_Max_L_curValue);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Min_Lag_curValue);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Mean_Lag_curValue);
	MicroBenchNumSamples_StandardGate_initialize((DSPEElement*) context, context->paramOut_Max_Lag_curValue);

}

/**
 * DisposeCurValues function.
 */
void disposeCurValues(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	/* GUI current values dispose */
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramIn_SignalDelay_curValue);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramIn_AutomaticStop_curValue);
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramIn_SamplesToProcess_curValue);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramIn_ShowInfo_curValue);
	MicroBenchFlag_StandardGate_dispose((DSPEElement*) context, context->paramIn_SignalSource_curValue);
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramOut_SamplesCount_curValue);
	MicroBenchSignalsCount_StandardGate_dispose((DSPEElement*) context, context->paramOut_SentSignals_curValue);
	MicroBenchSignalsCount_StandardGate_dispose((DSPEElement*) context, context->paramOut_ReceivedSignals_curValue);
	MicroBenchCounter_StandardGate_dispose((DSPEElement*) context, context->paramOut_OutOfSynchSamples_curValue);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_ElapsedTime_curValue);
	MicroBenchSamplesPerSecond_StandardGate_dispose((DSPEElement*) context, context->paramOut_Throughput_curValue);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Min_L_curValue);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Mean_L_curValue);
	MicroBenchTime_StandardGate_dispose((DSPEElement*) context, context->paramOut_Max_L_curValue);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Min_Lag_curValue);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Mean_Lag_curValue);
	MicroBenchNumSamples_StandardGate_dispose((DSPEElement*) context, context->paramOut_Max_Lag_curValue);

}

/**
 * Fixup function
 */
MicroBenchFlag_StandardGate MicroBenchFlag_StandardGate_fixup(DSPEElement *context, MicroBenchFlag_StandardGate value, MicroBenchFlag_StandardGate *lastValue) {
	if (value != MICROBENCHFLAG_STANDARDGATE_POSSIBLEVALUE0 &&
		value != MICROBENCHFLAG_STANDARDGATE_POSSIBLEVALUE1) {
		infoManager_writeInfo(context, "\nPOSSIBLE VALUE not respected: %d replaced with %d",  value, *lastValue);
	 	value = *lastValue;
	}
	return value;
}

/**
 * OptionPn function.
 * Sets input parameters values
 */
void optionPn(MatrixBenchMatrixMicroBench_Application_cmd *context, char *opt, char *value, int *err) {
	MicroBenchCounter_StandardGate MicroBenchCounter_StandardGate_converted;
	MicroBenchFlag_StandardGate MicroBenchFlag_StandardGate_converted;
	char *endp;
	errno = 0;
	if (stringSupport_compareNoCase(opt, "-p0") == 0) {
		/* Convert value */
		MicroBenchCounter_StandardGate_converted = strtol(value, &endp, 10);
		if (value == endp) {
			printf("\nERROR: p0 value is not an long integer!\n");
			*err = 1;
			return;
		}
		if (errno == ERANGE) {
			printf("\nERROR: p0 value overflow!\n");
			*err = 1;
			return;
		}
		/* Update current value */
		*context->paramIn_SignalDelay_curValue = MicroBenchCounter_StandardGate_converted;

		/* Updates parameter inputs */
		*((MatrixBenchMatrixMicroBench_Application*) context)->paramIn_SignalDelay = MicroBenchCounter_StandardGate_converted;

	} else if (stringSupport_compareNoCase(opt, "-p1") == 0) {
		/* Convert value */
		if (stringSupport_compareNoCase(value, "true") == 0) {
			MicroBenchFlag_StandardGate_converted = 1;
		} else if (stringSupport_compareNoCase(value, "false") == 0) {
			MicroBenchFlag_StandardGate_converted = 0;
		} else {		
			MicroBenchFlag_StandardGate_converted = (int) strtol(value, &endp, 10);
			if (value == endp) {
				printf("\nERROR: p1 value is not an integer!\n");
				*err = 1;
				return;
			}
			if (errno == ERANGE) {
				printf("\nERROR: p1 value overflow!\n");
				*err = 1;
				return;
			}
		}
	/* Fixup converted value */
		MicroBenchFlag_StandardGate_converted = MicroBenchFlag_StandardGate_fixup((DSPEElement*) context, MicroBenchFlag_StandardGate_converted, context->paramIn_AutomaticStop_curValue);

		/* Update current value */
		*context->paramIn_AutomaticStop_curValue = MicroBenchFlag_StandardGate_converted;

		/* Updates parameter inputs */
		*((MatrixBenchMatrixMicroBench_Application*) context)->paramIn_AutomaticStop = MicroBenchFlag_StandardGate_converted;

	} else if (stringSupport_compareNoCase(opt, "-p2") == 0) {
		/* Convert value */
		MicroBenchCounter_StandardGate_converted = strtol(value, &endp, 10);
		if (value == endp) {
			printf("\nERROR: p2 value is not an long integer!\n");
			*err = 1;
			return;
		}
		if (errno == ERANGE) {
			printf("\nERROR: p2 value overflow!\n");
			*err = 1;
			return;
		}
		/* Update current value */
		*context->paramIn_SamplesToProcess_curValue = MicroBenchCounter_StandardGate_converted;

		/* Updates parameter inputs */
		*((MatrixBenchMatrixMicroBench_Application*) context)->paramIn_SamplesToProcess = MicroBenchCounter_StandardGate_converted;

	} else if (stringSupport_compareNoCase(opt, "-p3") == 0) {
		/* Convert value */
		if (stringSupport_compareNoCase(value, "true") == 0) {
			MicroBenchFlag_StandardGate_converted = 1;
		} else if (stringSupport_compareNoCase(value, "false") == 0) {
			MicroBenchFlag_StandardGate_converted = 0;
		} else {		
			MicroBenchFlag_StandardGate_converted = (int) strtol(value, &endp, 10);
			if (value == endp) {
				printf("\nERROR: p3 value is not an integer!\n");
				*err = 1;
				return;
			}
			if (errno == ERANGE) {
				printf("\nERROR: p3 value overflow!\n");
				*err = 1;
				return;
			}
		}
	/* Fixup converted value */
		MicroBenchFlag_StandardGate_converted = MicroBenchFlag_StandardGate_fixup((DSPEElement*) context, MicroBenchFlag_StandardGate_converted, context->paramIn_ShowInfo_curValue);

		/* Update current value */
		*context->paramIn_ShowInfo_curValue = MicroBenchFlag_StandardGate_converted;

		/* Updates parameter inputs */
		*((MatrixBenchMatrixMicroBench_Application*) context)->paramIn_ShowInfo = MicroBenchFlag_StandardGate_converted;

	} else if (stringSupport_compareNoCase(opt, "-p4") == 0) {
		/* Convert value */
		if (stringSupport_compareNoCase(value, "true") == 0) {
			MicroBenchFlag_StandardGate_converted = 1;
		} else if (stringSupport_compareNoCase(value, "false") == 0) {
			MicroBenchFlag_StandardGate_converted = 0;
		} else {		
			MicroBenchFlag_StandardGate_converted = (int) strtol(value, &endp, 10);
			if (value == endp) {
				printf("\nERROR: p4 value is not an integer!\n");
				*err = 1;
				return;
			}
			if (errno == ERANGE) {
				printf("\nERROR: p4 value overflow!\n");
				*err = 1;
				return;
			}
		}
	/* Fixup converted value */
		MicroBenchFlag_StandardGate_converted = MicroBenchFlag_StandardGate_fixup((DSPEElement*) context, MicroBenchFlag_StandardGate_converted, context->paramIn_SignalSource_curValue);

		/* Update current value */
		*context->paramIn_SignalSource_curValue = MicroBenchFlag_StandardGate_converted;

		/* Updates parameter inputs */
		*((MatrixBenchMatrixMicroBench_Application*) context)->paramIn_SignalSource = MicroBenchFlag_StandardGate_converted;

	} else {
		printf("\nERROR: %s is not an option!\n", opt);
		*err = 1;
		return;
	}

}

/**
 * convertGatenameToOptionPn function.
 */
static INLINE char* convertGatenameToOptionPn(char* gateName) {
	if (stringSupport_compareNoCase(gateName, "SignalDelay") == 0 || stringSupport_compareNoCase(gateName, "p0") == 0)
		return "-p0";
	if (stringSupport_compareNoCase(gateName, "AutomaticStop") == 0 || stringSupport_compareNoCase(gateName, "p1") == 0)
		return "-p1";
	if (stringSupport_compareNoCase(gateName, "SamplesToProcess") == 0 || stringSupport_compareNoCase(gateName, "p2") == 0)
		return "-p2";
	if (stringSupport_compareNoCase(gateName, "ShowInfo") == 0 || stringSupport_compareNoCase(gateName, "p3") == 0)
		return "-p3";
	if (stringSupport_compareNoCase(gateName, "SignalSource") == 0 || stringSupport_compareNoCase(gateName, "p4") == 0)
		return "-p4";
	return NULL;
}

/**
 * convertOptionPnToGatename function.
 */
static INLINE char* convertOptionPnToGatename(char* optionPn) {
	if (stringSupport_compareNoCase(optionPn, "-p0") == 0 || stringSupport_compareNoCase(optionPn, "p0") == 0)
		return "SignalDelay";
	if (stringSupport_compareNoCase(optionPn, "-p1") == 0 || stringSupport_compareNoCase(optionPn, "p1") == 0)
		return "AutomaticStop";
	if (stringSupport_compareNoCase(optionPn, "-p2") == 0 || stringSupport_compareNoCase(optionPn, "p2") == 0)
		return "SamplesToProcess";
	if (stringSupport_compareNoCase(optionPn, "-p3") == 0 || stringSupport_compareNoCase(optionPn, "p3") == 0)
		return "ShowInfo";
	if (stringSupport_compareNoCase(optionPn, "-p4") == 0 || stringSupport_compareNoCase(optionPn, "p4") == 0)
		return "SignalSource";
	return NULL;
}

/**
 * loadInputParameters function.
 */
void loadInputParameters(MatrixBenchMatrixMicroBench_Application_cmd *context, char *filePath) {
	FILE *file = fopen(filePath, "r");

	size_t i = 0;
	size_t curLine = 0;
	char tmp[2048];
	char *tmpPtr = tmp;
	char **record = NULL;
	const char *delim = ";\r\n";

	const size_t numInputParameters = 5;
	char *columsParams[5];
	char *columsNames[5];
	size_t columsParamsElements = 0;

	int isHeaderLine = 1;

	if (file == NULL) {
		// FIXME DF:  notify error by using errorManager / infoManager! 
		return;
	}

	memorySupport_resetBlock(tmp, sizeof(tmp));
	while (fgets(tmp, sizeof(tmp), file) != 0) {
		size_t len = 0;
		DSPEInputParameters *curr = NULL;
		tmpPtr = tmp;
		record = &tmpPtr;
		
		// REAMRK skip comment line #
		if (tmp[0] == '#')
			continue;

		// Parse header row containing parameters to work on
		if (isHeaderLine) {
			isHeaderLine = 0;

			for (i = 0; i < numInputParameters; i++) {
				columsParams[i] = NULL;
				columsNames[i] = NULL;
			}

			for (i = 0; i < numInputParameters; i++) {
				char *value = stringSupport_separate(record, delim);
				// Stop at first empty column
				if (value == NULL || *value == '\0')
					break;
				columsParams[i] = convertGatenameToOptionPn(value);
				// FIXME DF: improve error handling. Clarify if this has to fail silently (like now) or if this is a major problem and program needs to be stopped.
				if (columsParams[i] == NULL)
					infoManager_writeInfo((DSPEElement*) context, "Invalid header parameter: '%s'", value);
				else
					columsNames[i] = convertOptionPnToGatename(columsParams[i]);
				columsParamsElements++;
			}
			continue;
		}

		curLine++;
		
		// Start separating line by delimiter
		for (i = 0; i < columsParamsElements; i++) {
			char *stringValue = stringSupport_separate(record, delim);

			// FIXME DF: improve error handling. Clarify if this has to fail silently (like now) or if this is a major problem and program needs to be stopped.
			if (columsParams[i] == NULL)
				continue;

			if (stringValue != NULL && *stringValue != '\0') {
				size_t len = 0;
				DSPEInputParameterValue *value = (DSPEInputParameterValue*) allocateAndInitMemory((DSPEElement*) context, 1, sizeof(DSPEInputParameterValue));

				// Create value with gatename string, optionPn string and value string
				len = stringSupport_length(columsNames[i]);
				value->gateName = (char*) allocateAndInitMemory((DSPEElement*) context, (len + 1), sizeof(char));
				stringSupport_nCopy(value->gateName, columsNames[i], len);
				
				len = stringSupport_length(columsParams[i]);
				value->optionPnString = (char*) allocateAndInitMemory((DSPEElement*) context, (len + 1), sizeof(char));
				stringSupport_nCopy(value->optionPnString, columsParams[i], len);

				len = stringSupport_length(stringValue);
				value->value = (char*) allocateAndInitMemory((DSPEElement*) context, (len + 1), sizeof(char));
				stringSupport_nCopy(value->value, stringValue, len);

				if (curr == NULL)
					curr = DSPEInputParameters_create((DSPEApplication*) context);

				// Append value to current inputParameters
				if (curr->numParams == 0) {
					curr->numParams = 1;
					curr->headParam = value;
					curr->tailParam = value;
				} else {
					curr->numParams++;
					curr->tailParam->nextValue = value;
					curr->tailParam = value;
				}
			}
		}

		/* Reset buffer */
		memorySupport_resetBlock(tmp, sizeof(tmp));

		/* append inputParameters if found */
		if (curr != NULL) {
			if (context->inputParametersNumElements == 0) {
				context->inputParametersNumElements = 1;
				context->inputParametersHead = curr;
				context->inputParametersTail = curr;
				context->inputParametersCurr = curr;
			} else {
				context->inputParametersNumElements++;
				context->inputParametersTail->next = curr;
				context->inputParametersTail = curr;
			}
		}
	}
		
	/* close file */
	fclose(file);
}

/**
 * createInputParameterFile function.
 */
void createInputParameters(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	FILE *file = fopen("MatrixBenchMatrixMicroBench_Application.csv", "w+");

	if (file == NULL) {
		// FIXME DF:  notify error by using errorManager / infoManager! 
		return;
	}

	fprintf(file, "# Example input parameters file with default values\n");

	/* Gate Constraints */
	fprintf(file, "#SignalDelay;long int;\n");
	fprintf(file, "#AutomaticStop;bool;AutomaticStop = {0, 1}\n");
	fprintf(file, "#SamplesToProcess;long int;\n");
	fprintf(file, "#ShowInfo;bool;ShowInfo = {0, 1}\n");
	fprintf(file, "#SignalSource;bool;SignalSource = {0, 1}\n");

	/* Header row containing gate names which values will be specified in the exact same order on the following rows */
	fprintf(file, "SignalDelay;");
	fprintf(file, "AutomaticStop;");
	fprintf(file, "SamplesToProcess;");
	fprintf(file, "ShowInfo;");
	fprintf(file, "SignalSource;");
	fprintf(file, "\n");


	/* Default value row */
	fprintf(file, "0L;");
	fprintf(file, "0;");
	fprintf(file, "0L;");
	fprintf(file, "0;");
	fprintf(file, "0;");
	fprintf(file, "\n");

	/* close file */
	fclose(file);
}

/**
 * optionG function.
 * Displays the selected gate constraints.
 */
void optionG(MatrixBenchMatrixMicroBench_Application_cmd *context, char *value, int *err) {
	printf("\nGATE FEATURES:\n\n");

	/* MicroBenchCounter_StandardGate features */
	if (stringSupport_compareNoCase(value, "p0") == 0 || stringSupport_compareNoCase(value, "p2") == 0) {
		infoManager_writeInfo((DSPEElement*) context, "TYPE CATEGORY: .......... %s", MICROBENCHCOUNTER_STANDARDGATE_TYPECATEGORY);
		infoManager_writeInfo((DSPEElement*) context, "TYPE: ................... long int");
		infoManager_writeInfo((DSPEElement*) context, "DEFINITION DEFAULT: ..... %ld",  MICROBENCHCOUNTER_STANDARDGATE_DEFAULTVALUE);
		infoManager_writeInfo((DSPEElement*) context, "QUALIFIER: .............. Samples");
	/* MicroBenchFlag_StandardGate features */
	} else if (stringSupport_compareNoCase(value, "p1") == 0 || stringSupport_compareNoCase(value, "p3") == 0 || stringSupport_compareNoCase(value, "p4") == 0) {
		infoManager_writeInfo((DSPEElement*) context, "TYPE CATEGORY: .......... %s", MICROBENCHFLAG_STANDARDGATE_TYPECATEGORY);
		infoManager_writeInfo((DSPEElement*) context, "TYPE: ................... int");
		infoManager_writeInfo((DSPEElement*) context, "DEFINITION DEFAULT: ..... %d",  MICROBENCHFLAG_STANDARDGATE_DEFAULTVALUE);
		infoManager_writeInfo((DSPEElement*) context, "QUALIFIER: .............. (none)");
		infoManager_writeInfo((DSPEElement*) context, "POSSIBLE VALUE0: ........ %d", MICROBENCHFLAG_STANDARDGATE_POSSIBLEVALUE0);
		infoManager_writeInfo((DSPEElement*) context, "POSSIBLE VALUE1: ........ %d", MICROBENCHFLAG_STANDARDGATE_POSSIBLEVALUE1);
	} else {
		infoManager_writeInfo((DSPEElement*) context, "\nERROR: option -g value is not a gate!");
	}
}

/**
 * OptionI function. Sets the number of process iterances.
 */
int optionI(char *value, int *err) {
	int iter = 0;
	char *endp;
	errno = 0;

	iter = (int)strtol(value, &endp, 10);
	if (value == endp) {
		printf("\nERROR: -i value is not an integer!\n");
		*err = 1;
		return 0;
	}
	if (errno == ERANGE) {
		printf("\nERROR: -i value overflow!\n");
		*err = 1;
		return 0;
	}
	return iter;
}

/**
 * OptionP function.
 * Displays the parameters input mapping.
 */
void optionP() {
	printf("\nPARAMETER INPUTS:\n\n");
	printf("-p0 ............. SignalDelay\n");
	printf("-p1 ............. AutomaticStop\n");
	printf("-p2 ............. SamplesToProcess\n");
	printf("-p3 ............. ShowInfo\n");
	printf("-p4 ............. SignalSource\n");
}

/**
 * OptionH function
 * Display the help.
 */
void optionH() {
	printf("\nHELP:\n\n");
	printf("-i <value> .............. Set process iterances\n");
	printf("-p ...................... Display list of gates\n");
	printf("-g <gate> ............... Display gate constraints\n");
	printf("-loadParams <file.csv> .. Load input parameters from file\n");
	printf("-createParams ........... Creates input parameters file 'MatrixBenchMatrixMicroBench_Application.csv' with default values\n");
}

/**
 * HandleOptionsWithoutValue function.
 * Handles all options without value, such as -h, -p and -u.
 * Returns 1 if execution has to be stopped.
 */
int handleOptionsWithoutValue(char *opt) {
	if (stringSupport_compareNoCase(opt, "-h") == 0) {
		optionH();
		return 1;
	}
	else if (stringSupport_compareNoCase(opt, "-p") == 0) {
		optionP();
		return 1;
	}
	return 0;
}

/**
 * HandleOptions function.
 * Returns 1 if execution has to be stopped.
 */
int handleOptions(MatrixBenchMatrixMicroBench_Application_cmd *context, char *opt, char *value, int *err, long int *iter, int lastOpt) {
	/* set parameters options */
	if (opt[0] =='-' && opt[1] == 'p') {
		if (lastOpt) {
			infoManager_writeInfo((DSPEElement*) context, "ERROR: Option %s without value!", opt);
			return 1;
		}
		optionPn(context, opt, value, err);

	} else if (stringSupport_nCompareNoCase(opt, "-loadParams", 11) == 0) {
		if (lastOpt) {
			infoManager_writeInfo((DSPEElement*) context, "ERROR: Option %s without value!", opt);
			return 1;
		}
		loadInputParameters(context, value);

	} else if (stringSupport_nCompareNoCase(opt, "-createParams", 13) == 0) {
		/* Creates default inputParameters file */
		createInputParameters(context);
		return 1;
	/* set iterances options */
	} else if (stringSupport_compareNoCase(opt, "-i") == 0) {
		if (lastOpt) {
			infoManager_writeInfo((DSPEElement*) context, "ERROR: Option %s without value!", opt);
			return 1;
		}
		*iter = optionI(value, err);

	/* show gate constraints */
	} else if (stringSupport_compareNoCase(opt, "-g") == 0) {
		if (lastOpt) {
			infoManager_writeInfo((DSPEElement*) context, "ERROR: Option %s without value!", opt);
			return 1;
		}
		optionG(context, value, err);
		return 1;


	/* invalid option */
	} else {
		infoManager_writeInfo((DSPEElement*) context, "ERROR: %s is not an option!", opt);
		return 1;
	}
	return 0;
}

/**
 * DisplayOutput function.
 * Display parameter output values.
 */
void displayOutput(MatrixBenchMatrixMicroBench_Application_cmd *context) {
	/* display output */
	printf("\nPARAMETER OUTPUTS:\n\n");
	printf("SamplesCount = %ld\tSamples\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_SamplesCount);
	printf("SentSignals = %lu\tSignals\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_SentSignals);
	printf("ReceivedSignals = %lu\tSignals\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_ReceivedSignals);
	printf("OutOfSynchSamples = %ld\tSamples\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_OutOfSynchSamples);
	printf("ElapsedTime = %.8lf\tSeconds\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_ElapsedTime);
	printf("Throughput = %.8lf\tSamplesPerSecond\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Throughput);
	printf("Min_L = %.8lf\tSeconds\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Min_L);
	printf("Mean_L = %.8lf\tSeconds\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Mean_L);
	printf("Max_L = %.8lf\tSeconds\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Max_L);
	printf("Min_Lag = %ld\tSamples\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Min_Lag);
	printf("Mean_Lag = %ld\tSamples\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Mean_Lag);
	printf("Max_Lag = %ld\tSamples\n",  *((MatrixBenchMatrixMicroBench_Application*) context)->paramOut_Max_Lag);

}

