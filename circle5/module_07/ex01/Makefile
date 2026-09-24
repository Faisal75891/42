NAME = i
SRC = main.cpp
OBJ = main.o
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = g++

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re