#include "Cat.h"

Cat::Cat(std::string n) : Animal(n)
{
    std::cout << "Hello i am cat\n";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "MEOOOOOOOOOOOW\n";
    delete (this->brain);
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}

const std::string    Cat::getIdea(size_t i) const
{
    return(this->brain->getIdea(i));
}

void	Cat::getIdeas() const
{
    this->brain->getIdeas();
}

void    			Cat::setIdea(size_t i, std::string idea)
{
    this->brain->setIdea(i, idea);
}
