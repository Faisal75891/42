NAME = megaphone
SRC = megaphone.cpp
OBJ = megaphone.o

all: $(NAME)

NAME:
	g++ -Wall -Wextra -Werror $(SRC)

clean:
	rm -rf $(OBJ)

fclean: $(clean)
	rm -rf $(NAME)

re: $(fclean) $(NAME)

.PHONY: all clean fclean re
