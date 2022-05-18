/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:52:21 by hkaddour          #+#    #+#             */
/*   Updated: 2022/05/02 17:52:28 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//count a linked list
//void  count_list(t_data *ptr)
//{
//  int i = 0;
//  while (ptr != NULL)
//  {
//    i++;
//    ptr = ptr->link;
//  }
//  printf("%d", i);
//}

//add a node at the end
//void  add_node_end(t_data *head)
//{
//  t_data  *ptr;
//  //t_data  *tmp;
//
//  //tmp = head;
//  ptr = (t_data *)malloc(sizeof(t_data));
//  ptr->data = 52;
//  ptr->link = NULL;
//  while (head->link != NULL)
//    head = head->link;
//  head->link = ptr;
//}

//allocate two or more node;
//int main()
//{
//  t_data  *head;
//  
//  head = (t_data *)malloc(sizeof(t_data));
//  head->data = 65;
//  head->link = NULL;
//  //printf("%d\n", head->data);
//
//  t_data  *next;
//  next = (t_data *)malloc(sizeof(t_data));
//  next->data = 88;
//  next->link = NULL;
//  head->link = next; //printf("%d\n", next->data);
//  next = (t_data *)malloc(sizeof(t_data));
//  next->data = 988;
//  next->link = NULL;
//  head->link->link = next;
//  //printf("%d", next->data);
//  //count_list(head);
//  add_node_end(head);
//  //t_data  *ok;
//  //ok = head;
//  while (head->link != NULL)
//  {
//    printf("%d\n", head->data);
//    head = head->link;
//  }
//  printf("%d", head->data);
// return (0); 
//}


//deleting the end node and free
//void  free_end_node(t_data *head)
//{
//  t_data  *last, *prev;
//
//  if (!head)
//    perror("head is empty");
//  if (!head->link)
//  {
//    free(head);
//    perror("head->link is pointing on NULL");
//  }
//  last = head;
//  while (last->link != NULL)
//  {
//    prev = last;
//    last = last->link;
//  }
//  free(last);
//  last = NULL;
//  prev->link = NULL;
//}
//delete last node with one pointer
//void  free_end_node_one_pointer(t_data *head)
//{
//  t_data  *prev;
//
//  prev = head;
//  while (prev->link->link != NULL)
//    prev = prev->link;
//  free(prev->link);
//  prev->link = NULL;
//}

//delete node in a position
//void  free_node_position(t_data *head, int pos)
//{
//  t_data  *next, *prev;
//
//  next = head;
//  while (pos > 1)
//  {
//    prev = next;
//    next = next->link;
//    pos--;
//  }
//  prev->link = next->link;
//  free(next);
//  next = NULL;
//}

//deleting the entire nodes free all
//t_data  *free_all(t_data *head)
//{
//  t_data  *tmp;
//
//  tmp = head;
//  while (tmp != NULL)
//  {
//    tmp = tmp->link;
//    free(head);
//    head = tmp;
//  }
//  return (head);
//}

//reverce the linked list
t_data  *reverce_node(t_data *head)
{
  t_data  *prev, *next;

  prev = NULL;
  next = NULL;
  while (head != NULL)
  {
    next = head->link;
    head->link = prev;
    prev = head;
    head = next;
  }
  head = prev;
  prev = NULL;
  return (head);
}

int main()
{
  t_data  *head;

  head = malloc(sizeof(t_data));
  head->data = 96;
  head->link = NULL;

  t_data  *next;
  next = malloc(sizeof(t_data));
  next->data = 922;
  next->link = NULL;
  head->link = next;

  next = malloc(sizeof(t_data));
  next->data = 39;
  next->link = NULL;
  head->link->link = next;

  t_data  *ll;
  ll = malloc(sizeof(t_data));
  ll->data = 22;
  ll->link = NULL;
  next->link = ll;
  //free_end_node(head);
  //free_end_node_one_pointer(head);
  //free_node_position(head, 4);
  //head = free_all(head);
  //if (head == NULL)
  //  printf("done");
  head = reverce_node(head);
  while (head != NULL)
  {
    printf("%d\n", head->data);
    head = head->link;
  }
  return (0);
}


//deleting a node free
//t_data  *free_node(t_data *head)
//{
//  t_data  *tmp;
//
//  tmp = head;
//  head = head->link;
//  free(tmp);
//  tmp = NULL;
//  return (head);
//}
//
//int main()
//{
//  t_data  *head;
//
//  head = (t_data *) malloc(sizeof(t_data));
//  head->data = 898;
//  head->link = NULL;
//  
//  t_data  *next;
//  next = (t_data *) malloc(sizeof(t_data));
//  next->data = 55;
//  next->link = NULL;
//  head->link = next;
//  head = free_node(head);
//  while (head != NULL)
//  {
//    printf("%d", head->data);
//    head = head->link;
//  }
//}


//add node in between more node
//void  add_node_between(t_data *head)
//{
//  t_data  *btw, *ptr;
//  int i = 0;
//  btw = (t_data *)malloc(sizeof(t_data));
//  btw->data = 73;
//  btw->link = NULL;
//  btw->link = head->link->link;
//  ptr = head;
//  while (i < 1)
//  {
//    ptr = ptr->link;
//    i++;
//  }
//  ptr->link = btw;
//}
//
//int main()
//{
//  t_data  *head;
//  head = (t_data *) malloc(sizeof(t_data));
//  head->data = 53;
//  head->link = NULL;
//
//  t_data  *next;
//  next = (t_data *) malloc(sizeof(t_data));
//  next->data = 89;
//  next->link = NULL;
//  head->link = next;
//
//  next = (t_data *) malloc(sizeof(t_data));
//  next->data = 33;
//  next->link = NULL;
//  head->link->link = next;
//  add_node_between(head);
//  while (head != NULL)
//  {
//    printf("%d\n", head->data);
//    head = head->link;
//  }
//}


//add node in between in two node
//void  add_node_inbetween(t_data *head)
//{
//  t_data  *between;
//
//  between = (t_data *) malloc(sizeof(t_data));
//  between->data = 99;
//  between->link = NULL;
//  head->link = between;
//}
//
//int main()
//{
//  t_data  *head;
//
//  head = (t_data *) malloc(sizeof(t_data));
//  head->data = 88;
//  head->link = NULL;
//
//  t_data  *next;
//  next = (t_data *) malloc(sizeof(t_data));
//  next->data = 34;
//  next->link = NULL;
//
//  add_node_inbetween(head);
//  head->link->link = next;
//  while (head != NULL)
//  {
//    printf("%d\n", head->data);
//    head = head->link;
//  }
//}


//add a node at first
//int main()
//{
//  t_data  *head;
//  t_data  *next;
//
//  head = (t_data *)malloc(sizeof(t_data));
//  head->data = 55;
//  head->link = NULL;
//
//  next = (t_data *) malloc(sizeof(t_data));
//  next->data = 88;
//  //next->link = NULL;
//  next->link = head;
//  head = next;
//  while (head != NULL)
//  {
//    printf("%d\n", head->data);
//    head = head->link;
//  }
//}

//add node at the end with O(1) time complecity no while
//t_data *add_node_ennd(t_data *node, int data)
//{
//  t_data  *ptr;
//
//  ptr = (t_data *) malloc(sizeof(t_data));
//  ptr->data = data;
//  ptr->link = NULL;
//  node->link = ptr;
//  return (ptr);
//}
//
//int main()
//{
//  t_data  *head;
//  t_data  *ptr;
//
//  head = (t_data *) malloc(sizeof(t_data));
//  ptr = head;
//
//  ptr = add_node_ennd(ptr, 10);
//  ptr = add_node_ennd(ptr, 20);
//  ptr = add_node_ennd(ptr, 30);
//  ptr = add_node_ennd(ptr, 40);
//
//  ptr = head;
//  while (ptr != NULL)
//  {
//    printf("%d\n", ptr->data);
//    ptr = ptr->link;
//  }
//  //printf("%d", ptr->data);
//
//  return (0);
//}

//allocate one node;
//int main()
//{
//  t_data  *head = NULL;
//  head = (t_data *) malloc(sizeof(t_data));
//  head->data = 55;
//  head->link = NULL;
//  printf("%d", head->data);
//  return (0);
//}
//
//pseudo code of push swap:
//first make a satac a and b
//read the argv and split it and turn it to int with atoi and  put it in a stack a
//make function ra rb ...
//make fufction that add in stack and delete and linked list too.
//start making an algorythm.
