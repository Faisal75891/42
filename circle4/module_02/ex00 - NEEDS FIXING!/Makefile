NAME = f
SRC = main.cpp Fixed.cpp
OBJ = main.o Fixed.o

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: $(clean)
	rm -rf $(NAME)

re: $(fclean) $(all)

.PHONY: all clean fclean re
