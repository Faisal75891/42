#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

AMateria	*Cure::clone() const
{   
    return new Cure();
}

