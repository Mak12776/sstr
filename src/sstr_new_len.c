sstr sstr_new_len(size_t len, const char c)
{
    sstr result;
    char *nstr;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    nstr = SSTR_ALLOC(len + 1);
    if (!nstr)
    {
        SSTR_FREE(nstr);
        return NULL;
    }
    memset(nstr, len, c);
    *(nstr + len) = '\0';
    result->len = len;
    result->str = nstr;
    return result;
}
