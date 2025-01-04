#include "../libft.h"

int    ft_print_h(unsigned int nbr, int lowupp)
{
    int                value;
    char            data[32];
    int                i;

    if (nbr == 0)
        return (ft_print_c(48));
    i = 0;
    while (nbr != 0)
    {
        value = nbr % 16;
        nbr = nbr / 16;
        if (value < 10)
            data[i] = value + 48;
        else if (value >= 10)
            data[i] = value + (55 + lowupp);
        i++;
    }
    data[i] = '\0';
    i--;
    while (i >= 0)
    {
        ft_print_c(data[i]);
        i--;
    }
    return (ft_strlen(data));
}
