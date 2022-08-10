/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:56:58 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/10 11:32:52 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_last(t_stack *st, t_node *target)
{
	t_node	*cur;

	if (st->count == 0)
	{
		st->head = target;
		st->tail = target;
		st->count += 1;
		return ;
	}
	cur = st->head;
	while (cur->next)
		cur = cur->next;
	target->prev = cur;
	cur->next = target;
	st->tail = target;
	st->count += 1;
}

void	ft_push(t_stack *st, t_node *target)
{
	t_node	*head;

	if (st->count == 0)
	{
		st->head = target;
		st->tail = target;
		st->count += 1;
		return ;
	}
	head = st->head;
	head->prev = target;
	st->head = target;
	st->head->next = head;
	st->count += 1;
}

t_node	*ft_pop_last(t_stack *st)
{
	t_node	*result;

	if (st-> count == 0)
		return (NULL);
	if (st-> count == 1)
	{
		st->count = 0;
		result = st->tail;
		st->head = NULL;
		st->tail = NULL;
		return (result);
	}
	result = st->tail;
	st->tail = st->tail->prev;
	st->tail->next = NULL;
	st->count -= 1;
	result->prev = NULL;
	result->next = NULL;
	return (result);
}

t_node	*ft_pop(t_stack *st)
{
	t_node	*result;

	if (st->count == 0)
		return (NULL);
	if (st-> count == 1)
	{
		st->count = 0;
		result = st->head;
		st->head = NULL;
		st->tail = NULL;
		return (result);
	}
	result = st->head;
	st->head = st->head->next;
	st->head->prev = NULL;
	st->count -= 1;
	result->prev = NULL;
	result->next = NULL;
	return (result);
}
