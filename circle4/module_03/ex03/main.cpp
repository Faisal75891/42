/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 23:02:30 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 23:02:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

int	main(void)
{
	DiamondTrap	f("g");

	f.attack("him");
	f.highFiveGuys();
	// f.ad = 3;
	f.beRepaired(1);
	std::cout << std::endl;
	f.whoAmI();
	f.display();
	std::cout << std::endl;
	return (0);
}
