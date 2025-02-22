/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:13:06 by blecoq            #+#    #+#             */
/*   Updated: 2023/10/25 06:43:49 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*clean_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	temp[i] = 0;
	return (temp);
}

static char	*str_rest(char *str)
{
	size_t	i;
	char	*temp;
	char	*start;

	if (!*str)
	{
		free(str);
		return (NULL);
	}
	start = str;
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		str++;
	i = 0;
	while (str[i] && str)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = 0;
	while (i-- > 0)
		temp[i] = str[i];
	free(start);
	return (temp);
}

static char	*get_text(char *str, int fd)
{
	char	*temp;
	int		nbytes;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && !ft_chrstr(str))
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(temp);
			free(str);
			return (NULL);
		}
		temp[nbytes] = 0;
		str = join_string(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_text(str, fd);
	if (!str)
		return (NULL);
	line = clean_line(str);
	str = str_rest(str);
	return (line);
}
