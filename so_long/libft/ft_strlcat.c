#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	if ((dst == NULL && src == NULL) || (dst == NULL && size == 0))
		return (0);
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d >= size)
		return (size + s);
	if (s < size - d)
	{
		ft_memcpy(dst + d, src, s + 1);
	}
	else
	{
		ft_memcpy(dst + d, src, size - d - 1);
		dst[size - 1] = '\0';
	}
	return (d + s);
}
