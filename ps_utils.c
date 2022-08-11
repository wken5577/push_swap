/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:23:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 17:44:47 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	validation_argv_isnum(char **strs)
{
	int		i;
	int		j;

	i = 0;
	while (strs[i])
	{	
		if (strs[i][0] == '-' || strs[i][0] == '+')
			j = 1;
		else
			j = 0;
		if (strs[i][j] == 0)
			return (0);
		while (strs[i][j])
		{
			if (ft_isdigit(strs[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	comp_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	validation_argv_uniq(char **argv)
{
	int			*arr;
	int			i;
	int			size;
	int			validaton;

	i = 0;
	validaton = 0;
	size = 0;
	arr = 0;
	while (argv[++i])
		arr = fill_extend_arr(arr, &size, argv[i], &validaton);
	sort_arr(arr, size);
	validaton = comp_arr(arr, size);
	free(arr);
	return (validaton);
}
