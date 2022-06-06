/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:58:28 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/06 18:38:03 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	join_space(t_data *data)
{
	int	i;

	i = 0;
	while (data->arg[i])
		i++;
	data->ptr = malloc(sizeof(char) * i + 2);
	i = 0;
	while (data->arg[i])
	{
		data->ptr[i] = data->arg[i];
		i++;
	}
	data->ptr[i++] = ' ';
	data->ptr[i] = 0;
}

void	join_all(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(data->str) + ft_strlen(data->ptr);
	data->join = malloc(sizeof(char ) * len + 1);
	while (data->str[i])
		*data->join++ = data->str[i++];
	i = 0;
	while (data->ptr[i])
		*data->join++ = data->ptr[i++];
	*data->join = 0;
	free(data->str);
	free(data->ptr);
	data->str = data->join - len;
}

void	get_arg(t_data *data, char **av, int ac)
{
	int	j;

	j = 1;
	data->str = av[j];
	check_spaces(data);
	data->str = ft_strdup("");
	while (av[j])
	{
		if (av[1][0] == 0 && ac == 2)
			error("Arg is empty :/", 0);
		data->arg = av[j];
		join_space(data);
		join_all(data);
		j++;
	}
	data->split = ft_split(data->str, ' ');
	check_number(data);
	fill_stack_a(data);
	free(data->str);
}
