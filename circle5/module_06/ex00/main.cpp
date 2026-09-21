/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 23:41:06 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/12 23:41:06 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(void)
{
    ScalarConverter::convert("1.23");
    std::cout << std::endl;
    ScalarConverter::convert("1");
    std::cout << std::endl;
    ScalarConverter::convert("1.2312312312312312312231312");
    std::cout << std::endl;
    ScalarConverter::convert("1.23f");
    std::cout << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
    ScalarConverter::convert("42.1f");
    std::cout << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
}
