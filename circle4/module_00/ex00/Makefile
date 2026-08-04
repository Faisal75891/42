NAME = megaphone
SRC = megaphone.cpp
OBJ = megaphone.o

all: $(NAME)

$(NAME): $(SRC)
	g++ -Wall -Wextra -Werror -std=c++98 $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
