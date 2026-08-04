
#pragma once

#include "ICharacter.hpp"
#include "Materia.hpp"

#define MAX_MATRIA 4

class Character : public ICharacter
{
	private:
		AMateria		*matria[MAX_MATRIA];
		int				idx; // should it be size_t??
		std::string		name;
	public:
		Character(std::string n);
		~Character();
		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int	idx);
		void				use(int idx, ICharacter& target);
		Character(Character &src);
		Character	&operator=(Character &src);

};
