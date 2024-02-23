# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:04:31 by marvin            #+#    #+#              #
#    Updated: 2024/02/23 13:10:55 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_printf/ft_printf.c ft_printf/print_num.c ft_printf/utils.c \
	ft_memset.c ft_putstr_fd.c ft_calloc.c ft_bzero.c ft_split.c \
	ft_strdup.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I../headers

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} $(INC) -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
