NAME = a
SRC = Animal.cpp  Cat.cpp  Dog.cpp  WrongAnimal.cpp  WrongCat.cpp  main.cpp Brain.cpp
OBJ = Animal.o  Cat.o  Dog.o  WrongAnimal.o  WrongCat.o  main.o Brain.o
HEADERS = Animal.h Brain.h Cat.h Dog.h WrongAnimal.h WrongCat.h
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I. $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re