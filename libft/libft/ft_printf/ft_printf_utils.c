#include "../libft.h"

size_t    ft_strlen(const char *s)
{
    size_t    i;

    i = 0;
    while (s[i] != '\0')
            i++;
    return (i);
}

char    ft_strchra(const char *s, int c)
{
    char    *st;
    char    data;
    int		i;
    int		len;

    i = 0;
    st = (char *)s;
    data = (char)c;
    len = ft_strlen(st);
    while (st[i] != data && i <= len)
    {
		if (st[i] == '\0')
			return (0);
		i++;
    }
    return (st[i]);
}
