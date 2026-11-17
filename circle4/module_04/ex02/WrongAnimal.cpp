#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
        std::cout << "a " << type << " is born\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "Copy WrongAnimal constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Assignment WrongAnimal constructor called\n";
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "a " << type << " is gone :(\n";
}

void	WrongAnimal::makeSound() const
{
    std::cout << "[wind blowing]\n";
}
