
#ifndef SSTR_H
#define SSTR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SSTR_DEBUG 1

#if 1
 #define SSTR_ERROR_IF(exp, err)\
    if (exp)\
        {fprintf(stderr,\
            __FILE__ ":%u: in function sstr_new: %s\n", __LINE__, err);\
            abort();}
#else
 #define SSTR_ERROR_IF(exp, err)
#endif


#define SSTR_ALLOC malloc
#define SSTR_FREE free

typedef struct _sstr
{
    size_t len;
    char *str;
} *sstr;

sstr sstr_new(const char *str);

#endif
