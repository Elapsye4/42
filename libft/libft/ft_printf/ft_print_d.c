#include "../libft.h"

int    ft_numbers(int n)
{
    long    res;
    int        i;

    res = n;
    i = 0;
    if (res <= 0)
    {
        res *= -1;
        i++;
    }
    while (res > 0)
    {
        i++;
        res /= 10;
    }
    return (i);
}

void    ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        ft_print_c('-');
        n *= -1;
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_print_c(n + 48);
}

int    ft_print_d(int n)
{
    ft_putnbr(n);
    return (ft_numbers(n));
}
