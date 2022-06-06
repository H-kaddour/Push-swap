/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:52:27 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/06 18:37:29 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	check_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len)
	{
		if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1))
			break ;
		i++;
	}
	if (i == data->len)
		error("Number already sorted :D", 0);
}

int	duplicate_num(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->len = node_size(data->stack_a);
	while (i < data->len)
	{
		j = i + 1;
		while (j < data->len)
		{
			if (node_index(data->stack_a, i) == node_index(data->stack_a, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_spaces(t_data *data)
{
	int	i;

	i = 0;
	if (data->str[i] == ' ')
	{
		while (data->str[i])
		{
			if (data->str[i] != ' ')
				break ;
			i++;
		}
		if (data->str[i] == '\0')
			error("First arg it's all spaces :v", 0);
	}
}

void	check_number(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split[i])
	{
		j = 0;
		while (data->split[i][j])
		{
			if (!ft_isdigit(data->split[i][j]))
				error("Not number :/", 0);
			j++;
		}
		i++;
	}
}

void	error(char *str, int check)
{
	if (check == 0)
	{
		ft_putstr_fd(str, 1);
		exit(0);
	}
	else if (check == 1)
		ft_putstr_fd(str, 1);
	else
		exit(0);
}
