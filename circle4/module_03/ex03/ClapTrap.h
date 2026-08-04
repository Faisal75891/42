
#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int	hp, ad, ep;
	public:
		// ClapTrap();
		ClapTrap(std::string name);
		ClapTrap();
		~ClapTrap();
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	display() const;
};

#endif
