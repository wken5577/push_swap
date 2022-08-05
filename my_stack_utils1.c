/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:23:39 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/05 18:55:29 by hyunkyle         ###   ########.fr       */
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
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->count == 0)
		return ;
	ft_push(stack_a, ft_pop(stack_b));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count == 0)
		return ;
	ft_push(stack_b, ft_pop(stack_a));
}
