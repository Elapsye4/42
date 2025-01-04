#include "../libft.h"

int    ft_print_p(unsigned long long nbr)
{
    unsigned long long    value;
    char                data[64];
    int                    i;
    int                    len;

	if (nbr == 0)
		return (ft_print_s("(nil)"));
	else
		len = ft_print_s("0x");
	i = 0;
	while (nbr != 0)
	{
		value = nbr % 16;
		nbr = nbr / 16;
        	if (value < 10)
            		data[i] = value + 48;
        	else if (value >= 10)
            		data[i] = value + 87;
        	i++;
    	}
    	data[i] = '\0';
    	i--;
    	while (i >= 0)
        	ft_print_c(data[i--]);
    	return (ft_strlen(data) + len);
}
