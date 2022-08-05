/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:48:30 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/05 19:10:28 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include"./libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		count;
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	print_error(void);
int		validation_argv_isnum(char **argv);
int		validation_argv_uniq(int argc, char **argv);
void	init_stack(t_stack **stack_a, t_stack **stack_b);
void	fill_data_stack_a(t_stack *stack_a, char **argv);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_push_last(t_stack *st, t_node *target);
void	ft_push(t_stack *st, t_node *target);
t_node	*ft_pop_last(t_stack *st);
t_node	*ft_pop(t_stack *st);
void	print_stack_desc(t_stack *stac);
void	print_stack_asc(t_stack *stac);
#endif