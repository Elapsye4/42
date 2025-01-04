/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:50:33 by blecoq            #+#    #+#             */
/*   Updated: 2023/07/25 13:39:59 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	plus_minus(const char *str)
{
	int	i;
	int	operator;

	i = 0;
	operator = 1;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == 43)
			operator = 1;
		else if (str[i] == 45)
			operator = -1;
		i++;
	}
	return (operator);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	a;

	i = 0;
	sign = plus_minus(str);
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == 43 || str[i] == 45)
		i++;
	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (sign * a);
}
