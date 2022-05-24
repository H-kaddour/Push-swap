/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:04:18 by hkaddour          #+#    #+#             */
/*   Updated: 2022/05/24 17:49:46 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//pseudo code:
//first make 2 arrays to store indexex of there

//t_list  *find_big_num(t_list *node)
//{
//  int i;
//  t_list  *min;
//  t_list  *next;
//  
//  i = 0;
//  min = NULL;
//  next = node->link;
//  while (node)
//  {
//    if (node->data < next->data)
//      next = node;
//  }
//  return (next);
//}

int big_index(t_list *node, t_data *data)
{
  t_list  *trav;
  int i;

  i = 1;
  trav = data->stack_a;
  while (trav)
  {
    if (trav->data == node->data)
      break ;
    trav = trav->link;
    i++;
  }
  return (i);
}

int find_big_num(t_list *node, t_data *data)
{
  t_list  *next;
  int     i;

  //i = 0;
  next = node->link;
  while (node)
  {
    if (node->data > next->data)
    {
      next = node;
      //i++;
      //break ;
    }
    node = node->link;
    //i++;
  }
  i = big_index(next, data);
  //printf("%d\n", i);
  //printf("%d\n", next->data);
  return (i);
}

int node_index(t_list *stack, int index)
{
  int i;

  i = 0;
  while (stack->link && i < index)
  {
    stack = stack->link;
    i++;
  }
  return (stack->data);
}

void  fill_pos_b(t_data *data)
{
  int i;
  int j;
  int k;
  int b;
  int odd;

  i = 0;
  b = 0;
  k = 0;
  data->trav_b = data->stack_b;
  data->s_b = data->len_b / 2;
  if (data->len_b % 2 == 1)
    odd = data->s_b + 1;
  if (data->len_b % 2 == 0)
    odd = data->s_b;
  while (data->trav_b->link)
  {
    if (i < odd)
    {
      data->pos_b[b] = i;
      i++;
    }
    j = -(i - k);
    b++;
    if (i >= data->s_b)
    {
      data->pos_b[b] = j;
      k++;
    }
    data->trav_b = data->trav_b->link;
  }
}


void  fill_pos_a(t_data *data)
{
  int i;
  int j;
  int k;
  int big_i;

  i = 0;
  while (i < data->len_b)
  {
    j = 0;
    if (data->stack_b->data < data->stack_a->data && data->stack_b->data > node_index(data->stack_a, data->len))
    {
      data->pos_a[i] = i;
    }
    while (j < data->s_a /*+ 1*/)
    {
      if (data->stack_b->data > node_index(data->stack_a, j) && data->stack_b->data < node_index(data->stack_a, j + 1))
      {//index of pos_a is "i"
        data->pos_a[i] = j;
        //break men loop
      }
      j++;
    }
    k = -(1);
    j = data->len - 1;
    while (j > data->s_a)
    {
      if (data->stack_b->data < node_index(data->stack_a, j) && data->stack_b->data > node_index(data->stack_a, j - 1))
      {
        data->pos_a[i] = k;
        //break ;
        //break men loop
      }
      k--;
      j--;
    }
    //if pos_a[0] == empty here go to this condition and add big_index in the pos_a
    //if ()
    big_i = find_big_num(data->stack_a, data);
    i++;
  }
}

//Compare operation:
//1) if stack_b->data < stack_b->data && stack_b > last element of stack_a


void  LSD(t_data *data)
{
  int i;

  i = 0;
  //loop for all those element
  data->len = node_size(data->stack_a);
  data->len_b = node_size(data->stack_b);
  data->pos_a = malloc(sizeof(int) * data->len_b);
  data->pos_b = malloc(sizeof(int) * data->len_b);
  data->s_a = data->len / 2;
  //while (i < data->len_b)
  //{
    //fill_pos_b(data);
    fill_pos_a(data);
    //find the smllest element
    //push it 
    //free all pos
    //loop again
  //}


  while (i < data->len_b)
  {
    printf("%d\n", data->pos_a[i]);
    i++;
  }
}

























//void  fill_pos_a(t_data *data)
//{
//  int i;
//  int j;
//
//  i = 0;
//  while (i < data->len_b)
//  {
//    j = 0;
//    while (j < data->len)
//    {
//      if (data->stack_b->data < data->stack_a->data && data->stack_b->data > node_index(data->stack_a, 5))
//        data->pos_a[i] = i;
//      //make a loop to check if the number is between two number and start incrementing
//    }
//    i++;
//  }
//}






//old shit;
//void  LSD(t_data *data)
//{
//  int i;
//  int j;
//  int s_a;
//  int s_b;
//  t_list  *trav_a;
//  t_list  *trav_b;
//  //t_list  *last;
//
//  i = 0;
//  //store size of a
//  data->len = node_size(data->stack_a);
//  //store size of b
//  data->len_b = node_size(data->stack_b);
//  s_a = data->len / 2;
//  s_b = data->len_b / 2;
//  data->pos_a = malloc(sizeof(int) * data->len);
//  data->pos_b = malloc(sizeof(int) * data->len_b);
//  trav_a = data->stack_a;
//  trav_b = data->stack_b;
//  //last = trav_a;
//  //while (last->link)
//  //  last = last->link;
//  //i = 5;
//  //last = node_index(data->stack_a, i);
//  //printf("%d\n", last->data);
//  //printf("%d", node_index(data->stack_a, i));
//  while (i < data->len_b)
//  {
//    j = 0;
//    while (j < data->len)
//    {
//      //compare first and last indexes
//      if (trav_b->data < trav_a->data && trav_b->data > node_index(trav_a, j))
//      {
//        data->pos_a[i] = i;
//      }
//      //compare all the stack and increment the index 
//      //if (trav_a)
//    }
//    j++;
//  }
//  i++;
//}
















































  //t_list  *trav_a;
  //t_list  *trav_b;
  //int     i;
  //int     j;
  //int     len_b;

  //i = 0;
  //len_b = node_size(data->stack_b);
  //trav_a = data->stack_a;
  //trav_b = data->stack_b;
  //while (i < data->len)
  //{
  //  j = 0;
  //  while (j < len_b)
  //  {
  //    if (trav_b >= trav_a && trav_b <= trav_a)
  //    {
  //    }
  //  }
  //  i++;
  //}










  //pseudo code:
  //loop for stack B and A and everytime check the 4 condition where that number should be replace in stack B and save this value and in stack A and save the value.
  //make the 4 condition to check where the number should be replace index









//make an array of stack a and b:
//  t_list  *trav_a;
//  t_list  *trav_b;
//  int     i;
//  int     j;
//  int     *s_a;
//  int     *s_b;
//  int     len;
//
//  i = 0;
//  trav_a = data->stack_a;
//  trav_b = data->stack_b;
//  data->len = node_size(trav_a);
//  len = node_size(trav_b);
//  s_a = malloc(sizeof(int) * data->len);
//  s_b = malloc(sizeof(int) * len);
//  while (trav_a != NULL)
//  {
//    s_a[i] = trav_a->data;
//    trav_a = trav_a->link;
//    i++;
//  }
//  //i = 0;
//  j = 0;
//  while (trav_b != NULL)
//  {
//    s_b[j] = trav_b->data;
//    trav_b = trav_b->link;
//    j++;
//  }
//  //here check if the 4 condition if and save positions
//  i = 0;
//  while (i < data->len)
//  {
//    printf("%d ", s_a[i]);
//    i++;
//  }
//  printf("\n");
//  j = 0;
//  while (j < len)
//  {
//    printf("%d ", s_b[j]);
//    j++;
//  }
