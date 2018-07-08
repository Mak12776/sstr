// this file is just a Todo list

// Done:
sstr sstr_new(char *str);
sstr sstr_empty();
sstr sstr_from_to(const char *beg, const char *end);
sstr sstr_from_until(const char *beg, const char c);
sstr sstr_from_to_until(const char *beg, const char *end, const char c);
void sstr_free(const sstr str);

sstr sstr_dup(const sstr str);

// Todos:
int sstr_format(sstr *fmt, ..);
int sstr_cat(sstr str1, sstr str2);
int sstr_strip(sstr str);
int sstr_lstrip(sstr str);
int sstr_rstrip(sstr str);

void sstr_reverse(sstr str);
void sstr_upper(char *s);
void sstr_lower(char *s);
void sstr_swapcase(char *s);

sstr sstr_format_new(const char *fmt, ...);
sstr sstr_cat_new(sstr str1);
sstr sstr_strip_new(sstr str);
sstr sstr_lstrip_new(sstr str);
sstr sstr_rstrip_new(sstr str);

sstr sstr_reverse_new(sstr str);
sstr sstr_upper_new(char *s);
sstr sstr_lower_new(char *s);
sstr sstr_swapcase_new(char *s);

int sstr_cmp(sstr str1, sstr str2);
int sstr_is_upper(char *str);
int sstr_is_lower(char *str);


SSTR_NOMEM(func_name);

// olds

void sstr_replace(sstr * dest, const sstr src);
