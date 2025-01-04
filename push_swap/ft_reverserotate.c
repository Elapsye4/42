/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverserotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:19:44 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 11:19:56 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool tf)
{
	reverse_rotate(a);
	if (!tf)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool tf)
{
	reverse_rotate(b);
	if (!tf)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool tf)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!tf)
		write(1, "rrr\n", 4);
}
