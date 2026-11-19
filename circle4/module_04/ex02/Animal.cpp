#include "Animal.h"

Animal::Animal() : type("Animal")
{
    std::cout << "a " << type << " is born\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Copy Animal constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Assignment Animal constructor called\n";
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal " << type << " is no more :(\n";
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
