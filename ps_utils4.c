/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:38:31 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 21:42:00 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_one_pivot(int r, t_stack *st)
{
	int	pivot;
	int	mid;
	int	*arr;

	mid = r / 2;
	arr = get_arr(st, r);
	sort_arr(arr, r);
	pivot = arr[mid];
	free(arr);
	return (pivot);
}

int	cnt_ra_pb(int r, t_stack *stack_a, t_stack *stack_b, int ra_pb[])
{
	int	i;
	int	pivot;

	pivot = get_one_pivot(r, stack_a);
	i = -1;
	while (++i < r)
	{
		if (stack_a->head->data >= pivot)
		{
			if (need_sort_a(i, r, stack_a, pivot))
			{
				ra(stack_a);
				ra_pb[0] += 1;
			}
			else
				return (r - i);
		}
		else
		{
			pb(stack_a, stack_b);
			ra_pb[1] += 1;
		}
	}
	return (0);
}

void	mv_atob_one_pivot(int r, t_stack *stack_a, t_stack *stack_b)
{
	int	ra_pb[2];
	int	i;
	int	tmp;

	if (is_sorted_a(stack_a, r))
		return ;
	if (r <= 3)
	{
		a_to_b_low_element(r, stack_a, stack_b);
		return ;
	}
	ra_pb[0] = 0;
	ra_pb[1] = 0;
	tmp = cnt_ra_pb(r, stack_a, stack_b, ra_pb);
	i = 0;
	while (i < ra_pb[0])
	{
		if (ra_pb[0] == stack_a->count)
			break ;
		rra(stack_a);
		i++;
	}
	mv_atob_one_pivot(ra_pb[0] + tmp, stack_a, stack_b);
	mv_btoa_one_pivot(ra_pb[1], stack_a, stack_b);
}

int	cnt_rb_pa(int r, t_stack *stack_a, t_stack *stack_b, int rb_pa[])
{
	int	i;
	int	pivot;

	pivot = get_one_pivot(r, stack_b);
	i = -1;
	while (++i < r)
	{
		if (stack_b->head->data >= pivot)
		{
			pa(stack_a, stack_b);
			rb_pa[1] += 1;
		}
		else
		{
			if (need_sort_b(i, r, stack_b, pivot))
			{
				rb(stack_b);
				rb_pa[0] += 1;
			}
			else
				return (r - i);
		}
	}
	return (0);
}

void	mv_btoa_one_pivot(int r, t_stack *stack_a, t_stack *stack_b)
{
	int	rb_pa[2];
	int	tmp;

	if (is_sorted_b(stack_b, r, stack_a))
		return ;
	if (r <= 2 || (stack_b->count == 3 && r == 3))
	{
		if (r <= 2 || (stack_b->count == 3 && r == 3))
			b_to_a_low_element(r, stack_a, stack_b);
		else
			b_low_element1(stack_a, stack_b, get_nums(stack_b));
		return ;
	}
	rb_pa[0] = 0;
	rb_pa[1] = 0;
	tmp = cnt_rb_pa(r, stack_a, stack_b, rb_pa);
	do_rrb(rb_pa, stack_b);
	mv_atob_one_pivot(rb_pa[1], stack_a, stack_b);
	mv_btoa_one_pivot(rb_pa[0] + tmp, stack_a, stack_b);
}
