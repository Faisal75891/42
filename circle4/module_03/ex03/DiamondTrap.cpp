/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:01:59 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:01:59 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap("Default DiamondTrap")
{
	std::cout << "DiamondTrap Default constructor Created\n";

	this->name = "Default DiamondTrap";
	ClapTrap::name = this->name + "_clap_name";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->ad = FragTrap::ad;
	// std::cout << hp << " " << ep << " " << ad << " " << std::endl;
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap(n + "_clap_name")
{
	this->name = n;
	ClapTrap::name = n + "_clap_name";
	this->hp = FragTrap::hp;
	this->ep = ScavTrap::ep;
	this->ad = FragTrap::ad;
	// std::cout << hp << " " << ep << " " << ad << " " << std::endl;
	std::cout << "DiamondTrap Created with name: " << this->name << ".\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " is destroyed\n";
}

void    DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << this->name << std::endl
	<< "ClapTrap Name: " << ClapTrap::name << "." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src) 
{
	*this = src;
	std::cout << "DiamondTrap copy instructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		this->hp = src.hp;
		this->ad = src.ad;
		this->ep = src.ep;
		this->name = src.name;
		ClapTrap::name = src.ClapTrap::name;
	}
	std::cout << "DiamondTrap assignment operator called\n";
	return (*this);
}	
