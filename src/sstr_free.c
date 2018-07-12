void sstr_free(const sstr str)
{
    CHECK_NULL(sstr_free, str);

    SSTR_FREE(str->str);
    SSTR_FREE(str);
}
