/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:23:39 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 11:29:17 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*node_1;
	t_node	*node_2;

	if (stack_a->count == 0 || stack_a->count == 1)
		return ;
	node_1 = ft_pop(stack_a);
	node_2 = ft_pop(stack_a);
	ft_push(stack_a, node_1);
	ft_push(stack_a, node_2);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b)
{
	t_node	*node_1;
	t_node	*node_2;

	if (stack_b->count == 0 || stack_b->count == 1)
		return ;
	node_1 = ft_pop(stack_b);
	node_2 = ft_pop(stack_b);
	ft_push(stack_b, node_1);
	ft_push(stack_b, node_2);
	ft_putstr_fd("sb\n", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->count == 0)
		return ;
	ft_push(stack_a, ft_pop(stack_b));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count == 0)
		return ;
	ft_push(stack_b, ft_pop(stack_a));
	ft_putstr_fd("pb\n", 1);
}
