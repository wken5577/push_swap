/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:52:49 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/05 19:24:03 by hyunkyle         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = 0;
	if (!(validation_argv_isnum(argv)) || !(validation_argv_uniq(argc, argv)))
		print_error();
	init_stack(&stack_a, &stack_b);
	fill_data_stack_a(stack_a, argv);
	
	return (0);
}
