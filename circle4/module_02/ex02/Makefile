NAME = f
SRC = Fixed.cpp main.cpp
OBJ =  Fixed.o main.o

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all