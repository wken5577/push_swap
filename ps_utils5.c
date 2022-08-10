/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:42:30 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 21:46:08 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_sort_b(int i, int r, t_stack *st_b, int pivot)
{
	t_node	*head;

	head = st_b->head;
	while (i < r)
	{
		if (head->data >= pivot)
			return (1);
		head = head->next;
		i++;
	}
	return (0);
}

int	need_sort_a(int i, int r, t_stack *st_a, int pivot)
{
	t_node	*head;

	head = st_a->head;
	while (i < r)
	{
		if (head->data < pivot)
			return (1);
		head = head->next;
		i++;
	}
	return (0);
}

void	start_ra(t_stack *stack_a, int data[], int n)
{
	ra(stack_a);
	data[n] += 1;
}

void	start_rb(t_stack *stack_b, int data[], int n)
{
	rb(stack_b);
	data[n] += 1;
}

void	do_rrb(int rb_pa[], t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < rb_pa[0])
	{	
		if (rb_pa[0] == stack_b->count)
			break ;
		rrb(stack_b);
		i++;
	}
}
