#include "Materia.hpp"

Materia::Materia() : AMateria()
{

}

Materia::Materia(const Materia& src) : AMateria(src)
{
    
}

Materia::Materia(const std::string &n) : AMateria(n)
{
    
}

Materia::~Materia()
{
    
}

Materia&    Materia::operator=(const Materia& src)
{
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

AMateria	*Materia::clone() const
{
	return new Materia(*this);
}

std::string const 	&Materia::getType() const
{
	return (AMateria::getType());
}

void	Materia::use(ICharacter& target)
{
	AMateria::use(target);
}
