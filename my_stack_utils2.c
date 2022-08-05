/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:03:34 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/05 19:08:07 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*node;

	node = ft_pop(stack_a);
	ft_push_last(stack_a, node);
}

void	rb(t_stack *stack_b)
{
	t_node	*node;

	node = ft_pop(stack_b);
	ft_push_last(stack_b, node);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack_a)
{
	t_node	*node;

	node = ft_pop_last(stack_a);
	ft_push(stack_a, node);
}

void	rrb(t_stack *stack_b)
{
	t_node	*node;

	node = ft_pop_last(stack_b);
	ft_push(stack_b, node);
}
