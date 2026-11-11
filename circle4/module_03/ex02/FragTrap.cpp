/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:00:59 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 17:00:59 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->ad = 30;
	this->hp = 100;
	this->ep = 100;
	std::cout << "FragTrap Created\n";
}

FragTrap::FragTrap(/* args */) : ClapTrap()
{
	this->ad = 30;
	this->hp = 100;
	this->ep = 100;
	this->name = "Default FragTrap";
	std::cout << "Default FragTrap Created\n";
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap's clone of " << src.name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		this->name =src.name;
		this->ad = src.ad;
		this->hp = src.hp;
		this->ep = src.ep;
	}
	std::cout << "FragTrap got cloned!\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destroyed\n";
}

void	FragTrap::highFiveGuys(void) const
{
	std::cout << "High-five request: Active!\n Up high! ✋\n";
}
