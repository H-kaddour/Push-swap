/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:19 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/04 12:06:33 by hkaddour         ###   ########.fr       */
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
  if (!ft_strncmp(data->input, "sa", data->len))
    swap_a(data, 0);
  else if (!ft_strncmp(data->input, "sb", data->len))
    swap_b(data, 0);
  else if (!ft_strncmp(data->input, "ss", data->len))
    swap_ab(data, 0);
  else if (!ft_strncmp(data->input, "ra", data->len))
    rotate_a(data, 0);
  else if (!ft_strncmp(data->input, "rb", data->len))
    rotate_b(data, 0);
  else if (!ft_strncmp(data->input, "rr", data->len))
    rotate_ab(data, 0);
  else if (!ft_strncmp(data->input, "rra", data->len))
    reverse_a(data, 0);
  else if (!ft_strncmp(data->input, "rrb", data->len))
    reverse_b(data, 0);
  else if (!ft_strncmp(data->input, "rrr", data->len))
    reverse_ab(data, 0);
  else if (!ft_strncmp(data->input, "pa", data->len))
    p_a(data, 0);
  else if (!ft_strncmp(data->input, "pb", data->len))
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

int check_error(int len, char *input)
{
  //if (!ft_strncmp(input, "sa", len))
  //  return (0);
  if (!ft_strncmp(input, "sa", len) || !ft_strncmp(input, "sb", len) || !ft_strncmp(input, "ss", len))
    return (0);
  else if (!ft_strncmp(input, "ra", len) || !ft_strncmp(input, "rb", len) || !ft_strncmp(input, "rr", len))
    return (0);
  else if (!ft_strncmp(input, "ra", len) || !ft_strncmp(input, "rb", len) || !ft_strncmp(input, "rrr", len))
    return (0);
  else if (!ft_strncmp(input, "pa", len) || !ft_strncmp(input, "pb", len))
    return (0);
  else
    return (1);
}

void  instructions(t_data *data)
{
  int i;
  //int j;

  i = 0;
  if (check_error(data->len, data->input))
  {
    ft_putstr_fd("Error\n", 1);
    exit(127);
  }
  while (data->sp_inst[i])
  {
    //if (check_error(data->len, data->input))
    //{
    //  ft_putstr_fd("Error\n", 1);
    //  exit(127);
    //}
    if (!ft_strncmp(data->input, data->sp_inst[i], data->len))
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
      data.len = ft_strlen(data.input);
      if (!data.len)
        error_push_P("Error\n");
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
    //else here if ac 0
    if (check_sor(&data))
    {
      //t_list  *trav;
      //i = 0;
      //trav = data->stack_a;
      ft_putstr_fd("OK\n", 1);
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
