# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 14:56:20 by pac-man           #+#    #+#              #
#    Updated: 2021/09/12 00:45:41 by pac-man          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK				= 		"\033[0;30m"
GRAY				= 		"\033[1;30m"
RED					=		"\033[0;31m"
GREEN				=		"\033[0;32m"
YELLOW				=		"\033[1;33m"
PURPLE				=		"\033[0;35m"
CYAN				=		"\033[0;36m"
WHITE				=		"\033[1;37m"
EOC					=		"\033[0;0m"
LINE_CLEAR			=		"\x1b[1A\x1b[M"

CC					=		gcc
CFLAGS				=		-Werror	-Wall -Wextra
RM					=		rm -rf
NAME				=		pipex

HEADER_DIR			=		./includes/
PIPEX_DIR			=		./srcs/

PIPEX_SRC_LIST		=		main.c					\
							cmds_init.c				\
							cmds_check_and_set.c	\

PIPEX_SRCS			=		$(addprefix $(PIPEX_DIR), $(PIPEX_SRC_LIST))
PIPEX_OBJS			=		$(PIPEX_SRCS:.c=.o)

OBJS				=		$(PIPEX_OBJS)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $@ $(EOC) $(LINE_CLEAR)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

$(NAME)				:		$(OBJS)
							@echo $(GREEN) "Object File Compiled!\n" $(EOC)
							@echo $(YELLOW) "pipex Building..." $(EOC)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(NAME) $(PIPEX_OBJS)
							@echo $(GREEN) "Ready to be Executed!\n\n" $(EOC)

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Object File Cleaning..." $(EOC)
							@$(RM) $(PIPEX_OBJS)
							@echo $(RED) "Object File Cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "pipex Removing..." $(EOC)
							@$(RM) $(NAME)
							@echo $(RED) "pipex Removed!\n\n" $(EOC)

.PHONY				:		re
re					:		fclean all