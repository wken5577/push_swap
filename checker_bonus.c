/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:40:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 20:13:42 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	search_exec_com(char *cmd, t_stack *st_a, t_stack *st_b)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		sa(st_a);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		sb(st_b);
	else if (ft_strcmp(cmd, "ss\n") == 0)
		ss(st_a, st_b);
	else if (ft_strcmp(cmd, "pa\n") == 0)
		pa(st_a, st_b);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		pb(st_a, st_b);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		ra(st_a);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rb(st_b);
	else if (ft_strcmp(cmd, "rr\n") == 0)
		rr(st_a, st_b);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		rra(st_a);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		rrb(st_b);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		rrr(st_a, st_b);
	else
		print_error();
}

void	start_checker(t_stack *st_a, t_stack *st_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			return ;
		search_exec_com(cmd, st_a, st_b);
		free(cmd);
	}
}

int	is_sorted(t_stack *st_a)
{
	t_node	*node;

	node = st_a->head;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	empty_stack_b(t_stack *st_b)
{
	if (st_b->head == 0)
		return (1);
	else
		return (0);
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
	if (argc == 2)
	{
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	init_stack(&stack_a, &stack_b);
	fill_data_stack_a(stack_a, argv);
	start_checker(stack_a, stack_b);
	if (is_sorted(stack_a) && empty_stack_b(stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	free(stack_b);
	free(stack_a);
	return (0);
}
