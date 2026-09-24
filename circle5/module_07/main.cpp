/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:31:14 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/22 16:31:14 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <vector>
#include <set>

int	main(void)
{
	int	i1 = 42, i2 = 77;
	std::cout << mymax(i1, i2) << std::endl;
	std::cout << mymax(0.7, 33.4) << std::endl;
	// std::cout << mymax(1, 33.4) << std::endl; <----- WONT COMPILE
	std::cout << mymax<double>(1, 33.4) << std::endl;
	std::cout << mymax<int>(1, 33.4) <<  std::endl;
	
	std::string s("bigger"), t("digger");
	std::cout << mymax(s, t) << std::endl;

	std::vector<int> v;
	// print(v);

	std::set<std::string>	l;
	// print(l);
	// print("gello");

	auto a1 = mymin(1, 0.1); // returns Double
	auto a2 = mymin(23.5, 21); // returns INT
	/*
		std::complex<double> c1, c2;
		std::cout << mymax(c1, c2); <----- T is complex, '<' and '>' unsupported
		std::atomic<int> a1{0}, a2{15};
		std::cout << mymax(a1, a2); <------- T is atomic, copying is disables
	*/


	// stack of ints
	Stack<int> intStack;
	intStack.push(7);
	std::cout << intStack.top() << std::endl;

	// stack of strings
	Stack<std::string> strStack;
	strStack.push("hello");
	strStack.push(", World");
	strStack.pop();
	std::cout << strStack.top() << '\n';

	array<int, 10> a = {1, 2,3, 4, 7};
	std::cout << a.size() << "elements\n";
	for (size_t	i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << '\n';
	}
	for (array<int, 10>::iterator	p = a.begin(); p!= a.end(); ++p)
	{
		std::cout << p << '\n';
		std::cout << *p << '\n';
	}
	for (const auto &elems: a)
		std::cout << elems << '\n';
	
	std::string	str = "world";
	print("hello", 7.5, str);
}
