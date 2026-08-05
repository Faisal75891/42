/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:57:37 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 16:28:47 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void)
{
	Zombie	*a, *b;
	
	b = newZombie("");
	a = newZombie("real man");
	a->announce();
	b->announce();
	std::cout << a->getName() << std::endl;
	std::cout << b->getName() << std::endl;
	randomChump("man");
	randomChump("man2");
	randomChump("man3");
	randomChump("man4");
	randomChump("man5");
	delete a;
	delete b;
	return (0);
}
