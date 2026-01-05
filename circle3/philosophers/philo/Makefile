NAME = philo
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = forks.c  free_philos.c  ft_atoi.c  init_philo.c  philo.c  state.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: flcean all

.PHONEY: all clean fclean re