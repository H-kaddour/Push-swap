/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:24:10 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/04 14:34:31 by hkaddour         ###   ########.fr       */
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
      rotate_ab(data, 1);
      i++;
    }
    //i = 0;
    while (i < data->pos_a[data->best])
    {
      rotate_a(data, 1);
      i++;
    }
  }
  //if (data->pos_a[data->best] < data->pos_b[data->best])
  else
  {
    i = 0;
    while (i < data->pos_a[data->best])
    {
      rotate_ab(data, 1);
      i++;
    }
    //i = 0;
    while (i < data->pos_b[data->best])
    {
      rotate_b(data, 1);
      i++;
    }
  }
}

void  down_part(t_data *data)
{
  int i;
  int sign_a;
  int sign_b;

  i = 0;
  sign_a = data->pos_a[data->best] * -1;
  sign_b = data->pos_b[data->best] * -1;
  //if (data->pos_a[data->best] > data->pos_b[data->best])
  if (sign_a > sign_b)
  {
    i = 0;
    //sign = data->pos_b[data->best] * -1;
    while (i < sign_b)
    {
      reverse_ab(data, 1);
      //rotate_ab(data, 1);
      i++;
    }
    //sign = data->pos_a[data->best] * -1;
    while (i < sign_a)
    {
      reverse_a(data, 1);
      //rotate_a(data, 1);
      i++;
    }
  }
  //if (data->pos_a[data->best] < data->pos_b[data->best])
  else
  {
    i = 0;
    //sign = data->pos_a[data->best] * -1;
    while (i < sign_a)
    {
      reverse_ab(data, 1);
      //rotate_ab(data, 1);
      i++;
    }
    //sign = data->pos_b[data->best] * -1;
    while (i < sign_b)
    {
      reverse_b(data, 1);
      //rotate_b(data, 1);
      i++;
    }
  }
}

int check_smart_rotates(t_data *data)
{
  int i;

  i = 0;
  if (data->pos_a[data->best] > 0 && data->pos_b[data->best] > 0)
  {
    up_part(data);
    return (1);
  }
  else if (data->pos_a[data->best] < 0 && data->pos_b[data->best] < 0)
  {
    down_part(data);
    return (1);
  }
  else
    return (0);
}
