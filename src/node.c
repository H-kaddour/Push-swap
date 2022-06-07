/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:47:29 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 18:24:17 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	node_size(t_list *node)
{
	t_list	*next;
	int		i;

	i = 0;
	next = node;
	while (next != NULL)
	{
		i++;
		next = next->link;
	}
	return (i);
}

void	fill_node(t_list *head, int data)
{
	head->data = data;
	head->link = NULL;
}

void	fill_stack_a(t_data *data)
{
	int		i;
	t_list	*head;
	t_list	*next;

	i = 0;
	head = malloc(sizeof(t_list));
	fill_node(head, ft_atoi(data->split[i++]));
	data->stack_a = head;
	while (data->split[i])
	{
		next = malloc(sizeof(t_list));
		next->data = ft_atoi(data->split[i]);
		next->link = NULL;
		head->link = next;
		head = next;
		i++;
	}
	next = NULL;
	if (duplicate_num(data))
		error("Duplicate number :/", 0);
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
	*node = next->link;
	free(next);
}
