# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/08 11:14:43 by fbaras            #+#    #+#              #
#    Updated: 2026/09/08 11:14:43 by fbaras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = b
SRC = AForm.cpp  Bureaucrat.cpp  PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp  main.cpp
OBJ = AForm.o  Bureaucrat.o  PresidentialPardonForm.o  RobotomyRequestForm.o  ShrubberyCreationForm.o  main.o		
HEADERS = AForm.hpp  PresidentialPardonForm.hpp  ShrubberyCreationForm.hpp  Bureaucrat.hpp  RobotomyRequestForm.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I. $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
