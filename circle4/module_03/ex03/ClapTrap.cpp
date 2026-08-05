/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:01:49 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:01:49 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap() : name("ClapTrap"), hp(10), ad(0), ep(10)
{
	std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ad(0), ep(10)
{
	std::cout << "ClapTrap created\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed\n";
}

void	ClapTrap::attack(const std::string& target)
{
	ep--;
	// change target's hp?
	std::cout << "ClapTrap " << name
	<< " attacks " << target << ", causing " << ad << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hp -= amount;
	std::cout << "ClapTrap " << name
	<< " took " << amount << " points of damage\n"
	<< "total hp is " << hp << "." << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
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
