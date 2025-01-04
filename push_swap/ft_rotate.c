/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:19:19 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 11:19:31 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	

void	ra(t_stack_node **a, bool tf)
{
	rotate(a);
	if (!tf)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool tf)
{
	rotate(b);
	if (!tf)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool tf)
{
	rotate(a);
	rotate(b);
	if (!tf)
		write(1, "rr\n", 3);
}
