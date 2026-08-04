
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap
{
	private:
		bool gateMode;
	public:
		ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};


#endif