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
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <cfloat>
#include <climits>

ScalarConverter::ScalarConverter() 
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) 
{
	(void)src;
	return *this; 
}
ScalarConverter::~ScalarConverter() 
{
}

static void	print_decimal(double d, const std::string suffix)
{
	if (d != d)
		std::cout << "nan";
	else if (d == HUGE_VAL)
		std::cout << "+inf";
	else if (d == -HUGE_VAL)
		std::cout << "-inf";
	else
	{
		std::cout << d;
		if (d == std::floor(d) && std::fabs(d) < 1e6)
			std::cout << ".0";
	}
	std::cout << suffix << std::endl;
}

static void parse(double value)
{
	std::cout << "char: ";
	if (value != value || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	
	std::cout << "int: ";
	if (value != value || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible\n";
	else
	 	std::cout << static_cast<int>(value) << std::endl;
	std::cout << "float: ";
	if (std::fabs(value) != HUGE_VAL && std::fabs(value) > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		print_decimal(static_cast<float>(value), "f");
	
	std::cout << "double: ";
	print_decimal(value, "");
	std::cout << std::endl;
	return ;
}

static bool isDecimal(std::string s)
{
	int	dots = 0;
	int	digits = 0;
	size_t	i = 0;

	if (s.empty())
		return (false);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return (false);
	for (; i < s.length(); i++)
	{
		if (s[i] == '.')
			dots++;
		else if (std::isdigit(s[i]))
			digits++;
		else
			return (false);
	}
	return (dots == 1 && digits > 0);
}

static bool	isInt(std::string s)
{
	size_t	i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return (false);
	for (; i < s.length(); i++)
		if (!std::isdigit(s[i]))
			return (false);
	return (true);
}

static void	impossible()
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	if (input.empty())
		return (impossible());
	// chars
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (parse(static_cast<double>(input[1])));
	if (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		return (parse(static_cast<double>(input[0])));
	// float
	if (input == "+inff" || input == "-inff" || input == "nanf"
		|| (input[input.length() - 1] == 'f'
			&& isDecimal(input.substr(0, input.length() - 1))))
	{
		char	*end;
		double converted = std::strtod(input.c_str(), &end);
		if (std::fabs(converted) != HUGE_VAL && std::fabs(converted) > FLT_MAX)
		return (impossible());
		float	f = static_cast<float>(converted);
		if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0')
			return (parse(static_cast<double>(f)));
		return (impossible());
	}
	// double
	if (input == "+inf" || input == "-inf" || input == "nan" || isDecimal(input))
	{
		double converted = std::strtod(input.c_str(), NULL);
		if (input != "+inf" && input != "-inf" && std::fabs(converted) == HUGE_VAL)
			return (impossible());
		return (parse(converted));
	}
	// int
	if (isInt(input))
	{
		double	converted = std::strtod(input.c_str(), NULL);
		if (converted < INT_MIN || converted > INT_MAX)
			return (impossible());
		return (parse(converted));
	}
	return (impossible());
}
