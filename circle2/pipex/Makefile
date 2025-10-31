NAME = pipex
SRC = pipex.c commands.c executor.c here_doc.c ft_split_new.c ft_split_utils.c error.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = pipex_bonus.c commands.c executor.c here_doc.c ft_split_new.c ft_split_utils.c error.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./ft_printf/libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

bonus: $(OBJ_BONUS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
