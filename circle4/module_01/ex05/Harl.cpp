/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:45:57 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 19:01:18 by fbaras           ###   ########.fr       */
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
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}
