# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/04 21:56:56 by fbaras            #+#    #+#              #
#    Updated: 2026/08/04 22:04:48 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = h
SRC = main.cpp  Zombie.cpp  zombieHorde.cpp
OBJ = main.o  Zombie.o  zombieHorde.o
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
