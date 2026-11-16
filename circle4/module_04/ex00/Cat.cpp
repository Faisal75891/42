#include "Cat.h"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Hello i am cat\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy Cat constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Copy Cat constructor called\n";
    return *this;
}

Cat::~Cat()
{
    std::cout << "MEOOOOOOOOOOOW\n";
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}