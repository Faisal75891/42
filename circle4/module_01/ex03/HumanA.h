
#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA
{
	private:
		string	name;
		Weapon	&weapon;
	public:
		HumanA(string name, Weapon &weapon);
		void    attack() { cout << name << " attacks their " << weapon.getType() << endl; }
		void	setWeapon(Weapon new_weapon) { weapon = new_weapon; }
};

HumanA::HumanA(string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

#endif
