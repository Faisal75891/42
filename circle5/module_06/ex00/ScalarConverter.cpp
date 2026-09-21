/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 23:12:02 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/12 23:12:02 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <typeinfo>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>

bool parseFloat(const std::string& input, float& value)
{
	std::string n = input;

	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf\n";
		else
			std::cout << "-inf\n";
	}
	if (!n.empty() && n[n.size() - 1] == 'f')
  		n.resize(n.size() - 1);
	std::stringstream ss(n);
	char extra;

	return (ss >> value) && !(ss >> extra);
}

bool parseInt(const std::string& input, int& value)
{
	std::stringstream ss(input);
	char extra;
	
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf\n";
		else
			std::cout << "-inf\n";
	}
	return (ss >> value) && !(ss >> extra);
}

bool parseDouble(const std::string& input, double& value)
{
	std::stringstream ss(input);
	char extra;

	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf\n";
		else
			std::cout << "-inf\n";
	}
	return (ss >> value) && !(ss >> extra);
}


void	ScalarConverter::convert(std::string input)
{
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	char c = '\0';

	if (input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		if (input == "-inf" || input == "-inff")
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
		return;
	}
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		c = input[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (parseInt(input, i))
	{
		f = float(i);
		d = double(i);
		c = static_cast<char>(i);
	}
	else if (parseFloat(input, f))
	{
		i = int(f);
		d = double(f);
		c = static_cast<char>(f);
	}
	else if (parseDouble(input, d))
	{
		f = float(d);
		i = int(d);
		c = static_cast<char>(d);
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return;
	}
	if (f < 0 || f > 127 || !std::isprint(static_cast<unsigned char>(f)))
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
