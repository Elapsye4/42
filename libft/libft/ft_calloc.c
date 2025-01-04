/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:12:45 by blecoq            #+#    #+#             */
/*   Updated: 2023/07/25 14:30:09 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	char			*c;
	unsigned int	total;

	if (size && (nmemb > (size_t)-1 / size))
		return (NULL);
	total = nmemb * size;
	i = 0;
	c = (char *)malloc(nmemb * size);
	if (!c)
		return (NULL);
	while (total > 0)
	{
		c[i] = 0;
		i++;
		total--;
	}
	return ((void *)c);
}
