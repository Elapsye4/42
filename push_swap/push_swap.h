/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:04:38 by blecoq            #+#    #+#             */
/*   Updated: 2024/02/08 11:44:26 by blecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// ft_newlistcheck.c
char					**ft_newlistinit(char **argv, char space);
char					**ft_newlist(char *argv, char space);
char					*ft_go_next(char *argv, char space);
int						ft_count(char *argv, char space);
int						ft_wordlen(char *argv, char space);

// ft_newlistcheck_utils.c
long					ft_atol(char *str);
long					ft_doublon(t_stack_node *a, long nbr);
int						ft_text(char *argv);
void					ft_errorcheck(t_stack_node **a, char **argv, bool tf);

// ft_freeforall.c
void					ft_freeforall(t_stack_node **a, char **argv, bool tf);
void					ft_freenode(t_stack_node **a);
void					ft_freeargument(char **argv);

// ft_node_init.c
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					set_current_position(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);

// ft_tiny_sort.c
bool					stack_sorted(t_stack_node *stack);
void					tiny_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);

// ft_nodeinfo.c
t_stack_node			*find_last_node(t_stack_node *head);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *stack);
void					append_node(t_stack_node **stack, long nbr);
int						stack_len(t_stack_node *stack);

// ft_moves.c
void					push_swap(t_stack_node **a, t_stack_node **b);
void					move_nodes(t_stack_node **a, t_stack_node **b);
void					finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name);
void					rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest_node);

void					reverse_rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest_node);

// ft_reverserotate.c
void					rra(t_stack_node **a, bool tf);
void					rrb(t_stack_node **b, bool tf);
void					rrr(t_stack_node **a, t_stack_node **b, bool tf);

// ft_push.c
void					pa(t_stack_node **a, t_stack_node **b, bool tf);
void					pb(t_stack_node **b, t_stack_node **a, bool tf);

// ft_swap.c
void					ss(t_stack_node **a, t_stack_node **b, bool tf);
void					sa(t_stack_node **a, bool tf);
void					sb(t_stack_node **b, bool tf);

// ft_rotate.c
void					ra(t_stack_node **a, bool tf);
void					rb(t_stack_node **b, bool tf);
void					rr(t_stack_node **a, t_stack_node **b, bool tf);

#endif
