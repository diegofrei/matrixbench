/**
 * File: StringManager.c
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#include "StringManager.h"

#include "RunnerGround.h"

#include <stdlib.h>
#include <string.h>

/**
 * StringSupport_copy function
 */
char* stringSupport_copy(char *destination, const char *source) {
	return strcpy(destination, source);
}

/**
 * StringSupport_nCopy function
 */
char* stringSupport_nCopy(char *destination, const char *source, size_t numChars) {
	return strncpy(destination, source, numChars);
}

/**
 * StringSupport_compare function
 */
int stringSupport_compare(const char *first, const char *second) {
	return strcmp(first, second);
}

/**
 * StringSupport_nCompare function
 */
int stringSupport_nCompare(const char *first, const char *second, size_t numChars) {
	return strncmp(first, second, numChars);
}

/**
 * StringSupport_compareNoCase function
 */
int stringSupport_compareNoCase(const char *first, const char *second) {
	return stringCompareNoCase(first, second);
}

/**
 * StringSupport_nCompareNoCase function
 */
int stringSupport_nCompareNoCase(const char *first, const char *second, size_t numChars) {
	return stringNCompareNoCase(first, second, numChars);
}

/**
 * StringSupport_length function
 */
size_t stringSupport_length(const char *string) {
	return strlen(string);
}

/**
 * StringSupport_concat function
 */
char* stringSupport_concat(char *destination, const char *source) {
	return strcat(destination, source);
}

/**
 * StringSupport_separate function
 * similar to strtok except that it returns an empty string instead of skipping an empty value
 * Example string :"a,b,c,,,d"
 * strtok: returns "a", "b", "c", "d"
 * strsep: returns "a", "b", "c", "", "", "d"
 */
char* stringSupport_separate(char **string, const char *delim) {
	register char *s;
	register const char *spanp;
	register int c, sc;
	char *tok;

	if ((s = *string) == NULL)
		return (NULL);
	for (tok = s;;) {
		c = *s++;
		spanp = delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*string = s;
				return (tok);
			}
		} while (sc != 0);
	}
	/* NOTREACHED */
}

/**
 * StringSupport_generateID function
 */
char* stringSupport_generateID(const char *prefix, const char *unitName) {
	register size_t prefixL = (prefix == 0) ? 0 : strlen(prefix);
	char *tmp;
	if (prefixL > 0) {
		// size: 1 for '_' + 1 for '\0' + prefixLenght + unitNameLenght
		tmp = (char*) allocateMemory(NULL, (2 + prefixL + strlen(unitName)) * sizeof(char));
		tmp[0] = '\0';
		tmp = strcat(tmp, prefix);
		tmp = strcat(tmp, "_");
		return strcat(tmp, unitName);
	} else {
		// size: 1 for '\0' + unitNameLenght
		tmp = (char*) allocateMemory(NULL, (1 + strlen(unitName)) * sizeof(char));
		tmp[0] = '\0';
		return strcat(tmp, unitName);
	}
}

