#include "../libft.h"

int	ft_print_s(char *s)
{
    int    i;

    i = 0;
    if (!s)
        return (ft_print_s("(null)"));
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return (ft_strlen(s));
}
