/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:50:48 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 21:50:55 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

bool    operator>(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() > f2.getRawBits());
}

bool    operator<(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() < f2.getRawBits());
}

bool    operator>=(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() >= f2.getRawBits());
}

bool    operator<=(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() <= f2.getRawBits());
}

bool    operator==(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() == f2.getRawBits());
}

bool    operator!=(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() != f2.getRawBits());
}
