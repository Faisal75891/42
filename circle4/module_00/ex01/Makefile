NAME = phonebook
SRC = phonebook.cpp
OBJ = phonebook.o

all: $(NAME)

NAME:
	g++ -Wall -Wextra -Werror $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re
