/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlistcheck_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:06:00 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 10:06:10 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '+'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		nbr *= sign;
	return (nbr);
}

long	ft_doublon(t_stack_node *a, long nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (nbr == a->value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_text(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (1);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
	}
	return (0);
}

void	ft_errorcheck(t_stack_node **a, char **argv, bool tf)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_text(argv[i]))
			ft_freeforall(a, argv, tf);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_freeforall(a, argv, tf);
		if (ft_doublon(*a, nbr))
			ft_freeforall(a, argv, tf);
		append_node(a, nbr);
		++i;
	}
	if (tf)
		ft_freeargument(argv);
}
