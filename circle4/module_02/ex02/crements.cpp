/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crements.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:06:42 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:13:27 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

// First two return the new state
Fixed& Fixed::operator++(void)
{
	this->fixed_val += 1;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->fixed_val -= 1;
	return (*this);
}

// These two return the old state
Fixed Fixed::operator++(int)
{
	Fixed   temp(*this);

	this->fixed_val += 1;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed   temp(*this);

	this->fixed_val -= 1;
	return temp;
}
