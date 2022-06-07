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

BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPink=\033[1;38;5;205m
BRed=\033[1;31m
BPurple=\033[1;35m

ascii =██████╗ ██╗   ██╗███████╗██╗  ██╗      ███████╗██╗    ██╗ █████╗ ██████╗ \n\
			 ██╔══██╗██║   ██║██╔════╝██║  ██║      ██╔════╝██║    ██║██╔══██╗██╔══██╗\n\
			 ██████╔╝██║   ██║███████╗███████║█████╗███████╗██║ █╗ ██║███████║██████╔╝\n\
			 ██╔═══╝ ██║   ██║╚════██║██╔══██║╚════╝╚════██║██║███╗██║██╔══██║██╔═══╝ \n\
			 ██║     ╚██████╔╝███████║██║  ██║      ███████║╚███╔███╔╝██║  ██║██║     \n\
			 ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝      ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n 
                                                                         

all: $(NAME)

$(LIB):
	@echo ""
	@echo "$(BGreen) $(ascii)"
	@make -C ./libft
	@echo ""
	@echo "$(BGreen)$(LIB) $(BBlue)is done :D"
	@echo ""
	@mv ./libft/libft.a .

$(NAME): $(LIB) $(OBJS)
	@echo ""
	@echo "$(BGreen)merge $(BBlue)$(SRC) $(LIB) $(BYellow)output $(BGreen)$(NAME)"
	@$(CC) $(SRC) $(LIB) -o $(NAME) -g

bonus: $(LIB) $(OBJS_B)
	@echo ""
	@echo "$(BGreen)merge $(BBlue)$(SRC) $(LIB) $(BYellow)output $(BGreen)$(NAME)"
	@$(CC) $(SRC_B) $(LIB) -o $(N_BONUS)

%.o: %.c
	@echo "$(BGreen)compile $(BBlue)$^ $(BYellow)link $(BGreen)$(HEADER)"
	@$(CC) $(FLAGS) -c $^ -I $(HEADER) -g

clean:
	@echo "$(BRed)clean"
	@rm $(LIB)
	@rm -rf *.o

fclean:
	@echo "$(BRed)fclean"
	@rm $(LIB)
	@rm -rf *.dSYM
	@rm -rf *.o $(N_BONUS) $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean bonus re
