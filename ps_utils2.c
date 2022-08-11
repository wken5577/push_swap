/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:22:01 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 10:32:19 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stack_atob(int ra_pb_rb[], t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < ra_pb_rb[0] && i < ra_pb_rb[2])
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while (i < ra_pb_rb[0])
	{
		rra(stack_a);
		i++;
	}
	while (i < ra_pb_rb[2])
	{
		rrb(stack_b);
		i++;
	}
}

void	reverse_stack_btoa(int rb_pa_ra[], t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < rb_pa_ra[0] && i < rb_pa_ra[2])
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while (i < rb_pa_ra[0])
	{
		rrb(stack_b);
		i++;
	}
	while (i < rb_pa_ra[2])
	{
		rra(stack_a);
		i++;
	}
}

int	is_sorted_b(t_stack *st_b, int r, t_stack *st_a)
{
	int		i;
	t_node	*head;

	i = 0;
	head = st_b->head;
	while (i < r - 1)
	{
		if (head->data < head->next->data)
			return (0);
		i++;
		head = head->next;
	}
	i = 0;
	while (i < r)
	{
		pa(st_a, st_b);
		i++;
	}
	return (1);
}

int	is_sorted_a(t_stack *st_a, int r)
{
	int		i;
	t_node	*head;

	i = 0;
	head = st_a->head;
	while (i < r - 1)
	{
		if (head->data > head->next->data)
			return (0);
		i++;
		head = head->next;
	}
	return (1);
}

int	*get_arr(t_stack *st, int r)
{
	int		*result;
	int		i;
	t_node	*head;

	i = 0;
	head = st->head;
	result = malloc(sizeof(int) * r);
	if (!result)
		print_error();
	while (i < r)
	{
		result[i] = head->data;
		i++;
		head = head->next;
	}
	return (result);
}
