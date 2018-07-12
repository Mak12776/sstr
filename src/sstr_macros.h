#define SSTR_ALLOC malloc
#define SSTR_REALLOC realloc
#define SSTR_FREE free

#define SSTR_NOMEM(func_name)

#define SSTR_DEBUG 1

#if SSTR_DEBUG
 #define SSTR_ERROR_IF(func, exp, err)\
    if (exp)\
        {fprintf(stderr,\
            __FILE__ ":%u: in function " #func ": %s\n", __LINE__, err);\
            abort();}
#else
 #define SSTR_ERROR_IF(func, exp, err)
#endif
