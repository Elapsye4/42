#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	d;

	d = 0;
	while (s[d] != '\0')
		d++;
	while (d >= 0)
	{
		if (s[d] == (char)c)
			return ((char *)&s[d]);
		d--;
	}
	return (0);
}
