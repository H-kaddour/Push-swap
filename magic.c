/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:04:18 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/04 13:47:30 by hkaddour         ###   ########.fr       */
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

void  check_part(t_data *data, int i)
{
  int k;
  int even;
  int odd;
  //t_list  *trav;
  int j;
  int m;

  //trav = data->stack_a;
  if (data->len % 2 == 0)
  {
    even = data->s_a;
    odd = (data->s_a) * -1;
  }
  //odd
  if (data->len % 2 == 1)
  {
    even = data->s_a + 1;
    odd = (data->s_a) * -1;
  }
  j = 0;
  while (j < even)
  {
    if (j == i)
    {
      data->big_i = i;
      break ;
    }
    j++;
  }
  k = odd;
  m = j;
  j = -i;
  //m = odd * -1;
  while (j < odd)
  {
    if (i == m)
    {
      data->big_i = k + 1;
      break ;
    }
    j++;
    k++;
    m++;
  }
}

void  big_index(t_list *node, t_data *data)
{
  //int i;
  //int k;
  //int even;
  //int odd;
  //t_list  *trav;

  //i = 0;
  //trav = data->stack_a;
  //even
  //if (data->len_b % 2 == 0)
  //{
  //  even = data->s_a + 1;
  //  odd = (data->s_a) * -1;
  //}
  ////odd
  //if (data->len_b % 2 == 1)
  //{
  //  even = data->s_a;
  //  odd = (data->s_a - 1) * -1;
  //}
  //while (trav)
  //{
  //  while (i < even)
  //  {
  //    if (trav->data == node->data)
  //    {
  //      data->big_i = i;
  //      break ;
  //    }
  //    trav = trav->link;
  //    i++;
  //  }
  //  k = -1;
  //  while (k > odd)
  //  {
  //    if (trav->data == node->data)
  //    {
  //      data->big_i = k;
  //      break ;
  //    }
  //    trav = trav->link;
  //    k--;
  //  }
  //}
  //while (i < even)
  //{
  //  if (trav->data == node->data)
  //  {
  //    data->big_i = i;
  //    break ;
  //  }
  //  trav = trav->link;
  //  i++;
  //}
  //k = -1;
  //while (k < odd)
  //{
  //  if (trav->data == node->data)
  //  {
  //    data->big_i = k;
  //    break ;
  //  }
  //  trav = trav->link;
  //  k--;
  //}

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
  data->big_i = i;
  //check_part(data, i);
  //return (i);
}

//int find_big_num(t_list *node, t_data *data)
void find_big_num(t_list *node, t_data *data)
{
  t_list  *next;
  //int     i;

  //i = 0;
  //segfault here
  if (node_size(node) == 0)
  {
    printf("exit");
    exit(0);
  }
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
  //i = big_index(next, data);
  big_index(next, data);
  //printf("%d\n", i);
  //printf("%d\n", next->data);
  //return (i);
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
  //data->min_index = i;
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
  //i = 0;
  //printf("\n---pos_b\n");
  //while (i < data->len_b)
  //{
  //  printf("| %d |\n", data->pos_b[i]);
  //  i++;
  //}
  //printf("\n");
}

void  do_it(t_data *data)
{
  int i;
  int j;

  //i = 0;
  //j = -1;
  //while (i <= data->len)
  //{
  //  if (i == data->big_i)
  //  {
  //    data->big_i = j;
  //    break ;
  //  }
  //  if (i >= data->s_a)
  //    j--;
  //  if (i == data->len)
  //    data->big_i = 0;
  //  i++;
  //}
  i = data->s_a + 1;
  //j = data->s_a * -1;
  j = data->down * -1;
  while (i <= data->len)
  {
    if (i == data->big_i)
    {
      data->big_i = j + 1;
      break ;
    }
    if (i == data->len - 1)
      data->big_i = 0;
      //data->pos_a[i] = j;
    i++;
    j++;
  }
}

void  fill_pos_a(t_data *data)
{
  int i;
  int j;
  int k;
  //int big_i;

  i = 0;
  data->down = data->s_a;
  //if (data->len % 2 == 0)
  //{
  //  data->s_a += 0;
  //}
  //data->big_i -= 1;
  if (data->len % 2 == 1)
  {
    data->s_a += 1;
  }
  while (i < data->len_b)
  {
    j = 0;
    //data->big_i = find_big_num(data->stack_a, data);
    find_big_num(data->stack_a, data);
    //if (node_index(data->stack_b, i) > data->big_i)
    //{
    if (data->big_i <= data->s_a)
      data->pos_a[i] = data->big_i;
    if (data->big_i > data->s_a)
    {
      do_it(data);
      data->pos_a[i] = data->big_i;
    }
      //if (big_i <= data->s_a + 1)
      //  data->pos_a[i] = big_i;
      //else if (big_i > data->s_a + 1)
      //  data->pos_a[i] = 1;
      //data->pos_a[i] = find_big_num(data->stack_a, data);
    //}
    if (node_index(data->stack_b, i) < data->stack_a->data && \
        node_index(data->stack_b, i) > node_index(data->stack_a, data->len))
    {
      //data->pos_a[i] = i;
      data->pos_a[i] = 0;
    }
    while (j < data->s_a /*+ 1*/)
    {
      if (node_index(data->stack_b, i) > node_index(data->stack_a, j) && \
          node_index(data->stack_b, i) < node_index(data->stack_a, j + 1))
      {//index of pos_a is "i"
        data->pos_a[i] = j + 1;
        break ;
        //break men loop
      }
      j++;
    }
    k = -(1);
    //k = 0;
    j = data->len - 1;
    while (j > data->s_a)
    {
      if (node_index(data->stack_b, i) < node_index(data->stack_a, j) && \
          node_index(data->stack_b, i) > node_index(data->stack_a, j - 1))
      {
        data->pos_a[i] = k;
        break ;
        //break men loop
      }
      k--;
      //k++;
      j--;
    }
    //if pos_a[0] == empty here go to this condition and add big_index in the pos_a
    //if (node_index(data->stack_b, i) > big_i)
    //{
    //  data->pos_a[i] = big_i;
    //  //data->pos_a[i] = find_big_num(data->stack_a, data);
    //}
    //printf("%d \n", data->pos_a[i]);
    //break ;
    i++;
  }
  //i = 0;
  //printf("\n---pos_a\n");
  //while (i < data->len_b)
  //{
  //  printf("| %d |\n", data->pos_a[i]);
  //  i++;
  //}
}

//Compare operation:
//1) if stack_b->data < stack_b->data && stack_b > last element of stack_a
//t_list  *find_best_element(t_data *data)

int find_best_element(t_data  *data)
{
  //t_list  *node;
  //t_list  *best;
  int     i;
  int     j;
  //int     *ptr;

  i = 0;
  //node = data->stack_b;
  //ptr = malloc(sizeof(int) * data->len_b);
  data->p = malloc(sizeof(int) * data->len_b);
  while (i < data->len_b /*&& j < data->len_b - 1*/)
  {
    if (data->pos_a[i] < 0 && data->pos_b[i] < 0)
      data->p[i] = (data->pos_a[i] * -1) + (data->pos_b[i] * -1);
      //ptr[i] = (data->pos_a[i] * -1) + (data->pos_b[i] * -1);
    else if (data->pos_a[i] < 0)
      data->p[i] = (data->pos_a[i] * -1) + data->pos_b[i];
    else if (data->pos_b[i] < 0)
      data->p[i] = data->pos_a[i] + data->pos_b[i] * -1;
    else
      data->p[i] = data->pos_a[i] + data->pos_b[i];

    i++;
    //if (data->pos_a[i] + data->pos_b[i] < data->pos_a[j] + data->pos_b[j])
    //  best = node;
    //node = node->link;
    //j++;
  }
  i = 0;
  j = 1;
  //best = node->link;
  while (j < data->len_b)
  {
    if (data->p[j] < data->p[i])
      i++;
      //best = node;
    j++;
    //node = node->link;
  }
  return (i);
  //return (best);
}

void  push_B(t_data *data)
{
  int i;
  int sign;

  if (data->pos_b[data->best] >= 0)
  {
    i = 0;
    //while (i < data->best)
    while (i < data->pos_b[data->best])
    {
      rotate_b(data, 1);
      i++;
    }
  }
  if (data->pos_b[data->best] < 0)
  {
    i = 0;
    sign = data->pos_b[data->best] * -1;
    //while (i < data->pos_b[data->best])
    while (i < sign)
    {
      reverse_b(data, 1);
      i++;
    }
  }
  //first gad place of the best element in stack B
  //second gad place rotate how many time in pos_a to push_b
  //then push the element to stack_a
}

void  push_A(t_data *data)
{
  int i;
  int sign;

  if (data->pos_a[data->best] >= 0)
  {
    i = 0;
    while (i < data->pos_a[data->best])
    {
      rotate_a(data, 1);
      i++;
    }
  }
  if (data->pos_a[data->best] < 0)
  {
    i = 0;
    sign = data->pos_a[data->best] * -1;
    while (i < sign /*data->pos_a[data->best]*/)
    {
      reverse_a(data, 1);
      i++;
    }
  }
  //first gad place of the best element in stack B
  //second gad place rotate how many time in pos_a to push_b
  //then push the element to stack_a
}

void  check_small_top(t_data *data)
{
  int i;
  t_list  *node;
  t_list  *trav_a;

  //i = 1;
  i = 0;
  trav_a = data->stack_a;
  node = find_min(data->stack_a, data);
  while (trav_a->link)
  {
    if (trav_a->data == node->data)
      break ;
    i++;
    trav_a = trav_a->link;
  }
  data->min_index = i;
  //printf("%d", i);
  i = 0;
  while (i < data->min_index)
  {
    rotate_a(data, 1);
    i++;
  }
  //if (data->min_index == 0)
  //  return ;
  //if (data->min_index == 1)
  //  rotate_a(data);
  //if (data->min_index < 1)
  //{
  //  while (i <= data->min_index - 1)
  //  {
  //    rotate_a(data);
  //    i++;
  //  }
  //}

  //if (data->min_index == 0)
  //  return ;
  //if (data->min_index == 1)
  //  rotate_a(data);
  //if (data->min_index < 1)
  //{
  //  while (i <= data->min_index - 1)
  //  {
  //    rotate_a(data);
  //    i++;
  //  }
  //}
}

void  LSD(t_data *data)
{
  int i;

  i = 0;
  int len;
  int check;
  //loop for all those element
  //data->len = node_size(data->stack_a);
  len = node_size(data->stack_b);
  //data->pos_a = malloc(sizeof(int) * data->len_b);
  //data->pos_b = malloc(sizeof(int) * data->len_b);
  //data->s_a = data->len / 2;
  //print_youness_ass(data);
  while (i < len)
  {
    data->len = node_size(data->stack_a);
    data->len_b = node_size(data->stack_b);
    data->pos_a = malloc(sizeof(int) * data->len_b);
    data->pos_b = malloc(sizeof(int) * data->len_b);
    data->s_a = data->len / 2;
    data->s_b = data->len_b / 2;
    fill_pos_b(data);
    fill_pos_a(data);
    data->best = find_best_element(data);
    //printf("**%d\n", data->best);
    //here check for smart rotate
    //here just pass 1 if smart rotate execute
    //check = check_smart_rotates(data);
    //check = 0;
    check = check_smart_rotates(data);
    if (check == 0)
    {
      push_B(data);
      push_A(data);
    }
    p_a(data, 1);
    //print_youness_ass(data);
    free(data->pos_a);
    free(data->pos_b);
    free(data->p);
    //free ptr of finding best element
    //printf("%d", data->best);

    //free(data->pos_a);
    //best_element(data);
    //push_to_a;
    //fill_pos_a(data);
    //find the smllest element
    //push it 
    //free all pos
    //loop again
    i++;
  }
  check_small_top(data);

    //i = 0;
    ////i = 0;
    //printf("\n\n---pos---\n");
    //while (i < data->len_b)
    //{
    //  //if (data->pos_b[i] < 0)
    //  //  printf("hey\n");
    //  printf("%d\n", data->pos_b[i]);
    //  i++;
    //}
    //printf("---------\n");
    //i = 0;
    //while (i < data->len_b)
    //{
    //  printf("%d\n", data->pos_a[i]);
    //  i++;
    //}
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
