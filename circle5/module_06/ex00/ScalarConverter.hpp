/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 23:12:10 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/12 23:12:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

// enum class DataType {
// 	Integer,
// 	Float,
// 	Double,
// 	String
// };

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		static void	convert(std::string input);
};
