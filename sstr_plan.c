// this file is just a Todo list

// tabbed = Done
// Todos:
    sstr sstr_new(const char *str);
    sstr sstr_new_len(size_t len, const char c);
    sstr sstr_empty();
    sstr sstr_from_to(const char *beg, const char *end);
    sstr sstr_from_until(const char *beg, const char c);
    sstr sstr_from_to_until(const char *beg, const char *end, const char c);
    void sstr_free(const sstr str);

int sstr_cat(sstr str1, sstr str2);
int sstr_format(const sstr *fmt, ..);
int sstr_strip(sstr str);
int sstr_lstrip(sstr str);
int sstr_rstrip(sstr str);

    void sstr_reverse(const sstr str);
    void sstr_upper(char *s);
    void sstr_lower(char *s);
    void sstr_swapcase(char *s);

    sstr sstr_dup(const sstr str);
    sstr sstr_cat_new(const sstr str1);
sstr sstr_format_new(const char *fmt, ...);
sstr sstr_strip_new(sstr str);
sstr sstr_lstrip_new(sstr str);
sstr sstr_rstrip_new(sstr str);

sstr sstr_reverse_new(sstr str);
sstr sstr_upper_new(char *s);
sstr sstr_lower_new(char *s);
sstr sstr_swapcase_new(char *s);

    int sstr_cmp(sstr str1, sstr str2);
    int sstr_is_upper(const char *str);
    int sstr_is_lower(const char *str);


SSTR_NOMEM(func_name);

// olds

void sstr_replace(sstr * dest, const sstr src);
