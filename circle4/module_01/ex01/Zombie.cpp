#include "Zombie.h"

Zombie	*newZombie( std::string name );
Zombie  *zombieHorde(int N, string name);
void	randomChump( std::string name );

int	main(void)
{
	Zombie  *z = zombieHorde(3, "gurrrr");
    
    for (int i = 0; i < 3; i++)
    {
        z[i].announce();
    }
    // for (int i = 0; i < 3; i++)
    //     delete &z[i];
    delete[] z;
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

Zombie  *zombieHorde(int N, string name)
{
    Zombie  *zombies;
    int     i = 0;

    zombies = new Zombie[N];
    while (i < N)
    {
        zombies[i].setName(name);
        i++;
    }
    return (zombies);
}
