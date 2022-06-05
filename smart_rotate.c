/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:24:10 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 20:09:10 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	up_part_helper(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pos_a[data->best])
	{
		rotate_ab(data, 1);
		i++;
	}
	while (i < data->pos_b[data->best])
	{
		rotate_b(data, 1);
		i++;
	}
}

void	up_part(t_data *data)
{
	int	i;

	if (data->pos_a[data->best] > data->pos_b[data->best])
	{
		i = 0;
		while (i < data->pos_b[data->best])
		{
			rotate_ab(data, 1);
			i++;
		}
		while (i < data->pos_a[data->best])
		{
			rotate_a(data, 1);
			i++;
		}
	}
	else
		up_part_helper(data);
}

void	down_part_helper(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sign_a)
	{
		reverse_ab(data, 1);
		i++;
	}
	while (i < data->sign_b)
	{
		reverse_b(data, 1);
		i++;
	}
}

void	down_part(t_data *data)
{
	int	i;

	i = 0;
	data->sign_a = data->pos_a[data->best] * -1;
	data->sign_b = data->pos_b[data->best] * -1;
	if (data->sign_a > data->sign_b)
	{
		i = 0;
		while (i < data->sign_b)
		{
			reverse_ab(data, 1);
			i++;
		}
		while (i < data->sign_a)
		{
			reverse_a(data, 1);
			i++;
		}
	}
	else
		down_part_helper(data);
}

int	check_smart_rotates(t_data *data)
{
	int	i;

	i = 0;
	if (data->pos_a[data->best] > 0 && data->pos_b[data->best] > 0)
	{
		up_part(data);
		return (1);
	}
	if (data->pos_a[data->best] < 0 && data->pos_b[data->best] < 0)
	{
		down_part(data);
		return (1);
	}
	else
		return (0);
}
