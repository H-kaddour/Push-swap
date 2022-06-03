/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:19 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/03 19:55:45 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//int cmp(char *s1, char *s2)
//{
//  int i;
//
//  i = 0;
//  while (s1[i] == s2[i] && s1[i])
//    i++;
//  return (s1[i] - s2[i]);
//}

int check_sor(t_data *data)
{
  int i;

  i = 0;
  data->len = node_size(data->stack_a) - 1;
  while (i < data->len)
  {
    if (node_index(data->stack_a, i) < node_index(data->stack_a, i + 1))
    {
      if (i == data->len - 1)
        return (1);
      i++;
    }
    else
      break ;
    //else
    //  return (0);
    //  break ;
    //if (i == data->len - 1)
    //  return (0);
    //i++;
  }
  return (0);
    //error_push_P("those number are sorted");
}

//void  sort(t_data *data, char *sp_ins)
void  sort(t_data *data)
{
  if (!ft_strncmp(data->input, "sa", 2))
    swap_a(data, 0);
  else if (!ft_strncmp(data->input, "sb", 2))
    swap_b(data, 0);
  else if (!ft_strncmp(data->input, "ss", 2))
    swap_ab(data, 0);
  else if (!ft_strncmp(data->input, "ra", 2))
    rotate_a(data, 0);
  else if (!ft_strncmp(data->input, "rb", 2))
    rotate_b(data, 0);
  else if (!ft_strncmp(data->input, "rr", 2))
    rotate_ab(data, 0);
  else if (!ft_strncmp(data->input, "rra", 2))
    reverse_a(data, 0);
  else if (!ft_strncmp(data->input, "rrb", 2))
    reverse_b(data, 0);
  else if (!ft_strncmp(data->input, "rrr", 2))
    reverse_ab(data, 0);
  else if (!ft_strncmp(data->input, "pa", 2))
    p_a(data, 0);
  else if (!ft_strncmp(data->input, "pb", 2))
    p_b(data, 0);
  
  //if (!cmp(sp_ins, "sa"))
  //  swap_a(data, 0);
  //else if (!cmp(sp_ins, "sb"))
  //  swap_b(data, 0);
  //else if (!cmp(sp_ins, "ss"))
  //  swap_ab(data, 0);
  //else if (!cmp(sp_ins, "ra"))
  //  rotate_a(data, 0);
  //else if (!cmp(sp_ins, "rb"))
  //  rotate_b(data, 0);
  //else if (!cmp(sp_ins, "rr"))
  //  rotate_ab(data, 0);
  //else if (!cmp(sp_ins, "rra"))
  //  reverse_a(data, 0);
  //else if (!cmp(sp_ins, "rrb"))
  //  reverse_b(data, 0);
  //else if (!cmp(sp_ins, "rrr"))
  //  reverse_ab(data, 0);
  //else if (!cmp(sp_ins, "pa"))
  //  p_a(data, 0);
  //else if (!cmp(sp_ins, "pb"))
  //  p_b(data, 0);

  //else
  //{
  //  ft_putstr_fd("Error", 0);
  //  exit(0);
  //}
}

//int check_error(t_data *data)
//{
//  int i;
//  int j;
//
//  i = 0;
//  while (data->split[i])
//  {
//    j = 0;
//    while (data->split[j])
//    {
//      if (ft_strncmp(data->split[i], data->split[j], 2))
//        j++;
//      else
//        break ;
//    }
//    i++;
//  }
//  return (0);
//}

int check_error(char *input)
{
  if (!ft_strncmp(input, "sa", 2))
    return (0);
  //if (!ft_strncmp(input, "sa", 2) || !ft_strncmp(input, "sb", 2) || !ft_strncmp(input, "ss", 2))
  //  return (0);
  else if (!ft_strncmp(input, "ra", 2) || !ft_strncmp(input, "rb", 2) || !ft_strncmp(input, "rr", 2))
    return (0);
  else if (!ft_strncmp(input, "ra", 2) || !ft_strncmp(input, "rb", 2) || !ft_strncmp(input, "rrr", 2))
    return (0);
  else if (!ft_strncmp(input, "pa", 2) || !ft_strncmp(input, "pb", 2))
    return (0);
  else
    return (1);
}

void  instructions(t_data *data)
{
  int i;
  //int j;

  i = 0;
  while (data->sp_inst[i])
  {
    if (check_error(data->input))
    {
      ft_putstr_fd("Error\n", 1);
      exit(127);
    }
    if (!ft_strncmp(data->input, data->sp_inst[i], 2))
      sort(data);
    i++;
  }
  //while (data->split[i])
  //{
  //  if (check_error(data->split[i]))
  //  {
  //    ft_putstr_fd("Error\n", 1);
  //    exit(127);
  //  }
  //  j = 0;
  //  while (data->sp_inst[j])
  //  {
  //    //if (ft_strncmp(data->split[i], data->split[j], 2))
  //    //check_error(data);
  //    //if (!cmp(data->split[i], data->sp_inst[j]))
  //    if (!ft_strncmp(data->split[i], data->sp_inst[j], 2))
  //    {
  //      sort(data, data->sp_inst[j]);
  //      //ft_putstr_fd("ok\n", 0);
  //      break ;
  //    }
  //    //else
  //    //{
  //    //  break ;
  //    //  ft_putstr_fd("Error\n", 1);
  //    //  exit(127);
  //    //}

  //    //if (data->sp_inst[j] == NULL)
  //    //  ft_putstr_fd("no\n", 0);
  //    //else
  //    //{
  //    //  ft_putstr_fd("no\n", 0);
  //    //  break ;
  //    //}
  //    j++;
  //  }
  //  //if ()
  //  i++;
  //}
}

int main(int ac, char **av)
{
  t_data  data;
  t_list  *trav_a;
  int i;

  i = 0;
  data.inst = "sa sb ss ra rb rr rra rrb rrr pa pb";
  data.sp_inst = ft_split(data.inst, ' ');
  //while (data.sp_inst[i])
  //{
  //  printf("%s\n", data.sp_inst[i]);
  //  i++;
  //}
  data.stack_a = NULL;
  data.stack_b = NULL;
  if (ac > 1)
  {
    data.str = ft_strdup("");
    get_arg(&data, av);
    trav_a = data.stack_a;
    while (1)
    {
      data.input = grab_line(0);
      if (!data.input)
        break ;
      //data.split = ft_split(data.input, ' ');
      //here check error of input
      instructions(&data);
      //while (data.input[i])
      //{
      //  write(1, &data.input[i], 1);
      //  i++;
      //}
      //i = 0;
    }
    if (check_sor(&data))
    {
      //t_list  *trav;
      //i = 0;
      //trav = data->stack_a;
      ft_putstr_fd("OK\n", 2);
      exit(127);
      //while (trav)
      //{
      //  trav = trav->link;
      //  i++;
      //}
      //data->len = i;
      //i = 0;
      //trav = data->stack_a;
      //while (i < data->len)
      //{
      //  ft_putchar_fd(trav->data, 0);
      //  ft_putchar_fd('\n', 0);
      //  trav = trav->link;
      //}
    }
    else
    {
      ft_putstr_fd("KO\n", 1);
      exit(127);
    }
    //while (trav_a)
    //{
    //  printf("%d\n", trav_a->data);
    //  trav_a = trav_a->link;
    //}
  }
}
