/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:52:27 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/01 17:06:19 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void  check_sorted(t_data *data)
{
  int i;

  i = 0;
  data->len = node_size(data->stack_a);
  while (i < data->len)
  {
    if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1))
      break ;
    i++;
  }
  if (i == data->len)
    error_push_P("those number are sorted");
}
