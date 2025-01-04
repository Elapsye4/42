#include "../libft.h"

int    get_print(char c, va_list list)
{
	int    print;

	print = 0;
	if (c == 'c')
		print = ft_print_c(va_arg(list, int));
	else if (c == 's')
		print = ft_print_s(va_arg(list, char *));
	else if (c == 'p')
		print = ft_print_p(va_arg(list, unsigned long long));
	else if (c == 'd')
		print = ft_print_d(va_arg(list, int));
	else if (c == 'i')
		print = ft_print_d(va_arg(list, int));
	else if (c == 'u')
		print = ft_print_u(va_arg(list, unsigned int));
	else if (c == 'x')
		print = ft_print_h(va_arg(list, unsigned int), 32);
	else if (c == 'X')
		print = ft_print_h(va_arg(list, unsigned int), 0);
	else if (c == '%')
		print = ft_print_c('%');
	return (print);
}

int    ft_printf(const char *str, ...)
{
    int        i;
    int        print;
    va_list    list;

    i = 0;
    print = 0;
    va_start(list, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            if (ft_strchra("cspdiuxX%", str[i + 1]))
            {
                print += get_print(str[i + 1], list);
                i++;
            }
        }
        else if (str[i] != '%')
            print += ft_print_c(str[i]);
        i++;
    }
    va_end(list);
    if (print < 0)
        return (-1);
    return (print);
}
