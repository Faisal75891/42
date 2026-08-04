
#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB
{
	private:
		string	name;
		Weapon	*weapon;
	public:
		HumanB(string name);
		void    attack() { cout << name << " attacks their " << weapon->getType() << endl; }
		void	setWeapon(Weapon new_weapon) { *weapon = new_weapon; }
};

HumanB::HumanB(string name) : name(name)
{
}

#endif
