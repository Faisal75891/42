/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:51:54 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:05:48 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed	operator+(const Fixed &f1, const Fixed &f2)
{
	Fixed   sum;

	sum = f1.getRawBits() + f2.getRawBits();
	return (sum);
}

Fixed	operator-(const Fixed &f1, const Fixed &f2)
{
	Fixed	result;

	result = f1.getRawBits() - f2.getRawBits();
	return (result);
}

Fixed	operator*(const Fixed &f1, const Fixed &f2)
{
	Fixed	result;

	// raw needs to be bigger than Fixed.
	long long raw = f1.getRawBits() * f2.getRawBits();
	result.setRawBits(raw >> 8); // Need to change when f_bits changes.
	return (result);
}

Fixed	operator/(const Fixed &f1, const Fixed &f2)
{
	Fixed	result;

	// needs to be big data type
	long long	numerator = (long long)f1.getRawBits() << 8; //shifted by f_bits;
	long long raw = numerator / f2.getRawBits();
	result.setRawBits(raw);
	return (result);
}
