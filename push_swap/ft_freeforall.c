/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeforall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:04:12 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 10:04:26 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freeargument(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free (argv -1);
}

void	ft_freenode(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*safe;

	if (a == NULL)
		return ;
	safe = *a;
	while (safe)
	{
		tmp = safe->next;
		free(safe);
		safe = tmp;
	}
	*a = NULL;
}

void	ft_freeforall(t_stack_node **a, char **argv, bool tf)
{
	ft_freenode(a);
	if (tf)
		ft_freeargument(argv);
	write (1, "Error\n", 6);
	exit (1);
}
