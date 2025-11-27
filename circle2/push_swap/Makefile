NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC =	utils/ops_swap.c utils/ops_push.c utils/ops_rotate_up.c utils/ops_rotate_down.c utils/check_for_duplicates.c utils/stack_operations.c utils/stack_checks.c utils/parser.c utils/print_stack.c \
		sort_utils/best_index_to_move.c sort_utils/is_sorted.c sort_utils/rotate_to_top.c sort_utils/smallest_biggers.c sort_utils/stack_positioning.c	sort_utils/utils.c \
		small_sort/small_sort.c \

PUSH_SWAP_SRC = push_swap.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./ft_printf/libft
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

SRC_BONUS = checker_utils/checker.c checker_utils/get_operation.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CHECKER = checker

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PUSH_SWAP_OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONUS) $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) $(PRINTF) $(LIBFT) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(PUSH_SWAP_OBJ) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: clean fclean re all bonus test clean_tests
