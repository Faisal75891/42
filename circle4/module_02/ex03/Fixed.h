
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
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	&operator--(int);
};

std::ostream& operator<<(std::ostream &os, const Fixed &src);
Fixed	operator+(const Fixed &f1, const Fixed &f2);
Fixed	operator-(const Fixed &f1, const Fixed &f2);
Fixed	operator*(const Fixed &f1, const Fixed &f2);
Fixed	operator/(const Fixed &f1, const Fixed &f2);

#endif