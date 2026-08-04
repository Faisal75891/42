
#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
private:
	int					raw_bits;
	const static	int	f_bits = 8;
public:
	// default constructor
	Fixed();

	// my constructor
	Fixed(int n = 0);

	// copy constructor
	Fixed(const Fixed &src);

	// copy assignment operarot
	Fixed& operator=(const Fixed &src);

	int		getRawBits(void) const;
	void	setRawBits( int const raw);
	~Fixed();
};


#endif