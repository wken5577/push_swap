/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:52:49 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 16:08:58 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_stack_asc(t_stack *stac)
{
	t_node *cur;
	
	if (stac->count == 0)
		return ;
	cur = stac->head;
	printf("head = %d\n", stac->head->data);
	printf("tail = %d\n", stac->tail->data);
	printf("count = %d\n", stac->count);
	while(cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void	print_stack_desc(t_stack *stac)
{
	t_node *cur;
	
	if (stac->count == 0)
		return ;
	cur = stac->tail;
	printf("head = %d\n", stac->head->data);
	printf("tail = %d\n", stac->tail->data);
	printf("count = %d\n", stac->count);
	while(cur)
	{
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}

void	cnt_ra_pb_rb(int r, t_stack *stack_a, t_stack *stack_b, int ra_pb_rb[])
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
			ra(stack_a);
			ra_pb_rb[0] += 1;
		}
		else
		{
			pb(stack_a, stack_b);
			ra_pb_rb[1] += 1;
			if (tmp >= pivot[0])
			{
				rb(stack_b);
				ra_pb_rb[2] += 1;
			}
		}
	}
}

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
		{
			rb(stack_b);
			rb_pa_ra[0] += 1;
		}
		else
		{
			pa(stack_a, stack_b);
			rb_pa_ra[1] += 1;
			if (tmp < pivot[1])
			{
				ra(stack_a);
				rb_pa_ra[2] += 1;
			}
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
		b_to_a_low_element(r, stack_a, stack_b);
		return ;
	}
	if (r == 3)
	{
		b_low_element1(stack_a, stack_b, get_nums(stack_b));
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

void	move_a_to_b(int r, t_stack *stack_a, t_stack *stack_b)
{
	int	ra_pb_rb[3];

	if (is_sorted_a(stack_a, r))
		return ;
	if (r <= 2 || (stack_a->count == 3 && r == 3))
	{
		a_to_b_low_element(r, stack_a);
		return ;
	}
	if (r == 3)
	{
		a_low_element1(stack_a, stack_b, get_nums(stack_a));
		return ;
	}
	ra_pb_rb[0] = 0;
	ra_pb_rb[1] = 0;
	ra_pb_rb[2] = 0;
	cnt_ra_pb_rb(r, stack_a, stack_b, ra_pb_rb);
	reverse_stack_atob(ra_pb_rb, stack_a, stack_b);
	move_a_to_b(ra_pb_rb[0], stack_a, stack_b);
	move_b_to_a(ra_pb_rb[2], stack_a, stack_b);
	move_b_to_a(ra_pb_rb[1] - ra_pb_rb[2], stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = 0;
	if (!(validation_argv_isnum(argv)) || !(validation_argv_uniq(argc, argv)))
		print_error();
	init_stack(&stack_a, &stack_b);
	fill_data_stack_a(stack_a, argv);
	move_a_to_b(stack_a->count, stack_a, stack_b);
	return (0);
}
