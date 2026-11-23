NAME = e
SRC = main.cpp ScalarConverter.cpp
OBJ = main.o ScalarConverter.o
HEADERS = ScalarConverter.hpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I. $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re