sstr sstr_cat_new(const sstr str1, const sstr str2)
{
    CHECK_NULL(sstr_cat_new, str1);
    CHECK_NULL(sstr_cat_new, str2);

    sstr result;
    char *nstr;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    nstr = SSTR_ALLOC((result->len = str1->len + str2->len) + 1);
    if (!nstr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    result->str = nstr;
    strcpy(stpcpy(nstr, str1->str), str2->str);
    return result;
}
