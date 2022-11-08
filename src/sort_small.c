/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:34:47 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 14:10:55 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

static void	sort_three_helper(t_data *data)
{
	if (node_index(data->stack_a, 0) < node_index(data->stack_a, 1) && \
			node_index(data->stack_a, 1) > node_index(data->stack_a, 2) \
			&& node_index(data->stack_a, 0) < node_index(data->stack_a, 2))
	{
		swap_a(data, 1);
		rotate_a(data, 1);
	}
	if (node_index(data->stack_a, 0) < node_index(data->stack_a, 1) && \
			node_index(data->stack_a, 1) > node_index(data->stack_a, 2) \
			&& node_index(data->stack_a, 0) > node_index(data->stack_a, 2))
		reverse_a(data, 1);
}

static void	sort_three(t_data *data)
{
	if (node_index(data->stack_a, 0) > node_index(data->stack_a, 1) && \
			node_index(data->stack_a, 1) < node_index(data->stack_a, 2) \
			&& node_index(data->stack_a, 0) < node_index(data->stack_a, 2))
		swap_a(data, 1);
	if (node_index(data->stack_a, 0) > node_index(data->stack_a, 1) && \
			node_index(data->stack_a, 1) > node_index(data->stack_a, 2) \
			&& node_index(data->stack_a, 0) > node_index(data->stack_a, 2))
	{
		swap_a(data, 1);
		reverse_a(data, 1);
	}
	if (node_index(data->stack_a, 0) > node_index(data->stack_a, 1) && \
			node_index(data->stack_a, 1) < node_index(data->stack_a, 2) \
			&& node_index(data->stack_a, 0) > node_index(data->stack_a, 2))
		rotate_a(data, 1);
	else
		sort_three_helper(data);
}

static void	sort_four(t_data *data, int check)
{
	t_list	*min;
	t_list	*trav_a;

	min = find_min(data->stack_a);
	trav_a = data->stack_a;
	while (trav_a->data != min->data)
	{
		rotate_a(data, 1);
		trav_a = data->stack_a;
	}
	p_b(data, 1);
	sort_three(data);
	if (check == 0)
		p_a(data, 1);
}

static void	sort_five(t_data *data)
{
	data->j = 0;
	data->s_a = data->len / 2 + 1;
	data->trav_a = data->stack_a;
	data->min = find_min(data->stack_a);
	while (data->trav_a->data != data->min->data)
	{
		data->trav_a = data->trav_a->link;
		data->j++;
	}
	data->trav_a = data->stack_a;
	while (data->trav_a->data != data->min->data)
	{
		if (data->j <= data->s_a)
			rotate_a(data, 1);
		if (data->j > data->s_a)
			reverse_a(data, 1);
		data->trav_a = data->stack_a;
	}
	p_b(data, 1);
	sort_four(data, 1);
	if (node_index(data->stack_b, 0) < node_index(data->stack_b, 1))
		swap_a(data, 1);
	p_a(data, 1);
	p_a(data, 1);
}

void	sort_small_num(t_data *data)
{
	if (data->len == 2)
		swap_a(data, 1);
	if (data->len == 3)
		sort_three(data);
	if (data->len == 4)
		sort_four(data, 0);
	if (data->len == 5)
		sort_five(data);
}
