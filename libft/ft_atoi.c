/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:54:08 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/08 16:06:57 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	check_max_min(long rslt)
{
	if (rslt > INT_MAX)
		error("Error INT MAX", 0);
	else if (rslt < INT_MIN)
		error("Error INT MIN", 0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt = (rslt * 10) + (str[i] - '0');
		i++;
	}
	check_max_min(rslt);
	return (rslt * sign);
}
