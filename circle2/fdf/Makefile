NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LINUX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MAC_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MINILIB_MAC_DIR = mlx
MINILIB_LINUX_DIR = minilibx_linux

LIBFT_DIR = ./ft_printf/libft
FT_PRINTF_DIR = ./ft_printf

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

SRC = fdf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(MAC_FLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MINILIB_MAC_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re