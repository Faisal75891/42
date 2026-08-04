
#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class Weapon
{
	private:
		string	type;
	public:
		Weapon(string type);
		~Weapon();
		string	getType(void) const { return type; }
		void	setType(string new_type) { type = new_type; }
};

Weapon::Weapon(string type)
{
	type = type;
}

Weapon::~Weapon()
{
	//cout << type << " got destroyed!\n";
}

#endif
