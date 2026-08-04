#include "ScavTrap.h"

int	main(void)
{
	ClapTrap	t("me"); 
	// const ClapTrap target("target");
	ScavTrap	s("n");

	s.guardGate();
	s.attack("ni");
	s.beRepaired(3);
	t.attack("target");
	t.takeDamage(2);
	t.beRepaired(1);

	t.display();
	return (0);
}