
#pragma once

#include "FragTrap.h"
#include "ScavTrap.h"

/*
Of course, the ClapTrap instance of DiamondTrap will be created once, and only once.
Yes, there’s a trick.
*/

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		void	attack(const std::string& target);// override;
		void	whoAmI();
};
