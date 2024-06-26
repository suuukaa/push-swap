# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 14:39:13 by sel-bouy          #+#    #+#              #
#    Updated: 2024/06/13 11:13:45 by sel-bouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
INC = lib_push.h lib_push_bonus.h get_next_line.h

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC =  push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c \
	   push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c push_swap_utils7.c \
	   push_swap_utils8.c push_swap_algo.c push_swap_algo2.c

SRC_BONUS = ./bonus/push_swap_bonus.c ./bonus/push_swap_utils.c ./bonus/push_swap_utils2.c \
            ./bonus/push_swap_utils3.c ./bonus/push_swap_utils4.c ./bonus/push_swap_utils5.c \
			./bonus/push_swap_utils6.c ./bonus/push_swap_utils7.c ./bonus/push_swap_utils8.c \
			./bonus/push_swap_algo.c ./bonus/push_swap_algo2.c ./bonus/checker_push_swap.c \
			./bonus/get_next_line.c ./bonus/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:$(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	
fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	
re: fclean all