
#ifndef SSTR_H
#define SSTR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "sstr_macros.h"

typedef struct _sstr
{
    char *str;
    size_t len;
} *sstr;

sstr sstr_new(const char *str);
sstr sstr_new_len(size_t len, const char c);
sstr sstr_empty();
sstr sstr_from_to(const char *beg, const char *end);
sstr sstr_from_until(const char *beg, const char c);
sstr sstr_from_to_until(const char *beg, const char *end, const char c);
void sstr_free(const sstr str);

void sstr_upper(char *s);
void sstr_lower(char *s);
void sstr_swapcase(char *s);
void sstr_reverse(const sstr str);

sstr sstr_dup(const sstr str);
sstr sstr_cat_new(const sstr str1, const sstr str2);

int sstr_cmp(const sstr str1, const sstr str2);
int sstr_is_upper(const char *str);
int sstr_is_lower(const char *str);

#endif
