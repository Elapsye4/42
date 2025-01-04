#include "../libft.h"

int    ft_print_c(char c)
{
    int    print;

    print = 0;
    print = write(1, &c, 1);
    return (print);
}
