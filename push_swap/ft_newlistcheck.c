/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlistcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:05:02 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 12:00:52 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordlen(char *argv, char space)
{
	static int	i = 0;
	int			j;

	j = 0;
	while (argv[i] && argv[i] == space)
		i++;
	while (argv[i] && argv[i] != space)
	{
		j++;
		i++;
	}
	return (j);
}

int	ft_count(char *argv, char space)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i] == space)
			i++;
		if (argv[i] != space)
		{
			count++;
			while (argv[i] && argv[i] != space)
				i++;
		}
	}
	return (count);
}

char	*ft_go_next(char *argv, char space)
{
	static int	i = 0;
	int			j;
	char		*tmp;

	j = 0;
	tmp = NULL;
	while (argv[i] && argv[i] == space)
		i++;
	tmp = malloc(sizeof(char) * ft_wordlen(argv, ' ') + 1);
	if (!tmp)
		return (NULL);
	while (argv[i] && argv[i] != space)
	{
		tmp[j] = argv[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	**ft_newlist(char *argv, char space)
{
	char	**nlist;
	int		count;
	int		i;

	count = ft_count(argv, space);
	if (!count)
		exit(1);
	nlist = malloc(sizeof(char *) * (count + 2));
	if (!nlist)
		return (NULL);
	i = 0;
	nlist[i] = malloc(sizeof(char));
	nlist[i][0] = '\0';
	i++;
	while (i <= count)
	{
		nlist[i] = ft_go_next(argv, ' ');
		i++;
	}
	nlist[i] = NULL;
	return (nlist);
}

char	**ft_newlistinit(char **argv, char space)
{
	argv = ft_newlist(argv[1], space);
	return (argv);
}
