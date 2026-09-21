# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 10:30:35 by fbaras            #+#    #+#              #
#    Updated: 2026/09/20 10:30:35 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = s
SRC = Data.cpp  Serializer.cpp  main.cpp
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = g++

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re