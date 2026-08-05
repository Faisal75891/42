# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/05 22:21:09 by fbaras            #+#    #+#              #
#    Updated: 2026/08/05 22:21:09 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
SRC = arithmetic.cpp  bsp.cpp  comparison.cpp  crements.cpp  Fixed.cpp  main.cpp  Point.cpp
OBJ =  arithmetic.o  bsp.o  comparison.o  crements.o  Fixed.o  main.o  Point.o

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	g++ $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
