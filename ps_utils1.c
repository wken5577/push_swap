/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:21:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 16:23:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_element_b(t_stack *st)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = st->head->data;
	num2 = st->head->next->data;
	num3 = st->head->next->next->data;
	if (num1 < num2 && num2 < num3 && num1 < num3)
	{
		sb(st);
		rrb(st);
	}
	else if (num1 < num2 && num2 > num3 && num1 < num3)
		rb(st);
	else if (num1 > num2 && num2 < num3 && num1 < num3)
		rrb(st);
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		sb(st);
	else if (num1 > num2 && num2 < num3 && num1 > num3)
	{
		sb(st);
		rb(st);
	}
}

void	b_to_a_low_element(int r, t_stack *stack_a, t_stack *stack_b)
{
	if (r == 0)
		return ;
	if (r == 1)
		pa(stack_a, stack_b);
	else if (r == 2)
	{
		if (stack_b->head->data > stack_b->head->next->data)
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			sb(stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
	}
	else
	{
		sort_three_element_b(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_three_element_a(t_stack *st)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = st->head->data;
	num2 = st->head->next->data;
	num3 = st->head->next->next->data;
	if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(st);
		ra(st);
	}
	else if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(st);
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(st);
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(st);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa(st);
		rra(st);
	}
}

void	a_to_b_low_element(int r, t_stack *stack_a, t_stack *stack_b)
{
	if (r == 1 || r == 0)
		return ;
	if (r == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			sa(stack_a);
	}
	else if (stack_a->count == 3 && r == 3)
		sort_three_element_a(stack_a);
	else
		a_low_element1(stack_a, stack_b, get_nums(stack_a));
}

void	get_pivot(t_stack *st, int pivot[], int r)
{
	int	idx1;
	int	idx2;
	int	*arr;

	arr = get_arr(st, r);
	idx1 = r * 0.3;
	idx2 = r * 0.6;
	sort_arr(arr, r);
	pivot[0] = arr[idx1];
	pivot[1] = arr[idx2];
	free(arr);
}
