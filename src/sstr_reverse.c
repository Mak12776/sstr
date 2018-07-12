void sstr_reverse(const sstr str)
{
    CHECK_NULL(sstr_reverse, str);

    char *beg, *end;

    beg = str->str;
    end = beg + str->len - 1;
    while (beg < end)
    {
        *(beg++) = *(end--);
    }
}
