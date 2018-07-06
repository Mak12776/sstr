
#include "sstr.h"

sstr sstr_new(const char *str)
{
    SSTR_ERROR_IF(str == NULL, "str argument is NULL");
    sstr result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    char *pntr = SSTR_ALLOC((result->len = strlen(str)) + 1);
    if (!pntr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    result->str = pntr;
    strcpy(pntr, str);
    return result;
}

sstr sstr_from(char *beg, char *end)
{
    SSTR_ERROR_IF(str == NULL, "str argument is NULL");
    sstr result = SSTR_ALLOC(sizeof(struct _sstr))
}
