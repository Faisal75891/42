
#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Materia : public AMateria
{
	public:
        Materia();
		Materia(std::string n);
        Materia(const Materia& src);
        Materia&    operator=(const Materia& src);
		~Materia();
		std::string const 	&getType() const;
		AMateria			*clone() const;
		void				use(ICharacter& target);
};
