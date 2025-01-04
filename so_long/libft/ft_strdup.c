#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	len;

	len = ft_strlen(s);
	t = ft_calloc(len + 1, 1);
	if (t == NULL)
		return (NULL);
	ft_memcpy(t, s, len);
	t[len] = '\0';
	return (t);
}
