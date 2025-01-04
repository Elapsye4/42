#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	o;

	o = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
	{
		while (n > o)
		{
			((unsigned char *)dest)[o] = ((unsigned char *)src)[o];
			o++;
		}
	}
	return (dest);
}
