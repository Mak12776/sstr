int sstr_is_lower(const char *str)
{
    CHECK_NULL(sstr_is_lower, str);
    char *c;

    for (c = (char *)str; *c; c++)
    {
        if (('A' <= *c) && (*c <= 'Z'))
        {
            return 0;
        }
    }
    return 1;
}
