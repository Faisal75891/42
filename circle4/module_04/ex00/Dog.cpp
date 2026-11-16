#include "Dog.h"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Hello i am dog\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy Dog constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Assignment Dog constructor called\n";
    return *this;
}

Dog::~Dog()
{
    std::cout << "AWOOOOOOOOOOOOOOOO\n";
}

void Dog::makeSound() const
{
    std::cout << "woof woof!\n";
}