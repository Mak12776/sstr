void sstr_lower(char *s)
{
    CHECK_NULL(sstr_lower, s);

    while (*s)
    {
        *s = (('A' <= *s) && (*s <= 'Z')) ? (*s + 32) : *s;
        s++;
    }
}
