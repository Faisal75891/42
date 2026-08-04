
#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(std::string="Wrong Cat");
		~WrongCat();
		void	makeSound() const;
};

#endif