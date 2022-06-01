/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:58:28 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/01 16:36:08 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void  join_space(t_data *data)
{
  int   i;

  i = 0;
  while (data->arg[i])
    i++;
  data->ptr = malloc(sizeof(char) * i + 2);
  i = 0;
  while (data->arg[i])
  {
    data->ptr[i] = data->arg[i];
    i++;
  }
  data->ptr[i++] = ' ';
  data->ptr[i] = 0;
}
//char  *str_nani(t_data *data)
void  str_nani(t_data *data)
{
	int	  len;
  //char  *ptr;
  int i = 0;
  //int j = 0;

	len = ft_strlen(data->str) + ft_strlen(data->ptr);
	//ptr = malloc(sizeof(char ) * len + 1);
	data->join = malloc(sizeof(char ) * len + 1);
	while (data->str[i])
	{
		*data->join++ = data->str[i];
    i++;
	}
  i = 0;
	while (data->ptr[i])
	{
		*data->join++ = data->ptr[i];
    i++;
	}
	//*data->jwan = '\0';
  //ptr[i] = 0;
  *data->join = 0;
  free(data->str);
  free(data->ptr);
  //data->join = data->join - len;
  data->str = data->join - len;
  //data->str = data->join;
  //free(data->str);
  //free(data->str);
  //*data->jwan = *data->jwan - len;
  //free(data->str);
  //*data->str = *data->jwan;
	//if (str1)
	//free(str1);
  //if (str2)
	//	free(str2);
  //return (ptr);
}

//void	roll_that_join(t_data **data)
//{
//	int		len;
//	//char	*ptr;
//  t_data  *join;
//
//  join = *data;
//	//if (!join->str || !join->ptr)
//	//	return (NULL);
//	len = ft_strlen(join->str) + ft_strlen(join->ptr);
//	join->jwan = malloc(sizeof(char ) * len + 1);
//	//if (ptr == NULL)
//	//	return (NULL);
//	while (*join->str)
//		*join->jwan++ = *join->str++;
//	while (*join->ptr)
//		*join->jwan++ = *join->ptr++;
//	*join->jwan = '\0';
//  join->jwan = join->jwan - len;
//  //join->ptr = join->ptr - 2;
//	//return ((char *) ptr - len);
//}

//char  *roll_that_join(t_data *data)
//{
//	int		len;
//  int   i;
//	//char	*ptr;
//
//	//if (!join->str || !join->ptr)
//	//	return (NULL);
//  i = 0;
//	len = ft_strlen(data->str) + ft_strlen(data->ptr);
//	data->jwan = malloc(sizeof(char ) * len + 1);
//	//data->str = malloc(sizeof(char ) * len + 1);
//	//if (ptr == NULL)
//	//	return (NULL);
//	while (data->str[i])
//  {
//		data->jwan[i] = data->str[i];
//    i++;
//  }
//  //*data->jwan++ = ' ';
//  i = 0;
//	while (data->ptr[i])
//  {
//		data->jwan[i] = data->ptr[i];
//    i++;
//  }
//	data->jwan[i] = '\0';
//  return (data->jwan);
//  //data->jwan = data->jwan - len;
//  //data->str = data->jwan - len;
//  //data->str = data->jwan;
//  //free(data->jwan);
//  //data->ptr = data->ptr - 2;
//	//return ((char *) ptr - len);
//}
//
//void  roll_that_join(t_data *data)
//{
//	int		len;
//  int   i;
//	//char	*ptr;
//
//	//if (!join->str || !join->ptr)
//	//	return (NULL);
//  i = 0;
//	len = ft_strlen(data->str) + ft_strlen(data->ptr);
//	data->jwan = malloc(sizeof(char ) * len + 1);
//	//data->str = malloc(sizeof(char ) * len + 1);
//	//if (ptr == NULL)
//	//	return (NULL);
//	while (data->str[i])
//  {
//		data->jwan[i] = data->str[i];
//    i++;
//  }
//  //*data->jwan++ = ' ';
//  i = 0;
//	while (data->ptr[i])
//  {
//		data->jwan[i] = data->ptr[i];
//    i++;
//  }
//	data->jwan[i] = '\0';
//  //free(data->str);
//  data->str = data->jwan;
//  //data->jwan = data->jwan - len;
//  //data->str = data->jwan - len;
//  //data->str = data->jwan;
//  //free(data->jwan);
//  //data->ptr = data->ptr - 2;
//	//return ((char *) ptr - len);
//}

int duplicate_num(t_data *data)
{
  int i;
  int j;

  i = 0;
  data->len = node_size(data->stack_a);
  while (i < data->len)
  {
    j = i + 1;
    while (j < data->len)
    {
      if (node_index(data->stack_a, i) == node_index(data->stack_a, j))
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}

void  get_arg(t_data *data, char **av)
{
  //t_list  *head;
  //t_list  *next;

  //head = (t_list *) malloc(sizeof(t_list));
  //next = head;
  int i;
  int j;

  j = 1;
  //while (av[j])
  //{

  //}
  while (av[j])
  {
    i = 0;
    //handling if ./push "" | empty arg
    if (av[1][0] == 0)
      error_push_P("arg is empty :/");
    //while (av[1][i])
    //{
    //  if (av[1][i] == ' ')
    //  {
    //    i++;
    //    exit(1);
    //    return ;
    //  }
    //  break ;
    //}
    //while (av[j][i])
    //{
      //if (!data->str)
      //{
      //  data->str = malloc(1);
      //  data->str[0] = 0;
      //}
      //handling other character like alphabet other
      //if (!ft_isdigit(av[j][i]))
      //  error_push_P("The arg has ur sister on :D");
      //data->arg = av[j];
      //data->str = av[j];
      //roll_that_join(data);
      //data->tmp = join_space(data);
      //join_space(data);
      //i++;
    //}
    data->arg = av[j];
    join_space(data);
    //data->str = ft_strjoin(data->str, data->ptr);
    //roll_that_join(data);
    str_nani(data);
    //data->str = data->join;
    //data->str = str_nani(data->str, data->ptr);
    //join_space(data);
    //if (av[j][0] == ' ')
    //  error_push_P("La la mabghitch :/");
    //data->str = ft_strjoin(data->str, data->ptr);
    //roll_that_join(&data);
    //if (j != 0)
    //  free(data->jwan);
    //data->str = roll_that_join(data);
    //roll_that_join(data);
    //data->str = data->jwan;
    //printf("%s", data->jwan);
    //printf("%s", data->str);
    //free(data->ptr);
    //free(data->str);
    //free(data->jwan);
    j++;
  }
  //free(data->str);
  //data->str = data->jwan; printf("%s", data->str);
  //printf("%s", data->str);
  //while (1);
  //data->str = data->jwan;
  ////while (1);
  i = 0;
  if (data->str[i] == ' ')
  {
    while (data->str[++i])
    {
     // if (data->str[i] == ' ')
     //   i++;
      if (data->str[i] != ' ')
        break ;
      //if (data->str[i] == '\0')
      //  error_push_P("arg empty only spaces");
      i++;
    }
    if (data->str[i] == '\0')
      error_push_P("arg empty only spaces");
  }
  //if (data->str[i] == ' ')
  //  error_push_P("empty arg only space :/");
  data->split = ft_split(data->str, ' ');
  i = 0;
  while (data->split[i])
  {
    j = 0;
    while (data->split[i][j])
    {
      if (!ft_isdigit(data->split[i][j]))
        error_push_P("those are not number :/");
      j++;
    }
    //if (ft_atoi(data->split[i]) == 0)
    //  error_push_P("INT MAX");
    i++;
  }

  //i = 0;
  //while (data->split[i])
  //{
  //  printf("%s\n", data->split[i]);
  //  i++;
  //}
  //while (1);
  //i = 0;
  //head->data = ft_atoi(data->split[i++]);
  //head->link = NULL;
  //head = add_node(head, ft_atoi(data->split[i++]));
  fill_stack_node(data);
  //while (data->split[i++])
  //  free(data->split[i]);
  //free(data->split);
  //t_list  *zabazibo;
  //zabazibo = data->stack_a;
  //while (zabazibo != NULL)
  //{
  //  printf("%d\n", zabazibo->data);
  //  zabazibo = zabazibo->link;
  //}
  //while (1);
  //fill_node(head, ft_atoi(data->split[i++]));
  //while (data->split[i])
  //{
  //  data->nbr = ft_atoi(data->split[i]);
  //  //ptr = add_node(ptr, data->nbr);
  //  head = add_to_stacka(head, data->nbr);
  //  //printf("%d\n", data->nbr);
  //  i++;
  //}
  //data->stack_a = head;
  //p_b(data);
  ///p_b(data);
  ///p_b(data);
  ///p_b(data);
  ///p_b(data);
  ///p_b(data);
  ///p_b(data);
  //fix if p_b or p_a is not the right num segmentation fault
  //while (data->stack_a != NULL && data->stack_b != NULL)
  //{
  //  printf("| %d |       | %d |\n", data->stack_a->data, data->stack_b->data);
  //  data->stack_a = data->stack_a->link;
  //  data->stack_b = data->stack_b->link;
  //}
  //printf("------       ------\n");
  //printf("stack a      stack b");

  ///p_a(data);
  ///p_a(data);
  ///p_a(data);
  //while (1);
  //p_a(data);
  //p_a(data);
  //while (1);
  //reverse_a(data);
  //reverse_b(data);

  //reverse_ab(data);
  //rotate_a(data);
  //rotate_b(data);
  //rotate_ab(data);

  //data->stack_a = swap_a(data->stack_a);
  //data->stack_b = swap_b(data->stack_b);
  //swap_ab(data);
  //swap_ab(data);
  //swap_a(data);
  //swap_b(data);
  //swap_ab(data);
  //data->stack_a = rotate_a(data->stack_a);
  //rotate_ab(data);
  //data->stack_b = rotate_b(data->stack_b);
  //FIX SWAP_A AND B and other fucntion to not return the pointer just in the struct
  //swap_a(data->stack_a);
  //swap_ab(data);
  //rotate_ab(data);
  //reverse_ab(data);

  //i = 0;
  //while (i < 6)
  //{
  //  //p_b(data);
  //  p_a(data);
  //  printf("%d\n", data->stack_a->data);
  //  i++;
  //}

  //t_list  *trav_b;
  //trav_b = data->stack_b;
  //printf("stack B:\n");
  //while (trav_b != NULL)
  //{
  //  printf("| %d |\n", trav_b->data);
  //  trav_b = trav_b->link;
  //}
  //printf("----------\n");
  //////data->stack_a = swap_a(data->stack_a);
  //////p_a(data);
  //////p_a(data);
  //////p_a(data);
  //t_list  *trav_a;
  //trav_a = data->stack_a;
  //printf("stack A:\n");
  //while (trav_a != NULL)
  //{
  //  printf("| %d |\n", trav_a->data);
  //  trav_a = trav_a->link;
  //}


  //while(1);
  //printf("%d", data->stack_a->data);
  //next = data->stack_a;
  //while (next != NULL)
  //{
  //  printf("%d\n", next->data);
  //  next = next->link;
  //}
  //printf("***%d", head->data);
  //ft_atoi(ft_split(data->str, ' '));
  //printf("%s", data->str);
}
//pseudo code:
//now stacka is pointing at the top node 
//
//error handling for arg:
//1 a 8 7 b     = done
//+ 1 3 !       = done
//"5 5 7" 5 7 8
//"a 6 75 43"   = done
//""
//" "
//1 2 3 2 5
//"0 1 3 5" 5 6
//"0 1 3 5"5 6
