#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(std::string a) : type(a)
{
        std::cout << "a " << a << " is born\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "a " << type << " is gone :(\n";
}

void	WrongAnimal::makeSound() const
{
    std::cout << "[wind blowing]\n";
}
