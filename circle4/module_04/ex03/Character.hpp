
#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATRIA 4

class Character : public ICharacter
{
	private:
		AMateria		*matria[MAX_MATRIA];
		std::string		name;
	public:
        Character();
		Character(std::string n);
		~Character();
		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int	idx);
		void				use(int idx, ICharacter& target);
		Character(const Character &src);
		Character	&operator=(const Character &src);

};
