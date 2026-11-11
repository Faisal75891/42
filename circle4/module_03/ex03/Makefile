# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/10 19:47:11 by fbaras            #+#    #+#              #
#    Updated: 2026/11/10 19:47:11 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = c
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = ClapTrap.o main.o ScavTrap.o FragTrap.o DiamondTrap.o

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
