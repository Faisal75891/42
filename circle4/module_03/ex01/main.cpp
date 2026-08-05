/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:54:41 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:54:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int	main(void)
{
	ClapTrap	t("me"); 
	// const ClapTrap target("target");
	ScavTrap	s("Scavtrap");

	s.guardGate();
	s.attack("him");
	s.beRepaired(3);
	s.takeDamage(2);

	// s.display();

	t.attack("target");
	t.takeDamage(2);
	t.beRepaired(1);

	// t.display();
	return (0);
}