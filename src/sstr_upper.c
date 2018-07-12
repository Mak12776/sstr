void sstr_upper(char *s)
{
    CHECK_NULL(sstr_upper, s);

    while (*s)
    {
        *s = (('a' <= *s) && (*s <= 'z')) ? (*s - 32) : *s;
        s++;
    }
}
