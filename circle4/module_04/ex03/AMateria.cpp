#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
 // check for valid type??   
}

AMateria::~AMateria()
{
    
}

std::string const 	&AMateria::getType() const
{
    return (type);
}

void    AMateria::setType(const std::string a)
{
    this->type = a;
}

void		AMateria::use(ICharacter& target)
{
    if (type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; 
    else if (type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds" << std::endl; 

}
