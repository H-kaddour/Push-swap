# ************************************************************************** # 
#                                                                            # 
#                                                        :::      ::::::::   # 
#   Makefile.c                                         :+:      :+:    :+:   # 
#                                                    +:+ +:+         +:+     # 
#   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        # 
#                                                +#+#+#+#+#+   +#+           # 
#   Created: 2022/05/03 13:51:39 by hkaddour          #+#    #+#             # 
#   Updated: 2022/06/05 20:09:42 by hkaddour         ###   ########.fr       # 
#                                                                            # 
# ************************************************************************** # 

NAME = push_swap
N_BONUS = checker
LIB = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = push.h
SRC = main.c \
			utils.c \
			node.c \
			instruction.c \
			instruction2.c \
			algorhythm.c \
			algorhythm_utils.c \
			algorhythm_helper.c \
			LIS.c \
			LIS_helper.c \
			error.c \
			fill_posa_utils.c \
			smart_rotate.c \
			sort_small.c 

SRC_B = checker.c \
						utils.c \
						node.c \
						instruction.c \
						instruction2.c \
						algorhythm_utils.c \
						error.c \
						gnl.c

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(SRC) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $(SRC)

$(LIB):
	@make -C ./../libft
	@mv ./../libft/libft.a .

fclean:
	@rm $(LIB)
	@make fclean -C ./../libft

.PHONY: all clean fclean bonus re
