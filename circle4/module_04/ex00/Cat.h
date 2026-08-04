
#pragma once

#include "Animal.h"

class Cat : public Animal
{
    public:
        Cat(std::string n = "Cat");
        virtual ~Cat();
        void    makeSound() const;
};
