/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:23:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/09 13:12:51 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	validation_argv_isnum(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j = 1;
		else
			j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
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

int	comp_arr(int *arr, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (arr[i] == arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	validation_argv_uniq(int argc, char **argv)
{
	int			*arr;
	int			i;
	int			j;
	int			validaton;

	arr = malloc(sizeof(long long) * (argc - 1));
	if (!arr)
		print_error();
	i = 1;
	j = 0;
	validaton = 0;
	while (argv[i])
	{
		arr[j] = ft_atoi(argv[i], &validaton);
		if (validaton)
			return (0);
		i++;
		j++;
	}
	sort_arr(arr, argc - 1);
	validaton = comp_arr(arr, argc);
	free(arr);
	return (validaton);
}
