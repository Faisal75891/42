# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/04 23:34:21 by fbaras            #+#    #+#              #
#    Updated: 2026/08/05 18:43:28 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = s
SRC = main.cpp
OBJ = main.o
CLFAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(CLFAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
