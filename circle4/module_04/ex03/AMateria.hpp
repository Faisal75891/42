
#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(std::string const & type);
		virtual	~AMateria();
		std::string const 	&getType() const;
		void				setType(const std::string a);
		virtual	AMateria	*clone() const = 0;
		virtual	void		use(ICharacter& target);

		// TODO: Copy and assign thing - Maybe not needed
};

#endif