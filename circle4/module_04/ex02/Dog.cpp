#include "Dog.h"

Dog::Dog(std::string n) : Animal(n)
{
    std::cout << "Hello i am dog\n";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "AWOOOOOOOOOOOOOOOO\n";
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "woof woof!\n";
}

const std::string    Dog::getIdea(size_t i) const
{
    return(this->brain->getIdea(i));
}

void	Dog::getIdeas() const
{
    this->brain->getIdeas();
}

void    			Dog::setIdea(size_t i, std::string idea)
{
    this->brain->setIdea(i, idea);
}
