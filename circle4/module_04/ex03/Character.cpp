#include "Character.hpp"

Character::Character() : name("Default character")
{
    for (int i = 0; i < MAX_MATRIA; i++)
        this->matria[i] = NULL;
}

Character::Character(std::string n) : name(n)
{
	for (int i = 0; i < MAX_MATRIA; i++)
		this->matria[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < MAX_MATRIA; i++)
	{
		if (this->matria[i] != NULL)
			delete this->matria[i];
		this->matria[i] = NULL;
	}
}

std::string const	&Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < MAX_MATRIA; i++)
	{
		if (this->matria[i] == NULL)
		{
			this->matria[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int	idx)
{
	if (idx < 0 || idx >= MAX_MATRIA)
		return ;
	this->matria[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_MATRIA || !this->matria[idx])
		return ;
	this->matria[idx]->use(target);
}

Character	&Character::operator=(const Character &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MAX_MATRIA; i++)
		{
			delete this->matria[i];
			this->matria[i] = NULL;
		}
		for (int i = 0; i < MAX_MATRIA; i++)
		{
			if (src.matria[i] != NULL)
				this->matria[i] = src.matria[i]->clone();
			else
				this->matria[i] = NULL;
		}
		this->name = src.name;
	}

	return (*this);
}

Character::Character(const Character &src) : name(src.name)
{
	for (int i = 0; i < MAX_MATRIA; i++)
	{
		if (src.matria[i] != NULL)
			this->matria[i] = src.matria[i]->clone();
		else
			this->matria[i] = NULL;
	}
}
