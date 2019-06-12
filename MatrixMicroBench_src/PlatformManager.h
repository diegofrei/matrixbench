/**
 * File: PlatformManager.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
 */
#ifndef PlatformManager_h
#define PlatformManager_h

#include <stddef.h>
#ifdef _MSC_VER
/* REMARK: Included here to avoid macro redefinition when using VisualStudio */
#include <stdarg.h>
#endif

// REMARK
// The following define is needed in order to enable 'rand_s' function under windows
// and has to be defined before the inclusion of stdlib.h header!
#define _CRT_RAND_S

// REMARK
// The following define is needed in order to enable affinity under linux
// See man page for pthread_setaffinity_np function
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif /* _GNU_SOURCE */

#define LINUX 1
#define GC_LINUX 1

#define INLINE inline

/* String compare no case defines */
#define stringCompareNoCase(first, second) strcasecmp(first, second)
#define stringNCompareNoCase(first, second, numChars) strncasecmp(first, second, numChars)

/* String to number conversion defines */
#define strToLongLong(str, ptr) strtoll(str, ptr, 10)
#define strToULongLong(str, ptr) strtoull(str, ptr, 10)
#define strToLongDouble(res, str, ptr) res = strtold(str, ptr)

/* Thread delay define */
#define threadDelay(time) nanosleep(&time, NULL)
/* Thread num processors */
#define threadNumProcessors() return (unsigned int) sysconf(_SC_NPROCESSORS_ONLN)

/* Profiling support */

#include <time.h>

typedef clock_t DSPEProfileTime;

#define DSPEProfileTime_getMilliseconds(a)	(((double) a * 1000.0) / CLOCKS_PER_SEC)
#define DSPEProfileTime_setCurrentTicks(a)	a = clock()
#define DSPEProfileTime_add(a, b) 			(a) += (b)
#define DSPEProfileTime_sub(a, b) 			(a) -= (b)
#define DSPEProfileTime_div(a, b) 			(a) /= (b)
#define DSPEProfileTime_isSet(a) 			((a) != 0)
#define DSPEProfileTime_cmp(a, b, cmp)		((a) cmp (b))
#define DSPEProfileTime_init(a)  			(a) = 0
#define DSPEProfileTime_initMin(a)			(a) = LONG_MAX
#endif
