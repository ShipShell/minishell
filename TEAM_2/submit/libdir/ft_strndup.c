#include "libft.h"

char        *ft_strndup(const char *s, size_t n)
{
    char    *result;
    size_t  idx;
    size_t  len;
    idx = 0;
    len = ft_strlen(s);
    if ((result = (char *)malloc(sizeof(char) * len + 1)) == 0)
        return (NULL);
    while (s[idx] && idx < n)
    {
        result[idx] = s[idx];
        idx++;
    }
    result[idx] = '\0';
    return (result);
}