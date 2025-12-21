NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIB_MAC_DIR = ./minilibx/mlx
MINILIB_LINUX_DIR = ./minilibx/mlx_linux

LINUX_FLAGS = -Lmlx_linux -lmlx_Linux -L$(MINILIB_LINUX_DIR) -Imlx_linux -lXext -lX11 -lm -lz
MAC_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./ft_printf/libft
FT_PRINTF_DIR = ./ft_printf

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIB_LINUX_DIR)/libmlx.a

SRC = fdf.c parse.c ft_get_next_line/get_next_line.c ft_get_next_line/get_next_line_utils.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) $(MINILIBX) $(LINUX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

install_dependencies_linux:
	sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(MINILIBX):
	make all -C $(MINILIB_LINUX_DIR)

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