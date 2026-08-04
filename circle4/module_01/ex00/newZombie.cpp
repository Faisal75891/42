/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 20:01:45 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 20:01:52 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie	*newZombie( std::string name )
{
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	// newZombie->setName(name);

	return (newZombie);
}
