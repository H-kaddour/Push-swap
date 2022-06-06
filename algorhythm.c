/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorhythm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:04:18 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/06 19:01:24 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	fill_pos_b(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	data->index = 0;
	odd_b(data);
	while (data->trav_b->link)
	{
		if (i < data->odd)
		{
			data->pos_b[data->index] = i;
			i++;
		}
		data->j = -(i - k);
		data->index++;
		if (i >= data->s_b)
		{
			data->pos_b[data->index] = data->j;
			k++;
		}
		data->trav_b = data->trav_b->link;
	}
}

static void	fill_pos_a(t_data *data)
{
	int	i;

	i = 0;
	data->down = data->s_a;
	if (data->len % 2 == 1)
		data->s_a += 1;
	while (i < data->len_b)
	{
		find_big_num(data->stack_a, data);
		check_big(data, i);
		if (node_index(data->stack_b, i) < data->stack_a->data && \
			node_index(data->stack_b, i) > node_index(data->stack_a, data->len))
			data->pos_a[i] = 0;
		check_up_part_a(data, i);
		check_down_part_a(data, i);
		i++;
	}
}

static void	push_b(t_data *data)
{
	int	i;
	int	sign;

	if (data->pos_b[data->best] > 0)
	{
		i = 0;
		while (i < data->pos_b[data->best])
		{
			rotate_b(data, 1);
			i++;
		}
	}
	if (data->pos_b[data->best] < 0)
	{
		i = 0;
		sign = data->pos_b[data->best] * -1;
		while (i < sign)
		{
			reverse_b(data, 1);
			i++;
		}
	}
}

static void	push_a(t_data *data)
{
	int	i;
	int	sign;

	if (data->pos_a[data->best] > 0)
	{
		i = 0;
		while (i < data->pos_a[data->best])
		{
			rotate_a(data, 1);
			i++;
		}
	}
	else if (data->pos_a[data->best] < 0)
	{
		i = 0;
		sign = data->pos_a[data->best] * -1;
		while (i < sign)
		{
			reverse_a(data, 1);
			i++;
		}
	}
}

void	algorhythm(t_data *data)
{
	int	i;
	int	len;
	int	check;

	i = 0;
	len = node_size(data->stack_b);
	while (i < len)
	{
		init_algorhythm(data);
		fill_pos_b(data);
		fill_pos_a(data);
		find_best_element(data);
		check = check_smart_rotates(data);
		if (check == 0)
		{
			push_b(data);
			push_a(data);
		}
		p_a(data, 1);
		free(data->pos_a);
		free(data->pos_b);
		free(data->p);
		i++;
	}
	check_small_top(data);
}
