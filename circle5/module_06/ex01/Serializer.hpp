/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:31:22 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/20 10:31:22 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		/* data */
	public:
		Serializer() ;
		~Serializer();
        Serializer(const Serializer& s);
        Serializer& operator=(const Serializer& s);
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};
