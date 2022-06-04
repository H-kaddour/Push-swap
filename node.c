/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:47:29 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/04 12:16:12 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//make a node
//void  fill_node(t_list *head, int data)
t_list  *fill_node(t_list *head, int data)
{
  head->data = data;
  head->link = NULL;
  return (head);
}

void  fill_no(t_list *head, int data)
{
  head->data = data;
  head->link = NULL;

  //t_list  *node;
  //node = *head;
  //node->data = data;
  //node->link = NULL;
}

void  fill_stack_node(t_data *data)
{
  int i;
  t_list  *head;
  t_list  *next;

  i = 0;
  head = malloc(sizeof(t_list));
  fill_no(head, ft_atoi(data->split[i++]));
  //printf("%d", head->data);
  data->stack_a = head;
  while (data->split[i])
  {
    next = malloc(sizeof(t_list));
    next->data = ft_atoi(data->split[i]);
    next->link = NULL;
    head->link = next;
    head = next;
    //head->link = next;
    //next->link = data->stack_a;
    //data->stack_a = next;
    i++;
  }
  next = NULL;
  if (duplicate_num(data))
    error_push_P("duplicate number :/");
  //t_list  *trav;
  //trav = data->stack_a;
  //while (trav)
  //{
  //  printf("%d\n", trav->data);
  //  trav = trav->link;
  //}
}

//void  fill_stack_node(t_data *data)
//{
//  int i;
//  t_list  *head;
//  t_list  *next;
//
//  i = 0;
//  head = malloc(sizeof(t_list));
//  data->stack_a = fill_node(head, ft_atoi(data->split[i++]));
//  while (data->split[i])
//  {
//    next = malloc(sizeof(t_list));
//    next->data = ft_atoi(data->split[i]);
//    next->link = NULL;
//    next->link = data->stack_a;
//    data->stack_a = next;
//    i++;
//  }
//  next = NULL;
//}

//allocate a new node and fill it
//t_list  *node(t_list *head, int data)
//{
//  t_list  *node;
//
//  node = malloc(sizeof(t_list));
//  node->data = data;
//  node->link = NULL;
//  return (node);
//}

//add node at the end with O(1) time complex
t_list  *add_node(t_list *head, int data)
{
  t_list  *next;

  next = (t_list *) malloc(sizeof(t_list));
  next->data = data;
  next->link = NULL;
  head->link = next;
  return (next);
}

//add node at the begining for stack A
t_list  *add_to_stacka(t_list *head, int data)
{
  t_list  *next;

  next = (t_list *) malloc(sizeof(t_list));
  next->data = data;
  next->link = NULL;
  next->link = head;
  head = next;
  next = NULL;
  return (head);
}

int node_size(t_list  *node)
{
  t_list  *next;
  int i;

  i = 0;
  next = node;
  while (next != NULL)
  {
    i++;
    next = next->link;
  }
  return (i);
}

void  error_push_P(char *str)
{
  ft_putstr_fd(str, 1);
  exit(128);
  //maybe i need to free in here the node i allocate.
}

void  add_to_stack_abs(t_list **node, t_list **nudes)
{
  t_list  *head;
  t_list  *ptr;

  if (node_size(*node) == 0)
    return ;
    //error_push_P("stack is empty!\n");
  head = malloc(sizeof(t_list));
  ptr = *node;
  head->data = ptr->data;
  head->link = NULL;
  head->link = *nudes;
  *nudes = head;
}

//logic ta3 likhaso li7wih baghi li3dbo mzn wlkin mabghitch return just struct saving
//t_list  *add_to_stack2(t_list *s_a, t_list *s_b)
//{
//  t_list  *head;
//
//  if (node_size(s_a) == 0)
//    error_push_P("stack is empty or less than 2 arg!\n");
//  head = malloc(sizeof(t_list));
//  head->data = s_a->data;
//  head->link = NULL;
//  head->link = s_b;
//  s_b = head;
//  return (head);
//}

//Logic dial chi 9e7ba ma5lessehach pimp dialha :/
//void  add_to_stackb(t_data *data, int check)
//{
//  t_list  *head;
//  t_list  *s_a;
//  t_list  *s_b;
//
//  head = malloc(sizeof(t_list));
//  if (check == 0)
//  {
//    s_a = data->stack_a;
//    s_b = data->stack_b;
//  }
//  if (check == 1)
//  {
//    s_a = data->stack_b;
//    s_b = data->stack_a;
//  }
//  head->data = s_a->data;
//  head->link = NULL;
//  head->link = s_b;
//  s_b = head;
//  if (check == 0)
//    data->stack_b = s_b;
//  if (check == 1)
//    data->stack_a = s_b;
//  //if (check == 0)
//  //{ //stack b
//  //  if (node_size(data->stack_a) == 0)
//  //  {
//  //    ft_putstr_fd("Stack a is empty son of a bitch!", 1);
//  //    exit(128);
//  //  }
//  //  head->data = data->stack_a->data;
//  //  head->link = NULL;
//  //  head->link = data->stack_b;
//  //  data->stack_b = head;
//  //}
//  //if (check == 1)
//  //{ //stack a
//  //  if (node_size(data->stack_b) == 0)
//  //  {
//  //    ft_putstr_fd("Stack a is empty son of b bitch!", 1);
//  //    exit(128);
//  //  }
//  //  head->data = data->stack_b->data;
//  //  head->link = NULL;
//  //  head->link = data->stack_a;
//  //  data->stack_a = head;
//  //}
//  //data->stack_b = data->stack_a;
//  //data->stack_b->link = NULL;
//  //return (head);
//}

//void  pop_that_shit(t_data *data, int check)
void  pop_that_shit(t_list **node)
{
  t_list  *next;

  next = *node;
  *node = next->link;
  free(next);
  //logic min orakdtawi lottery
  //if (check == 0)
  //{ //stack b
  //  next = data->stack_a;
  //  data->stack_a = data->stack_a->link;
  //}
  //if (check == 1)
  //{//stack a
  //  next = data->stack_b;
  //  data->stack_b = data->stack_b->link;
  //}
  //free(next);
}
