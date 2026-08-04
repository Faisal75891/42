# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/04 23:10:34 by fbaras            #+#    #+#              #
#    Updated: 2026/08/04 23:13:14 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = e
SRC = HumanA.cpp  HumanB.cpp  main.cpp  Weapon.cpp
OBJ = HumanA.o  HumanB.o  main.o  Weapon.o
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
