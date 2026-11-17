

#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& src);
		Ice&    operator=(const Ice& src);
		AMateria	*clone() const;
};
