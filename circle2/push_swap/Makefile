# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:29:05 by taeskim           #+#    #+#              #
#    Updated: 2021/10/10 00:29:51 by pac-man          ###   ########.fr        #
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
CFLAGS 				= 		-Werror -Wall -Wextra
RM 					= 		rm -rf
P_NAME				= 		push_swap
C_NAME				= 		checker
NAME				= 		$(C_NAME) $(P_NAME)

HEADER_DIR			=		./includes/
CHECKER_DIR			=		./srcs/checker/
PUSH_SWAP_DIR		=		./srcs/push_swap/
SHARED_DIR			=		./srcs/shared/
TEST_DIR			=		./test/

D_VAL				=		validators/
D_INST				=		instructions/
D_LIBFT				=		libft/
D_UTILS				=		utils/
D_SORTING			=		sorting/
D_CHECKER			=		utils/


CHECKER_SRC_LIST	=		$(D_CHECKER)checker_utils.c		\
							checker.c
													
PUSH_SWAP_SRC_LIST	=		$(D_SORTING)ft_sorting.c 		\
							$(D_SORTING)ft_sorting_two.c 	\
							$(D_SORTING)ft_sorting_three.c 	\
							$(D_SORTING)ft_sorting_five.c 	\
							$(D_SORTING)ft_sorting_all.c 	\
							$(D_SORTING)ft_sorting_utils.c 	\
							$(D_SORTING)ft_sorting_algo.c 	\
							push_swap.c
SHARED_SRC_LIST		=		$(D_INST)push.c					\
							$(D_INST)swap.c					\
							$(D_INST)rotate.c				\
							$(D_INST)rrotate.c				\
							$(D_LIBFT)ft_isdigit.c			\
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
							$(D_UTILS)ft_get_count.c 		\
							$(D_UTILS)ft_stack_init.c 		\
							$(D_UTILS)ft_append_node.c 		\
							$(D_UTILS)ft_remove_node.c 		\
							$(D_UTILS)ft_export_node.c 		\
							$(D_UTILS)ft_free.c 			\
							$(D_UTILS)ft_replace.c 			\
							$(D_UTILS)ft_node_setter.c		\
							$(D_UTILS)ft_parser_input.c		\
							$(D_UTILS)ft_error_disposal.c	\
							${D_VAL}validator.c 			\
							${D_VAL}validator_num.c 		\
							${D_VAL}validator_int.c 		\
							${D_VAL}validator_duplicate.c	\
							${D_VAL}validator_sorting.c 	\

CHECKER_SRCS 		=		$(addprefix $(CHECKER_DIR), $(CHECKER_SRC_LIST))
CHECKER_OBJS 		=		$(CHECKER_SRCS:.c=.o)

PUSH_SWAP_SRCS 		=		$(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC_LIST))
PUSH_SWAP_OBJS 		=		$(PUSH_SWAP_SRCS:.c=.o)

SHARED_SRCS 		=		$(addprefix $(SHARED_DIR), $(SHARED_SRC_LIST))
SHARED_OBJS 		=		$(SHARED_SRCS:.c=.o)

OBJS				=		$(CHECKER_OBJS) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)

%.o					:		%.c
							@echo $(YELLOW) "Compiling...\t" $@ $(EOC) $(LINE_CLEAR)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

$(NAME)				:		$(OBJS)
							@echo $(GREEN) "Object File Compiled!\n" $(EOC)
							@echo $(YELLOW) "checker Building..." $(EOC)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(C_NAME) $(CHECKER_OBJS) $(SHARED_OBJS)
							@echo $(YELLOW) "push_swap Building..." $(EOC)
							@$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(P_NAME) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)
							@echo $(GREEN) "Ready to be Executed!\n\n" $(EOC)

.PHONY				:		all
all					:		$(NAME)

.PHONY				:		clean
clean				:
							@echo $(YELLOW) "Object File Cleaning..." $(EOC)
							@$(RM) $(SHARED_OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
							@echo $(RED) "Object File Cleaned!\n" $(EOC)

.PHONY				:		fclean
fclean				:		clean
							@echo $(YELLOW) "checker Removing..." $(EOC)
							@$(RM) $(CHECKER)
							@echo $(RED) "checker Removed!\n" $(EOC)
							@echo $(YELLOW) "push_swap Removing..." $(EOC)
							@$(RM) $(PUSH_SWAP)
							@echo $(RED) "push_swap Removed!\n\n" $(EOC)
							
.PHONY				:		re
re					:		fclean all

.PHONY				:		bonus
bonus				:		all

.PHONY				:		checker_error
checker_error		:
							@echo $(CYAN) "checker Error Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)checker_error.sh
							@bash $(TEST_DIR)checker_error.sh
							@echo $(EOC)

.PHONY				:		checker_false
checker_false		:
							@echo $(CYAN) "checker False Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)checker_false.sh
							@bash $(TEST_DIR)checker_false.sh
							@echo $(EOC)

.PHONY				:		checker_true
checker_true		:
							@echo $(CYAN) "checker True Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)checker_true.sh
							@bash $(TEST_DIR)checker_true.sh
							@echo $(EOC)

.PHONY				:		checker_test
checker_test		:		all checker_error checker_false checker_true

.PHONY				:		push_swap_identity
push_swap_identity	:
							@echo $(CYAN) "push_swap Identity Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_identity.sh
							@bash $(TEST_DIR)push_swap_identity.sh
							@echo $(EOC)

.PHONY				:		push_swap_vsimple
push_swap_vsimple	:
							@echo $(CYAN) "push_swap Simple Version Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_vsimple.sh
							@bash $(TEST_DIR)push_swap_vsimple.sh
							@echo $(EOC)

.PHONY				:		push_swap_vmiddle
push_swap_vmiddle	:
							@echo $(CYAN) "push_swap Middle Version Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_vmiddle.sh
							@bash $(TEST_DIR)push_swap_vmiddle.sh
							@echo $(EOC)

.PHONY				:		push_swap_vadvanced
push_swap_vadvanced	:
							@echo $(CYAN) "push_swap Advanced Version Testing...\n" $(EOC)
							@chmod 777 $(TEST_DIR)push_swap_vadvanced.sh
							@bash $(TEST_DIR)push_swap_vadvanced.sh
							@echo $(EOC)

.PHONY				:		push_swap_test
push_swap_test		:		all push_swap_identity push_swap_vsimple push_swap_vmiddle push_swap_vadvanced

.PHONY				:		test
test				:		checker_test push_swap_test