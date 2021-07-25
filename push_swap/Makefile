# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:29:05 by taeskim           #+#    #+#              #
#    Updated: 2021/07/24 00:26:14 by pac-man          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

NAME = push_swap.a

RM = rm -rf

LIB = ./libft/libft.a

SRCS = \
	./node_setter/node_setter.c \
	./utils/ft_clean.c \
	./utils/ft_get_count.c \
	./parser/parser_input.c \
	./validators/validator.c \
	./validators/validator_sign.c \
	./validators/validator_num.c \
	./validators/validator_int.c \
	./validators/validator_duplicate.c \
	./validators/validator_sorting.c \

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
