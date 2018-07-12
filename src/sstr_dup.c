sstr sstr_dup(const sstr str)
{
    CHECK_NULL(sstr_dup, str);

    sstr result;
    char *nstr;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    nstr = SSTR_ALLOC(result->len = str->len);
    if (!nstr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    strcpy(result->str = nstr, str->str);
    return result;
}
