
#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(std::string="wrong animal");
		virtual	~WrongAnimal();
		virtual	void	makeSound() const;
};

#endif