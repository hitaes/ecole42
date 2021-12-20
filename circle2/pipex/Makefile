# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pacman <pacman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 00:56:50 by pac-man           #+#    #+#              #
#    Updated: 2021/12/20 18:05:57 by pacman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Color Variables
# =============================================================================

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

# =============================================================================
# Command Variables
# =============================================================================

CC					=		gcc
CFLAGS				=		-Wall -Werror -Wextra
CDEBUG				=		-fsanitize=address -g
RM					=		rm -f
NAME				=		pipex

# =============================================================================
# File Variables
# =============================================================================

HEADER_DIR			=		./includes/
PIPEX_DIR			=		./srcs/
SHARED_DIR			=		./srcs/shared/
D_LIBFT				=		libft/
D_UTILS				=		utils/

PIPEX_SRC_LIST		=		pipex.c								\

SHARED_SRC_LIST		=		$(D_LIBFT)ft_strncmp.c				\
							$(D_LIBFT)ft_memset.c				\
							$(D_LIBFT)ft_putstr_fd.c			\
							$(D_LIBFT)ft_strlen.c				\
							$(D_LIBFT)ft_calloc.c				\
							$(D_LIBFT)ft_strdup.c				\
							$(D_LIBFT)ft_strlcpy.c				\
							$(D_LIBFT)ft_strjoin.c				\
							$(D_UTILS)char_frequency.c			\
							$(D_UTILS)arg_init.c				\
							$(D_UTILS)substr.c					\
							$(D_UTILS)str_slicer.c				\
							$(D_UTILS)pipe_utils.c				\

PIPEX_SRCS			=		$(addprefix $(PIPEX_DIR), $(PIPEX_SRC_LIST))
PIPEX_OBJS			=		$(PIPEX_SRCS:.c=.o)

SHARED_SRCS			=		$(addprefix $(SHARED_DIR), $(SHARED_SRC_LIST))
SHARED_OBJS			=		$(SHARED_SRCS:.c=.o)

OBJS				=		$(PIPEX_OBJS) ${SHARED_OBJS}

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $@ $(EOC) $(LINE_CLEAR)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

$(NAME)				:		$(OBJS)
							@echo $(GREEN) "Object File Compiled!\n" $(EOC)
							@echo $(YELLOW) "PIPEX Building..." $(EOC)
							@$(CC) ${CFLAGS} -I $(HEADER_DIR) -o $(NAME) ${PIPEX_OBJS} ${SHARED_OBJS}
							@echo $(GREEN) "Ready to be Executed!\n\n" $(EOC)


.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Object File Cleaning..." $(EOC)
							@$(RM) $(PIPEX_OBJS) $(SHARED_OBJS) 
							@echo $(RED) "Object File Cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "PIPEX Removing..." $(EOC)
							@$(RM) $(NAME)
							@echo $(RED) "PIPEX Removed!\n\n" $(EOC)
							
.PHONY				:		re
re					:		fclean all

.PHONY				:		bonus
bonus				:		all