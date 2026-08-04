#include "Zombie.h"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie	*nigga0, *niggarito;
	
	niggarito = newZombie("");
	nigga0 = newZombie("real nigga");
	cout << nigga0->getName() << endl;
	cout << niggarito->getName() << endl;
	randomChump("nigga");
	randomChump("nigga2");
	randomChump("nigga3");
	randomChump("nigga4");
	randomChump("nigga5");
	delete nigga0, niggarito;
	return (1);
}

void	randomChump( std::string name)
{
	Zombie	*zombie = newZombie(name);
	if (!zombie)
		return ;
	zombie->announce();
	delete zombie;
}

Zombie	*newZombie( std::string name )
{
	Zombie	*newZombie;

	newZombie = new Zombie;
	newZombie->setName(name);

	return (newZombie);
}
