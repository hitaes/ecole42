# =============================================================================
# Color Variables
# =============================================================================

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CDEBUG		=	-fsanitize=address -g
RM			=	rm -f

# =============================================================================
# File Variables
# =============================================================================

NAME		=	philo
HEADER		=	./includes/
PHIL_DIR	=	./srcs/
D_UTILS		=	./utils/
D_LIBFT		=	./libft/
SRC_LIST	=	philo.c							\
				$(D_LIBFT)ft_memset.c			\
				$(D_LIBFT)ft_putstr_fd.c		\
				$(D_LIBFT)ft_strlen.c			\
				$(D_LIBFT)ft_atoi.c				\
				$(D_UTILS)ft_error_disposal.c	\
				$(D_UTILS)ft_philo_init.c		\

SRCS		=	$(addprefix $(PHIL_DIR), $(SRC_LIST))
OBJS		=	$(SRCS:.c=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o			:	%.c
				@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJS)
				@echo $(GREEN) "Source files are compiled!\n" $(EOC)
				@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
				@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJS)
				@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

# =============================================================================
# Rules
# =============================================================================

.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
				@echo $(YELLOW) "Cleaning object files..." $(EOC)
				@$(RM) $(OBJ)
				@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY		:	fclean
fclean		:	clean
				@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
				@$(RM) $(NAME)
				@echo $(RED) "$(NAME) is removed!\n" $(EOC)

.PHONY		:	re
re			:	fclean all

.PHONY		:	norm
norm		:
				@norminette

