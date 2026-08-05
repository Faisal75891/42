/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:36:30 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 21:36:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"


Fixed::Fixed() : raw_bits(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	std::cout << "int Constructor called" << std::endl;
	raw_bits = n;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (raw_bits);
}

void Fixed::setRawBits ( int const raw_bits )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->raw_bits = raw_bits;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}
