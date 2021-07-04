# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taeskim <taeskim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:36:10 by taeskim           #+#    #+#              #
#    Updated: 2021/06/15 11:28:32 by taeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

NAME = libft.a

RM = rm -rf

SRCS = \
	ft_isdigit.c	\
	ft_atoi.c		\
	ft_strlen.c		\

SRCS_OBJS = ${SRCS:%.c=%.o}

%.o : %.c
	${CC} ${CFLAGS} -c $? -o $@

${NAME}: ${SRCS_OBJS}
	ar src $@ $?

all : ${NAME}

clean : 
	${RM} ${SRCS_OBJS}

fclean : clean
	${RM} ${NAME}

re : clean all

.PHONY = all clean fclean re