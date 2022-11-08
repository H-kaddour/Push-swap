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
LIB = libft/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g
HEADER = include/push.h
SRC = $(addprefix src/, main.c utils.c node.c instruction.c instruction2.c \
			algorhythm.c algorhythm_utils.c algorhythm_helper.c LIS.c LIS_helper.c \
			error.c fill_posa_utils.c smart_rotate.c sort_small.c)

SRC_B = $(addprefix src/, checker.c utils.c node.c instruction.c instruction2.c \
				algorhythm_utils.c error.c gnl.c)

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
                                                                         

all: $(LIB) $(NAME)

$(LIB):
	@echo ""
	@echo "$(BGreen) $(ascii)"
	@make -C ./libft
	@echo ""
	@echo "$(BGreen)$(LIB) $(BBlue)is done :D"

$(NAME): $(OBJS)
	@echo ""
	@echo "$(BGreen)merge $(BBlue)$(OBJS) $(LIB) $(BYellow)output $(BGreen)$(NAME)"
	@$(CC) $(SRC) $(LIB) -g -o $(NAME)

bonus: $(LIB) $(OBJS_B)
	@echo ""
	@echo "$(BGreen)merge $(BBlue)$(OBJS_B) $(LIB) $(BYellow)output $(BGreen)$(B_NAME)"
	@$(CC) $(SRC_B) $(LIB) -g -o $(N_BONUS)

%.o: %.c $(HEADER)
	@echo "$(BGreen)compile $(BBlue)$< $(BYellow) output it $(BBlue)$@ $(BYellow)link $(BGreen)$(HEADER)"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@echo "$(BRed)clean"
	@make clean -C ./libft
	@rm -rf $(OBJS_B) $(OBJS)

fclean:
	@echo "$(BRed)fclean"
	@make fclean -C ./libft
	@rm -rf $(OBJS_B) $(OBJS) $(N_BONUS) $(NAME)
	@rm -rf *.dSYM

re: fclean all

.PHONY: all clean fclean bonus re

#handle INTMAX and INTMIN
#./checker "" 9
#./checker should not print error
#fix this one ./checker 9 and pa in function pop_node segfault
#write error in stderror
