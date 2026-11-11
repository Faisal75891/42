/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:57:44 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:57:44 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

int	main(void)
{
	FragTrap	f("g");
	FragTrap	t;
	FragTrap	w("n");
	FragTrap	n = w;
	ClapTrap	test = FragTrap(f);

	t = f;

	f.display();
	t.display();
	w.display();
	n.display();
	test.display();
	// test.highFiveGuys(); xxxx
	f.attack("him");
	f.highFiveGuys();
	f.beRepaired(1);
	f.display();
	return (0);
}