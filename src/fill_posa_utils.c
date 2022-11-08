/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_posa_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:50:53 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 14:10:39 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	find_big_num(t_list *node, t_data *data)
{
	t_list	*next;

	if (node_size(node) == 0)
		exit(0);
	next = node->link;
	while (node)
	{
		if (node->data > next->data)
			next = node;
		node = node->link;
	}
	big_index(next, data);
}

void	do_it(t_data *data)
{
	int	i;
	int	j;

	i = data->s_a + 1;
	j = data->down * -1;
	while (i <= data->len)
	{
		if (i == data->big_i)
		{
			data->big_i = j + 1;
			break ;
		}
		if (i == data->len - 1)
			data->big_i = 0;
		i++;
		j++;
	}
}

void	check_big(t_data *data, int i)
{
	if (data->big_i <= data->s_a)
		data->pos_a[i] = data->big_i;
	if (data->big_i > data->s_a)
	{
		do_it(data);
		data->pos_a[i] = data->big_i;
	}
}

void	check_up_part_a(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < data->s_a)
	{
		if (node_index(data->stack_b, i) > node_index(data->stack_a, j) && \
				node_index(data->stack_b, i) < node_index(data->stack_a, j + 1))
		{
			data->pos_a[i] = j + 1;
			break ;
		}
		j++;
	}
}

void	check_down_part_a(t_data *data, int i)
{
	int	k;
	int	j;

	k = -(1);
	j = data->len - 1;
	while (j > data->s_a)
	{
		if (node_index(data->stack_b, i) < node_index(data->stack_a, j) && \
				node_index(data->stack_b, i) > node_index(data->stack_a, j - 1))
		{
			data->pos_a[i] = k;
			break ;
		}
		k--;
		j--;
	}
}
