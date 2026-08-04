#include "WrongCat.h"


WrongCat::WrongCat(std::string t) : WrongAnimal(t)
{
	std::cout << "Wrong Cat is born\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destrutor call\n";
}

void    WrongCat::makeSound() const
{
	// very creative :/
	std::cout << "Wrong cat noise wooooooo\n";
}
