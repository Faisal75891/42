NAME = philo
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = forks.c  free_philos.c  ft_atoi.c  init_philo.c  philo.c  state.c  actions.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONEY: all clean fclean re