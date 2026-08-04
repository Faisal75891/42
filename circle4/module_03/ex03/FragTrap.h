
#pragma once

#include "ClapTrap.h"

class FragTrap  : public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();
		void	highFiveGuys(void) const;
};
