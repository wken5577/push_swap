/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:29:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 11:32:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	do_sa(t_stack *stack_a)
{
	t_node	*node_1;
	t_node	*node_2;

	if (stack_a->count == 0 || stack_a->count == 1)
		return ;
	node_1 = ft_pop(stack_a);
	node_2 = ft_pop(stack_a);
	ft_push(stack_a, node_1);
	ft_push(stack_a, node_2);
}

void	do_sb(t_stack *stack_b)
{
	t_node	*node_1;
	t_node	*node_2;

	if (stack_b->count == 0 || stack_b->count == 1)
		return ;
	node_1 = ft_pop(stack_b);
	node_2 = ft_pop(stack_b);
	ft_push(stack_b, node_1);
	ft_push(stack_b, node_2);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node1;
	t_node	*node2;

	node1 = ft_pop_last(stack_a);
	ft_push(stack_a, node1);
	node2 = ft_pop_last(stack_b);
	ft_push(stack_b, node2);
	ft_putstr_fd("rrr\n", 1);
}