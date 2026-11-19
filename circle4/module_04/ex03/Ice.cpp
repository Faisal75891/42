#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{ 
}

Ice::~Ice()
{
}

Ice::Ice(const Ice& src) : AMateria(src)
{

}

Ice&    Ice::operator=(const Ice& src)
{
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

AMateria	*Ice::clone() const
{
    return new Ice(*this);
}
