/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:46:20 by blecoq            #+#    #+#             */
/*   Updated: 2023/07/25 12:51:10 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	j = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			flag = 0;
			j++;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (j);
}

static size_t	letters_in_word(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**arr;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	words = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		arr[j] = ft_substr(s, i, letters_in_word(s, c, i));
		if (!arr[j++])
			return (NULL);
		i += letters_in_word(s, c, i);
	}
	arr[j] = NULL;
	return (arr);
}
