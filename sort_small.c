/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:34:47 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 20:02:56 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_three(t_data *data)
{
	int	i;

	i = 0;
	if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1) && \
			node_index(data->stack_a, i + 1) < node_index(data->stack_a, i + 2) && \
			node_index(data->stack_a, i) < node_index(data->stack_a, i + 2))
	  swap_a(data, 1);
	if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1) && \
			node_index(data->stack_a, i + 1) > node_index(data->stack_a, i + 2) && \
			node_index(data->stack_a, i) > node_index(data->stack_a, i + 2))
	{
		swap_a(data, 1);
		reverse_a(data, 1);
	}
	if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1) && \
			node_index(data->stack_a, i + 1) < node_index(data->stack_a, i + 2) && \
			node_index(data->stack_a, i) > node_index(data->stack_a, i + 2))
		rotate_a(data, 1);
	if (node_index(data->stack_a, i) < node_index(data->stack_a, i + 1) && \
			node_index(data->stack_a, i + 1) > node_index(data->stack_a, i + 2) && \
			node_index(data->stack_a, i) < node_index(data->stack_a, i + 2))
	{
		swap_a(data, 1);
		rotate_a(data, 1);
	}
	if (node_index(data->stack_a, i) < node_index(data->stack_a, i + 1) && \
			node_index(data->stack_a, i + 1) > node_index(data->stack_a, i + 2) && \
			node_index(data->stack_a, i) > node_index(data->stack_a, i + 2))
		reverse_a(data, 1);
}

void	sort_four(t_data *data, int check)
{
	t_list  *min;
	t_list  *trav_a;

	min = find_min(data->stack_a, data);
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

void	sort_five(t_data *data)
{
	int i;
	
	i = 0;
	t_list  *trav;
	t_list  *min;

	data->s_a = data->len /2 + 1;
	trav = data->stack_a;
	min = find_min(data->stack_a, data);
	while (trav->data != min->data)
	{
		trav = trav->link;
		i++;
	}
	trav = data->stack_a;
	while (trav->data != min->data)
	{
		if (i <= data->s_a)
			rotate_a(data, 1);
		if (i > data->s_a)
			reverse_a(data, 1);
		trav = data->stack_a;
	}
	p_b(data, 1);
	sort_four(data, 1);
	if (node_index(data->stack_b, 0) < node_index(data->stack_b, 1))
		swap_a(data, 1);
	p_a(data, 1);
	p_a(data, 1);
}

void  sort_small_num(t_data *data)
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
