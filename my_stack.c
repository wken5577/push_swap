/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:43:50 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/09 11:18:38 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_node(int num)
{
	t_node	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		print_error();
	result->data = num;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void	fill_data_stack_a(t_stack *stack_a, char **argv)
{
	t_node	*tmp;
	int		i;
	int		val;

	i = 1;
	while (argv[i])
	{
		tmp = make_node(ft_atoi(argv[i], &val));
		ft_push_last(stack_a, tmp);
		i++;
	}
}

void	init_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc (sizeof(t_stack));
	b = malloc (sizeof(t_stack));
	if (!a || !b)
		print_error();
	a->count = 0;
	a->head = NULL;
	a->tail = NULL;
	b->count = 0;
	b->head = NULL;
	b->tail = NULL;
	*stack_a = a;
	*stack_b = b;
}
