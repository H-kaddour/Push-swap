/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:24:10 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/02 20:03:19 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void  up_part(t_data *data)
{
  int i;

  if (data->pos_a[data->best] > data->pos_b[data->best])
  {
    i = 0;
    //check if pos of a and b in index [data->best] are not negative
    while (i < data->pos_b[data->best])
    {
      rotate_ab(data);
      i++;
    }
    //i = 0;
    while (i < data->pos_a[data->best])
    {
      rotate_a(data);
      i++;
    }
  }
  if (data->pos_a[data->best] < data->pos_b[data->best])
  {
    i = 0;
    while (i < data->pos_a[data->best])
    {
      rotate_ab(data);
      i++;
    }
    //i = 0;
    while (i < data->pos_b[data->best])
    {
      rotate_b(data);
      i++;
    }
  }
}

void  down_part(t_data *data)
{
  int i;

  i = 0;
  if (data->pos_a[data->best] > data->pos_b[data->best])
  {

  }
  if (data->pos_a[data->best] < data->pos_b[data->best])
  {

  }
}

void  check_smart_rotates(t_data *data)
{
  int i;

  i = 0;
  if (data->pos_a[data->best] >= 0 && data->pos_b[data->best] >= 0)
    up_part(data);
  if (data->pos_a[data->best] < 0 && data->pos_b[data->best] < 0)
    down_part(data);
}
