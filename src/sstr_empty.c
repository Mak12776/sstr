sstr sstr_empty()
{
    sstr result;
    char *pntr;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }
    pntr = SSTR_ALLOC(1);
    if (!pntr)
    {
        SSTR_FREE(result);
        return NULL;
    }
    *(result->str = pntr) = '\0';
    result->len = 0;
    return result;
}
