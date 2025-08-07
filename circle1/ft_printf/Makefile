NAME = libprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC = ft_printf.c ft_putbase_fd.c  ft_putchar_fdi.c  ft_putnbr_fdi.c  ft_putptr_fd.c  ft_putstr_fdi.c  ft_putunbr_fd.c
OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd ./libft && make

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re
