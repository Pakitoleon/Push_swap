NAME = push_swap

CC = $(shell which cc clang gcc | head -n 1)
CFLAGS = -Wall -Wextra -Werror -g# -fsanitize=address
AR = ar rcs
RM = rm -f

FILES = push_swap_exec/push_swap \
		src/stack/stack_funcions \
		src/utils/ft_atol \
		src/utils/ft_find \
		src/utils/ft_free \
		src/utils/ft_print_error \
		src/utils/ft_split_utils \
		src/utils/ft_split \
		src/stack/ft_steps_calculator \
		src/stack/ft_stack_size \
		src/operations/operation_push \
		src/operations/operation_rerotate \
		src/operations/operations_rotate \
		src/operations/operations_swap \
		src/process/process \
		src/sort/sort_position \
		src/stack/stack_sorting \
		src/sort/utils_for_sort \

FILES_BONUS =

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix _bonus.c, $(FILES_BONUS)))

OBJS_DIR = ./

OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_PUSH)
	$(CC) $(CFLAGS) $(OBJ_PUSH) $(OBJ) -o $(NAME)

all: $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)_bonus

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus re bonus
