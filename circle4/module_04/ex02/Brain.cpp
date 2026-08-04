#include "Brain.h"

Brain::Brain(/* args */)
{
    std::cout << "Brain constructed\n";
}

Brain::~Brain()
{
    std::cout << "Brain Destructed\n";
}

void    Brain::setIdea(size_t i, std::string idea)
{
    if (i < 100)
        this->ideas[i] = idea;
    else
        std::cout << "Couldn't add idea, brain too small\n";
}

const std::string   Brain::getIdea(size_t i) const
{
    if (i < 100)
        return (this->ideas[i]);
    std::cout << "Couldn't remember idea, brain too small\n";
    return (NULL);
}

void	Brain::getIdeas() const
{
    for (int i = 0; i < 100; i++)
    {
        if (this->ideas[i] != "")
        {
            std::cout << this->ideas[i] << " ";

        }
    }
    std::cout << std::endl;
}
