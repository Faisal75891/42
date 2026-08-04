#include "Cat.h"

Cat::Cat(std::string n) : Animal(n)
{
    std::cout << "Hello i am cat\n";
}

Cat::~Cat()
{
    std::cout << "MEOOOOOOOOOOOW\n";
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}