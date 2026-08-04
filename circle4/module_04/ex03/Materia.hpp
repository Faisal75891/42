
#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Materia : public AMateria
{
	public:
		Materia(std::string n);
		~Materia();
		std::string const 	&getType() const;
		AMateria			*clone() const;
		void				use(ICharacter& target);
};
