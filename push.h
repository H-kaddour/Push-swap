/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:23:35 by hkaddour          #+#    #+#             */
/*   Updated: 2022/05/17 14:16:27 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
  int data;
  struct s_list *link;
} t_list;

typedef struct t_pusha
{
  char    *str;
  char    *arg;
  char    *tmp;
  char    **split;
  char    *ptr;
  int     nbr;
  char    *jwan;
  char    *join;
  int     len;
  int     *cache;
  int     *seq;
  int     len_seq;
  t_list  *stack_a;
  t_list  *stack_b;
} t_data;

void    get_arg(t_data *data, char **av);
t_list  *add_node(t_list *node, int data);
t_list  *add_to_stacka(t_list *node, int data);
//void    fill_node(t_list *head, int data);
void    swap_a(t_data *data);
void    swap_b(t_data *data);
void    swap_ab(t_data *data);
//t_list  *swap_a(t_list *head);
//t_list  *swap_b(t_list *head);
//t_list  *rotate_a(t_list *head);
//t_list  *rotate_b(t_list *head);
void    rotate_a(t_data *data);
void    rotate_b(t_data *data);
void    rotate_ab(t_data *data);
void    reverse_a(t_data *data);
void    reverse_b(t_data *data);
void    reverse_ab(t_data *data);
//t_list  *reverse_a(t_list *head);
//t_list  *reverse_b(t_list *head);
void    p_a(t_data *data);
void    p_b(t_data *data);
void    add_to_stackb(t_data *data, int check);
t_list  *add_to_stack2(t_list *s_a, t_list *s_b);
int     node_size(t_list  *node);
//t_list  *add_to_stackb(t_data *data, int check);
//void    pop_that_shit(t_data *data, int check);
void    pop_that_shit(t_list **node);
void    add_to_stack_abs(t_list **node, t_list **nudes);
void    fill_stack_node(t_data *data);
t_list  *fill_node(t_list *head, int data);
void    error_push_P(char *str);
void    algorhythm(t_data *data);

#endif