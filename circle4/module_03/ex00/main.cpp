/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:22:59 by fbaras            #+#    #+#             */
/*   Updated: 2026/11/10 16:22:59 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int	main(void)
{
	ClapTrap	d;
	ClapTrap	hi("Hi");
	ClapTrap	hello(hi);
	ClapTrap	t("me"); 
	const ClapTrap target("target");

	d = hello;
	ClapTrap c = ClapTrap("whaaat");

	d.display();
	hi.display();
	hello.display();
	c.display();
	t.display();
	target.display();

	t.attack("target");
	t.takeDamage(2);
	t.beRepaired(1);

	t.display();
	return (0);
}
