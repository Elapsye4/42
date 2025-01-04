#include "../libft.h"

int    ft_numbers_u(unsigned int n)
{
    unsigned int    res;
    int                i;

    res = n;
    i = 0;
    if (res == 0)
        i++;
    while (res > 0)
    {
        i++;
        res /= 10;
    }
    return (i);
}

char    *ft_itoa_u(unsigned int n)
{
    char            *u;
    int                k;
    unsigned int    nb;

    nb = n;
    k = ft_numbers_u(n);
    u = (char *)malloc(sizeof(char) * (k + 1));
    if (!u)
        return (NULL);
    u[k--] = '\0';
    if (nb < 9 || nb == 0)
        u[k--] = nb + 48;
    else
    {
        while (nb > 0)
        {
            u[k--] = (nb % 10) + 48;
            nb /= 10;
        }
    }
    return (u);
}

int    ft_print_u(unsigned int n)
{
    char            *s;
    unsigned int    data;
    int                size;

    data = (unsigned int)n;
    s = ft_itoa_u(data);
    size = ft_print_s(s);
    free(s);
    return (size);
}

