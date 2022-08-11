/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:48:30 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 19:31:21 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
char	*get_next_line(int fd);
#endif