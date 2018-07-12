sstr sstr_new(const char *str)
{
    CHECK_NULL(sstr_new, str);

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
