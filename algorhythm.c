/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorhythm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:58:14 by hkaddour          #+#    #+#             */
/*   Updated: 2022/05/19 13:04:06 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_list  *find_min(t_list *node)
{
  int i;
  t_list  *min;
  t_list  *next;
  
  i = 0;
  min = NULL;
  next = node->link;
  while (node)
  {
    if (node->data < next->data)
    {
      next = node;
      //min = next;
    }
    node = node->link;
  }
  //while (node)
  //{
    //while (next)
    //{
    //  if (node->data < next->data)
    //    min = node;
    //  else if (node->data > next->data)
    //    min = next;
    //  next = next->link;
    //  node = node->link;
    //}
    //while (node)
    //{
    //  //if (min->data < node->data)
    //  //  min = node;
    //  if (min->data > node->data)
    //    min = node;
    //  node = node->link;
    //}
  //}


//  while (next)
//  {
//    if (node->data < next->data)
//      min = node;
//    else if (node->data > next->data)
//      min = next;
//    next = next->link;
//    node = node->link;
//  }
  return (next);
}

void  get_sequence(t_data *data)
{
  int i;
  int j;
  int value;

  j = 0;
  i = data->len - 1;
  value = data->cache[data->len - 1];
  data->seq = malloc(sizeof(int) * data->cache[data->len - 1]);
  while (i >= 0)
  {
    if (data->cache[i] == value)
    {
      data->seq[j] = data->tmp[i];
      value--;
      j++;
    }
    i--;
  }

  //print caches
  //i = 0;
  data->len_seq = j;
  printf("cache number:\n");
  j--;
  while (j >= 0)
  {
    printf("%d ", data->seq[j]);
    j--;
    //i++;
  }
  printf("\n");
}

void  be_ones(t_data *data)
{
  int i;

  i = 1;
  data->cache = malloc(sizeof(int) * data->len);
  *data->cache++ = 0;
  while (i < data->len)
  {
    *data->cache++ = 1;
    i++;
  }
  //*data->cache = 0;
  data->cache = data->cache - data->len;
}

void  init_stacka_LIS(t_data *data)
{
  t_list  *trav_a;
  int i;
  int j;

  //while (i <= data->len_seq)
  //{
  //  j = 0;
  //  trav_a = data->stack_a;
  //  while (j < data->len)
  //  {
  //    if (data->seq[i] == trav_a->data)
  //    {
  //      rotate_a(data);
  //      break ;
  //    }
  //    trav_a = trav_a->link;
  //    j++;
  //  }
  //  i++;
  //}
  i = 0;
  while (i < data->len)
  {
    j = 0;
    trav_a = data->stack_a;
    while (j <= data->len_seq)
    {
      if (data->seq[j] == trav_a->data)
      {
        rotate_a(data);
        break ;
      }
      if (j == data->len_seq)
        p_b(data);
      j++;
    }
    i++;
    trav_a = trav_a->link;
  }
  //while (data->stack_a != NULL)
  //{
  //  printf("%d ", data->stack_a->data);
  //  data->stack_a = data->stack_a->link;
  //}
  //printf("\n");

  //while (data->stack_b != NULL)
  //{
  //  printf("%d ", data->stack_b->data);
  //  data->stack_b = data->stack_b->link;
  //}
  //printf("\n");
}

void  LIS_LSD(t_data *data)
{
  int i;
  int j;

  i = 1;
  be_ones(data);
  while (i < data->len)
  {
    j = 0;
    while (j < i)
    {
      if (data->tmp[j] < data->tmp[i])
        data->cache[i] = data->cache[j] + 1;
      j++;
    }
    i++;
  }
  get_sequence(data);
  init_stacka_LIS(data);

  //print the cache ones
  printf("cache ones:\n");
  i = 0;
  while (i < data->len)
  {
    printf("%d ", data->cache[i]);
    i++;
  }
}

void  algorhythm(t_data *data)
{
  //char  *tmp;
  //int   len;
  int   i;
  t_list  *min;
  t_list  *trav;
  t_list  *trav_a;

  i = 0;
  data->len = node_size(data->stack_a); 
  data->tmp = malloc(sizeof(int) * data->len + 1);
  min = find_min(data->stack_a);
  trav = min;
  while (trav)
  {
    data->tmp[i] = trav->data;
    trav = trav->link;
    i++;
  }
  trav_a = data->stack_a;
  while (trav_a != trav)
  {
    data->tmp[i] = trav_a->data;
    trav_a = trav_a->link;
    i++;
  }
  data->tmp[i] = 0;
  LIS_LSD(data);

  //i = 0;
  //while (i < data->len)
  //{
  //  printf("%d", data->cache[i]);
  //  i++;
  //}


  //print new cache:
  //i = 0;
  //while (i < data->len)
  //{
  //  printf("%d ", data->cache[i]);
  //  i++;
  //}
  //printf("\n--------------\n");



  //i = 0;
  ///print tmp 
  //printf("%d\n", data->len);
  //while (i < data->len)
  //{
  //  printf("%d\n", data->tmp[data->cache[i]]);
  //  i++;
  //}
  //printf("\n-------\n\n");



  //while (min)
  //{
  //  printf("%d\n", min->data);
  //  min = min->link;
  //}
  //printf("%d", min->data);
  //while (data->stack_a->link != NULL)
  //{
  //  tmp[i] = data->stack_a->data;
  //}
  //printf("%d", len);
}


  //pseudo code:
  //first find the smallest number in stack a push it up 
  //start in LIS algo :
    //*allocate a cache contain ones
    //*nested loop for traversing nodes and compare
    //*push other num to stack b


//pseudo code:
//count my linked list
//malloc an array of node len
//find the smallist element in the list
//copy from the smallest to the end NULL
//then start from the begining and start copy to the smallest element
//now tmp try to get the LIS
