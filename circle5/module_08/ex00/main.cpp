/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:57:32 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/24 13:57:32 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main(int, char**)
{
	std::vector<int>	v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	std::list<int>	l;
	l. = {7, 8, 9};

	std::deque<int>	d = {50, 60, 70};

	std::cout << easyFind(v, 10) << '\n';
	std::cout << easyFind(v, 20) << '\n';
	std::cout << easyFind(v, 30) << '\n';
	std::cout << easyFind(l, 7) << '\n';
	std::cout << easyFind(l, 8) << '\n';
	std::cout << easyFind(l, 9) << '\n';
	std::cout << easyFind(d, 50) << '\n';
	std::cout << easyFind(d, 60) << '\n';
	std::cout << easyFind(d, 70) << '\n';
	try
	{
		std::cout << easyFind(v, 11) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyFind(l, 10) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyFind(d, 120) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
