/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorhythm_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:00:12 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 18:09:03 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	init_algorhythm(t_data *data)
{
	data->len = node_size(data->stack_a);
	data->len_b = node_size(data->stack_b);
	data->pos_a = malloc(sizeof(int) * data->len_b);
	data->pos_b = malloc(sizeof(int) * data->len_b);
	data->trav_a = data->stack_a;
	data->trav_b = data->stack_b;
	data->s_a = data->len / 2;
	data->s_b = data->len_b / 2;
}

int	find_best_element(t_data *data)
{
	int	i;

	i = 0;
	data->p = malloc(sizeof(int) * data->len_b);
	while (i < data->len_b)
	{
		if (data->pos_a[i] < 0 && data->pos_b[i] < 0)
			data->p[i] = (data->pos_a[i] * -1) + (data->pos_b[i] * -1);
		else if (data->pos_a[i] < 0)
			data->p[i] = (data->pos_a[i] * -1) + data->pos_b[i];
		else if (data->pos_b[i] < 0)
			data->p[i] = data->pos_a[i] + data->pos_b[i] * -1;
		else
			data->p[i] = data->pos_a[i] + data->pos_b[i];
		i++;
	}
	i = 0;
	data->j = 1;
	while (data->j < data->len_b)
	{
		if (data->p[data->j] < data->p[i])
			i++;
		data->j++;
	}
	return (i);
}

void	check_small_top(t_data *data)
{
	int		i;
	t_list	*node;
	t_list	*trav_a;

	i = 0;
	trav_a = data->stack_a;
	node = find_min(data->stack_a, data);
	while (trav_a->link)
	{
		if (trav_a->data == node->data)
			break ;
		i++;
		trav_a = trav_a->link;
	}
	data->min_index = i;
	i = 0;
	while (i < data->min_index)
	{
		rotate_a(data, 1);
		i++;
	}
}
