/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:23:35 by hkaddour          #+#    #+#             */
/*   Updated: 2022/06/06 18:37:44 by hkaddour         ###   ########.fr       */
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
	int				data;
	struct s_list	*link;
}	t_list;

typedef struct grab_line
{
	char	*ptr;
	char	*tmp;
	char	*buff;
	char	*line;
}	t_gnl;

typedef struct t_pusha
{
	t_list	*min;
	t_list	*trav_a;
	t_list	*trav_b;
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;
	char	*arg;
	char	**split;
	char	*ptr;
	char	*join;
	char	*input;
	char	*inst;
	char	**sp_inst;
	int		sign_a;
	int		sign_b;
	int		even;
	int		j;
	int		index;
	int		odd;
	int		*tmp;
	int		nbr;
	int		len;
	int		len_b;
	int		*cache;
	int		*seq;
	int		len_seq;
	int		*pos_a;
	int		*pos_b;
	int		s_a;
	int		s_b;
	int		best;
	int		min_index;
	int		*p;
	int		big_i;
	int		down;
	int		best_element;
}	t_data;

t_list	*add_node(t_list *node, int data);
t_list	*find_min(t_list *node);
//void	get_arg(t_data *data, char **av);
void	get_arg(t_data *data, char **av, int ac);
void	swap_a(t_data *data, int check);
void	swap_b(t_data *data, int check);
void	swap_ab(t_data *data, int check);
void	rotate_a(t_data *data, int check);
void	rotate_b(t_data *data, int check);
void	rotate_ab(t_data *data, int check);
void	reverse_a(t_data *data, int check);
void	reverse_b(t_data *data, int check);
void	reverse_ab(t_data *data, int check);
void	p_a(t_data *data, int check);
void	p_b(t_data *data, int check);
int		node_size(t_list *node);
void	add_to_stack(t_list **node, t_list **node2);
void	pop_node(t_list **node);
void	fill_stack_a(t_data *data);
void	fill_node(t_list *head, int data);
void	error(char *str, int check);
void	LSD(t_data *data);
void	find_big_num(t_list *node, t_data *data);
int		node_index(t_list *stack, int index);
int		duplicate_num(t_data *data);
void	check_sorted(t_data *data);
void	sort_small_num(t_data *data);
int		check_smart_rotates(t_data *data);
char	*grab_line(int fd);
void	check_spaces(t_data *data);
void	check_number(t_data *data);
void	lis(t_data *data);
int		find_big_value(t_data *data);
void	be_ones(t_data *data);
void	algorhythm(t_data *data);
void	find_big_num(t_list *node, t_data *data);
void	do_it(t_data *data);
void	check_big(t_data *data, int i);
void	check_up_part_a(t_data *data, int i);
void	check_down_part_a(t_data *data, int i);
void	big_index(t_list *node, t_data *data);
void	odd_b(t_data *data);
int		node_index(t_list *stack, int index);
void	check_even_odd(t_data *data);
void	find_best_element(t_data *data);
void	check_small_top(t_data *data);
void	init_algorhythm(t_data *data);

#endif
