/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:58:28 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 16:58:27 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	init(t_data *data, int ac, char **av)
{
	data->av = &av[1];
	data->ac = ac - 1;
}

static void	check_only_number(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->av[i])
	{
		j = 0;
		while (data->av[i][j])
		{
			if (!(data->av[i][j] >= '0' && data->av[i][j] <= '9'))
				error("Error\n", 0);
			j++;
		}
		i++;
	}
}

static void	check_if_duplicated(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->ac)
	{
		j = 0;
		while (data->av[j])
		{
			if (ft_atoi(data->av[i]) == ft_atoi(data->av[j]) && i != j)
				error("Error\n", 0);
			j++;
		}
		i++;
	}
}

void	parsing(t_data *data)
{
	check_only_number(data);
	check_if_duplicated(data);
	fill_stack_a(data);
	data->len = node_size(data->stack_a);
}
