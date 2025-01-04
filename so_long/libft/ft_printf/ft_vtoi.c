#include "../libft.h"

static int	ft_strlen_ft_printf(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	return (write (1, s, ft_strlen_ft_printf(s)));
}

int	ft_putnbr(int n)
{
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			return (1 + ft_putnbr(-n));
		}
		if (n >= 10)
			return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
		return (ft_putchar(n + '0'));
	}
}
