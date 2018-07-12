sstr sstr_from_until(const char *beg, const char c)
{
    CHECK_NULL(sstr_from_until, beg);

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
