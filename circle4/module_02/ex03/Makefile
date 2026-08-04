NAME = bsp
SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJ =  Fixed.o main.o Point.o bsp.o

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