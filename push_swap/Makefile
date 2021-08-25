# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:29:05 by taeskim           #+#    #+#              #
#    Updated: 2021/08/25 14:36:33 by pac-man          ###   ########.fr        #
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
	./utils/ft_remove_node.c \
	./utils/ft_export_node.c \
	./parser/parser_input.c \
	./sorting/ft_sorting.c \
	./sorting/ft_sorting_two.c \
	./sorting/ft_sorting_three.c \
	./sorting/ft_sorting_five.c \
	./sorting/ft_sorting_all.c \
	./sorting/ft_sorting_utils.c \
	./sorting/ft_sorting_algo.c \
	./validators/validator.c \
	./validators/validator_num.c \
	./validators/validator_int.c \
	./validators/validator_duplicate.c \
	./validators/validator_sorting.c \
	./instructions/push.c \
	./instructions/swap.c \
	./instructions/rotate.c \
	./instructions/rrotate.c \

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
