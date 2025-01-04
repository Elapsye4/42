#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			o;
	unsigned char	*str;

	o = 0;
	str = (unsigned char *)s;
	while (n > o)
	{
		if (str[o] == (unsigned char)c)
			return ((void *)(str + o));
		o++;
	}
	return (0);
}
