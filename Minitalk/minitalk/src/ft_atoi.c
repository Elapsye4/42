#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	symb;
	int	res;

	i = 0;
	symb = 1;
	res = 0;
	while (nptr[i] != '\0')
	{
		while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		if (nptr[i] == 43 || nptr[i] == 45)
		{
			if (nptr[i] == 45)
				symb = -symb;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			res = (res * 10) + (nptr[i] - 48);
			i++;
		}
		return (symb * res);
	}
	return (0);
}
