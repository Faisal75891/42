# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/05 16:50:22 by fbaras            #+#    #+#              #
#    Updated: 2026/08/05 16:52:10 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = w
SRC = main.cpp
OBJ = main.o
CXX = clang++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
