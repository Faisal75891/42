
#pragma once

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
    private:
        Brain   *brain;
    public:
        Cat(std::string n = "Cat");
        virtual ~Cat();
        void    makeSound() const;
        void    			setIdea(size_t i, std::string idea);
        const std::string	getIdea(size_t i) const;
		void				getIdeas() const;
};
