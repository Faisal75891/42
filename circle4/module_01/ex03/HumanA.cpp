/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:09:07 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 23:24:04 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << name << " joined the lobby\n";

}

HumanA::~HumanA()
{
    std::cout << name << " left the game\n";
}

void    HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon new_weapon)
{
	weapon = new_weapon;
}
