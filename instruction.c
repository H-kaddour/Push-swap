/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:49:08 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/01 11:25:09 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//this one is for returning and i won't returning fuck that shit
//t_list  *swap_a(t_list *head)
//{
//  t_list  *next;
//
//  //check if the node is empty or contain one element.
//  next = head->link;
//  head->link = next->link;
//  next->link = head;
//  return (next);
//}

//t_list  *swap_b(t_list *head)
//{
//  t_list  *next;
//
//  //check if the node is empty or contain one element.
//  next = head->link;
//  head->link = next->link;
//  next->link = head;
//  return (next);
//}

//void  error_ins(char *str)
//{
//  ft_putstr_fd(str, 1);
//}

void  swap_a(t_data *data)
{
  t_list  *next;

  if (node_size(data->stack_a) < 2)
  {
    ft_putstr_fd("stack a is empty or under 2 arg.\n", 1);
    return ;
  }
  next = data->stack_a->link;
  data->stack_a->link = next->link;
  next->link = data->stack_a;
  data->stack_a = next;
  next = NULL;
  //ft_putstr_fd("sa\n", 1);
}

void  swap_b(t_data *data)
{
  t_list  *next;

  if (node_size(data->stack_b) < 2)
  {
    ft_putstr_fd("stack b is empty or under 2 arg.\n", 1);
    return ;
  }
  next = data->stack_b->link;
  data->stack_b->link = next->link;
  next->link = data->stack_b;
  data->stack_b = next;
  next = NULL;
  //ft_putstr_fd("sb\n", 1);
}


void  swap_ab(t_data *data)
{
  swap_a(data);
  swap_b(data);
  //data->stack_a = swap_a(data->stack_a);
  //data->stack_b = swap_b(data->stack_b);
}

//Hicham is the most sucks programmer i know u better go back to sell slipat f marche
//t_list  *rotate_a(t_list *head)
//{
//  t_list  *next;
//
//  next = head;
//  while (next->link != NULL)
//    next = next->link;
//  next->link = head;
//  next = head->link;
//  head->link = NULL;
//  return (next);
//}

//t_list  *rotate_b(t_list *head)
//{
//  t_list  *next;
//
//  next = head;
//  while (next->link != NULL)
//    next = next->link;
//  next->link = head;
//  next = head->link;
//  head->link = NULL;
//  return (next);
//}

void  rotate_a(t_data *data)
{
  t_list  *next;

  if (node_size(data->stack_a) < 2)
  {
    ft_putstr_fd("Stack a is empty or under 2 arg.\n", 1);
    return ;
  }
  next = data->stack_a;
  while (next->link != NULL)
    next = next->link;
  next->link = data->stack_a;
  data->stack_a = data->stack_a->link;
  next->link->link = NULL;
  next = NULL;
  ft_putstr_fd("ra\n", 1);
}

void  rotate_b(t_data *data)
{
  t_list  *next;

  if (node_size(data->stack_b) < 2)
  {
    ft_putstr_fd("Stack b is empty or under 2 arg.\n", 1);
    return ;
  }
  next = data->stack_b;
  while (next->link != NULL)
    next = next->link;
  next->link = data->stack_b;
  data->stack_b = data->stack_b->link;
  next->link->link = NULL;
  next = NULL;
  ft_putstr_fd("rb\n", 1);
}

void  rotate_ab(t_data *data)
{
  rotate_a(data);
  rotate_b(data);
  //data->stack_a = rotate_a(data->stack_a);
  //data->stack_b = rotate_b(data->stack_b);
}

//Go back to tamazight and arkssa ir3eman ama coding origi winek
//t_list  *reverse_a(t_list *head)
//{
//  t_list  *prev;
//  t_list  *next;
//
//  next = head;
//  while (next->link != NULL)
//  {
//    prev = next;
//    next = next->link;
//  }
//  next->link = head->link;
//  prev->link = head;
//  head->link = NULL;
//  prev = NULL;
//  return (next);
//}

//t_list  *reverse_b(t_list *head)
//{
//  t_list  *prev;
//  t_list  *next;
//
//  next = head;
//  while (next->link != NULL)
//  {
//    prev = next;
//    next = next->link;
//  }
//  next->link = head->link;
//  prev->link = head;
//  head->link = NULL;
//  prev = NULL;
//  return (next);
//}

//Hada smito logic dial zeb a welidi level up or get the fuck out of the way.
//void  reverse_a(t_data *data)
//{
//  t_list  *prev;
//  t_list  *next;
//
//  next = data->stack_a;
//  while (next->link != NULL)
//  {
//    prev = next;
//    next = next->link;
//  }
//  next->link = data->stack_a;
//  data->stack_a = next;
//  prev->link = NULL;
//  //next = data->stack_a;
//  //data->stack_a = next;
//  next = NULL;
//}

//hicham nadi wlkin ba9i 5asou li inikou just a lil bit
void  reverse_a(t_data *data)
{
  t_list  *next;

  if (node_size(data->stack_a) < 2)
  {
    ft_putstr_fd("Stack a is empty or under 2 arg.\n", 1);
    return ;
  }
  next = data->stack_a;
  while (next->link->link != NULL)
    next = next->link;
  next->link->link = data->stack_a;
  data->stack_a = next->link;
  next->link = NULL;
  next = NULL;
  ft_putstr_fd("rra\n", 1);
}

void  reverse_b(t_data *data)
{
  t_list  *next;

  if (node_size(data->stack_b) < 2)
  {
    ft_putstr_fd("Stack b is empty or under 2 arg.\n", 1);
    return ;
  }
  next = data->stack_b;
  while (next->link->link != NULL)
    next = next->link;
  next->link->link = data->stack_b;
  data->stack_b = next->link;
  next->link = NULL;
  next = NULL;
  ft_putstr_fd("rrb\n", 1);
}

void  reverse_ab(t_data *data)
{
  reverse_a(data);
  reverse_b(data);
  //data->stack_a = reverse_a(data->stack_a);
  //data->stack_b = reverse_b(data->stack_b);
}

void  p_b(t_data *data) 
{
  //t_list  *next;

  //data->stack_b = add_to_stacka(data->stack_a, data->stack_a->data);
  //data->stack_b = aadd_to_stackb(data);
  //data->stack_b = add_to_stack2(data->stack_a, data->stack_b);
  add_to_stack_abs(&data->stack_a, &data->stack_b);
  //add_to_stackb(data, 0);
  pop_that_shit(&data->stack_a);
  ft_putstr_fd("pb\n", 1);
  //pop_that_shit(data, 0);
  //data->stack_a = pop_that_shit(stack);
}

void  p_a(t_data *data)
{
  //check if the one of the stack are empty
  //data->stack_a = add_to_stackb(data, 1);
  //data->stack_a = add_to_stack2(data->stack_b, data->stack_a);
  add_to_stack_abs(&data->stack_b, &data->stack_a);
  //add_to_stackb(data, 1);
  pop_that_shit(&data->stack_b);
  ft_putstr_fd("pa\n", 1);
  //pop_that_shit(data, 1);
}

//int main()
//{
//  t_list  *head;
//  t_list  *next;
//  t_list  *last;
//
//  head = malloc(sizeof(t_list));
//  head->data = 10;
//  head->link = NULL;
//
//  next = malloc(sizeof(t_list));
//  next->data = 20;
//  next->link = NULL;
//  head->link = next;
//
//  next = malloc(sizeof(t_list));
//  next->data = 30;
//  next->link = NULL;
//  head->link->link = next;
//
//  last = malloc(sizeof(t_list));
//  last->data = 40;
//  last->link = NULL;
//  next->link = last;
//  //head = swap_a(head);
//  //head = rotate_a(head);
//  head = rotate_a(head);
//  while (head != NULL)
//  {
//    printf("%d\n", head->data);
//    head = head->link;
//  }
//}
