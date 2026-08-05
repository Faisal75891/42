# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/05 22:58:01 by fbaras            #+#    #+#              #
#    Updated: 2026/08/05 22:58:01 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = s
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
OBJ =   ClapTrap.o main.o ScavTrap.o FragTrap.o

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
