/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:57:37 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:57:37 by fbaras           ###   ########.fr       */
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
	std::cout << "Default FragTrap Created\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destroyed\n";
}

void	FragTrap::highFiveGuys(void) const
{
	std::cout << "High-five request: Active!\n Up high! ✋\n";
}
