/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:49:08 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 18:21:54 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a(t_data *data, int check)
{
	t_list	*next;

	if (node_size(data->stack_a) < 2)
		return ;
	next = data->stack_a->link;
	data->stack_a->link = next->link;
	next->link = data->stack_a;
	data->stack_a = next;
	next = NULL;
	if (check == 1)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_data *data, int check)
{
	t_list	*next;

	if (node_size(data->stack_b) < 2)
		return ;
	next = data->stack_b->link;
	data->stack_b->link = next->link;
	next->link = data->stack_b;
	data->stack_b = next;
	next = NULL;
	if (check == 1)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_data *data, int check)
{
	swap_a(data, 0);
	swap_b(data, 0);
	if (check == 1)
		ft_putstr_fd("ss\n", 1);
}

void	reverse_ab(t_data *data, int check)
{
	reverse_a(data, 0);
	reverse_b(data, 0);
	if (check == 1)
		ft_putstr_fd("rrr\n", 1);
}

void	p_a(t_data *data, int check)
{
	add_to_stack(&data->stack_b, &data->stack_a);
	pop_node(&data->stack_b);
	if (check == 1)
		ft_putstr_fd("pa\n", 1);
}
