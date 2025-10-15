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

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)
	make clean -C $(ft_printf)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(ft_printf)

re: fclean a;;

.PHONY: clean fclean re all
