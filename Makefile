NAME = push_swap
User = $(shell whoami)

APPNAME = push_swap
BONUS = checker
LIBTH = get_next_line

CC = $(shell which clang gcc cc | head -n 1)
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRCS_DIR = ./
OBJS_DIR = ./objs/
LIBTH_DIR = ./get_next_line/
BONUS_DIR = ./bonus/

$(shell mkdir -p $(OBJS_DIR))
$(shell mkdir -p $(OBJS_DIR)push_swap_exec)
$(shell mkdir -p $(OBJS_DIR)src/stack)
$(shell mkdir -p $(OBJS_DIR)src/utils)
$(shell mkdir -p $(OBJS_DIR)src/operations)
$(shell mkdir -p $(OBJS_DIR)src/process)
$(shell mkdir -p $(OBJS_DIR)src/sort)

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

FILE_LIBTH = get_next_line/get_next_line \
				get_next_line/get_next_line_utils\

FILES_BONUS = bonus/checker \
				bonus/utils_checker \
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
				get_next_line/get_next_line \
				get_next_line/get_next_line_utils\


SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
LIBTH_SRC = $(addprefix $(LIBTH_DIR), $(addsuffix .c, $(FILE_LIBTH)))
LIBTH_OBJS = $(LIBTH_SRC:$(LIBTH_DIR)%.c=$(OBJS_DIR)%.o)
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = $(SRCS_BONUS:$(BONUS_DIR)%.c=$(OBJS_DIR)%.o)

LIBTH_A = $(LIBTH_DIR)$(LIBTH)

BONUS_A = $(BONUS_DIR)$(BONUS)

all: $(NAME)
	@echo "$(BLUE) $(OBJS) $(LIBTH) $(LIBTH_A) was successfully created.$(DEFAULT)"

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) $(BONUS_DIR) $(OBJS_DIR) Compiled "$<" successfully!"

$(LIBTH_A): $(LIBTH_OBJS)
	@mkdir -p $(LIBTH_DIR)
	$(AR) $(LIBTH_A) $(LIBTH_OBJS)
	@echo "$(CYAN) $(LIBTH_OBJS) $(LIBTH_A) library was successfully created.$(DEFAULT)"

$(BONUS_A): $(OBJS_BONUS)
	@mkdir -p $(BONUS_DIR)
	$(CC) -o $(BONUS_A) $(OBJS_BONUS)
	@echo "$(MAGENTA) $(OBJS_BONUS) $(BONUS_A) $(OBJS_DIR) $(BONUS_DIR) BONUS was successfully created.$(DEFAULT)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"

$(LIBTH_DIR)%.o: $(LIBTH_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) $(LIBTH_DIR) Creating object file: $(DEFAULT)$(notdir $@)"

$(OBJS_DIR)%.o: $(LIBTH_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(purple) $(LIBTH_DIR) $(OBJS_DIR) Creating object file: $(DEFAULT)$(notdir $@)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MAGENTA) $(SRCS_DIR) $(OBJS_DIR) Creating object file: $(DEFAULT)$(notdir $@)"

bonus: $(BONUS_A)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS)
	@echo "$(purple) $(BONUS_A) $(BONUS) $(OBJS_BONUS) Bonus compiled: $(DEFAULT)$(NAME)_bonus"

$(NAME): $(OBJS) $(LIBTH_A)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LIBTH)
	@echo "$(BLUE) $(OBJS) $(LIBTH) $(LIBTH_A) was successfully created.$(DEFAULT)"

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) $(BONUS_DIR) $(OBJS_DIR) Compiled "$<" successfully!"

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(RED) $(OBJS) Fully cleaned.$(DEFAULT)"
	@echo "$(PINK) $(OBJS_BONUS) $(OBJS) Fully cleaned.$(DEFAULT)"
	$(RM) $(LIBTH_OBJS)
	@echo "$(RED) $(RM) $(LIBTH_OBJS) Fully cleaned.$(DEFAULT)"
	$(shell rm -r $(OBJS_DIR))
	@echo "$(RED)Fully cleaned.$(DEFAULT)"

fclean: clean
	$(RM) $(OBJS) $(OBJS_BONUS) 
	$(RM) $(LIBTH_OBJS) $(LIBTH_A)
	@echo "$(GREEN)Cleaned everything.$(DEFAULT)"

re: fclean clean
	@echo "$(BOLD)Cleaned .$(DEFAULT)"

rebonus: fclean 
	$(RM) $(OBJS_BONUS) $(BONUS)
	@echo "$(YELLOW)Cleaned bonus.$(DEFAULT)"

.PHONY: clean fclean re rebonus $(RM) $(get_next_linemake \
	get_next_lineclean \ get_next_linefclean \ get_next_linere \)
	@echo "$(YELLOW).PHONY Cleaned.$(DEFAULT)"

get_next_linemake:
	@make -C get_next_line $(LIBTH)
get_next_lineclean:
	@make clean -C get_next_line $(LIBTH)
get_next_linefclean:
	@make fclean -C get_next_line $(LIBTH)
get_next_linere:
	@make re -C get_next_line $(LIBTH)

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
PINK	:= \033[38;5;206m
purple	:= \033[38;5;57m
DEFAULT	:= \033[0m