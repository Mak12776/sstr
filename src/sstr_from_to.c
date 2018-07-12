sstr sstr_from_to(const char *beg, const char *end)
{
    CHECK_NULL(sstr_from_to, beg);
    CHECK_NULL(sstr_from_to, end);

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
