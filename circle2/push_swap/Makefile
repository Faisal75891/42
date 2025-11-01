NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = instructions.c  operations.c    push_swap.c
OBJ = $(SRC:.c=.o)
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./ft_printf/libft
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

test_three:
	@echo "============================="
	@./push_swap 1 2 3
	@echo "============================="
	@./push_swap 1 3 2
	@echo "============================="
	@./push_swap 2 1 3
	@echo "============================="
	@./push_swap 2 3 1
	@echo "============================="
	@./push_swap 3 1 2
	@echo "============================="
	@./push_swap 3 2 1
	@echo "============================="
	@./push_swap 2 1
	@echo "============================="
	@./push_swap 1 2
	@echo "============================="

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: clean fclean re all
