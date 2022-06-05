/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:19 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 17:49:44 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_sor(t_data *data)
{
	int	i;

	i = 0;
	data->len = node_size(data->stack_a) - 1;
	while (i < data->len)
	{
		if (node_index(data->stack_a, i) < node_index(data->stack_a, i + 1))
		{
			if (i == data->len - 1)
				return (1);
			i++;
		}
		else
			break ;
	}
	return (0);
}

void	sort(t_data *data)
{
	if (!ft_strncmp(data->input, "sa", data->len))
		swap_a(data, 0);
	else if (!ft_strncmp(data->input, "sb", data->len))
		swap_b(data, 0);
	else if (!ft_strncmp(data->input, "ss", data->len))
		swap_ab(data, 0);
	else if (!ft_strncmp(data->input, "ra", data->len))
		rotate_a(data, 0);
	else if (!ft_strncmp(data->input, "rb", data->len))
		rotate_b(data, 0);
	else if (!ft_strncmp(data->input, "rr", data->len))
		rotate_ab(data, 0);
	else if (!ft_strncmp(data->input, "rra", data->len))
		reverse_a(data, 0);
	else if (!ft_strncmp(data->input, "rrb", data->len))
		reverse_b(data, 0);
	else if (!ft_strncmp(data->input, "rrr", data->len))
		reverse_ab(data, 0);
	else if (!ft_strncmp(data->input, "pa", data->len))
		p_a(data, 0);
	else if (!ft_strncmp(data->input, "pb", data->len))
		p_b(data, 0);
}

int	check_error(int len, char *input)
{
	if (!ft_strncmp(input, "sa", len) || !ft_strncmp(input, "sb", len) || \
			!ft_strncmp(input, "ss", len))
		return (0);
	else if (!ft_strncmp(input, "ra", len) || !ft_strncmp(input, "rb", len) || \
			!ft_strncmp(input, "rr", len))
		return (0);
	else if (!ft_strncmp(input, "ra", len) || !ft_strncmp(input, "rb", len) || \
			!ft_strncmp(input, "rrr", len))
		return (0);
	else if (!ft_strncmp(input, "pa", len) || !ft_strncmp(input, "pb", len))
		return (0);
	else
		return (1);
}

void	instructions(t_data *data)
{
	int	i;

	i = 0;
	if (check_error(data->len, data->input))
	{
		ft_putstr_fd("Error\n", 1);
		exit(127);
	}
	while (data->sp_inst[i])
	{
		if (!ft_strncmp(data->input, data->sp_inst[i], data->len))
			sort(data);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.inst = "sa sb ss ra rb rr rra rrb rrr pa pb";
	data.sp_inst = ft_split(data.inst, ' ');
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (ac == 1)
		error("Enter the arg :v\nUsage: [checker] number :v", 0);
	get_arg(&data, av);
	while (1)
	{
		data.input = grab_line(0);
		if (!data.input)
			break ;
		data.len = ft_strlen(data.input);
		if (!data.len)
			error("Error\n", 0);
		instructions(&data);
		free(data.input);
	}
	if (check_sor(&data))
		error("OK\n", 0);
	else
		error("KO\n", 0);
}
