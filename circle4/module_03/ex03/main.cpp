/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:47:32 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 19:47:32 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

int	main(void)
{
	DiamondTrap	a;
	std::cout<<std::endl;
	DiamondTrap	f("g");
	DiamondTrap	c(a);
	DiamondTrap	temp("new DiamondTrap");
	std::cout<<std::endl;

	a.whoAmI();
	std::cout<<std::endl;
	a = temp;
	a.attack("f");
	std::cout<<std::endl;
	c.whoAmI();
	std::cout<<std::endl;
	c.attack("g");
	std::cout<<std::endl;
	f.whoAmI();
	std::cout<<std::endl;

	{
		ClapTrap	*a = new DiamondTrap("Yoooo");
		delete a;
		std::cout << "\n";
	}
	return (0);
}
