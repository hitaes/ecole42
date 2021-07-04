# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taeskim <taeskim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:29:05 by taeskim           #+#    #+#              #
#    Updated: 2021/06/15 11:02:57 by taeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

NAME = push_swap.a

RM = rm -rf

LIB = ./libft/libft.a

SRCS = \
	validator_num.c \

SRCS_OBJS = ${SRCS:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $? -o $@

${NAME}: ${SRCS_OBJS}
	${MAKE} -C libft
	ar src $@ $?
	${CC} -o push_swap main.c ${NAME} ${LIB}

all : ${NAME}

clean : 
	${RM} ${SRCS_OBJS}
	${MAKE} clean -C libft

fclean : clean
	${RM} ${NAME}
	${MAKE} fclean -C libft

re : clean all

.PHONY = all clean fclean re
