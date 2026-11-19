#include "Dog.h"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Hello i am dog\n";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "Copy Dog constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        Brain *newBrain = new Brain(*other.brain);
        delete this->brain;
        this->brain = newBrain;
    }
    std::cout << "Assignment Dog operator called\n";
    return *this;
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

void    Dog::setIdea(size_t i, std::string idea)
{
    this->brain->setIdea(i, idea);
}
