/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:52:49 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 20:22:27 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cnt_rb_pa_ra(int r, t_stack *stack_a, t_stack *stack_b, int rb_pa_ra[])
{
	int		i;
	int		pivot[2];
	int		tmp;

	i = -1;
	get_pivot(stack_b, pivot, r);
	while (++i < r)
	{
		tmp = stack_b->head->data;
		if (tmp < pivot[0])
			start_rb(stack_b, rb_pa_ra, 0);
		else
		{
			pa(stack_a, stack_b);
			rb_pa_ra[1] += 1;
			if (tmp < pivot[1])
				start_ra(stack_a, rb_pa_ra, 2);
		}
	}
}

void	move_b_to_a(int r, t_stack *stack_a, t_stack *stack_b)
{
	int	rb_pa_ra[3];

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
	if (r <= 6)
	{
		mv_btoa_one_pivot(r, stack_a, stack_b);
		return ;
	}
	rb_pa_ra[0] = 0;
	rb_pa_ra[1] = 0;
	rb_pa_ra[2] = 0;
	cnt_rb_pa_ra(r, stack_a, stack_b, rb_pa_ra);
	move_a_to_b(rb_pa_ra[1] - rb_pa_ra[2], stack_a, stack_b);
	reverse_stack_btoa(rb_pa_ra, stack_a, stack_b);
	move_a_to_b(rb_pa_ra[2], stack_a, stack_b);
	move_b_to_a(rb_pa_ra[0], stack_a, stack_b);
}

int	cnt_ra_pb_rb(int r, t_stack *stack_a, t_stack *stack_b, int ra_pb_rb[])
{
	int		i;
	int		pivot[2];
	int		tmp;

	i = -1;
	get_pivot(stack_a, pivot, r);
	while (++i < r)
	{
		tmp = stack_a->head->data;
		if (tmp >= pivot[1])
		{
			if (need_sort_a(i, r, stack_a, pivot[1]))
				start_ra(stack_a, ra_pb_rb, 0);
			else
				return (r - i);
		}
		else
		{
			pb(stack_a, stack_b);
			ra_pb_rb[1] += 1;
			if (tmp >= pivot[0])
				start_rb(stack_b, ra_pb_rb, 2);
		}
	}
	return (0);
}

void	move_a_to_b(int r, t_stack *stack_a, t_stack *stack_b)
{
	int	ra_pb_rb[3];
	int	tmp;

	if (is_sorted_a(stack_a, r))
		return ;
	if (r <= 3)
	{
		a_to_b_low_element(r, stack_a, stack_b);
		return ;
	}
	if (r <= 6)
	{
		mv_atob_one_pivot(r, stack_a, stack_b);
		return ;
	}
	ra_pb_rb[0] = 0;
	ra_pb_rb[1] = 0;
	ra_pb_rb[2] = 0;
	tmp = cnt_ra_pb_rb(r, stack_a, stack_b, ra_pb_rb);
	reverse_stack_atob(ra_pb_rb, stack_a, stack_b);
	move_a_to_b(ra_pb_rb[0] + tmp, stack_a, stack_b);
	move_b_to_a(ra_pb_rb[2], stack_a, stack_b);
	move_b_to_a(ra_pb_rb[1] - ra_pb_rb[2], stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	start_validation_isnum(argc, argv);
	if (!(validation_argv_uniq(argv)))
		print_error();
	init_stack(&stack_a, &stack_b);
	fill_data_stack_a(stack_a, argv);
	move_a_to_b(stack_a->count, stack_a, stack_b);
	free(stack_b);
	free(stack_a);
	return (0);
}
