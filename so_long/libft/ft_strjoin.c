#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = ft_calloc(i1 + i2 + 1, 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, i1);
	ft_memcpy(s3 + i1, s2, i2);
	s3[i1 + i2] = '\0';
	return (s3);
}
