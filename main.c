/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:51:39 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/05 20:09:42 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		error("Enter the arg :v\nUsage: [push_swap] number :v", 0);
	data.stack_a = NULL;
	data.stack_b = NULL;
	get_arg(&data, av);
	check_sorted(&data);
	if (data.len <= 5)
		sort_small_num(&data);
	if (data.len > 5)
	{
		lis(&data);
		algorhythm(&data);
	}
	return (0);
}
