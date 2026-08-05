/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:37:15 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 21:37:15 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int					fixed_val;
	const static int	f_bits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &src);
	~Fixed();

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed	&operator=(const Fixed &src);

	static Fixed	&min(Fixed &n, Fixed &i);
	static Fixed	&min(const Fixed &n, const Fixed &i);
	static Fixed	&max(Fixed &n, Fixed &i);
	static Fixed	&max(const Fixed &n, const Fixed &i);
	
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream &os, const Fixed &src);

Fixed	operator+(const Fixed &f1, const Fixed &f2);
Fixed	operator-(const Fixed &f1, const Fixed &f2);
Fixed	operator*(const Fixed &f1, const Fixed &f2);
Fixed	operator/(const Fixed &f1, const Fixed &f2);

bool    operator>(const Fixed &f1, const Fixed &f2);
bool    operator<(const Fixed &f1, const Fixed &f2);
bool    operator>=(const Fixed &f1, const Fixed &f2);
bool    operator<=(const Fixed &f1, const Fixed &f2);
bool    operator==(const Fixed &f1, const Fixed &f2);
bool    operator!=(const Fixed &f1, const Fixed &f2);

#endif