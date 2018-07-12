int sstr_cmp(const sstr str1, const sstr str2)
{
    CHECK_NULL(sstr_cmp, str1);
    CHECK_NULL(sstr_cmp, str2);

    size_t len1, len2;

    len1 = str1->len;
    len2 = str2->len;
    if (len1 < len2)
    {
        return -1;
    }
    else if (len1 > len2)
    {
        return 1;
    }
    else
    {
        return strcmp(str1->str, str2->str);
    }
}
