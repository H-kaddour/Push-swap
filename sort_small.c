/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:34:47 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/01 18:42:48 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void  sort_three(t_data *data)
{
  int i;

  i = 0;
  if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1) &&
      node_index(data->stack_a, i + 1) < node_index(data->stack_a, i + 2) &&
      node_index(data->stack_a, i) < node_index(data->stack_a, i + 2))
    swap_a(data);
  if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1) &&
      node_index(data->stack_a, i + 1) > node_index(data->stack_a, i + 2) &&
      node_index(data->stack_a, i) > node_index(data->stack_a, i + 2))
  {
    swap_a(data);
    reverse_a(data);
  }
  if (node_index(data->stack_a, i) > node_index(data->stack_a, i + 1) &&
      node_index(data->stack_a, i + 1) < node_index(data->stack_a, i + 2) &&
      node_index(data->stack_a, i) > node_index(data->stack_a, i + 2))
    rotate_a(data);
  if (node_index(data->stack_a, i) < node_index(data->stack_a, i + 1) &&
      node_index(data->stack_a, i + 1) > node_index(data->stack_a, i + 2) &&
      node_index(data->stack_a, i) < node_index(data->stack_a, i + 2))
  {
    swap_a(data);
    rotate_a(data);
  }
  if (node_index(data->stack_a, i) < node_index(data->stack_a, i + 1) &&
      node_index(data->stack_a, i + 1) > node_index(data->stack_a, i + 2) &&
      node_index(data->stack_a, i) > node_index(data->stack_a, i + 2))
    reverse_a(data);
}

void  sort_four(t_data *data)
{
  int i;
  t_list  *min;
  t_list  *trav_a;

  i = 0;
  min = find_min(data->stack_a, data);
  trav_a = data->stack_a;
  printf("%d\n", min->data);
  while (trav_a != min)
  {
    rotate_a(data);
    trav_a = trav_a->link;
  }
  printf("**%d\n", trav_a->data);
  //p_b(data);
  //sort_three(data);
  //p_a(data);
}

void  sort_small_num(t_data *data)
{
  if (data->len == 3)
    sort_three(data);
  if (data->len == 4)
    sort_four(data);
  //if (data->len == 5)
  //  sort_five(data);
}
