#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Materia.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Materia source ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	std::cout << "Created materia types: ";
	AMateria* tmp = src->createMateria("ice");
	if (tmp)
	{
		std::cout << tmp->getType() << ", ";
		me->equip(tmp);
	}
	tmp = src->createMateria("cure");
	if (tmp)
	{
		std::cout << tmp->getType() << std::endl;
		me->equip(tmp);
	}

	std::cout << "Unknown materia: ";
	tmp = src->createMateria("fire");
	std::cout << (tmp == NULL ? "not created" : "unexpectedly created")
			  << std::endl;
	delete tmp;

	std::cout << "=== Character inventory ===" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "Four equipped slots:" << std::endl;
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << "Unequip and reuse a slot:" << std::endl;
	me->unequip(3);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
