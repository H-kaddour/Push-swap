/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:52:27 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 16:54:05 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

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
		error(0, 2);
}

void	error(char *str, int check)
{
	if (check == 0)
	{
		ft_putstr_fd(str, 2);
		exit(2);
	}
	else if (check == 1)
		ft_putstr_fd(str, 1);
	else
		exit(0);
		//exit(2);
}
