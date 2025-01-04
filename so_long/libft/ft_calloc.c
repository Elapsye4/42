#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	i = nmemb * size;
	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	if (size == 0 || i == 0)
		s = malloc(1);
	else
		s = malloc(i);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, i);
	return (s);
}
