#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	o;

	o = 0;
	while (n > o)
	{
		((unsigned char *)s)[o] = (unsigned char)c;
		o++;
	}
	return (s);
}
