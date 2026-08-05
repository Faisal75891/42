/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:02:35 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:02:35 by fbaras           ###   ########.fr       */
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
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap is created\n";
	this->hp = 100;
	this->ad = 20;
	this->ep = 50;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap is destroyed!\n";
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name
	<< " attacks " << target << ", causing " << ad << " points of damage!\n";
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode!\n";
	gateMode = true;
}
