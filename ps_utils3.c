/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:57:01 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 15:51:26 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_nums(t_stack *st)
{
	int	*nums;

	nums = malloc(sizeof(int) * 3);
	if (!nums)
		print_error();
	nums[0] = st->head->data;
	nums[1] = st->head->next->data;
	nums[2] = st->head->next->next->data;
	return (nums);
}

void	b_low_element2(t_stack *st_a, t_stack *st_b, int nums[])
{
	if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] > nums[0])
	{
		sb(st_b);
		pa(st_a, st_b);
		sb(st_b);
		pa(st_a, st_b);
		pa(st_a, st_b);
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] > nums[0])
	{
		pa(st_a, st_b);
		sb(st_b);
		pa(st_a, st_b);
		sa(st_a);
		pa(st_a, st_b);
	}
	free(nums);
}

void	b_low_element1(t_stack *st_a, t_stack *st_b, int nums[])
{
	if (nums[0] < nums[1] && nums[1] < nums[2] && nums[2] > nums[0])
	{
		sb(st_b);
		pa(st_a, st_b);
		sb(st_b);
		pa(st_a, st_b);
		sa(st_a);
		pa(st_a, st_b);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
	{
		sb(st_b);
		pa(st_a, st_b);
		pa(st_a, st_b);
		pa(st_a, st_b);
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] < nums[0])
	{
		pa(st_a, st_b);
		sb(st_b);
		pa(st_a, st_b);
		pa(st_a, st_b);
	}
	b_low_element2(st_a, st_b, nums);
}

void	a_low_element2(t_stack *st_a, t_stack *st_b, int nums[])
{
	if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] < nums[0])
	{
		sa(st_a);
		pb(st_a, st_b);
		sa(st_a);
		pa(st_a, st_b);
	}
	else if (nums[0] > nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
	{
		pb(st_a, st_b);
		pb(st_a, st_b);
		sb(st_b);
		ra(st_a);
		pa(st_a, st_b);
		pa(st_a, st_b);
		rra(st_a);
	}
	free(nums);
}

void	a_low_element1(t_stack *st_a, t_stack *st_b, int nums[])
{
	if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] > nums[0])
	{
		pb(st_a, st_b);
		sa(st_a);
		pa(st_a, st_b);
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] > nums[0])
		sa(st_a);
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
	{
		pb(st_a, st_b);
		ra(st_a);
		pb(st_a, st_b);
		sb(st_b);
		rra(st_a);
		pa(st_a, st_b);
		pa(st_a, st_b);
	}
	a_low_element2(st_a, st_b, nums);
}
