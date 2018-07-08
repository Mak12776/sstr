
#include "sstr.h"

#define CHECK_NULL(name) SSTR_ERROR_IF(name == NULL, #name " argument is NULL")

sstr sstr_new(const char *str)
{
    CHECK_NULL(str);

    sstr result;
    char *nstr;
    size_t len;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    nstr = SSTR_ALLOC((len = strlen(str)) + 1);
    if (!nstr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    result->len = len;
    result->str = nstr;
    strcpy(nstr, str);
    return result;
}

sstr sstr_from_to(const char *beg, const char *end)
{
    CHECK_NULL(beg);
    CHECK_NULL(end);

    sstr result;
    char *nstr;
    size_t len;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    len = (end <= beg) ? 0 : end - beg;
    nstr = SSTR_ALLOC(len + 1);
    if (!nstr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    result->str = nstr;
    result->len = len;
    *(char *)mempcpy(nstr, beg, len) = '\0';
    return result;
}

sstr sstr_from_until(const char *beg, const char c)
{
    CHECK_NULL(beg);

    sstr result;
    char *pntr;
    size_t len;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    for (pntr = (char *)beg; *pntr != c; pntr++);
    len = pntr - beg;
    pntr = SSTR_ALLOC(len + 1);
    if (!pntr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    result->str = pntr;
    result->len = len;
    *(char *)mempcpy(pntr, beg, len) = '\0';
    return result;
}

void sstr_free(const sstr str)
{
    CHECK_NULL(str);

    SSTR_FREE(str->str);
    SSTR_FREE(str);
}
