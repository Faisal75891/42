/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:46:49 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:46:49 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int	main(void)
{
	ClapTrap	t("me"); 
	const ClapTrap target("target");

	t.attack("target");
	t.takeDamage(2);
	t.beRepaired(1);

	t.display();

	// target.attack("t");
	// target.takeDamage(0);
	// target.beRepaired(20);
	target.display();
	return (0);
}