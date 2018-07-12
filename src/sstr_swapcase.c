void sstr_swapcase(char *s)
{
    CHECK_NULL(sstr_swapcase, s);

    while (*s)
    {
        *s = (('a' <= *s) && (*s <= 'z')) ? (*s + 32) :
            (('A' <= *s) && (*s <= 'Z') ? (*s - 32) : *s);
        s++;
    }
}
