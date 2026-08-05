/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:37:10 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 21:37:10 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"


Fixed::Fixed() : fixed_val(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int Constructor called" << std::endl;
	fixed_val = n << f_bits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float Constructor called" << std::endl;
	fixed_val = roundf(n * (1 << f_bits));
}

float	Fixed::toFloat( void ) const
{
	float	float_val = 0.0;

	float_val = (float)this->fixed_val / (1 << f_bits);
	return (float_val);
}

int		Fixed::toInt(void) const
{
	return (this->fixed_val / (1 << f_bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return (fixed_val);
}

void Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;

	fixed_val = raw;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}

Fixed	&Fixed::min(Fixed &n, Fixed &i)
{
	if (n > i)
	{
		return (i);
	}
	return (n);
}

Fixed	&Fixed::min(const Fixed &n, const Fixed &i)
{
	if (n > i)
	{
		return ((Fixed &)i);
	}
	return ((Fixed &)n);
}

Fixed	&Fixed::max(Fixed &n, Fixed &i)
{
	if (n > i)
	{
		return (n);
	}
	return (i);
}

Fixed	&Fixed::max(const Fixed &n, const Fixed &i)
{
	if (n > i)
	{
		return ((Fixed &)n);
	}
	return ((Fixed &)i);
}
