#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
    {
        Animal animal;
        Animal animalCopy(animal);
        Animal animalAssigned;
        animalAssigned = animal;
        animal.makeSound();
    }
    {
        Dog dog;
        Dog dogCopy(dog);
        Dog dogAssigned;
        dogAssigned = dog;
        dog.makeSound();
    }
    {
        Cat cat;
        Cat catCopy(cat);
        Cat catAssigned;
        catAssigned = cat;
        cat.makeSound();
    }
    {
        WrongAnimal wrongAnimal;
        WrongAnimal wrongAnimalCopy(wrongAnimal);
        WrongAnimal wrongAnimalAssigned;
        wrongAnimalAssigned = wrongAnimal;
        wrongAnimal.makeSound();
    }
    {
        WrongCat wrongCat;
        WrongCat wrongCatCopy(wrongCat);
        WrongCat wrongCatAssigned;
        wrongCatAssigned = wrongCat;
        wrongCat.makeSound();
    }
    {
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        animal->makeSound();
        dog->makeSound();
        cat->makeSound();
        wrongAnimal->makeSound();
        wrongCat->makeSound();

        delete animal;
        delete dog;
        delete cat;
        delete wrongAnimal;
        delete wrongCat;
    }
}