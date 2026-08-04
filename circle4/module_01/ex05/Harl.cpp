/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:45:57 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 23:50:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "Debug\n";
}

void	Harl::info( void )
{
	std::cout << "Info\n";
}

void	Harl::warning( void )
{
	std::cout << "warning\n";
}

void	Harl::error( void )
{
	std::cout << "error\n";
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level == "DEBUG")
		(this->*ptr[0])();
	else if (level == "INFO")
		(this->*ptr[1])();
	else if (level == "WARNING")
		(this->*ptr[2])();
	else if (level == "ERROR")
		(this->*ptr[3])();
	// else
	// 	(this->*ptr[3])();
}
