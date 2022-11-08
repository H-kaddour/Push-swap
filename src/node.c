/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:47:29 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 16:57:12 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	node_size(t_list *node)
{
	int		i;
	t_list	*next;

	i = 0;
	next = node;
	while (next)
	{
		i++;
		next = next->link;
	}
	return (i);
}

void	fill_stack_a(t_data *data)
{
	int		i;
	t_list	*head;
	t_list	*next;

	i = 0;
	head = ft_calloc(1, sizeof(t_list));
	head->data = ft_atoi(data->av[i++]);
	data->stack_a = head;
	while (data->av[i])
	{
		next = ft_calloc(1, sizeof(t_list));
		next->data = ft_atoi(data->av[i++]);
		head->link = next;
		head = next;
	}
}

void	add_to_stack(t_list **node, t_list **node2)
{
	t_list	*head;
	t_list	*ptr;

	if (node_size(*node) == 0)
		return ;
	head = malloc(sizeof(t_list));
	ptr = *node;
	head->data = ptr->data;
	head->link = NULL;
	head->link = *node2;
	*node2 = head;
}

void	pop_node(t_list **node)
{
	t_list	*next;

	next = *node;
	//here check if next->link exist then do it
	*node = next->link;
	free(next);
}
