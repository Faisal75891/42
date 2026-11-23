/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:53:27 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/20 10:53:27 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : a(0), b(0), c(0)
{

}

Data::Data(const Data& src) : a(src.a), b(src.b), c(src.c)
{

}

Data& Data::operator=(const Data& src)
{
    if (this != &src)
    {
        a = src.a;
        b = src.b;
        c = src.c;
    }
    return (*this);
}

Data::~Data()
{

}
