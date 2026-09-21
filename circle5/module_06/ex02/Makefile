# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/21 17:08:48 by fbaras            #+#    #+#              #
#    Updated: 2026/09/21 17:08:48 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = s
SRC = A.cpp  B.cpp  Base.cpp  C.cpp  main.cpp
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