# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/04 23:50:38 by fbaras            #+#    #+#              #
#    Updated: 2026/08/04 23:53:07 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = h
SRC = Harl.cpp main.cpp
OBJ = Harl.o main.o
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
