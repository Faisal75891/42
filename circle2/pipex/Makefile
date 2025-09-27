NAME = pipex.a
SRC = pipex.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ./ft_printf
PRINTF = ft_printf/libftprintf.a
LIBFT_DIR = ./libft
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
	cp $(PRINTF) $(NAME)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(SRC)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONEY: all clean fclean re
