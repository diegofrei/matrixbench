/**
 * File: StringManager.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:52 CEST 2019
 */
#ifndef StringManager_h
#define StringManager_h

#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * StringSupport_copy function
 */
char* stringSupport_copy(char *destination, const char *source);

/**
 * StringSupport_nCopy function
 */
char* stringSupport_nCopy(char *destination, const char *source, size_t numChars);

/**
 * StringSupport_compare function
 */
int stringSupport_compare(const char *first, const char *second);

/**
 * StringSupport_nCompare function
 */
int stringSupport_nCompare(const char *first, const char *second, size_t numChars);

/**
 * StringSupport_compareNoCase function
 */
int stringSupport_compareNoCase(const char *first, const char *second);

/**
 * StringSupport_nCompareNoCase function
 */
int stringSupport_nCompareNoCase(const char *first, const char *second, size_t numChars);

/**
 * StringSupport_length function
 */
size_t stringSupport_length(const char *string);

/**
 * StringSupport_concat function
 */
char* stringSupport_concat(char *destination, const char *source);

/**
 * StringSupport_separate function
 * similar to strtok except that it returns an empty string instead of skipping an empty value
 * Example string :"a,b,c,,,d"
 * strtok: returns "a", "b", "c", "d"
 * strsep: returns "a", "b", "c", "", "", "d"
 */
char* stringSupport_separate(char **string, const char *delim);

/**
 * StringSupport_generateID function
 */
char* stringSupport_generateID(const char *prefix, const char *unitName);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
