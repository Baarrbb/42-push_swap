# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 16:45:30 by marvin            #+#    #+#              #
#    Updated: 2024/02/23 13:10:47 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC = src
DIR_SRC_BONUS = src_bonus

MAIN_SRC = $(DIR_SRC)/push_swap.c

FILES = $(DIR_SRC)/check_args.c \
	$(DIR_SRC)/lst_manage.c \
	$(DIR_SRC)/push.c \
	$(DIR_SRC)/swap.c \
	$(DIR_SRC)/rotate.c \
	$(DIR_SRC)/rev_rotate.c \
	$(DIR_SRC)/set_stack.c \
	$(DIR_SRC)/get_val_misc.c \
	$(DIR_SRC)/sort.c \
	$(DIR_SRC)/utils.c \
	$(DIR_SRC)/cost_analysis.c \
	$(DIR_SRC)/put_up_node.c \
	$(DIR_SRC)/parsing_args.c 

SRC = $(MAIN_SRC) $(FILES)
SRC_BONUS = $(FILES) \
	$(DIR_SRC_BONUS)/checker.c \
	$(DIR_SRC_BONUS)/get_next_line.c \
	$(DIR_SRC_BONUS)/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a
RM = rm -rf
INC = -I./headers

all : start $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

start :
	make -C libft all

clean :
	make -C libft clean
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re : fclean all

bonus : start $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)
