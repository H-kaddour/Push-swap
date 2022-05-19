/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:51:02 by hkaddour          #+#    #+#             */
/*   Updated: 2022/05/16 16:54:02 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct push
{
  int *tmp;
  int *cache;
  int len;
} t_data;

void  LIS_LSD(t_data *data)
{
  int i;
  int j;

  i = 1;
  while (i < data->len)
  {
    j = 0;
    while (j < i)
    {
      if (data->tmp[j] < data->tmp[i])
      {
        data->cache[i] = data->cache[j] + 1;
        //printf("%d", data->cache[i]);
      }
      j++;
    }
    i++;
  }
}

int main()
{
  t_data  data;
  int tt[] = {0, 22, 3, 7, 6, 10};
  int ll[] = {0, 1, 1, 1, 1, 1};
  
  data.tmp = tt;
  data.cache = ll;
  data.len = 6;
  LIS_LSD(&data);
  int *lis2 = malloc(sizeof(int) * ll[data.len - 1] + 1);
  int i = data.len - 1;
  int j = 0;
  int value = ll[data.len - 1];
  while(i >= 0)
  {
    if (ll[i] == value)
    {
      lis2[j] = tt[i];
      value--;
      j++;
    }
    i--;
  }
  i = 0;
  while (i < ll[data.len - 1] + 1)
  {
    printf("%d   ",lis2[i]);
    i++;
  }
}
