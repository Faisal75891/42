# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/04 20:02:01 by fbaras            #+#    #+#              #
#    Updated: 2026/08/05 16:30:42 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = h
SRC = main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp
OBJ = main.o  newZombie.o  randomChump.o  Zombie.o
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
