/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:58:14 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 18:04:16 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	fill_tmp(t_data *data, t_list *min)
{
	int		i;
	t_list	*trav;
	t_list	*trav_a;

	i = 0;
	trav = min;
	trav_a = data->stack_a;
	while (trav)
	{
		data->tmp[i] = trav->data;
		trav = trav->link;
		i++;
	}
	while (trav_a != trav)
	{
		data->tmp[i] = trav_a->data;
		trav_a = trav_a->link;
		i++;
	}
}

void	implement_cache(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	be_ones(data);
	while (i < data->len)
	{
		j = 0;
		while (j < i)
		{
			if (data->tmp[j] < data->tmp[i] && \
					data->cache[i] < data->cache[j] + 1)
				data->cache[i] = data->cache[j] + 1;
			j++;
		}
		i++;
	}
}

void	get_sequence(t_data *data)
{
	int	i;
	int	j;
	int	value;

	j = 0;
	i = data->len - 1;
	value = find_big_value(data);
	value = data->cache[value];
	data->len_seq = value;
	data->seq = malloc(sizeof(int) * data->len_seq);
	while (i >= 0)
	{
		if (data->cache[i] == value)
		{
			data->seq[j] = data->tmp[i];
			value--;
			j++;
		}
		i--;
	}
}

void	init_stacka_lis(t_data *data)
{
	int		i;
	int		j;
	t_list	*trav_a;

	i = 0;
	while (i < data->len)
	{
		j = 0;
		trav_a = data->stack_a;
		while (j <= data->len_seq)
		{
			if (data->seq[j] == trav_a->data)
			{
				rotate_a(data, 1);
				break ;
			}
			if (j == data->len_seq)
			{
				p_b(data, 1);
			}
			j++;
		}
		i++;
	}
}

void	lis(t_data *data)
{
	t_list	*min;
	int		i;

	i = 0;
	data->len = node_size(data->stack_a);
	data->tmp = malloc(sizeof(int) * data->len);
	min = find_min(data->stack_a, data);
	fill_tmp(data, min);
	implement_cache(data);
	get_sequence(data);
	init_stacka_lis(data);
}
