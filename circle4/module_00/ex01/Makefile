NAME = phonebook
SRC = phonebook.cpp main.cpp Contact.cpp 
OBJ = phonebook.o main.o Contact.o

all: $(NAME)

$(NAME): $(SRC)
	clang++ -Wall -Wextra -Werror --std=c++98 $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
