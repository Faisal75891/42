/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:06:10 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 17:00:09 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string type): type(type)
{
	std::cout << type << " got equipped\n";
}

Weapon::~Weapon()
{
    std::cout << type << " lost its durability\n";
}

const std::string	&Weapon::getType(void) const
{
	return type;
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}
