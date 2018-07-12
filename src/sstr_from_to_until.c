sstr sstr_from_to_until(const char *beg, const char *end, const char c)
{
    CHECK_NULL(sstr_from_to_until, beg);

    sstr result;
    char *pntr;
    size_t len;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    for (pntr = (char *)beg; *pntr != c; pntr++)
    {
        if (pntr == end)
        {
            break;
        }
    }
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
