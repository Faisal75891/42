
#pragma once

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(std::string n = "Dog");
		~Dog();
		void  				makeSound() const;
		void    			setIdea(size_t i, std::string idea);
		const std::string	getIdea(size_t i) const;
		void				getIdeas() const;
};

