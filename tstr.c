sstr sstr_format_new(const char *fmt, ...)
{
    CHECK_NULL(fmt);

    sstr result;
    int size;
    va_list vars;

    result = SSTR_ALLOC(sizeof(struct _sstr));
    if (!result)
    {
        return NULL;
    }

    va_start(vars, fmt);
    size = vasprintf(&(result->str), fmt, vars);
    va_end(vars);

    if (size == -1)
    {
        SSTR_FREE(result);
        return NULL;
    }
    result->len = size;
    return result;
}
