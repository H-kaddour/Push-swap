/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:51:39 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 16:54:46 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	main(int ac, char **av)
{
	t_data	data;

	//if (ac == 1)
	if (ac <= 2)
		return (0);
	data.stack_a = 0;
	data.stack_b = 0;
	init(&data, ac, av);
	parsing(&data);
	check_sorted(&data);
	if (data.len <= 5)
		sort_small_num(&data);
	else if (data.len > 5)
	{
		lis(&data);
		algorhythm(&data);
	}
	return (0);
}
