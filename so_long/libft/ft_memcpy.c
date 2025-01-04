#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	o;

	o = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > o)
	{
		((unsigned char *)dest)[o] = ((unsigned char *)src)[o];
		o++;
	}
	return (dest);
}
