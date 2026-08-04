#include "Materia.hpp"

Materia::Materia(std::string n) : AMateria(n)
{

}

Materia::~Materia()
{
	
}

AMateria	*Materia::clone() const
{
	return new Materia(this->getType());
}

std::string const 	&Materia::getType() const
{
	return (AMateria::getType());
}

void	Materia::use(ICharacter& target)
{
	AMateria::use(target);
}
