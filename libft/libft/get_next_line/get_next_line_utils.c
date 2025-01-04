/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:21:52 by blecoq            #+#    #+#             */
/*   Updated: 2023/07/25 16:27:39 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_chrstr(const char *str)
{
	size_t	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join_string(char *s1, char *s2)
{
	char	*ret;
	char	*p;
	int		i;
	int		j;
	int		size;

	size = ft_strlen(s2);
	if (s1)
		size += ft_strlen(s1);
	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (!p)
		return (NULL);
	ret = p;
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		p[i++] = s2[j++];
	p[i] = 0;
	free(s1);
	return (ret);
}
