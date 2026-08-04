NAME = a
SRC = Animal.cpp  Cat.cpp  Dog.cpp  WrongAnimal.cpp  WrongCat.cpp  main.cpp Brain.cpp
OBJ = Animal.o  Cat.o  Dog.o  WrongAnimal.o  WrongCat.o  main.o Brain.o
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	clang++ $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re