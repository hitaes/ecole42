# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:36:10 by taeskim           #+#    #+#              #
#    Updated: 2021/08/04 17:49:32 by pac-man          ###   ########.fr        #
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
	ft_memset.c     \
	ft_calloc.c     \
	ft_strlcpy.c    \
	ft_strdup.c		\
	ft_putstr.c 	\

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