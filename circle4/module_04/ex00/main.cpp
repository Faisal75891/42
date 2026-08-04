#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    const   WrongAnimal *cat = new WrongCat();
    const   WrongAnimal &kitty = *cat;
    const   WrongAnimal *a = new WrongAnimal();
    const   WrongAnimal &b = *a;

    a->makeSound();
    cat->makeSound();

    kitty.makeSound();
    b.makeSound();

    delete cat;
    delete  a;
    delete meta;
    delete j;
    delete i;
}