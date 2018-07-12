
#include "sstr.h"

#define CHECK_NULL(func, name)\
    SSTR_ERROR_IF(func, name == NULL, #name " argument is NULL")

#include "sstr_new.c"
#include "sstr_empty.c"
#include "sstr_from_to.c"
#include "sstr_from_until.c"
#include "sstr_from_to_until.c"
#include "sstr_free.c"

#include "sstr_dup.c"

#include "sstr_upper.c"
#include "sstr_lower.c"
#include "sstr_swapcase.c"
#include "sstr_reverse.c"

#include "sstr_cmp.c"
#include "sstr_is_upper.c"
#include "sstr_is_lower.c"
