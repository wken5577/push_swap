/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:48:30 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 19:31:48 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include"./libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		count;
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	print_error(void);
int		validation_argv_isnum(char **strs);
void	start_validation_isnum(int argc, char **argv);
int		validation_argv_uniq(char **argv);
int		*fill_extend_arr(int *arr, int *size, char *str, int *validation);
int		get_size(char **strs);
void	release_strs(char **strs);
void	init_stack(t_stack **stack_a, t_stack **stack_b);
void	fill_data_stack_a(t_stack *stack_a, char **argv);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_push_last(t_stack *st, t_node *target);
void	ft_push(t_stack *st, t_node *target);
t_node	*ft_pop_last(t_stack *st);
t_node	*ft_pop(t_stack *st);
void	b_to_a_low_element(int r, t_stack *stack_a, t_stack *stack_b);
void	a_to_b_low_element(int r, t_stack *stack_a, t_stack *stack_b);
void	sort_arr(int *arr, int size);
int		*get_arr(t_stack *st, int r);
void	get_pivot(t_stack *st, int pivot[], int r);
void	move_b_to_a(int r, t_stack *stack_a, t_stack *stack_b);
void	move_a_to_b(int r, t_stack *stack_a, t_stack *stack_b);
void	reverse_stack_atob(int ra_pb_rb[], t_stack *stack_a, t_stack *stack_b);
void	reverse_stack_btoa(int rb_pa_ra[], t_stack *stack_a, t_stack *stack_b);
int		is_sorted_a(t_stack *st_a, int r);
int		is_sorted_b(t_stack *st_b, int r, t_stack *st_a);
void	a_low_element1(t_stack *st_a, t_stack *st_b, int nums[]);
void	b_low_element1(t_stack *st_a, t_stack *st_b, int nums[]);
int		*get_nums(t_stack *st);
void	mv_atob_one_pivot(int r, t_stack *stack_a, t_stack *stack_b);
void	mv_btoa_one_pivot(int r, t_stack *stack_a, t_stack *stack_b);
int		need_sort_b(int i, int r, t_stack *st_b, int pivot);
int		need_sort_a(int i, int r, t_stack *st_a, int pivot);
void	start_ra(t_stack *stack_a, int data[], int n);
void	start_rb(t_stack *stack_b, int data[], int n);
void	do_rrb(int rb_pa[], t_stack *stack_b);
#endif