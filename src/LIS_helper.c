/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:57:21 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/06 11:14:22 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_list	*find_min(t_list *node)
{
	t_list	*next;
	int		i;

	i = 0;
	next = node;
	while (node)
	{
		if (node->data < next->data)
			next = node;
		node = node->link;
	}
	return (next);
}

int	find_big_value(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < data->len)
	{
		if (data->cache[i] >= data->cache[j])
			j = i;
		i++;
	}
	return (j);
}

void	be_ones(t_data *data)
{
	int	i;

	i = 1;
	data->cache = malloc(sizeof(int) * data->len);
	*data->cache++ = 0;
	while (i < data->len)
	{
		*data->cache++ = 1;
		i++;
	}
	data->cache = data->cache - data->len;
}
