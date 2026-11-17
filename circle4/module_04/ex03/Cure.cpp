#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& src) : AMateria(src)
{

}

Cure& Cure::operator=(const Cure& src)
{
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

AMateria	*Cure::clone() const
{   
    return new Cure();
}

