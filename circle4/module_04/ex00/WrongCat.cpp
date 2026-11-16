#include "WrongCat.h"


WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "Wrong Cat is born\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "Copy WrongCat constructor called\n";

}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
    std::cout << "Assignment WrongCat constructor called\n";
	return *this;
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
