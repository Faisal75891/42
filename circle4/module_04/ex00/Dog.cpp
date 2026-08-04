#include "Dog.h"

Dog::Dog(std::string n) : Animal(n)
{
    std::cout << "Hello i am dog\n";
}

Dog::~Dog()
{
    std::cout << "AWOOOOOOOOOOOOOOOO\n";
}

void Dog::makeSound() const
{
    std::cout << "woof woof!\n";
}