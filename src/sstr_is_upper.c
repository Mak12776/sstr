int sstr_is_upper(const char *str)
{
    CHECK_NULL(sstr_is_upper, str);
    char *c;

    for (c = (char *)str; *c; c++)
    {
        if (('a' <= *c) && (*c <= 'z'))
        {
            return 0;
        }
    }
    return 1;
}
