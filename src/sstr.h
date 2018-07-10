
#ifndef SSTR_H
#define SSTR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


#define SSTR_ALLOC malloc
#define SSTR_REALLOC realloc
#define SSTR_FREE free

#define SSTR_NOMEM(func_name)

#define SSTR_DEBUG 1

#if SSTR_DEBUG
 #define SSTR_ERROR_IF(func, exp, err)\
    if (exp)\
        {fprintf(stderr,\
            __FILE__ ":%u: in function " #func ": %s\n", __LINE__, err);\
            abort();}
#else
 #define SSTR_ERROR_IF(exp, err)
#endif

typedef struct _sstr
{
    char *str;
    size_t len;
} *sstr;

sstr sstr_new(const char *str);
sstr sstr_empty();
sstr sstr_from_to(const char *beg, const char *end);
sstr sstr_from_until(const char *beg, const char c);
sstr sstr_from_to_until(const char *beg, const char *end, const char c);
void sstr_free(const sstr str);


#endif
