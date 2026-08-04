
#pragma once

#include "ClapTrap.h"

class FragTrap  : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();
		void	highFiveGuys(void) const;
};
