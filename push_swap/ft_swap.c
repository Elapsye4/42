/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:20:06 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 11:20:11 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	int	len;

	len = stack_len(*head);
	if (head == NULL || *head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**a, bool tf)
{
	swap(a);
	if (!tf)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool tf)
{
	swap(b);
	if (!tf)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool tf)
{
	swap(a);
	swap(b);
	if (!tf)
		write(1, "ss\n", 3);
}
