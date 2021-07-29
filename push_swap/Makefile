# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:29:05 by taeskim           #+#    #+#              #
#    Updated: 2021/07/28 18:00:55 by pac-man          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

NAME = push_swap.a

RM = rm -rf

LIB = ./libft/libft.a

SRCS = \
	./node_setter/node_setter.c \
	./utils/ft_get_count.c \
	./utils/ft_stack_init.c \
	./utils/ft_append_node.c \
	./utils/ft_node_reset.c \
	./utils/ft_remove_node.c \
	./parser/parser_input.c \
	./sorting/ft_sorting.c \
	./validators/validator.c \
	./validators/validator_sign.c \
	./validators/validator_num.c \
	./validators/validator_int.c \
	./validators/validator_duplicate.c \
	./validators/validator_sorting.c \
	./instructions/push.c \

SRCS_OBJS = ${SRCS:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $? -o $@

${NAME}: ${SRCS_OBJS}
	${MAKE} -C libft
	ar src $@ $?
	${CC} -o push_swap main.c ${NAME} ${LIB} -fsanitize=address

all : ${NAME}

clean : 
	${RM} ${SRCS_OBJS}
	${MAKE} clean -C libft

fclean : clean
	${RM} ${NAME}
	${MAKE} fclean -C libft

re : clean all

.PHONY = all clean fclean re
