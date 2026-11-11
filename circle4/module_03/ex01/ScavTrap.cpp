/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:54:49 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:54:49 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap is created\n";
	this->name = "ScavTrap";
	this->hp = 100;
	this->ad = 20;
	this->ep = 50;
	this->gateMode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap named: " << name << " is now created\n";
	this->hp = 100;
	this->ad = 20;
	this->ep = 50;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
	{
		this->hp = src.hp;
		this->ad = src.ad;
		this->ep = src.ep;
		this->name = src.name;
	}
	std::cout << "ScavTrap got assigned\n"; //idk
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	this->gateMode = src.gateMode;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << this->name << " is destroyed!\n";
}

void	ScavTrap::attack(const std::string& target)
{
	this->ep--;
	std::cout << "Scavtrap " << name
	<< " attacks " << target << ", causing " << ad << " points of damage! (It's so much stronger!)\n";
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode!\n";
	gateMode = true;
}
