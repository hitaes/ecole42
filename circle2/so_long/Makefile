# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:29:05 by taeskim           #+#    #+#              #
#    Updated: 2021/10/19 21:30:20 by pac-man          ###   ########.fr        #
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

CC 					= 		gcc
CFLAGS 				= 		-Wall -Wextra -Werror -Imlx
MFLAGS				=		-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
RM 					= 		rm -rf
NAME				= 		so_long
MLX					=		libmlx.a
LIBFT				=		libft.a

HEADER_DIR			=		./includes/
SO_LONG_DIR			=		./srcs/so_long/
SHARED_DIR			=		./srcs/shared/
MLX_DIR				=		./resources/minilibx_opengl_20191021/

D_LIBFT				=		libft/
D_MAP				=		map/
D_UTILS				=		utils/
D_GAME				=		game/
											
SO_LONG_SRC_LIST	=		$(D_MAP)map_validator.c 		\
							$(D_MAP)map_frame_setter.c		\
							$(D_MAP)map_maker.c				\
							$(D_MAP)map_finder.c			\
							$(D_MAP)map_row_column.c		\
							$(D_MAP)draw_sprite.c			\
							$(D_GAME)game_init.c			\
							$(D_GAME)game_end.c				\
							main.c

SHARED_SRC_LIST		=		$(D_LIBFT)ft_isdigit.c			\
							$(D_LIBFT)ft_atoi.c				\
							$(D_LIBFT)ft_strlen.c			\
							$(D_LIBFT)ft_memset.c     		\
							$(D_LIBFT)ft_calloc.c     		\
							$(D_LIBFT)ft_strlcpy.c    		\
							$(D_LIBFT)ft_strdup.c			\
							$(D_LIBFT)ft_putstr_fd.c 		\
							$(D_LIBFT)ft_get_next_line.c	\
							$(D_LIBFT)ft_strjoin.c			\
							$(D_LIBFT)ft_strcmp.c			\
							$(D_LIBFT)ft_replace.c			\
							$(D_LIBFT)ft_itoa.c				\
							$(D_UTILS)ft_error_disposal.c	\
							$(D_UTILS)ft_free.c				\
							$(D_UTILS)ft_trace_setter.c		\
							$(D_UTILS)ft_keypress.c			\
							$(D_UTILS)ft_free_map.c			\

SO_LONG_SRCS 		=		$(addprefix $(SO_LONG_DIR), $(SO_LONG_SRC_LIST))
SO_LONG_OBJS 		=		$(SO_LONG_SRCS:.c=.o)

SHARED_SRCS 		=		$(addprefix $(SHARED_DIR), $(SHARED_SRC_LIST))
SHARED_OBJS 		=		$(SHARED_SRCS:.c=.o)

MLX_LIB				=		$(addprefix $(MLX_DIR), $(MLX))	

OBJS				=		$(SO_LONG_OBJS) ${SHARED_OBJS}

$(NAME)				:		$(OBJS)
							@make -C $(MLX_DIR) all;
							@echo $(GREEN) "Object File Compiled!\n" $(EOC)
							@echo $(YELLOW) "SO_LONG Building..." $(EOC)
							$(CC) ${MFLAGS} -I $(HEADER_DIR) -o $(NAME) ${SO_LONG_OBJS} ${SHARED_OBJS}
							@echo $(GREEN) "Ready to be Executed!\n\n" $(EOC)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $@ $(EOC) $(LINE_CLEAR)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Object File Cleaning..." $(EOC)
							@$(RM) $(SO_LONG_OBJS) $(SHARED_OBJS) 
							@make -C $(MLX_DIR) clean;
							@echo $(RED) "Object File Cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "SO_LONG Removing..." $(EOC)
							@$(RM) $(NAME)
							@echo $(RED) "SO_LONG Removed!\n\n" $(EOC)
							
.PHONY				:		re
re					:		fclean all

.PHONY				:		bonus
bonus				:		all