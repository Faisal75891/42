#include "ClapTrap.h"

int	main(void)
{
	ClapTrap	t("me"); 
	// const ClapTrap target("target");

	t.attack("target");
	t.takeDamage(2);
	t.beRepaired(1);

	t.display();
	return (0);
}