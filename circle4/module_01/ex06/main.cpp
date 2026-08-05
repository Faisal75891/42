/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:58:09 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 23:58:09 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int argc, char **argv)
{
	int		level = 4;
	Harl	h;
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	if (argc != 2)
	{
		std::cout << "./harlfilter \"LOG LEVEL\"\n";
		return (1);
	}
	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			level = i;
	}
	switch (level)
	{
	case 0:
		std::cout << "[ DEBUG ]\n";
		h.complain("DEBUG");
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]\n";
		h.complain("INFO");
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]\n";
		h.complain("WARNING");
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]\n";
		h.complain("ERROR");
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
