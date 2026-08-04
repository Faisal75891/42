#include "Character.hpp"

Character::Character(std::string n) : name(n)
{
	for (int i = 0; i < MAX_MATRIA; i++)
		this->matria[i] = new Materia(n);
	this->idx = 0;
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
	if (idx > MAX_MATRIA || !m)
		return ;
	this->matria[this->idx] = m->clone();
	this->idx++;
}

//decrement idx??? Can't delete so idk
void	Character::unequip(int	idx)
{
	if (idx <= 0)
		return ;
	this->idx--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > MAX_MATRIA)
		return ;
	this->matria[idx]->AMateria::use(target);
}

Character	&Character::operator=(Character &src)
{
	// check if this == src

	// create new matria
	// copy matrias
	// delete old Matria

	if (this != &src)
	{
		for (int i = 0; i < MAX_MATRIA; i++)
		{
			if (this->matria[i] != NULL)
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
		this->idx = src.idx;
		this->name = src.name;
	}

	return (*this);
}

Character::Character(Character &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MAX_MATRIA; i++)
		{
			if (this->matria[i] != NULL)
				delete this->matria[i];
			this->matria[i] = NULL;
		}
		for (int i = 0; i < MAX_MATRIA; i++)
			this->matria[i] = src.matria[i]->clone();
		this->idx = src.idx;
		this->name = src.name;
	}
}
