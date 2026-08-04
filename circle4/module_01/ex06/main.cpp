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
	int		level;
	Harl	h;
	if (argc != 2)
	{
		std::cout << "./harlfilter \"LOG LEVEL\"\n";
		return (1);
	}
	if (!strcmp(argv[1], "DEBUG"))
		level = 0;
	else if (!strcmp(argv[1], "INFO"))
		level = 1;
	else if (!strcmp(argv[1], "WARNING"))
		level = 2;
	else if (!strcmp(argv[1], "ERROR"))
		level = 3;
	else
		level = -1;
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
		break;
	}
}
