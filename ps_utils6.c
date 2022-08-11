/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:44:33 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/08/11 11:29:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	release_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	*allocation_res(int size, int str_size)
{
	int		*result;

	if (size == 0)
		result = malloc (sizeof(int) * str_size);
	else
		result = malloc (sizeof(int) * (str_size + size));
	if (!result)
		print_error();
	return (result);
}

int	*fill_extend_arr(int *arr, int *size, char *str, int *validation)
{
	char	**strs;
	int		*result;
	int		str_size;
	int		i;

	strs = ft_split(str, ' ');
	str_size = get_size(strs);
	result = allocation_res(*size, str_size);
	i = 0;
	while (i < *size)
	{
		result[i] = arr[i];
		i++;
	}
	while (i < str_size + *size)
	{
		result[i] = ft_atoi(strs[i - *size], validation);
		if (*validation)
			print_error();
		i++;
	}
	*size = *size + str_size;
	return (result);
}
