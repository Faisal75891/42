NAME = n
SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  Materia.cpp  MateriaSource.cpp  main.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS =  AMateria.hpp  Character.hpp  Cure.hpp  Ice.hpp  ICharacter.hpp  IMateriaSource.hpp  Materia.hpp  MateriaSource.hpp
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
