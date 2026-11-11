/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:23:31 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 16:23:31 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap() : name(""), hp(10), ad(0), ep(10)
{
	std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ad(0), ep(10)
{
	std::cout << "ClapTrap name contructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	name = src.name;
	hp = src.hp;
	ep = src.ep;
	ad = src.ad;
	std::cout << "ClapTrap copy contructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (hp <= 0 || ep <= 0)
		return ;
	ep--;
	std::cout << "ClapTrap " << name
	<< " attacks " << target << ", causing " << ad << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hp <= 0)
		return ;
	if (amount >= static_cast<unsigned int>(hp))
		hp = 0;
	else
		hp -= static_cast<int>(amount);
	std::cout << "ClapTrap " << name
	<< " took " << amount << " points of damage\n"
	<< "total hp is " << hp << "." << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp <= 0 || ep <= 0)
		return ;
	ep--;
	hp += amount;
	std::cout << "ClapTrap " << name << " repaired " << amount
	<< " amount of hp \n" << "total hp is " << hp << "." << std::endl;
}

void	ClapTrap::display() const
{
	std::cout << "\nClapTrap stats for " << name << std::endl 
	<< "Hp: " << hp << std::endl
	<< "Energy: " << ep << std::endl
	<< "Ad: " << ad << std::endl; 
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	if (this != &src)
	{
		name = src.name;
		hp = src.hp;
		ep = src.ep;
		ad = src.ad;
	}
	std::cout << "ClapTrap copy assignment contructor called\n";
	return (*this);
}
