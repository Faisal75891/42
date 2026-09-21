NAME = e
SRC = main.cpp ScalarConverter.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = g++

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re