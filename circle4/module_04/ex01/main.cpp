#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Brain.h"

int main()
{
	const	Animal	*zoo[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			zoo[i] = new Cat();
		}
		else
		{
			zoo[i] = new Dog();
		}
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal type: " << zoo[i]->getType() << std::endl;
		zoo[i]->makeSound();
		std::cout << std::endl;
		delete(zoo[i]);
	}

	Dog	*a = new Dog();
	Brain	*b = new Brain();

	b->setIdea(0, "Hello i am first idea");
	b->setIdea(1, "Hello i am second idea");
	b->setIdea(99, "Hello i am last idea");
	a->setIdea(0, "I am hungry");
	a->setIdea(1, "I am hungry");
	a->setIdea(2, "I am hungry");
	a->setIdea(3, "I am hungry");

	std::cout << "Animal: "<< a->getType() << ": thinks of the following: \n"; 
	a->getIdeas();
	b->getIdeas();
	delete (b);
	delete (a);
}

// valgrind ./a