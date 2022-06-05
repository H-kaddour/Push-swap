/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:19:06 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 18:20:09 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate_a(t_data *data, int check)
{
	t_list	*next;

	if (node_size(data->stack_a) < 2)
		return ;
	next = data->stack_a;
	while (next->link != NULL)
		next = next->link;
	next->link = data->stack_a;
	data->stack_a = data->stack_a->link;
	next->link->link = NULL;
	next = NULL;
	if (check == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_data *data, int check)
{
	t_list	*next;

	if (node_size(data->stack_b) < 2)
		return ;
	next = data->stack_b;
	while (next->link != NULL)
		next = next->link;
	next->link = data->stack_b;
	data->stack_b = data->stack_b->link;
	next->link->link = NULL;
	next = NULL;
	if (check == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_data *data, int check)
{
	rotate_a(data, 0);
	rotate_b(data, 0);
	if (check == 1)
		ft_putstr_fd("rr\n", 1);
}

void	reverse_a(t_data *data, int check)
{
	t_list	*next;

	if (node_size(data->stack_a) < 2)
		return ;
	next = data->stack_a;
	while (next->link->link != NULL)
		next = next->link;
	next->link->link = data->stack_a;
	data->stack_a = next->link;
	next->link = NULL;
	next = NULL;
	if (check == 1)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_b(t_data *data, int check)
{
	t_list	*next;

	if (node_size(data->stack_b) < 2)
		return ;
	next = data->stack_b;
	while (next->link->link != NULL)
		next = next->link;
	next->link->link = data->stack_b;
	data->stack_b = next->link;
	next->link = NULL;
	next = NULL;
	if (check == 1)
		ft_putstr_fd("rrb\n", 1);
}
