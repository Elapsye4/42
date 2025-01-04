#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	o;

	o = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n > o)
	{
		if (((unsigned char *)s1)[o] != ((unsigned char *)s2)[o])
			return (((unsigned char *)s1)[o] - ((unsigned char *)s2)[o]);
		o++;
	}
	return (0);
}
