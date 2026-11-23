/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:41:24 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/20 10:41:24 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

int	main(void)
{
	Data a;

	uintptr_t b = Serializer::serialize(&a);
	Data *result = Serializer::deserialize(b);
	std::cout << "Data address: " << &a << std::endl;
	std::cout << "Serialized uintptr_t: " << b << std::endl;
	std::cout << "Deserialized address: " << result << std::endl;
	std::cout << "Pointers are equal: " << (&a == result) << std::endl;
}
