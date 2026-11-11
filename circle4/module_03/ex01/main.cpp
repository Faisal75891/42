/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:36:15 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 16:36:15 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int	main(void)
{
	ClapTrap	t("me");
	ScavTrap	s("sssssssssssss");

	ScavTrap	test = ScavTrap("yeye");

	test.display();
	std::cout << "\n";
	ScavTrap j = test;
	std::cout << "\n";
	j.display();
	std::cout << "\n";
	s.guardGate();
	s.attack("him");
	s.beRepaired(3);
	s.takeDamage(2);

	s.display();

	t.attack("target");
	t.takeDamage(2);
	t.beRepaired(1);

	t.display();
	return (0);
}
