/*
******************************************************************************
*
*   Copyright (C) 1997-2001, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
******************************************************************************
*
* File CSTRING.H
*
* Contains CString interface
*
* @author       Helena Shih
*
* Modification History:
*
*   Date        Name        Description
*   6/17/98     hshih       Created.
*  05/03/99     stephen     Changed from functions to macros.
*  06/14/99     stephen     Added icu_strncat, icu_strncmp, icu_tolower
*
******************************************************************************
*/

#ifndef CSTRING_H
#define CSTRING_H 1

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "unicode/utypes.h"

#define uprv_strcpy(dst, src) U_STANDARD_CPP_NAMESPACE  strcpy(dst, src)
#define uprv_strcpyWithSize(dst, src, size) U_STANDARD_CPP_NAMESPACE strncpy(dst, src, size)
#define uprv_strncpy(dst, src, size) U_STANDARD_CPP_NAMESPACE strncpy(dst, src, size)
#define uprv_strlen(str) U_STANDARD_CPP_NAMESPACE strlen(str)
#define uprv_strcmp(s1, s2) U_STANDARD_CPP_NAMESPACE strcmp(s1, s2)
#define uprv_strncmp(s1, s2, n) U_STANDARD_CPP_NAMESPACE strncmp(s1, s2, n)
#define uprv_strcat(dst, src) U_STANDARD_CPP_NAMESPACE strcat(dst, src)
#define uprv_strncat(dst, src, n) U_STANDARD_CPP_NAMESPACE strncat(dst, src, n)
#define uprv_strchr(s, c) U_STANDARD_CPP_NAMESPACE strchr(s, c)
#define uprv_strstr(s, c) U_STANDARD_CPP_NAMESPACE strstr(s, c)
#define uprv_strrchr(s, c) U_STANDARD_CPP_NAMESPACE strrchr(s, c)
#define uprv_toupper(c) U_STANDARD_CPP_NAMESPACE toupper(c)
#define uprv_tolower(c) U_STANDARD_CPP_NAMESPACE tolower(c)
#define uprv_strtoul(str, end, base) U_STANDARD_CPP_NAMESPACE strtoul(str, end, base)
#define uprv_strtol(str, end, base) U_STANDARD_CPP_NAMESPACE strtol(str, end, base)
#ifdef WIN32
#   define uprv_stricmp(str1, str2) U_STANDARD_CPP_NAMESPACE _stricmp(str1, str2)
#   define uprv_strnicmp(str1, str2, n) U_STANDARD_CPP_NAMESPACE _strnicmp(str1, str2, n)
#elif defined(POSIX) 
#   define uprv_stricmp(str1, str2) U_STANDARD_CPP_NAMESPACE strcasecmp(str1, str2) 
#   define uprv_strnicmp(str1, str2, n) U_STANDARD_CPP_NAMESPACE strncasecmp(str1, str2, n) 
#else
#   define uprv_stricmp(str1, str2) T_CString_stricmp(str1, str2)
#   define uprv_strnicmp(str1, str2, n) T_CString_strnicmp(str1, str2, n)
#endif

/* Conversion from a digit to the character with radix base from 2-19 */
/* May need to use U_UPPER_ORDINAL*/
#define T_CString_itosOffset(a) ((a)<=9?('0'+(a)):('A'+(a)-10))

U_CAPI char *uprv_strdup(const char *src);

U_CAPI char* U_EXPORT2
T_CString_toLowerCase(char* str);

U_CAPI char* U_EXPORT2
T_CString_toUpperCase(char* str);

U_CAPI void U_EXPORT2
T_CString_integerToString(char *buffer, int32_t n, int32_t radix);

U_CAPI int32_t U_EXPORT2
T_CString_stringToInteger(const char *integerString, int32_t radix);

U_CAPI int U_EXPORT2
T_CString_stricmp(const char *str1, const char *str2);

U_CAPI int U_EXPORT2
T_CString_strnicmp(const char *str1, const char *str2, uint32_t n);

#endif /* ! CSTRING_H */
