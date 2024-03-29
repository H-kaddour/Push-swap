/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorhythm_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:03:15 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 14:10:32 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	check_even_odd(t_data *data)
{
	if (data->len % 2 == 0)
	{
		data->even = data->s_a;
		data->odd = (data->s_a) * -1;
	}
	if (data->len % 2 == 1)
	{
		data->even = data->s_a + 1;
		data->odd = (data->s_a) * -1;
	}
}

int	node_index(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack->link && i < index)
	{
		stack = stack->link;
		i++;
	}
	return (stack->data);
}

void	odd_b(t_data *data)
{
	if (data->len_b % 2 == 1)
		data->odd = data->s_b + 1;
	if (data->len_b % 2 == 0)
		data->odd = data->s_b;
}

void	big_index(t_list *node, t_data *data)
{
	t_list	*trav;
	int		i;

	i = 1;
	trav = data->stack_a;
	while (trav)
	{
		if (trav->data == node->data)
			break ;
		trav = trav->link;
		i++;
	}
	data->big_i = i;
}

void	p_b(t_data *data, int check)
{
	add_to_stack(&data->stack_a, &data->stack_b);
	pop_node(&data->stack_a);
	if (check == 1)
		ft_putstr_fd("pb\n", 1);
}
