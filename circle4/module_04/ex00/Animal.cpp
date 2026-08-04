#include "Animal.h"

Animal::Animal(std::string t) : type(t)
{
    std::cout << "a " << t << " is born\n";
}

Animal::~Animal()
{
    std::cout << type << " is no more :(\n";
}

void Animal::makeSound() const
{
    std::cout << "...\n";
}

std::string Animal::getType() const
{
    return type;
}

void Animal::setType(std::string newType)
{
    type = newType;
}
