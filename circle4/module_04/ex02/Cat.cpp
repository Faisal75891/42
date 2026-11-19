#include "Cat.h"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Hello i am cat\n";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain = new Brain(*other.brain);

    std::cout << "Copy Cat constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        Brain *newBrain = new Brain(*other.brain);
        delete this->brain;
        this->brain = newBrain;
    }
    std::cout << "Copy Cat constructor called\n";
    return *this;
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
