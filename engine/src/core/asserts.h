#pragma once

#include "defines.h"

//Disable assertions by commenting out the below line.
#define M_ASSERTIONS_ENABLED

#ifdef M_ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

M_API void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define M_ASSERT(expression) \
    do { \
        if (expression) { \
            /* Do nothing */ \
        } else { \
            report_assertion_failure(#expression, "", __FILE__, __LINE__); \
            debugBreak(); \
        } \
    } while (0)

#define M_ASSERT_MSG(expression, message) \
    do { \
        if (expression) { \
            /* Do nothing */ \
        } else { \
            report_assertion_failure(#expression, message, __FILE__, __LINE__); \
            debugBreak(); \
        } \
    } while (0)

#ifdef _DEBUG
#define M_ASSERT_DEBUG(expression) \
    do { \
        if (expression) { \
            /* Do nothing */ \
        } else { \
            report_assertion_failure(#expression, "", __FILE__, __LINE__); \
            debugBreak(); \
        } \
    } while (0)
#else
#define M_ASSERT_DEBUG(expression) /* Release build, does nothing */
#endif

#else // Assertions not enabled
#define M_ASSERT(expression) /* Does nothing */
#define M_ASSERT_MSG(expression, message) /* Does nothing */
#define M_ASSERT_DEBUG(expression) /* Does nothing */
#endif
