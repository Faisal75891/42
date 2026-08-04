
#pragma once

#include "Animal.h"

class Dog : public Animal
{
    public:
        Dog(std::string n = "Dog");
        ~Dog();
        void    makeSound() const;
};

