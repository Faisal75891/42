
#ifndef FIXED_H
#define FIXED_H

using namespace std;

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int					val;
	const static	int	f_bits = 8;
public:
	// default constructor
	Fixed();

	// my constructor
	Fixed(const int n);
	Fixed(const float n);

	// copy constructor
	Fixed(const Fixed &src);

	// copy assignment operarot
	Fixed& operator=(const Fixed &src);

	// << operator.
	// friend ostream& operator<<(ostream& os, const Fixed& e);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;
	~Fixed();
};

std::ostream& operator<<(std::ostream &os, const Fixed &src);

#endif