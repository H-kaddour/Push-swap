/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:19:06 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/06 09:27:42 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

void	swap_ab(t_data *data, int check)
{
	swap_a(data, 0);
	swap_b(data, 0);
	if (check == 1)
		ft_putstr_fd("ss\n", 1);
}

void	rotate_ab(t_data *data, int check)
{
	rotate_a(data, 0);
	rotate_b(data, 0);
	if (check == 1)
		ft_putstr_fd("rr\n", 1);
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
