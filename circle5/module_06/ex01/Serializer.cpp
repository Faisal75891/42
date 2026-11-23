/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:37:47 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/20 10:37:47 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer& s)
{
    (void)s;
}

Serializer& Serializer::operator=(const Serializer& s)
{
    (void)s;
	return *this;
}

uintptr_t 	Serializer::serialize(Data *ptr)
{
	// (void)ptr;
	// std::cout << "Bytes: " << sizeof(uintptr_t) << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	// (void)raw;

	// std::cout << "Bytes: " << sizeof(Data) << std::endl;
	return reinterpret_cast<Data *>(raw);
}
