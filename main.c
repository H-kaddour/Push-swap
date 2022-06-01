/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:51:39 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/01 11:27:22 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//char  *join_space(char *str)
//{
//  int   i;
//  char  *ptr;
//
//  i = 0;
//  while (str[i])
//    i++;
//  ptr = malloc(sizeof(char) * i + 2);
//  i = 0;
//  while (str[i])
//  {
//    ptr[i] = str[i];
//    i++;
//  }
//  ptr[i++] = ' ';
//  ptr[i] = 0;
//  return (ptr);
//}

//int main(int ac, char **av)
//{
//  int   i;
//  int   j;
//  char  *str;
//  char  *arg;
//  char  *tmp;
//
//  j = 1;
//  while (av[j])
//  {
//    i = 0;
//    while (av[j][i])
//    {
//      if (!str)
//      {
//        str = malloc(1);
//        str[0] = 0;
//      }
//      arg = av[j];
//      tmp = join_space(arg);
//      i++;
//    }
//    str = ft_strjoin(str, tmp);
//    j++;
//  }
//  //printf("%s", str);
//  return (0);
//}

int main(int ac, char **av)
{
  t_data  data;
  //t_list *bigg;

  if (ac == 1)
    error_push_P("Enter the arg :v\nUsage: [push] number :D");
  data.stack_a = NULL;
  data.stack_b = NULL;
  //data.str = malloc(1);
  //data.str[0] = 0;
  data.str = ft_strdup("");
  get_arg(&data, av);
  algorhythm(&data);
  //bigg = data.stack_a;
  //find_big_num(bigg, &data);
  //p_b(&data);

  //int i = 0;
  //printf("tmp\n");
  //while (i < data.len)
  //{
  //  printf("%d ", data.tmp[i]);
  //  i++;
  //}
  //printf("\n------------\n");

  //LSD(&data);
  //while (1);

  //p_b(&data);
  //p_b(&data);
  //print_youness_ass(&data);
  LSD(&data);

  //t_list  *trav_b;
  //trav_b = data.stack_b;
  //printf("\nstack B:\n");
  //while (trav_b != NULL)
  //{
  //  printf("| %d |\n", trav_b->data);
  //  trav_b = trav_b->link;
  //}
  //printf("----------\n");

  //rotate_a(&data);
  //rotate_a(&data);
  //reverse_a(&data);

  //t_list  *trav_a;
  //trav_a = data.stack_a;
  //printf("stack A:\n");
  //while (trav_a != NULL)
  //{
  //  printf("| %d |\n", trav_a->data);
  //  trav_a = trav_a->link;
  //}

  //while (1);

  //printf("%d", data.stack_a->data);
  //fill_stack(&data);
  //while (1);
  //while (data.split[i] != NULL)
  //{
  //  printf("%s\n", data.split[i]);
  //  i++;
  //}
  //printf("%s", data.str);
}


//tmp = tt;
//sep = lis2;
//cache = ll;
