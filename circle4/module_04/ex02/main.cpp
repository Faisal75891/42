#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Brain.h"

int main()
{
	{
		Cat basic;
		basic.setIdea(0, "Hii");
		Cat tmp = basic;
		tmp.setIdea(0, "Hello");
		std::cout << basic.getIdea(0) << std::endl;
		std::cout << tmp.getIdea(0) << std::endl;
	}
	{
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		dog->makeSound();
		cat->makeSound();

		delete dog;
		delete cat;
	}
	// Animal animal; // <------ compile error
}
