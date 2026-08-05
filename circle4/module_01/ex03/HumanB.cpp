/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:08:03 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 17:01:20 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << name << " joined the server\n";
	// weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << name << " died\n";
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}
